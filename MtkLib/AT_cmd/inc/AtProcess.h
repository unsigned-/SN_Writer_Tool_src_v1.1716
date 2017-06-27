/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   Thread.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   MF_Setup.txt file handler source
 *
 * Author:
 * -------
 *  Xuhua (mtk70506)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef _AT_PROCESS_H_
#define _AT_PROCESS_H_

#include <cvirte.h> 
#include <utility.h>
#include <userint.h>
//#include <winbase.h>
//#include "windows.h"
#include "General.h"

#define CR '\r'       //CR+LR+xxxx+CR+LR
#define LR '\n'

#define CRLF2 2
#define CRLF3 3
#define CRLF4 4
typedef enum
{
	STATE_WAIT_1ST_CR = 0,
	STATE_WAIT_1ST_LF,
	STATE_WAIT_2ND_CR,
	STATE_WAIT_2ND_LF
	
} E_AT_RSP_STATUS;

typedef enum
{
	AT_SUCCESS,
	AT_TIMEOUT,
	AT_WRITE_FAIL,
	AT_PARSE_FAIL,
	
	AT_STOP,
	AT_NOT_EXPECTED
	
} E_AT_RESULT_TYPE;

typedef enum AtParaTypeTag
{	
	AT_OMIT,
	AT_STRING,
	AT_INTERVAL,
	AT_INTEGER,
	AT_PARA_LIST
}
AtParaType;


typedef struct 
{
	AtParaType  type;
	kal_uchar8 *str_value;				//string type, maybe pdu
	kal_int32 int_value;				//value type
	kal_int32 int_range_begin, int_range_end;	//range type
   
} ATParamElem;

typedef struct {
	
	HANDLE hWriteEvent;
	HANDLE hReadEvent;
	HANDLE hInProgressEvent[2];

} S_EVENT;

typedef struct {
	
	E_AT_RESULT_TYPE eATResult;
	kal_uchar8 *pstrReceResult;
	kal_uchar8 *pstrExpectedResult;
	kal_uint32 iTimeOut;

} S_AT_RESULT;

typedef struct {
	
	kal_uchar8 *pTip;
	kal_uchar8 *pContext;
	kal_uchar8 *pReslt;

} S_AT_RSP;

typedef struct {
	
	kal_uint32 iTimeOut;
	kal_uchar8 *pstrATCmd;

} S_AT_REQUEST;


typedef void ( *EXEC_FUNC )( void );

typedef struct {
	E_COM_NUMBER eCom;
	kal_uchar8 *pBuf;
	kal_uint16 iLength;
	EXEC_FUNC FuncExec;
} S_EXEC_ARG;

typedef struct {
	kal_uchar8* pPDUBuf;
	E_AT_RESULT_TYPE *pState;
	kal_uint16 nLF;
	EXEC_FUNC FuncExec;
} S_EXEC_ARG2;

typedef struct{	

	S_EVENT event;
	S_AT_REQUEST request;
	S_AT_RESULT result;
	S_EXEC_ARG cb;
	S_EXEC_ARG2 cb2;
	kal_bool bIsConnected;
	kal_bool bTimerOut;
	
} AT_THREAD_CONTEXT;

extern void SetTimeOutFlag ( kal_bool bFlag );
extern kal_bool WriteCommand ( E_COM_NUMBER eComPort, S_AT_REQUEST tRequest, S_AT_RESULT *ptResult );
extern kal_bool ParseAtResult ( E_COM_NUMBER eComPort, S_AT_RESULT *ptResult, kal_uint16 nLF);
extern kal_bool AT_Preset ( E_COM_NUMBER eComPort, kal_uint16 iTimeOut );
extern kal_bool AT_Preset_rr( E_COM_NUMBER eComPort, kal_uint16 iTimeOut );
extern kal_bool AT_Preset_r( E_COM_NUMBER eComPort, kal_uint16 iTimeOut );
extern kal_bool COMContextInit (E_COM_NUMBER eComPort, UART_BAUDRATE eBaudRate );
extern kal_bool COMContextDeInit (E_COM_NUMBER eComPort, UART_BAUDRATE eBaudRate );

extern kal_bool WriteBarcodeATMode ( E_COM_NUMBER eComPort, kal_uchar8* pstrBarcode );
extern kal_bool SDSATMode(E_COM_NUMBER eComPort);
extern kal_bool WriteBarcodeATMode_r ( E_COM_NUMBER eComPort, kal_uchar8* pBarcode );
extern kal_bool SDSATMode_r(E_COM_NUMBER eComPort);
extern kal_bool ReadBarcodeATMode ( E_COM_NUMBER eComPort, kal_uchar8* pBarcode, kal_uint32* len );
extern kal_bool WriteIMEIATMode ( E_COM_NUMBER eComPort, IMEISV_struct_T *tIMEI, kal_uint16 id, kal_bool bSVN );
extern kal_bool WriteDataCallATMode ( E_COM_NUMBER eComPort,  kal_uint16 id);
extern kal_bool WriteIMEIATMode_r ( E_COM_NUMBER eComPort, IMEISV_struct_T *pIMEI, kal_uint16 id, kal_bool bSVN );
extern kal_bool ReadIMEIATMode ( E_COM_NUMBER eComPort, IMEISV_struct_T *ptIMEI, kal_uint16 id );
extern kal_bool WriteCDROMATMode ( E_COM_NUMBER eComPort,  kal_uchar8 id );
// add for fastboot oem lock start

typedef struct r_buf
{
	char rd_buf[1000];

}ADB_READ_BUF;



int Fastboot_Lock_Oem();
bool Adb_Manager_Init();
bool Adb_WR_Cmd(char *cmd_line,int cmd_length);
int Adb_Detect_Devact();
int Adb_Manager_Deinit();
int Set_Fastboot_EnvironmentVariable(void);

int Adb_Manager_Write(char *cmd_line,int cmd_length);
int Adb_Manager_Read(ADB_READ_BUF *adb_read_buf,int buf_size);	

//add for fastboot oem lock end

#endif


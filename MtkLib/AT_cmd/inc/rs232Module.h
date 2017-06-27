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

#ifndef _RS232MODULE_H_
#define _RS232MODULE_H_

#include "context.h" 
#include "general.h" 
#include <cvirte.h> 
#include <utility.h>
#include <userint.h>
//#include <winbase.h>
//#include "windows.h"


#define QUEUE_MAX_LENGTH 1024	


typedef struct {
	
	kal_uint32 iHead;
	kal_uint32 iTail;
	kal_uchar8 *pRawChars;

} S_RS232_QUEUE;

extern kal_bool ComportInit (E_COM_NUMBER eComPort, UART_BAUDRATE eBaudRate );
extern kal_bool ComportDeInit (E_COM_NUMBER eComPort, UART_BAUDRATE eBaudRate );
extern kal_bool WritePDU ( E_COM_NUMBER eComPort, kal_uchar8* ptr, kal_uint16 length );
extern kal_bool GetDeviceData ( E_COM_NUMBER eComPort );
extern kal_int32 ReadPDU ( E_COM_NUMBER eComPort, kal_uchar8* ptr, kal_uint16 length );
extern kal_bool InitQueue ( S_RS232_QUEUE *pQueue );
extern void DeInitQueue ( S_RS232_QUEUE *pQueue );
extern kal_bool IsQueueEmpty ( S_RS232_QUEUE *pQueue );
extern kal_bool IsQueueFull ( S_RS232_QUEUE *pQueue );
extern kal_int32 GetQueueLength ( S_RS232_QUEUE *pQueue );
extern void EnQueue ( S_RS232_QUEUE *pQueue, kal_uchar8* pData, kal_uint32 length );
extern kal_uint32 DeQueue ( S_RS232_QUEUE *pQueue, kal_uchar8* pData, kal_uint32 length );
extern kal_uchar8 GetByteQueue ( S_RS232_QUEUE *pQueue );
extern void FlushQueue ( S_RS232_QUEUE *pQueue );
extern kal_bool GetRawData( kal_uchar8 *ch );
extern void ClearAllBuff ( E_COM_NUMBER eComPort );


#endif //_RS232_H_

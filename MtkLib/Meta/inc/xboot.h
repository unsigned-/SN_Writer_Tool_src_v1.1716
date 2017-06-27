
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the XBOOT_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// XBOOT_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifndef _XBOOT_H_
#define _XBOOT_H_

#include  "stdlib.h"
#include  "windows.h"

#ifdef XBOOT_EXPORTS
#define XBOOT_API  __stdcall
#else
#define XBOOT_API  __stdcall
#endif

// Connect result
/*
typedef enum 
{
	CONNECT_SYNC_FAIL,
	CONNECT_FAIL,
	CONNECT_SUCCESS
} CONNECT_RESULT;
*/

typedef struct  {
	unsigned long  read_retry_time;			//     0 means default  (2400 times)
	unsigned long  read_interval_timeout;	// ms, 0 means default  (10 ms)
	int			 * m_p_stopflag;
} XMEtA_BOOT_ARG;

typedef struct  {
	unsigned long  read_retry_time;			//     0 means default  (2400 times)
	unsigned long  read_interval_timeout;	// ms, 0 means default  (10 ms)
	int			 * m_p_stopflag;
} XBOOT_BOOT_ARG;

/*
//Errors
typedef enum 
{
	EBOOT_SUCCESS = 1,
	EBOOT_EXCEPTION,

	//USER
	USER_PRESS_STOP_BUTTON,
	WAIT_FOR_PLATFORM_ERROR,

	// COM PORT ERROR
	OPEN_COM_PORT_ERROR = 1000,
	SETUP_COM_PORT_ERROR,
	GET_COM_STATE_ERROR,
	SET_COM_STATE_ERROR,
	PURGE_COM_PORT_ERROR,
	SET_COMM_TIMEOUTS_ERROR,
	CLOSE_COM_PORT_ERROR,

	//Boot ERROR
	READ_READY_PATTERN_ERROR = 2000,

	WRITE_META_PATTERN_ERROR,
	READ_META_ACK_PATTERN_ERROR,

	WRITE_ADVMETA_PATTERN_ERROR,
	READ_ADVMETA_ACK_PATTERN_ERROR,

	WRITE_DOWNLOAD_PATTERN_ERROR,
	READ_DOWNLOAD_ACK_PATTERN_ERROR,

	WRITE_FACTORYM_PATTERN_ERROR,
	READ_FACTORYM_ACK_PATTERN_ERROR,

	WRITE_MPWAIT_PATTERN_ERROR,
	READ_MPWAIT_ACK_PATTERN_ERROR,

	WRITE_MPGOON_PATTERN_ERROR,
	READ_MPGOON_ACK_PATTERN_ERROR,

	WRITE_CLEAN_BOOT_PATTERN_ERROR,
	READ_CLEAN_BOOT_ACK_PATTERN_ERROR,

	//USB PORT ERROR
	OPEN_USB_PORT_ERROR = 3000,
	USB_PORT_READ_FILE_ERROR,
	USB_PORT_READ_FILE_TIMEOUT_ERROR,
	USB_PORT_WRITE_FILE_ERROR,
	USB_PORT_READ_FILE_LEN_ERROR,
	USB_PORT_WRITE_FILE_LEN_ERROR,
	USB_PORT_SET_TIMEOUT_ERROR,
	USB_PORT_TOO_MANY_ERROR,
	USB_PORT_LOAD_WINDEV_DLL_ERROR,

	//ANDROID DOWNLOAD ERROR
	NOT_FLASH_INFO_PKT_ERROR = 4000,
	NOT_IMAGE_INFO_PKT_ERROR,
	OPEN_IMAGE_FILE_ERROR,
	GET_IMAGE_FILE_SIZE_ERROR,
	IMAGE_FILE_PATH_IS_NULL_ERROR,
	READ_IMAGE_FILE_ERROR,
	WRITE_IMAGE_FILE_ERROR,
	SEND_IMAGE_FILE_ERROR,
	UNKONWN_SEND_IMAGE_CHECK_PACKET_ERROR,
	SEND_REBOOT_PATTERN_ERROR,
	SEND_REBOOT_PATTERN_SIZE_ERROR,
	ANDROID_VERIFY_FAIL_ERROR,

         //Wei added for image patch & lock
	INFORM_IMAGE_PACKET_ERROR,
	PATCH_CMD_PACKET_ERROR,
	SEND_SECURITY_PACKET_ERROR,
	IMAGE_LOCK_RESPONSE_ERROR,
	SET_LOCK_RESPONSE_ERROR,
	RECEIVE_CHECKSUM_ERROR,
	META_LOCKED_ERROR,

	//Other Error
	OPEN_FLASH_BIN_FILE_ERROR,
	READ_FLASH_BIN_FILE_ERROR,
	ALLOC_MEMORY_ERROR,

	EBOOT_RESULT_END = 0x7FFFFFFF,

} XBOOT_RESULT;
*/
 
// Baud rate
#define MTK_CBR_230400 230400
#define MTK_CBR_460800 460800
#define MTK_CBR_921600 921600
#define MTK_CBR_1500000 1500000 
/*
typedef enum COMM_BAUDRATE
{
	BAUD2400 = CBR_2400,
	BAUD4800 = CBR_4800,
	BAUD9600 = CBR_9600,
	BAUD14400 = CBR_14400,
	BAUD19200 = CBR_19200,
	BAUD57600 = CBR_57600,	
    BAUD115200 = CBR_115200,    
	BAUD230400 = MTK_CBR_230400,
	BAUD460800 = MTK_CBR_460800,
	BAUD921600 = MTK_CBR_921600,
	BAUD1500000 = MTK_CBR_1500000
} COMM_BAUDRATE;
 */
// The magic value to stop boot process 
#define BOOT_STOP	9876

//extern hMTRACE  g_hEBOOT_DEBUG; 

#ifdef	__cplusplus
extern "C" {
#endif

	
int XBOOT_API  Xboot_DebugOn( void );
int XBOOT_API  Xboot_DebugOff( void );
int XBOOT_API  Xboot_DebugClear( void );
	
EBOOT_RESULT XBOOT_API   SP_Boot_WM_MetaMode(int comport,COMM_BAUDRATE baudrate, XMEtA_BOOT_ARG meta_arg);
EBOOT_RESULT XBOOT_API   SP_Boot_Anrdoid_MetaMode(int comport,COMM_BAUDRATE baudrate, XMEtA_BOOT_ARG meta_arg);

EBOOT_RESULT XBOOT_API   XBOOT_COMPORT_Init_r (HANDLE *hCOM, int comport, COMM_BAUDRATE baud);
EBOOT_RESULT XBOOT_API XBOOT_COMPORT_Close_r (HANDLE hCOM);
BOOL XBOOT_API   XBOOT_SendCMD_r (HANDLE *hCOM, char *pCMD, int cmd_len);
BOOL XBOOT_API XBOOT_Wait4Confirm_r (HANDLE hCOM, XBOOT_BOOT_ARG boot_arg, const char* pTARGET_ACK);

#ifdef	__cplusplus
}
#endif

#endif



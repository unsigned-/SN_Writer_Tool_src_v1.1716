/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/
/*!
 * @file meta.h
 * @mainpage Mobile Engineering Test Architecture Development Kit
 * @author MediaTek Inc.
 */
/*******************************************************************************
 * Filename:
 * ---------
 * meta.h
 *
 * Project:
 * --------
 *   META
 *
 * Description:
 * ------------
 *   This module contains the definitions for using META_DLL.dll.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *           HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef META_DLL_H
#define META_DLL_H


#include "brom.h"




#if defined(__cplusplus)
extern "C" {
#endif // #if defined(__cplusplus)



#if defined(__CHECK_REENTRANCY__)
#define NON_REENTRANT_FUNC __declspec(deprecated("this is not a reentrant function"))
#else
#define NON_REENTRANT_FUNC
#endif // #if !defined(__CHECK_REENTRANCY__)

//--------------------------------------------------------------------------//
//  META General                                                            //
//--------------------------------------------------------------------------//

#define INVALID_HANDLE  -1
#define MAX_BAUDRATE_ITEM_NUM 12

extern unsigned long g_defaultMinTimeout;
extern unsigned long g_defaultDebugTimeout;


//-----------------------------------------------------//
//  META General: data structure definition            //
//-----------------------------------------------------//
typedef enum
{
    /**
     * META_DLL received a corrupted frame
     */
    META_CNF_FRAME_ERROR = 0,

    /**
     * META_DLL received a confirm or indication from target,
     * but there is not corresponding call back function
     * installed for this confirm or indication.
     */
    META_CNF_NO_CALLBACK = 1,

    /**
     * META_DLL received a corrupted primitive.
     */
    META_CNF_PRIMITIVE_ERROR = 2,

    /**
     * META_DLL received a confirm or indication from
     * target, but there is no sufficient memory to process.
     */
    META_CNF_NO_MEMORY = 3,

    /**
     * META_DLL retrieved a callback function, however,
     * the user input arguments are invalid.
     */
    META_CNF_CALLBACK_PARAMETER_ERROR = 4,

    /**
     * META_DLL received a confirm with peer msg, however,
     * the peer msg is corrupted.
     */
    META_CNF_PEER_MSG_ERROR = 5,

    /**
     * META_DLL received a confirm and successfully executed
     * the callback function.
     */
    META_CNF_OK = 6
}
META_CNF_ERR_CODE;

// The magic value to stop usb enumerate process
#define ENUM_USB_STOP   9876
#define ENUM_ANY_STOP   9876

typedef enum
{
    META_SUCCESS = 0,
    META_FAILED = 1,
    META_COMM_FAIL = 2,
    META_NORESPONSE = 3,
    META_EBOOT_FAILED = 4,
    META_BUFFER_LEN = 5,
    META_FILE_BAD = 6,
    META_LID_INVALID = 7,
    META_INTERNAL_DB_ERR = 8,
    META_NO_MEMORY = 9,
    META_INVALID_ARGUMENTS = 10,
    META_TIMEOUT = 11,
    META_BUSY = 12,
    META_INVALID_HANDLE = 13,
    META_FAT_ERROR = 14,
    META_FAT_DISK_FULL = 15,
    META_FAT_ROOT_DIR_FULL = 16,
    META_FAT_INVALID_FILENAME = 17,
    META_FAT_INVALID_FILE_HANDLE = 18,
    META_FAT_FILE_NOT_FOUND = 19,
    META_FAT_DRIVE_NOT_FOUND = 20,
    META_FAT_PATH_NOT_FOUND = 21,
    META_FAT_ACCESS_DENIED = 22,
    META_FAT_TOO_MANY_FILES = 23,
    META_INCORRECT_TARGET_VER = 24,
    META_COM_ERROR = 25,
    META_BROM_CMD_ERROR = 26,
    META_INCORRECT_BBCHIP_TYPE = 27,
    META_BROM_ERROR = 28,
    META_STOP_BOOTUP_PROCEDURE = 29,
    META_CANCEL = 30,
    META_FUNC_NOT_IMPLEMENT_YET = 31,
    META_NOT_SUPPORT = META_FUNC_NOT_IMPLEMENT_YET,
    META_FAT_APP_QUOTA_FULL = 32,
    META_IMEI_CD_ERROR = 33,
    META_RFID_MISMATCH = 34,
    META_NVRAM_DB_IS_NOT_LOADED_YET = 35,
    META_WAIT_FOR_TARGET_READY_TIMEOUT = 36,
    META_ERR_EXCEED_MAX_PEER_BUF_SIZE = 37,
    META_BROM_SECURITY_CHECK_FAIL = 38,
    META_MAUI_DB_INCONSISTENT = 39,
    META_FAT_FILEPATH_TOO_LONG = 40,
    META_FAT_RESTRICTED_FILEPATH = 41,
    META_FAT_DIR_NOT_EXIST = 42,
    META_FAT_DISK_SPACE_IS_NOT_ENOUGH = 43,
    META_TDMB_ERR_BAND_NOT_EXIST = 44,
    META_TDMB_ERR_FREQ_NOT_EXIST = 45,
    META_TDMB_ERR_ENSM_NOT_EXIST = 46,
    META_TDMB_ERR_SERV_NOT_EXIST = 47,
    META_TDMB_ERR_SUB_CHAN_NOT_EXIST = 48,
    META_TDMB_ERR_DEMOD_STATE = 49,
    META_ENUMERATE_USB_FAIL = 50,
    META_STOP_ENUM_USB_PROCEDURE = 51,
    META_MISC_TARGET_LOAD_NEED_TO_BE_PATCHED = 52,
    META_MISC_INI_FILE_SETTINGS_WRONG = 53,
    META_MISC_FAIL_TO_READ_IMEI = 54,
    META_MISC_FAIL_TO_BACKUP_FILE = 55,
    META_MISC_FAIL_TO_WRITE_BACKUP_RESULT = 56,
    META_MISC_FAIL_TO_GET_NVRAM_FOLDER_PATH = 57,
    META_MISC_FAIL_TO_GET_NVRAM_MUST_LIST = 58,
    META_STOP_CURRENT_PROCEDURE = 59,
    META_MISC_CUSTOMIZED_NVRAM_ERROR = 60,
    META_MISC_FOLDER_EMPTY_CHECKING_FAIL = 61,
    META_MISC_TOO_MANY_BACKUP_RESULT_FILE = 62,
    META_MISC_TOO_MANY_RESTORE_RESULT_FILE = 63,
    META_MISC_RESTORE_RESULT_FILE_NOT_EXIST = 64,
    META_MISC_RESTORE_RESULT_FILE_INCOMPLETE = 65,
    META_FAIL_TO_CELAR_ALL_IN_BACUP_FOLDER = 66,
    META_MISC_BACKUP_RESULT_FILE_NOT_EXIST = 67,
    META_MISC_BACKUP_RESULT_FILE_INCOMPLETE = 68,
    META_MISC_IMEI_MISMATCH = 69,
    META_MISC_SML_FILE_VERIFY_FAIL = 70,
    META_MISC_BACKUP_RESULT_NOT_ENOUGH_FOR_NEW_LOAD = 71,
    META_MISC_FAIL_TO_RESTORE_FILE = 72,
    META_MISC_FAIL_TO_WRITE_RESTORE_RESULT = 73,
    META_MISC_USE_WRONG_API_FOR_NEW_LOAD = 74,
    META_MISC_QUERY_TARGET_CAPABILITY_FAIL = 75,
    META_MISC_INI_SETTINGS_ERR_IN_NVRAM_SEC = 76,
    META_MISC_INI_SETTINGS_ERR_IN_TARGET_SEC = 77,
    META_MISC_INI_SETTINGS_ERR_IN_PC_SEC = 78,
    META_MISC_NO_FILES_NEED_TO_BE_UPLOAD = 79,
    META_FAT_ACTION_NOT_SUPPORT = 80,
    META_MISC_EMPTY_UPLOADFILES_AND_IMEI_SEC = 81,
    META_MISC_INI_SETTINGS_ERR_IN_MORE_SEC = 82,
    META_MISC_INI_SETTINGS_ERR_IN_DELETE_SEC = 83,
    META_MISC_CHECK_TARGET_NVRAM_FILES_FAIL = 84,
    META_MISC_FAIL_TO_GET_NVRAM_FOLDER_AMOUNT = 85,
    META_AUDIO_CHECK_WAVE_FILE_FAIL = 86,
    META_MISC_COLLECT_NVRAM_FOLDER_FILES_FAILED = 87,
    META_MISC_COLLECT_NVRAM_FOLDER_FILES_FIRST = 88,
    META_MISC_BACKUP_FILE_NOT_FOUND_IN_NVRAM = 89,
    META_MISC_BACKUP_MORE_FILE_NOT_FOUND_IN_NVRAM = 90,
    META_MISC_LOCAL_FS_UNKNOWN_ERROR = 91,
    META_MISC_RETORE_FILE_NOT_FOUND_IN_BACKUP_RESULT = 92,
    META_MISC_LEGACY_ADC_FILE_NOT_FOUND = 93,
    META_MISC_LEGACY_BARCODE_FILE_NOT_FOUND = 94,
    META_MISC_FILE_SIZE_MISMATCH = 95,
    META_MISC_RESTORE_TARGET_NOT_FOUND_IN_NVRAM = 96,
    META_UTIL_CONVERT_MULTIBYTE_TO_WCHAR_FAILED = 97,
    META_FAT_RECURSIVE_CREATE_FOLDER_FAILED = 98,
    META_FAT_COPY_INVALID_SOURCE_FOLDER = 99,
    META_FAT_COPY_EMPTY_SOURCE_FOLDER = 100,
    META_MISC_MULTIPLE_ENTRY_NOT_SUPPORTED = 101,
    META_MISC_INVALID_FORMAT = 102,
    META_FAT_FILE_LENGTH_ZERO = 103,
    META_MISC_INI_SETTINGS_ERR_IN_PC_FOLDER_SEC = 104,
    META_PC_FILE_NOT_FOUND = 105,
    META_MEMBER_FIELD_TYPE_NOT_FOUND = 106,
    META_MEMBER_FIELD_OFFSET_NOT_FOUND = 107,
    META_NVRAM_GET_KEY_LENGTH_CALLBACK_ERROR = 108,
    META_NVRAM_ALLOCATE_KEY_BUFFER_ERROR = 109,
    META_NVRAM_GET_KEY_BUFFER_CALLBACK_ERROR = 110,
    META_NVRAM_KEY_ENTRY_MISSING = 111,
    META_NVRAM_KEY_ENTRY_ERROR = 112,
    META_NVRAM_KEY_LENGTH_EXCEEDS_INTERNAL_BUFFER = 113,
    META_FAT_SPACE_SIZE_OVERFLOW = 114,
    META_LIB_INCONSISTENT = 115,
    META_INTERNAL_DB_ERROR = 116,
    META_REQUIRED_TOOL_VERSION_CHECK_FAILD = 117,               /**< 117, the current tool version does not fullfil the required tool version */
    META_CROSS_BRANCH_BACKUP_OPEN_FAILED = 118,
    META_CROSS_BRANCH_BACKUP_PARSE_FAILED = 119,
    META_CROSS_BRANCH_BACKUP_FILE_ATT_NOT_MATCH = 120,
    META_NVRAM_VALUE_NOT_LEGAL = 121,
    META_INIT_CONNECTION_STARTED = 122,
    META_QUERY_NO_MODEM_SUPPORT = 123,
    META_MEMBER_FIELD_SIZE_NOT_FOUND = 124,                       /**< 124, the member field size look-up failed */
    META_MDLOGGING_SET_FILTER_COMMAND_ERROR = 125,
    META_RF_RESULT_PENDING = 126, /**< the calibration result is pending, waiting for target to complete */
    META_URF_RESULT_PENDING = 127, /**< the calibration result is pending, waiting for target to complete */
    META_MODE_TRACE_CONFIG_FAILED = 128, /**< setting up META mode trace parameter failed */
    META_NVRAM_DB_GET_ENUM_TYPE_FAIL = 129,
    META_NOT_SUPPORTED_VC_CONFIG = 130, /**< Not supported virtual channel configuration, for the MODEM protocol is TST or DHL */
    META_MODEM_EXCEPTION = 131,
    META_MAUI_DB_NOT_FIND,
    META_LAST_RESULT

} META_RESULT;

typedef enum
{
    META_BAUD2400 = 0, /**< Baud Rate: 2400bps */
    META_BAUD4800 = 1, /**< Baud Rate: 4800bps */
    META_BAUD9600 = 2, /**< Baud Rate: 9600bps */
    META_BAUD14400 = 3, /**< Baud Rate: 14400bps */
    META_BAUD19200 = 4, /**< Baud Rate: 19200bps */
    META_BAUD57600 = 5, /**< Baud Rate: 57600bps */
    META_BAUD115200 = 6, /**< Baud Rate: 115200bps */
    META_BAUD230400 = 7, /**< Baud Rate: 230400bps */
    META_BAUD460800 = 8, /**< Baud Rate: 460800bps */
    META_BAUD921600 = 9, /**< Baud Rate: 921600bps */
    META_BAUD1500000 = 10, /**< Baud Rate: 1500000bps */
    META_BAUD_END = 0xFF
} META_COMM_BAUDRATE;

typedef enum
{
    META_NO_FLOWCTRL = 0,   /**< no flow control */
    META_SW_FLOWCTRL = 1,   /**< enable S/W flow control (0x11: 0x77, 0x01; 0x13: 0x77, 0x02; 0x77: 0x77, 0x03) */
    META_ADV_SW_FLOWCTRL = 2,  /**< enable ADV S/W flow control (0x11: 0x77, 0xEE; 0x13: 0x77, 0xEC; 0x77: 0x77, 0x88) */
    META_FLOWCTRL_END
} META_FLOWCTRL;

typedef struct
{
    char    BB_CHIP[64];    /**< BaseBand chip version */
    char    ECO_VER[4];     /**< ECO version */
    char    DSP_FW[64];     /**< DSP firmware version */
    char    DSP_PATCH[64];  /**< DSP patch version */
    char    SW_VER[64];     /**< S/W version */
    char    HW_VER[64];     /**< H/W board version */
    char    MELODY_VER[64]; /**< Melody version */
    char    SW_FLAVOR[64];  /**< Build flavor information*/
} VerInfo_Cnf;

typedef struct
{
    unsigned short      com_port_list[255];
    unsigned short      com_port_num;
    unsigned int        ms_connect_timeout; /**< [META] META enumerate port timeout value */
} META_Enumerate_USB_Req;

typedef struct
{
    int                 com_port;
    META_COMM_BAUDRATE  baudrate[12];       /**< [META] META stage baudrate polling array, it must end with META_BAUD_END. */
    META_FLOWCTRL       flowctrl;           /**< [META] META stage uart flow control type. */
    BOOT_META_ARG       boot_meta_arg;      /**< [BootROM] please refer to brom.h */
    unsigned int        ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
} META_Connect_Req;

typedef enum
{
    GENERAL_MODE = 0,
    CATCHER_RELAY_MODE = 1,
    LOGGING_TOOL_RELAY_MODE = CATCHER_RELAY_MODE,
    FILE_DUMP_MODE = 2,
    TRACE_MODE_NUM
} META_TRACE_MODE;

typedef  struct
{
	bool            enable;
	char*           dump_file_path;
} META_COMM_TRACE_PARA_T;

typedef  struct
{
    META_TRACE_MODE        mode;
    int                    modem_index;
    char*                  dump_file_path;
    META_COMM_TRACE_PARA_T commTrace;                /**< [META] META dump com port raw data */
} META_MODE_TRACE_PARA_T;

typedef struct
{
    int                    com_port;
    META_COMM_BAUDRATE     baudrate[12];       /**< [META] META stage baudrate polling array, it must end with META_BAUD_END. */
    META_FLOWCTRL          flowctrl;           /**< [META] META stage uart flow control type. */
    BOOT_META_ARG          boot_meta_arg;      /**< [BootROM] please refer to brom.h */
    unsigned int           ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
    unsigned int           usb_enable: 1;      /**< [META] Connect target with UART or USB, 0: UART 1: USB others:reserved */
    unsigned int           InMetaMode: 1;      /**< [META] Decide that need boot META or not 0:need boot META 1:already in meta mode */
    unsigned int           escape: 1;          /**< [META] Force to connect target with escaping */
    unsigned int           close_com_port: 1;  /**< [META] Choose to close com port or handle */
    META_MODE_TRACE_PARA_T trace_para;         /**< [META] META mode trace parameters */
    unsigned int           protocol: 4;        /**< [META] Only for MultiMode connection API. When InMetaMode==true, connect target with different protocol 0||1:TST 2:DHL */
    unsigned int           channel_type: 4;    /**< [META] Only for MultiMode connection API. Connect target with different channel type, 0||1: native channel, 2: tunneling, 3: tunneling with check sum ignored */
} META_Connect_Ex_Req;

typedef struct
{
    unsigned int m_u4TargetMainVersion;
    unsigned int m_u4TargetMinorVersion;
    unsigned int m_u4TargetBuildNum;
} META_VER_REQUIRED_BY_TARGET;

typedef struct
{
    META_COMM_BAUDRATE  final_baudrate;                 /**< [META] Detected META stage baudrate. */
    unsigned int        meta_ver_required_by_target;    /**< [META] Target required META_DLL version.  ==> always return 0 */
    BOOT_RESULT         boot_result;                    /**< [BootROM] boot-up result. */
    STATUS_E            boot_meta_ret;                  /**< [BROM_DLL] The return code of Boot_META function. */
    META_VER_REQUIRED_BY_TARGET   m_rTargetVer;         /**< [META] Target required META_DLL version. */
} META_Connect_Report;

typedef struct
{
    int                 com_port;
    BOOT_META_ARG       boot_meta_arg;      /**< [BootROM] please refer to brom.h */
    unsigned int        ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
} META_ConnectByUSB_Req;

typedef struct
{
    unsigned int        meta_ver_required_by_target;    /**< [META] Target required META_DLL version.  ==> always return 0 */
    BOOT_RESULT         boot_result;                    /**< [BootROM] boot-up result. */
    STATUS_E            boot_meta_ret;                  /**< [BROM_DLL] The return code of Boot_META function. */
    META_VER_REQUIRED_BY_TARGET   m_rTargetVer;         /**< [META] Target required META_DLL version. */
} META_ConnectByUSB_Report;

typedef struct
{
    int                 com_port;
    META_COMM_BAUDRATE  baudrate[11];       /**< [META] META stage baudrate polling array, it must end with META_BAUD_END. */
    META_FLOWCTRL       flowctrl;           /**< [META] META stage uart flow control type. */
    unsigned int        ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
} META_ConnectInMETA_Req;

typedef struct
{
    int                 com_port;
    META_COMM_BAUDRATE  baudrate[11];       /**< [META] META stage baudrate polling array, it must end with META_BAUD_END. */
    META_FLOWCTRL       flowctrl;           /**< [META] META stage uart flow control type. */
    unsigned int        ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
    bool                escape;             /**< [META] Force to connect target with escaping */
} META_ConnectInMETA_Ex_Req;

typedef struct
{
    META_COMM_BAUDRATE            final_baudrate;                   /**< [META] Detected META stage baudrate. */
    unsigned int                  meta_ver_required_by_target;  /**< [META] Target required META_DLL version.  ==> always return 0 */
    META_VER_REQUIRED_BY_TARGET   m_rTargetVer;         /**< [META] Target required META_DLL version. */
} META_ConnectInMETA_Report;

//-----------------------------------------------------//
//  META General: callback function definition         //
//-----------------------------------------------------//
typedef void (__stdcall* META_Error_CallBack)(const META_CNF_ERR_CODE  mr);
typedef void (__stdcall* META_SysTrace_CallBack)(const char* sys_trace, void* arg);
typedef void (__stdcall* META_GET_VERSION_INFO_CNF)(const VerInfo_Cnf*  cnf, const short token, void* usrData);

//-----------------------------------------------------//
//  META for CTI                                       //
//-----------------------------------------------------//
typedef enum
{
    CTI_OK = 0,
    CTI_MISSING_HEADER = 1,
    CTI_CORRUPTED_FAME = 2,
    CTI_EXCEED_LEN = 3,
    CTI_END
} CTI_RET_ENUM;

typedef void (__stdcall* META_CTI_CallBack)(CTI_RET_ENUM  ret, const int size, const unsigned char* data, void* param);
META_RESULT  __stdcall META_CTI_SendPacketCmd(const unsigned char* pPayLoadBuffer, int nPayloadLength);
META_RESULT  __stdcall META_CTI_SendPacketCmd_r(const int meta_handle, const unsigned char* pPayLoadBuffer, int nPayloadLength);
META_RESULT  __stdcall META_CTI_SetPacketCallback(META_CTI_CallBack  pCBFunc, void* param);
META_RESULT  __stdcall META_CTI_SetPacketCallback_r(const int meta_handle, META_CTI_CallBack  pCBFunc, void* param);

//-----------------------------------------------------//
//  Switch TST message format                          //
//-----------------------------------------------------//
typedef enum
{
    META_TST_MSG_2G = 0,
    META_TST_MSG_3G = 1,
    META_TST_MSG_FORMAT_END
} META_TST_MSG_FORMAT;

META_RESULT  __stdcall META_SetTstMsgFormat(META_TST_MSG_FORMAT  msg_fmt);
META_RESULT  __stdcall META_SetTstMsgFormat_r(const int meta_handle, META_TST_MSG_FORMAT  msg_fmt);

//-----------------------------------------------------//
//  META Debug: exported debug function definition     //
//-----------------------------------------------------//
META_RESULT  __stdcall META_DebugOn();
META_RESULT  __stdcall META_DebugOn_With_FilePath(const char* filepath);
/**
 * \brief turn on META DLL debug log in c:\META_DLL_HANDLE%d_COM%d.log the
 * for example the meta_handle is 0 and COM port number is 10 then the log file will be c:\META_DLL_HANDLE0_COM10.log
 * \param meta_handle META handle
 */
META_RESULT  __stdcall META_DebugOn_ex(const int meta_handle);
/**
 * \brief turn on META DLL debug log in c:\META_DLL_HANDLE%d_COM%d.log the
 * for example the meta_handle is 0 and COM port number is 10 then the log file will be c:\META_DLL_HANDLE0_COM10.log
 * \param meta_handle META handle
 * \param [OUT] path the buffer to store the log location for upper layer (no boundary check to this function)
 *              the underlying buffer is 260 bytes
 */
META_RESULT  __stdcall META_DebugOn_ex2(const int meta_handle, char* path);
META_RESULT  __stdcall META_DebugOn_With_Handle_FilePath(const int meta_handle, const char* filename);
META_RESULT  __stdcall META_DebugOn_With_Handle_FilePath_Cumulative(const int meta_handle, const char* filename);
META_RESULT  __stdcall META_DebugOff();
META_RESULT  __stdcall META_DebugOff_With_Handle(const int meta_handle);
META_RESULT  __stdcall META_DebugClear();
META_RESULT  __stdcall META_DebugClear_With_Handle(const int meta_handle);

//-----------------------------------------------------//
//  META UnitTest                                      //
//-----------------------------------------------------//

typedef struct
{
    unsigned int    m_TestCaseID;
    const char*     m_pDescription;
} META_UT_TestCaseID_T;

void __stdcall META_QueryTestCase(META_UT_TestCaseID_T**  ppTestCase, unsigned int*  pTestCaseCount);
void __stdcall META_UnitTest(const unsigned int*  p_TestCaseID_Array, unsigned int  TestCaseCount);

//-----------------------------------------------------//
//  META General: exported function definition         //
//-----------------------------------------------------//

#define     FT_MT_UNKNOWN  0
#define     FT_MT6305  1
#define     FT_MT6318  2
#define     FT_MT6326  3

typedef struct
{
    unsigned char   id;
} PMIC_ID;
typedef struct
{
    unsigned int    pcl;
} RF_GetITC_PCL;
// General
void  __stdcall META_GetDLLVer(unsigned int* major_ver, unsigned int* minor_ver, unsigned int* build_num, unsigned int* patch_num);
void  __stdcall META_GetDLLInfo(const char** pp_version, const char** pp_release_type, const char** pp_build_date, const char** pp_load_path);
void  __stdcall META_GetDLLInfo_r(const int meta_handle, const char** pp_version, const char** pp_release_type, const char** pp_build_date, const char** pp_load_path);
void  __stdcall META_Cancel(const short token);
void  __stdcall META_Cancel_r(const int meta_handle, const short token);
void  __stdcall META_CancelAllBlockingCall(void);
void  __stdcall META_CancelAllBlockingCall_r(const int meta_handle);
META_RESULT  __stdcall META_QueryIfFunctionSupportedByTarget(unsigned int ms_timeout, const char* query_func_name);
META_RESULT  __stdcall META_QueryIfFunctionSupportedByTarget_r(const int meta_handle, unsigned int ms_timeout, const char* query_func_name);
META_RESULT  __stdcall META_QueryIfTargetSupportISP(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportISP_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportAcoustic16level(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportAcoustic16level_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportAudioParam45Tap(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportAudioParam45Tap_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetIsLowCostSingleBankFlash(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetIsLowCostSingleBankFlash_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryPMICID(unsigned int ms_timeout, PMIC_ID*  cnf);
META_RESULT  __stdcall META_QueryPMICID_r(const int meta_handle, unsigned int ms_timeout, PMIC_ID*  cnf);
META_RESULT  __stdcall META_BTPowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_BTPowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportWifiALC(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportWifiALC_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryITC_PCL(unsigned int ms_timeout, RF_GetITC_PCL*  cnf);
META_RESULT  __stdcall META_QueryITC_PCL_r(const int meta_handle, unsigned int ms_timeout, RF_GetITC_PCL*  cnf);
META_RESULT  __stdcall META_QueryIfTargetSupportDRC(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfTargetSupportDRC_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfBTPowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_QueryIfBTPowerOn_r(const int meta_handle, unsigned int ms_timeout);

//-----------------------------------------------------//
//  UTILITY--ENABLE WATCHDOG                           //
//-----------------------------------------------------//
#define GPIO_DEV_LED_MAINLCD 0
//#define GPIO_DEV_LED_SUBLCD 1

typedef struct
{
    unsigned int    ms_timeout_interval;
} FtWatchDog;

typedef struct
{
    unsigned char       led_light_level;
} FtLEDLevel;

typedef struct
{
    unsigned char       lcd_type;
    unsigned char       lcd_light_level;
} FtLCDLevel;

typedef struct
{
    unsigned char       onoff;
} FtVibratorOnOff;

typedef struct
{
    unsigned char       m_rtc_sec;    /**< seconds after the minute   - [0,59]  */
    unsigned char       m_rtc_min;    /**< minutes after the hour     - [0,59]  */
    unsigned char       m_rtc_hour;   /**< hours after the midnight   - [0,23]  */
    unsigned char       m_rtc_day;    /**< day of the month           - [1,31]  */
    unsigned char       m_rtc_mon;    /**< months                     - [1,12] */
    unsigned char       m_rtc_wday;   /**< days in a week             - [1,7] */
    unsigned char       m_rtc_year;
} T_Rtc;

typedef enum
{
    DATA_LIBRARY_MODE_OPENDB = 0,
    DATA_LIBRARY_MODE_EDB = 1
} DATA_LIBRARY_MODE;

META_RESULT  __stdcall META_EnableWatchDogTimer(unsigned int ms_timeout, FtWatchDog* req);
META_RESULT  __stdcall META_EnableWatchDogTimer_r(const int meta_handle, unsigned int ms_timeout, FtWatchDog* req);

META_RESULT  __stdcall META_SetLEDLightLevel(unsigned int ms_timeout, FtLEDLevel* req);
META_RESULT  __stdcall META_SetLEDLightLevel_r(const int meta_handle, unsigned int ms_timeout, FtLEDLevel* req);

META_RESULT  __stdcall META_SetVibratorOnOff(unsigned int ms_timeout, FtVibratorOnOff* req);
META_RESULT  __stdcall META_SetVibratorOnOff_r(const int meta_handle, unsigned int ms_timeout, FtVibratorOnOff* req);

META_RESULT  __stdcall META_QueryLocalTime(unsigned int ms_timeout, T_Rtc*  cnf);
META_RESULT  __stdcall META_QueryLocalTime_r(const int meta_handle, unsigned int ms_timeout, T_Rtc*  cnf);

META_RESULT  __stdcall META_SetMainSubLCDLightLevel(unsigned int ms_timeout, FtLCDLevel* req);
META_RESULT  __stdcall META_SetMainSubLCDLightLevel_r(const int meta_handle, unsigned int ms_timeout, FtLCDLevel* req);


// timer-related APIs
META_RESULT  __stdcall META_StartTimer();
META_RESULT  __stdcall META_StartTimer_r(const int meta_handle);
META_RESULT  __stdcall META_StopTimer();
META_RESULT  __stdcall META_StopTimer_r(const int meta_handle);
META_RESULT __stdcall META_GetProcessTime(unsigned int*  pProcessTime, unsigned short* pNumAPIs);
META_RESULT __stdcall META_GetProcessTime_r(const int meta_handle, unsigned int* pProcessTime, unsigned short* pNumAPIs);

const char* __stdcall META_GetErrorString(META_RESULT  ErrCode);
const char* __stdcall META_BaudrateEnumToName(META_COMM_BAUDRATE  baudrate);

// Initialization
META_RESULT  __stdcall META_GetAvailableHandle(int* p_meta_handle);
META_RESULT  __stdcall META_GetAvailableHandle_Ex(int* p_meta_handle, DATA_LIBRARY_MODE mode);
META_RESULT  __stdcall META_Init(const META_Error_CallBack  cb);
META_RESULT  __stdcall META_Init_r(const int meta_handle, const META_Error_CallBack  cb);
/* [Dual Talk] */
typedef struct
{
    unsigned int number_of_md: 8;
    unsigned int active_md_idx: 8;
    unsigned int multi_talk: 1; /**< 0: no multi-talk, 1: multi-talk */
    unsigned int multi_frame_type: 1; /**< 0: all MD use the same frame type, 1: each MD is assigned a frame type */
    unsigned int number_of_mdSwImg: 4; /**< world phone (multi-MDtype) */
    unsigned int active_mdtype_idx: 4;
    unsigned int multi_mdtype: 1; /**< 0: no multi-MDtype, 1: multi-MDtype */
    unsigned int multi_md_capability_support: 1;
    unsigned int reserved: 4;
} META_MD_Query_Result_T;
typedef enum
{
    md_type_invalid = 0,
    modem_2g = 1,
    modem_3g = 2,
    modem_wg = 3,
    modem_tg = 4,
    modem_lwg = 5,
    modem_ltg = 6,
    modem_ltng = 7,
    modem_ultg = 8,
    modem_ulwg = 9,
    modem_ulwtg = 10,
    modem_ulwcg = 11,
    modem_ulwctg = 12,
    modem_ulttg = 13,
    modem_ulfwg = 14,
    modem_ulfwcg = 15,
    num_modem_type  //number of md type need to -1, bescause "md_type_invalid = 0"
} modem_type_t;
const char* __stdcall META_GetModemTypeString(modem_type_t mdType);
//for switch mdtype callback arguments
typedef struct
{
    unsigned int md_idx: 8;
    unsigned int mdtype_idx: 8;
    unsigned int reserved: 16;
} META_MDTYPE_Switch_Param_T;
/**
 * \brief the callback function for querying the multi-talk capability on the target system
 * \return the query result
 */
typedef META_MD_Query_Result_T (__stdcall* META_MD_Query_CallBack)(void* arg);
/**
 * \brief the callback function for MODEM switching
 * \return 0: success, otherwise, fail
 */
typedef int (__stdcall* META_MD_Switch_CallBack)(void* arg);
/**
 * \brief the callback function for MODEM TYPEswitching
 * \return 0: success, otherwise, fail
 */
typedef int (__stdcall* META_MDTYPE_Switch_CallBack)(META_MDTYPE_Switch_Param_T mdtype_switch_param, void* arg);
/**
 * \brief non-reentrant version of META_Init_Ex_r
 */
META_RESULT  __stdcall META_Init_Ex(const META_Error_CallBack err_cb,
                                    const META_MD_Query_CallBack md_query_cb,
                                    void* md_query_arg,
                                    const META_MD_Switch_CallBack md_switch_cb,
                                    void* md_switch_arg
                                   );
/**
 * \details META_Init extended version for multiple-talk project
 * \param meta_handle the operating session ID (meta_handle)
 * \param err_cb the error handler for META DLL
 * \param md_query_cb the switching implementation of upper layer (OPTIONAL)
 *        in different product segment, the multiple-talk product could be all-in-one chip or
 *        external MODEM solution
 *        external MODEM solution needs extra switching procedure
 *        all-in-one solution needs no extra switching procedure
 * \param md_query_arg the argument to be passed to md_query_cb (OPTIONAL)
 * \param md_switch_cb the switching implementation of upper layer (OPTIONAL)
 * \param md_switch_arg the argument to be passed to md_switch_arg (OPTIONAL)
 * \return On success: META_SUCCESS
 *         On fail: META_FAILED or META_INVALID_ARGUMENTS
 */
META_RESULT  __stdcall META_Init_Ex_r(const int meta_handle,
                                      const META_Error_CallBack err_cb,
                                      const META_MD_Query_CallBack md_query_cb,
                                      void* md_query_arg,
                                      const META_MD_Switch_CallBack md_switch_cb,
                                      void* md_switch_arg
                                     );
/**
 * \brief non-reentrant version of META_Init_Ex_2_r
 */
META_RESULT  __stdcall META_Init_Ex_2(const META_Error_CallBack err_cb,
                                      const META_MD_Query_CallBack md_query_cb,
                                      void* md_query_arg,
                                      const META_MD_Switch_CallBack md_switch_cb,
                                      void* md_switch_arg,
                                      const META_MDTYPE_Switch_CallBack mdtype_switch_cb,
                                      void* mdtype_switch_arg
                                     );
/**
 * \details META_Init extended version for multiple-modemtype project [world phone]
 * \param meta_handle the operating session ID (meta_handle)
 * \param err_cb the error handler for META DLL
 * \param md_query_cb the switching implementation of upper layer (OPTIONAL)
 *        in different product segment, the multiple-talk product could be all-in-one chip or
 *        Multiple MODEM Typesolution
 *        Multiple MODEM solution needs extra switching procedure
 *        all-in-one solution needs no extra switching procedure
 * \param md_query_arg the argument to be passed to md_query_cb (OPTIONAL)
 * \param md_switch_cb the switching implementation of upper layer (OPTIONAL)
 * \param md_switch_arg the argument to be passed to md_switch_arg (OPTIONAL)
 * \param mdtype_switch_cb the mdtype switching implementation of upper layer (OPTIONAL)
 * \param mdtype_switch_arg the argument to be passed to mdtype_switch_arg (OPTIONAL)
 * \retval META_SUCCESS successful
 * \retval META_FAILED failed
 * \retval META_INVALID_ARGUMENTS invalid arguments
 */
META_RESULT  __stdcall META_Init_Ex_2_r(const int meta_handle,
                                        const META_Error_CallBack err_cb,
                                        const META_MD_Query_CallBack md_query_cb,
                                        void* md_query_arg,
                                        const META_MD_Switch_CallBack md_switch_cb,
                                        void* md_switch_arg,
                                        const META_MDTYPE_Switch_CallBack mdtype_switch_cb,
                                        void* mdtype_switch_arg
                                       );
/**
 * \brief non-reentrant version of META_SwitchCurrentModem_r
 *        this API switch the operating MODEM of meta_handle 0
 */
META_RESULT  __stdcall META_SwitchCurrentModem(const unsigned int ms_timeout, const unsigned int md_index);
/**
 * \details switch the current operating MODEM to specified md_index
 * \param meta_handle the operating session ID (meta_handle)
 * \param ms_timeout time out (ms)
 * \param md_index the specified md_index to be switched to
 * \retval META_SUCCESS Successful
 * \retval META_MAUI_DB_INCONSISTENT if the DB does not match with the switched MODEM
 * \retval META_FAILED failed to switch to specifed md_index
 * \retval META_FUNC_NOT_IMPLEMENT_YET for single-talk project
 * \retval META_INVALID_ARGUMENTS for not supported md_index
 *         for example, md_index 0 and 1 are valid on dual-talk projects
 */
META_RESULT  __stdcall META_SwitchCurrentModem_r(const int meta_handle, const unsigned int ms_timeout, const unsigned int md_index);
/**
 * \brief non-reentrant version of META_QueryCurrentModem_r
 *        this API query the operating MODEM of meta_handle 0
 */
META_RESULT  __stdcall META_QueryCurrentModem(unsigned int* md_index);
/**
 * \brief Query the current operating MODEM of the specified meta_handle
 * \param meta_handle the operating session ID (meta_handle)
 * \param [out] md_index the query result
 * \return On success: META_SUCCESS
 */
META_RESULT  __stdcall META_QueryCurrentModem_r(const int meta_handle, unsigned int* md_index);
/**
 * \brief non-reentrant version of META_SwitchCurrentModem_r
 *        this API switch the operating MODEM of meta_handle 0
 */
META_RESULT  __stdcall META_SwitchCurrentModemEx(const unsigned int ms_timeout, const unsigned int md_index, const unsigned int protocol, const unsigned int channel_type, const META_MODE_TRACE_PARA_T* trace_para);
/**
 * \details switch the current operating MODEM to specified md_index and protocol and channel type
 * \param meta_handle the operating session ID (meta_handle)
 * \param ms_timeout time out (ms)
 * \param md_index the specified md_index to be switched to
 * \param protocol the protocol type of the specified meta handle
 * \param channel_type the channel type of the specified meta handle
 * \param trace_para the META mode trace parameter of the specified meta handle
 * \retval META_SUCCESS Successful
 * \retval META_MAUI_DB_INCONSISTENT if the DB does not match with the switched MODEM
 * \retval META_FAILED failed to switch to specifed md_index
 * \retval META_FUNC_NOT_IMPLEMENT_YET for single-talk project
 * \retval META_INVALID_ARGUMENTS for not supported md_index
 *         for example, md_index 0 and 1 are valid on dual-talk projects
 */
META_RESULT  __stdcall META_SwitchCurrentModemEx_r(const int meta_handle, const unsigned int ms_timeout, const unsigned int md_index, const unsigned int protocol, const unsigned int channel_type, const META_MODE_TRACE_PARA_T* trace_para);
/**
 * \brief non-reentrant version of META_QueryCurrentModem_r
 *        this API query the operating MODEM of meta_handle 0
 */
META_RESULT  __stdcall META_QueryCurrentModemEx(unsigned int* md_index, unsigned int* protocol, unsigned int* channel_type);
/**
 * \details Query the current operating MODEM of the specified meta_handle
 * \param meta_handle the operating session ID (meta_handle)
 * \param [out] md_index the query result
 * \param [out] protocol the protocol type used for specified meta handle
 * \param [out] channel_type the channel type used for specified meta handle
 * \return On success: META_SUCCESS
 */
META_RESULT  __stdcall META_QueryCurrentModemEx_r(const int meta_handle, unsigned int* md_index, unsigned int* protocol, unsigned int* channel_type);
META_RESULT  __stdcall META_SetSysTraceCallback(const META_SysTrace_CallBack  sys_cb, void* arg);
META_RESULT  __stdcall META_SetSysTraceCallback_r(const int meta_handle, const META_SysTrace_CallBack  sys_cb, void* arg);
void  __stdcall META_Deinit(void);
void  __stdcall META_Deinit_r(int* p_meta_handle);
/**
 * \brief non-reentrant version of META_SetInfo4SwitchModemType_r
 */
META_RESULT  __stdcall META_SetInfo4SwitchModemType(const unsigned int ms_timeout, const unsigned int md_index, const unsigned int mdtype_index);
/**
 * \details Set the current operating MODEM type of the specified meta_handle
 * \param meta_handle the operating session ID (meta_handle)
 * \param ms_timeout time out (ms)
 * \param md_index index of MODEM handle
 * \param mdtype_index index of MODEM software type handle
 * \return On success: META_SUCCESS
 */
META_RESULT  __stdcall META_SetInfo4SwitchModemType_r(const int meta_handle, const unsigned int ms_timeout, const unsigned int md_index, const unsigned int mdtype_index);
// connect with target
META_RESULT  __stdcall META_ConnectWithTarget(const META_Connect_Req*  req, int* p_bootstop, META_Connect_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithTarget_r(const int meta_handle, const META_Connect_Req*  req, int* p_bootstop, META_Connect_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithTargetEx(const META_Connect_Ex_Req*  req, int* p_bootstop, META_Connect_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithTargetEx_r(const int meta_handle, const META_Connect_Ex_Req*  req, int* p_bootstop, META_Connect_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithMultiModeTarget(const META_Connect_Ex_Req*  req, const unsigned int requestLengthlength, int* p_bootstop, META_Connect_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithMultiModeTarget_r(const int meta_handle, const META_Connect_Ex_Req*  req, const unsigned int requestLengthlength, int* p_bootstop, META_Connect_Report*  p_report);
// dsiconnect and shutdown target
META_RESULT  __stdcall META_DisconnectWithTarget(void);
META_RESULT  __stdcall META_DisconnectWithTarget_r(const int meta_handle);

// connect with target when target already in meta mode
META_RESULT  __stdcall META_ConnectInMetaMode(const META_ConnectInMETA_Req*  req, int* p_bootstop, META_ConnectInMETA_Report*  p_report);
META_RESULT  __stdcall META_ConnectInMetaMode_r(const int meta_handle, const META_ConnectInMETA_Req* req, int* p_bootstop, META_ConnectInMETA_Report* p_report);
// connect with target when target already in meta mode for SP connection via UART with escaping
META_RESULT  __stdcall META_ConnectInMetaMode_Ex(const META_ConnectInMETA_Ex_Req* req, int* p_bootstop, META_ConnectInMETA_Report* p_report);
META_RESULT  __stdcall META_ConnectInMetaMode_Ex_r(const int meta_handle, const META_ConnectInMETA_Ex_Req* req, int* p_bootstop, META_ConnectInMETA_Report* p_report);
// dsiconnect without shutdown target
META_RESULT  __stdcall META_DisconnectInMetaMode(void);
META_RESULT  __stdcall META_DisconnectInMetaMode_r(const int meta_handle);

// USB-related connect
META_RESULT  __stdcall META_ConnectInMetaModeByUSB(const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report);
META_RESULT  __stdcall META_ConnectInMetaModeByUSB_r(const int meta_handle, const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report);

META_RESULT  __stdcall META_ConnectWithTargetByUSB(const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report);
META_RESULT  __stdcall META_ConnectWithTargetByUSB_r(const int meta_handle, const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report);

META_RESULT  __stdcall META_ConnectWithTargetByUSBEx(const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report, bool close_com_port);
META_RESULT  __stdcall META_ConnectWithTargetByUSBEx_r(const int meta_handle, const META_ConnectByUSB_Req*  req, int* p_bootstop, META_ConnectByUSB_Report*  p_report, bool close_com_port);
META_RESULT  __stdcall META_QueryConnectionMedia(unsigned int* indicator, int* comport);
META_RESULT  __stdcall META_QueryConnectionMedia_r(const int meta_handle, unsigned int* indicator, int* comport);
META_RESULT  __stdcall META_QueryConnectionInfo(unsigned int* protocol, unsigned int* channel_type);
META_RESULT  __stdcall META_QueryConnectionInfo_r(const int meta_handle, unsigned int* protocol, unsigned int* channel_type);

META_RESULT  __stdcall META_GetDynamicUSBComPort(unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop);
META_RESULT  __stdcall META_GetDynamicUSBComPort_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop);
META_RESULT  __stdcall META_GetDynamicUSBComPortWithPrefix(unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, const char* prefix);
META_RESULT  __stdcall META_GetDynamicUSBComPortWithPrefix_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, const char* prefix);
META_RESULT  __stdcall META_GetDynamicUSBComPortEx(unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, char* info, int length);
META_RESULT  __stdcall META_GetDynamicUSBComPortEx_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, char* info, int length);
META_RESULT  __stdcall META_GetDynamicUSBComPortExWithFilter(unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, char* info, int length, char* valid_usb_info);
META_RESULT  __stdcall META_GetDynamicUSBComPortExWithFilter_r(const int meta_handle, unsigned int ms_scan_timeout, unsigned short* com_port, int* p_scanstop, char* info, int length, char* valid_usb_info);

META_RESULT  __stdcall META_ConnectCOMChannelWithMultiTarget_r(const int meta_handle, const META_Connect_Ex_Req* req);
META_RESULT  __stdcall META_DisconnectCOMChannelWithMultiTarget_r(const int meta_handle);
/**
 * \brief Get target S/W, H/W and Melody version with fixed timeout value in asynchronous way
 * \sa META_GetTargetVerInfo_r
 */
META_RESULT  __stdcall META_GetTargetVerInfo(const META_GET_VERSION_INFO_CNF  cb, short* token, void* usrData);
/**
 * \brief Get target S/W, H/W and Melody version with fixed timeout value in asynchronous way
 * \param meta_handle meta handle
 * \param cb callback function for the get target version result
 * \param[out] token the given token value of the transaction
 * \param usrData the parameter for the callback function
 */
META_RESULT  __stdcall META_GetTargetVerInfo_r(const int meta_handle, const META_GET_VERSION_INFO_CNF  cb, short* token, void* usrData);
/**
 * \brief Get target S/W, H/W and Melody version with user defined timeout value in asynchronous way
 * \sa META_GetTargetVerInfo2_r
 */
META_RESULT  __stdcall META_GetTargetVerInfo2(const int ms_timeout, const META_GET_VERSION_INFO_CNF cb, short* token, void* usrData);
/**
 * \brief Get target S/W, H/W and Melody version with user defined timeout value in asynchronous way
 * \param meta_handle meta handle
 * \param ms_timeout timeout value in ms
 * \param cb callback function for the get target version result
 * \param[out] token the given token value of the transaction
 * \param usrData the parameter for the callback function
 */
META_RESULT  __stdcall META_GetTargetVerInfo2_r(const int meta_handle, const int ms_timeout, const META_GET_VERSION_INFO_CNF cb, short* token, void* usrData);
/**
 * \brief Get target S/W, H/W and Melody version with fixed timeout value in synchronous way
 * \sa META_GetTargetVerInfoEx_r
 */
META_RESULT  __stdcall META_GetTargetVerInfoEx(VerInfo_Cnf* cnf);
/**
 * \brief Get target S/W, H/W and Melody version with fixed timeout value in synchronous way
 * \param meta_handle meta handle
 * \param cnf the result of get target version
 */
META_RESULT  __stdcall META_GetTargetVerInfoEx_r(const int meta_handle, VerInfo_Cnf* cnf);
/**
 * \brief Get target S/W, H/W and Melody version with user defined timeout value in synchronous way
 * \sa META_GetTargetVerInfoEx2_r
 */
META_RESULT  __stdcall META_GetTargetVerInfoEx2(const int ms_timeout, VerInfo_Cnf* cnf);
/**
 * \brief Get target S/W, H/W and Melody version with user defined timeout value in synchronous way
 * \param meta_handle meta handle
 * \param ms_timeout timeout value in ms
 * \param cnf the result of get target version
 */
META_RESULT  __stdcall META_GetTargetVerInfoEx2_r(const int meta_handle, const int ms_timeout, VerInfo_Cnf* cnf);
// Shutdown target
META_RESULT  __stdcall META_ShutDownTarget(void);
META_RESULT  __stdcall META_ShutDownTarget_r(const int meta_handle);
// Get target send bytes
META_RESULT  __stdcall META_GetReadBytes(unsigned long* read_bytes);
META_RESULT  __stdcall META_GetReadBytes_r(const int meta_handle, unsigned long* read_bytes);
META_RESULT  __stdcall META_GetReadBytesEx(unsigned __int64* read_bytes);
META_RESULT  __stdcall META_GetReadBytesEx_r(const int meta_handle, unsigned __int64* read_bytes);

// ***** Expired Functions -- BEGIN ***** //
// these functions are expired, we encourage you to use META_ConnectWithTarget and META_DisconnectWithTarget
/**
 * \brief non-reentrant version of META_COMM_Set_Baudrate_r
 * \deprecated This API is deprecated.
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Set_Baudrate(const META_COMM_BAUDRATE  baudrate);
/**
 * \details set baud rate for current meta handle
 * \deprecated This API is deprecated.
 * \param meta_handle meta handle
 * \param baudrate baud rate
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Set_Baudrate_r(const int meta_handle, const META_COMM_BAUDRATE  baudrate);
/**
 * \brief non-reentrant version of META_COMM_Start_r
 * \deprecated This API is deprecated.
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Start(const int comm_port, const META_FLOWCTRL  flowctrl);
/**
 * \details start the underlaying connection handle
 * \deprecated This API is deprecated.
 * \param meta_handle meta handle
 * \param comm_port the number of com port
 * \param flowctrl flow control mode
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Start_r(const int meta_handle, const int comm_port, const META_FLOWCTRL  flowctrl);
/**
 * \brief non-reentrant version of META_COMM_Stop_r
 * \deprecated This API is deprecated.
 * \sa META_DisconnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Stop(void);
/**
 * \details stop the underlaying connection handle
 * \deprecated This API is deprecated.
 * \param meta_handle meta handle
 * \sa META_DisconnectWithTarget_r
 */
META_RESULT  __stdcall META_COMM_Stop_r(const int meta_handle);
/**
 * \brief non-reentrant version of META_WaitForTargetReady_r
 * \deprecated This API is deprecated.
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_WaitForTargetReady(unsigned int ms_waiting_time, unsigned int request_count);
/**
 * \details start the underlaying connection handle
 * \deprecated This API is deprecated.
 * \param meta_handle meta handle
 * \param ms_waiting_time time out in ms
 * \param request_count number of request to be sent
 * \sa META_ConnectWithTarget_r
 */
META_RESULT  __stdcall META_WaitForTargetReady_r(const int meta_handle, unsigned int ms_waiting_time, unsigned int request_count);
META_RESULT  __stdcall META_GetTargetRequiredMetaVer(unsigned int* p_meta_ver_required_by_target);
META_RESULT  __stdcall META_GetTargetRequiredMetaVer_r(const int meta_handle, unsigned int* p_meta_ver_required_by_target);
// ***** Expired Functions -- END ***** //
const char* __stdcall META_GetBBChipNameByType(unsigned int type);
const char* __stdcall META_GetBBChipNameByType_r(const int meta_handle, unsigned int type);
unsigned int __stdcall META_GetBBChipTypeByString(const char* bb_str);
unsigned int __stdcall META_GetBBChipTypeByString_r(const int meta_handle, const char* bb_str);

/**
 * \addtogroup WCDMA
 * @{
 */
/**
 * \brief
 * Using cost down PA, is needed to add compensation for dealing with transient state unstable situation
 * when switching mode, e.g., Low mode to High mode.
 */
typedef struct
{
    short pa_drift_comp_w_table[6][2];
    short pa_drift_comp_h_table[6][4];
} U_sPADRIFTSETTING;
typedef struct
{
    U_sPADRIFTSETTING txPaDriftCompData;
} ul1Cal_txPaDriftCompData_T;

typedef struct
{
    short   vga_comp_by_temperature[8][2];  ///<[0]:slope in dB (unit: 1/32 dB), [1]:offset in txdac
} U_sRACHCOMP;
typedef struct
{
    U_sRACHCOMP power_dac[3];///<0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
} U_sPARACHTMCOMPDATA;
typedef struct
{
    U_sPARACHTMCOMPDATA txPrachTmCompData;
} ul1cal_txPrachTmCompData_T;

typedef struct
{
    unsigned short ul_uarfcn;       /**< UL uarfcn range:????Read from NVRAM?? (9612 ~ 9888) */
    unsigned short dl_uarfcn;
    unsigned short dl_psc;      /**< 0~511. */
    unsigned short signature;   /**< 0~15, for single signature decision. */
    unsigned char  pa_mode; /**< 0: high 1: middle 2: low */
    char           init_power;  /**< Assume cpich_rscp=0, ul_interference=0. */
    unsigned char  power_step;     /**< Preamble power ramping step. 1 ~ 8dB */
    unsigned char  max_retrans; /**< 1~64 */
    unsigned char  asc;            /**< 0~7 */
} URfTestCmdTxAccess;
typedef struct
{
    unsigned short  ul_freq;
    short   psc;        /**< 0~511. */
    unsigned int    sc_code;    /**< Scrambling code #. 0 ~ 16777215 */
    unsigned char   power_ctrl_mode;
    unsigned char   pa_mode;
    unsigned short  idx;
    unsigned short  afc_dac;
    unsigned char   dpcch_pwr;
    unsigned char   dpdch_pwr;
    unsigned char   rf_band;
    unsigned char   vm1;
    unsigned char   vm2;
    unsigned short  dc2dc_dac;
    unsigned short  vbias_dac;
    bool            pwr_det;
    unsigned short  apc_dac;
} URfTestCmdTxDPCh;
typedef struct
{
    unsigned short  dl_freq;
    short   psc;    /**< 0~511. */
    unsigned char   ssc;    /**< 0~15. */
    short   ovsf;   /**< 0~sf-1. */
    unsigned short  afc_dac;
    bool    hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short   gain;       /**< mode0. */
    unsigned char   LNAmode;     /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
} URfTestCmdRxDPCh;
#define MAX_FREQ_LIST 36
typedef struct
{
    unsigned char   num_freq;
    unsigned short  dl_freq[ MAX_FREQ_LIST ];
    unsigned char   temperature;
    bool    hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short   gain;       /**< mode0. */
    unsigned char   LNAmode;    /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
} URfTestCmdRSSI;
typedef struct
{
    unsigned char   num_freq;
    unsigned short  dl_freq[ MAX_FREQ_LIST ];
    unsigned char   temperature;
    bool    hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short   gain;       /**< mode0. */
    unsigned char   LNAmode;    /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
    unsigned char   lpm_mode;   /* 0: normal LNA gain mode, 1: low poer LNA gain mode*/
} URfTestCmdLPMRSSI;
typedef struct
{
    unsigned char   num_freq;
    unsigned short  dl_freq[ MAX_FREQ_LIST ];
    unsigned char   temperature;
    bool    hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short   gain;       /**< mode0. */
    unsigned char   LNAmode;    /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
} URfTestCmdRxGainSweep;
typedef struct
{
    unsigned char   num_freq;
    unsigned short  dl_freq[ MAX_FREQ_LIST ];
    unsigned char   temperature;
    bool    hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    unsigned char   lpm_mode;   /* 0: normal LNA gain mode, 1: low poer LNA gain mode*/
    short           rx_gain;
    unsigned char   rx_LNAmode;
    unsigned short  rx_pga;
    short           rxd_gain;
    unsigned char   rxd_LNAmode;
    unsigned short  rxd_pga;
    unsigned char   antenna_path;
    bool is_cal;
} URfTestCmdELNARSSI;
typedef struct
{
    bool            pscan_before_cell_search;   /**< True if UL1TST needs power scan before cell search/RSCP. */
    unsigned short  dl_freq;    /**< Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
    unsigned char   sample_num_per_cell;
    bool            read_sfn;   /**< True if we need to do SFN measurement for the found cell. */
    bool            hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short           gain;       /**< mode0. */
    unsigned char   LNAmode;    /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
} URfTestCmdRSCP;
typedef struct
{
    short           dl_freq;    /**< Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
    short           afc_dac;
    bool            hwAGC;
    unsigned char   mode;       /**< 0: mode0, 1: mode1. */
    short           gain;       /**< mode0. */
    unsigned char   LNAmode;    /**< mode1. 0: LNA high, 1: LNA mid, 2: LNA low. */
    unsigned short  pga;        /**< mode1. */
} URfTestCmdAFC;
typedef struct
{
    char            m_cRfBand;    ///< only 0 ~ 5
    unsigned short  m_u2Idx;
    unsigned char   m_ucPaMode;
    unsigned char    m_ucVm1;
    unsigned char    m_ucVm2;
    unsigned short   m_u2DC2DC_Dac;
    unsigned short   m_u2Vbias_Dac;
    unsigned short   m_u2ApcDac;
} UL1D_RF_TX_PA_APC_REQ_T;

typedef struct
{
    unsigned char  pseudo_hscch[5];
    unsigned char  pseudo_hdsch[5];
    unsigned short beta_hs_p[15];
    unsigned short beta_hs_q[15];
} UL1D_RF_HWTPC_FRAME_INFO_R5R6_HSDPA;

typedef struct
{
    unsigned char  edch_enable[5];
    unsigned char  is_new_tx[5];
    unsigned char  etfci[5];
    unsigned char  beta_ed_num[5];
    unsigned short  beta_ed0_sf[5];
    unsigned short  beta_ed1_sf[5];
    unsigned short  beta_ed2_sf[5];
    unsigned short  beta_ed3_sf[5];
    unsigned short  beta_ec[5];
    unsigned short  beta_ed_x_beta_c_0[5];
    unsigned short  beta_ed_x_beta_c_1[5];
    unsigned short  beta_ed_x_beta_c_2[5];
    unsigned short  beta_ed_x_beta_c_3[5];
    unsigned char  delta_harq[5];
} UL1D_RF_HWTPC_FRAME_INFO_R5R6_HSUPA;

typedef struct
{
    unsigned int   normcon;
    short          net_maxpow;
    short          net_minpow;
    UL1D_RF_HWTPC_FRAME_INFO_R5R6_HSDPA frame_info_r5r6_hsdpa;
    UL1D_RF_HWTPC_FRAME_INFO_R5R6_HSUPA frame_info_r5r6_hsupa;
} UL1D_RF_HWTPC_FRAME_INFO_R5R6;

typedef struct
{
    unsigned char tpc_step;
    unsigned char itp;
    unsigned char rpp;
    unsigned char fmt_idx;
    unsigned char dl_frame_type;
    unsigned short slot_mask;
    char   tpc_cmd[15];
    unsigned char  beta_c;
    unsigned char  beta_d;
    UL1D_RF_HWTPC_FRAME_INFO_R5R6 r5r6_parameters;
} UL1D_RF_HWTPC_FRAME_INFO;

typedef struct
{
    unsigned short  h_dpch_offset;
    unsigned char   h_cqi_cycle;
    unsigned char   h_cqi_rep_factor;
    unsigned char   h_delta_cqi;
    unsigned char   h_delta_ack;
    unsigned char   h_delta_nack;
    unsigned char   h_acknack_repe_factor;
    unsigned char   h_harq_pre_mode;
} UL1D_RF_HWTPC_INFO_R5R6_HSDPA;

typedef struct
{
    unsigned char   e_tti;
    unsigned char   e_ul_dpch_num;
    unsigned char   e_beta_ec_idx;
    unsigned char   e_ref_etfci_num;
    unsigned char   e_etfci_table_idx;
    unsigned char   e_pl_non_max;
    unsigned char   e_ref_etfci[8];
    unsigned char   e_ref_etfci_po[8];
} UL1D_RF_HWTPC_INFO_R5R6_HSUPA;

typedef struct
{
    short         max_pow;
    short         min_pow;
    unsigned char hsdpa;
    unsigned char hsupa;
    UL1D_RF_HWTPC_INFO_R5R6_HSDPA hwtpc_info_r5r6_hsdpa;
    UL1D_RF_HWTPC_INFO_R5R6_HSUPA hwtpc_info_r5r6_hsupa;

} UL1D_RF_HWTPC_INFO_R5R6_EXTRA;

typedef struct
{
    unsigned char pc_algo;
    unsigned char tpc_used_frame;  ///< at most 8 so far
    short  p_ini;
    UL1D_RF_HWTPC_INFO_R5R6_EXTRA hw_tpc_r5r6_extra;
    UL1D_RF_HWTPC_FRAME_INFO frame_info[9];
} UL1D_RF_HWTPC_CONFIG_REQ_T;
typedef struct
{
    unsigned char rf_band;
} UL1D_RF_GET_PWR_THR_REQ_T;
typedef struct
{
    unsigned int bsi_data;
} UL1D_RF_SET_BSI_DATA_REQ_T;
typedef struct
{
    unsigned int bsi_addr;
} UL1D_RF_GET_BSI_DATA_REQ_T;
#define FT_MAX_FHC_FREQ_COUNT 40
#define FT_MAX_FHC_PWR_COUNT 40
#define FT_MAX_CAL_BAND     10
typedef struct
{
    bool              no_loop_ctrl;
    unsigned short    afc_dac;
    bool              pwr_det;///<0 off/manual mode, 1 on/auto mode
    unsigned char     power_ctrl_mode;///<1: HW->O3, 2: SW->59D, Smarti
    unsigned char     vm1[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned char     vm2[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned short    dc2dc_dac[FT_MAX_CAL_BAND][3];///<PA param
    unsigned short    vbias_dac[FT_MAX_CAL_BAND][3];///<PA param
    bool              init_tx_onoff;             ///<0:off, 1:on
    bool              ready_tx_onoff;            ///<0:off, 1:on
    unsigned char     init_pa_mode;
    unsigned char     ready_pa_mode;
    unsigned short    init_pa_gain;
    unsigned short    ready_pa_gain;
    unsigned short    init_vga_dac_tpc_idx;
    unsigned short    ready_vga_dac_tpc_idx;
    unsigned char     temperature;
    bool              hwAGC;       ///<0:SW gain mode, 1:HW AGC. AGC must on for RSSI measure. HW limit
    short             gain_init;     /* for HW mode */
    bool              init_condition; ///<0: max_pwr, 1:min_pwr
    unsigned char     step_duration;  ///<in slot
    unsigned char     ready_duration; ///<in slot
    unsigned char     retune_duration; ///<in slot
    unsigned char     gain_stable_time; ///<in slot
    unsigned short    max_vga_dac;
    unsigned short    min_vga_dac;
    unsigned short    jump_vga_dac;
    unsigned char     freq_count;
    unsigned char     pwr_count;
    unsigned char     freq_start_idx;
    unsigned char     pwr_start_idx;
    unsigned char     odd_record;  /*for Anritsu8820, only odd step (1,3,5...start from 1) is for measurement.  */
    unsigned char     pa_gain_start_idx; ///< for O3 TPC
    unsigned char     pd_gain_start_idx; ///< for O3 TPC
    unsigned char     dl_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned char     ul_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned short    dl_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned short    ul_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned char     pa_mode[FT_MAX_FHC_PWR_COUNT];
    unsigned short    vga_dac_tpc_idx[FT_MAX_FHC_PWR_COUNT];///<power_ctrl_mode=HW, tpc_idx. Vice versa.
    unsigned short    pa_gain[FT_MAX_FHC_PWR_COUNT]; ///< for O3 TPC
    unsigned char     pd_gain[FT_MAX_FHC_FREQ_COUNT]; ///< [FT_MAX_MQC_FREQ_COUNT]; // for O3 TPC
} UL1D_RF_FHC_REQ_T;
typedef struct
{
    bool              no_loop_ctrl;
    unsigned short    afc_dac;
    bool              pwr_det;///<0 off/manual mode, 1 on/auto mode
    unsigned char     power_ctrl_mode;///<1: HW->O3, 2: SW->59D, Smarti
    unsigned char     vm1[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned char     vm2[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned short    dc2dc_dac[FT_MAX_CAL_BAND][3];///<PA param
    unsigned short    vbias_dac[FT_MAX_CAL_BAND][3];///<PA param
    bool              init_tx_onoff;             ///<0:off, 1:on
    bool              ready_tx_onoff;            ///<0:off, 1:on
    unsigned char     init_pa_mode;
    unsigned char     ready_pa_mode;
    unsigned short    init_pa_gain;
    unsigned short    ready_pa_gain;
    unsigned short    init_vga_dac_tpc_idx;
    unsigned short    ready_vga_dac_tpc_idx;
    unsigned char     temperature;
    bool              hwAGC;       ///<0:SW gain mode, 1:HW AGC. AGC must on for RSSI measure. HW limit
    short             gain_init;     /* for HW mode */
    bool              init_condition; ///<0: max_pwr, 1:min_pwr
    unsigned char     step_duration;  ///<in slot
    unsigned char     ready_duration; ///<in slot
    unsigned char     retune_duration; ///<in slot
    unsigned char     gain_stable_time; ///<in slot
    unsigned short    max_vga_dac;
    unsigned short    min_vga_dac;
    unsigned short    jump_vga_dac;
    unsigned char     freq_count;
    unsigned char     pwr_count;
    unsigned char     freq_start_idx;
    unsigned char     pwr_start_idx;
    unsigned char     odd_record;  /*for Anritsu8820, only odd step (1,3,5...start from 1) is for measurement.  */
    unsigned char     pa_gain_start_idx; ///< for O3 TPC
    unsigned char     pd_gain_start_idx; ///< for O3 TPC
    unsigned char     dl_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned char     ul_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned short    dl_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned short    ul_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned char     pa_mode[FT_MAX_FHC_PWR_COUNT];
    unsigned short    vga_dac_tpc_idx[FT_MAX_FHC_PWR_COUNT];///<power_ctrl_mode=HW, tpc_idx. Vice versa.
    unsigned short    pa_gain[FT_MAX_FHC_PWR_COUNT]; ///< for O3 TPC
    unsigned char     pd_gain[FT_MAX_FHC_FREQ_COUNT]; ///< [FT_MAX_MQC_FREQ_COUNT]; // for O3 TPC
    unsigned char     pa_section[FT_MAX_FHC_PWR_COUNT];
    unsigned short    lna_gain[FT_MAX_FHC_FREQ_COUNT];  /**< 80 path loss 3 lna mode fixed gain */
} UL1D_RF_FHC_EX_REQ_T;
typedef struct
{
    bool              no_loop_ctrl;
    unsigned short    afc_dac;
    bool              pwr_det;///<0 off/manual mode, 1 on/auto mode
    unsigned char     power_ctrl_mode;///<1: HW->O3, 2: SW->59D, Smarti
    unsigned char     vm1[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned char     vm2[FT_MAX_CAL_BAND][3];      ///<PA param
    unsigned short    dc2dc_dac[FT_MAX_CAL_BAND][3];///<PA param
    unsigned short    vbias_dac[FT_MAX_CAL_BAND][3];///<PA param
    unsigned char     temperature;
    bool              hwAGC;       ///<0:SW gain mode, 1:HW AGC. AGC must on for RSSI measure. HW limit
    unsigned char     step_duration;  ///<in slot
    unsigned char     freq_count;
    unsigned char     pwr_count;
    unsigned char     freq_start_idx;
    unsigned char     pwr_start_idx;
    unsigned char     pa_gain_start_idx; ///< for O3 TPC
    unsigned char     pd_gain_start_idx; ///< for O3 TPC
    unsigned char     lna_gain_start_idx;
    unsigned char     dl_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned char     ul_band[FT_MAX_FHC_FREQ_COUNT]; ///<1:band1, 2:band2, 3:band3, 5:band5
    unsigned short    dl_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned short    ul_freq[FT_MAX_FHC_FREQ_COUNT]; ///<in uarfcn
    unsigned char     pd_gain[FT_MAX_FHC_FREQ_COUNT];
    unsigned char     pa_mode[FT_MAX_FHC_PWR_COUNT];
    unsigned short    vga_dac_tpc_idx[FT_MAX_FHC_PWR_COUNT];///<power_ctrl_mode=HW, tpc_idx. Vice versa.
    unsigned short    pa_gain[FT_MAX_FHC_PWR_COUNT]; ///< for O3 TPC
    unsigned char     pa_section[FT_MAX_FHC_PWR_COUNT];
    unsigned short    rx_lna_gain[FT_MAX_FHC_FREQ_COUNT]; // WCDMA ELNA
    unsigned short    rxd_lna_gain[FT_MAX_FHC_FREQ_COUNT]; // WCDMA ELNA
    unsigned char     fix_pga_gain[FT_MAX_FHC_FREQ_COUNT]; // WCDMA ELNA
    unsigned char     is_lpm[FT_MAX_FHC_FREQ_COUNT]; // WCDMA ELNA
} UL1D_RF_FHC_ELNA_REQ_T;
#define FT_MAX_FHC_RSSI_COUNT 400
typedef struct
{
    bool             ok;
    unsigned char    freq_count;
    unsigned char    pwr_count;
    unsigned char    freq_start_idx;
    unsigned char    pwr_start_idx;
    short            rssi[FT_MAX_FHC_RSSI_COUNT];
    short            pwr_det_value[FT_MAX_FHC_FREQ_COUNT];
} UL1D_RF_FHC_CNF_T;
typedef struct
{
    bool             ok;
    unsigned char    freq_count;
    unsigned char    pwr_count;
    unsigned char    freq_start_idx;
    unsigned char    pwr_start_idx;
    unsigned char    rx_lna_mode[FT_MAX_FHC_RSSI_COUNT];
    short            rssi[FT_MAX_FHC_RSSI_COUNT];
    short            pwr_det_value[FT_MAX_FHC_FREQ_COUNT][3];
} UL1D_RF_FHC_EX_CNF_T;

typedef struct
{
    bool             ok;
    unsigned char    freq_count;
    unsigned char    pwr_count;
    unsigned char    freq_start_idx;
    unsigned char    pwr_start_idx;
    unsigned char    rx_lna_mode[FT_MAX_FHC_RSSI_COUNT];
    short            rssi[FT_MAX_FHC_RSSI_COUNT];
    short            pwr_det_value[FT_MAX_FHC_FREQ_COUNT][3];
    short            Gbb_Offset[FT_MAX_FHC_RSSI_COUNT];   /**< TX Gbb power compensation */
    unsigned char    rxd_lna_mode[FT_MAX_FHC_RSSI_COUNT]; /**< Rx diversity path lna mode */
    short            rxd_rssi[FT_MAX_FHC_RSSI_COUNT];     /**< Rx diversity path RSSI */
} UL1D_RF_FHC_EX2_CNF_T;

typedef struct
{
    unsigned short m_u2TxPclIndex;
} UL1D_RF_GET_PWR_DET_REPORT_REQ_T;
typedef struct
{
    unsigned short m_u2PwrDetResult;
} UL1D_RF_GET_PWR_DET_REPORT_CNF_T;
typedef struct
{
    unsigned char m_u1PwrCtrlMode;
} UL1D_RF_SET_PWR_CTRL_MODE_REQ_T;
typedef struct
{
    bool              b_afc_dac_valid;
    unsigned short    u2_afc_dac;
    unsigned char     u1_loopbackType;///<0: no loopback, 1: loopback type 1, 2: loopback type 2
    unsigned char     u1_frame_shift;///<default=0, depends on Test Machine
    unsigned char     u1_rmc_type;///<1: 12.2k, 2: 64k, 3: 144k, 4: 384k
    unsigned char     u1_ctfc[4];///<8960=0,1,2,3; cmu200=0,2,1,3
    unsigned char     u1_bit_pattern;///<0: single ended ber disable, 1: all one, 2: all zero
    short             i2_dl_freq;
    short             i2_dl_psc;/* 0~511. */
    short             i2_dl_ovsf;///<RMC12.2k: <128, but test set not allow all ovsf,
    short            i2_ul_freq;
    unsigned short   u2_ul_tfci;
    unsigned int     u4_ul_sc_code;  /* Scrambling code #. 0 ~ 16777215 */
    bool             b_iq_pwr_valid;///<valid dpcch, dpdch power
    unsigned char    u1_dpcch_pwr;///<default 8, depends on testing requirement
    unsigned char    u1_dpdch_pwr;///<default 15, depends on testing requirement
} UL1D_RF_NSFT_REQ_T;

/** list mode */
#define FT_MAX_LIST_MODE_FREQ_COUNT 50
typedef struct
{
    bool afc_dac_valid;
    unsigned short afc_dac;
    unsigned char loopbackType;///<0: no loopback, 1: loopback type 1, 2: loopback type 2
    unsigned char frame_shift;///<default=0, depends on Test Machine
    unsigned char rmc_type;///<1: 12.2k, 2: 64k, 3: 144k, 4: 384k
    unsigned char ctfc[4];///<8960=0,1,2,3; cmu200=0,2,1,3
    unsigned char bit_pattern;///<0: single ended ber disable, 1: all one, 2: all zero
    /* DL parameters */
    short dl_freq[50];
    short dl_psc;/* 0~511. */
    short dl_ovsf;///<RMC12.2k: <128, but test set not allow all ovsf, //RMC12.2k default ovsf=9
    /* UL parameters */
    short ul_freq[50];
    unsigned short ul_tfci;
    unsigned int ul_sc_code;    /* Scrambling code #. 0 ~ 16777215 */
    bool iq_pwr_valid;///<valid dpcch, dpdch power
    unsigned char dpcch_pwr;///<default 8, depends on testing requirement
    unsigned char dpdch_pwr;///<default 15, depends on testing requirement
    /* common parameters */
    unsigned char valid_freq; ///<valid count of dl/ul freq.
    unsigned short test_item[50]; /**
                                   * <bit0, reserved. //bit1=1: single ended BER enable //bit2=1: rssi enable //bit3, reserved //bit4, reserved
                                   * bit5=1: ILPC_ABC enable //bit6=1: ILPC_EF enable //bit7=1: ILPC_GH enable
                                   * the time settings, unit = frame
                                   * */
    unsigned short full_test_time;///<the total time of one freq.
    unsigned char ready_time; ///< for first sync after TX transmit
    unsigned char sync_time; ///< from cs_start to LBK is 26 frame
    unsigned char retrial; ///<just for first sync
    unsigned short test_time; ///<the time of test for max&min TX power tests
    unsigned short rx_rssi_start_time[3]; ///<RSSI start time for 3 LNA mode
    unsigned char rx_rssi_duration[3];
    unsigned short rx_ber_start_time; ///<BER start time, no used now.
    unsigned char rx_ber_duration;
    unsigned short ILPC_ABC_time; ///<the time of ILPC ABC
    unsigned short ILPC_EF_time; ///<the time of ILPC EF
    unsigned short ILPC_GH_time; ///<the time of ILPC GH
    unsigned short transition_time; ///<the limitation of UE state machine is 4 frame at least
} URfNsftListModeReq;
/**
 * META DLL HSPA NSFT parameter
 */
typedef struct
{
    UL1D_RF_NSFT_REQ_T r99Param;
    unsigned char      subTest;
} META_URfTestCmdHspaNsft;

typedef struct
{
    bool    ok;
    unsigned char   num_freq;
    short   dl_freq[ MAX_FREQ_LIST ];
    int inband_pow[ MAX_FREQ_LIST ];
} URfTestResultRxGainSweep;

typedef struct
{
    bool    ok;
    unsigned char   num_freq;
    short   dl_freq[ MAX_FREQ_LIST ];
    int rssi[ MAX_FREQ_LIST ];
} URfTestResultRSSI;

typedef struct
{
    bool      ok;
    int       NSFT_RSSI;
    int       NSFT_RSSI_RXD;
    int          cmd_location;
} URfTestResultNSFTRSSI;

typedef struct
{
    bool ok;
    unsigned int  u4TotalBits;
    unsigned int  u4ErrorBits;
} URfTestResultNSFTResetBERResult;

typedef struct
{
    bool    ok;
    unsigned char   num_freq;
    short   dl_freq[ MAX_FREQ_LIST ];
    int rssi[ MAX_FREQ_LIST ];
    int rssi_rxd[ MAX_FREQ_LIST ];
} URfTestResultRSSIRxD;
typedef struct
{
    unsigned char   num_freq;
    short   dl_freq[ MAX_FREQ_LIST ];
    int rx_rssi[ MAX_FREQ_LIST ];
    int rxd_rssi[ MAX_FREQ_LIST ];
    unsigned char rx_LNAmode[ MAX_FREQ_LIST ];
    unsigned char rxd_LNAmode[ MAX_FREQ_LIST ];
} URfTestResultELNARSSI;

typedef struct
{
    unsigned short  psc;        /**< Primary scrambling code */
    int tm;     /**< Cell frame boundary offset to LST */
    short   off;        /**< Cell frame number offset to LST */
    bool    sttd;       /**< True for STTD used. */
    unsigned char   sample_num;
    short rscp_sum;
    short freq_error;  // 20070514
} UL1TST_cpich_result_T;
#define MAX_NUM_MEAS_CELL 32
typedef struct
{
    bool        ok;
    unsigned char       num_cell;
    UL1TST_cpich_result_T   cpich_result[ MAX_NUM_MEAS_CELL ];
} URfTestResultRSCP;
typedef struct
{
    bool            ok;
    unsigned short  psc;        /**< Primary scrambling code */
    int             tm;     /**< Cell frame boundary offset to LST */
    bool            sttd;       /**< True for STTD used. */
    unsigned char   rscp_sum;
    short           freq_error;
} URfTestResultAFC;
typedef struct
{
    bool            ok;
    unsigned short  psc;        /**< Primary scrambling code */
    int             tm;         /**< Cell frame boundary offset to LST */
    bool            sttd;       /**< True for STTD used. */
    unsigned char   rscp_sum;
    int             freq_error;
} URfTestResultAFC_Ex;
typedef struct
{
    bool    ok;
    unsigned int    ber;    /**< Spec requirement=10^-3. We will count 10^5 frames(100 times spec requirement) for BER calculation. Only count for the only TRCh for DPDCh. */
} URfTestResultRxDPCh;
#define  UL1D_RF_ID_SONY_CXA3359    0x00000001
#define  UL1D_RF_ID_MT6159B         0x00000002
#define  UL1D_RF_ID_SMARTI3G        0x00000003
#define  UL1D_RF_ID_MT6159C         0x00000004
#define  UL1D_RF_ID_MT6159D         0x00000005
#define  UL1D_RF_ID_MT6159E         0x00000006
#define  UL1D_RF_ID_MT6160          0x00000007
#define  UL1D_RF_ID_MT6161          0x00000010
#define  UL1D_RF_ID_MT6162          0x00000008
#define  UL1D_RF_ID_MT6162_DUAL     0x00000009
#define  UL1D_RF_ID_MT6280          0x0000000B
#define  UL1D_RF_ID_MT6167          0x0000000C
#define  UL1D_RF_ID_MT6166          0x0000000D
#define  UL1D_RF_ID_MT6169          0x0000000E
#define  UL1D_RF_ID_MT6580          0x0000000F
#define  UL1D_RF_ID_MT6176          0x00000011
#define  UL1D_RF_ID_MT6179          0x00000012
#define  UL1D_RF_ID_MT6570          0x00000013
#define  UL1D_RF_ID_MT6177L         0x00000014
#define  UL1D_RF_ID_MT6173          0x00000015
typedef struct
{
    unsigned int m_u4Rfid;
} URfTestResultRFID;
typedef struct
{
    unsigned char m_u1Result;
} URfTestResultPwrDtStep;
typedef struct
{
    unsigned short m_u2Result;
} URfTestResultPwrDtDac;
typedef struct
{
    unsigned char m_u1Result;
} URfTestResultPwrDtDefaultThr;

#define UMTS_SUPPORT_BAND1       0x00000001
#define UMTS_SUPPORT_BAND2       0x00000002
#define UMTS_SUPPORT_BAND3       0x00000004
#define UMTS_SUPPORT_BAND4       0x00000008
#define UMTS_SUPPORT_BAND5       0x00000010
#define UMTS_SUPPORT_BAND6       0x00000020
#define UMTS_SUPPORT_BAND7       0x00000040
#define UMTS_SUPPORT_BAND8       0x00000080
#define UMTS_SUPPORT_BAND9       0x00000100
#define UMTS_SUPPORT_BAND10      0x00000200
#define UMTS_SUPPORT_BAND11      0x00000400
#define UMTS_SUPPORT_BAND12      0x00000800
#define UMTS_SUPPORT_BAND13      0x00001000
#define UMTS_SUPPORT_BAND14      0x00002000
#define UMTS_SUPPORT_BAND15_DMY  0x00004000 /* dummy band */
#define UMTS_SUPPORT_BAND16_DMY  0x00008000 /* dummy band */
#define UMTS_SUPPORT_BAND17      0x00010000
#define UMTS_SUPPORT_BAND18_DMY  0x00020000 /* dummy band */
#define UMTS_SUPPORT_BAND19      0x00040000
#define UMTS_SUPPORT_BAND_COUNT  19


typedef struct
{
    unsigned int    PaOctLevelControl: 1;                  // 0x00000001
    unsigned int    PaPhaseCompensationConversion: 1;      // 0x00000002
    unsigned int    PaCouplerLossByPaMode: 1;              // 0x00000004
    unsigned int    HsdpaNsft: 1;                          // 0x00000008
    unsigned int    HsupaNsft: 1;                          // 0x00000010
    unsigned int    UmtsFddDcxoSupport: 1;                 // 0x00000020
    unsigned int    UmtsFddRxDiversitySupport: 1;          // 0x00000040
    unsigned int    UmtsFddRxDualCellSupport: 1;           // 0x00000080
    unsigned int    PdMeasurementDbConversion: 1;          // 0x00000100
    unsigned int    PaDriftCompenstaion: 1;                // 0x00000200
    unsigned int    UmtsTempAdcUsingL1API: 1;              // 0x00000400
    unsigned int    Dc2DcLevelUnused: 1;                   // 0x00000800
    unsigned int    RxSoftwareModeTracking: 1;             // 0x00001000
    unsigned int    FhcTxVgaBB0Mode: 1;                    // 0x00002000
    unsigned int    FhcTxFrameDurationLimit: 1;            // 0x00004000  /**< frame time 15 ms * x */
    unsigned int    NsftSetICSInitialGain: 1;              // 0x00008000  /**< setup initial gain for ICS */
    unsigned int    UmtsFddTxPRACHTemperatureCompensationSupport: 1; // 0x00010000  /**< setup temperature compensation for PRACH Tx*/
    unsigned int    RfCapabilityExtension: 1;              // 0x00020000  /**< indicates the extended capability API is supported by UL1 */
    unsigned int    UmtsFddDpdSupport: 1;                  // 0x00040000  /**< indicates that wcdma dpd support band is reported by L1 */
} UMTS_MsCapabilityEx_Bits;
typedef struct
{
    unsigned int        capability;
    unsigned int        band_support;
    /** R8 RX diversity band support */
    unsigned int        rxd_band_support;
    /** R8 Pa drift compenstaion band support */
    unsigned int        padrift_band_support;
    unsigned int        dpd_band_support;
} UMTS_MsCapabilityEx;
typedef struct
{
    UMTS_MsCapabilityEx_Bits      capability;
    unsigned int                  band_support;
    /** R8 RX diversity band support */
    unsigned int                  rxd_band_support;
    /** R8 Pa drift compenstaion band support */
    unsigned int                  padrift_band_support;
    unsigned int                  dpd_band_support;
} UMTS_MsCapabilityEx2;
typedef struct
{
    bool         bDataValid;
    unsigned int u4TotalBits; ///< if bDataValid = true, the value here is valid
    unsigned int u4ErrorBits; ///< if bDataValid = true, the value here is valid
} UL1D_RF_NSFT_GET_BIT_CNT_FOR_BER_CNF_T;

typedef struct
{
    bool          ok;
    unsigned char link_status;
} UMTS_NSFTLinkStatusReport;

typedef struct
{
    unsigned char status;
    unsigned char current_idx;
    short   total_bits[FT_MAX_LIST_MODE_FREQ_COUNT][2]; ///<[0]:real ber test. [1]: ber test for debug
    short   error_bits[FT_MAX_LIST_MODE_FREQ_COUNT][2];
    short   rssi[FT_MAX_LIST_MODE_FREQ_COUNT][3]; ///<RSSI at 3 LNA mode
    short   rssi_rxd[FT_MAX_LIST_MODE_FREQ_COUNT][3]; ///<RSSI at 3 LNA mode
    char    lnamode[3]; ///<0 : high, 1 : mid, 2 : low
} URfNsftListModeCnf;

typedef struct
{
    bool          ok;    /**< ok indicator */
    unsigned int  sum;   /**< the sum of measure_count times of temp sensor result */
} URfTestResultGetRfTempSensor;

typedef struct
{
    unsigned int is_capable      : 1; /**< the indicator to indicate if this item is supported by SW or HW */
    unsigned int is_mandatory    : 1; /**< the indicator to indicate if this item is mandatory to be calibrated */
    unsigned int parameter       : 30; /**< parameter to be carried to tool side */
} UL1TSTCalibrationItem;

typedef struct
{
    unsigned int mipi_pa_support_band; /**< bit map of mipi pa support band */
    unsigned int rx_gain_sweep_support; /**< bit map of rx gain sweep support>*/
} UL1TSTCapabilityItemSet;

/* DO NOT Modify the member order of UL1TSTCalibrationItemSet, Items must be added to the end  */
typedef struct
{
    UL1TSTCalibrationItem tadc_cal;                                   /**<  [0] TADC calibration capability.           ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem multi_rat_tadc_bitmap;                      /**<  [1] bit map of multi-rat TADC calibration. ;is_capable (0: not supported, 1: supported) parameter (0|0|C|Lf|Lt|T|W|G) */
    UL1TSTCalibrationItem multi_rat_afc_bitmap;                       /**<  [2] bit map of multi-rat AFC calibration.  ;is_capable (0: not supported, 1: supported) parameter (0|0|C|Lf|Lt|T|W|G) */
    UL1TSTCalibrationItem mipi_pa_level_and_cw_num;                   /**<  [3] MIPI PA power level and codeword number;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem temperature_info;                           /**<  [4] Target support temperature info.       ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem list_mode_support;                          /**<  [5] Target support list mode API.          ;is_capable (0: not supported, 1: supported) parameter (0: not supportted Rxd RSSI 1: supported Rxd RSSI) */
    UL1TSTCalibrationItem thermal_sensor_type;                        /**<  [6] Target support temp sensor type.       ;is_capable (0: not supported, 1: supported) parameter (0: internal 1: external) */
    UL1TSTCalibrationItem ubin_mode_switch_support;                   /**<  [7] Target support universal bin switch.   ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem nvram_access_interface;                     /**<  [8] Target support nvram access interface. ;is_capable (0: not supported, 1: supported) parameter (0x01 RX pathloss)*/
    UL1TSTCalibrationItem rx_gain_lpm_offset;                         /**<  [9] Target support RX low power gain mode. ;is_capable (0: not supported, 1: supported) parameter (bit0-4 normal gain number, bit5-9 low power offset number) */
    UL1TSTCalibrationItem nsft_get_RSSI;                              /**< [10] Target support get RSSI during NSFT.   ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem new_prf_select_method;                      /**< [11] Prf selection for fitting H/M/L mode.  ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem nsft_reset_ber_result;                      /**< [12] Support reset ber result command       ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem elna_addition;                              /**< [13] Target support eLNA                    ;is_capable (0: not supported, 1: supported) parameter (band support bitmap of eLNA |...|band4|band3|band2|band1|)*/ 
    UL1TSTCalibrationItem apc_extend;                                 /**< [14] Support APC additional gain cal        ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem elna_addition_diversity_path;               /**< [15] Target support eLNA div path           ;is_capable (0: not supported, 1: supported) parameter (band support bitmap of eLNA |...|band4|band3|band2|band1|)*/
    UL1TSTCalibrationItem cancel_polling_action_when_get_fhc_result;  /**< [16] cancel polling when get fhc result     ;is_capable (0: not supported, 1: supported) */
    UL1TSTCalibrationItem wcdma_md_cal_generation;                    /**< [17] Modem calibration generation           ;is_capable (0: not supported, 1: supported) parameter (3:V3)*/
    UL1TSTCalibrationItem dpd_generation;                             /**< [18] >**/
} UL1TSTCalibrationItemSet;

typedef struct
{
    unsigned int capabilityItemsSize;
    unsigned int calibrationItemsSize;
} URfTestCmdGetRfCapabilityReq;

typedef struct
{
    int                    valid;
    int                    status;
    UL1TSTCapabilityItemSet capabilityItems;
    UL1TSTCalibrationItemSet calibrationItems;
} URfTestResultGetRfCapabilityCnf;
#define MAX_URF_MIPI_POWER_LEVEL   16
#define MAX_URF_MIPI_CODE_WORD_NUM 16
typedef struct
{
    unsigned short       rf_band_idx;
    unsigned short       power_level_num;
    unsigned short       code_word_num;
    unsigned int         codeword[MAX_URF_MIPI_POWER_LEVEL][MAX_URF_MIPI_CODE_WORD_NUM];
} URfTestCmdSetMIPICodeWord;
typedef struct
{
    unsigned short       power_level_num;
    unsigned short       code_word_num;
    unsigned int         codeword[MAX_URF_MIPI_POWER_LEVEL][MAX_URF_MIPI_CODE_WORD_NUM];
} URfTestResultGetMIPICodeWord;
typedef struct
{
    short status;
    short tadc_dac;
    short temperature;
    short temp_index;
} META_Rf_TemperatureInfo_T;
typedef META_Rf_TemperatureInfo_T META_3Grf_TemperatureInfo_T;
typedef union
{
    bool                                   ok;
    char                                   nvramAccessResult;
    char                                   m_i1CurGainTableState;
    unsigned int                           bsi_data;
    unsigned int                           m_u4MaxCapId;
    unsigned char                          currentLnaMode;
    URfTestResultRSSI                      rssi;
    URfTestResultRSSIRxD                   rssi_rxd; /**< \brief R8 get both rx path RSSI */
    URfTestResultELNARSSI                  rssi_elna;
    URfTestResultAFC                       afc;
    URfTestResultRSCP                      rscp;
    URfTestResultRFID                      rfid;
    UL1D_RF_FHC_CNF_T                      m_rMQCResult;
    URfTestResultAFC_Ex                    afc_ex;
    URfTestResultRxDPCh                    rx_dpch;
    UMTS_MsCapabilityEx                    m_rTargetCapability;
    UL1D_RF_FHC_EX2_CNF_T                  fhcExResult;
    URfTestResultPwrDtDac                  pwr_dt_dac;
    URfTestResultPwrDtStep                 pwr_dt_step;
    UMTS_NSFTLinkStatusReport              m_rNSFTLinkStatusReport;
    URfNsftListModeCnf                     m_rNSFTListModeLinkStatusReport;
    URfTestResultGetRfTempSensor           rfTemperature;
    URfTestResultPwrDtDefaultThr           pwr_dt_default_thr;
    UL1D_RF_GET_PWR_DET_REPORT_CNF_T       m_rPwrDetResult;
    UL1D_RF_NSFT_GET_BIT_CNT_FOR_BER_CNF_T m_rNSFTBERResult;
    URfTestResultRxGainSweep               rx_gain_sweep;
    URfTestResultNSFTRSSI                  rssi_nsft;
    URfTestResultNSFTResetBERResult        resetBERResult;
} URfTestResultParam;
META_RESULT  __stdcall META_3Grf_TxAccess(unsigned int ms_timeout, URfTestCmdTxAccess* req, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_TxAccess_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdTxAccess* req, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_TestStop(unsigned int ms_timeout, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_TestStop_r(const int meta_handle, unsigned int ms_timeout, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_TxDpch(unsigned int ms_timeout, URfTestCmdTxDPCh* req, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_TxDpch_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdTxDPCh* req, URfTestResultParam* cnf);
META_RESULT  __stdcall META_3Grf_RxDpch(unsigned int ms_timeout, URfTestCmdRxDPCh* req, URfTestResultRxDPCh* cnf);
META_RESULT  __stdcall META_3Grf_RxDpch_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRxDPCh* req, URfTestResultRxDPCh* cnf);
META_RESULT  __stdcall META_3Grf_Rssi(unsigned int ms_timeout, URfTestCmdRSSI* req, URfTestResultRSSI* cnf);
META_RESULT  __stdcall META_3Grf_Rssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRSSI* req, URfTestResultRSSI* cnf);
META_RESULT  __stdcall META_3Grf_QueryNsftRssi(unsigned int ms_timeout, URfTestResultNSFTRSSI* cnf);
META_RESULT  __stdcall META_3Grf_QueryNsftRssi_r(const int meta_handle, unsigned int ms_timeout, URfTestResultNSFTRSSI* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_Reset_BER_Result(unsigned int ms_timeout, URfTestResultNSFTResetBERResult* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_Reset_BER_Result_r(const int meta_handle, unsigned int ms_timeout, URfTestResultNSFTResetBERResult* cnf);

/**
 * \brief R8 RF tool. RX diversity RSSI.
 **/
META_RESULT  __stdcall META_3Grf_RxDRssi(unsigned int ms_timeout, URfTestCmdRSSI* req, URfTestResultRSSIRxD* cnf);
META_RESULT  __stdcall META_3Grf_RxDRssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRSSI* req, URfTestResultRSSIRxD* cnf);
META_RESULT  __stdcall META_3Grf_Rscp(unsigned int ms_timeout, URfTestCmdRSCP* req, URfTestResultRSCP* cnf);
META_RESULT  __stdcall META_3Grf_Rscp_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRSCP* req, URfTestResultRSCP* cnf);
META_RESULT  __stdcall META_3Grf_Set_Tx_PaApc(unsigned int ms_timeout, UL1D_RF_TX_PA_APC_REQ_T* req);
META_RESULT  __stdcall META_3Grf_Set_Tx_PaApc_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_TX_PA_APC_REQ_T* req);
META_RESULT  __stdcall META_3Grf_AFC(unsigned int ms_timeout, URfTestCmdAFC* req, URfTestResultAFC* cnf);
META_RESULT  __stdcall META_3Grf_AFC_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdAFC* req, URfTestResultAFC* cnf);
META_RESULT  __stdcall META_3Grf_GetRFID(unsigned int ms_timeout, URfTestResultRFID* cnf);
META_RESULT  __stdcall META_3Grf_GetRFID_r(const int meta_handle, unsigned int ms_timeout, URfTestResultRFID* cnf);
META_RESULT  __stdcall META_3Grf_ConfigHWTPC(unsigned int ms_timeout, UL1D_RF_HWTPC_CONFIG_REQ_T* req);
META_RESULT  __stdcall META_3Grf_ConfigHWTPC_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_HWTPC_CONFIG_REQ_T* req);
META_RESULT  __stdcall META_3Grf_GetPwrDtStep(unsigned int ms_timeout, URfTestResultPwrDtStep* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtStep_r(const int meta_handle, unsigned int ms_timeout, URfTestResultPwrDtStep* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtDac(unsigned int ms_timeout, URfTestResultPwrDtDac* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtDac_r(const int meta_handle, unsigned int ms_timeout, URfTestResultPwrDtDac* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtDefaultThr(unsigned int ms_timeout, UL1D_RF_GET_PWR_THR_REQ_T* req, URfTestResultPwrDtDefaultThr* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtDefaultThr_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_GET_PWR_THR_REQ_T* req, URfTestResultPwrDtDefaultThr* cnf);
META_RESULT  __stdcall META_3Grf_SetImmediateBSI(unsigned int ms_timeout, const UL1D_RF_SET_BSI_DATA_REQ_T* req);
META_RESULT  __stdcall META_3Grf_SetImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_SET_BSI_DATA_REQ_T* req);
META_RESULT  __stdcall META_3Grf_GetImmediateBSI(unsigned int ms_timeout, const UL1D_RF_GET_BSI_DATA_REQ_T* req, unsigned int* p_bsi_data);
META_RESULT  __stdcall META_3Grf_GetImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_GET_BSI_DATA_REQ_T* req, unsigned int* p_bsi_data);
META_RESULT  __stdcall META_3Grf_ContinuousRX(unsigned int ms_timeout, URfTestCmdRSSI* req);
META_RESULT  __stdcall META_3Grf_ContinuousRX_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRSSI* req);
META_RESULT  __stdcall META_3Grf_FHC_Start(unsigned int ms_timeout, const UL1D_RF_FHC_REQ_T* req, UL1D_RF_FHC_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_FHC_Start_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_FHC_REQ_T* req, UL1D_RF_FHC_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_FHC_NoWaitResult(unsigned int ms_timeout, const UL1D_RF_FHC_REQ_T* req);
META_RESULT  __stdcall META_3Grf_FHC_NoWaitResult_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_FHC_REQ_T* req);
META_RESULT  __stdcall META_3Grf_QueryFHCResult(unsigned int ms_timeout, UL1D_RF_FHC_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_QueryFHCResult_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_FHC_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtMeasureResult(unsigned int ms_timeout,
        const UL1D_RF_GET_PWR_DET_REPORT_REQ_T* req,
        UL1D_RF_GET_PWR_DET_REPORT_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_GetPwrDtMeasureResult_r(const int meta_handle, unsigned int ms_timeout,
        const UL1D_RF_GET_PWR_DET_REPORT_REQ_T* req,
        UL1D_RF_GET_PWR_DET_REPORT_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_SetPowerControlMode(unsigned int ms_timeout, const UL1D_RF_SET_PWR_CTRL_MODE_REQ_T* req);
META_RESULT  __stdcall META_3Grf_SetPowerControlMode_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_SET_PWR_CTRL_MODE_REQ_T* req);
META_RESULT  __stdcall META_3Grf_ReplaceGainTableforCal(unsigned int ms_timeout, const unsigned char* pTableType, char* pCurState);
META_RESULT  __stdcall META_3Grf_ReplaceGainTableforCal_r(const int meta_handle, unsigned int ms_timeout, const unsigned char* pTableType, char* pCurState);
META_RESULT  __stdcall META_3Grf_QueryTargetCapability(unsigned int ms_timeout, UMTS_MsCapabilityEx* cnf);
META_RESULT  __stdcall META_3Grf_QueryTargetCapability_r(const int meta_handle, unsigned int ms_timeout, UMTS_MsCapabilityEx* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_Start(unsigned int ms_timeout, const UL1D_RF_NSFT_REQ_T* req);
META_RESULT  __stdcall META_3Grf_NSFT_Start_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_NSFT_REQ_T* req);
META_RESULT  __stdcall META_3Grf_NSFT_GetBitCountForSingleEndedBER(unsigned int ms_timeout, UL1D_RF_NSFT_GET_BIT_CNT_FOR_BER_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_GetBitCountForSingleEndedBER_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_NSFT_GET_BIT_CNT_FOR_BER_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_SetILPCStep(unsigned int ms_timeout, unsigned char step);
META_RESULT  __stdcall META_3Grf_NSFT_SetILPCStep_r(const int meta_handle, unsigned int ms_timeout, unsigned char step);
META_RESULT  __stdcall META_3Grf_NSFT_StartEx(unsigned int ms_timeout, const UL1D_RF_NSFT_REQ_T* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_StartEx_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_NSFT_REQ_T* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_HsdpaNsftStart(unsigned int ms_timeout, const META_URfTestCmdHspaNsft* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_HsdpaNsftStart_r(const int meta_handle, unsigned int ms_timeout, const META_URfTestCmdHspaNsft* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_HsupaNsftStart(unsigned int ms_timeout, const META_URfTestCmdHspaNsft* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_HsupaNsftStart_r(const int meta_handle, unsigned int ms_timeout, const META_URfTestCmdHspaNsft* req, UMTS_NSFTLinkStatusReport* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_List_Mode_Start(unsigned int ms_timeout, const URfNsftListModeReq* req, URfNsftListModeCnf* cnf);
META_RESULT  __stdcall META_3Grf_NSFT_List_Mode_Start_r(const int meta_handle, unsigned int ms_timeout, const URfNsftListModeReq* req, URfNsftListModeCnf* cnf);
META_RESULT  __stdcall META_3Grf_FHC_StartEx(unsigned int ms_timeout, const UL1D_RF_FHC_EX_REQ_T* req);
META_RESULT  __stdcall META_3Grf_FHC_StartEx_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_FHC_EX_REQ_T* req);
META_RESULT  __stdcall META_3Grf_QueryFHCExResult(unsigned int ms_timeout, UL1D_RF_FHC_EX2_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_QueryFHCExResult_r(const int meta_handle, unsigned int ms_timeout, UL1D_RF_FHC_EX2_CNF_T* cnf);
META_RESULT  __stdcall META_3Grf_QueryCurrentLnaMode(unsigned int ms_timeout, unsigned char* mode);
META_RESULT  __stdcall META_3Grf_QueryCurrentLnaMode_r(const int meta_handle, unsigned int ms_timeout, unsigned char* mode);
/**
 * WCDMA eLNA
**/
META_RESULT  __stdcall META_3Grf_FHC_ELNA(unsigned int ms_timeout, const UL1D_RF_FHC_ELNA_REQ_T* req);
META_RESULT  __stdcall META_3Grf_FHC_ELNA_r(const int meta_handle, unsigned int ms_timeout, const UL1D_RF_FHC_ELNA_REQ_T* req);
META_RESULT  __stdcall META_3Grf_ELNA_Rssi(unsigned int ms_timeout, URfTestCmdELNARSSI* req, URfTestResultELNARSSI* cnf);
META_RESULT  __stdcall META_3Grf_ELNA_Rssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdELNARSSI* req, URfTestResultELNARSSI* cnf);
META_RESULT  __stdcall META_3Grf_ELNA_ContinuousRssi(unsigned int ms_timeout, URfTestCmdELNARSSI* req);
META_RESULT  __stdcall META_3Grf_ELNA_ContinuousRssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdELNARSSI* req);
/**
 * pass cell power to UL1 to choose the best initial gain for ICS
 **/
META_RESULT  __stdcall META_3Grf_Set_Initial_Cellpower(unsigned int ms_timeout, int confg_cell/*uints:qdbm*/);
META_RESULT  __stdcall META_3Grf_Set_Initial_Cellpower_r(const int meta_handle, unsigned int ms_timeout, int confg_cell/*uints:qdbm*/);
/**
 * R8 get RxD LNA mode
 */
META_RESULT  __stdcall META_3Grf_QueryCurrentRxDLnaMode(unsigned int ms_timeout, unsigned char* mode);
META_RESULT  __stdcall META_3Grf_QueryCurrentRxDLnaMode_r(const int meta_handle, unsigned int ms_timeout, unsigned char* mode);
META_RESULT  __stdcall META_3Grf_SetCapId(unsigned int ms_timeout, unsigned int capId);
META_RESULT  __stdcall META_3Grf_SetCapId_r(const int meta_handle, unsigned int ms_timeout, unsigned int capId);
META_RESULT  __stdcall META_3Grf_GetMaxCapId(unsigned int ms_timeout, unsigned int* capId);
META_RESULT  __stdcall META_3Grf_GetMaxCapId_r(const int meta_handle, unsigned int ms_timeout, unsigned int* capId);
META_RESULT  __stdcall META_3Grf_AFC_Ex(unsigned int ms_timeout, URfTestCmdAFC* req, URfTestResultAFC_Ex* cnf);
META_RESULT  __stdcall META_3Grf_AFC_Ex_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdAFC* req, URfTestResultAFC_Ex* cnf);
META_RESULT __stdcall META_3Grf_SetRxBandwidth(unsigned int ms_timeout, unsigned char is_5mhz);
META_RESULT __stdcall META_3Grf_SetRxBandwidth_r(const int meta_handle, unsigned int ms_timeout, unsigned char is_5mhz);
/**
 * Starts from R8
 * The RX path splits into two path: main and diversity.
 */
typedef enum
{
    RX_PATH_NONE = 0, /**< none is enabled */
    RX_PATH_MAIN = 1, /**< main path is enabled */
    RX_PATH_DIVERSITY = 2, /**< diversity path is enabled */
    RX_PATH_BOTH = 3 /**< both path are enabled */
} RF_RX_PATH_T;
META_RESULT __stdcall META_3Grf_SetRxAntenna(unsigned int ms_timeout, RF_RX_PATH_T is_main);
META_RESULT __stdcall META_3Grf_SetRxAntenna_r(const int meta_handle, unsigned int ms_timeout, RF_RX_PATH_T is_main);
META_RESULT __stdcall META_3Grf_SetTxPaDriftCompEnable(unsigned int ms_timeout, unsigned char is_PaDrift);
META_RESULT __stdcall META_3Grf_SetTxPaDriftCompEnable_r(const int meta_handle, unsigned int ms_timeout, unsigned char is_PaDrift);
META_RESULT __stdcall META_3Grf_GetRfTemperature(unsigned int ms_timeout, const unsigned short measureCount, URfTestResultGetRfTempSensor* cnf);
META_RESULT __stdcall META_3Grf_GetRfTemperature_r(const int meta_handle, unsigned int ms_timeout, const unsigned short measureCount, URfTestResultGetRfTempSensor* cnf);
META_RESULT __stdcall META_3Grf_GetRfCapability(unsigned int ms_timeout, const URfTestCmdGetRfCapabilityReq* req, const unsigned int requestLength, URfTestResultGetRfCapabilityCnf* cnf, const unsigned int responseLength);
META_RESULT __stdcall META_3Grf_GetRfCapability_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetRfCapabilityReq* req, const unsigned int requestLength, URfTestResultGetRfCapabilityCnf* cnf, const unsigned int responseLength);
META_RESULT __stdcall META_3Grf_SetMIPICodeWord(unsigned int ms_timeout, const URfTestCmdSetMIPICodeWord* req);
META_RESULT __stdcall META_3Grf_SetMIPICodeWord_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetMIPICodeWord* req);
META_RESULT __stdcall META_3Grf_GetMIPICodeWord(unsigned int ms_timeout, const unsigned short RfBandIndex, URfTestResultGetMIPICodeWord* cnf);
META_RESULT __stdcall META_3Grf_GetMIPICodeWord_r(const int meta_handle, unsigned int ms_timeout, const unsigned short RfBandIndex, URfTestResultGetMIPICodeWord* cnf);
META_RESULT __stdcall META_3Grf_GetTemperatureInfo(const unsigned int ms_timeout, META_3Grf_TemperatureInfo_T* info);
META_RESULT __stdcall META_3Grf_GetTemperatureInfo_r(const int meta_handle, const unsigned int ms_timeout, META_3Grf_TemperatureInfo_T* info);
META_RESULT __stdcall META_3Grf_RxGainSweep(unsigned int ms_timeout, URfTestCmdRxGainSweep* req, URfTestResultRxGainSweep* cnf);
META_RESULT __stdcall META_3Grf_RxGainSweep_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdRxGainSweep* req, URfTestResultRxGainSweep* cnf);
META_RESULT __stdcall META_3Grf_UbinModeSetup(unsigned int ms_timeout, const unsigned char ubin_fdd_mode_init);//  1 : UBIN mode Init 3G FDD ,      0 : UBIN mode de-init 3G FDD
META_RESULT __stdcall META_3Grf_UbinModeSetup_r(const int meta_handle, unsigned int ms_timeout, const unsigned char ubin_fdd_mode_init);
const char* __stdcall META_3Grf_GetRfChipIdName(unsigned int id);
const char* __stdcall META_3Grf_GetRfChipIdName_r(const int meta_handle, unsigned int id);
/**
 * Low power mode RSSI.
**/
META_RESULT  __stdcall META_3Grf_Lpm_Rssi(unsigned int ms_timeout, URfTestCmdLPMRSSI* req, URfTestResultRSSI* cnf);
META_RESULT  __stdcall META_3Grf_Lpm_Rssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdLPMRSSI* req, URfTestResultRSSI* cnf);
META_RESULT  __stdcall META_3Grf_Lpm_RxDRssi(unsigned int ms_timeout, URfTestCmdLPMRSSI* req, URfTestResultRSSIRxD* cnf);
META_RESULT  __stdcall META_3Grf_Lpm_RxDRssi_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdLPMRSSI* req, URfTestResultRSSIRxD* cnf);
META_RESULT  __stdcall META_3Grf_Lpm_ContinuousRX(unsigned int ms_timeout, URfTestCmdLPMRSSI* req);
META_RESULT  __stdcall META_3Grf_Lpm_ContinuousRX_r(const int meta_handle, unsigned int ms_timeout, URfTestCmdLPMRSSI* req);
/**
 * 3G TX/RX calbiration data interface.
**/
typedef struct
{
    unsigned char version_number;
} URfTestCmdCalDataProcess;
#define UL1D_RF_LNA_NUM     6
#define CAL_TEMP_SECTION    8
#define CAL_UARFCN_SECTION 15
typedef  struct
{
    unsigned short max_uarfcn;
    char           path_loss_HPM[UL1D_RF_LNA_NUM];
    char           path_loss_LPM[UL1D_RF_LNA_NUM];
} UL1D_RF_LNA_PATHLOSS;
typedef  struct
{
    unsigned char           band;
    unsigned char           rxantpath;
    char                    temper_offset[CAL_TEMP_SECTION];
    UL1D_RF_LNA_PATHLOSS    loss_of_uarfcn[CAL_UARFCN_SECTION];
} URfTestPathlossItem;
typedef union
{
    URfTestPathlossItem     urfPathLoss;
} URfRxCalData;
typedef struct
{
    unsigned char version_number;
    unsigned char is_uplate_to_NVRAM;
    URfRxCalData  rxCalData;  
} URfTestCmdSetRxCalData;
META_RESULT  __stdcall META_3Grf_Set_RX_CalibrationData(unsigned int ms_timeout, const URfTestCmdSetRxCalData* req);
META_RESULT  __stdcall META_3Grf_Set_RX_CalibrationData_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetRxCalData* req);
typedef struct
{
    unsigned char version_number;
    unsigned char band;
    unsigned char rxantpath;
} URfTestCmdGetRxCalData;
typedef struct
{
    URfRxCalData  rxCalData;
} URfTestResultGetRxCalData;
META_RESULT  __stdcall META_3Grf_Get_RX_CalibrationData(unsigned int ms_timeout, const URfTestCmdGetRxCalData* req, URfTestResultGetRxCalData* cnf);
META_RESULT  __stdcall META_3Grf_Get_RX_CalibrationData_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetRxCalData* req, URfTestResultGetRxCalData* cnf);
#define URF_PA_PHASE_COMPENSATION_NUM     3
#define URF_TX_POWER_DAC_NUM              3
#define URF_TX_HYSTERESIS_NUM             2
#define URF_PA_SETTING_NUM                8
#define URF_CAL_UARFCN_SECTION_NUM       15
#define URF_CAL_PWR_DETECTOR_SECTION_NUM 32
#define URF_VGA_DAC_NUM                  10
#define URF_VGA_TEMP_COMPENSATION_1_NUM   8 
#define URF_VGA_TEMP_COMPENSATION_2_NUM   2
#define ARX_NORMAL_GAIN_MODE_NUM          6
#define ARX_LPM_GAIN_MODE_OFFSET_NUM      3
#define ARX_CAPABILITY_BIT_FIELD_SHIFT    5
#define UL1TST_CHIP_VERSION               1 
#define NVRAM_ACCESS_BY_UL1TST_TXDATA     2
#define NVRAM_ACCESS_BY_UL1TST_RXDATA     6
typedef struct
{
    unsigned short start;
    unsigned short end;
} UL1D_sHYSTERESISDATA;
typedef struct
{
    unsigned short level_0;
    unsigned short level_1;
} UL1D_sDC2DC;
typedef  struct
{
   unsigned short dc2dc_level;
   unsigned short vbias_dac;
   unsigned char  vm1;
   unsigned char  vm2;
}  UL1D_sPADATA;
typedef  struct
{
   unsigned short max_uarfcn;
   short          pwr_offset_dB;
   short          pwr_offset_txdac;
}  UL1D_sARFCN_SECTION;
typedef struct
{
    UL1D_sPADATA         pa_data; 
    unsigned short       vga_dac[URF_VGA_DAC_NUM];
    UL1D_sARFCN_SECTION  vga_comp_by_subband[URF_CAL_UARFCN_SECTION_NUM];
    short                vga_comp_by_temperature[URF_VGA_TEMP_COMPENSATION_1_NUM][URF_VGA_TEMP_COMPENSATION_2_NUM]; 
} UL1D_sTXPOWERDATA;
typedef struct
{
    unsigned char        pwr_dt_thr;
    unsigned char        pwr_dt_section;
    unsigned short       pwr_dt_dac[URF_CAL_PWR_DETECTOR_SECTION_NUM];
    short                pwr_dt_value[URF_CAL_PWR_DETECTOR_SECTION_NUM]; 
    UL1D_sARFCN_SECTION  pwr_dt_comp_by_subband[URF_CAL_UARFCN_SECTION_NUM];
    short                pwr_dt_comp_by_temperature[URF_VGA_TEMP_COMPENSATION_1_NUM][URF_VGA_TEMP_COMPENSATION_2_NUM]; 
}  UL1D_sPWTDTDATA;
typedef struct
{
    UL1D_sDC2DC          pa_dc2dc;
    UL1D_sTXPOWERDATA    power_dac[URF_TX_POWER_DAC_NUM]; 
    UL1D_sHYSTERESISDATA tx_hysteresis[URF_TX_HYSTERESIS_NUM];
    UL1D_sPWTDTDATA      pwr_dt_data;
} UL1D_sRAMPDATA;
typedef  struct
{
    unsigned char   pa_mode;
    char            prf;
    unsigned char   dc2dc_lvl;
    unsigned char   vm1;
    unsigned char   vm2;
    unsigned short  vbias_dac;
    unsigned short  pa_gain;
} UL1D_sPMULEVHANDLE;
typedef struct
{
    unsigned char        octlev_num_section;
    unsigned char        reserved_byte; 
    unsigned int         pa_phase_compensation[URF_PA_PHASE_COMPENSATION_NUM]; 
    UL1D_sPMULEVHANDLE   pmu_level_handle[URF_PA_SETTING_NUM];
    unsigned short       pa_gain_g12a;
    unsigned short       pa_gain_g12b;
} UL1D_sPAOCTLVLSETTING;
typedef struct
{
    unsigned char            band;
    UL1D_sRAMPDATA           txdacData;
    UL1D_sPAOCTLVLSETTING    txPAOCTLevelData;
}  URfTestTXDataItem;
typedef union
{
    URfTestTXDataItem     urfTestTxData;
} URfTxCalData;
typedef struct
{
    unsigned char version_number;
    unsigned char is_uplate_to_NVRAM;
    URfTxCalData  txCalData;
} URfTestCmdSetTxCalData;
META_RESULT  __stdcall META_3Grf_Set_TX_CalibrationData(unsigned int ms_timeout, const URfTestCmdSetTxCalData* req);
META_RESULT  __stdcall META_3Grf_Set_TX_CalibrationData_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetTxCalData* req);
typedef struct
{
    unsigned char version_number;
    unsigned char band;
} URfTestCmdGetTxCalData;
typedef struct
{
    URfTxCalData  txCalData;
} URfTestResultGetTxCalData;
META_RESULT  __stdcall META_3Grf_Get_TX_CalibrationData(unsigned int ms_timeout, const URfTestCmdGetTxCalData* req, URfTestResultGetTxCalData* cnf);
META_RESULT  __stdcall META_3Grf_Get_TX_CalibrationData_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetTxCalData* req, URfTestResultGetTxCalData* cnf);
typedef struct
{
    unsigned char fix_pga_gain;// 0 : normal 1 : fix PGA 12a 2 : fix PGA 12b
} URfTestCmdTxDPChFixGain;
META_RESULT  __stdcall META_3Grf_TxDpchFixGain(unsigned int ms_timeout, const URfTestCmdTxDPChFixGain* req);
META_RESULT  __stdcall META_3Grf_TxDpchFixGain_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdTxDPChFixGain* req);
#define UL1TST_WCDMA_BAND_SUPPORT_V3 5
#define UL1TST_HPM_POINT_V3          7
#define UL1TST_LPM_POINT_V3          4
#define UL1TST_GAIN_MODE_POINT_V3   (UL1TST_HPM_POINT_V3+UL1TST_LPM_POINT_V3)
#define UL1TST_FHC_POINT_V3          13
typedef struct
{
    unsigned char   cal_band_number;
    unsigned char   cal_band[UL1TST_WCDMA_BAND_SUPPORT_V3]; // band 1 = 1
} URfTestCmdGetMdCalInfoV3;
typedef struct
{
    unsigned char   band;
    unsigned char   rx_elna_mode;
    unsigned char   rxd_elna_mode;
    unsigned char   cal_point_hpm;
    unsigned char   cal_point_lpm;
    unsigned char   rx_cal_sequency[UL1TST_GAIN_MODE_POINT_V3];
    unsigned char   rx_elna_bypass[UL1TST_GAIN_MODE_POINT_V3];
    unsigned char   rxd_elna_bypass[UL1TST_GAIN_MODE_POINT_V3];
    short           rx_cal_dl_power_min[UL1TST_GAIN_MODE_POINT_V3];
    short           rx_cal_dl_power_max[UL1TST_GAIN_MODE_POINT_V3];
    short           rx_cal_dl_power[UL1TST_GAIN_MODE_POINT_V3];
} URfCalBandInfoV3;
typedef struct
{
    unsigned short    support_band_number;
    URfCalBandInfoV3  cal_band_info_v3[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestResultGetMdCalInfoV3;
META_RESULT  __stdcall META_3Grf_GetCalInfoV3(unsigned int ms_timeout, const URfTestCmdGetMdCalInfoV3* req, URfTestResultGetMdCalInfoV3* cnf);
META_RESULT  __stdcall META_3Grf_GetCalInfoV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetMdCalInfoV3* req, URfTestResultGetMdCalInfoV3* cnf);
#define UL1TST_MAX_RF_LNA_MODE_NUM_V3  7
#define UL1TST_FHC_FREQUENCY_NUMBER   15
typedef struct
{
    unsigned short     uarfcn;
    short              path_loss_HPM[UL1TST_MAX_RF_LNA_MODE_NUM_V3];
    short              path_loss_LPM[UL1TST_MAX_RF_LNA_MODE_NUM_V3];
} URfLnaPathlossV3;
typedef struct
{
    unsigned char      band;
    unsigned char      rxantpath;  // 1: main path, 2: div path
    char               temper_offset[CAL_TEMP_SECTION];
    URfLnaPathlossV3   loss_of_uarfcn[CAL_UARFCN_SECTION];
} URfPathlossV3;
typedef struct
{
    unsigned char      band;
    unsigned char      freq_count;
    unsigned char      pwr_count;
    unsigned char      hpm_cal_point;
    unsigned char      lpm_cal_point;
    unsigned char      rx_elna_mode;
    unsigned char      rxd_elna_mode;
    unsigned char      is_lpm[UL1TST_FHC_POINT_V3];
    unsigned char      rx_elna_bypass[UL1TST_FHC_POINT_V3];
    unsigned char      rxd_elna_bypass[UL1TST_FHC_POINT_V3];
    unsigned char      rx_cal_sequency[UL1TST_FHC_POINT_V3];
    unsigned char      fix_pga_gain[UL1TST_FHC_POINT_V3];
    unsigned char      pa_mode[UL1TST_FHC_POINT_V3];
    unsigned char      vga_dac_tpc_idx[UL1TST_FHC_POINT_V3];
    unsigned char      pa_section[UL1TST_FHC_POINT_V3];
    unsigned short     pa_gain[UL1TST_FHC_POINT_V3];
    short              rx_cal_dl_power[UL1TST_FHC_POINT_V3];
    unsigned short     dl_uarfcn[UL1TST_FHC_FREQUENCY_NUMBER];
    unsigned short     ul_uarfcn[UL1TST_FHC_FREQUENCY_NUMBER];
    URfTestTXDataItem  tx_cal_data_info;
    URfPathlossV3      rxm_cal_data_info;
    URfPathlossV3      rxd_cal_data_info;
} URfFhcBandParamV3;
typedef struct
{
    unsigned char      cal_band_number;
    unsigned char      cal_band[UL1TST_WCDMA_BAND_SUPPORT_V3];
    unsigned char      antenna_setting;
    unsigned char      step_duration;
    URfFhcBandParamV3  band_param[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestCmdFhcV3;
META_RESULT  __stdcall META_3Grf_FhcV3(unsigned int ms_timeout, const URfTestCmdFhcV3* req);
META_RESULT  __stdcall META_3Grf_FhcV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdFhcV3* req);
typedef struct
{
    unsigned short     ul_uarfcn;
    short              pd_value_h;
    short              pd_value_m;
    short              pd_value_l;
} URfFhcPdInfo;
typedef struct
{
    unsigned short     dl_uarfcn;
    short              hpm_rssi[UL1TST_HPM_POINT_V3];
    short              lpm_rssi[UL1TST_LPM_POINT_V3];
} URfFhcPathlossInfoV3;
typedef struct
{
    unsigned char         band;
    URfFhcPdInfo          pd_result[UL1TST_FHC_FREQUENCY_NUMBER];
    URfFhcPathlossInfoV3  rx_rssi_result[UL1TST_FHC_FREQUENCY_NUMBER];
    URfFhcPathlossInfoV3  rxd_rssi_result[UL1TST_FHC_FREQUENCY_NUMBER];
} URfFhcBandReportV3;
typedef struct
{
    unsigned char         ok;
    unsigned char         band_number;
    URfFhcBandReportV3    band_report[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestResultGetFhcReportV3;
META_RESULT  __stdcall META_3Grf_GetFhcResultV3(unsigned int ms_timeout, URfTestResultGetFhcReportV3* cnf);
META_RESULT  __stdcall META_3Grf_GetFhcResultV3_r(const int meta_handle, unsigned int ms_timeout, URfTestResultGetFhcReportV3* cnf);
typedef struct
{
    unsigned char  hwAGC;
    unsigned char  rx_elna_bypass; 
    unsigned char  rxd_elna_bypass;
    unsigned char  conti_rssi;
    unsigned char  rx_elna_mode;
    unsigned char  rxd_elna_mode;
    unsigned char  temperature;
    unsigned char  antenna_path; // 0:main, 1:diversity, 2:both
    unsigned char  lpm_mode;
    unsigned short uarfcn;
    unsigned short rx_gain;
    unsigned short rxd_gain;
    unsigned short rx_digital_gain;
    unsigned short rxd_digital_gain;
} URfTestCmdGetRssiV3;
typedef struct
{
    unsigned char  ok;
    unsigned char  rx_elna_bypass;
    unsigned char  rxd_elna_bypass;
    unsigned char  rx_lna_mode;
    unsigned char  rxd_lna_mode;
    unsigned short uarfcn;
    short          rx_rssi;
    short          rxd_rssi;
    unsigned short rx_used_gain;
    unsigned short rxd_used_gain;
} URfTestResultGetRssiV3;
META_RESULT  __stdcall META_3Grf_GetRssiV3(unsigned int ms_timeout, const URfTestCmdGetRssiV3* req, URfTestResultGetRssiV3* cnf);
META_RESULT  __stdcall META_3Grf_GetRssiV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetRssiV3* req, URfTestResultGetRssiV3* cnf);
typedef struct
{
    unsigned char   rx_elna_bypass; 
    unsigned char   rxd_elna_bypass;
    unsigned char   antenna_path;
    unsigned char   lpm_mode;
    unsigned char   rx_elna_mode;
    unsigned char   rxd_elna_mode;
    unsigned char   rx_cal_sequency;
    short           rx_dl_power;
} URfTestCmdPwrToGainV3;
typedef struct
{
    unsigned char   ok;
    unsigned short  rx_digital_gain; 
    unsigned short  rxd_digital_gain; 
    unsigned short  rx_rf_gain;      
    unsigned short  rxd_rf_gain;
} URfTestResultPwrToGainV3;
META_RESULT  __stdcall META_3Grf_GainSelectFromPowerV3(unsigned int ms_timeout, const URfTestCmdPwrToGainV3* req, URfTestResultPwrToGainV3* cnf);
META_RESULT  __stdcall META_3Grf_GainSelectFromPowerV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdPwrToGainV3* req, URfTestResultPwrToGainV3* cnf);
typedef struct
{
    unsigned char   rx_elna_bypass; 
    unsigned char   rxd_elna_bypass;
    unsigned char   band;
    unsigned char   antenna_path;
    unsigned char   lpm_mode;
    unsigned char   rx_lna_mode;
    unsigned char   rxd_lna_mode;
    unsigned char   rx_elna_mode;
    unsigned char   rxd_elna_mode;
} URfTestCmdLnaToGainV3;
typedef struct
{
    unsigned char   ok;
    unsigned short  rx_digital_gain; 
    unsigned short  rxd_digital_gain; 
    unsigned short  rx_rf_gain;      
    unsigned short  rxd_rf_gain;
    short           dl_power;
} URfTestResultLnaToGainV3;
META_RESULT  __stdcall META_3Grf_GainSelectFromLnaModeV3(unsigned int ms_timeout, const URfTestCmdLnaToGainV3* req, URfTestResultLnaToGainV3* cnf);
META_RESULT  __stdcall META_3Grf_GainSelectFromLnaModeV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdLnaToGainV3* req, URfTestResultLnaToGainV3* cnf);
typedef struct
{
    unsigned char      rxm_band_num;
    unsigned char      rxd_band_num;
    unsigned char      tx_band_num;
    unsigned char      rxm_cal_band[UL1TST_WCDMA_BAND_SUPPORT_V3];
    unsigned char      rxd_cal_band[UL1TST_WCDMA_BAND_SUPPORT_V3];
    unsigned char      tx_cal_band[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestCmdGetRxTxCalDataV3;
typedef struct
{
    unsigned char      rxm_count;
    unsigned char      rxd_count;
    unsigned char      tx_count;
    URfPathlossV3      rxm_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
    URfPathlossV3      rxd_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
    URfTestTXDataItem  tx_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestResultGetRxTxCalDataV3;
META_RESULT  __stdcall META_3Grf_GetRxTxCalibrationDataV3(unsigned int ms_timeout, const URfTestCmdGetRxTxCalDataV3* req, URfTestResultGetRxTxCalDataV3* cnf);
META_RESULT  __stdcall META_3Grf_GetRxTxCalibrationDataV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdGetRxTxCalDataV3* req, URfTestResultGetRxTxCalDataV3* cnf);
typedef struct
{
    unsigned char      is_uplate_to_NVRAM;
    unsigned char      rxm_count;
    unsigned char      rxd_count;
    unsigned char      tx_count;
    URfPathlossV3      rxm_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
    URfPathlossV3      rxd_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
    URfTestTXDataItem  tx_cal_data[UL1TST_WCDMA_BAND_SUPPORT_V3];
} URfTestCmdSetRxTxCalDataV3;
META_RESULT  __stdcall META_3Grf_SetRxTxCalibrationDataV3(unsigned int ms_timeout, const URfTestCmdSetRxTxCalDataV3* req);
META_RESULT  __stdcall META_3Grf_SetRxTxCalibrationDataV3_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetRxTxCalDataV3* req);
/**
 * @}
 */
//--------------------------------------------------------------------------//
//  RF Testing                                                              //
//--------------------------------------------------------------------------//
/**
 * \addtogroup GGE
 * @{
 */
//-----------------------------------------------------//
//  RF Testing: data structure definition              //
//-----------------------------------------------------//
typedef short   ARFCN;
typedef short   Gain;
typedef char    BSIC;
typedef short   Power;
typedef unsigned char   TimingAdvance;
typedef char    TSC;
typedef char    TimeSlot;

// RF ID
#define  RF_ID_UNKNOWN     0x00000000
#define  RF_ID_BRIGHT2     0x00000001
#define  RF_ID_BRIGHT4     0x00000002
#define  RF_ID_AERO        0x00000004
#define  RF_ID_AERO1PLUS   0x00000008
#define  RF_ID_POLARIS1    0x00000010
#define  RF_ID_POLARIS2    0x00000020
#define  RF_ID_SKY74045    0x00000040
#define  RF_ID_BRIGHT5P    0x00000080
#define  RF_ID_MT6116      0x00000100
#define  RF_ID_MT6119      0x00000200
#define  RF_ID_MT6119C     0x00000400
#define  RF_ID_MT6129A     0x00000800
#define  RF_ID_MT6129B     0x00001000
#define  RF_ID_MT6129C     0x00002000
#define  RF_ID_MT6129D     0x00004000
#define  RF_ID_MT6139B     0x00008000
#define  RF_ID_MT6139C     0x00010000
#define  RF_ID_MT6140A     0x00020000
#define  RF_ID_SKY74117    0x00040000
#define  RF_ID_SKY74400    0x00080000
#define  RF_ID_AERO2       0x00100000
#define  RF_ID_MT6140B     0x00200000
#define  RF_ID_ALICEG2S    0x00400000
#define  RF_ID_MT6139E     0x00800000
#define  RF_ID_SKY74137    0x01000000
#define  RF_ID_MT6140C     0x02000000
#define  RF_ID_GRF6201     0x04000000
#define  RF_ID_IRFS3001    0x08000000
#define  RF_ID_MT6140D     0x10000000
#define  RF_ID_AG2550      0x10000001
#define  RF_ID_AERO2E      0x10000002
#define  RF_ID_AD6548      0x10000005
#define  RF_ID_AD6546      0x10000006
#define  RF_ID_CMOSEDGE    0x10000007
#define  RF_ID_MTKSOC1     0x10000008
#define  RF_ID_MT6256RF    0x10000009
#define  RF_ID_MT6251RF    0x1000000a
#define  RF_ID_MT6252RF    0x1000000c
#define  RF_ID_MT6162      0x1000000d
#define  RF_ID_MT6163      0x1000000e
#define  RF_ID_MT6255RF    0x1000000f
#define  RF_ID_MT6250RF    0x10000010
#define  RF_ID_MT6280RF    0x10000011
#define  RF_ID_MT6167RF    0x10000012
#define  RF_ID_MT6260RF    0x10000013
#define  RF_ID_MT6166RF    0x10000014
#define  RF_ID_MT6169RF    0x10000015
#define  RF_ID_MT6165RF    0x10000016
#define  RF_ID_MT6261RF    0x10000017
#define  RF_ID_MT6580RF    0x10000018
#define  RF_ID_MT6176RF    0x10000019
#define  RF_ID_MT6179RF    0x1000001A
#define  RF_ID_MT6570RF    0x1000001B
#define  RF_ID_MT6177L     0x1000001C
#define  RF_ID_MT6173      0x1000001D
typedef enum
{
    FrequencyBand400 = 0,            ///< GSM 450/480 band
    FrequencyBand850 = 1,            ///< GSM 850 band
    FrequencyBand900 = 2,            ///< GSM 900 band
    FrequencyBand1800 = 3,           ///< DCS 1800 band
    FrequencyBand1900 = 4,           ///< PCS 1900 band

    FrequencyBandCount               ///< count of supported bands
} FrequencyBand;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    char            sampleNoPerFrame;   ///< number of samples per frame
    Gain            gain;               ///< Gain that should be used in power management
    short           frames;             ///< number of frames
} RfPm_Req;

typedef struct
{
    unsigned char   valid;              // if valid != zero, it means the extra info is meaningful.
    // otherwise, the extra info should be ignore.
    int             iOffset;
    int             qOffset;
    int             validSamples;
} RfPmExtraInfo_T;

/**
 * This request structure is used for Power scan specified if flag
 */
typedef struct
{
    /// original power scan request
    RfPm_Req        m_Pm;
    /// if flag used for specifying the if flag in power scan (override the if flag setting)
    char   m_IfFlag;
} RfIfPm_Req;

typedef struct
{
    int             power;              ///< average power
    int             deviation;          ///< deviation of power measurement
    Gain            usedGain;           ///< Gain that is used
    unsigned char   ok;                 ///< status
    RfPmExtraInfo_T extra_info;         ///< extra info
} RfPm_Cnf;

typedef struct
{
    ARFCN           arfcn;              ///< absolute radio frequency channel number
    short           dacValue;           ///< AFC DAC value
    Gain            gain;               ///< gain used for AFC testing
    short           testNumber;         ///< test number
} RfAfc_Req;

typedef struct
{
    short           fcb_ok_number;      ///< successful number of FCB decoded
    int             freqOffset;         ///< average frequency error
    int             deviation;          ///< deviation of frequency error
    unsigned char   ok;                 ///< status
} RfAfc_Cnf;

typedef enum
{
    AB_TX_RANDOM_WITH_SYNC_SEQ
    , NB_TX_ALL_ZEROS_WITHOUT_TSC
    , NB_TX_ALL_ONES_WITHOUT_TSC
    , NB_TX_ALTER_BITS_WITHOUT_TSC
    , NB_TX_RANDOM_WITH_TSC
    , NB_TX_PATTERN_WITHOUT_TSC
    , NB_TX_FIXED_RANDOM_WITH_TSC
    , NB_TX_FIXED_ALL_ZEROS_WITH_TSC
    , NB_TX_FIXED_ALTER_BITS_WITH_TSC
    , NB_TX_FIXED_ALL_ONES_WITH_TSC
    , NB_TX_FIXED_OE_PATTERN_WITH_TSC
} APCTxPattern;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    BSIC            bsic;               ///< bsic value used in transmission
    Power           power;              ///< Tx power in the unit of PCL
    short           frames;             ///< the number of frames NB should transmit
    short           dacValue;           ///< AFC DAC value
    APCTxPattern    burstTypeNB;
} RfNbtx_Req;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    Gain            gain;               ///< Gain that should be used
    unsigned char   OnOff;              ///< On or off
} RfCnRx_Req;

typedef enum
{
    CONT_TX_ALL_ZEROS
    , CONT_TX_ALL_ONES
    , CONT_TX_ALTERNATE_BITS
    , CONT_TX_PSEUDO_RANDOM
    , CONT_TX_PATTERN_WITHOUT_TSC
} ContTxPattern;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    ContTxPattern   pattern;
    unsigned char   OnOff;              ///< On or off
} RfCnTx_Req;

typedef struct
{
    char    TxTrimI;
    char    TxTrimQ;
    char    TxOffsetI;
    char    TxOffsetQ;
} RfSetBBTXCfg_Req;

typedef struct
{
    char    TxTrimI;
    char    TxTrimQ;
    char    TxOffsetI;
    char    TxOffsetQ;
    char    TxCalbias;
    char    TxIQSwap;
    char    TxCMV;
    char    TxGain;
    char    TxCalrcsel;
} RfBBTXCfg2;

typedef struct
{
    char    TxTrimI;
    char    TxTrimQ;
    char    TxOffsetI;
    char    TxOffsetQ;
    char    TxCalbias;
    char    TxIQSwap;
    char    TxCMV;
    char    TxGain;
    char    TxCalrcsel;
    char    TxPhasesel;
} RfBBTXCfg3;

typedef struct
{
    char    TxTrimI;
    char    TxTrimQ;
    char    TxOffsetI;
    char    TxOffsetQ;
    char    TxCalbias;
    char    TxIQSwap;
    char    TxCMV;
    char    TxGain;
    char    TxCalrcsel;
    char    TxPhasesel;
    char    TxCoarseI;
    char    TxCoarseQ;

} RfBBTXCfg4; //RfTestCmdSetBBTXCfg4

typedef struct
{
    unsigned char bbtx_common_mode_voltage;
    unsigned char bbtx_gain;
    unsigned char bbtx_calrcsel;
    unsigned char bbtx_trimI;   // need to set
    unsigned char bbtx_trimQ;   // need to set
    unsigned char bbtx_dccoarseI; // need to set
    unsigned char bbtx_dccoarseQ; // need to set
    unsigned char bbtx_offsetI; // need to set
    unsigned char bbtx_offsetQ; // need to set
    unsigned char bbtx_isCalibrated; // need to set
    int           apc_bat_low_voltage;
    int           apc_bat_high_voltage;
    int           apc_bat_low_temperature;
    int           apc_bat_high_temperature;
    unsigned char bbtx_common_mode_voltage_h;
    unsigned char bbtx_gain_h;
    unsigned char bbtx_calrcsel_h;
    unsigned char bbtx_trimI_h;
    unsigned char bbtx_trimQ_h;
    unsigned char bbtx_dccoarseI_h;
    unsigned char bbtx_dccoarseQ_h;

    unsigned char bbtx_offsetI_h;
    unsigned char bbtx_offsetQ_h;
    unsigned char bbtx_phsel;
    unsigned char bbtx_phsel_h;
} BBTXParameters_T;
typedef enum
{
    CodingSchemeNone = 0,
    CodingSchemeCS1,
    CodingSchemeCS2,
    CodingSchemeCS3,
    CodingSchemeCS4,
    CodingSchemePRACh8,
    CodingSchemePRACh11,
    CodingSchemeMCS1,
    CodingSchemeMCS2,
    CodingSchemeMCS3,
    CodingSchemeMCS4,
    CodingSchemeMCS5,
    CodingSchemeMCS6,
    CodingSchemeMCS7,
    CodingSchemeMCS8,
    CodingSchemeMCS9,
    CodingSchemeCount,
} CodingScheme;

typedef struct
{
    ARFCN           arfcn;          ///< absolute radio frequency channel number
    BSIC            bsic;           ///< training sequence
    char            timeSlotmask;   ///< time slot mask, slot_1: 0x01, slot_2: 0x02, slot_3: 0x04, slot_4: 0x08
    Power           powerLev[4];    ///< power level for each time slot
    CodingScheme    cs[4];          ///< coding scheme for each time slot
    TimingAdvance   ta;             ///< time advance
    int             frames;         ///< the number of frames should transmit
    short           dacValue;       ///< AFC DAC value
} RfMultiSlotTX_Req;

typedef struct
{
    FrequencyBand   rf_band;
    int             power_level;
    int             apc_dac;
} RfSetRampApcLevel_Req;

typedef struct
{
    short           dacValue;       ///< AFC DAC value
} RfSetAfcDacValue_Req;

typedef struct
{
    int             cap_id;
} RfSetCrystalCfg_Req;

typedef struct
{
    ARFCN           arfcn;          ///< absolute radio frequency channel number
    BSIC            bsic;           ///< training sequence
    char            timeSlotmask;   ///< time slot mask, slot_1: 0x01, slot_2: 0x02, slot_3: 0x04, slot_4: 0x08
    Power           powerLev[4];    ///< power level for each time slot
    CodingScheme    cs[4];          ///< coding scheme for each time slot, MCS1~9 is only valid for EPSK function
    TimingAdvance   ta;             ///< time advance
    int             frames;         ///< the number of frames should transmit
    short           dacValue;       ///< AFC DAC value
    APCTxPattern    pattern;        ///< Tx pattern is only valid for EPSK function
    unsigned short  pattern_data;   ///< if NB_TX_PATTERN_WITHOUT_TSC==pattern, user can input any 16bits value as pattern.
} Rf_MultiSlotTXEx_Req;

typedef struct
{
    unsigned int    id;             ///< 2G RF chip ID please refer RF_ID_XXXX
} RFMod_ID;

typedef enum
{
    MS_GSM = 0
             , MS_GPRS
    , MS_EGPRS_RX_ONLY
    , MS_EGPRS_FULL_FUNCTION
} MS_CAPABILITY_E;

typedef struct
{
    unsigned int    GSM400;         ///< Zero: not support, Non-zero: support
    unsigned int    GSM850;
    unsigned int    GSM900;
    unsigned int    DCS1800;
    unsigned int    PCS1900;
} RFBandSupport_S;

typedef struct
{
    MS_CAPABILITY_E     capability;
    RFBandSupport_S     band_support;
} RfMsCapability_S;

typedef struct
{
    unsigned int    GSM: 1;
    unsigned int    GPRS: 1;
    unsigned int    EDGE_RX: 1;
    unsigned int    EDGE_8PSK_TX: 1;
    unsigned int    Calibration_8PM: 1;
} RfMsCapabilityBits;

typedef struct
{
    unsigned int    GSM400: 1;
    unsigned int    GSM850: 1;
    unsigned int    GSM900: 1;
    unsigned int    DCS1800: 1;
    unsigned int    PCS1900: 1;
} RfMsBandSupportBits;

typedef struct
{
    RfMsCapabilityBits      capability;
    RfMsBandSupportBits     band_support;
} RfMsCapabilityEx_S;


typedef struct
{
    unsigned int    GSM: 1;
    unsigned int    GPRS: 1;
    unsigned int    EDGE_RX: 1;
    unsigned int    EDGE_8PSK_TX: 1;
    unsigned int    Calibration_8PM: 1;
    unsigned int    Calibration_FDT: 1;     // new
    unsigned int    Calibration_33Steps: 1; // new
    unsigned int    NSFT: 1; // NSFT
    unsigned int    AFCType: 1; // AFC Type
    unsigned int    GMSKClosedLoopPowerControl: 1;
    unsigned int    OpenLoopPowerControl: 1;
    unsigned int    ClosedLoopPowerControlTemperature: 1;
    unsigned int    EPSKClosedLoopPowerControl: 1;
    unsigned int    MiddleLowLnaCalibration: 1;
    unsigned int    AuxTempADC: 1;
    unsigned int    BsiTempADC: 1;
} RfMsCapabilityBits_2;

typedef struct
{
    RfMsCapabilityBits_2        capability;
    RfMsBandSupportBits     band_support;
} RfMsCapabilityEx2_S;

typedef struct
{
    unsigned short support_gsm: 1;
    unsigned short support_gprs: 1;
    unsigned short support_edge_rx: 1;
    unsigned short support_epsk_tx: 1;
    unsigned short support_8pm: 1;
    unsigned short support_fhc: 1;
    unsigned short support_nsft: 1;
    unsigned short band_gsm400: 1;
    unsigned short band_gsm850: 1;
    unsigned short band_gsm900: 1;
    unsigned short band_dcs1800: 1;
    unsigned short band_pcs1900: 1;
    /**
     * base on the PS edge switch
     * 0: check the EDGE TX power
     * 1: by pass check
     */
    unsigned short ps_unsupport_edge_tx: 1;
    unsigned short reserved1: 2;
} RfCapabilityItem;


/**
 * Description: get the tx_pcl GMSK and EPSK version from the parameter field
 **/
#define TX_PCL_EPSK_VERSION_MASK (0x7F << 7)
#define GET_EPSK_VERSION(x) (((x) & TX_PCL_EPSK_VERSION_MASK) >> 7)
#define GET_GSM_VERSION(x) ((x) & 0x0001)
//Battery Compensate
/**
 * When the sw capability for EDGE Battery Compensation is equal to 1, and in 14-bits paramter, LSB of first 7 bits equals 1.
 * unit conversion for EDGE Battery Compensation becomes as dBm, Otherwise, in 14-bits paramter, LSB of first 7 bits equals 0.,
 * unit conversion for EDGE Battery Compensation do not change (still use weighting)
 */

typedef struct
{
    unsigned short is_capable: 1;
    unsigned short is_mandatory: 1;
    unsigned short parameter: 14;
} RfFactoryModeCalItem;
typedef struct
{
    RfFactoryModeCalItem cap_id; /* 0 */
    RfFactoryModeCalItem afc; /* 1 */
    RfFactoryModeCalItem rx_pathloss; /* 2 */
    RfFactoryModeCalItem tx_pcl; /* 3 */
    RfFactoryModeCalItem tx_subband; /* 4 */
    RfFactoryModeCalItem trx_offset; /* 5 */
    RfFactoryModeCalItem tx_iq; /* 6 */
    RfFactoryModeCalItem tx_fb_dac; /* 7 */
    RfFactoryModeCalItem tx_slope_skew; /* 8 */
    RfFactoryModeCalItem w_coef; /* 9 */
    RfFactoryModeCalItem txpc; /* 10 */
    RfFactoryModeCalItem temp_adc; /* 11 */
    RfFactoryModeCalItem remove_32k_xo; /* 12 */
    RfFactoryModeCalItem co_crystal; /* 13 */
    RfFactoryModeCalItem high_lna_sp; /* 14 */
    RfFactoryModeCalItem mid_lna_sp; /* 15 */
    RfFactoryModeCalItem low_lna_sp; /* 16 */
    //Battery Compensate
    /** for EPSK new feature
     * When the sw capability for EDGE Battery Compensation is equal to 1, and in 14-bits paramter, LSB of first 7 bits equals 1.
     * unit conversion for EDGE Battery Compensation becomes as dBm, Otherwise, in 14-bits paramter, LSB of first 7 bits equals 0.,
     * unit conversion for EDGE Battery Compensation do not change (still use weighting)
     */
    RfFactoryModeCalItem bat_temp_comp; /* 17 */
    RfFactoryModeCalItem dts_gain_cmb; /* 18 */
    //---------------------------------------------------------------------------
    // parameter: 0, capable: 1, mandatory: 1 ==> support FHC double-band combine, but only 50 steps (orignal interface)
    // parameter: 1, capable: 1, mandatory: 1 ==> support FHC double-band combine, but only 100 steps (Big interface)
    //---------------------------------------------------------------------------
    RfFactoryModeCalItem uts_band_cmb; /* 19 */
    //---------------------------------------------------------------------------
    // Temp ADC on TDD mode, use the same NVRAM item of 2G temperature ADC("NVRAM_EF_L1_TEMPERATURE_ADC_LID")
    // When the sw capability for co_temp_adc is equal to 1,
    // it means 2G and TDD use the same NVRAM item of 2G temperature ADC
    // (TDD: "NVRAM_EF_AST_TL1_TEMP_DAC_LID")
    //---------------------------------------------------------------------------
    RfFactoryModeCalItem co_temp_adc; /* 20 */
    //------------------------------------------------------
    // Fill middle/low mode of LNA path loss by high mode result
    //-----------------------------------------------------
    RfFactoryModeCalItem adjustable_lna_mode_pathloss; /* 21 */
    //------------------------------------------------------
    // Indicate the EDGE TX should calibrated by gain rf mechanism
    // parameter: 0, capable: 1, mandatory: 1
    //-----------------------------------------------------
    RfFactoryModeCalItem gain_rf_cal; /* 22 */
    /**
     * Indicate the AP/MD NVRAM check is required or not
     * is_capable: 0: check AP/MD NVRAM, 1: bypass AP/MD NVRAM check
     * is_mandatory: don't care
     * parameter: check capability when is_capable equal to 0
     *      1: GPS co-clock configure correct. Do GPS co-clock.
     *      Others: Error => check WMT.CFG
     **/
    RfFactoryModeCalItem bypass_check_fixafc; /* 23 */
    /**
     * Bit map used to indicate the TADC calibration data can be shared between different RAT
     * the bitmap is defined in parameter part and starts from LSB to MSB
     * new RAT can be extended upto 14 RATs;bits: (0|0|C|Lf|Lt|T|W|G)
     */
    RfFactoryModeCalItem multi_rat_tadc_bitmap; /* 24 */
    /**
     * Bit map used to indicate the AFC calibration data can be shared between different RAT
     * the bitmap is defined in parameter part and starts from LSB to MSB
     * new RAT can be extended upto 14 RATs;bits: (0|0|C|Lf|Lt|T|W|G)
     */
    RfFactoryModeCalItem multi_rat_afc_bitmap; /* 25 */
    /**
     * unsigned short    cal_lna_mode    :4;     // LNA mode(s) need to be calibrated (Bitwise)
     * unsigned short    dup_lna_src     :4;     // Duplicated LNA mode From (Bitwise)
     * unsigned short    dup_lna_dest    :4;     // Duplicated LNA mode To (Bitwise)
     * unsigned short    reserved        :2;
     **/
    RfFactoryModeCalItem reduce_rx_lna_cal; /* 26 */
    /**
     * Indicate the Get temperature info. API is available on the target
     * is_capable: 0: not supported, 1: supported
     * is_mandatory: don't care
     * parameter: don't care
     **/
    RfFactoryModeCalItem temperature_info; /* 27 */
    /**
     * Indicate the Get temperature info. API is available on the target
     * is_capable: 0: not supported, 1: supported
     * is_mandatory: don't care
     * parameter: the band support bit-map from of GSM850, GSM900, DCS1800, PCS1900 (from LSB to MSB)
     **/
    RfFactoryModeCalItem dt_coexistence_info; /* 28 */
    /**
     * Indicate the external temp sensor support.
     * is_capable: 0: not supported, 1: supported
     * is_mandatory: don't care
     * parameter: 0:internal sensor 2:external sensor
     **/
    RfFactoryModeCalItem thermal_sensor_type; /* 29 */
    /**
     * Indicate support list mode NSFT or not.
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: don't care
     **/
    RfFactoryModeCalItem list_mode_nsft; /* 30 */
    /**
     * Indicate world mode id
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: bits: 0|0|Lf|Lt|W|C|T|G
     **/
    RfFactoryModeCalItem worldmode_id_info; /* 31 */
    /**
     * Indicate 32k less afc dac selection
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: bits: don't care
     **/
    RfFactoryModeCalItem crystal_on_pmic_enable; /* 32 */
    /**
     * Indicate subband low weighting calibration
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: bits: [6:0] for LB, [13:7] for HB
     **/
    RfFactoryModeCalItem low_pcl_subband_cal; /* 33 */
    /**
     * Indicate enable extra fb for RX sync
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: don't care
     **/
    RfFactoryModeCalItem fhc_dts_extra_fb_enable; /* 34 */
    /**
     * Indicate set DSP point parameter for sawless mid gain 
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     **/
    RfFactoryModeCalItem  sawless_lna_sp; /* 35 */
    /**
     * Indicate L1 nvram access command 
     * parameter: 0, capable: 1, mandatory: 1 ==> support
     * parameter: 0, capable: 0, mandatory: 0 ==> not support
     * parameter: |...|...|Not define yet|Rx path loss|
     **/ 
    RfFactoryModeCalItem nvram_access_interface; /* 36 */
    /**
     * Indicate eLNA support band  
     * parameter: 0, capable: 0, mandatory: 0 ==> not support eLNA
     * parameter: 0, capable: 1, mandatory: 1 ==> support eLNA
     * parameter: |...|PSC1900 |DSC1800|GSM900|GSM850|GSM400|
     **/ 
    RfFactoryModeCalItem elna_support_band_bitmap; /* 37 */
    RfFactoryModeCalItem elna_high_sp; /* 38 */
    RfFactoryModeCalItem elna_mid_sp;  /* 39 */
    RfFactoryModeCalItem elna_low_sp;  /* 40 */
    RfFactoryModeCalItem elna_w_coef_sp; /* 41 */
    RfFactoryModeCalItem elna_mid_sawless_sp; /* 42 */
    RfFactoryModeCalItem elna_high_sensitivity_sp; /* 43 */            
    RfFactoryModeCalItem elna_bypass_low_maxpin_sp; /* 44 */
    RfFactoryModeCalItem elna_bypass_gain_threshold; /* 45 */
    RfFactoryModeCalItem elna_bypass_support_band_bitmap; /* 46 */
} RfCalibrationItem;
typedef struct
{
    int                  valid;
    int                  status;
    RfCapabilityItem     capabilityItems;
    RfCalibrationItem    calibrationItems;
} RfMsCapabilityEx3_S;

typedef enum
{
    AFC_SINWAVE_OFF = 0,
    AFC_SINWAVE_ON
} AFC_SINWAVE_DETECTION_E;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    ContTxPattern   pattern;
    unsigned short  pattern_data;
    unsigned char   OnOff;              ///< On or off
    unsigned short  modtype;            ///< modulation type: 0->GMSK, 1->EPSK
} RfCnTxEx_Req;

typedef struct
{
    ARFCN           arfcn;              ///< Absolute radio frequency channel number
    ContTxPattern   pattern;
    unsigned short  pattern_data;
    unsigned char   OnOff;              ///< On or off
    unsigned short  modtype;            ///< modulation type: 0->GMSK, 1->EPSK
    Power           powerLev;           ///< power level
} RfCnTxEx2_Req;

typedef struct
{
    short           dacValue;       ///< AFC DAC value
} RfGetAfcDacValueAtRTXOffsetCal;

//----------  FDT related structure -----------------------

#define MAX_STEP_CNT   50
typedef struct
{
    FrequencyBand      band;
    ARFCN              arfcn;
    short              dac_value[33];
    Gain               gain;
    short              repeat_cnt;   ///< repetitive test counts (frames) for each AFC DAC value
    bool               capid_cal;    ///< capid calibration ctrl
    bool               linear_cal;   ///< 33 stages calibration ctrl
    int                capid_min;    ///< min value for capid range when capid_cal is True; capid when capid_cal is False
    int                capid_max;    ///< max value for capid range

} Rf_DSSAFC_T;

typedef struct
{
    FrequencyBand       band;
    ARFCN               arfcn;
    Gain                gain[6];     ///< gain for rx slot 0/1/2/3/4/5
    short               repeat_cnt;  ///< repetitive test counts (frames) for each ARFCN value
} Rf_DSSPL_T;

typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num; ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;               ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    char                step_cnt;
    Rf_DSSPL_T          PathLossDSS[MAX_STEP_CNT - 2]; ///< because sync process will need 2 steps
} Rf_DTS_REQ_T;

typedef struct
{
    FrequencyBand        band;
    ARFCN                arfcn;
    char                 timeslot_per_frame;
    char                 apc_dac_pcl_sel;                ///< 1: apc_dac, 0: apc_pcl
    short                apc_dac_pcl_value[4];
    unsigned char        pa_vbias_val[4];
    unsigned char        is_low_pcl[4];

    CodingScheme         cs[4];
    int                  repeat_cnt;
    short                afc_dac_value;
    char                 tsc;
    APCTxPattern         pattern;
    unsigned short       pattern_data;
} Rf_USSAPC_T;

typedef struct
{
    char                step_cnt;
    short               high_apc_dcoffset[FrequencyBandCount];
    Rf_USSAPC_T         ApcUSS[MAX_STEP_CNT];
} Rf_UTS_REQ_T;

typedef struct
{
    int      power[MAX_STEP_CNT - 2]; ///< because sync process will need 2 steps
    short    valid_sample[MAX_STEP_CNT - 2];
    bool     ok;
} Rf_DSSPL_RESULT_T;

typedef struct
{
    int      freq_offset[33];    ///< only valid when 33 stage calibration is ON
    int      deviation[33];      ///< only valid when 33 stage calibration is ON
    short    fcb_ok_number[33];  ///< only valid when 33 stage calibration is ON
    int      capid;              ///< only valid when capid calibration is ON
    short    init_dac_value;     ///< only valid when 33 stage calibration is OFF
    int      slope;              ///< only valid when 33 stage calibration is OFF
    bool     ok;
} Rf_DSSAFC_RESULT_T;



#define FHC_PRE_CAPID_SEARCH_NUM   9
#define FHC_MAX_CAPID_SEARCH_NUM   (7 + FHC_PRE_CAPID_SEARCH_NUM)
typedef struct
{
    int               path_loss_cnt;
    int               freq_offset;
    int               capid_freq_offset_min;
    int               capid_freq_offset[FHC_MAX_CAPID_SEARCH_NUM];       // 20 is the possible max value for FHC_MAX_CAPID_SEARCH_NUM in target side
    int               capid_search_order[FHC_MAX_CAPID_SEARCH_NUM];  // 20 is the possible max value for FHC_MAX_CAPID_SEARCH_NUM in target side
    int               capid;
    int               capid_high;
    int               capid_low;
    int               capid_best;
    short             afc_dac;
    short             arfcn;
    short             capid_cnt;
    short             repeat_index;
    char              state;
    char              capid_index;
    char              capid_okay_cnt;
    char              afc_dac_index;
    char              sb_okay_cnt;
    unsigned char     sb_fail_cnt;
    unsigned char     fb_fail_cnt;
    bool              pl_started;
    bool              pre_capid_cal_ok[FHC_PRE_CAPID_SEARCH_NUM];

} Rf_FHC_DTSM_INFO_T;

typedef enum
{
    DTS_RESULT_READY = 0,       ///< DTS results is ready to get back
    DTS_RESULT_NOT_READY,       ///< DTS result is still in progress and not ready to get back
    DTS_RESULT_NOT_REQUESTED    ///< Haven't called the META_Rf_StartFdtDL() in advance.
} RF_DTS_GET_RESULT_STATUS;
typedef struct
{
    RF_DTS_GET_RESULT_STATUS     status;
    Rf_DSSPL_RESULT_T      PLResult;
    Rf_DSSAFC_RESULT_T     AfcResult;
    Rf_FHC_DTSM_INFO_T     DtsmInfo;
} Rf_DTS_CNF_T;

META_RESULT  __stdcall META_Rf_GetFdtDL(unsigned int ms_timeout, Rf_DTS_CNF_T* fdt_dl_get_result_cnf);
META_RESULT  __stdcall META_Rf_GetFdtDL_r(const int meta_handle, unsigned int ms_timeout, Rf_DTS_CNF_T* fdt_dl_get_result_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult(unsigned int ms_timeout, const Rf_DTS_REQ_T*  fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_r(const int meta_handle, unsigned int ms_timeout, const Rf_DTS_REQ_T*  fdt_dl_req);

typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num; ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;               ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    char                step_cnt;
    Rf_DSSPL_T          PathLossDSS[MAX_STEP_CNT - 2]; ///< because sync process will need 2 steps
    short               lpm_sb_num;
} RF_DTS_REQ_EX_T;
typedef struct
{
    int           cload_freq_offset;
    unsigned char ok;
    unsigned char is_perform_cal;
} RF_DSSLPM_RESULT_T;
typedef struct
{
    RF_DTS_GET_RESULT_STATUS     status;
    Rf_DSSPL_RESULT_T      PLResult;
    Rf_DSSAFC_RESULT_T     AfcResult;
    Rf_FHC_DTSM_INFO_T     DtsmInfo;
    RF_DSSLPM_RESULT_T     LpmResult;
} RF_DTS_CNF_EX_T;

META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Ex(unsigned int ms_timeout, const RF_DTS_REQ_EX_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Ex_r(const int meta_handle, unsigned int ms_timeout, const RF_DTS_REQ_EX_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_GetFdtDL_Ex(unsigned int ms_timeout, RF_DTS_CNF_EX_T* result);
META_RESULT  __stdcall META_Rf_GetFdtDL_Ex_r(const int meta_handle, unsigned int ms_timeout, RF_DTS_CNF_EX_T* result);

//-----------------------------------------------------//
//  FHC DTS & UTS gain mode and band combine           //
//-----------------------------------------------------//
/**
 * Description:
 *  Extenstion DTS interface for gain mode combine
 **/
#define MAX_STEP_EX_CNT   100
typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num; ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;               ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    char                step_cnt;
    Rf_DSSPL_T          PathLossDSS[MAX_STEP_EX_CNT - 2]; ///< because sync process will need 2 steps
} Rf_DTS_REQ_BIG_T;

typedef struct
{
    int      power[MAX_STEP_EX_CNT - 2]; ///< because sync process will need 2 steps
    short    valid_sample[MAX_STEP_EX_CNT - 2];
    bool     ok;
} Rf_DSSPL_RESULT_BIG_T;

typedef struct
{
    RF_DTS_GET_RESULT_STATUS     status;
    Rf_DSSPL_RESULT_BIG_T        PLResult;
    Rf_DSSAFC_RESULT_T           AfcResult;
    Rf_FHC_DTSM_INFO_T           DtsmInfo;
} Rf_DTS_CNF_BIG_T;

typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num; ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;               ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    char                step_cnt;
    Rf_DSSPL_T          PathLossDSS[MAX_STEP_EX_CNT - 2]; ///< because sync process will need 2 steps
    short               lpm_sb_num;
} RF_DTS_REQ_EX_BIG_T;

typedef struct
{
    RF_DTS_GET_RESULT_STATUS     status;
    Rf_DSSPL_RESULT_BIG_T        PLResult;
    Rf_DSSAFC_RESULT_T           AfcResult;
    Rf_FHC_DTSM_INFO_T           DtsmInfo;
    RF_DSSLPM_RESULT_T           LpmResult;
} RF_DTS_CNF_EX_BIG_T;

/**
 * Description:
 *  Extenstion UTS interface for middel chanenl tx pcl calibration band combine
 **/
typedef struct
{
    char                step_cnt;
    short               high_apc_dcoffset[FrequencyBandCount];
    Rf_USSAPC_T         ApcUSS[MAX_STEP_EX_CNT];
} Rf_UTS_REQ_BIG_T;

/**
 * Extension interface for the target *not* supported LPM
 **/
META_RESULT  __stdcall META_Rf_GetFdtDL_Big(unsigned int ms_timeout, Rf_DTS_CNF_BIG_T* fdt_dl_get_result_cnf);
META_RESULT  __stdcall META_Rf_GetFdtDL_Big_r(const int meta_handle, unsigned int ms_timeout, Rf_DTS_CNF_BIG_T* fdt_dl_get_result_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDL_Big(unsigned int ms_timeout, const Rf_DTS_REQ_BIG_T*  fdt_dl_req,  Rf_DTS_CNF_BIG_T* fdt_dl_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDL_Big_r(const int meta_handle, unsigned int ms_timeout, const Rf_DTS_REQ_BIG_T*  fdt_dl_req,  Rf_DTS_CNF_BIG_T* fdt_dl_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Big(unsigned int ms_timeout, const Rf_DTS_REQ_BIG_T*  fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Big_r(const int meta_handle, unsigned int ms_timeout, const Rf_DTS_REQ_BIG_T*  fdt_dl_req);

/**
 * Extension interface for the target *supported* LPM
 **/
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Big_Ex(unsigned int ms_timeout, const RF_DTS_REQ_EX_BIG_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Big_Ex_r(const int meta_handle, unsigned int ms_timeout, const RF_DTS_REQ_EX_BIG_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_GetFdtDL_Big_Ex(unsigned int ms_timeout, RF_DTS_CNF_EX_BIG_T* result);
META_RESULT  __stdcall META_Rf_GetFdtDL_Big_Ex_r(const int meta_handle, unsigned int ms_timeout, RF_DTS_CNF_EX_BIG_T* result);

/**
 * Extension interface for the TX quad band combine
 **/
META_RESULT  __stdcall META_Rf_StartFdtUL_Big(unsigned int ms_timeout, const Rf_UTS_REQ_BIG_T*  fdt_ul_req);
META_RESULT  __stdcall META_Rf_StartFdtUL_Big_r(const int meta_handle, unsigned int ms_timeout, const Rf_UTS_REQ_BIG_T*  fdt_ul_req);

#define MAX_STEP_EX_512P_CNT   512

typedef enum 
{
    GSM_LNA_NULL = 0,
    GSM_LNA_HIGH,
    GSM_LNA_MID,
    GSM_LNA_LOW,
    GSM_LNA_W_COEF,
    GSM_LNA_SAWLESS_MID,
    GSM_LNA_END
} GSM_LNA_Cal_Type;

typedef struct
{
    FrequencyBand       band;
    ARFCN               arfcn;
    Gain                gain[6];     ///< gain for rx slot 0/1/2/3/4/5
    short               repeat_cnt;  ///< repetitive test counts (frames) for each ARFCN value
    GSM_LNA_Cal_Type    gsm_lna_mode;  
} Rf_DSSPL_WITH_LNAMODE_T;

typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num;  ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;        ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    unsigned short      step_cnt;     ///< due to 512 step, type of step_cnt changes to unsigned short 
    Rf_DSSPL_WITH_LNAMODE_T   PathLossDSS[MAX_STEP_EX_512P_CNT - 2];  ///< because sync process will need 2 steps
    short               lpm_sb_num;
} RF_DTS_REQ_LPM_512P_T;

typedef struct
{
    int      power[MAX_STEP_EX_512P_CNT - 2]; ///< because sync process will need 2 steps
    short    valid_sample[MAX_STEP_EX_512P_CNT - 2];
    bool     ok;
} Rf_DSSPL_RESULT_512P_T;

typedef struct
{
    RF_DTS_GET_RESULT_STATUS     status;
    Rf_DSSPL_RESULT_512P_T       PLResult;
    Rf_DSSAFC_RESULT_T           AfcResult;
    Rf_FHC_DTSM_INFO_T           DtsmInfo;
    RF_DSSLPM_RESULT_T           LpmResult;
} RF_DTS_CNF_LPM_512P_T;

typedef struct
{
    unsigned short      step_cnt;
    short               high_apc_dcoffset[FrequencyBandCount];
    Rf_USSAPC_T         ApcUSS[MAX_STEP_EX_512P_CNT];
} Rf_UTS_REQ_512P_T;

/**
 * Extension interface for Extension of test point
 **/
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Lpm_512p(unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Lpm_512p_r(const int meta_handle, unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_T* fdt_dl_req);

META_RESULT  __stdcall META_Rf_GetFdtDL_Lpm_512p(unsigned int ms_timeout, RF_DTS_CNF_LPM_512P_T* result);
META_RESULT  __stdcall META_Rf_GetFdtDL_Lpm_512p_r(const int meta_handle, unsigned int ms_timeout, RF_DTS_CNF_LPM_512P_T* result);

META_RESULT  __stdcall META_Rf_StartFdtDL_Lpm_512p(unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_T* fdt_dl_req, RF_DTS_CNF_LPM_512P_T* fdt_dl_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDL_Lpm_512p_r(const int meta_handle, unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_T* fdt_dl_req, RF_DTS_CNF_LPM_512P_T* fdt_dl_cnf);

META_RESULT  __stdcall META_Rf_StartFdtUL_512p(unsigned int ms_timeout, const Rf_UTS_REQ_512P_T*  fdt_ul_req);
META_RESULT  __stdcall META_Rf_StartFdtUL_512p_r(const int meta_handle, unsigned int ms_timeout, const Rf_UTS_REQ_512P_T*  fdt_ul_req);

META_RESULT  __stdcall META_Rf_GetFdtDL_Lpm_512p_V3(unsigned int ms_timeout, RF_DTS_CNF_LPM_512P_T* result);
META_RESULT  __stdcall META_Rf_GetFdtDL_Lpm_512p_V3_r(const int meta_handle, unsigned int ms_timeout, RF_DTS_CNF_LPM_512P_T* result);

typedef enum 
{
    GSM_LNA_NULL_V3 = 0,
    GSM_LNA_HIGH_V3,
    GSM_LNA_MID_V3,
    GSM_LNA_LOW_V3,
    GSM_LNA_W_COEF_V3,
    GSM_LNA_SAWLESS_MID_V3,
    GSM_ELNA_HIGH_SENSITIVITY_V3,
    GSM_ELNA_BYPASS_LOW_MAXPIN_V3,
    GSM_LNA_END_V3
} GSM_LNA_Cal_Type_V3;

typedef struct
{
    FrequencyBand       band;
    ARFCN               arfcn;
    Gain                gain[6];     ///< gain for rx slot 0/1/2/3/4/5
    short               repeat_cnt;  ///< repetitive test counts (frames) for each ARFCN value
    GSM_LNA_Cal_Type_V3 gsm_lna_mode;  
} Rf_DSSPL_WITH_LNAMODE_V3_T;

typedef struct
{
    bool                afc_cal;
    bool                pl_cal;       ///< Control whether Path loss calibration is needed or not
    char                sync_sb_num;  ///< the SB frame numbers needed for sync process before path loss calibration
    short               power;        ///< the power level expected to measure from test set
    Rf_DSSAFC_T         AfcDSS;
    unsigned short      step_cnt;     ///< due to 512 step, type of step_cnt changes to unsigned short 
    Rf_DSSPL_WITH_LNAMODE_V3_T   PathLossDSS[MAX_STEP_EX_512P_CNT - 2];  ///< because sync process will need 2 steps
    short               lpm_sb_num;
} RF_DTS_REQ_LPM_512P_V3_T;

META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Lpm_512p_V3(unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_V3_T* fdt_dl_req);
META_RESULT  __stdcall META_Rf_StartFdtDLNotWaitResult_Lpm_512p_V3_r(const int meta_handle, unsigned int ms_timeout, const RF_DTS_REQ_LPM_512P_V3_T* fdt_dl_req);

//-----------------------------------------------------//
//  TX Ramping Table                                   //
//-----------------------------------------------------//
#define PROFILE_NUM             16
#define ARFCN_SECTION_NUM       12
#define ARFCN_SECTION_NUM_Ex       64
typedef  struct
{
    unsigned char   point[2][16];    ///< ramp up/down profile

} sRAMPAREADATA;

typedef  struct
{
    short            max_arfcn;      ///< sub-band boundary of this PCL weighting area
    unsigned short   mid_level;      ///< PCLboundary level to apply high/low weighting
    unsigned short   hi_weight;      ///< scale factor of PCLs higher than mid_level
    unsigned short   low_weight;     ///< scale factor of PCLs lower than mid_level

} sARFCN_SECTION;

typedef  struct
{
    int              lowest_power;                       ///< The lower apc power of the indicated band
    unsigned short   power[16];                          ///< The mapping of power level to apc dac value
    sRAMPAREADATA    ramp[ PROFILE_NUM ];                ///< ramp profile
    sARFCN_SECTION   arfcn_weight[ ARFCN_SECTION_NUM ];  ///< profile of weighting power level by PCL and sub-band
    unsigned short   battery_compensate[3][3];           ///< [volt][temp]
    short            tx_afc_offset;
} sRAMPDATA;

typedef struct
{
    int              lowest_power;                       ///< The lower apc power of the indicated band
    unsigned short   power[16];                          ///< The mapping of power level to apc dac value
    sRAMPAREADATA    ramp[ PROFILE_NUM ];                ///< ramp profile
    sARFCN_SECTION   arfcn_weight[ ARFCN_SECTION_NUM_Ex ];   ///< profile of weighting power level by PCL and sub-band
    unsigned short   battery_compensate[3][3];           ///< [volt][temp]
    short            tx_afc_offset;
} sRAMPDATA_Ex;

typedef  struct
{
    int              lowest_power;                       ///< The lower apc power of the indicated band
    unsigned short   power[16];                          ///< The mapping of power level to apc dac value
    sRAMPAREADATA    ramp[ PROFILE_NUM ];                ///< ramp profile
    sARFCN_SECTION   arfcn_weight[ ARFCN_SECTION_NUM ];  ///< profile of weighting power level by PCL and sub-band
    unsigned short   battery_compensate[3][3];           ///< [volt][temp]
    short            tx_afc_offset;
    unsigned char    vbias[16];
} sRAMPDATA_Ex2;

typedef struct
{
    sRAMPDATA          rampData;                         ///< apc ramp profile of all bands
} l1cal_rampTable_T;

// useless: Ex and Ex2
typedef struct
{
    sRAMPDATA_Ex          rampData;                          ///< apc ramp profile of all bands
} l1cal_rampTable_T_Ex;

typedef struct
{
    sRAMPDATA_Ex2          rampData;                         ///< apc ramp profile of all bands
} l1cal_rampTable_T_Ex2;


//-----------------------------------------------------//
//  TX Inter Ramping Table                             //
//-----------------------------------------------------//

// interRampData
typedef struct
{
    unsigned char   interRampData[16];
} l1cal_interRampData_T;

// EPSK interRampData
typedef struct
{
    unsigned char   EPSK_interRampData[4][16];
} l1cal_EPSK_interRampData_T;
#define  CAL_UARFCN_SECTION       15
#define  U_ARFCN_SECTION_NUM      15
#define  CAL_TEMP_SECTION          8
#define  CAL_PWR_DETECTOR_SECTION 32
typedef  struct
{
    unsigned short  max_uarfcn;
    char   path_loss_H;//loss;
    char   path_loss_M;//gain_diff_HM;
    char   path_loss_L;//gain_diff_HL;
    char   path_loss_LPM_offset;
}  U_sAGCGAINOFFSET;
typedef  struct
{
    U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];
}  U_sTEMPAGCOFFSET;
typedef  struct
{
    unsigned short dc2dc_dac;
    unsigned short vbias_dac;
    unsigned char vm1;
    unsigned char vm2;
}  U_sPADATA;
typedef  struct
{
    unsigned short  max_uarfcn;
    short           pwr_offset;
    short           pwr_slope;
} U_sARFCN_SECTION;
typedef struct
{
    unsigned short max_uarfcn;
    short          pwr_offset_dB; /* unit: 1/32 dB, range: -8 ~ +7 dB */
    short          pwr_offset_txdac;
} U_sARFCN_SECTION_B; // for MT6268B later
typedef  struct
{
    U_sPADATA          pa_data;
    unsigned short     vga_dac[90];
    U_sARFCN_SECTION   vga_comp_by_subband[CAL_UARFCN_SECTION];
    short              vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
} U_sTXPOWERDATA;
typedef  struct
{
    U_sPADATA           pa_data;
    unsigned short      vga_dac[96];   // number: 96/10
    U_sARFCN_SECTION_B  vga_comp_by_subband[ CAL_UARFCN_SECTION ];
    short               vga_comp_by_temperature[8][2];  //[0]:offset in dB (unit: 1/32 dB), [1]:offset in txdac
} U_sTXPOWERDATA_B;
typedef  struct
{
    unsigned short start;
    unsigned short end;
} U_sHYSTERESISDATA;
typedef  struct
{
    unsigned char     pwr_dt_thr;
    unsigned char     pwr_dt_section;   // can not be larger than CAL_PWR_DETECTOR_SECTION
    unsigned short    pwr_dt_dac[CAL_PWR_DETECTOR_SECTION];
    short             pwr_dt_value[CAL_PWR_DETECTOR_SECTION]; //bit0~4 is used for fractions
    U_sARFCN_SECTION  pwr_dt_comp_by_subband[CAL_UARFCN_SECTION];   // for compensation, no need calibration, after test, will auto-store
    short             pwr_dt_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
}  U_sPWTDTDATA;
typedef  struct
{
    unsigned char       pwr_dt_thr;
    unsigned char       pwr_dt_section;
    unsigned short      pwr_dt_dac[ CAL_PWR_DETECTOR_SECTION ];
    short               pwr_dt_value[ CAL_PWR_DETECTOR_SECTION ]; //bit0~4 is used for fractions
    U_sARFCN_SECTION_B  pwr_dt_comp_by_subband[ CAL_UARFCN_SECTION ];
    short               pwr_dt_comp_by_temperature[8][2];  //[0]:offset in dB (unit: 1/32 dB), [1]:offset in txdac
}  U_sPWTDTDATA_B;   // for MT6268B later
typedef  struct
{
    unsigned short level_0;
    unsigned short level_1;
} U_sDC2DC;

typedef struct
{
    unsigned char level[8];
} U_sDC2DCOCTLVL;

typedef struct
{
    unsigned char   pa_mode;
    char            prf;
    unsigned char   dc2dc_lvl;
    unsigned char   vm1;
    unsigned char   vm2;
    unsigned short  vbias_dac;
    unsigned short  pa_gain;
} U_sPMULEVHANDLE;

typedef  struct
{
    /* These two control parameters belong to BB TX HW funtionality
     * and all related to PA, though PA phase compensation only has
     * three modes. PD coupler loss by PA modes stored in power_dac[]->vga_dac[9].
     */
    unsigned char     octlev_num_section;
    unsigned int      pa_phase_compensation[3]; // 0: PA high mode, 1: PA mid mode
    U_sPMULEVHANDLE   pmu_level_handle[8];
} U_sPAOCTLVLSETTING;

typedef  struct
{
    U_sDC2DC          pa_dc2dc;       // 2009,Nov add, need to check DB to compose/decompose it automatically
    U_sTXPOWERDATA    power_dac[3];   //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
    U_sHYSTERESISDATA tx_hysteresis[2];
    U_sPWTDTDATA      pwr_dt_data;
} U_sRAMPDATA;
typedef  struct
{
    U_sDC2DC              pa_dc2dc;       //need to check DB to compose/decompose it automatically
    U_sTXPOWERDATA_B      power_dac[3];   //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
    U_sHYSTERESISDATA     tx_hysteresis[2];
    U_sPWTDTDATA_B        pwr_dt_data;
} U_sRAMPDATA_B;   // for MT6268B later
typedef struct
{
    unsigned short tempdacData[8];
} ul1cal_tempdacData_T;
typedef struct
{
    U_sTEMPAGCOFFSET  pathlossData[CAL_TEMP_SECTION];
} ul1cal_pathlossData_T;
typedef struct
{
    U_sRAMPDATA txdacData;
} ul1cal_txdacData_T;
typedef struct
{
    U_sRAMPDATA_B txdacData;
} ul1cal_txdacData_T_B;  // for MT6268B or later
typedef struct
{
    U_sPAOCTLVLSETTING txPaOctLevData;
} ul1cal_txPaOctLevData_T;
typedef struct
{
    unsigned char band;
    ul1cal_txdacData_T_B txdacData;
} ul1cal_txdacData_T_B_ByBand;
META_RESULT  __stdcall META_3Grf_SetTxDacData_B(unsigned int ms_timeout, const ul1cal_txdacData_T_B_ByBand* req);
META_RESULT  __stdcall META_3Grf_SetTxDacData_B_r(const int meta_handle, unsigned int ms_timeout, const ul1cal_txdacData_T_B_ByBand* req);

typedef struct
{
    /// band indicator (in local parameter)
    unsigned char band;
    /// PA Oct level data (in peer buffer)
    ul1cal_txPaOctLevData_T txPaOctLevData;
} URfTestCmdSetTxPaOctLevData;
META_RESULT  __stdcall META_3Grf_SetTxPaOctLevData(unsigned int ms_timeout, const URfTestCmdSetTxPaOctLevData* req);
META_RESULT  __stdcall META_3Grf_SetTxPaOctLevData_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetTxPaOctLevData* req);

typedef struct
{
    /// band indicator (in local parameter)
    unsigned char           band;
    /// pa mode (in local parameter)
    unsigned char           pa_mode;
    /// tx dac data (only the power_dac is composed into peer buffer)
    ul1cal_txdacData_T_B    txdacData;
} URfTestCmdSetTxDacPowerDac;
META_RESULT  __stdcall META_3Grf_SetTxDacPowerDac(unsigned int ms_timeout, const URfTestCmdSetTxDacPowerDac* req);
META_RESULT  __stdcall META_3Grf_SetTxDacPowerDac_r(const int meta_handle, unsigned int ms_timeout, const URfTestCmdSetTxDacPowerDac* req);

typedef struct
{
    char temper_offset[CAL_TEMP_SECTION];
    U_sAGCGAINOFFSET gain_of_uarfcn[CAL_UARFCN_SECTION];
} U_sAGCOFFSETRXD;
typedef struct
{
    U_sAGCOFFSETRXD pathlossData;
} ul1cal_pathlossRxdData_T;
/**
 * for 3G URF NVRAM-Access via interface directly
 */
typedef enum
{
    NVRAM_ACCESS_FOR_RX_PATH_LOSS  = 1,
    NVRAM_ACCESS_FOR_RXD_PATH_LOSS = (1 << 1),
    NVRAM_ACCESS_FOR_TX_CAL_DATA   = (1 << 2),
    NVRAM_ACCESS_FOR_RX_CAL_DATA   = (1 << 6)
} NVRAM_ACCESS_INTERFACE_SUPPORT;

typedef enum
{
    TX_DATA_STRUCTURE_FOR_6HPM6LPM = 0x04,
    RX_DATA_STRUCTURE_FOR_6HPM6LPM = 0x40
} TRX_DATA_STRUCTURE_TYPE;

typedef enum
{
    CNF_SUCCESS  = 0, /**< URF access NVRAM successfully  */
    CNF_GENREAL_FAIL  = 1, /**< URF access NVRAM general error  */
    CNF_NVRAM_ACCESS_FAIL  = 2, /**< URF access NVRAM, NVRAM return failed */
    CNF_FREQ_INVALID  = 3 /**< Error arfcn parameter for band*/
} URF_NVRAM_ACCESS_RESULT;

typedef  struct
{
    char temper_offset[CAL_TEMP_SECTION];
    U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];
} U_sTEMPAGCOFFSETEX;
typedef struct
{
    char band;
    char rxAntPath; /**< 1 for main Rx path, 2 for diversity Rx path*/
    U_sTEMPAGCOFFSETEX pathlossDataEx;
} URfTestCmdSetRxPathLoss;
/**
   * \brief non-reentrant version of META_3Grf_SetRxPathLoss_r
 */
META_RESULT __stdcall META_3Grf_SetRxPathLoss (const unsigned int ms_timeout, const URfTestCmdSetRxPathLoss* req);
/**
 * \details Wcdma Rx/Rxd path loss NVRAM item write API
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req the pointer to a memory space which is stored the rx path loss data for
 *          writing to target NVRAM.
 * \sa URF_TEST_CMD_SET_RX_PATH_LOSS
 * \retval META_SUCCESS successful
 **/
META_RESULT __stdcall META_3Grf_SetRxPathLoss_r (const int meta_handle, const unsigned int ms_timeout, const URfTestCmdSetRxPathLoss* req);

typedef struct
{
    char band;
    char rxAntPath;
} URfTestCmdGetRxPathLoss;

typedef struct
{
    U_sTEMPAGCOFFSETEX pathlossDataEx;
} URfTestResultGetRxPathLoss;
/**
   * \brief non-reentrant version of META_3Grf_GetRxPathLoss_r
 */
META_RESULT __stdcall META_3Grf_GetRxPathLoss (const unsigned int ms_timeout, const URfTestCmdGetRxPathLoss* req, URfTestResultGetRxPathLoss* cnf );
/**
 * \details Wcdma Rx/Rxd path loss NVRAM item read API
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
  * \param req get path loss command to target
 * \param cnf the pointer to a memory space for storing the result of path loss
 *           NVRAM item acquired from target.
 * \sa URF_TEST_CMD_GET_RX_PATH_LOSS
 * \retval META_SUCCESS successful
 **/
META_RESULT __stdcall META_3Grf_GetRxPathLoss_r (const int meta_handle, const unsigned int ms_timeout, const URfTestCmdGetRxPathLoss*  req, URfTestResultGetRxPathLoss* cnf );


//-----------------------------------------------------//
//  RF Module Special Coef                             //
//-----------------------------------------------------//

//mt6140D
typedef struct
{
    short        pcl_index;
    unsigned char pa_vbias1;
} pa_vbias;

typedef struct
{
    pa_vbias GSM850_pa_vbias[8];
    pa_vbias GSM900_pa_vbias[8];
    pa_vbias DCS1800_pa_vbias[8];
    pa_vbias PCS1900_pa_vbias[8];
} mt6140tx_pa_vbias;

typedef struct
{
    mt6140tx_pa_vbias data;
} mt6140tx;
// Skyworks
typedef struct
{
    unsigned int        icorrection;
    unsigned int        qcorrection;
} RF_SKY74045_IP2_Coef;

typedef struct
{
    RF_SKY74045_IP2_Coef    coef[5/*band*/];
} RF_SKY74045_RX_Coef;

typedef struct
{
    RF_SKY74045_RX_Coef     rx;
} RF_SKY74045_Coef_T;

typedef struct
{
    unsigned int            ipol;
    unsigned int            qpol;
} RF_SKY74117_IP2_Pol;

typedef struct
{
    RF_SKY74045_IP2_Coef    coef[5/*band*/];
    RF_SKY74117_IP2_Pol     pol[5/*band*/];
} RF_SKY74117_RX_Coef;

typedef struct
{
    RF_SKY74117_RX_Coef     rx;
} RF_SKY74117_Coef_T;

// MT6139B
typedef struct
{
    unsigned int        acode;
    unsigned int        amcode;
} RF_MT6139B_IP2_Coef;

typedef struct
{
    RF_MT6139B_IP2_Coef     coef[5/*band*/];
    unsigned int            rxamcalmode;
} RF_MT6139B_RX_Coef;

typedef struct
{
    RF_MT6139B_RX_Coef      rx;
} RF_MT6139B_Coef_T;

// Bright5P
typedef struct
{
    unsigned int        word6_4_0;
    unsigned int        word6_5_0;
    unsigned int        word6_6_0;
    unsigned int        word6_7_0;
    unsigned int        bvmode;
    unsigned int        c3mode;
    unsigned int        wordC3;
} RF_BRIGHT5P_TX_Coef;

typedef struct
{
    RF_BRIGHT5P_TX_Coef     tx;
} RF_BRIGHT5P_Coef_T;


typedef struct
{
    unsigned char REFDET_SLOPE_SKEW;
    unsigned char AM_FB_DAC;
} ad6546txcoef;

typedef struct
{
    char MID_GAMA_THRESHOLD;
    char LOW_GAMA_THRESHOLD;
    char MID_DELTA_SLOPE_SKEW;
    char LOW_DELTA_SLOPE_SKEW;
    char MID_DELTA_APC_CAP;
    char LOW_DELTA_APC_CAP;
} ad6546tx_reg8_highband_delta;

typedef struct
{
    unsigned long Address           : 7;
    unsigned long POLAR_APC_CAP     : 5;
    unsigned long VGA_SLOPE         : 4;
    unsigned long REFDET_SLOPE_SKEW : 4;
    unsigned long AM_FB_DAC         : 4;
    unsigned long reserved          : 8;
} AM_LOOP;
typedef union
{
    AM_LOOP AMLoop;
    unsigned long RegData;
} ad6546tx_reg8;

typedef  struct
{
    ad6546txcoef   CalData[4];
    ad6546tx_reg8  Reg8_default[4];
} ad6546tx;

typedef struct
{
    //int rf_band;
    short afc_offset[FrequencyBandCount];

} RF_SET_AFC_DAC_OFFSET_REQ_T;

typedef struct
{
    short afc_offset[FrequencyBandCount];

} RF_GET_AFC_DAC_OFFSET_CNF_T;


//-----------------------------------------------------//
//  RF Testing: callback function definition           //
//-----------------------------------------------------//
typedef void (__stdcall* META_RF_PM_CNF)(const RfPm_Cnf* cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_AFC_CNF)(const RfAfc_Cnf* cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_NB_TX_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_CONT_RX_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_CONT_TX_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_SETBBTX_CFG_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_SELBAND_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_STOP_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_MULTISLOT_TX_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_SET_RAMPAPCLEVEL_CNF)(const unsigned char cnf, const short token, void* usrData);
typedef void (__stdcall* META_RF_SET_AFCDACVALUE_CNF)(const unsigned char cnf, const short token, void* usrData);

//-----------------------------------------------------//
//  RF Testing: exported function definition           //
//-----------------------------------------------------//
META_RESULT  __stdcall META_Rf_PM(const RfPm_Req* req, const META_RF_PM_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_PM_r(const int meta_handle, const RfPm_Req* req, const META_RF_PM_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_PmEx(unsigned int ms_timeout, const RfPm_Req* req, RfPm_Cnf* cnf);
META_RESULT  __stdcall META_Rf_PmEx_r(const int meta_handle, unsigned int ms_timeout, const RfPm_Req* req, RfPm_Cnf* cnf);
META_RESULT  __stdcall META_Rf_IfPm(unsigned int ms_timeout, const RfIfPm_Req* req, RfPm_Cnf* cnf);
META_RESULT  __stdcall META_Rf_IfPm_r(const int meta_handle, unsigned int ms_timeout, const RfIfPm_Req* req, RfPm_Cnf* cnf);
META_RESULT  __stdcall META_Rf_Sawless_Pm(const unsigned int ms_timeout, const RfPm_Req* req, RfPm_Cnf* cnf);
META_RESULT  __stdcall META_Rf_Sawless_Pm_r(const int meta_handle, const unsigned int ms_timeout, const RfPm_Req* req, RfPm_Cnf* cnf);

META_RESULT  __stdcall META_Rf_AFC(const RfAfc_Req* req, const META_RF_AFC_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_AFC_r(const int meta_handle, const RfAfc_Req* req, const META_RF_AFC_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_NB_TX(const RfNbtx_Req* req, const META_RF_NB_TX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_NB_TX_r(const int meta_handle, const RfNbtx_Req* req, const META_RF_NB_TX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_CONTINUE_RX(const RfCnRx_Req* req, const META_RF_CONT_RX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_CONTINUE_RX_r(const int meta_handle, const RfCnRx_Req* req, const META_RF_CONT_RX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_CONTINUE_TX(const RfCnTx_Req* req, const META_RF_CONT_TX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_r(const int meta_handle, const RfCnTx_Req* req, const META_RF_CONT_TX_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetBBTXCfg(const RfSetBBTXCfg_Req* req, const META_RF_SETBBTX_CFG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetBBTXCfg_r(const int meta_handle, const RfSetBBTXCfg_Req* req, const META_RF_SETBBTX_CFG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SelectFrequencyBand1900(const unsigned char selectPCS1900, const META_RF_SELBAND_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SelectFrequencyBand1900_r(const int meta_handle, const unsigned char selectPCS1900, const META_RF_SELBAND_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_Stop(const META_RF_STOP_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_Stop_r(const int meta_handle, const META_RF_STOP_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_MultiSlot_TX(const RfMultiSlotTX_Req* req, const META_RF_MULTISLOT_TX_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_r(const int meta_handle, const RfMultiSlotTX_Req* req, const META_RF_MULTISLOT_TX_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetAfcDacValue(const RfSetAfcDacValue_Req* req, const META_RF_SET_AFCDACVALUE_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetAfcDacValue_r(const int meta_handle, const RfSetAfcDacValue_Req* req, const META_RF_SET_AFCDACVALUE_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetBBTxCfg2(unsigned int ms_timeout, const RfBBTXCfg2*  tx_cfg_req, RfBBTXCfg2*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetBBTxCfg2_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg2*  tx_cfg_req, RfBBTXCfg2*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg2(unsigned int ms_timeout, RfBBTXCfg2*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg2_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg2*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetCrystalCapId(unsigned int ms_timeout, const RfSetCrystalCfg_Req*  req);
META_RESULT  __stdcall META_Rf_SetCrystalCapId_r(const int meta_handle, unsigned int ms_timeout, const RfSetCrystalCfg_Req*  req);
META_RESULT  __stdcall META_Rf_BBTXAutoCal(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_BBTXAutoCal_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_QueryMSCapability(unsigned int ms_timeout, RfMsCapability_S*  p_type);
META_RESULT  __stdcall META_Rf_QueryMSCapability_r(const int meta_handle, unsigned int ms_timeout, RfMsCapability_S*  p_type);
META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx(unsigned int ms_timeout, RfMsCapabilityEx_S*  p_ms_cap);
META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx_r(const int meta_handle, unsigned int ms_timeout, RfMsCapabilityEx_S*  p_ms_cap);
META_RESULT  __stdcall META_Rf_SetAfcSinWaveDetection(unsigned int ms_timeout, AFC_SINWAVE_DETECTION_E  bIsAfcSinWaveOn);
META_RESULT  __stdcall META_Rf_SetAfcSinWaveDetection_r(const int meta_handle, unsigned int ms_timeout, AFC_SINWAVE_DETECTION_E  bIsAfcSinWaveOn);
META_RESULT  __stdcall META_Rf_QueryIfTwoApcDCOffsetSupport(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_QueryIfTwoApcDCOffsetSupport_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex(unsigned int ms_timeout, const Rf_MultiSlotTXEx_Req* req);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex_r(const int meta_handle, unsigned int ms_timeout, const Rf_MultiSlotTXEx_Req* req);
META_RESULT  __stdcall META_Rf_GetRFID(unsigned int ms_timeout, RFMod_ID* cnf);
META_RESULT  __stdcall META_Rf_GetRFID_r(const int meta_handle, unsigned int ms_timeout, RFMod_ID* cnf);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex(unsigned int ms_timeout, const RfCnTxEx_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfCnTxEx_Req* req);
META_RESULT  __stdcall META_Rf_SetBBTxCfg3(unsigned int ms_timeout, const RfBBTXCfg3*  tx_cfg_req, RfBBTXCfg3*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetBBTxCfg3_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg3*  tx_cfg_req, RfBBTXCfg3*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg3(unsigned int ms_timeout, RfBBTXCfg3*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg3_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg3*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex2(unsigned int ms_timeout, const RfCnTxEx2_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex2_r(const int meta_handle, unsigned int ms_timeout, const RfCnTxEx2_Req* req);
META_RESULT  __stdcall META_Rf_GetAfcDacValueAtRTXOffsetCal(unsigned int ms_timeout, RfGetAfcDacValueAtRTXOffsetCal* cnf);
META_RESULT  __stdcall META_Rf_GetAfcDacValueAtRTXOffsetCal_r(const int meta_handle, unsigned int ms_timeout, RfGetAfcDacValueAtRTXOffsetCal* cnf);

META_RESULT  __stdcall META_Rf_SetBBTxCfg4(unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetBBTxCfg4_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg4(unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg4_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);


META_RESULT  __stdcall META_Rf_SetBBTxCfg5(unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetBBTxCfg5_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg5(unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg5_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);


META_RESULT  __stdcall META_Rf_SetBBTxCfg6(unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_SetBBTxCfg6_r(const int meta_handle, unsigned int ms_timeout, const RfBBTXCfg4*  tx_cfg_req, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg6(unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);
META_RESULT  __stdcall META_Rf_GetBBTxCfg6_r(const int meta_handle, unsigned int ms_timeout, RfBBTXCfg4*  tx_cfg_cnf);



//-----------------------------------------------------//
//  RunTime Setting Functions Without Update NVRAM     //
//-----------------------------------------------------//
META_RESULT  __stdcall META_Rf_SetRampTable(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_SetRampTable_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_SetRampApcLevel(const RfSetRampApcLevel_Req* req, const META_RF_SET_RAMPAPCLEVEL_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_SetRampApcLevel_r(const int meta_handle, const RfSetRampApcLevel_Req* req, const META_RF_SET_RAMPAPCLEVEL_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable_Ex(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex*  ramp);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable_Ex_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex*  ramp);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable_Ex2(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2*  ramp);
META_RESULT  __stdcall META_Rf_EPSK_SetRampTable_Ex2_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2*  ramp);

// AGC path loss
#define  PLTABLE_SIZE  13           ///< element count of path loss table

typedef struct
{
    short    max_arfcn;
    char     path_loss_H;
    char     path_loss_M;
    char     path_loss_M_Sawless;
    char     path_loss_L;   
} RfPathLossOffset;

typedef struct
{
    RfPathLossOffset    rx_pathloss[FrequencyBandCount][PLTABLE_SIZE];
} RfTestCmdSetGetRxPathLoss;

typedef struct
{
    char is_uplate_to_NVRAM;
    RfTestCmdSetGetRxPathLoss    set_rx_pathloss;
} RfTestCmdSetRxPathLoss;

/**
 * \brief non-reentrant version of META_Rf_SetRxPathLoss_r
 */
META_RESULT __stdcall  META_Rf_SetRxPathLoss(const unsigned int ms_timeout, const RfTestCmdSetRxPathLoss* req);
/**
 * \details set rx path loss by L1 command
 * \param meta_handle meta handle
 * \param ms_timeout time out (ms)
 * \param req the request structure of set rx path loss
 */
 
META_RESULT __stdcall  META_Rf_SetRxPathLoss_r(const int meta_handle, const unsigned int ms_timeout, const RfTestCmdSetRxPathLoss* req);
/**
 * \brief non-reentrant version of META_Rf_GetRxPathLoss_r
 */
META_RESULT __stdcall  META_Rf_GetRxPathLoss(const unsigned int ms_timeout, RfTestCmdSetGetRxPathLoss* cnf);
/**
 * \details get rx path loss by L1 command
 * \param meta_handle meta handle
 * \param ms_timeout time out (ms)
 * \param cnf the confirm structure of get rx path loss
 */
META_RESULT __stdcall  META_Rf_GetRxPathLoss_r(const int meta_handle, const unsigned int ms_timeout, RfTestCmdSetGetRxPathLoss* cnf);

typedef struct
{
    short    max_arfcn;
    char     path_loss_H;
    char     path_loss_M;
    char     path_loss_M_Sawless;
    char     path_loss_L;
    char     path_loss_H_sensitivity; //elna+g6
    char     path_loss_L_maxpin;       //elna_bypass+g1   ,sLNAGAINOFFSET
} RfPathLossOffsetV3;

typedef struct
{
    RfPathLossOffsetV3    rx_pathloss[FrequencyBandCount][PLTABLE_SIZE];
} RfTestCmdSetGetRxPathLossV3;

typedef struct
{
    char is_uplate_to_NVRAM;
    RfTestCmdSetGetRxPathLossV3    set_rx_pathloss;
} RfTestCmdSetRxPathLossV3;

META_RESULT __stdcall  META_Rf_SetRxPathLossV3(const unsigned int ms_timeout, const RfTestCmdSetRxPathLossV3* req);
META_RESULT __stdcall  META_Rf_SetRxPathLossV3_r(const int meta_handle, const unsigned int ms_timeout, const RfTestCmdSetRxPathLossV3* req);
META_RESULT __stdcall  META_Rf_GetRxPathLossV3(const unsigned int ms_timeout, RfTestCmdSetGetRxPathLossV3* cnf);
META_RESULT __stdcall  META_Rf_GetRxPathLossV3_r(const int meta_handle, const unsigned int ms_timeout, RfTestCmdSetGetRxPathLossV3* cnf);

typedef struct
{
    FrequencyBand eFreqBand; ///< band indicator
    char          cTxAdc_State; ///< 0: normal mode, 1: cal TXADC, 2:cal subband
    char          is_EPSK; ///< 1: EPSK, 0: GMSK
} MEAT_RF_RESET_PD_DATA_T;
/**
 * \brief non-reentrant version of META_Rf_TXPC_CL_ResetPdData_r
 */
META_RESULT  __stdcall META_Rf_TXPC_CL_ResetPdData(unsigned int ms_timeout, const MEAT_RF_RESET_PD_DATA_T* pTxPc_ResetPD);
/**
 * \details reset pd value and let L1D knowing that currently
 *              is calibrating normal mode, TXADC, or subband.
 *
 * \param meta_handle meta handle
 * \param ms_timeout time out (ms)
 * \param pTxPc_ResetPD the request structure of reset PD data
 *
 */
META_RESULT  __stdcall META_Rf_TXPC_CL_ResetPdData_r(const int meta_handle, unsigned int ms_timeout, const MEAT_RF_RESET_PD_DATA_T* pTxPc_ResetPD);

//===================================

/** \brief  the number of pa control levels */
#define  PA_OCT_16_LEVEL 16
typedef struct
{
    short          pcl_index;
    unsigned char  pa_vbias;
    unsigned short pa_gain;
} epsk_pa_vbias;

typedef struct
{
    epsk_pa_vbias GSM850_8pa_vbias[PA_OCT_16_LEVEL];
    epsk_pa_vbias GSM900_8pa_vbias[PA_OCT_16_LEVEL];
    epsk_pa_vbias DCS1800_8pa_vbias[PA_OCT_16_LEVEL];
    epsk_pa_vbias PCS1900_8pa_vbias[PA_OCT_16_LEVEL];
} EPSK_8PA_VBIAS;

typedef struct
{
    EPSK_8PA_VBIAS data;
} RF_EPSK_8PA_TX_Coef;

typedef struct
{
    RF_EPSK_8PA_TX_Coef  tx;
} RF_EPSK_8PA_SPECIAL_Coef_T;

typedef struct
{
    /// band indicator (in local parameter)
    unsigned char band;
    /// PA Oct level data (in peer buffer)
    unsigned short pa_gain[PA_OCT_16_LEVEL];
} RfEpskSetTxPaOctLevData;
META_RESULT  __stdcall META_Rf_EPSK_SetTxPaOctLevData_Ex(unsigned int ms_timeout, const RfEpskSetTxPaOctLevData*  p_pa_oct_data);
META_RESULT  __stdcall META_Rf_EPSK_SetTxPaOctLevData_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfEpskSetTxPaOctLevData*  p_pa_oct_data);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_EPSKtxPaOctLevData(const RF_EPSK_8PA_SPECIAL_Coef_T* epsk_specialCoef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_EPSKtxPaOctLevData_r(const int meta_handle, const RF_EPSK_8PA_SPECIAL_Coef_T* epsk_specialCoef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_DeCompose_EPSKtxPaOctLevData(RF_EPSK_8PA_SPECIAL_Coef_T* epsk_specialCoef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_DeCompose_EPSKtxPaOctLevData_r(const int meta_handle, RF_EPSK_8PA_SPECIAL_Coef_T* epsk_specialCoef, const char* buf, const int buf_len);
//===================================

typedef struct
{
    ARFCN           arfcn;          ///< absolute radio frequency channel number
    BSIC            bsic;            ///< training sequence
    CodingScheme    cs;     ///< coding scheme for each time slot, MCS1~9 is only valid for EPSK function
    TimingAdvance   ta;       ///< time advance
    int             frames;        ///< the number of frames should transmit
    short           dacValue;    ///< AFC DAC value
    APCTxPattern    pattern;            ///< Tx pattern is only valid for EPSK function
    unsigned short  pattern_data;   ///< if NB_TX_PATTERN_WITHOUT_TSC==pattern, user can input any 16bits value as pattern.
    unsigned short  pa_gain;           ///< pa gain from ini file
    unsigned short  pa_vbias;         ///< pa vbias from ini file
    unsigned char   rf_gain_index; ///< gain rf index
} Rf_GainRfTx_Req;
/**
 * \brief non-reentrant version of META_Rf_GainRf_TX_r
 */
META_RESULT  __stdcall META_Rf_GainRf_TX(unsigned int ms_timeout, const Rf_GainRfTx_Req* req);
/**
 * \details start EDGE TX signal indicated by gain index
 *
 * \param meta_handle meta handler
 * \param ms_timeout time out (ms)
 * \param req Rf_GainRfTx_Req
 **/
META_RESULT  __stdcall META_Rf_GainRf_TX_r(const int meta_handle, unsigned int ms_timeout, const Rf_GainRfTx_Req* req);
/**
 * \brief non-reentrant version of META_Rf_QueryNumOfGainRf_r
 */
META_RESULT  __stdcall META_Rf_QueryNumOfGainRf(unsigned int ms_timeout, unsigned char* ucNumOfGainRf);
/**
 * \details RF gain number query API
 *
 * \param meta_handle meta handler
 * \param ms_timeout time out (ms)
 * \param ucNumOfGainRf the space to store result
 **/
META_RESULT  __stdcall META_Rf_QueryNumOfGainRf_r(const int meta_handle, unsigned int ms_timeout, unsigned char* ucNumOfGainRf);
#define MAX_GAIN_RF_NUM 64
/**
 * \brief non-reentrant version of META_Rf_QueryBBPowerList_r
 */
META_RESULT  __stdcall META_Rf_QueryBBPowerList(unsigned int ms_timeout, short* sBBPowerArrary, unsigned char ucArraySize);
/**
 * \details Gain power array query function
 *
 * \param meta_handle meta handler
 * \param ms_timeout time out (ms)
 * \param sBBPowerArrary the space to store the gain power array
 * \param ucArraySize the size of the storing space
 **/
META_RESULT  __stdcall META_Rf_QueryBBPowerList_r(const int meta_handle, unsigned int ms_timeout, short* sBBPowerArrary, unsigned char ucArraySize);


META_RESULT  __stdcall META_Rf_EPSK_SetRampApcLevel(unsigned int ms_timeout, const RfSetRampApcLevel_Req* req);
META_RESULT  __stdcall META_Rf_EPSK_SetRampApcLevel_r(const int meta_handle, unsigned int ms_timeout, const RfSetRampApcLevel_Req* req);
META_RESULT  __stdcall META_Rf_SetRFImmediateBSI(unsigned int ms_timeout, const unsigned int bsi_data);
META_RESULT  __stdcall META_Rf_SetRFImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, const unsigned int bsi_data);
META_RESULT  __stdcall META_Rf_GetRFImmediateBSI(unsigned int ms_timeout, unsigned int bsi_addr, unsigned int* p_bsi_data);
META_RESULT  __stdcall META_Rf_GetRFImmediateBSI_r(const int meta_handle, unsigned int ms_timeout, unsigned int bsi_addr, unsigned int* p_bsi_data);

META_RESULT  __stdcall META_Rf_SetRampTable_Ex(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex*  ramp);
META_RESULT  __stdcall META_Rf_SetRampTable_Ex_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex*  ramp);
META_RESULT  __stdcall META_Rf_SetRampTable_Ex2(unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2*  ramp);
META_RESULT  __stdcall META_Rf_SetRampTable_Ex2_r(const int meta_handle, unsigned int ms_timeout, FrequencyBand  band, const l1cal_rampTable_T_Ex2*  ramp);
// Skyworks
META_RESULT  __stdcall META_Rf_SKY74045_SetSpecialCoef(unsigned int ms_timeout, const RF_SKY74045_Coef_T* rf_mod_coef);
META_RESULT  __stdcall META_Rf_SKY74045_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_SKY74045_Coef_T* rf_mod_coef);
META_RESULT  __stdcall META_Rf_SKY74117_SetSpecialCoef(unsigned int ms_timeout, const RF_SKY74117_Coef_T* rf_mod_coef);
META_RESULT  __stdcall META_Rf_SKY74117_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_SKY74117_Coef_T* rf_mod_coef);
// MT6139B
META_RESULT  __stdcall META_Rf_MT6139B_SetSpecialCoef(unsigned int ms_timeout, const RF_MT6139B_Coef_T* rf_mod_coef);
META_RESULT  __stdcall META_Rf_MT6139B_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_MT6139B_Coef_T* rf_mod_coef);
// Renesas Bright5P
META_RESULT  __stdcall META_Rf_BRIGHT5P_SetSpecialCoef(unsigned int ms_timeout, const RF_BRIGHT5P_Coef_T* rf_mod_coef);
META_RESULT  __stdcall META_Rf_BRIGHT5P_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const RF_BRIGHT5P_Coef_T* rf_mod_coef);

//---------------------------------------------------------------------------------------------------
META_RESULT  __stdcall META_Rf_32kCalibration(unsigned int ms_timeout, int* p_result);
META_RESULT  __stdcall META_Rf_32kCalibration_r(const int meta_handle, unsigned int ms_timeout, int* p_result);

META_RESULT  __stdcall META_Rf_AD6546_SetSpecialCoef(unsigned int ms_timeout, const ad6546tx* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_Rf_AD6546_SetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, const ad6546tx* rf_mod_coef, const char* buf, const int buf_len);

META_RESULT  __stdcall META_Rf_StartFdtDL(unsigned int ms_timeout, const Rf_DTS_REQ_T*  fdt_dl_req,  Rf_DTS_CNF_T* fdt_dl_cnf);
META_RESULT  __stdcall META_Rf_StartFdtDL_r(const int meta_handle, unsigned int ms_timeout, const Rf_DTS_REQ_T*  fdt_dl_req,  Rf_DTS_CNF_T* fdt_dl_cnf);

META_RESULT  __stdcall META_Rf_StartFdtUL(unsigned int ms_timeout, const Rf_UTS_REQ_T*  fdt_ul_req);
META_RESULT  __stdcall META_Rf_StartFdtUL_r(const int meta_handle, unsigned int ms_timeout, const Rf_UTS_REQ_T*  fdt_ul_req);


META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx2(unsigned int ms_timeout, RfMsCapabilityEx2_S*  p_ms_cap);
META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx2_r(const int meta_handle, unsigned int ms_timeout, RfMsCapabilityEx2_S*  p_ms_cap);

typedef struct
{
    unsigned int capabilityItemsSize;
    unsigned int calibrationItemsSize;
} RfMsCapabilityEx3_REQ_S;
META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx3(unsigned int ms_timeout, const RfMsCapabilityEx3_REQ_S* req, RfMsCapabilityEx3_S* ms_cap);
META_RESULT  __stdcall META_Rf_QueryMSCapabilityEx3_r(const int meta_handle, unsigned int ms_timeout, const RfMsCapabilityEx3_REQ_S* req, RfMsCapabilityEx3_S* ms_cap);

META_RESULT  __stdcall META_Rf_GetAFCDacTRxOffset(unsigned int ms_timeout, //const int rf_band_req,
        RF_GET_AFC_DAC_OFFSET_CNF_T* cnf);

META_RESULT  __stdcall META_Rf_GetAFCDacTRxOffset_r(const int meta_handle,
        unsigned int ms_timeout,
        RF_GET_AFC_DAC_OFFSET_CNF_T* cnf);

META_RESULT  __stdcall META_Rf_SetAFCDacTRxOffset(unsigned int ms_timeout, const RF_SET_AFC_DAC_OFFSET_REQ_T* req);
META_RESULT  __stdcall META_Rf_SetAFCDacTRxOffset_r(const int meta_handle,
        unsigned int ms_timeout,
        const RF_SET_AFC_DAC_OFFSET_REQ_T* req);


//--------------------------------------------------------------------------//
//  BER NSFT (Bit Error Rate in Non-signaling Final Test) : not release     //
//--------------------------------------------------------------------------//
typedef struct
{
    FrequencyBand   band;
    ARFCN           BCH_ARFCN;
    ARFCN           TCH_ARFCN;
    Gain            BCH_gain;
    Gain            TCH_gain;
    TSC             tsc;
    TimeSlot        TCH_slot;
    Power           tx_power_level;
    bool            is_EPSK_tx;
    CodingScheme    epsk_cs;
} Rf_NSFT_REQ_T;

typedef struct
{
    Power tx_power_level;
} Rf_NSFT_TX_POWERE_REQ_T;

typedef struct
{
    Power           tx_power_level;
    CodingScheme    epsk_cs;
    TimeSlot        TCH_slot;
} Rf_NSFT_EPSK_MOD_CHANGE_REQ_T;

// Start the BER NSFT process
META_RESULT  __stdcall META_Rf_NSFT_Start(unsigned int ms_timeout, const  Rf_NSFT_REQ_T* req);
META_RESULT  __stdcall META_Rf_NSFT_Start_r(const int meta_handle, unsigned int ms_timeout, const  Rf_NSFT_REQ_T* req);
// In NSFT process, change the frequency channel
META_RESULT  __stdcall META_Rf_NSFT_ChangeSettings(unsigned int ms_timeout, const  Rf_NSFT_REQ_T* req);
META_RESULT  __stdcall META_Rf_NSFT_ChangeSettings_r(const int meta_handle, unsigned int ms_timeout, const  Rf_NSFT_REQ_T* req);
// Stop the BER NSFT porcess
META_RESULT  __stdcall META_Rf_NSFT_Stop(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_NSFT_Stop_r(const int meta_handle, unsigned int ms_timeout);
// In NSFT TX performance test, change different tx power.
META_RESULT  __stdcall META_Rf_NSFT_ChangePower(unsigned int ms_timeout, const Rf_NSFT_TX_POWERE_REQ_T* req);
META_RESULT  __stdcall META_Rf_NSFT_ChangePower_r(const int meta_handle, unsigned int ms_timeout, const Rf_NSFT_TX_POWERE_REQ_T* req);
// In NSFT TX performance test, change to EPSK mode and set tx power.
META_RESULT  __stdcall META_Rf_NSFT_ChangeToEPSK(unsigned int ms_timeout, const Rf_NSFT_EPSK_MOD_CHANGE_REQ_T* req);
META_RESULT  __stdcall META_Rf_NSFT_ChangeToEPSK_r(const int meta_handle, unsigned int ms_timeout, const Rf_NSFT_EPSK_MOD_CHANGE_REQ_T* req);

//--------------------------------------------------------------------------//
//  2G List Mode NSFT                                                               //
//--------------------------------------------------------------------------//
typedef enum
{
    NSFT_LM_MCS_TYPE_GMSK = 0,
    NSFT_LM_MCS_TYPE_QPSK = 1,
    NSFT_LM_MCS_TYPE_MAX  = 0xFFFF
} NsftListModType;

typedef enum
{
    NSFT_LM_CMD_NULL    = 0,
    NSFT_LM_CMD_SYNC    = 1,
    NSFT_LM_CMD_TRIGGER = 2,
    NSFT_LM_CMD_CHMEAS  = 3,
    NSFT_LM_CMD_STOP    = 4,
    NSFT_LM_CMD_END     = 0xFF
} NsftListCmdType;

typedef enum
{
    NSFT_LM_EXECUTION_NULL    = 0,
    NSFT_LM_EXECUTION_INIT    = 1,
    NSFT_LM_EXECUTION_START   = 2,
    NSFT_LM_EXECUTION_DONE    = 3,
    NSFT_LM_EXECUTION_FAIL    = 4,
    NSFT_LM_EXECUTION_STA_MAX = 0xFFFF
} NsftListCmdStatus;

typedef struct
{
    unsigned char cmd_type;
} Rf_LIST_MODE_NSFT_COMMON_REQ;

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_REQ common;
    unsigned char              rf_band;
    unsigned short             sync_arfcn;
    short                     sync_power;
    unsigned char              sync_slot_offset;
} Rf_LIST_MODE_NSFT_SYNC_REQ;

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_REQ common;
    unsigned char              rf_band;
    unsigned short             arfcn;
    unsigned char              tsc;
    unsigned char              rtx_types;
    short                     tx_pcl;
} Rf_LIST_MODE_NSFT_TRIGGER_REQ;

#define RF_MAX_LIST_MODE_TX_MEAS_COUNT 8

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_REQ common;
    unsigned char              rf_band;
    unsigned short             arfcn;
    unsigned char              tsc;
    unsigned char              rtx_types;
    char                      tx_pcl[RF_MAX_LIST_MODE_TX_MEAS_COUNT];
    short                     rx_power;
    char                      repeat_count[RF_MAX_LIST_MODE_TX_MEAS_COUNT];
} Rf_LIST_MODE_NSFT_CHMEAS_REQ;

typedef union
{
    Rf_LIST_MODE_NSFT_SYNC_REQ    sync;
    Rf_LIST_MODE_NSFT_TRIGGER_REQ trigger;
    Rf_LIST_MODE_NSFT_CHMEAS_REQ  test;
} Rf_LIST_MODE_NSFT_COMMAND_T;

#define RF_MAX_LIST_MODE_SYNC_COUNT 5
#define RF_MAX_LIST_MODE_TRIGGER_COUNT 5
#define RF_MAX_LIST_MODE_CH_COUNT 50
#define RF_MAX_LIST_MODE_COMMAND_COUNT (RF_MAX_LIST_MODE_CH_COUNT + RF_MAX_LIST_MODE_SYNC_COUNT + RF_MAX_LIST_MODE_TRIGGER_COUNT)

typedef struct
{
    unsigned char               ucCmdCount;
    Rf_LIST_MODE_NSFT_COMMAND_T   command[RF_MAX_LIST_MODE_COMMAND_COUNT];
} Rf_LIST_MODE_NSFT_REQ_T;

typedef struct
{
    unsigned char         cmd_type;
    unsigned short        status;
} Rf_LIST_MODE_NSFT_COMMON_CNF;

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_CNF   common;
    unsigned short               retry_count;
    short                       afc_dac;
    int                         detected_foe;
} Rf_LIST_MODE_NSFT_SYNC_CNF;

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_CNF common;
} Rf_LIST_MODE_NSFT_TRIGGER_CNF;

typedef struct
{
    Rf_LIST_MODE_NSFT_COMMON_CNF common;
    unsigned short             rx_level;
    unsigned int               BER_sum;
    unsigned int               BER_frame_count;
} Rf_LIST_MODE_NSFT_CHMEAS_CNF;

typedef union
{
    Rf_LIST_MODE_NSFT_SYNC_CNF    sync;
    Rf_LIST_MODE_NSFT_TRIGGER_CNF trigger;
    Rf_LIST_MODE_NSFT_CHMEAS_CNF  test;
} Rf_LIST_MODE_NSFT_RPT_T;
typedef struct
{
    unsigned char               ucCnfCount;
    Rf_LIST_MODE_NSFT_RPT_T      report[RF_MAX_LIST_MODE_COMMAND_COUNT];
} Rf_LIST_MODE_NSFT_RPT_CNF_T;

// Start the LIst Mode NSFT process
META_RESULT  __stdcall META_Rf_List_Mode_NSFT_Start(unsigned int ms_timeout, const  Rf_LIST_MODE_NSFT_REQ_T* req, Rf_LIST_MODE_NSFT_RPT_CNF_T* cnf);
META_RESULT  __stdcall META_Rf_List_Mode_NSFT_Start_r(const int meta_handle, unsigned int ms_timeout, const  Rf_LIST_MODE_NSFT_REQ_T* req, Rf_LIST_MODE_NSFT_RPT_CNF_T* cnf);

// query OE PATTERN ready (NO OP function, just for query)
META_RESULT  __stdcall META_Rf_OE_Pattern_Ready();
META_RESULT  __stdcall META_Rf_AFC_Type_Query_Ready();


META_RESULT  __stdcall META_Rf_PowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_PowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_PowerOff(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_PowerOff_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_QueryPowerState(unsigned int ms_timeout, char* pRfPwrState);
META_RESULT  __stdcall META_Rf_QueryPowerState_r(const int meta_handle, unsigned int ms_timeout,  char* pRfPwrState);

typedef struct
{
    char rollback_2t;
    char rollback_3t;
    char rollback_4t;
    char rollback_5t;
} sTX_POWERROLLBACK;

typedef struct
{
    int band;
    sTX_POWERROLLBACK PowerRollbackTable;
} Rf_TX_ROLLBACK_REQ_T;

typedef struct
{
    sTX_POWERROLLBACK   rollback_data[FrequencyBandCount];
} l1cal_tx_power_rollback_T;

META_RESULT  __stdcall META_Rf_SetTXPowerRollbackGMSK(unsigned int ms_timeout, Rf_TX_ROLLBACK_REQ_T* req);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackGMSK_r(const int meta_handle, unsigned int ms_timeout,  Rf_TX_ROLLBACK_REQ_T* req);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackEPSK(unsigned int ms_timeout, Rf_TX_ROLLBACK_REQ_T* req);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackEPSK_r(const int meta_handle, unsigned int ms_timeout,  Rf_TX_ROLLBACK_REQ_T* req);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackTableGMSK(unsigned int ms_timeout, const l1cal_tx_power_rollback_T*  table);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackTableGMSK_r(const int meta_handle, unsigned int ms_timeout, const l1cal_tx_power_rollback_T*  table);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackTableEPSK(unsigned int ms_timeout, const l1cal_tx_power_rollback_T*  table);
META_RESULT  __stdcall META_Rf_SetTXPowerRollbackTableEPSK_r(const int meta_handle, unsigned int ms_timeout, const l1cal_tx_power_rollback_T*  table);

typedef struct
{
    unsigned short data[16];
} sTXPC_ADCDATA;

typedef struct
{
    unsigned short data[8];
} sTXPC_TEMPDATA;

typedef struct
{
    char           is_calibrated;
    sTXPC_ADCDATA  adc[FrequencyBandCount];
    short          temperature;
    sTXPC_TEMPDATA temp[FrequencyBandCount];
} sTXPC_L1CAL;

typedef sTXPC_L1CAL l1cal_txpc_T;

typedef struct
{
    unsigned char  band;
    short pcl;
} Rf_GET_TXPC_PD_REQ_T;


META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueByPCLGMSK(unsigned int ms_timeout, const Rf_GET_TXPC_PD_REQ_T* req, unsigned short* PDValue);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueByPCLGMSK_r(const int meta_handle, unsigned int ms_timeout, const Rf_GET_TXPC_PD_REQ_T* req, unsigned short* PDValue);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueByPCLEPSK(unsigned int ms_timeout, const Rf_GET_TXPC_PD_REQ_T* req, unsigned short* PDValue);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueByPCLEPSK_r(const int meta_handle, unsigned int ms_timeout, const Rf_GET_TXPC_PD_REQ_T* req, unsigned short* PDValue);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueGMSK(unsigned int ms_timeout, l1cal_txpc_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueGMSK_r(const int meta_handle, unsigned int ms_timeout, l1cal_txpc_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueEPSK(unsigned int ms_timeout, l1cal_txpc_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCDetectorValueEPSK_r(const int meta_handle, unsigned int ms_timeout, l1cal_txpc_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationGMSK(unsigned int ms_timeout, const unsigned char band, l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationGMSK_r(const int meta_handle, unsigned int ms_timeout, const unsigned char band, l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationEPSK(unsigned int ms_timeout, const unsigned char band, l1cal_rampTable_T*  ramp);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationEPSK_r(const int meta_handle, unsigned int ms_timeout, const unsigned char band, l1cal_rampTable_T*  ramp);
typedef struct
{
    short data[11];
} txpc_subband_comp_T;

META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationGMSKEx(unsigned int ms_timeout, const unsigned char band, txpc_subband_comp_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationGMSKEx_r(const int meta_handle, unsigned int ms_timeout, const unsigned char band, txpc_subband_comp_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationEPSKEx(unsigned int ms_timeout, const unsigned char band, txpc_subband_comp_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCSubbandCompensationEPSKEx_r(const int meta_handle, unsigned int ms_timeout, const unsigned char band, txpc_subband_comp_T* table);
META_RESULT  __stdcall META_Rf_GetTXPCTemperature(unsigned int ms_timeout, unsigned short* temperature);
META_RESULT  __stdcall META_Rf_GetTXPCTemperature_r(const int meta_handle, unsigned int ms_timeout, unsigned short* temperature);
typedef struct
{
    short w_re[19];
    short w_im[19];
} RF_AvgW_Coef_T;

META_RESULT  __stdcall META_Rf_GetSpecialCoef(unsigned int ms_timeout, unsigned int rfid, void* coef_struct);
META_RESULT  __stdcall META_Rf_GetSpecialCoef_r(const int meta_handle, unsigned int ms_timeout, unsigned int rfid, void* coef_struct);

META_RESULT  __stdcall META_Rf_NSFT_ConfigSBER(unsigned int ms_timeout, const unsigned int test_frame_count);
META_RESULT  __stdcall META_Rf_NSFT_ConfigSBER_r(const int meta_handle, unsigned int ms_timeout, const unsigned int test_frame_count);
typedef struct
{
    unsigned int m_u4NSFTSBERSum;
    unsigned int m_u4NSFTSBERCurrentCount;
} RF_NSFT_SBERResult_T;

META_RESULT  __stdcall META_Rf_NSFT_GetSBER(unsigned int ms_timeout, RF_NSFT_SBERResult_T* sber_result);
META_RESULT  __stdcall META_Rf_NSFT_GetSBER_r(const int meta_handle, unsigned int ms_timeout, RF_NSFT_SBERResult_T* sber_result);
META_RESULT  __stdcall META_Rf_NSFT_StartRxLevel(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_NSFT_StartRxLevel_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_NSFT_GetRxLevel(unsigned int ms_timeout, unsigned short* rx_level);
META_RESULT  __stdcall META_Rf_NSFT_GetRxLevel_r(const int meta_handle, unsigned int ms_timeout, unsigned short* rx_level);
META_RESULT  __stdcall META_Rf_NSFT_GetRxQual(unsigned int ms_timeout, const unsigned short ber_decile, unsigned char* rx_qual);
META_RESULT  __stdcall META_Rf_NSFT_GetRxQual_r(const int meta_handle, unsigned int ms_timeout, const unsigned short ber_decile, unsigned char* rx_qual);

META_RESULT  __stdcall META_Rf_AFC_Ex(unsigned int ms_timeout, const RfAfc_Req* req, RfAfc_Cnf* cnf);
META_RESULT  __stdcall META_Rf_AFC_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfAfc_Req* req, RfAfc_Cnf* cnf);
META_RESULT  __stdcall META_Rf_NB_TX_Ex(unsigned int ms_timeout, const RfNbtx_Req* req);
META_RESULT  __stdcall META_Rf_NB_TX_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfNbtx_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_RX_Ex(unsigned int ms_timeout, const RfCnRx_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_RX_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfCnRx_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex1(unsigned int ms_timeout, const RfCnTx_Req* req);
META_RESULT  __stdcall META_Rf_CONTINUE_TX_Ex1_r(const int meta_handle, unsigned int ms_timeout, const RfCnTx_Req* req);
META_RESULT  __stdcall META_Rf_SetBBTXCfg_Ex(unsigned int ms_timeout, const RfSetBBTXCfg_Req* req);
META_RESULT  __stdcall META_Rf_SetBBTXCfg_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfSetBBTXCfg_Req* req);
META_RESULT  __stdcall META_Rf_SelectFrequencyBand1900_Ex(unsigned int ms_timeout, unsigned char selectPCS1900);
META_RESULT  __stdcall META_Rf_SelectFrequencyBand1900_Ex_r(const int meta_handle, unsigned int ms_timeout, unsigned char selectPCS1900);
META_RESULT  __stdcall META_Rf_Stop_Ex(unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_Stop_Ex_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex1(unsigned int ms_timeout, const RfMultiSlotTX_Req* req);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex1_r(const int meta_handle, unsigned int ms_timeout, const RfMultiSlotTX_Req* req);
META_RESULT  __stdcall META_Rf_SetAfcDacValue_Ex(unsigned int ms_timeout, const RfSetAfcDacValue_Req* req);
META_RESULT  __stdcall META_Rf_SetAfcDacValue_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfSetAfcDacValue_Req* req);
META_RESULT  __stdcall META_Rf_SetRampApcLevel_Ex(unsigned int ms_timeout, const RfSetRampApcLevel_Req* req);
META_RESULT  __stdcall META_Rf_SetRampApcLevel_Ex_r(const int meta_handle, unsigned int ms_timeout, const RfSetRampApcLevel_Req* req);
META_RESULT  __stdcall META_Rf_SetDcxoPowerMode(unsigned int ms_timeout, unsigned char mode);
META_RESULT  __stdcall META_Rf_SetDcxoPowerMode_r(const int meta_handle, unsigned int ms_timeout, unsigned char mode);

/********************************
 * CO TSX
 ********************************/
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex_AuxADCRead(unsigned int ms_timeout, const RfMultiSlotTX_Req* req, unsigned short* piTemp);
META_RESULT  __stdcall META_Rf_MultiSlot_TX_Ex_AuxADCRead_r(const int meta_handle, unsigned int ms_timeout, const RfMultiSlotTX_Req* req, unsigned short* piTemp);

META_RESULT __stdcall META_Rf_GetTemperatureInfo(const unsigned int ms_timeout, META_Rf_TemperatureInfo_T* info);
META_RESULT __stdcall META_Rf_GetTemperatureInfo_r(const int meta_handle, const unsigned int ms_timeout, META_Rf_TemperatureInfo_T* info);

/**
 * \brief non-reentrant version of META_Rf_SetDtPathFlag_r
 */
META_RESULT __stdcall META_Rf_SetDtPathFlag(const unsigned int ms_timeout, unsigned char path_flag);
/**
 * \details Set GSM path to other path
 *          the path will be restored to default path (first path) after RF stop
 * \param meta_handle meta handle
 * \param ms_timeout time out (ms)
 * \param path_flag 0: first path 1: second path
 */
META_RESULT __stdcall META_Rf_SetDtPathFlag_r(const int meta_handle, const unsigned int ms_timeout, unsigned char path_flag);
/**
 * \details get the RF chip ID name by given RF chip ID
 * \param id RF chip ID
 * \return constant pointer to the RF chip ID name
 */
const char* __stdcall META_Rf_GetRfChipIdName(unsigned int id);
const char* __stdcall META_Rf_GetRfChipIdName_r(const int meta_handle, unsigned int id);
/**
 * @}
 */
#if defined(__META_LTE__)
//--------------------------------------------------------------------------//
//  LTE RF                                                                  //
//--------------------------------------------------------------------------//
/**
 * \addtogroup LTE
 * @{
 */

/********************* MT6291 Constant Definitions *********************/

#define MAX_FHC_RX_FREQ_NUM_EX       15
#define MAX_FHC_TX_FREQ_NUM_EX       15

#define MAX_RX_CC_NUM                2  // for gain-by-gin PCC & SCC results

#define MAX_ROUTE_NUM                128
#define MAX_ROUTE_NUM_IN_WORD        (((MAX_ROUTE_NUM-1)>>5)+1)

#define MAX_TEMP_SECTION_NUM         8
#define MAX_RX_LNA_N_MODE_NUM        6  //for LNA normal mode
#define MAX_RX_LNA_L_MODE_NUM        1  //for LNA low power mode
#define MAX_RX_LNA_MODE_NUM         (MAX_RX_LNA_N_MODE_NUM+MAX_RX_LNA_L_MODE_NUM)

#define MAX_TX_PA_MODE_NUM           3
#define MAX_TX_DET_MODE_NUM          MAX_TX_PA_MODE_NUM
#define MAX_TX_PA_LEVEL_NUM          8
#define MAX_TX_RPT_NUM              (MAX_TX_DET_MODE_NUM+MAX_TX_PA_LEVEL_NUM)


#define MAX_FHC_RX_TYPE1_ROUTE_NUM   48 //single band + inter-CA + PCC/SCC exchange
#define MAX_FHC_RX_TYPE2_ROUTE_NUM   8  //intra-NCCA
#define MAX_FHC_TX_TYPE1_ROUTE_NUM   21

#define MAX_SCENARIO_BY_BAND_NUM     15 // SCENARIO means CA category

//META self-defined
#define INVALID_CA_COMB_TABLE_INDEX  255
#define MAX_SRX_LNA_SETTING_NUM   3
#define MAX_CA_USAGE_NUM   256
#define MAX_CA_COMBINE_NUM   256

/********************* MT6291 Constant Definitions *********************/
#define ERF_MAX_BAND_NUM 21

#define MAX_LTE_BAND (44)
typedef struct
{
    unsigned char band;
#define ERF_TX_TEST_COMMAND_CONFIG_TDD 0
#define ERF_TX_TEST_COMMAND_CONFIG_FDD 1
    unsigned char duplexMode; /**< tdd,fdd */
    unsigned char tddConfig;
    unsigned char tddSfConfig;
    unsigned short ulFrequency;
    unsigned short cellId;
    short afcdac;
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_6RB 0
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_15RB 1
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_25RB 2
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_50RB 3
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_75RB 4
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_100RB 5
    unsigned char ulBandwidth; /**< 6,15,25,50,75,100RB */
    unsigned char vrbStart;
    unsigned char vrbLength;
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_QPSK 0
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_16QAM 1
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_64QAM 2
    unsigned char mcsMode;
    short txPower;
    unsigned char networkSelection; /**< 0~31 */
    unsigned char txPowerMode;
    unsigned char disableCloseLoop;
    unsigned char enableAmpr;
    short bbBackoff;
    unsigned char rfGain;
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_HIGH 0
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_MIDDLE 1
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_LOW 2
    unsigned char paMode;
    unsigned char paVcc;
    unsigned char vm0;
    unsigned char vm1;
    unsigned char enableCsr; //0: Don¡¦t enable CSR, 1: Enable Csr
    unsigned short dlFrequency;
} ERfTestCmdPuschTx;

META_RESULT __stdcall META_ERf_TxPusch( const ERfTestCmdPuschTx* req, const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_TxPusch_r( const int meta_handle, const  ERfTestCmdPuschTx* req, const unsigned int ms_timeout );

META_RESULT __stdcall META_ERf_StartTraditionalTxNSFT( const ERfTestCmdPuschTx* req, const unsigned int ms_timeout, unsigned int* pSyncStatus );
META_RESULT __stdcall META_ERf_StartTraditionalTxNSFT_r( const int meta_handle, const  ERfTestCmdPuschTx* req, const unsigned int ms_timeout, unsigned int* pSyncStatus );

typedef struct
{
    unsigned char band;
    unsigned char duplexMode /**< tdd,fdd */;
    unsigned char tddConfig;
    unsigned char tddSfConfig;
    unsigned short ulFrequency;
    unsigned short cellId;
    short afcdac;
    unsigned char ulBandwidth; /**< 6,15,25,50,75,100RB */
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1 0
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1A 1
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1B 2
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2 3
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2_CPACK 4
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2A 5
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2B 6
    unsigned char format; /**< 1,1a,1b,2,2_cpack,2a,2b */
    short txPower;
    unsigned char networkSelection; /**< 0~31 */
    unsigned char disableCloseLoop;
    unsigned char enableAmpr;
} ERfTestCmdPucchTx;
META_RESULT __stdcall META_ERf_TxPucch( const ERfTestCmdPucchTx* req, const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_TxPucch_r( const int meta_handle, const  ERfTestCmdPucchTx* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char band;
    unsigned short ulFrequency;
    unsigned short cellId;
    short afcdac;
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_FDD_TIME_MASK 0
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_TDD_TIME_MASK 1
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_FDD_EVM 2
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_TDD_EVM 3
    unsigned char configIndex; /**< fdd time mask,tdd time mask,fdd evm,tdd evm*/
    short txPower;
    unsigned char networkSelection; /**< 0~31 */
    unsigned char disableCloseLoop;
    unsigned char enableAmpr;
} ERfTestCmdPrachTx;
META_RESULT __stdcall META_ERf_TxPrach( const ERfTestCmdPrachTx* req, const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_TxPrach_r( const int meta_handle, const  ERfTestCmdPrachTx* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char band;
    unsigned char duplexMode /**< tdd,fdd */;
    unsigned short ulFrequency;
    unsigned short cellId;
    short afcdac;
#define ERF_TX_TEST_COMMAND_CONFIG_SRS_BANDWIDTH_CONFIG_0 0
#define ERF_TX_TEST_COMMAND_CONFIG_SRS_BANDWIDTH_CONFIG_2 2
#define ERF_TX_TEST_COMMAND_CONFIG_SRS_BANDWIDTH_CONFIG_5 5
#define ERF_TX_TEST_COMMAND_CONFIG_SRS_BANDWIDTH_CONFIG_7 7
    unsigned char tddCsSrsBwCfg;
    short txPower;
    unsigned char networkSelection; /**< 0~31 */
    unsigned char disableCloseLoop;
    unsigned char enableAmpr;
} ERfTestCmdSrsTx;
META_RESULT __stdcall META_ERf_TxSrs( const ERfTestCmdSrsTx* req, const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_TxSrs_r( const int meta_handle, const  ERfTestCmdSrsTx* req, const unsigned int ms_timeout );

typedef struct
{
#define MAX_ERF_TEST_MIXRX_DLRX_MODE (0)
#define MAX_ERF_TEST_MIXRX_TXRX_MODE (1)
#define MAX_ERF_TEST_MIXRX_PSEUDO_TXRX_MODE (2)
    unsigned char mode;
#define MAX_ERF_TEST_MIXRX_REPORT_COUNT 10
    unsigned char measCnt;
    unsigned char measBandwidth; /**< Refer to Tx ulBandwidth - 6,15,25,50,75,100RB */
    short afcdac;
    unsigned short dlFrequency;
    unsigned char band;
    unsigned char duplexMode; /**< Refer to Tx duplexMode - tdd,fdd */
    unsigned char tddConfig;
    unsigned char tddSfConfig;
    unsigned char bandwidth; /**< Refer to Tx ulBandwidth - 6,15,25,50,75,100RB */
    unsigned char rxPath0Enbl;
    unsigned char rxPath1Enbl;
    unsigned short ulFrequency;
    short txPowerValue;
    unsigned char vrbStart;
    unsigned char vrbLength;
    unsigned char mcsMode; /**< Refer to Tx mcsMode */
} ERfTestCmdMixRx;
META_RESULT __stdcall META_ERf_StartMixRx( const unsigned int ms_timeout, ERfTestCmdMixRx* req );
META_RESULT __stdcall META_ERf_StartMixRx_r( const int meta_handle, ERfTestCmdMixRx* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char measRptCnt; //0 ~ MAX_ERF_TEST_MIXRX_REPORT_COUNT
    short rssiPath0[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    short rssiPath1[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    short rsrpPath0[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    short rsrpPath1[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    short rsrqPath0[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    short rsrqPath1[MAX_ERF_TEST_MIXRX_REPORT_COUNT];
    unsigned int crcOK_cnt;
    unsigned int crcNG_cnt;
} ERfTestCmdGetMixRxRpt;
META_RESULT __stdcall META_ERf_GetMixRxReport( const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt* resp );
META_RESULT __stdcall META_ERf_GetMixRxReport_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt* resp );

typedef struct
{
    unsigned char mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx

    /*Common parameters*/
    unsigned char measCnt[MAX_RX_CC_NUM];//range 0~10
    unsigned char measBandwidth[MAX_RX_CC_NUM];//0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
    short         afcdac;
    unsigned short dlFrequency[MAX_RX_CC_NUM];//range: 7280~26900 (100KHz unit)
    unsigned char band[MAX_RX_CC_NUM];
    unsigned char duplexMode;//0:tdd, 1:fdd
    unsigned char tddConfig[MAX_RX_CC_NUM];//range 0~7
    unsigned char tddSfConfig[MAX_RX_CC_NUM];//range 0~8
    unsigned char bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
    unsigned char rxPath0Enbl;
    unsigned char rxPath1Enbl;

    /*Tx-Rx & Pseudo Tx-Rx only*/
    unsigned short ulFrequency;//range: 7280~26900 (100KHz unit)
    short         txPowerValue;/*S(8,8)*/

    /*Pseudo Tx-Rx only*/
    unsigned char vrbStart;
    unsigned char vrbLength;
    unsigned char mcsMode;
} ERfTestCmdMixRx_CaMode;
META_RESULT __stdcall META_ERf_StartMixRx_CaMode( const unsigned int ms_timeout, ERfTestCmdMixRx_CaMode* req );
META_RESULT __stdcall META_ERf_StartMixRx_CaMode_r( const int meta_handle, ERfTestCmdMixRx_CaMode* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char measRptCnt[MAX_RX_CC_NUM];//range 0~10
    short rssiPath0[MAX_RX_CC_NUM][10];//final format is TBD
    short rssiPath1[MAX_RX_CC_NUM][10];//final format is TBD
    short rsrpPath0[MAX_RX_CC_NUM][10];//final format is TBD
    short rsrpPath1[MAX_RX_CC_NUM][10];//final format is TBD
    short rsrqPath0[MAX_RX_CC_NUM][10];//final format is TBD
    short rsrqPath1[MAX_RX_CC_NUM][10];//final format is TBD

    unsigned int crcOK_cnt[MAX_RX_CC_NUM];
    unsigned int crcNG_cnt[MAX_RX_CC_NUM];
} ERfTestCmdGetMixRxRpt_CaMode;

META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode( const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode* resp );
META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode* resp );

META_RESULT __stdcall META_ERf_ResetCounter( const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_ResetCounter_r( const int meta_handle, const unsigned int ms_timeout );

META_RESULT __stdcall META_ERf_StopTestMode( const unsigned int ms_timeout );
META_RESULT __stdcall META_ERf_StopTestMode_r( const int meta_handle, const unsigned int ms_timeout );

typedef struct
{
    //PA Control
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE 8
    unsigned char paControlLevel; /* 2~8 */
    unsigned char calRoomTempIdx;
    short hysteresisStart0;
    short hysteresisEnd0;
    short hysteresisStart1;
    short hysteresisEnd1;
    unsigned char paMode[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    short pRf[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned short paGain[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char dc2dcLevel[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned short vBiasDac[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char vm0[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char vm1[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    //Tx Compensation
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE 8
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE 21
    unsigned short ulFrequency[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainHigh[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainMiddle[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainLow[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short couplerLossHigh;
    short couplerLossMiddle;
    short couplerLossLow;
    short powerDetectorHigh[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short powerDetectorMiddle[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short powerDetectorLow[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
} ERfTestCmdGetSetTpcSetting;

META_RESULT  __stdcall META_ERf_GetTpcSetting( unsigned char band,  const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_GetTpcSetting_r( const int meta_handle, unsigned char band, const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_SetTpcSetting( unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );
META_RESULT  __stdcall META_ERf_SetTpcSetting_r( const int meta_handle, unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );

// WARNNING: backward compatible(BC) function, these will be removed after MP
typedef struct
{
    //PA Control
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE 8
    unsigned char paControlLevel; /* 2~8 */
    short hysteresisStart0;
    short hysteresisEnd0;
    short hysteresisStart1;
    short hysteresisEnd1;
    unsigned char paMode[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    short pRf[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned short paGain[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char dc2dcLevel[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned short vBiasDac[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char vm0[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    unsigned char vm1[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE];
    //Tx Compensation
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE 8
#define MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE 21
    unsigned short earfcn[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainHigh[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainMiddle[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short paGainLow[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_TEMPERATURE_SIZE][MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short couplerLossHigh;
    short couplerLossMiddle;
    short couplerLossLow;
    short powerDetectorHigh[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short powerDetectorMiddle[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
    short powerDetectorLow[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_SUBBAND_SIZE];
} ERfTestCmdGetSetTpcSetting_Bc;

META_RESULT  __stdcall META_ERf_GetTpcSetting_Bc( unsigned char band,  const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_GetTpcSetting_Bc_r( const int meta_handle, unsigned char band, const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_SetTpcSetting_Bc( unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );
META_RESULT  __stdcall META_ERf_SetTpcSetting_Bc_r( const int meta_handle, unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned int is_capable: 1;
    unsigned int is_mandatory: 1;
    unsigned int fdd_to_tdd_switch_time: 3;
    unsigned int fdd_tx_to_rx_switch_time: 3;
    unsigned int tdd_tx_to_rx_switch_time: 3;
    unsigned int freq_switch_time: 3;
    unsigned int band_switch_time: 3;
    unsigned int tx_step_width: 3;
    unsigned int reserve: 12;
} ERfCalItemSwitchTime;

typedef struct
{
    unsigned int capabilityItemsSize;
    unsigned int calibrationItemsSize;
} ERfTestCmdRfCapabilityReq;

typedef struct
{
    unsigned int  supportBandMap[2];            ///< supportBandMap[0]           :Band01(LSB)~Band32(MSB);supportBandMap[1]            :Band33(LSB)~Band64(MSB)
    unsigned int  supportMipiBandMap[2];        ///< supportMipiBandMap[0]       :Band01(LSB)~Band32(MSB);supportMipiBandMap[1]        :Band33(LSB)~Band64(MSB)
    unsigned int  supportCoexistenceBandMap[2]; ///< supportCoexistenceBandMap[0]:Band01(LSB)~Band32(MSB);supportCoexistenceBandMap[1] :Band33(LSB)~Band64(MSB)
    unsigned int  supportDpdBandMap[2];         ///< supportDpdBandMap[0]        :Band01(LSB)~Band32(MSB);supportDpdBandMap[1]         :Band33(LSB)~Band64(MSB)
    unsigned int  supportCim3BandMap[2];        ///< supportCim3BandMap[0]       :Band01(LSB)~Band32(MSB);supportCim3BandMap[1]        :Band33(LSB)~Band64(MSB)
    unsigned int  supportHRMBandMap[2];         ///< supportHRMBandMap[0]        :Band01(LSB)~Band32(MSB);supportHRMBandMap[1]         :Band33(LSB)~Band64(MSB)
    unsigned int  supportNCCAOneElnaBandMap[2]; ///< supportNCCAOneElnaBandMap[0]:Band01(LSB)~Band32(MSB);supportNCCAOneElnaBandMap[1] :Band33(LSB)~Band64(MSB) 
} ErfCapabilityItemSet;

typedef struct
{
    unsigned int is_capable: 1;
    unsigned int is_mandatory: 1;
    unsigned int parameter: 30;
} ErfCalibrationItem;

typedef struct
{
    ErfCalibrationItem tadc_cal;                     /**< [0] TADC calibration capability.                 ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem multi_rat_tadc_bitmap;        /**< [1] Bit map of multi-rat TADC calibration;       ;is_capable (0: not supported, 1: supported) parameter (0|0|C|Lf|Lt|T|W|G) */
    ErfCalibrationItem multi_rat_afc_bitmap;         /**< [2] Bit map of multi-rat AFC calibration;        ;is_capable (0: not supported, 1: supported) parameter (0|0|C|Lf|Lt|T|W|G) */
    ErfCalibrationItem pd_temp_comp;                 /**< [3] Target support PD temperature compensation.  ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem mipi_pa_level_and_cw_num;     /**< [4] MIPI PA power level and codeword number.     ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem temperature_info;             /**< [5] Target support temperature info.             ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem et_module_support;            /**< [6] support ET modulator.                        ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem tool_usage_setting_support;   /**< [7] Support set tool usage or not.               ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem thermal_sensor_type;          /**< [8] Target support temp sensor type.             ;is_capable (0: not supported, 1: supported) parameter (0: internal, 1: external) */
    ErfCalibrationItem cap_id_calibration;           /**< [9] Target support CAP ID calibration.           ;is_capable (0: not supported, 1: supported) parameter (MAX CAP ID) */
    ErfCalibrationItem enable_csr;                   /**< [10] Target support carrier search.              ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem gps_co_tms_support;           /**< [11] Target support GPS CO-TMS.                  ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_ca_support;               /**< [12] Target support CA mode.                     ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_ca_ena;                   /**< [13] Target enable CA mode.                      ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_dpd_support;              /**< [14] DPD calibration item.                       ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_cim3_support;             /**< [15] CIM3 calibration item.                      ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_coexistence_support;      /**< [16] Coexistence calibration item.               ;is_capable (0: not supported, 1: supported) */
    ErfCalibrationItem lte_hrm_support;              /**< [17] HRM calibration item.                       ;is_capable (0: not supported, 1: supported) */ 
    ErfCalibrationItem fhc_sw_time;                  /**< [18] FHC dut's minimum switch time               ;is_capable (0: not supported, 1: supported) */ 
    ErfCalibrationItem nsft_extension;               /**< [19] NSFT extension.                             ;is_capable (0: not supported, 1: supported) parameter (0x01:HRM 0x02:filter mode)*/ 
    ErfCalibrationItem lte_tas_support;              /**< [20] TAS support.                                ;is_capable (0: not supported, 1: supported) */ 
    ErfCalibrationItem ncca_bypass_check;            /**< [21] For reporting NCCA Bypass check rx gain mode;is_capable (0: not supported, 1: supported) */ 
    ErfCalibrationItem lte_generation_version;          /**< [22]: For reporting generation version control ;is_capable (0: not supported, 1: supported) parameter (0x01:MD_V1 0x02:MD_V2...)*/
    ErfCalibrationItem lte_rftool_ui_version;          /**< [23]: For reporting RF tool UI version control ;is_capable (0: not supported, 1: supported) parameter */
    ErfCalibrationItem additional_palevel_support;
    ErfCalibrationItem lte_elna_support;                /**< [25]: For lte elna feature support             ;is_capable (0: not supported, 1: supported) parameter */
    ErfCalibrationItem lte_band2bitmap;               /**< [26]:For lte band to bitmap mapping  */
    ErfCalibrationItem lte_ubin_mode_setup;            /**< [27]:For lte UBin support                       ;is_capable (0: not supported, 1: supported) parameter */
} ErfCalibrationItemSet;

#define ERF_RF_ID_UNSUPPORT (0)
#define ERF_RF_ID_MT6169    (1)
#define ERF_RF_ID_MT6176    (2)
#define ERF_RF_ID_MT6179    (3)
#define ERF_RF_ID_MT6177L   (4)
#define ERF_RF_ID_MT6173    (5)

typedef struct
{
    int                    valid;
    int                    status;
    unsigned int           rfId;
    ErfCapabilityItemSet   capabilityItems;
    ErfCalibrationItemSet  calibrationItems;
} ERfTestCmdRfCapabilityCnf;

META_RESULT __stdcall META_ERf_GetRfCapability( const unsigned int ms_timeout, const ERfTestCmdRfCapabilityReq* req, const unsigned int requestLength, ERfTestCmdRfCapabilityCnf* resp, const unsigned int responseLength );
META_RESULT __stdcall META_ERf_GetRfCapability_r( const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdRfCapabilityReq* req, const unsigned int requestLength, ERfTestCmdRfCapabilityCnf* resp, const unsigned int responseLength );

typedef struct
{
    unsigned char duplexMode /**< 0:tdd, 1:fdd */;
    unsigned char band;
    unsigned short ulFrequency;/**< range: 7280~26900 (100KHz unit) */
    unsigned char capid;    /**< 0 ~ 255 */
    short afcdac;  /**< 0 ~ 8191 */
    unsigned char afcDataType; /**< 0: calibration data, 1: interface */
    short txPowerValue;/**<S(8,8),  x dB * 256.0 */
} ERfTestCmdAfcSingleToneTx;
/**
 * \brief non-reentrant version of META_ERf_AfcSingleToneTx_r
 */
META_RESULT  __stdcall META_ERf_AfcSingleToneTx( const ERfTestCmdAfcSingleToneTx* req, const unsigned int ms_timeout);
/**
 * \details AFC single tone TX for calibrating frequency error.
 * \param meta_handle meta handle
 * \param req The single TX control parameters to target
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_START_AFC_SINGLE_TONE_TX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_AfcSingleToneTx_r( const int meta_handle, const ERfTestCmdAfcSingleToneTx* req, const unsigned int ms_timeout);

typedef struct
{
    unsigned char     capid;       /**< 0 ~ 255 */
    unsigned short    afcdac;     /**< 0 ~ 8191 */
    int               slopeInv;
} ERfFreqAdjustTable;

/**
 * \brief non-reentrant version of META_ERf_GetAfcSetting_r
 */
META_RESULT  __stdcall META_ERf_GetAfcSetting( const unsigned int ms_timeout, ERfFreqAdjustTable* resp );
/**
 * \details LTE AFC NVRAM item write/read API
 * \param meta_handle meta handle
 * \param resp the pointer to a memory space for storing the result of AFC
 *           NVRAM item acquired from target.
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_GET_AFC_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetAfcSetting_r( const int meta_handle, const unsigned int ms_timeout, ERfFreqAdjustTable* resp );
/**
 * \brief non-reentrant version of META_ERf_SetAfcSetting_r
 */
META_RESULT  __stdcall META_ERf_SetAfcSetting( const ERfFreqAdjustTable* req, const unsigned int ms_timeout );
/**
 * \details LTE AFC NVRAM item write API
 * \param meta_handle meta handle
 * \param req the pointer to a memory space which is stored the AFC data for
 *          writing to target NVRAM.
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_AFC_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetAfcSetting_r( const int meta_handle, const ERfFreqAdjustTable* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char duplexMode /**< 0:tdd, 1:fdd */;
    unsigned char band;
    unsigned short ulFrequency;/**< range: 7280~26900 (100KHz unit) */
    unsigned char bandwidth;///<(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
    short ulFrequencyOffset;/*<* range: -32768~32767, 6 ==> 90K (1:15K), 6ªº­¿¼Æ*/
    short afcdac;
    unsigned char afcDataType; /**< 0: calibration data, 1: interface */
    short txPowerValue;/*<*S(8,8), x dB * 256.0 */
    unsigned char txCloseLoopDisbl;
    unsigned char pa_mode;
} ERfTestCmdTpcSingleToneTx;
/**
 * \brief non-reentrant version of META_ERf_ApcSingleToneTx_r
 */
META_RESULT  __stdcall META_ERf_ApcSingleToneTx( const ERfTestCmdTpcSingleToneTx* req, const unsigned int ms_timeout);
/**
 * \details APC single tone TX for calibrating TX power.
 * \param meta_handle meta handle
 * \param req The single TX control parameters to target
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_START_TPC_SINGLE_TONE_TX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_ApcSingleToneTx_r( const int meta_handle, const ERfTestCmdTpcSingleToneTx* req, const unsigned int ms_timeout );

typedef struct
{
    unsigned char   band; /**< 1~40 */
    short           txPaGain[MAX_ERF_TEST_TX_TPC_SETTING_TABLE_POWER_LEVEL_SIZE]; /**< resolution 1/32 */
} ERfTestCmdSetTpcPaGain;
/**
 * \brief non-reentrant version of META_ERf_UpdateRunTimePaGains_r
 */
META_RESULT  __stdcall META_ERf_UpdateRunTimePaGains( const ERfTestCmdSetTpcPaGain* req, const unsigned int ms_timeout );
/**
 * \details The API for changing the TX PA gain in DRAM (runtime value)
 *     for calibrating TX power.
 * \param meta_handle meta handle
 * \param req The pa gain of 8-level DC2DC table
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_TPC_PA_GAIN
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_UpdateRunTimePaGains_r( const int meta_handle, const ERfTestCmdSetTpcPaGain* req, const unsigned int ms_timeout );
/**
 * \brief non-reentrant version of META_ERf_GetPowerDectorValue_r
 */
META_RESULT  __stdcall META_ERf_GetPowerDectorValue( const unsigned int ms_timeout, short* txPowerDetectorValue );
/**
 * \details The API for acquiring the DAC value of power detector.
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param txPowerDetectorValue the short space for storing the DAC value of
 *                 power detector acquiring from target.
 * \sa ERF_TEST_CMD_GET_POWER_DETECTOR_VALUE
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetPowerDectorValue_r( const int meta_handle, const unsigned int ms_timeout, short* txPowerDetectorValue );

typedef struct
{
#define MAX_ERF_TEST_RX_RSSI_FREQ_NUM 36
    unsigned char   duplexMode;/**< 0:tdd, 1:fdd */
    unsigned char   band; /**< 1~40 */
    unsigned char   num_freq; /**< 1~36 */
    unsigned short  dl_freq[MAX_ERF_TEST_RX_RSSI_FREQ_NUM];
    unsigned char   temperatureIndex; /**< 0~7 */
    short           gain1; /**< main path, resolution 1/32 */
    short           gain2; /**< rx diversity path, resolution 1/32 */
} ERfTestCmdRSSI;

typedef struct
{
    unsigned char   num_freq;
    short           dl_freq[MAX_ERF_TEST_RX_RSSI_FREQ_NUM];
    short           rssi[MAX_ERF_TEST_RX_RSSI_FREQ_NUM]; /**< resolution 1/32 */
    unsigned char   lna_mode[MAX_ERF_TEST_RX_RSSI_FREQ_NUM]; /**< 0 ~ 5 */
    short           rssi_rxd[MAX_ERF_TEST_RX_RSSI_FREQ_NUM]; /**< resolution 1/32 */
    unsigned char   lna_mode_rxd[MAX_ERF_TEST_RX_RSSI_FREQ_NUM]; /**< 0 ~ 5 */
} ERfTestResultRSSI;
/**
 * \brief non-reentrant version of META_ERf_Rssi_r
 */
META_RESULT  __stdcall META_ERf_Rssi( const ERfTestCmdRSSI* req, const unsigned int ms_timeout, ERfTestResultRSSI* resp );
/**
 * \details The API for calibrating RX path loss.
 *     Set the command to target and get back the RSSI value.
 * \param meta_handle meta handle
 * \param req RSSI commands to target
 * \param ms_timeout time out in ms
 * \param resp RSSI results acquired from target
 * \sa ERF_TEST_CMD_START_RSSI
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_Rssi_r( const int meta_handle, const ERfTestCmdRSSI* req, const unsigned int ms_timeout, ERfTestResultRSSI* resp );

typedef struct
{
    unsigned char   duplexMode;                            /* 0:tdd, 1:fdd */
    unsigned char   ca_comb_tbl_idx;        /* 1~40 */
    unsigned char   num_freq;                              /* 1~36 */
    short          dl_freq[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];
    unsigned char   temperatureIndex;                       /* 0~7 */
    short          gain1[MAX_RX_CC_NUM];       /* resolution 1/32 */
    short          gain2[MAX_RX_CC_NUM];       /* resolution 1/32 */
} ERfTestCmdRSSI_CaMode;

typedef struct
{
    unsigned char   num_freq;
    short          dl_freq[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];
    short          rssi[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];         /* resolution 1/32 */
    unsigned char   lna_mode[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];     /* 0 ~ 5 */
    short          rssi_rxd[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX];     /* resolution 1/32 */
    unsigned char   lna_mode_rxd[MAX_RX_CC_NUM][MAX_FHC_RX_FREQ_NUM_EX]; /* 0 ~ 5 */
} ERfTestResultRSSI_CaMode;

/**
 * \brief non-reentrant version of META_ERf_Rssi_CaMode_r
 */
META_RESULT  __stdcall META_ERf_Rssi_CaMode( const ERfTestCmdRSSI_CaMode* req, const unsigned int ms_timeout, ERfTestResultRSSI_CaMode* resp );
/**
 * \details The API for calibrating RX path loss for ca mode.
 *     Set the command to target and get back the RSSI ca mode value.
 * \param meta_handle meta handle
 * \param req RSSI ca mode commands to target
 * \param ms_timeout time out in ms
 * \param resp RSSI ca mode results acquired from target
 * \sa ERF_TEST_CMD_START_RSSI_CA_MODE
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_Rssi_CaMode_r( const int meta_handle, const ERfTestCmdRSSI_CaMode* req, const unsigned int ms_timeout, ERfTestResultRSSI_CaMode* resp );

typedef struct
{
#define MAX_ERF_TEST_RX_LNA_MODE_NUM 6
    short   lna_mode[MAX_ERF_TEST_RX_LNA_MODE_NUM]; ///<loss of mode 0~5; resolution 1/32
} ERfRSSIGainOffsetTable;

typedef struct
{
#define MAX_ERF_TEST_RX_RSSI_TABLE_SUBBAND_NUM 15
    ERfRSSIGainOffsetTable gain_of_dl_freq[MAX_ERF_TEST_RX_RSSI_TABLE_SUBBAND_NUM];
} ERfRSSITempOffsetTable;

typedef struct
{
#define MAX_ERF_TEST_RX_RSSI_TEMP_INDEX_NUM 8
    unsigned short  dlMainFrequency[MAX_ERF_TEST_RX_RSSI_TABLE_SUBBAND_NUM];
    unsigned short  dlDiversityFrequency[MAX_ERF_TEST_RX_RSSI_TABLE_SUBBAND_NUM];
    ERfRSSITempOffsetTable  pathlossMainData[MAX_ERF_TEST_RX_RSSI_TEMP_INDEX_NUM];
    ERfRSSITempOffsetTable  pathlossDiversityData[MAX_ERF_TEST_RX_RSSI_TEMP_INDEX_NUM];
} ERfRSSIBandGainTable;

/**
 * \brief non-reentrant version of META_ERf_SetPathLossSetting_r
 */
META_RESULT  __stdcall META_ERf_SetPathLossSetting( const unsigned char band, const ERfRSSIBandGainTable* req, const unsigned int ms_timeout );
/**
 * \details SET/GET gain offset table to/from target for a specific band
 * \param meta_handle meta handle
 * \param band band index
 * \param req RSSI commands to target
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_RSSI_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetPathLossSetting_r( const int meta_handle, const unsigned char band, const ERfRSSIBandGainTable* req, const unsigned int ms_timeout );
/**
 * \brief non-reentrant version of META_ERf_GetPathLossSetting_r
 */
META_RESULT  __stdcall META_ERf_GetPathLossSetting( const unsigned char band, const unsigned int ms_timeout, ERfRSSIBandGainTable* resp );
/**
 * \details GET gain offset table to/from target for a specific band
 * \param meta_handle meta handle
 * \param band band index
 * \param ms_timeout time out in ms
 * \param resp: RSSI results acquired from target
 * \sa ERF_TEST_CMD_GET_RSSI_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetPathLossSetting_r( const int meta_handle, const unsigned char band, const unsigned int ms_timeout, ERfRSSIBandGainTable* resp );

typedef enum
{
    ERF_TEST_RSSI_TABLE_TYPE_INVALID     = 0,
    ERF_TEST_RSSI_TABLE_TYPE_1          = 1,  // for single band or inter-band CA RSSI table
    ERF_TEST_RSSI_TABLE_TYPE_2          = 2,  // for NCCA RSSI table
    ERF_TEST_RSSI_TABLE_TYPE_MAX,
} ERfTestRSSITableType;

typedef struct
{
    short   lna_mode[MAX_RX_LNA_MODE_NUM];  // loss of mode 0~5; resolution 1/32
} ERfRSSIGainOffsetTable_Type1;

typedef struct
{
    short   lna_mode[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM]; // loss of mode 0~5, PCC & SCC; resolution 1/32
} ERfRSSIGainOffsetTable_Type2;

typedef struct
{
    short  temp_comp[MAX_TEMP_SECTION_NUM];
} ERfRSSITempOffsetTable_Ex;

typedef struct
{
    unsigned char   bandIndex;
    unsigned char   routeIndex;
    unsigned short  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type1 pathlossMainData[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type1 pathlossDiversityData[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSITempOffsetTable_Ex pathlossTempData;
} ERfRSSIBandGainTable_Type1;

typedef struct
{
    unsigned char   bandIndex;
    unsigned char   routeIndex;
    unsigned short  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type2 pathlossMainData[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type2 pathlossDiversityData[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSITempOffsetTable_Ex pathlossTempData;
} ERfRSSIBandGainTable_Type2;

typedef union
{
    ERfRSSIBandGainTable_Type1  t1_tbl;
    ERfRSSIBandGainTable_Type2  t2_tbl;
} ERfRSSIBandGainTable_Ex;

typedef enum
{
    ERF_TEST_RSSI_SET_STATUS_INVALID = 0,
    ERF_TEST_RSSI_SET_STATUS_OK   = 1,   // set scusses
    ERF_TEST_RSSI_SET_STATUS_ERR1 = 2, // band mismatch with route
    ERF_TEST_RSSI_SET_STATUS_ERR2 = 3, // subband frequency out of band region
    ERF_TEST_RSSI_SET_STATUS_MAX,
} ERfTestRSSISetStatus;

/**
 * \brief non-reentrant version of META_ERf_SetPathLossSettingEx_r
 */
META_RESULT  __stdcall META_ERf_SetPathLossSettingEx( const unsigned char RssiTableType, const ERfRSSIBandGainTable_Ex* req, const unsigned int ms_timeout, ERfTestRSSISetStatus& statusCode);
/**
 * \details SET/GET gain offset table to/from target for a specific band
 * \param meta_handle meta handle
 * \param route_index route index
 * \param req path loss commands to target
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_RSSI_SETTING_EX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetPathLossSettingEx_r( const int meta_handle, const unsigned char RssiTableType, const ERfRSSIBandGainTable_Ex* req, const unsigned int ms_timeout, ERfTestRSSISetStatus& statusCode);
/**
 * \brief non-reentrant version of META_ERf_GetPathLossSettingEx_r
 */
META_RESULT  __stdcall META_ERf_GetPathLossSettingEx( const unsigned char RssiTableType, const unsigned int ms_timeout, ERfRSSIBandGainTable_Ex* resp );
/**
 * \details GET gain offset table to/from target for a specific band
 * \param meta_handle meta handle
 * \param route_index route index
 * \param ms_timeout time out in ms
 * \param resp: path loss results acquired from target
 * \sa ERF_TEST_CMD_GET_RSSI_SETTING_EX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetPathLossSettingEx_r( const int meta_handle, const unsigned char RssiTableType, const unsigned int ms_timeout, ERfRSSIBandGainTable_Ex* resp );

typedef struct
{
    unsigned char   duplexMode;/**< 0:tdd, 1:fdd */
    unsigned char   band; /**< 1~40 */
    unsigned short  dl_freq;
    unsigned char   bandwidth;///<(DL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
    short           gain1; /**< main path, resolution 1/32 */
    short           gain2;  /**< rx diversity path, resolution 1/32 */
} ERfTestCmdContRx;
/**
 * \brief non-reentrant version of META_ERf_ContRx_r
 */
META_RESULT  __stdcall META_ERf_ContRx( const ERfTestCmdContRx* req, const unsigned int ms_timeout);
/**
 * \details Trigger DUT starts continuous RX
 * \param meta_handle meta handle
 * \param req Continuous RX commands to target
 * \param ms_timeout: time out in ms
 * \sa ERF_TEST_CMD_START_CONT_RX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_ContRx_r( const int meta_handle, const ERfTestCmdContRx* req, const unsigned int ms_timeout);

typedef struct
{
    unsigned char duplexMode; /* 0:tdd, 1:fdd */
    unsigned char ca_comb_tbl_idx; /* 1~128 */
    unsigned short dl_freq[MAX_RX_CC_NUM];
    unsigned char bandwidth[MAX_RX_CC_NUM]; /*(DL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB*/
    short gain1[MAX_RX_CC_NUM]; /* main path, resolution 1/32 */
    short gain2[MAX_RX_CC_NUM]; /* rx diversity path, resolution 1/32 */
} ERfTestCmdContRx_CaMode;
/**
 * \brief non-reentrant version of META_ERf_ContRx_CaMode_r
 */
META_RESULT  __stdcall META_ERf_ContRx_CaMode( const ERfTestCmdContRx_CaMode* req, const unsigned int ms_timeout);
/**
 * \details Trigger DUT starts continuous RX CA Mode
 * \param meta_handle meta handle
 * \param req Continuous RX CA Mode commands to target
 * \param ms_timeout: time out in ms
 * \sa ERF_TEST_CMD_START_CONT_RX_CA_MODE
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_ContRx_CaMode_r( const int meta_handle, const ERfTestCmdContRx_CaMode* req, const unsigned int ms_timeout);
typedef struct
{
    unsigned char  rf_band;
    unsigned char  vco_lna_port_cfg_index;
    unsigned char  is_lna_low_power_mode;  // 0: HPM, 1: LPM
} ERfTestCmdSetRxCommonCfg;
/**
 * \brief non-reentrant version of META_ERf_SetLnaSrx_r
 */
META_RESULT  __stdcall META_ERf_SetLnaSrx( const ERfTestCmdSetRxCommonCfg* req, const unsigned int ms_timeout);
/**
 * \details Set RX path to target
 * \param meta_handle meta handle
 * \param req Set RX Path commands to target
 * \param ms_timeout: time out in ms
 * \sa ERF_TEST_CMD_SET_LNA_SRX
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetLnaSrx_r( const int meta_handle, const ERfTestCmdSetRxCommonCfg* req, const unsigned int ms_timeout);


typedef struct
{
    unsigned char          vco;
    unsigned char          srx;
    unsigned char          lna_port;
    unsigned char          lna_group;
} ERfTestVcoSrxLnaCfg;

typedef struct
{
    unsigned char          band;
    unsigned char          padding[MAX_SRX_LNA_SETTING_NUM];
    ERfTestVcoSrxLnaCfg     cfg[MAX_SRX_LNA_SETTING_NUM];
} ERfTestSupportVcoSrxLnaCfg;

typedef struct
{
    unsigned char          band;
    unsigned char          route_idx;
    unsigned char          usg_start_idx;
    unsigned char          usg_stop_idx;
} ERfTestUsageElm;

typedef struct
{
    ERfTestUsageElm    cat[4];
} ERfTestSupportRxUsageByBand;

typedef struct
{
    unsigned char          band;
    unsigned char          index[MAX_SCENARIO_BY_BAND_NUM];
} ERfTestSupportCaCombTblIdx;

typedef enum
{
    VCO_SRX_SEL_INVALID = 0,
    VCO_SRX_SEL_VCO     = 1,
    VCO_SRX_SEL_SRX     = 2
} ERfTestVcoSrxSel;

typedef struct
{
    unsigned char          band;
    unsigned char          bw_class;
    unsigned char          lna_port;
    unsigned char          lna_group;
    unsigned char          vco_cfg;
    unsigned char          srx_cfg;
    unsigned char          padding[2];
} ERfTestRouteDes;

typedef struct
{
    ERfTestRouteDes    cfg[MAX_RX_CC_NUM];
} ERfTestScenarioDes;

typedef struct
{
    int table_idx_count;
    ERfTestScenarioDes caCombinationTableElement[128];
} ERfTestCaCombinationTable;

typedef struct
{
    unsigned char     cc_band;
    unsigned char     cc_class;
} ERfTestCcElm;

typedef struct
{
    unsigned char      cc_num;
    unsigned char      usg_band;
    ERfTestCcElm       cc_setting[MAX_RX_CC_NUM];
} ERfTestUsageDes;

typedef struct
{
    unsigned short  usg_num;
    ERfTestUsageDes usg_array[MAX_CA_USAGE_NUM];
} ERfTestUsageDesTable;

typedef struct
{
    unsigned char         band;
    unsigned char         ca_cat_rx_cal_bitmap;
    unsigned char         ca_cat_tx_cal_bitmap;
    unsigned char         padding;
} ERfTestSupportCaCalDim;

typedef struct
{
    unsigned short         gain_mode1_ena    : 1;
    unsigned short         gain_mode2_ena    : 1;
    unsigned short         gain_mode3_ena    : 1;
    unsigned short         gain_mode4_ena    : 1;
    unsigned short         gain_mode5_ena    : 1;
    unsigned short         gain_mode6_ena    : 1;
    unsigned short         gain_mode_lpm_ena : 1;
    unsigned short         gain_mode_reserved: 9;
    unsigned short         gain_by_gain_expn_type;
} ERfTestSupportRxGainModeMask;

typedef struct
{
    unsigned short         gain_mode_setting[MAX_RX_LNA_MODE_NUM][2]; /*[0] upper limit; [1] lower limit*/
} ERfTestSupportRxGain;

typedef struct
{
   char          ncca_gbg_bypass_check_table[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
} ERfTestNccaGbgBypassCheck;

#define ERF_BAND_MAPPING_TBL_SIZE 64

typedef struct
{
    /*Struct should be 4 bytes alignment*/
    unsigned int                  support_route_map[MAX_ROUTE_NUM_IN_WORD];
    unsigned int                  ltea_vco_srx_sel;
    ERfTestSupportVcoSrxLnaCfg    support_vco_srx_lna_cfg[ERF_MAX_BAND_NUM];
    ERfTestCaCombinationTable     ca_comb_tbl;
    ERfTestSupportCaCombTblIdx    support_ca_cfg_tbl_idx[ERF_MAX_BAND_NUM];
    ERfTestUsageDesTable          rx_usg_tbl;
    ERfTestSupportRxUsageByBand   support_rx_usage_by_band[ERF_MAX_BAND_NUM];
    ERfTestSupportCaCalDim        ca_cal_dim[ERF_MAX_BAND_NUM];
    ERfTestSupportRxGainModeMask  support_rx_gain_mode_mask;
    ERfTestSupportRxGain          support_rx_gain_mode_setting;
    ERfTestNccaGbgBypassCheck     ncca_gbg_bypass_check_setting;
    unsigned int                band_mapping_table[ERF_BAND_MAPPING_TBL_SIZE];
} ERfTestCmdCaConfig;

/**
 * \brief non-reentrant version of META_ERf_QueryCaConfigTable_r
 */
META_RESULT  __stdcall META_ERf_QueryCaConfigTable( const unsigned int ms_timeout, ERfTestCmdCaConfig* resp);
/**
 * \details To get ca config table from target
 * \param meta_handle meta handle
 * \param ms_timeout: time out in ms
 * \param resp RX ca usage table
 * \sa ERF_TEST_CMD_QUERY_RX_CA_USAGE_TABLE
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_QueryCaConfigTable_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdCaConfig* resp);

/********************
 *   FHC interface  *
 ********************/

#define MAX_FHC_BAND_NUM 10
#define MAX_FHC_RX_FREQ_NUM 22  ///< MAX( MAX_FHC_RX_FREQ_NUM, MAX_FHC_TX_FREQ_NUM )
#define MAX_FHC_TX_FREQ_NUM 22  ///< subband nubmer + middle channel
#define MAX_FHC_PWR_STEP_NUM 27     ///< 8 pa section * 3 + 3 PD values(H,M,L)

/* uplink arrangements */
typedef struct
{
    unsigned short   ul_freq;///<100kHz unit
    unsigned char    ul_bw;///<0(1.4M)~5(20M)
    unsigned char    pwr_step_num; ///< number of power steps
    short            pwr_step_value[MAX_FHC_PWR_STEP_NUM]; ///< tx power report from detector S(8, 8)
    short            pwr_step_pa_gain [MAX_FHC_PWR_STEP_NUM]; ///< PA gain used for tx power step
    unsigned char    pwr_step_pa_gain_tbl_indx [MAX_FHC_PWR_STEP_NUM]; ///< PA gain table index for tx power step
    unsigned char    pwr_step_pa_mode [MAX_FHC_PWR_STEP_NUM];  /**< 0: high, 1: middle, 2: low */
} ERf_FHC_Tx_Freq_Param;

typedef struct
{
    unsigned char    band_index; ///< band indicator (starting from 0)
    unsigned char    freq_num;
    ERf_FHC_Tx_Freq_Param freq_param[MAX_FHC_TX_FREQ_NUM];
} ERf_FHC_Tx_Band_Param;

typedef struct
{
    unsigned char    tx_step_width;///<ms unit
    unsigned char    band_num;
    ERf_FHC_Tx_Band_Param     band_param[MAX_FHC_BAND_NUM];
    short            freq_offst;///<range -32768~32767
    short            afc_dac;
    unsigned char    afc_data_type;///<0: calibration data, 1: from interface value
    unsigned char    close_loop_disable;
} ERf_FHC_Tx_Cfg;

/* uplink arrangements */
typedef struct
{
    unsigned short   dl_freq;///<100kHz unit
    unsigned char    temperature_indx;
    unsigned char    pwr_step_num;
    short            gain1[MAX_FHC_PWR_STEP_NUM];
    short            gain2[MAX_FHC_PWR_STEP_NUM];
} ERf_FHC_Rx_Freq_Param;

typedef struct
{
    unsigned char    band_index;
    unsigned char    freq_num;
    ERf_FHC_Rx_Freq_Param freq_param[MAX_FHC_RX_FREQ_NUM];
} ERf_FHC_Rx_Band_Param;

typedef struct
{
    unsigned char   tx_to_rx_time;///<ms unit
    unsigned char   band_num;
    ERf_FHC_Rx_Band_Param    band_param[MAX_FHC_BAND_NUM];
} ERf_FHC_Rx_Cfg;

/* FHC TRX command parameter */
typedef struct
{
    unsigned char    phy_cell_id;///< no used for single tone?
    unsigned char    fdd_band_start_index;
    unsigned char    fdd_band_end_index;
    unsigned char    tdd_band_start_index;
    unsigned char    tdd_band_end_index;
    unsigned char    fdd_to_tdd_switch_time;///<ms unit
    unsigned char    tdd_to_fdd_switch_time;///<ms unit
    unsigned char    tdd_tx_rx_switch_time;///<ms unit
    unsigned char    freq_switch_time;///<ms unit
    unsigned char    band_switch_time;///<ms unit
    ERf_FHC_Tx_Cfg   txCmd;
    ERf_FHC_Rx_Cfg   rxCmd;
} ERf_FHC_Cmd;


/* FHC TRX results */
typedef struct
{
    unsigned short    ul_freq;///<100kHz unit
    short             txPowerDetectorValue[MAX_FHC_PWR_STEP_NUM];
    unsigned char     pwr_step_num;
} ERf_FHC_Tx_Freq_Rpt;

typedef struct
{
    unsigned short   dl_freq;///<100kHz unit
    short            rssi[MAX_FHC_PWR_STEP_NUM];
    short            rssi_rxd[MAX_FHC_PWR_STEP_NUM];
    unsigned char    lna_mode[MAX_FHC_PWR_STEP_NUM];
    unsigned char    lna_mode_rxd[MAX_FHC_PWR_STEP_NUM];
    unsigned char    pwr_step_num;
} ERf_FHC_Rx_Freq_Rpt;

typedef struct
{
    unsigned char    band_index;
    unsigned char    tx_freq_num;
    unsigned char    rx_freq_num;
    ERf_FHC_Tx_Freq_Rpt  tx_freq_rpt[MAX_FHC_TX_FREQ_NUM];
    ERf_FHC_Rx_Freq_Rpt  rx_freq_rpt[MAX_FHC_RX_FREQ_NUM];
} ERf_FHC_TRx_Band_Rpt;

typedef struct
{
    unsigned char           band_num;
    ERf_FHC_TRx_Band_Rpt    band_rpt[MAX_FHC_BAND_NUM];
} ERf_FHC_TRx_Rpt;
/**
 * \brief non-reentrant version of META_ERf_FHC_r
 */
META_RESULT  __stdcall META_ERf_FHC( const ERf_FHC_Cmd* req, const unsigned int ms_timeout, ERf_FHC_TRx_Rpt* resp );
/**
 * \details Command target to execute FHC arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req FHC arrangements
 * \param ms_timeout time out in ms
 * \param resp RSSI results and PD values acquired from target
 * \sa ERF_TEST_CMD_START_FHC
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_FHC_r( const int meta_handle, const ERf_FHC_Cmd* req, const unsigned int ms_timeout, ERf_FHC_TRx_Rpt* resp );

/********************* MT6291 Structure Definitions *********************/

/********************* CA Mode FHC REPORT *********************/
typedef struct
{
    unsigned short  dl_freq;//100kHz unit
    short          rssi_m[MAX_RX_LNA_MODE_NUM];
    short          rssi_d[MAX_RX_LNA_MODE_NUM];
} ERf_FHC_Rx_Type1_Freq_Rpt;

typedef struct
{
    unsigned short  dl_freq;//100kHz unit
    short          rssi_m[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
    short          rssi_d[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
} ERf_FHC_Rx_Type2_Freq_Rpt;

typedef struct
{
    unsigned char              route_index;
    unsigned char              band_index;  //real band number,  ex. band_index=LTE_BAND26
    unsigned char              rx_freq_num;
    ERf_FHC_Rx_Type1_Freq_Rpt  rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
} ERf_FHC_Rx_Type1_Route_Rpt;

typedef struct
{
    unsigned char              route_index;
    unsigned char              band_index;  //real band number,  ex. band_index=LTE_BAND26
    unsigned char              rx_freq_num;
    ERf_FHC_Rx_Type2_Freq_Rpt  rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
} ERf_FHC_Rx_Type2_Route_Rpt;

typedef struct
{
    unsigned short  ul_freq;      //100kHz unit
    short          txPowerDetectorValue[MAX_TX_RPT_NUM];
} ERf_FHC_Tx_Type1_Freq_Rpt;

typedef struct
{
    unsigned char             route_index;  //route_index = X th calibration Band
    unsigned char             band_index;   //real band number,  ex. band_index=LTE_BAND26
    unsigned char             tx_freq_num;
    ERf_FHC_Tx_Type1_Freq_Rpt tx_freq_rpt[MAX_FHC_TX_FREQ_NUM_EX];
} ERf_FHC_Tx_Type1_Route_Rpt;

typedef struct
{
    unsigned char               rx_type1_route_num;
    unsigned char               rx_type2_route_num;
    unsigned char               tx_type1_route_num;
    ERf_FHC_Rx_Type1_Route_Rpt  rx_type1_rpt[MAX_FHC_RX_TYPE1_ROUTE_NUM];
    ERf_FHC_Rx_Type2_Route_Rpt  rx_type2_rpt[MAX_FHC_RX_TYPE2_ROUTE_NUM];
    ERf_FHC_Tx_Type1_Route_Rpt  tx_type1_rpt[MAX_FHC_TX_TYPE1_ROUTE_NUM];
} ERf_FHC_CaMode_Rpt;

/********************* CA Mode FHC COMMAND *********************/
typedef struct
{
    short   gain_rxm[MAX_RX_LNA_MODE_NUM];
    short   gain_rxd[MAX_RX_LNA_MODE_NUM];
} ERf_FHC_Rx_Type1_Gain_Param;

typedef struct
{
    short   gain_rxm[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
    short   gain_rxd[MAX_RX_CC_NUM][MAX_RX_LNA_N_MODE_NUM][MAX_RX_LNA_N_MODE_NUM];
} ERf_FHC_Rx_Type2_Gain_Param;

typedef struct
{
    unsigned char   band_index;
    unsigned char   ca_category;
    unsigned char   freq_num;
    unsigned short  dl_freq[MAX_FHC_RX_FREQ_NUM_EX]; //100kHz unit
} ERf_FHC_Rx_Band_Param_CaMode;

typedef struct
{
    unsigned char                band_num;
    ERf_FHC_Rx_Type1_Gain_Param  t1_band[3];
    ERf_FHC_Rx_Type2_Gain_Param  t2_band;
    ERf_FHC_Rx_Band_Param_CaMode band_param[ERF_MAX_BAND_NUM];
} ERf_FHC_Rx_Cfg_CaMode;

typedef struct
{
    unsigned char   band_index;
    unsigned char   freq_num;
    unsigned short  ul_freq[MAX_FHC_TX_FREQ_NUM_EX];
    unsigned char   pwr_step_pa_mode [MAX_TX_RPT_NUM];
    short          pwr_step_value[MAX_TX_RPT_NUM]; //target Power (PRF)
    short          pwr_step_pa_gain[MAX_TX_RPT_NUM];
} ERf_FHC_Tx_Band_Param_Ex;

typedef struct
{
    unsigned char   band_num;
    unsigned char   pwr_step_num;
    ERf_FHC_Tx_Band_Param_Ex    band_param[ERF_MAX_BAND_NUM];
} ERf_FHC_Tx_Cfg_Ex;

typedef struct
{
    unsigned char         fdd_to_tdd_switch_time;//ms unit
    unsigned char         fdd_tx_rx_switch_time;
    unsigned char         tdd_tx_rx_switch_time;//ms unit
    unsigned char         freq_switch_time;//ms unit
    unsigned char         band_switch_time;//ms unit
    unsigned char         step_time;
    ERf_FHC_Tx_Cfg_Ex     txCmd;
    ERf_FHC_Rx_Cfg_CaMode rxCmd;
} ERf_FHC_Cmd_CaMode;
/**
 * \brief non-reentrant version of META_ERf_FHC_CaMode_r
 */
META_RESULT  __stdcall META_ERf_FHC_CaMode( const ERf_FHC_Cmd_CaMode* req, const unsigned int ms_timeout, ERf_FHC_CaMode_Rpt* resp );
/**
 * \details Command target to execute CA mode FHC arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req CA mode FHC arrangements
 * \param ms_timeout time out in ms
 * \param resp RSSI results and PD values acquired from target
 * \sa ERF_TEST_CMD_START_FHC
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_FHC_CaMode_r( const int meta_handle, const ERf_FHC_Cmd_CaMode* req, const unsigned int ms_timeout, ERf_FHC_CaMode_Rpt* resp );


typedef struct
{
    bool         ok;
    unsigned int sum;
} ERf_TemperatureResult;
/**
 * \brief non-reentrant version of META_ERf_GetRfTemperature_r
 */
META_RESULT __stdcall META_ERf_GetRfTemperature(const unsigned int ms_timeout, const unsigned short measureCount, ERf_TemperatureResult* result);
/**
 * \details Get RF Temperature sensor reading
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param measureCount number of measurements
 * \param result the temperature sensor reading value
 * \sa ERF_TEST_CMD_GET_RF_TEMP
 * \retval META_SUCCESS successful
 **/
META_RESULT __stdcall META_ERf_GetRfTemperature_r(const int meta_handle, const unsigned int ms_timeout, const unsigned short measureCount, ERf_TemperatureResult* result);

typedef struct
{
#define MAX_ERF_TEST_TADC_INDEX_NUM 8
    unsigned short data[MAX_ERF_TEST_TADC_INDEX_NUM];
} ERfTadcSetting;
/**
 * \brief non-reentrant version of META_ERf_GetTadcSetting_r
 */
META_RESULT __stdcall META_ERf_GetTadcSetting(const unsigned int ms_timeout, ERfTadcSetting* table);
/**
 * \details LTE TADC NVRAM read API
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param table the LTE TADC NVRAM data
 * \sa ERF_TEST_CMD_GET_TADC_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT __stdcall META_ERf_GetTadcSetting_r(const int meta_handle, const unsigned int ms_timeout, ERfTadcSetting* table);
/**
 * \brief non-reentrant version of META_ERf_SetTadcSetting_r
 */
META_RESULT __stdcall META_ERf_SetTadcSetting(const unsigned int ms_timeout, const ERfTadcSetting* table);
/**
 * \details LTE TADC NVRAM write API
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param table the LTE TADC NVRAM data
 * \sa ERF_TEST_CMD_SET_TADC_SETTING
 * \retval META_SUCCESS successful
 **/
META_RESULT __stdcall META_ERf_SetTadcSetting_r(const int meta_handle, const unsigned int ms_timeout, const ERfTadcSetting* table);
#define MAX_ERF_MIPI_POWER_LEVEL   16
#define MAX_ERF_MIPI_CODE_WORD_NUM 16
typedef struct
{
    unsigned short       rf_band_idx;
    unsigned short       power_level_num;
    unsigned short       code_word_num;
    unsigned int         codeword[MAX_ERF_MIPI_POWER_LEVEL][MAX_ERF_MIPI_CODE_WORD_NUM];
} ERfSetMIPICodeWord;
typedef struct
{
    unsigned short       power_level_num;
    unsigned short       code_word_num;
    unsigned int         codeword[MAX_ERF_MIPI_POWER_LEVEL][MAX_ERF_MIPI_CODE_WORD_NUM];
} ERfGetMIPICodeWord;
META_RESULT __stdcall META_ERf_SetMIPICodeWord(const ERfSetMIPICodeWord* req,  unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetMIPICodeWord_r(const int meta_handle, const ERfSetMIPICodeWord* req, const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_GetMIPICodeWord(const unsigned int ms_timeout, const unsigned short RfBandIndex, ERfGetMIPICodeWord* cnf);
META_RESULT __stdcall META_ERf_GetMIPICodeWord_r(const int meta_handle, const unsigned int ms_timeout, const unsigned short RfBandIndex, ERfGetMIPICodeWord* cnf);

typedef enum
{
   ERF_TEST_MODEM_NULL  =  0,
   ERF_TEST_MODEM_V1    =  1,
   ERF_TEST_MODEM_V2    =  2,
   ERF_TEST_MODEM_V3    =  3,
   ERF_TEST_MODEM_END   =  0xFFFF
} ERfTestLteGeneration;
/********************* MT6292 Constant Definitions *********************/
#define      ERF_BAND_MAP_SIZE                     2 //support 2*32 bands at maximum, need to align LTE_BIT_MASK_BUFFER_SIZE
#define      ERF_MAX_BAND_NUM_V2                   35
#define      MAX_TX_CC_NUM                         2
#define      MAX_RX_CC_NUM_V2                      4
#define      MAX_RX_LNA_TYPE_NUM                   2

#define      MAX_TX_TYPE1_CATEGORY_NUM            16
#define      MAX_TX_CATEGORY_NUM                 MAX_TX_TYPE1_CATEGORY_NUM
#define      MAX_RX_TYPE1_CATEGORY_NUM            16
#define      MAX_RX_TYPE2_CATEGORY_NUM             8
#define      MAX_RX_CATEGORY_NUM                 MAX_RX_TYPE1_CATEGORY_NUM  +  MAX_RX_TYPE2_CATEGORY_NUM 

#define      MAX_RX_TYPE1_LNA_N_MODE_NUM           6     //   for LNA normal mode
#define      MAX_RX_TYPE1_LNA_L_MODE_NUM           3     //   for LNA low power mode
#define      MAX_RX_TYPE1_LNA_MODE_NUM          (MAX_RX_TYPE1_LNA_N_MODE_NUM  +  MAX_RX_TYPE1_LNA_L_MODE_NUM)

#define      MAX_RX_TYPE2_LNA_N_MODE_NUM           6  //for LNA normal mode
#define      MAX_RX_TYPE2_LNA_L_MODE_NUM           3  //for LNA low power mode
#define      MAX_RX_TYPE2_LNA_MODE_NUM          (MAX_RX_TYPE2_LNA_N_MODE_NUM  +  MAX_RX_TYPE2_LNA_L_MODE_NUM)

#define      RX_TYPE2_START_ROUTE_NUM            512
#define      MAX_RX_TYPE2_GBG_PATH_NUM             2

#define      MAX_FHC_TX_TYPE1_ROUTE_NUM_V2       256
#define      MAX_FHC_RX_TYPE1_ROUTE_NUM_V2       512
#define      MAX_FHC_RX_TYPE2_ROUTE_NUM_V2        64

#define      MAX_TX_ROUTE_NUM                    MAX_FHC_TX_TYPE1_ROUTE_NUM_V2
#define      MAX_RX_ROUTE_NUM                    MAX_FHC_RX_TYPE1_ROUTE_NUM_V2 + MAX_FHC_RX_TYPE2_ROUTE_NUM_V2

#define      MAX_FHC_RX_TYPE1_CMD_NUM             16
#define      MAX_FHC_RX_TYPE2_CMD_NUM              8 
#define      MAX_FHC_TX_TYPE1_CMD_NUM             16
#define      MAX_FHC_RX_TYPE1_REPORT_NUM          16
#define      MAX_FHC_RX_TYPE2_REPORT_NUM           8 
#define      MAX_FHC_TX_TYPE1_REPORT_NUM          16

#define      MAX_RX_ANT_NUM                        2
#define      MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM     65
#define      MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM      5
#define      MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM     32

#define      ADDITIONAL_PA_LEVEL                   2
#define      MAX_TX_RPT_NUM_V2                  (MAX_TX_DET_MODE_NUM + MAX_TX_PA_LEVEL_NUM + ADDITIONAL_PA_LEVEL)
#define      ERF_MAX_TX_BYPASS_BAND_NUM            5
#define      ERF_MAX_TX_CCA_BAND_NUM             ERF_MAX_BAND_NUM_V2
#define      LTE_PORT_ASCII_ARRAY_SIZE           8
/********************* MT6292 Constant Definitions *********************/

/********************* MT6293 Constant Definitions *********************/
#define ERF_MAX_BAND_NUM_V3                       25
#define ERF_MAX_TX_CCA_BAND_NUM_V3                ERF_MAX_BAND_NUM_V3
#define ERF_MAX_TX_BYPASS_BAND_NUM_V3             5

#define ERF_MAX_FHC_RX_FREQ_NUM_V3                15
#define ERF_MAX_FHC_TX_FREQ_NUM_V3                15

#define ERF_MAX_RX_ANT_NUM_V3                     2
#define ERF_MAX_RX_CC_NUM_V3                      2
#define ERF_MAX_TX_CC_NUM_V3                      2

#define ERF_MAX_RX_ELNA_TYPE_V3                   5

#define ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3          4
#define ERF_MAX_TX_CATEGORY_NUM_V3                ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3

#define ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3          4
#define ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3          2
#define ERF_MAX_RX_CATEGORY_NUM_V3                ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3 + ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3

#define ERF_MAX_RX_LNA_MODE_NUM_V3                7  //for LNA normal mode

#define ERF_MAX_RX_TYPE1_SEQ_NUM_V3               7
#define ERF_MAX_RX_TYPE2_SEQ_NUM_V3               18

#define ERF_RX_TYPE2_START_ROUTE_NUM_V3           96
#define ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3          2

#define ERF_MAX_FHC_TX_TYPE1_ROUTE_NUM_V3         50
#define ERF_MAX_FHC_RX_TYPE1_ROUTE_NUM_V3         88
#define ERF_MAX_FHC_RX_TYPE2_ROUTE_NUM_V3         22

#define ERF_MAX_TX_ROUTE_NUM_V3                   ERF_MAX_FHC_TX_TYPE1_ROUTE_NUM_V3
#define ERF_MAX_RX_ROUTE_NUM_V3                   ERF_MAX_FHC_RX_TYPE1_ROUTE_NUM_V3 + ERF_MAX_FHC_RX_TYPE2_ROUTE_NUM_V3

#define ERF_LTE_ANT_ALL_MASK_V3                   (LTE_ANT_0_MASK | LTE_ANT_1_MASK)

#define ERF_MAX_FHC_RX_TYPE1_CMD_NUM_V3           12
#define ERF_MAX_FHC_RX_TYPE2_CMD_NUM_V3           6
#define ERF_MAX_FHC_TX_TYPE1_CMD_NUM_V3           12

#define ERF_MAX_FHC_RX_TYPE1_REPORT_NUM_V3        12
#define ERF_MAX_FHC_RX_TYPE2_REPORT_NUM_V3        6
#define ERF_MAX_FHC_TX_TYPE1_REPORT_NUM_V3        12

#define ERF_MAX_FHC_BAND_CMD_NUM_V3               12

#define ERF_MAX_PEER_BUF_CNF_BYTE_SIZE            51200 //50*1024
#define ERF_MAX_PEER_BUF_CNF_WORD_SIZE            ERF_MAX_PEER_BUF_CNF_BYTE_SIZE >> 2

#define ERF_MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM_V3   ( ERF_MAX_PEER_BUF_CNF_BYTE_SIZE/sizeof(ERfRSSIBandGainTable_Type1_V3) )
#define ERF_MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM_V3   ( ERF_MAX_PEER_BUF_CNF_BYTE_SIZE/sizeof(ERfRSSIBandGainTable_Type2_V3) )
#define ERF_MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM_V3   ( ERF_MAX_PEER_BUF_CNF_BYTE_SIZE/sizeof(ERfTestCmdGetSetTpcSetting_V3) )
#define ADDITIONAL_PA_LEVEL_V3                    2
#define MAX_TX_RPT_NUM_V3                       (MAX_TX_DET_MODE_NUM + MAX_TX_PA_LEVEL_NUM + ADDITIONAL_PA_LEVEL_V3)

#define MAX_RX_RFTOOL_FERQ_NUM                    5
/********************* MT6293 Constant Definitions *********************/

/********************* MT6292 Structure Definitions *********************/
typedef struct
{
    unsigned char       total_route_num;
    unsigned char       padding;
    unsigned short      band;
    unsigned short      total_route_idx[MAX_TX_TYPE1_CATEGORY_NUM];
    unsigned short      comp_route_idx[MAX_TX_TYPE1_CATEGORY_NUM];//take considerate FE route + RFIC route
    unsigned short      FE_route_idx[MAX_TX_TYPE1_CATEGORY_NUM];
    unsigned char       port[MAX_TX_TYPE1_CATEGORY_NUM];
    unsigned char       stx[MAX_TX_TYPE1_CATEGORY_NUM];
} ERfTestTxType1CaInfo;

typedef struct
{
    unsigned char    total_route_num;
    unsigned char    padding;
    unsigned short   band;
    unsigned short   total_route_idx[MAX_RX_TYPE1_CATEGORY_NUM];   
    unsigned short   comp_route_idx[MAX_RX_TYPE1_CATEGORY_NUM];   
    unsigned short   FE_route_idx[MAX_RX_TYPE1_CATEGORY_NUM];
    unsigned char    port[MAX_RX_TYPE1_CATEGORY_NUM][MAX_RX_ANT_NUM];   
    unsigned char    dummy_param1[MAX_RX_TYPE1_CATEGORY_NUM];
    unsigned char    srx[MAX_RX_TYPE1_CATEGORY_NUM];
    unsigned char    dummy_param2[MAX_RX_TYPE1_CATEGORY_NUM];
} ERfTestRxType1CaInfo;

typedef struct
{
    unsigned char       total_route_num;
    unsigned char       padding;
    unsigned short      band;
    unsigned short      total_route_idx[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned short      comp_route_idx[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned char       FE_route_idx[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned char       port[MAX_RX_TYPE2_CATEGORY_NUM][2];
    unsigned char       dummy_param1[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned char       srx[MAX_RX_TYPE2_CATEGORY_NUM][MAX_RX_TYPE2_GBG_PATH_NUM];
    unsigned char       dummy_param2[MAX_RX_TYPE2_CATEGORY_NUM][MAX_RX_TYPE2_GBG_PATH_NUM];
} ERfTestRxType2CaInfo;

typedef struct
{
    ERfTestTxType1CaInfo     tx_type1_ca_info[ERF_MAX_BAND_NUM_V2];
    ERfTestRxType1CaInfo     rx_type1_ca_info[ERF_MAX_BAND_NUM_V2];
    ERfTestRxType2CaInfo     rx_type2_ca_info[ERF_MAX_BAND_NUM_V2];
} ERfTestTRxCaInfo;

typedef struct
{
    unsigned char    total_route_num;
    unsigned char    padding[3];
    unsigned short    band;
    unsigned short    route_idx[MAX_TX_TYPE1_CATEGORY_NUM];
} ERfTestTxCCARouteInfo, ERfTestTxFilterRouteInfo;

typedef struct
{
   unsigned char        total_band_num;
   ERfTestTxCCARouteInfo tx_cca_route_info[ERF_MAX_TX_CCA_BAND_NUM];
} ERfTestTxCCAInfo;

typedef struct
{
   unsigned char          total_band_num;
   ERfTestTxFilterRouteInfo    tx_filter_route_info[ERF_MAX_TX_BYPASS_BAND_NUM];
} ERfTestTxFILTERInfo;

typedef struct
{
    unsigned char    normal_used_tbl[MAX_RX_TYPE1_LNA_N_MODE_NUM];
    unsigned char    lpm_used_tbl[MAX_RX_TYPE1_LNA_N_MODE_NUM];
} ERfTestRXUsageType1Info;

typedef struct
{
    unsigned char    gbg_normal_used_tbl[MAX_RX_TYPE2_LNA_N_MODE_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM];
    unsigned char    gbg_lpm_used_tbl[MAX_RX_TYPE2_LNA_N_MODE_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM];
    unsigned char    partialon_normal_used_tbl[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE1_LNA_N_MODE_NUM];
    unsigned char    partialon_lpm_used_tbl[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE1_LNA_N_MODE_NUM];
} ERfTestRXUsageType2Info;

typedef struct
{
    ERfTestRXUsageType1Info    rx_type1_usagetbl;
    ERfTestRXUsageType2Info    rx_type2_usagetbl;
} ERfTestRXUsageInfo;

typedef struct
{
    short    normalmode_gain[MAX_RX_TYPE1_LNA_N_MODE_NUM][MAX_RX_ANT_NUM]; //[ Upper Bound, Lower Bound ]
    short    lpm_gain[MAX_RX_TYPE1_LNA_N_MODE_NUM][MAX_RX_ANT_NUM];
} ERfTestRXGainInfo;

typedef struct
{
    unsigned char  total_route_num;
    unsigned char  padding;
    unsigned short band;
    unsigned short total_route_idx[MAX_TX_TYPE1_CATEGORY_NUM];
    unsigned short comp_route_idx[MAX_TX_TYPE1_CATEGORY_NUM];
    unsigned char  port[MAX_TX_TYPE1_CATEGORY_NUM][LTE_PORT_ASCII_ARRAY_SIZE];
} ERfTestTxType1PortInfo;

typedef struct
{
    unsigned char  total_route_num;
    unsigned char  padding;
    unsigned short band;
    unsigned short total_route_idx[MAX_RX_TYPE1_CATEGORY_NUM];   
    unsigned short comp_route_idx[MAX_RX_TYPE1_CATEGORY_NUM];   
    unsigned char  port[MAX_RX_TYPE1_CATEGORY_NUM][MAX_RX_ANT_NUM][LTE_PORT_ASCII_ARRAY_SIZE];
} ERfTestRxType1PortInfo;

typedef struct
{
    unsigned char  total_route_num;
    unsigned char  padding;
    unsigned short band;
    unsigned short total_route_idx[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned short comp_route_idx[MAX_RX_TYPE2_CATEGORY_NUM];
    unsigned char  port[MAX_RX_TYPE2_CATEGORY_NUM][MAX_RX_ANT_NUM][LTE_PORT_ASCII_ARRAY_SIZE];
} ERfTestRxType2PortInfo;

typedef struct
{
    ERfTestTxType1PortInfo tx_type1_port_info[ERF_MAX_BAND_NUM_V2];
    ERfTestRxType1PortInfo rx_type1_port_info[ERF_MAX_BAND_NUM_V2];
    ERfTestRxType2PortInfo rx_type2_port_info[ERF_MAX_BAND_NUM_V2];
} ERfTestTRxPortInfo;

typedef struct
{
    unsigned char         eLNA_info[MAX_RX_ROUTE_NUM];
    unsigned short        band_mapping_info[ERF_BAND_MAPPING_TBL_SIZE];
    ERfTestTRxCaInfo      trx_ca_info;              
    ERfTestTxCCAInfo      tx_cca_info;
    ERfTestTxFILTERInfo   tx_filter_info;
    ERfTestRXUsageInfo    rx_usage_info;
    ERfTestRXGainInfo     rx_gain_info; 
    ERfTestTRxPortInfo    trx_band_port_info;
} ERfTestCmdCaConfig_V2;

typedef struct
{
    unsigned short band;
    unsigned char  rx_type1_num;
    unsigned char  rx_type2_num;
    unsigned char  tx_type1_num;
    unsigned char  rx_freq_num;
    unsigned char  tx_freq_num;
    unsigned char  padding;
} ERf_FHC_V2_Band_Usage_Param;

typedef struct
{
    unsigned char                 band_num;
    unsigned char                 padding;
    ERf_FHC_V2_Band_Usage_Param    band_usage[MAX_FHC_RX_TYPE1_CMD_NUM];
} ERf_FHC_V2_Band_Info_Param;

typedef struct
{
    unsigned short    route_idx;
    unsigned short    band;
    unsigned short    dl_freq[MAX_FHC_RX_FREQ_NUM_EX];
    short            temp_offset[MAX_TEMP_SECTION_NUM];
} ERf_FHC_V2_Rx_Type1_Cfg;

typedef struct
{
    unsigned short    route_idx;
    unsigned short    band;
    unsigned char     ant_mask;
    unsigned short    dl_freq[MAX_FHC_RX_FREQ_NUM_EX];
    short            temp_offset[MAX_TEMP_SECTION_NUM];
} ERf_FHC_V2_Rx_Type2_Cfg;

typedef struct
{
    unsigned short is_filter_path: 1; // 0: bypass path; 1: filter path
    unsigned short is_cca_setting: 1; // 0: non-CCA setting; 1: CCA setting
    unsigned short reserved      :14;
} ERfTestParamTxCfg;

typedef struct
{
    unsigned short  bandIndex;
    unsigned short  routeIndex;
    ERfTestParamTxCfg path_select;
    /* PA Control */
    unsigned char   paControlLevel; /* 2~8 */
    unsigned char   calRoomTempIdx;
    short          hysteresisStart0;
    short          hysteresisEnd0;
    short          hysteresisStart1;
    short          hysteresisEnd1;
    unsigned char   paMode[MAX_TX_PA_LEVEL_NUM]; /* 0:high, 1:middle, 2:low */
    short          pRf[MAX_TX_PA_LEVEL_NUM];
    unsigned short  paGain[MAX_TX_PA_LEVEL_NUM];
    unsigned char   dc2dcLevel[MAX_TX_PA_LEVEL_NUM]; /* voltage map by chip, TODO */
    unsigned short  vBiasDac[MAX_TX_PA_LEVEL_NUM];
    unsigned char   vm0[MAX_TX_PA_LEVEL_NUM];
    unsigned char   vm1[MAX_TX_PA_LEVEL_NUM];
    unsigned short  pa_gain_g12a;
    unsigned short  pa_gain_g12b;
    /* TX Compensation */
    unsigned short  ulFrequency[MAX_FHC_TX_FREQ_NUM_EX];//100kHz unit
    short   paGainSbWeight[MAX_TX_PA_MODE_NUM][MAX_TEMP_SECTION_NUM][MAX_FHC_TX_FREQ_NUM_EX];
    short   couplerLoss[MAX_TX_DET_MODE_NUM];
    short   powerDetector[MAX_TX_DET_MODE_NUM][MAX_TEMP_SECTION_NUM][MAX_FHC_TX_FREQ_NUM_EX];
} ERfTestCmdGetSetTpcSetting_V2;

typedef struct
{
    unsigned short              route_idx;
    unsigned short              band;
    unsigned short              tx_path_sel_bitmap;
    ERfTestCmdGetSetTpcSetting_V2 tpc_settings;
    unsigned char               freq_pwr_step_num[MAX_FHC_TX_FREQ_NUM_EX];
    unsigned char               pwr_step_pa_mode[MAX_TX_RPT_NUM_V2];
    short                      pwr_step_value[MAX_TX_RPT_NUM_V2]; 
    short                      pwr_step_pa_gain[MAX_TX_RPT_NUM_V2];
} ERf_FHC_V2_Tx_Type1_Cfg;

typedef struct
{
    unsigned char           switch_time;
    unsigned char           tx_rx_switch_time;  
    short                  gain_rxm[MAX_RX_LNA_TYPE_NUM][MAX_RX_TYPE2_LNA_MODE_NUM];
    short                  gain_rxd[MAX_RX_LNA_TYPE_NUM][MAX_RX_TYPE2_LNA_MODE_NUM];
    ERf_FHC_V2_Band_Info_Param band_info;
    ERf_FHC_V2_Rx_Type1_Cfg rx_type1_route[MAX_FHC_RX_TYPE1_CMD_NUM];
    ERf_FHC_V2_Rx_Type2_Cfg rx_type2_route[MAX_FHC_RX_TYPE2_CMD_NUM];
    ERf_FHC_V2_Tx_Type1_Cfg tx_type1_route[MAX_FHC_TX_TYPE1_CMD_NUM];
} ERf_FHC_V2_CaMode_Cmd;

typedef struct
{
    short                 txPowerDetectorValue[MAX_TX_RPT_NUM_V2];
} ERf_FHC_V2_Tx_Type1_Freq_Rpt;

typedef struct
{
    unsigned short             route_idx;
    unsigned short             band;
    unsigned short             tx_path_sel;
    unsigned char              tx_freq_num;
    unsigned char              padding;
    ERf_FHC_V2_Tx_Type1_Freq_Rpt tx_freq_rpt[MAX_FHC_TX_FREQ_NUM_EX];
} ERf_FHC_V2_Tx_Type1_Rpt;

typedef struct
{
    short partialOn[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE1_LNA_MODE_NUM];
    short lpm[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE2_LNA_L_MODE_NUM];
    short gainbygain[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM];
} ERf_FHC_V2_Rx_Type2_NCCA_Rpt;

typedef struct
{
    ERf_FHC_V2_Rx_Type2_NCCA_Rpt rssi_m;
    ERf_FHC_V2_Rx_Type2_NCCA_Rpt rssi_d;
} ERf_FHC_V2_Rx_Type2_Freq_Rpt;

typedef struct
{
    unsigned short             route_idx;
    unsigned short             band;
    unsigned char              rx_freq_num;
    unsigned char              padding;
    ERf_FHC_V2_Rx_Type2_Freq_Rpt rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
} ERf_FHC_V2_Rx_Type2_Rpt;

typedef struct
{
    short rssi_m[MAX_RX_TYPE1_LNA_MODE_NUM];
    short rssi_d[MAX_RX_TYPE1_LNA_MODE_NUM];
} ERf_FHC_V2_Rx_Type1_Freq_Rpt;

typedef struct
{
    unsigned short             route_idx;
    unsigned short             band;
    unsigned char              rx_freq_num;
    unsigned char              padding;
    ERf_FHC_V2_Rx_Type1_Freq_Rpt rx_freq_rpt[MAX_FHC_RX_FREQ_NUM_EX];
} ERf_FHC_V2_Rx_Type1_Rpt;

typedef struct
{
    unsigned short         rx_type1_route_num;
    unsigned short         rx_type2_route_num;
    unsigned short         tx_type1_route_num;
    ERf_FHC_V2_Rx_Type1_Rpt rx_type1_rpt[MAX_FHC_RX_TYPE1_REPORT_NUM];
    ERf_FHC_V2_Rx_Type2_Rpt rx_type2_rpt[MAX_FHC_RX_TYPE2_REPORT_NUM];
    ERf_FHC_V2_Tx_Type1_Rpt tx_type1_rpt[MAX_FHC_TX_TYPE1_REPORT_NUM];
} ERf_FHC_V2_CaMode_Rpt;

// Peer buffer of confirm: RX Type-2
typedef struct
{
    short   lna_mode_hpm[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE1_LNA_N_MODE_NUM];
    short   lna_mode_lpm[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE1_LNA_N_MODE_NUM];
} ERfRSSIGainOffsetTable_Type2a_V2;

typedef struct
{
    short   lna_mode_hpm[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM];
    short   lna_mode_lpm[MAX_RX_TYPE2_GBG_PATH_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM][MAX_RX_TYPE2_LNA_N_MODE_NUM];
} ERfRSSIGainOffsetTable_Type2b_V2;

typedef struct
{
    unsigned short  bandIndex;
    unsigned short  routeIndex;
    unsigned short  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type2a_V2 pathlossData_sc[MAX_RX_ANT_NUM][MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type2b_V2 pathlossData_gbg[MAX_RX_ANT_NUM][MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSITempOffsetTable_Ex pathlossTempComp;
} ERfRSSIBandGainTable_Type2_V2;

// Peer buffer of confirm: RX Type-1
typedef struct
{
    short   lna_mode_hpm[MAX_RX_TYPE1_LNA_N_MODE_NUM];  // loss of mode 0~5; resolution 1/32
    short   lna_mode_lpm[MAX_RX_TYPE1_LNA_N_MODE_NUM];  // loss of mode 0~5; resolution 1/32
} ERfRSSIGainOffsetTable_Type1_V2;

typedef struct
{
    unsigned short  bandIndex;
    unsigned short  routeIndex;
    unsigned short  subbandFrequency[MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSIGainOffsetTable_Type1_V2 pathlossData[MAX_RX_ANT_NUM][MAX_FHC_RX_FREQ_NUM_EX];
    ERfRSSITempOffsetTable_Ex pathlossTempComp;
} ERfRSSIBandGainTable_Type1_V2;

typedef struct
{
    unsigned short    route_index;
    ERfTestParamTxCfg  path_select;
} ERfTestParamRouteInfo;

// Local parameter of request
typedef struct
{
    unsigned short  rx_type1_route_num;
    unsigned short  rx_type2_route_num;
    unsigned short  tx_type1_route_num;
    unsigned short  rx_type1_route_index[MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM];
    unsigned short  rx_type2_route_index[MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM];
    ERfTestParamRouteInfo  tx_type1_route_index[MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM];
} ERfTestCmdGetRxTxSettingReqParam_T;

// Local parameter of confirm
typedef struct
{
    unsigned short  count;
    unsigned short  offset;
} ERfTestParamDynamicEntryElm;

typedef enum
{
    ERF_TEST_GET_RX_TX_STATUS_INVALID  = 0,
    ERF_TEST_GET_RX_TX_STATUS_OK       = 1,
    ERF_TEST_GET_RX_TX_STATUS_OVERFLOW = 2,  // request parameters exceed 50kB
    ERF_TEST_GET_RX_TX_STATUS_MAX      = 0xFFFF
}ERfTestGetRxTxSettingStatus;

typedef enum
{
    ERF_TEST_SET_RX_TX_STATUS_INVALID  = 0,
    ERF_TEST_SET_RX_TX_STATUS_OK       = 1,
    ERF_TEST_SET_RX_TYPE1_PARAM_ERROR  = 2,  // TX type-1 count/offset mismatch
    ERF_TEST_SET_RX_TYPE2_PARAM_ERROR  = 3,  // TX type-1 count/offset mismatch
    ERF_TEST_SET_TX_TYPE1_PARAM_ERROR  = 4,  // TX type-1 count/offset mismatch
    ERF_TEST_SET_RX_TX_STATUS_MAX      = 0xFFFF
}ERfTestSetRxTxSettingStatus;

typedef enum
{
    ERF_TEST_TPC_SET_STATUS_INVALID = 0,
    ERF_TEST_TPC_SET_STATUS_OK      = 1,  // set success
    ERF_TEST_TPC_SET_STATUS_ERR1    = 2,  // Not used, just aligned RX
    ERF_TEST_TPC_SET_STATUS_ERR2    = 3,  // subband frequency out of band region
    ERF_TEST_TPC_SET_STATUS_MAX,
}ERfTestTPCSetStatus;

typedef struct
{
    unsigned int                   result;
    ERfTestGetRxTxSettingStatus  get_status;
    ERfTestParamDynamicEntryElm  rx_type1_data;
    ERfTestParamDynamicEntryElm  rx_type2_data;
    ERfTestParamDynamicEntryElm  tx_type1_data;
} ERfTestResultGetRxTxSettingCnfParam_T;

typedef struct
{
   unsigned int                result;
   ERfTestSetRxTxSettingStatus   set_status;
   unsigned short              rx_type1_result_count;
   unsigned short              rx_type2_result_count;
   unsigned short              tx_type1_result_count;
   ERfTestRSSISetStatus         rx_type1_result[MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM];
   ERfTestRSSISetStatus         rx_type2_result[MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM];
   ERfTestTPCSetStatus          tx_type1_result[MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM];
}ERfTestResultSetRxTxSettingCnfParam_T;

typedef struct
{
    unsigned short  rx_type1_route_num;
    unsigned short  rx_type2_route_num;
    unsigned short  tx_type1_route_num;
    unsigned short  rx_type1_route_index[MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM];
    unsigned short  rx_type2_route_index[MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM];
    unsigned short  tx_type1_route_index[MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM];
    // RX TX data
    ERfRSSIBandGainTable_Type1_V2 rx_type1[MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM];
    ERfRSSIBandGainTable_Type2_V2 rx_type2[MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM];
    ERfTestCmdGetSetTpcSetting_V2 tx_type1[MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM];
} ERfTestCmdRxTxSetting;

typedef enum
{
   ERF_AFC_DATA_TYPE_USE_CAL_RESULT = 0, // use calibration data
   ERF_AFC_DATA_TYPE_USE_UI_SETTING = 1  // use setting in UI
}ERfTestAfcDataTypeE;

typedef struct
{
    unsigned short          band;
       unsigned short             routeidx;
      unsigned short          tx_path_sel_bitmap;
      unsigned short          ulFrequency;/* range: 0~65535 (100KHz unit) */
       unsigned char           capid;      /* 0 ~ 255 */
    unsigned short          afcdac;     /* 0 ~ 8191 */
      ERfTestAfcDataTypeE      afcDataType;
     unsigned short          txPowerValue;       /*S(8,8),  x dB * 256.0 */
} ERfTestCmdAfcSingleToneTxV2;

typedef enum
{
    ERF_FREQ_OFFSET_m540KHZ = 0xFFDC, // -36
    ERF_FREQ_OFFSET_m450KHZ = 0xFFE2, // -30
      ERF_FREQ_OFFSET_m360KHZ = 0xFFE8, // -24
       ERF_FREQ_OFFSET_m270KHZ = 0xFFEE, // -18
    ERF_FREQ_OFFSET_m180KHZ = 0xFFF4, // -12
      ERF_FREQ_OFFSET_m90KHZ  = 0xFFFA, // -6
     ERF_FREQ_OFFSET_ZERO    = 0x0000, // 0
     ERF_FREQ_OFFSET_p90KHZ  = 0x0006, // 6
    ERF_FREQ_OFFSET_p180KHZ = 0x000C, // 12
    ERF_FREQ_OFFSET_p270KHZ = 0x0012, // 18
       ERF_FREQ_OFFSET_p360KHZ = 0x0018, // 24
       ERF_FREQ_OFFSET_p450KHZ = 0x001E, // 30
      ERF_FREQ_OFFSET_p540KHZ = 0x0024, // 36
}ERfTestFreqOffsetE;

typedef enum
{
   ERF_TX_PA_MODE_HIGH = 0, 
   ERF_TX_PA_MODE_MID  = 1,
   ERF_TX_PA_MODE_LOW  = 2
}ERfTestTxPaModeE;

typedef enum
{
    ERF_PGAMODE_NORMAL = 0,
    ERF_PGAMODE_A = 1,
    ERF_PGAMODE_B = 2
} ERfTestPgaModeE;

typedef enum
{
   ERF_BW_6RB,   // 1.4 MHz
   ERF_BW_15RB,  //   3 MHz
   ERF_BW_25RB,  //   5 MHz
   ERF_BW_50RB,  //  10 MHz
   ERF_BW_75RB,  //  15 MHz
   ERF_BW_100RB, //  20 MHz
}ERfTestBwE;

typedef struct
{
    unsigned short  band;
    unsigned short  txRoute;
    unsigned short  tx_path_sel_bitmap;
    unsigned char   cc_num;
    unsigned short  ulFrequency[MAX_TX_CC_NUM];/* range: 0~65535 (100KHz unit) */
    ERfTestFreqOffsetE  ulFrequencyOffset;
    unsigned short      afcdac;
    ERfTestBwE          tx_bw[MAX_TX_CC_NUM];
    ERfTestPgaModeE     pga_mode;
    unsigned short      txPowerValue;        /* S(8,8), x dB * 256.0 */
    ERfTestAfcDataTypeE    afcDataType;
} ERfTestCmdTpcSingleToneTxV2;

typedef struct
{
    unsigned char       is_partialon;        // 0:No , 1:Yes
    unsigned char       num_freq;            // 1~15
    unsigned char       temperatureIndex;    // 0~7
    unsigned char       powermode;           // 0: ModeA (HPM), 1: ModeB (LPM)
    unsigned char       partial_on_path;
    unsigned char       ant_sel;
    unsigned short      band;
    unsigned short      dl_freq[MAX_FHC_RX_FREQ_NUM_EX];
    unsigned short      routeidx;
    short               gain0[MAX_RX_ANT_NUM];       /* resolution 1/32 */
    short               gain1[MAX_RX_ANT_NUM];       /* resolution 1/32 */
} ERfTestCmdRSSIV2;

typedef struct
{
    unsigned char   num_freq;
       unsigned short  dl_freq[MAX_FHC_RX_FREQ_NUM_EX];
      short           rssi_path0[MAX_RX_ANT_NUM][MAX_FHC_RX_FREQ_NUM_EX];
      unsigned char   lna_mode_path0[MAX_RX_ANT_NUM];
     short           rssi_path1[MAX_RX_ANT_NUM][MAX_FHC_RX_FREQ_NUM_EX];
      unsigned char   lna_mode_path1[MAX_RX_ANT_NUM];
} ERfTestResultRSSIV2CnfPdu;

typedef struct
{
   unsigned char       rx_cc_num;
   unsigned short      rx_freq[MAX_RX_CC_NUM_V2]; //frequency in 100kHz
   unsigned short      rx_band[MAX_RX_CC_NUM_V2]; //LTE BAND
   ERfTestBwE      rx_bw[MAX_RX_CC_NUM_V2];
} ErfContRxRfNormalMode;

typedef struct
{
   unsigned short   routeidx;     // judge type1 or type2
   unsigned char    is_partialon; // if type2, 0:No , 1:Yes
   unsigned char       partial_on_path;
   unsigned short      rx_freq;      // frequency in 100kHz
   unsigned short      rx_band;
   ERfTestBwE      rx_bw;
} ErfContRxRfForceMode;

typedef union
{
   ErfContRxRfForceMode      forcemode;
   ErfContRxRfNormalMode        normalmode;
} ErfContRx_Rf_Param;

typedef struct
{
    unsigned char             is_forcedmode;       // 0:No , 1:Yes
    ErfContRx_Rf_Param      contrx_param;
} ERfTestCmdContRxV2;

typedef struct
{
    unsigned char   rx_cc_num;
    unsigned short  rx_freq[MAX_RX_CC_NUM_V2]; 
    unsigned short  rx_band[MAX_RX_CC_NUM_V2]; 
    ERfTestBwE  rx_bw[MAX_RX_CC_NUM_V2];   
    unsigned char   tx_cc_num;
    unsigned short  tx_freq[MAX_TX_CC_NUM]; 
    unsigned short  tx_band[MAX_TX_CC_NUM]; 
    ERfTestBwE  tx_bw[MAX_TX_CC_NUM];
} ERfTestCmdGetTxRxRouteInfo;

typedef enum
{
    ERF_TEST_GET_TXRX_ROUTE_INFO_STATUS_INVALID    = 0,
    ERF_TEST_GET_TXRX_ROUTE_INFO_STATUS_OK         = 1,
    ERF_TEST_GET_TXRX_ROUTE_INFO_STATUS_ERR1    = 2,
    ERF_TEST_GET_TXRX_ROUTE_INFO_STATUS_ERR2    = 3,
    ERF_TEST_GET_TXRX_ROUTE_INFO_STATUS_MAX,
} ERfTestGetTxRxRouteInfoStatus;

typedef struct
{
    unsigned int  result;
    ERfTestGetTxRxRouteInfoStatus get_status;
} ERfTestResultGetTxRxRouteInfo;

typedef struct
{
       unsigned short      total_route_idx;   
       unsigned short      comp_route_idx;   
       unsigned short      FE_route_idx;
       unsigned char       port[MAX_RX_ANT_NUM][LTE_PORT_ASCII_ARRAY_SIZE];
       unsigned char       srx;
} ERfTestRxRouteInfo;

typedef struct
{
       unsigned short  total_route_idx;   
       unsigned short  comp_route_idx;   
       unsigned short  FE_route_idx;
      unsigned char   port[LTE_PORT_ASCII_ARRAY_SIZE];
       unsigned char   stx;
} ERfTestTxRouteInfo;

typedef struct
{
    unsigned char        get_status;
    ERfTestTxRouteInfo  tx_route_info[MAX_TX_CC_NUM];
    ERfTestRxRouteInfo     rx_route_info[MAX_RX_CC_NUM_V2];
} ERfTestResultGetTxRxRouteInfoCnfPdu;

/********************* MT6292 Structure Definitions *********************/

/********************* MT6293 Structure Definitions *********************/

/*******************************************************************************
 * ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE_V3
 ******************************************************************************/

typedef struct
{
   unsigned char   total_route_num;
   unsigned short  band;
   unsigned char   is_hrm[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];
   unsigned short  total_route_idx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];
   unsigned short  comp_route_idx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
   unsigned short  FE_route_idx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];
   unsigned char   port[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3][LTE_PORT_ASCII_ARRAY_SIZE];
   unsigned char   stx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];
} ERfTestTxType1CaInfoV3_T;

typedef struct
{
   unsigned char   total_route_num;
   unsigned char   padding;
   unsigned short  band;
   unsigned short  total_route_idx[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3];   //take considerate FE route + RFIC route
   unsigned short  comp_route_idx[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
   unsigned short  FE_route_idx[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3];
   unsigned char   port[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3][ERF_MAX_RX_ANT_NUM_V3][LTE_PORT_ASCII_ARRAY_SIZE];
   unsigned char   elna[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];
   unsigned char   srx[ERF_MAX_RX_TYPE1_CATEGORY_NUM_V3];
} ERfTestRxType1CaInfoV3_T;

typedef struct
{
   unsigned char   total_route_num;
   unsigned char   simultaneousl_k[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3];
   unsigned short  band;
   unsigned short  total_route_idx[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
   unsigned short  comp_route_idx[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
   unsigned char   FE_route_idx[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3];
   unsigned char   port[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3][ERF_MAX_RX_ANT_NUM_V3][LTE_PORT_ASCII_ARRAY_SIZE];
   unsigned char   elna[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];
   unsigned char   srx[ERF_MAX_RX_TYPE2_CATEGORY_NUM_V3][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3];//for SRX path0 & path1
} ERfTestRxType2CaInfoV3_T;

typedef struct
{
    ERfTestTxType1CaInfoV3_T     tx_type1_ca_info[ERF_MAX_BAND_NUM_V3];
    ERfTestRxType1CaInfoV3_T     rx_type1_ca_info[ERF_MAX_BAND_NUM_V3];
    ERfTestRxType2CaInfoV3_T     rx_type2_ca_info[ERF_MAX_BAND_NUM_V3];
} ERfTestTRxCaInfoV3_T;

typedef struct
{
   unsigned char   total_route_num;
   unsigned char   padding[3];
   unsigned short  band;
   unsigned short  route_idx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
} ERfTestTxCCARouteInfoV3_T;

typedef struct
{
   unsigned char               total_band_num;
   ERfTestTxCCARouteInfoV3_T    tx_cca_route_info[ERF_MAX_TX_CCA_BAND_NUM_V3];
} ERfTestTxCCAInfoV3_T;

typedef struct
{
   unsigned char   total_route_num;
   unsigned char   padding[3];
   unsigned short  band;
   unsigned short  route_idx[ERF_MAX_TX_TYPE1_CATEGORY_NUM_V3];//take considerate FE route + RFIC route
} ERfTestTxFilterRouteInfoV3_T;

typedef struct
{
   unsigned char                 total_band_num;
   ERfTestTxFilterRouteInfoV3_T    tx_filter_route_info[ERF_MAX_TX_BYPASS_BAND_NUM_V3];
} ERfTestTxFILTERInfoV3_T;

typedef enum
{
   ERF_TEST_RX_HPM            = 0,
   ERF_TEST_RX_LPM            = 1,
   ERF_TEST_RX_POWER_MODE_NUM,
   ERF_TEST_RX_POWER_MODE_MAX =  0xFF
} ERfTestRxPowerMode_E;


typedef struct
{
   unsigned char   seq_num[ERF_TEST_RX_POWER_MODE_NUM];
   short          dlpow_default[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   short          dlpow_lbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   short          dlpow_hbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   unsigned char   dlpow_lna_mode[ERF_MAX_RX_ANT_NUM_V3][ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
   unsigned char   dlpow_elna_bypass[ERF_MAX_RX_ANT_NUM_V3][ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];//1:bypass(elna off)
   unsigned char   nvram_idx[ERF_MAX_RX_ANT_NUM_V3][ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
} ERfTestElnaInfoT1V3_T;

typedef struct
{
   unsigned char   gbg_seq_num[ERF_TEST_RX_POWER_MODE_NUM];
   short          gbg_dlpow_default[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];// resolution 1/32
   short          gbg_dlpow_lbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];// resolution 1/32
   short          gbg_dlpow_hbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];// resolution 1/32
   unsigned char   gbg_dlpow_lna_mode[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];
   unsigned char   gbg_dlpow_elna_bypass[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];
   unsigned char   gbg_nvram_idx[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];
   unsigned char   sc_seq_num[ERF_TEST_RX_POWER_MODE_NUM];
   short          sc_dlpow_default[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   short          sc_dlpow_lbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   short          sc_dlpow_hbound[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];// resolution 1/32
   unsigned char   sc_dlpow_lna_mode[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
   unsigned char   sc_dlpow_elna_bypass[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
   unsigned char   sc_nvram_idx[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
} ERfTestElnaInfoT2V3_T;

typedef struct
{
   ERfTestElnaInfoT1V3_T      elna_info_t1[ERF_MAX_RX_ELNA_TYPE_V3][ERF_MAX_RX_ELNA_TYPE_V3];
   ERfTestElnaInfoT2V3_T      elna_info_t2[ERF_MAX_RX_ELNA_TYPE_V3];// T2 can't use different ELNA type for rx path
} ERfTestElnaCalInfoV3_T;

typedef struct
{
    unsigned short         band_mapping_info[ERF_BAND_MAPPING_TBL_SIZE];
    ERfTestTRxCaInfoV3_T    trx_ca_info;
    ERfTestTxCCAInfoV3_T    tx_cca_info;
    ERfTestTxFILTERInfoV3_T tx_filter_info;
    ERfTestElnaCalInfoV3_T  elna_cal_info;
} ERfTestCmdCaConfig_V3;

/*******************************************************************************
 * ERF_TEST_CMD_GET_RX_TX_SETTING_V3
 ******************************************************************************/

typedef struct
{
    short lna_mode_lpm;
    short lna_mode_hpm;
} ERfRxPLRAWData_V3_T;

typedef struct
{
    short   temp_comp[MAX_TEMP_SECTION_NUM];
} ERfRxTempOffsetTable_V3_T;

typedef struct
{
    ERfRxPLRAWData_V3_T    pathloss_raw[ERF_MAX_RX_LNA_MODE_NUM_V3];
} ERfRxPLSubband_Type1_V3_T;

typedef struct
{
    unsigned short               bandIndex;
    unsigned short               routeIndex;
    unsigned short               subbandFrequency[ERF_MAX_FHC_RX_FREQ_NUM_V3];
    ERfRxPLSubband_Type1_V3_T     pathlossData[ERF_MAX_FHC_RX_FREQ_NUM_V3][ERF_MAX_RX_ANT_NUM_V3/*0: RXM, 1: RXD*/];
    ERfRxTempOffsetTable_V3_T     pathlossTempComp;
} ERfRSSIBandGainTable_Type1_V3;

typedef struct
{
    ERfRxPLRAWData_V3_T           pathloss_raw_sc[MAX_RX_TYPE2_GBG_PATH_NUM][ERF_MAX_RX_LNA_MODE_NUM_V3];
} ERfRxPLSubband_Type2A_V3_T;

typedef struct
{
    ERfRxPLRAWData_V3_T           pathloss_raw_gbg[MAX_RX_TYPE2_GBG_PATH_NUM][ERF_MAX_RX_LNA_MODE_NUM_V3][ERF_MAX_RX_LNA_MODE_NUM_V3];
} ERfRxPLSubband_Type2B_V3_T;

typedef struct
{
    ERfRxPLSubband_Type2A_V3_T    pathlossData_sc;
    ERfRxPLSubband_Type2B_V3_T    pathlossData_gbg;
} ERfRxPLSubband_Type2_V3_T;

typedef struct
{
    unsigned short               bandIndex;
    unsigned short               routeIndex;
    unsigned short               subbandFrequency[ERF_MAX_FHC_RX_FREQ_NUM_V3];
    ERfRxPLSubband_Type2_V3_T     pathlossData[ERF_MAX_FHC_RX_FREQ_NUM_V3][ERF_MAX_RX_ANT_NUM_V3/*0: RXM, 1: RXD*/];
    ERfRxTempOffsetTable_V3_T     pathlossTempComp;
} ERfRSSIBandGainTable_Type2_V3;

typedef struct
{
    unsigned short        bandIndex;
    unsigned short        routeIndex;
    ERfTestParamTxCfg     path_select;
    /* PA Control */
    unsigned char         paControlLevel; /* 2~8 */
    unsigned char         calRoomTempIdx;
    short                hysteresisStart0;
    short                hysteresisEnd0;
    short                hysteresisStart1;
    short                hysteresisEnd1;
    unsigned char         paMode[MAX_TX_PA_LEVEL_NUM];
    short                pRf[MAX_TX_PA_LEVEL_NUM];
    unsigned short        paGain[MAX_TX_PA_LEVEL_NUM];
    unsigned char         dc2dcLevel[MAX_TX_PA_LEVEL_NUM]; /* voltage map by chip, TODO */
    unsigned short        vBiasDac[MAX_TX_PA_LEVEL_NUM];
    unsigned short        pa_gain_g12a;
    unsigned short        pa_gain_g12b;

    /* TX Compensation */
    unsigned short        ulFrequency[ERF_MAX_FHC_TX_FREQ_NUM_V3];//100kHz unit
    short                paGainSbWeight[MAX_TX_PA_MODE_NUM][MAX_TEMP_SECTION_NUM][ERF_MAX_FHC_TX_FREQ_NUM_V3];
    short                couplerLoss[MAX_TX_DET_MODE_NUM];
    short                powerDetector[MAX_TX_DET_MODE_NUM][MAX_TEMP_SECTION_NUM][ERF_MAX_FHC_TX_FREQ_NUM_V3];
} ERfTestCmdGetSetTpcSetting_V3;

typedef struct
{
    unsigned short                rx_type1_route_num;
    unsigned short                rx_type2_route_num;
    unsigned short                tx_type1_route_num;
    unsigned short                rx_type1_route_index[ERF_MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
    unsigned short                rx_type2_route_index[ERF_MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM_V3];
    ERfTestParamRouteInfo          tx_type1_route_index[ERF_MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
} ERfTestCmdGetRxTxSettingV3ReqParam_T;

typedef struct
{
    unsigned int                   result;
    ERfTestGetRxTxSettingStatus  get_status;
    ERfTestParamDynamicEntryElm  rx_type1_data;
    ERfTestParamDynamicEntryElm  rx_type2_data;
    ERfTestParamDynamicEntryElm  tx_type1_data;
} ERfTestResultGetRxTxSettingV3CnfParam_T;

typedef struct
{
   unsigned int                result;
   ERfTestSetRxTxSettingStatus   set_status;
   unsigned short              rx_type1_result_count;
   unsigned short              rx_type2_result_count;
   unsigned short              tx_type1_result_count;
   ERfTestRSSISetStatus         rx_type1_result[ERF_MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
   ERfTestRSSISetStatus         rx_type2_result[ERF_MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM_V3];
   ERfTestTPCSetStatus          tx_type1_result[ERF_MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
} ERfTestResultSetRxTxSettingV3CnfParam_T;

typedef struct
{
    unsigned short  rx_type1_route_num;
    unsigned short  rx_type2_route_num;
    unsigned short  tx_type1_route_num;
    unsigned short  rx_type1_route_index[ERF_MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
    unsigned short  rx_type2_route_index[ERF_MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM_V3];
    unsigned short  tx_type1_route_index[ERF_MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
    // RX TX data
    ERfRSSIBandGainTable_Type1_V3 rx_type1[ERF_MAX_RX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
    ERfRSSIBandGainTable_Type2_V3 rx_type2[ERF_MAX_RX_TYPE2_CAL_DATA_ACCESS_NUM_V3];
    ERfTestCmdGetSetTpcSetting_V3 tx_type1[ERF_MAX_TX_TYPE1_CAL_DATA_ACCESS_NUM_V3];
} ERfTestCmdRxTxSettingV3;

/*******************************************************************************
 * ERF_TEST_CMD_START_FHC_V3
 ******************************************************************************/
typedef struct
{
    unsigned short                    band;
    unsigned char                     rx_type1_num;
    unsigned char                     rx_type2_num;
    unsigned char                     tx_type1_num;
    unsigned char                     rx_freq_num;
    unsigned char                     tx_freq_num;
    unsigned char                     padding;
} FHC_V3_Band_Usage_Param_T;

typedef struct
{
    unsigned char                     band_num;
    unsigned char                     padding;
    FHC_V3_Band_Usage_Param_T          band_usage[ERF_MAX_FHC_BAND_CMD_NUM_V3];    // Max band support
} FHC_V3_Band_Info_Param_T;

typedef struct
{
    unsigned short                    route_idx;
    unsigned short                    band;
    unsigned short                     ant_mask;
    unsigned short                    dl_freq [ERF_MAX_FHC_RX_FREQ_NUM_V3];
    short                            temp_offset[MAX_TEMP_SECTION_NUM];
    unsigned char                     rx_cal_step[ERF_TEST_RX_POWER_MODE_NUM];
    short                            dl_power[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
} FHC_V3_Rx_Type1_Cfg_T;

typedef struct
{
    unsigned short                    route_idx;
    unsigned short                    band;
    unsigned short                    ant_mask;
    unsigned short                    dl_freq [ERF_MAX_FHC_RX_FREQ_NUM_V3];
    short                            temp_offset[MAX_TEMP_SECTION_NUM];
    unsigned char                     sc_rx_cal_step[ERF_TEST_RX_POWER_MODE_NUM];
    short                            sc_dl_power[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
    unsigned char                     gbg_rx_cal_step[ERF_TEST_RX_POWER_MODE_NUM];
    short                            gbg_dl_power[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];
} FHC_V3_Rx_Type2_Cfg_T;

typedef struct
{
    unsigned short                    route_idx;
    unsigned short                    band;
    unsigned short                    tx_path_sel_bitmap;
    unsigned char                     pwr_step_num_at_freq[ERF_MAX_FHC_TX_FREQ_NUM_V3];
    unsigned char                     pwr_step_pa_mode[MAX_TX_RPT_NUM_V3];
    short                            pwr_step_value[MAX_TX_RPT_NUM_V3]; //target Power (PRF)
    short                            pwr_step_pa_gain[MAX_TX_RPT_NUM_V3];
    ERfTestCmdGetSetTpcSetting_V3      tpc_settings;
} FHC_V3_Tx_Type1_Cfg_T;

typedef struct
{
    unsigned char                     switch_time;//ms unit
    unsigned char                     tx_rx_switch_time;//ms unit
    FHC_V3_Band_Info_Param_T            band_info;
    FHC_V3_Rx_Type1_Cfg_T              rx_type1_route [ERF_MAX_FHC_RX_TYPE1_CMD_NUM_V3];
    FHC_V3_Rx_Type2_Cfg_T              rx_type2_route [ERF_MAX_FHC_RX_TYPE2_CMD_NUM_V3];
    FHC_V3_Tx_Type1_Cfg_T              tx_type1_route [ERF_MAX_FHC_TX_TYPE1_CMD_NUM_V3];
} ERfTestCmd_StartFhcV3_Req_T;

typedef struct
{
   short                 txPowerDetectorValue[MAX_TX_RPT_NUM_V3];
} FHC_V3_Tx_Type1_Freq_Rpt_T;

typedef struct
{
   unsigned short                 route_idx;
   unsigned short                 band;
   unsigned short                 tx_path_sel_bitmap;
   unsigned char                  tx_freq_num;
   FHC_V3_Tx_Type1_Freq_Rpt_T tx_freq_rpt[ERF_MAX_FHC_TX_FREQ_NUM_V3];
} FHC_V3_Tx_Type1_Rpt_T;

typedef struct
{
   short                 sc[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
   short                 gbg[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_TYPE2_SEQ_NUM_V3];
} FHC_V3_Rx_Type2_NCCA_Rpt_T;

typedef struct
{
   FHC_V3_Rx_Type2_NCCA_Rpt_T   rssi_m;
   FHC_V3_Rx_Type2_NCCA_Rpt_T   rssi_d;
} FHC_V2_Rx_Type2_Freq_Rpt_T;

typedef struct
{
   unsigned short                 route_idx;
   unsigned short                 band;
   unsigned char                  rx_freq_num;
   FHC_V2_Rx_Type2_Freq_Rpt_T rx_freq_rpt[ERF_MAX_FHC_RX_FREQ_NUM_V3];
} FHC_V3_Rx_Type2_Rpt_T;

typedef struct
{
   short                  rssi_m[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
   short                  rssi_d[ERF_TEST_RX_POWER_MODE_NUM][ERF_MAX_RX_TYPE1_SEQ_NUM_V3];
} FHC_V3_Rx_Type1_Freq_Rpt_T;

typedef struct
{
   unsigned short                 route_idx;
   unsigned short                 band;
   unsigned char                  rx_freq_num;
   FHC_V3_Rx_Type1_Freq_Rpt_T rx_freq_rpt[ERF_MAX_FHC_RX_FREQ_NUM_V3];
} FHC_V3_Rx_Type1_Rpt_T;

typedef struct
{
    unsigned short               rx_type1_route_num;
    unsigned short               rx_type2_route_num;
    unsigned short               tx_type1_route_num;
    FHC_V3_Rx_Type1_Rpt_T    rx_type1_rpt[ERF_MAX_FHC_RX_TYPE1_REPORT_NUM_V3];
    FHC_V3_Rx_Type2_Rpt_T    rx_type2_rpt[ERF_MAX_FHC_RX_TYPE2_REPORT_NUM_V3];
    FHC_V3_Tx_Type1_Rpt_T    tx_type1_rpt[ERF_MAX_FHC_TX_TYPE1_REPORT_NUM_V3];
} ERfTestCmd_StartFhcV3_Cnf_T;

/*******************************************************************************
 * ERF_TEST_CMD_START_RSSI_V3
 ******************************************************************************/

typedef struct
{
   unsigned char    elna_bypass[ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
   short            rf_gain[ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
   short            digital_gain[ERF_MAX_RX_ANT_NUM_V3];
}ERfStartRssiV3_Sc_RxInput_T;

typedef struct
{
   unsigned char    elna_bypass[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
   short            rf_gain[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
   short            digital_gain[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];
}ERfStartRssiV3_Gbg_RxInput_T;

typedef union
{
   ERfStartRssiV3_Sc_RxInput_T  sc_rxinput;
   ERfStartRssiV3_Gbg_RxInput_T gbg_rxinput;
}ERfStartRssiV3_RxInput_U;

typedef union
{
    unsigned short          in_100khz;
    // for GP tool
    // ERfTestDlFrequency_E    in_enum;
}ERfTestDlFrequency_U;

typedef struct
{
   ERfTestRxPowerMode_E     powermode;
   ERfTestDlFrequency_U     dl_freq[MAX_RX_RFTOOL_FERQ_NUM];
   unsigned char            is_partialon;        // 0:No , 1:Yes
   unsigned char 	        num_freq;            // 1~15
   unsigned char  	        temperatureIndex;    // 0~7
   unsigned char  	        partialon_path;
   unsigned char 	        ant_sel;
   unsigned short  	        band;
   unsigned short           routeidx;
   ERfStartRssiV3_RxInput_U rssi_start_input;
} ERfTestCmd_StartRssiV3_ReqParam_T;


typedef struct
{
    short           rssi[MAX_RX_RFTOOL_FERQ_NUM][ERF_MAX_RX_ANT_NUM_V3];
    unsigned char   lna_mode[ERF_MAX_RX_ANT_NUM_V3];
}ERfStartRssiV3_Sc_RxOutput_T;

typedef struct
{
   short            rssi[MAX_RX_RFTOOL_FERQ_NUM][ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];/* resolution 1/32 */
   unsigned char    lna_mode[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];
}ERfStartRssiV3_gbg_RxOutput_T;

typedef union
{
    ERfStartRssiV3_Sc_RxOutput_T    sc_rxoutput;
    ERfStartRssiV3_gbg_RxOutput_T   gbg_rxoutput;
}ERfStartRssiV3_RxOutput_U;

typedef struct
{
   unsigned char                num_freq;
   unsigned short               dl_freq[MAX_RX_RFTOOL_FERQ_NUM];
   ERfStartRssiV3_RxOutput_U    rssi_start_output;
} ERfTestCmd_StartRssiV3_CnfPdu_T;

META_RESULT __stdcall META_ERf_StartRssiV3(const unsigned int ms_timeout, const ERfTestCmd_StartRssiV3_ReqParam_T* req, ERfTestCmd_StartRssiV3_CnfPdu_T* cnf);
META_RESULT __stdcall META_ERf_StartRssiV3_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmd_StartRssiV3_ReqParam_T* req, ERfTestCmd_StartRssiV3_CnfPdu_T* cnf);
/*******************************************************************************
 * ERF_TEST_CMD_GET_RX_GAIN_INFO_V3
 ******************************************************************************/

typedef enum
{
    ERF_TEST_GET_RX_Gain_INFO_STATUS_INVALID = 0,
    ERF_TEST_GET_RX_Gain_INFO_STATUS_OK      = 1,  // get success
    ERF_TEST_GET_RX_Gain_INFO_STATUS_ERR     = 2,  // can not search coverage gain for this combination
    ERF_TEST_GET_RX_Gain_INFO_STATUS_MAX,
}ERfTestGetRxGainInfoV3Status;

typedef struct
{
    unsigned char   elna_bypass[ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
    unsigned char   lna_mode[ERF_MAX_RX_ANT_NUM_V3];
}ERfTestGetRxGainInfoV3_Sc_RxInput_T;

typedef struct
{
    unsigned char   elna_bypass[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3];// 0:No , 1:Yes
    unsigned char   lna_mode[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3];
}ERfTestGetRxGainInfoV3_Gbg_RxInput_T;

typedef union
{
    ERfTestGetRxGainInfoV3_Sc_RxInput_T  sc_rxinput;
    ERfTestGetRxGainInfoV3_Gbg_RxInput_T gbg_rxinput;
}ERfTestGetRxGainInfoV3_RxInput_U;

typedef struct
{
    ERfTestRxPowerMode_E                powermode;
    unsigned char                       ant_sel;
    unsigned short                      routeidx;
    unsigned char                       is_partialon;     // 0:No , 1:Yes
    ERfTestGetRxGainInfoV3_RxInput_U    rxgaininfo_input;
}ERfTestCmd_GetRxGainInfoV3_ReqParam_T;


typedef struct
{
    short   rf_gain[ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
    short   digital_gain[ERF_MAX_RX_ANT_NUM_V3];
}ERfTestGetRxGainInfoV3_Sc_RxOutput_T;

typedef struct
{
    short   rf_gain[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];/* resolution 1/32 */
    short   digital_gain[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];/* resolution 1/32 */
}ERfTestGetRxGainInfoV3_Gbg_RxOutput_T;

typedef union
{
    ERfTestGetRxGainInfoV3_Sc_RxOutput_T    sc_rxoutput;
    ERfTestGetRxGainInfoV3_Gbg_RxOutput_T   gbg_rxoutput;
}ERfTestGetRxGainInfoV3_RxOutput_U;

typedef struct
{
   short    dl_power;
   ERfTestGetRxGainInfoV3_RxOutput_U    rxgaininfo_output;
}ERfTestCmd_GetRxGainInfoV3_CnfPdu_T;

META_RESULT __stdcall META_ERf_GetRxGainInfoV3(const unsigned int ms_timeout, const ERfTestCmd_GetRxGainInfoV3_ReqParam_T* req, ERfTestCmd_GetRxGainInfoV3_CnfPdu_T* cnf);
META_RESULT __stdcall META_ERf_GetRxGainInfoV3_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmd_GetRxGainInfoV3_ReqParam_T* req, ERfTestCmd_GetRxGainInfoV3_CnfPdu_T* cnf);
/*******************************************************************************
 * ERF_TEST_CMD_START_CONT_RX_V3
 ******************************************************************************/

typedef struct
{
    unsigned char   elna_bypass[ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
    short           rf_gain[ERF_MAX_RX_ANT_NUM_V3];/* resolution 1/32 */
}ERfContRxV3_Sc_RxInput_T;

typedef struct
{
    unsigned char    elna_bypass[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];// 0:No , 1:Yes
    short            rf_gain[ERF_MAX_RX_TYPE2_GBG_PATH_NUM_V3][ERF_MAX_RX_ANT_NUM_V3];/* resolution 1/32 */
}ERfContRxV3_Gbg_RxInput_T;

typedef union
{
    ERfContRxV3_Sc_RxInput_T  sc_rxinput;
    ERfContRxV3_Gbg_RxInput_T gbg_rxinput;
}ERfStartContRxV3_RxInput_U;

typedef struct
{
    ERfTestRxPowerMode_E        powermode;
    unsigned short              routeidx;
    unsigned char               is_partialon;                 //  0:No , 1:Yes
    unsigned char               partialon_path;
    ERfStartContRxV3_RxInput_U  cont_rx_input;
    ERfTestDlFrequency_U        rx_freq;                      // frequency in 100kHz
    unsigned short              rx_band;
    ERfTestBwE                  rx_bw;
}ErfContRxRfForcedMode_T;

typedef struct
{
    ERfTestRxPowerMode_E    powermode;
    unsigned char           rx_cc_num;
    ERfTestDlFrequency_U    rx_freq[ERF_MAX_RX_CC_NUM_V3]; //frequency in 100kHz
    unsigned short          rx_band[ERF_MAX_RX_CC_NUM_V3]; //LTE BAND
    ERfTestBwE              rx_bw[ERF_MAX_RX_CC_NUM_V3];
}ErfContRxRfNormalMode_T;

typedef union
{
    ErfContRxRfForcedMode_T   forcedmode;
    ErfContRxRfNormalMode_T   normalmode;
} ErfContRx_Rf_Param_U;

typedef struct
{
   unsigned char        is_forcedmode;       // 0:No , 1:Yes
   ErfContRx_Rf_Param_U contrx_param;
} ERfTestCmd_StartContRxV3_ReqParam_T;

META_RESULT __stdcall META_ERf_StartContRxV3(const unsigned int ms_timeout, const ERfTestCmd_StartContRxV3_ReqParam_T* req);
META_RESULT __stdcall META_ERf_StartContRxV3_r(const int meta_handle, const unsigned int ms_timeout, const  ERfTestCmd_StartContRxV3_ReqParam_T* req);
/********************* MT6293 Structure Definitions *********************/
META_RESULT __stdcall META_ERf_AfcSingleToneTx_V2(const unsigned int ms_timeout, const ERfTestCmdAfcSingleToneTxV2* req);
META_RESULT __stdcall META_ERf_AfcSingleToneTx_V2_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdAfcSingleToneTxV2* req);


META_RESULT __stdcall META_ERf_TpcSingleToneTx_V2(const unsigned int ms_timeout, const ERfTestCmdTpcSingleToneTxV2* req);
META_RESULT __stdcall META_ERf_TpcSingleToneTx_V2_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdTpcSingleToneTxV2* req);

META_RESULT __stdcall META_ERf_Rssi_V2(const unsigned int ms_timeout, const ERfTestCmdRSSIV2* req, ERfTestResultRSSIV2CnfPdu* cnf);
META_RESULT __stdcall META_ERf_Rssi_V2_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdRSSIV2* req, ERfTestResultRSSIV2CnfPdu* cnf);

META_RESULT __stdcall META_ERf_ContRx_V2(const unsigned int ms_timeout, const ERfTestCmdContRxV2* req);
META_RESULT __stdcall META_ERf_ContRx_V2_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdContRxV2* req);

META_RESULT __stdcall META_ERf_GetTxRxRouteInfo(const unsigned int ms_timeout, const ERfTestCmdGetTxRxRouteInfo* req, ERfTestResultGetTxRxRouteInfoCnfPdu* cnf);
META_RESULT __stdcall META_ERf_GetTxRxRouteInfo_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdGetTxRxRouteInfo* req, ERfTestResultGetTxRxRouteInfoCnfPdu* cnf);
typedef struct
{
    unsigned char   band;
#define ERF_TX_TEST_COMMAND_CONFIG_TDD 0
#define ERF_TX_TEST_COMMAND_CONFIG_FDD 1
    unsigned char   duplexMode;
    unsigned char   tddConfig;
    unsigned char   tddSfConfig;
    unsigned short  ulFrequency;
    unsigned short  cellId;
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_6RB 0
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_15RB 1
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_25RB 2
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_50RB 3
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_75RB 4
#define ERF_TX_TEST_COMMAND_CONFIG_UL_BANDWIDTH_100RB 5
    unsigned char   ulBandwidth;
    unsigned char   vrbStart;
    unsigned char   vrbLength;
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_QPSK 0
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_16QAM 1
#define ERF_TX_TEST_COMMAND_CONFIG_PUSCH_MSC_64QAM 2
    unsigned char   mcsMode;
    unsigned char   txPowerMode;
    short           txPowerValue;
    unsigned char   networkSelection;
    unsigned char   txCloseLoopDisbl;
    unsigned char   amprEnbl;
    short           bbBackoff;
    unsigned char   rfGain;
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_HIGH 0
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_MIDDLE 1
#define ERF_TX_TEST_COMMAND_CONFIG_PA_MODE_LOW 2
    unsigned char   paMode;
    unsigned char   paVcc; 
    unsigned char   vm0;
    unsigned char   vm1;
    unsigned short   txRoute;
    unsigned char   enableMultiCluster;
    unsigned char   multiClusterVrbStart;
    unsigned char   multiClustervrbLength;
    unsigned char   enableCsr;
    unsigned short  dlFrequency;
#define ERF_TX_TEST_COMMAND_CONFIG_BYPASS_NONCAA_MODE 0
#define ERF_TX_TEST_COMMAND_CONFIG_FILTER_NONCAA_MODE 1
#define ERF_TX_TEST_COMMAND_CONFIG_BYPASS_CAA_MODE 2
#define ERF_TX_TEST_COMMAND_CONFIG_FILTER_CAA_MODE 3
    unsigned short  txPathSelBitmap;
} ERfTestCmdPuschTxV2Param;

typedef struct
{
     unsigned char   ulCCNum;
     short   afcdac;
     ERfTestCmdPuschTxV2Param   puschTxParam[MAX_TX_CC_NUM];     
} ERfTestCmdPuschTxV2;

META_RESULT __stdcall META_ERf_TxPusch_V2( const unsigned int ms_timeout, const ERfTestCmdPuschTxV2* req, unsigned int* pSyncStatus );
META_RESULT __stdcall META_ERf_TxPusch_V2_r( const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdPuschTxV2* req, unsigned int* pSyncStatus );

typedef struct
{
    unsigned char    band;
    unsigned char    duplexMode;
    unsigned char    tddConfig;
    unsigned char    tddSfConfig;
    unsigned short   ulFrequency;
    unsigned short   cellId;
    short            afcdac;
    unsigned char    ulBandwidth;
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1 0
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1A 1
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_1B 2
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2 3
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2_CPACK 4
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2A 5
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_2B 6
#define ERF_TX_TEST_COMMAND_CONFIG_PUCCH_FORMAT_3 7
    unsigned char    format;
    short            txPowerValue;
    unsigned char    networkSelection;
    unsigned char    txCloseLoopDisbl;
    unsigned char    amprEnbl;
    unsigned short   txRoute;
    unsigned short   txPathSelBitmap;
} ERfTestCmdPucchTxV2;
META_RESULT __stdcall META_ERf_TxPucch_V2( const unsigned int ms_timeout, const ERfTestCmdPucchTxV2* req );
META_RESULT __stdcall META_ERf_TxPucch_V2_r( const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdPucchTxV2* req );

typedef struct
{
    unsigned char    band;
    unsigned char    duplexMode;    /* 0: tdd, 1: fdd */
    unsigned short   ulFrequency;
    unsigned short   cellId;
    unsigned char    tddCsSrsBwCfg;
    short            txPowerValue;
    unsigned char    networkSelection;
    unsigned char    txCloseLoopDisbl;
    unsigned char    amprEnbl;
    unsigned short   txRoute;
    unsigned short   txPathSelBitmap;
} ERfTestCmdSrsTxV2Param;

typedef struct
{
    unsigned char   ulCCNum;
    short   afcdac;
    ERfTestCmdSrsTxV2Param   srsTxParam[MAX_TX_CC_NUM];     
} ERfTestCmdSrsTxV2;

META_RESULT __stdcall META_ERf_TxSrs_V2( const unsigned int ms_timeout, const ERfTestCmdSrsTxV2* req );
META_RESULT __stdcall META_ERf_TxSrs_V2_r( const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdSrsTxV2* req );

typedef struct
{
    unsigned char   band;
    unsigned short  ulFrequency;
    unsigned short  cellId;
    short           afcdac;
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_FDD_TIME_MASK 0
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_TDD_TIME_MASK 1
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_FDD_EVM 2
#define ERF_TX_TEST_COMMAND_CONFIG_PRACH_CONFIG_INDEX_TDD_EVM 3
    unsigned char   configIndex;
    short           txPowerValue;
    unsigned char   networkSelection;
    unsigned char   txCloseLoopDisbl;
    unsigned char   amprEnbl;
    unsigned short  txRoute;
    unsigned short  txPathSelBitmap;
} ERfTestCmdPrachTxV2;

META_RESULT __stdcall META_ERf_TxPrach_V2( const unsigned int ms_timeout, const ERfTestCmdPrachTxV2* req );
META_RESULT __stdcall META_ERf_TxPrach_V2_r( const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdPrachTxV2* req );

typedef struct
{
   /*Common parameters*/
   unsigned char            measCnt;//range 0~10
   unsigned char            measBandwidth;
   unsigned short           dlFrequency;//range: 7280~26900 (100KHz unit)
   unsigned char            band;//range 1~40
   unsigned char            duplexMode;
   unsigned char            tddConfig;//range 0~7
   unsigned char            tddSfConfig;//range 0~8
   unsigned char            bandwidth;
   unsigned short           rxRoute;
   unsigned short           routePathSel;   /* 0: bypass path, 1: filter path */

   /*Pseudo Tx-Rx only*/
   bool                    hasUl;
   unsigned short           ulFrequency;//range: 7280~26900 (100KHz unit)
   unsigned short            txPowerValue;/*S(8,8)*/
   unsigned char            vrbStart;
   unsigned char            vrbLength;
   unsigned char            mcsMode;
   unsigned short           txRoute;
}Mix_Rx_Dl_Ul_Ca_Normal_Mode_Param;

typedef struct
{
   unsigned char                   mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx
   unsigned short                  afcdac;
   unsigned char                   rxPath0Enbl;
   unsigned char                   rxPath1Enbl;
   unsigned char                   numOfDlCC;
   unsigned char                   numOfUlCC;
   Mix_Rx_Dl_Ul_Ca_Normal_Mode_Param mix_rx_dl_ul_ca_normal_mode_param[MAX_RX_CC_NUM_V2];
}Mix_Rx_Dl_Ul_Ca_Normal_Mode;

typedef struct
{
   unsigned char            mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx
   unsigned char            measCnt;//range 0~10
   unsigned char            measBandwidth;
   unsigned short           dlFrequency;//range: 7280~26900 (100KHz unit)
   unsigned char            band;//range 1~40
   unsigned char            duplexMode;
   unsigned char            tddConfig;//range 0~7
   unsigned char            tddSfConfig;//range 0~8
   unsigned char            bandwidth;
   unsigned char            rxPath0Enbl;
   unsigned char            rxPath1Enbl;
   unsigned char            rxRoute;
   unsigned short           routePathSel;   /* 0: bypass path, 1: filter path */
}Mix_Rx_Force_Mode;

typedef union
{
   Mix_Rx_Dl_Ul_Ca_Normal_Mode   mix_rx_dl_ul_ca_normal_mode;
   Mix_Rx_Force_Mode            mix_rx_force_mode;
} Mix_Rx_Dl_Ul_Ca_Mode;

typedef struct
{
   unsigned char       opMode; //0: normal mode, 1: force mode
   Mix_Rx_Dl_Ul_Ca_Mode MixRxCaModeV2Param;
} ERfTestCmdMixRx_CaMode_V2;

META_RESULT __stdcall META_ERf_StartMixRx_CaMode_V2( const unsigned int ms_timeout, ERfTestCmdMixRx_CaMode_V2* req );
META_RESULT __stdcall META_ERf_StartMixRx_CaMode_V2_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdMixRx_CaMode_V2* req);

typedef struct
{
    unsigned char measRptCnt[MAX_RX_CC_NUM_V2];//range 0~10
    short rssiPath0[MAX_RX_CC_NUM_V2][10];//final format is TBD
    short rssiPath1[MAX_RX_CC_NUM_V2][10];//final format is TBD
    short rsrpPath0[MAX_RX_CC_NUM_V2][10];//final format is TBD
    short rsrpPath1[MAX_RX_CC_NUM_V2][10];//final format is TBD
    short rsrqPath0[MAX_RX_CC_NUM_V2][10];//final format is TBD
    short rsrqPath1[MAX_RX_CC_NUM_V2][10];//final format is TBD

    unsigned int crcOK_cnt[MAX_RX_CC_NUM_V2];
    unsigned int crcNG_cnt[MAX_RX_CC_NUM_V2];
} ERfTestCmdGetMixRxRpt_CaMode_V2;

META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode_V2( const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode_V2* resp );
META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode_V2_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode_V2* resp );
/**
 * \brief non-reentrant version of META_ERf_QueryCaConfigTableV2_r
 */ 
META_RESULT  __stdcall META_ERf_QueryCaConfigTableV2( const unsigned int ms_timeout, ERfTestCmdCaConfig_V2* resp);
/**
 * \details To get ca config table from target
 * \param meta_handle meta handle
 * \param ms_timeout: time out in ms
 * \param resp RX ca usage table
 * \sa ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE_V2
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_QueryCaConfigTableV2_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdCaConfig_V2* resp);

/**
 * \brief non-reentrant version of META_ERf_FHC_CaModeV2_r
 */
META_RESULT  __stdcall META_ERf_FHC_CaModeV2( const ERf_FHC_V2_CaMode_Cmd* req, const unsigned int ms_timeout, ERf_FHC_V2_CaMode_Rpt* resp );
/**
 * \details Command target to execute CA mode FHC arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req CA mode FHC arrangements
 * \param ms_timeout time out in ms
 * \param resp RSSI results and PD values acquired from target
 * \sa ERF_TEST_CMD_START_FHC
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_FHC_CaModeV2_r( const int meta_handle, const ERf_FHC_V2_CaMode_Cmd* req, const unsigned int ms_timeout, ERf_FHC_V2_CaMode_Rpt* resp );

/**
 * \brief non-reentrant version of META_ERf_GetRxTxSetting_r
 */
META_RESULT  __stdcall META_ERf_GetRxTxSetting( const ERfTestCmdGetRxTxSettingReqParam_T* req, const unsigned int ms_timeout, ERfTestCmdRxTxSetting* resp );
/**
 * \details Command target to execute reading TX and RX calibration data and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX and RX route information
 * \param ms_timeout time out in ms
 * \param resp TX and RX calibration data acquired from target
 * \sa ERF_TEST_CMD_GET_RX_TX_SETTING_V2
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetRxTxSetting_r( const int meta_handle, const ERfTestCmdGetRxTxSettingReqParam_T* req, const unsigned int ms_timeout, ERfTestCmdRxTxSetting* resp );

/**
 * \brief non-reentrant version of META_ERf_SetRxTxSetting_r
 */
META_RESULT  __stdcall META_ERf_SetRxTxSetting( const bool& update_to_nvram, const ERfTestCmdRxTxSetting* req, const unsigned int ms_timeout, ERfTestResultSetRxTxSettingCnfParam_T* resp );
/**
 * \details Command target to execute writing TX and RX calibration data and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX and RX calibration data
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_RX_TX_SETTING_V2
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetRxTxSetting_r( const int meta_handle, const bool& update_to_nvram, const ERfTestCmdRxTxSetting* req, const unsigned int ms_timeout, ERfTestResultSetRxTxSettingCnfParam_T* resp );


/**
 * \brief non-reentrant version of META_ERf_QueryCaConfigTableV3_r
 */ 
META_RESULT  __stdcall META_ERf_QueryCaConfigTableV3( const unsigned int ms_timeout, ERfTestCmdCaConfig_V3* resp);
/**
 * \details To get ca config table from target
 * \param meta_handle meta handle
 * \param ms_timeout: time out in ms
 * \param resp RX ca usage table
 * \sa ERF_TEST_CMD_QUERY_CA_CONFIG_TABLE_V3
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_QueryCaConfigTableV3_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdCaConfig_V3* resp);
/**
 * \brief non-reentrant version of META_ERf_FHC_CaModeV3_r
 */
META_RESULT  __stdcall META_ERf_FHC_CaModeV3( const ERfTestCmd_StartFhcV3_Req_T* req, const unsigned int ms_timeout, ERfTestCmd_StartFhcV3_Cnf_T* resp );
/**
 * \details Command target to execute CA mode FHC arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req CA mode FHC arrangements
 * \param ms_timeout time out in ms
 * \param resp RSSI results and PD values acquired from target
 * \sa ERF_TEST_CMD_START_FHC
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_FHC_CaModeV3_r( const int meta_handle, const ERfTestCmd_StartFhcV3_Req_T* req, const unsigned int ms_timeout, ERfTestCmd_StartFhcV3_Cnf_T* resp);

/**
 * \brief non-reentrant version of META_ERf_GetRxTxSetting_r
 */
META_RESULT  __stdcall META_ERf_GetRxTxSettingV3( const ERfTestCmdGetRxTxSettingV3ReqParam_T* req, const unsigned int ms_timeout, ERfTestCmdRxTxSettingV3* resp );
/**
 * \details Command target to execute reading TX and RX calibration data and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX and RX route information
 * \param ms_timeout time out in ms
 * \param resp TX and RX calibration data acquired from target
 * \sa ERF_TEST_CMD_GET_RX_TX_SETTING_V3
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_GetRxTxSettingV3_r( const int meta_handle, const ERfTestCmdGetRxTxSettingV3ReqParam_T* req, const unsigned int ms_timeout, ERfTestCmdRxTxSettingV3* resp );

/**
 * \brief non-reentrant version of META_ERf_SetRxTxSetting_r
 */
META_RESULT  __stdcall META_ERf_SetRxTxSettingV3( const bool& update_to_nvram, const ERfTestCmdRxTxSettingV3* req, const unsigned int ms_timeout, ERfTestResultSetRxTxSettingV3CnfParam_T* resp );
/**
 * \details Command target to execute writing TX and RX calibration data and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX and RX calibration data
 * \param ms_timeout time out in ms
 * \sa ERF_TEST_CMD_SET_RX_TX_SETTING_V3
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_SetRxTxSettingV3_r( const int meta_handle, const bool& update_to_nvram, const ERfTestCmdRxTxSettingV3* req, const unsigned int ms_timeout, ERfTestResultSetRxTxSettingV3CnfParam_T* resp );

typedef struct
{
   unsigned char                   mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx
   unsigned char                   rxPath0Enbl;
   unsigned char                   rxPath1Enbl;
   unsigned char                   numOfDlCC;
   unsigned char                   numOfUlCC;
   Mix_Rx_Dl_Ul_Ca_Normal_Mode_Param mix_rx_dl_ul_ca_normal_mode_param[MAX_RX_CC_NUM_V2];
}Mix_Rx_Dl_Ul_Ca_Normal_Mode_V3;

typedef union
{
   Mix_Rx_Dl_Ul_Ca_Normal_Mode_V3   mix_rx_dl_ul_ca_normal_mode;
   Mix_Rx_Force_Mode               mix_rx_force_mode;
} Mix_Rx_Dl_Ul_Ca_Mode_V3;

typedef struct
{
   unsigned char       opMode; //0: normal mode, 1: force mode
   Mix_Rx_Dl_Ul_Ca_Mode_V3 MixRxCaModeV3Param;
} ERfTestCmdMixRx_CaMode_V3;

META_RESULT __stdcall META_ERf_StartMixRx_CaMode_V3( const unsigned int ms_timeout, ERfTestCmdMixRx_CaMode_V3* req );
META_RESULT __stdcall META_ERf_StartMixRx_CaMode_V3_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdMixRx_CaMode_V3* req);

META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode_V3( const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode_V2* resp );
META_RESULT __stdcall META_ERf_GetMixRxReport_CaMode_V3_r( const int meta_handle, const unsigned int ms_timeout, ERfTestCmdGetMixRxRpt_CaMode_V2* resp );

/***********************
 *     LTE TX NSFT
 ***********************/

// NSFT TX power step arrange type 0
typedef struct
{
#define MAX_NSFT_LIST_TX_PWR_STEP_NUM 8
    unsigned char    pwr_step_num;///<0~8;
    short            pwr_step_tx_power[MAX_NSFT_LIST_TX_PWR_STEP_NUM];///<S(8,8)
    unsigned char    pwr_step_VRB_strt[MAX_NSFT_LIST_TX_PWR_STEP_NUM];
    unsigned char    pwr_step_VRB_len[MAX_NSFT_LIST_TX_PWR_STEP_NUM];
} ERf_NSFT_List_Tx_Specify_Pwr_Param;
// NSFT TX power step arrange type 1
typedef struct
{
    short            start_power;///<S(8,8)
    short            pwr_step_value;///<S(8,8)
    unsigned char    pwr_step_num;
    unsigned char    pwr_step_VRB_strt_p1; ///<start VRB for the first period
    unsigned char    pwr_step_VRB_len_p1;
    unsigned char    pwr_step_VRB_strt_p2; ///<start VRB for the second period
    unsigned char    pwr_step_VRB_len_p2;
    unsigned char    step_for_change_tx_VRB; ///<0: Tx VRB will be changed to p2 at step 0
} ERf_NSFT_List_Tx_Specify_Step_Param;
// NSFT TX frequency step setting
typedef struct
{
    unsigned short   ul_freq;///<100kHz unit
    unsigned char    ul_bw;///<0(1.4M)~5(20M)
    unsigned char    pwr_step_MCS_mode; ///<0:QPSK, 1:16QAM, 2:64QAM
    char             cmd_type;     ///<0: NSFT_List_Tx_Specify_Pwr_Param, 1: NSFT_List_Tx_Specify_Step_Param
    union
    {
        ERf_NSFT_List_Tx_Specify_Pwr_Param     specify_tx_pwr_cmd;
        ERf_NSFT_List_Tx_Specify_Step_Param    specify_pwr_step_cmd;
    };
} ERf_NSFT_List_Tx_Freq_Param;
// NSFT TX band step setting
typedef struct
{
    unsigned char    band_index;
    unsigned char    freq_num;
    unsigned short   dl_sync_freq;///<100kHz unit
#define MAX_NSFT_LIST_TX_FREQ_NUM 13
    ERf_NSFT_List_Tx_Freq_Param     freq_param[MAX_NSFT_LIST_TX_FREQ_NUM];
} ERf_NSFT_List_Tx_Band_Param;
// NSFT TX configure
typedef struct
{
    unsigned char    fdd_tx_step_width;///<ms unit
    unsigned char    tdd_tx_step_width;///<ms unit
    unsigned char    band_num;
#define MAX_NSFT_LIST_TX_BAND_NUM 10
    ERf_NSFT_List_Tx_Band_Param     band_param[MAX_NSFT_LIST_TX_BAND_NUM];
    short            freq_offst;///<range -32768~32767
    short            afc_dac;
    unsigned char    afc_data_type;///<0: calibration data, 1: from interface value
    unsigned char    close_loop_disable;
} ERf_NSFT_List_Tx_Cfg;

// NSFT TX command
typedef struct
{
    unsigned char           phy_cell_id;///<no used for single tone?
    unsigned char           fdd_band_start_index;
    unsigned char           fdd_band_end_index;
    unsigned char           tdd_band_start_index;
    unsigned char           tdd_band_end_index;
    unsigned char           fdd_to_tdd_switch_time;///<ms unit
    unsigned char           fdd_freq_switch_time;///<ms unit
    unsigned char           tdd_freq_switch_time;///<ms unit
    unsigned char           fdd_band_switch_time;///<ms unit
    unsigned char           tdd_band_switch_time;///<ms unit
    unsigned short          fdd_dl_sync_time;///<ms unit
    unsigned short          tdd_dl_sync_time;///<ms unit
    ERf_NSFT_List_Tx_Cfg    txCmd;
} ERf_NSFT_List_Cmd;
/**
 * \brief non-reentrant version of META_ERf_Start_TxNsft_r
 */
META_RESULT  __stdcall META_ERf_Start_TxNsft( const ERf_NSFT_List_Cmd* req, const unsigned int ms_timeout, unsigned int* p_iTxNsftStatus );
/**
 * \details Command target to execute TX NSFT arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX NSFT arrangements
 * \param ms_timeout time out in ms
 * \param p_iTxNsftStatus: the pointer point to a space to store TX NSFT status
 * \sa ERF_TEST_CMD_START_NSFT_LIST
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_Start_TxNsft_r( const int meta_handle, const ERf_NSFT_List_Cmd* req, const unsigned int ms_timeout, unsigned int* p_iTxNsftStatus );
typedef struct
{
    unsigned short   ul_freq;///<100kHz unit
    unsigned char    ul_bw;///<0(1.4M)~5(20M)
    unsigned char    pwr_step_MCS_mode; ///<0:QPSK, 1:16QAM, 2:64QAM
    char             cmd_type;     ///<0: NSFT_List_Tx_Specify_Pwr_Param, 1: NSFT_List_Tx_Specify_Step_Param
    union
    {
        ERf_NSFT_List_Tx_Specify_Pwr_Param     specify_tx_pwr_cmd;
        ERf_NSFT_List_Tx_Specify_Step_Param    specify_pwr_step_cmd;
    };
    unsigned char    signal_path;  /// 0:normal path 1:hrm path 2: filter path
} ERf_NSFT_List_Tx_Freq_Ex_Param;
// NSFT TX band step setting
typedef struct
{
    unsigned char    band_index;
    unsigned char    freq_num;
    unsigned short   dl_sync_freq;///<100kHz unit
#define MAX_NSFT_LIST_TX_FREQ_NUM 13
    ERf_NSFT_List_Tx_Freq_Ex_Param     freq_param[MAX_NSFT_LIST_TX_FREQ_NUM];
} ERf_NSFT_List_Tx_Band_Ex_Param;
// NSFT TX configure
typedef struct
{
    unsigned char    fdd_tx_step_width;///<ms unit
    unsigned char    tdd_tx_step_width;///<ms unit
    unsigned char    band_num;
#define MAX_NSFT_LIST_TX_BAND_NUM 10
    ERf_NSFT_List_Tx_Band_Ex_Param     band_param[MAX_NSFT_LIST_TX_BAND_NUM];
    short            freq_offst;///<range -32768~32767
    short            afc_dac;
    unsigned char    afc_data_type;///<0: calibration data, 1: from interface value
    unsigned char    close_loop_disable;
} ERf_NSFT_List_Tx_Ex_Cfg;

// NSFT TX command
typedef struct
{
    unsigned char       phy_cell_id;///<no used for single tone?
    unsigned char       fdd_band_start_index;
    unsigned char       fdd_band_end_index;
    unsigned char       tdd_band_start_index;
    unsigned char       tdd_band_end_index;
    unsigned char       fdd_to_tdd_switch_time;///<ms unit
    unsigned char       fdd_freq_switch_time;///<ms unit
    unsigned char       tdd_freq_switch_time;///<ms unit
    unsigned char       fdd_band_switch_time;///<ms unit
    unsigned char       tdd_band_switch_time;///<ms unit
    unsigned short      fdd_dl_sync_time;///<ms unit
    unsigned short      tdd_dl_sync_time;///<ms unit
    ERf_NSFT_List_Tx_Ex_Cfg    txCmd;
} ERf_NSFT_List_Ex_Cmd;
META_RESULT  __stdcall META_ERf_Start_TxNsftWithSignalPath_r( const int meta_handle, const ERf_NSFT_List_Ex_Cmd* req, const unsigned int ms_timeout, unsigned int* p_iTxNsftStatus );
/**
 * \brief non-reentrant version of META_ERf_Start_TxNsft_Ex_r
 */
META_RESULT  __stdcall META_ERf_Start_TxNsftWithSignalPath( const ERf_NSFT_List_Ex_Cmd* req, const unsigned int ms_timeout, unsigned int* p_iTxNsftStatus );
/**
 * \details Command target to execute TX NSFT arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX NSFT arrangements
 * \param ms_timeout time out in ms
 * \param p_iTxNsftStatus: the pointer point to a space to store TX NSFT status
 * \sa ERF_TEST_CMD_START_NSFT_LIST
 * \retval META_SUCCESS successful
 **/
typedef struct
{
    unsigned short  tx_route_idx;
    unsigned short  routePathSel;
} ERf_NSFT_List_RxTx_Tx_Route_Info; 
typedef struct
{
    unsigned short ul_freq;             //100kHz unit
    unsigned short dl_freq;             //100kHz unit 
    unsigned char  ul_bw;               //0(1.4M)~5(20M)
    unsigned char  pwr_step_MCS_mode;   //0: QPSK, 1:16QAM, 2:64QAM
    char           cmd_type;            //0: NSFT_List_RxTx_Specify_Pwr_Param, 1: NSFT_List_RxTx_Specify_Step_Param      
    union
    {
        ERf_NSFT_List_Tx_Specify_Pwr_Param     specify_tx_pwr_cmd;
        ERf_NSFT_List_Tx_Specify_Step_Param    specify_pwr_step_cmd;
    };
} ERf_NSFT_List_RxTx_Freq_Param;
typedef struct
{
    unsigned short tx_route_num;
#define MAX_NSFT_LIST_TX_ROUTE_NUM         8
    ERf_NSFT_List_RxTx_Tx_Route_Info tx_route_path_info[MAX_NSFT_LIST_TX_ROUTE_NUM];
    unsigned short rx_route_num;
#define MAX_NSFT_LIST_RX_ROUTE_NUM         8
    unsigned short rx_route_idx[MAX_NSFT_LIST_RX_ROUTE_NUM];
    unsigned short rx_step_num;
#define MAX_NSFT_LIST_RXTX_PWR_LEVEL_NUM   5
    unsigned short rx_step_width[MAX_NSFT_LIST_RXTX_PWR_LEVEL_NUM];
    ERf_NSFT_List_RxTx_Freq_Param rxtx_freq_param;
} ERf_NSFT_List_RxTx_Freq; 
typedef struct
{
    unsigned char  band_index;
    unsigned short dl_sync_freq; 
    unsigned char  freq_num;
#define MAX_NSFT_LIST_RXTX_FREQ_NUM        8
    ERf_NSFT_List_RxTx_Freq freq_param[MAX_NSFT_LIST_RXTX_FREQ_NUM];         
} ERf_NSFT_List_RxTx_Band_Param;
typedef struct
{ 
    unsigned char  fdd_tx_step_width;      //ms unit
    unsigned char  tdd_tx_step_width;      //ms unit
    unsigned short freq_offst;             //range -32768~32767
    unsigned short afc_dac;
    unsigned char  afc_data_type;          //0: calibration data, 1: from interface value
    unsigned char  close_loop_disable;
    unsigned char  band_num;
#define MAX_NSFT_LIST_RXTX_BAND_NUM        8
    ERf_NSFT_List_RxTx_Band_Param band_param[MAX_NSFT_LIST_RXTX_BAND_NUM];
} ERf_NSFT_List_RxTx_Cfg;
typedef struct
{
    unsigned char  op_mode;                 //0: only tx, 1: tx-rx list mode
    unsigned char  phy_cell_id;
    unsigned char  fdd_band_start_index; 
    unsigned char  fdd_band_end_index;
    unsigned char  tdd_band_start_index;
    unsigned char  tdd_band_end_index;
    unsigned char  fdd_to_tdd_switch_time;  //ms unit
    unsigned char  fdd_freq_switch_time;    //ms unit
    unsigned char  tdd_freq_switch_time;    //ms unit
    unsigned char  fdd_band_switch_time;    //ms unit
    unsigned char  tdd_band_switch_time;    //ms unit
    unsigned short fdd_dl_sync_time;        //ms unit
    unsigned short tdd_dl_sync_time;        //ms unit
    ERf_NSFT_List_RxTx_Cfg rxtxCmd; 
} ERf_NSFT_List_RxTx_Cmd;
typedef struct
{
    short          rssiPath0;
    short          rssiPath1;
    short          rsrpPath0;
    short          rsrpPath1;
    short          rsrqPath0;
    short          rsrqPath1;
    unsigned short crcOK_cnt;
    unsigned short crcNG_cnt;
} ERf_NSFT_List_Rx_Step_Rpt;
typedef struct
{
    unsigned char route_idx;
    unsigned char rx_step_num;
#define MAX_NSFT_LIST_RXTX_PWR_LEVEL_NUM   5
    ERf_NSFT_List_Rx_Step_Rpt rx_step[MAX_NSFT_LIST_RXTX_PWR_LEVEL_NUM];
} ERf_NSFT_List_Rx_Route_Rpt;
typedef struct
{
    unsigned char freq_idx;
    unsigned char rx_route_num;
#define MAX_NSFT_LIST_TX_ROUTE_NUM         8
    ERf_NSFT_List_Rx_Route_Rpt rx_route[MAX_NSFT_LIST_RX_ROUTE_NUM];
} ERf_NSFT_List_Rx_Freq_Rpt;
typedef struct
{
    unsigned char band_idx;
    unsigned char freq_num;
#define MAX_NSFT_LIST_RXTX_FREQ_NUM       8
    ERf_NSFT_List_Rx_Freq_Rpt freq[MAX_NSFT_LIST_RXTX_FREQ_NUM];
} ERf_NSFT_List_Rx_Band_Rpt;
typedef struct
{
    unsigned short bandIndex;
    unsigned short dlFreq;
    unsigned short ulFreq;
    unsigned short pci;
    unsigned char  reSyncCnt;
    unsigned char  rxPath0Enbl;
    unsigned char  rxPath1Enbl;
} ERf_NSFT_List_Rx_Error_Rpt;
typedef struct
{ 
    unsigned int  status;
    unsigned char band_num;
#define MAX_NSFT_LIST_RXTX_BAND_NUM        8
    ERf_NSFT_List_Rx_Band_Rpt  band[MAX_NSFT_LIST_RXTX_BAND_NUM];
    ERf_NSFT_List_Rx_Error_Rpt error_report;
} ERf_NSFT_List_RxTx_Rpt;
/**
 * \brief non-reentrant version of META_ERf_Start_TrxNsft_r
 */
META_RESULT  __stdcall META_ERf_Start_TrxNsft( const ERf_NSFT_List_RxTx_Cmd* req, const unsigned int ms_timeout, ERf_NSFT_List_RxTx_Rpt* resp );
/**
 * \details Command target to execute TX NSFT arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX NSFT arrangements
 * \param ms_timeout time out in ms
 * \param p_iTxNsftStatus: the pointer point to a space to store TX NSFT status
 * \sa ERF_TEST_CMD_START_NSFT_RXTX_LIST
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_Start_TrxNsft_r( const int meta_handle, const ERf_NSFT_List_RxTx_Cmd* req, const unsigned int ms_timeout, ERf_NSFT_List_RxTx_Rpt* resp );
typedef struct
{ 
    short          freq_offst;             //range -32768~32767
    unsigned char  close_loop_disable;
    unsigned char  band_num;
#define MAX_NSFT_LIST_RXTX_BAND_NUM        8
    ERf_NSFT_List_RxTx_Band_Param band_param[MAX_NSFT_LIST_RXTX_BAND_NUM];
} ERf_NSFT_List_RxTx_V3_Cfg;
typedef struct
{ 
    unsigned char  fdd_band_start_index;
    unsigned char  fdd_band_end_index;
    unsigned char  tdd_band_start_index;
    unsigned char  tdd_band_end_index;
    unsigned short fdd_dl_sync_time;        //ms unit
    unsigned short tdd_dl_sync_time;        //ms unit
    unsigned char  fdd_to_tdd_switch_time;  //ms unit
    unsigned char  fdd_freq_switch_time;    //ms unit
    unsigned char  tdd_freq_switch_time;    //ms unit
    unsigned char  fdd_band_switch_time;    //ms unit
    unsigned char  tdd_band_switch_time;    //ms unit
    unsigned char  fdd_tx_step_width;       //ms unit
    unsigned char  tdd_tx_step_width;       //ms unit
    unsigned char  reserved;
} ERf_NSFT_List_RxTx_V3_scheduling_Setting;
typedef struct
{
    unsigned char  op_mode;                 //0: only tx, 1: tx-rx list mode
    unsigned char  phy_cell_id;
    ERf_NSFT_List_RxTx_V3_scheduling_Setting  schdlSetting;
    ERf_NSFT_List_RxTx_V3_Cfg                 rxtxCmd;
} ERf_NSFT_List_RxTx_V3_Cmd; 
/**
 * \brief non-reentrant version of META_ERf_Start_TrxNsftV3_r
 */
META_RESULT  __stdcall META_ERf_Start_TrxNsftV3( const ERf_NSFT_List_RxTx_V3_Cmd* req, const unsigned int ms_timeout, ERf_NSFT_List_RxTx_Rpt* resp );
/**
 * \details Command target to execute TX NSFT arrangements and blocking until result returns
 * \param meta_handle meta handle
 * \param req TX NSFT arrangements
 * \param ms_timeout time out in ms
 * \param p_iTxNsftStatus: the pointer point to a space to store TX NSFT status
 * \sa ERF_TEST_CMD_START_NSFT_RXTX_LIST_V3
 * \retval META_SUCCESS successful
 **/
META_RESULT  __stdcall META_ERf_Start_TrxNsftV3_r( const int meta_handle, const ERf_NSFT_List_RxTx_V3_Cmd* req, const unsigned int ms_timeout, ERf_NSFT_List_RxTx_Rpt* resp );

typedef META_Rf_TemperatureInfo_T META_ERf_TemperatureInfo_T;

META_RESULT __stdcall META_ERf_GetTemperatureInfo(const unsigned int ms_timeout, META_ERf_TemperatureInfo_T* info);
META_RESULT __stdcall META_ERf_GetTemperatureInfo_r(const int meta_handle, const unsigned int ms_timeout, META_ERf_TemperatureInfo_T* info);
/**
 * \details get the LTE RF chip ID name by given RF chip ID
 * \param id LTE RF chip ID
 * \return constant pointer to the RF chip ID name
 */
const char* __stdcall META_ERf_GetRfChipIdName(unsigned int id);
const char* __stdcall META_ERf_GetRfChipIdName_r( const int meta_handle, unsigned int id);
META_RESULT __stdcall META_ERf_SetPathFlag(const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetPathFlag_r(const int meta_handle, const unsigned int ms_timeout);
#define MAX_ERF_ET_NUM_BAND 14
#define MAX_ERF_ET_NUM_SUBBAND 8
#define MAX_ERF_ET_NUM_CBW 6
#define MAX_ERF_ET_NUM_VIN 33
typedef struct
{
    unsigned char band;
    unsigned char bandwidth;
    short txPower;
    unsigned short ulFrequency;
} ERfEtTxSetting;
typedef struct
{
    short output_vpa_voltage;
} ERfEtFdModeSetting;
typedef struct
{
    unsigned short mode; ///< ET:0 FD:1 Bypass:2
    short outer_gain;
    short input_offset_voltage;
    short main_sw_output_voltage;
    short aux_sw_output_voltage;
} ERfEtSpModeSetting;
typedef struct
{
    unsigned short et_mode; ///< ET:0 FD:1 static performance mode:2
    ERfEtTxSetting tx_setting;
    ERfEtFdModeSetting fd_mode_setting;
    ERfEtSpModeSetting sp_mode_setting;
} ERfEtModeSetting;
META_RESULT __stdcall META_ERf_SetEtMode(ERfEtModeSetting* req, const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetEtMode_r(const int meta_handle, ERfEtModeSetting* req , const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_StartEtCal(const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_StartEtCal_r(const int meta_handle, const unsigned int ms_timeout);
typedef struct
{
    unsigned short VinVpaLut[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_VIN];
    short          VinPmLut[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_VIN];
    short          VinAmLut[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_VIN];
    short          PathDelay[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_CBW];
    short          Pout_max[MAX_ERF_ET_NUM_SUBBAND];
    short          Pout_gain_offset[MAX_ERF_ET_NUM_SUBBAND];
    unsigned short GainComp_0p5_dB;
    unsigned short GainComp_0p5_dB_delta;
    unsigned short PathDelayOffsetByTemp[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_CBW];
    short          GrpDlyOfstBySubband[MAX_ERF_ET_NUM_SUBBAND][MAX_ERF_ET_NUM_CBW];
    unsigned short VpaTargetStep2;
    unsigned short SmpValStep2Sec1;
    short          PaGainAdjustStep1;
    unsigned int   PowThrdStep2;
} ERfEtCalSetting;
META_RESULT __stdcall META_ERf_GetEtCalSetting(const unsigned short bandIdx, const unsigned int ms_timeout, ERfEtCalSetting* etCalSetting);
META_RESULT __stdcall META_ERf_GetEtCalSetting_r(const int meta_handle, const unsigned short bandIdx, const unsigned int ms_timeout, ERfEtCalSetting* etCalSetting);
META_RESULT __stdcall META_ERf_SetEtCalSetting(const unsigned short bandIdx, const ERfEtCalSetting* etCalSetting, const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetEtCalSetting_r(const int meta_handle, const unsigned short bandIdx, const ERfEtCalSetting* etCalSetting, const unsigned int ms_timeout);
/**
 * \brief non-reentrant version of META_ERf_SetToolUsage_r
 */
META_RESULT __stdcall META_ERf_SetToolUsage(const unsigned short tool_usage, const unsigned int ms_timeout);
/**
 * \details set the tool usage mode for L1
 * \param meta_handle meta handle
 * \param tool_usage 1:Normal mode 2:Calibration mode 3: ET Calibration mode
 * \param ms_timeout time out in ms
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_ERf_SetToolUsage_r(const int meta_handle, const unsigned short tool_usage, const unsigned int ms_timeout);
typedef struct
{
    unsigned short  CmdType;
    unsigned char   BandIndex;
} ERfNVRAMInfoReq;
typedef struct
{
    unsigned short LID;    // Logical data item ID of a EF
    unsigned short RID;    // Record ID (the first record is 1)
} ERfNVRAMInfoElement;
typedef struct
{
    unsigned char        item_count;    // Query result count
    unsigned char        status;       // 0: read ok; others: read failed.
    ERfNVRAMInfoElement   nvramElement[255];
} ERfNVRAMInfoCnf;
META_RESULT __stdcall META_ERf_QueryNVRAMInfo(const ERfNVRAMInfoReq* req, const unsigned int ms_timeout, ERfNVRAMInfoCnf* cnf);
META_RESULT __stdcall META_ERf_QueryNVRAMInfo_r(const int meta_handle, const ERfNVRAMInfoReq* req, const unsigned int ms_timeout, ERfNVRAMInfoCnf* cnf);
typedef struct
{
    int  C0;
    int  C1;
} ERfCoTmsData;
META_RESULT __stdcall META_ERf_GetCoTmsData(const unsigned int ms_timeout, ERfCoTmsData* cnf);
META_RESULT __stdcall META_ERf_GetCoTmsData_r(const int meta_handle, const unsigned int ms_timeout, ERfCoTmsData* cnf);
META_RESULT __stdcall META_ERf_SetCoTmsData(const ERfCoTmsData* req, const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetCoTmsData_r(const int meta_handle, const ERfCoTmsData* req, const unsigned int ms_timeout);
typedef struct
{
    unsigned int   EtCalDoneFlag   [MAX_ERF_ET_NUM_BAND];    /*to check if FHC/ETK done already*/
    unsigned short Band            [MAX_ERF_ET_NUM_BAND];    /*band indicator*/
    unsigned short SubbandFreq     [MAX_ERF_ET_NUM_BAND][MAX_ERF_ET_NUM_SUBBAND]; /*subband frequency*/
} ERfTestCmdEtPathDelayCheckResult;
META_RESULT __stdcall META_ERf_GetEtPathDelayCheckResult(const unsigned int ms_timeout, ERfTestCmdEtPathDelayCheckResult* cnf);
META_RESULT __stdcall META_ERf_GetEtPathDelayCheckResult_r(const int meta_handle, const unsigned int ms_timeout, ERfTestCmdEtPathDelayCheckResult* cnf);
typedef struct
{
    unsigned short Band;
    unsigned short SubbandFreq;
    unsigned short CbwIdx;
    short          Offset;
} ERfTestCmdEtPathDelayStartSetting;
META_RESULT __stdcall META_ERf_StartEtPathDelaySearch(const ERfTestCmdEtPathDelayStartSetting* req, const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_StartEtPathDelaySearch_r(const int meta_handle, const ERfTestCmdEtPathDelayStartSetting* req, const unsigned int ms_timeout);
/**
 * \brief non-reentrant version of META_ERf_GetFilterModeTpcSetting
 */
META_RESULT  __stdcall META_ERf_GetFilterModeTpcSetting( unsigned char band,  const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_GetFilterModeTpcSetting_r( const int meta_handle, unsigned char band,  const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
/**
 * \brief non-reentrant version of META_ERf_SetFilterModeTpcSetting
 */
META_RESULT  __stdcall META_ERf_SetFilterModeTpcSetting( unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );
META_RESULT  __stdcall META_ERf_SetFilterModeTpcSetting_r( const int meta_handle, unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );
/**
 * \brief non-reentrant version of META_ERf_SetHrmTpcSetting
 */
META_RESULT __stdcall META_ERf_SetHrmFlag(const unsigned int ms_timeout);
META_RESULT __stdcall META_ERf_SetHrmFlag_r(const int meta_handle, const unsigned int ms_timeout);
/**
 * \brief non-reentrant version of META_ERf_GetHrmTpcSetting
 */
META_RESULT  __stdcall META_ERf_GetHrmTpcSetting( unsigned char band, const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
META_RESULT  __stdcall META_ERf_GetHrmTpcSetting_r( const int meta_handle, unsigned char band, const unsigned int ms_timeout, ERfTestCmdGetSetTpcSetting* resp );
/**
 * \brief non-reentrant version of META_ERf_SetHrmTpcSetting
 */
META_RESULT  __stdcall META_ERf_SetHrmTpcSetting( unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );
META_RESULT  __stdcall META_ERf_SetHrmTpcSetting_r( const int meta_handle, unsigned char band, ERfTestCmdGetSetTpcSetting* req, const unsigned int ms_timeout );

typedef struct
{
   unsigned char tas_idx;
} ERfTestCmdTasCfg;

/**
 * \brief non-reentrant version of META_ERf_ForceTasSwitch_r
 */
META_RESULT __stdcall META_ERf_ForceTasSwitch(const unsigned int ms_timeout, const ERfTestCmdTasCfg* req);

/**
 * \details Configure DPDT switch mode
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param tas_cfg DPDT switch configuration
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_ERf_ForceTasSwitch_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestCmdTasCfg* req);
typedef enum
{
    ERF_TEST_ANT_SEL_0,     ///< Select antenna 0 only main.
    ERF_TEST_ANT_SEL_1,     ///< Select antenna 1 only diversity.
    ERF_TEST_ANT_SEL_01     ///< Select antenna 0 & 1 both.
} ERfTestAntSel;
/**
 * \brief non-reentrant version of META_ERf_SetRxAntenna_r
 */
META_RESULT __stdcall META_ERf_SetRxAntenna(const unsigned int ms_timeout, const ERfTestAntSel* req);
/**
 * \details set LTE Rx path antenna type
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req antenna type configuration
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_ERf_SetRxAntenna_r(const int meta_handle, const unsigned int ms_timeout, const ERfTestAntSel* req);
typedef struct
{
    unsigned int  auxadc_temp;
} ERfResultTempAuxAdc;
/**
 * \brief non-reentrant version of META_ERf_QueryAuxAdc_r
 */
META_RESULT __stdcall META_ERf_QueryTempAuxAdc(const unsigned int ms_timeout, const ERfResultTempAuxAdc* cnf);
/**
 * \details Query Temp AuxADC from target
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param cnf the result of AuxADC
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_ERf_QueryTempAuxAdc_r(const int meta_handle, const unsigned int ms_timeout, const ERfResultTempAuxAdc* cnf);
/**
 * \brief non-reentrant version of META_ERf_UbinModeSetup_r
 */
META_RESULT __stdcall META_ERf_UbinModeSetup(unsigned int ms_timeout, const unsigned char ubin_lte_mode_init);//  1 : UBIN mode Init LTE ,      0 : UBIN mode de-init LTE
/**
 * \details intialize UBIN to target
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param ubin_lte_mode_init init parameter 1: init 0: de-init
 * \param cnf the result of AuxADC
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_ERf_UbinModeSetup_r(const int meta_handle, unsigned int ms_timeout, const unsigned char ubin_lte_mode_init);

/**
 * @}
 */
#endif /* __META_LTE__ */
#define MMRF_GSM_RAT_INDEX      (1 << 0)
#define MMRF_TDSCDMA_RAT_INDEX  (1 << 1)
#define MMRF_C2K_RAT_INDEX      (1 << 2)
#define MMRF_WCDMA_RAT_INDEX    (1 << 3)
#define MMRF_LTE_TDD_RAT_INDEX  (1 << 4)
#define MMRF_LTE_FDD_RAT_INDEX  (1 << 5)
typedef struct
{
    unsigned int capabilityItemsSize;
    unsigned int calibrationItemsSize;
} MMRfTestCmdRfCapabilityReq;
typedef struct
{
    unsigned int    reserved;
} MMRfCapabilityItemSet;
typedef struct
{
    unsigned int    is_capable  : 1;
    unsigned int    is_mandatory: 1;
    unsigned int    parameter   : 30;
} MMRfCalibrationItem;
typedef struct
{
    MMRfCalibrationItem    ratmap_cal_result_share_tadc;       /**< [0] bitmap for Multi-RAT to share TADC calibration result;parameter (0|0|C|Lf|Lt|T|W|G) */
    MMRfCalibrationItem    ratmap_cal_result_share_afc;        /**< [1] bitmap for Multi-RAT to share AFC calibration result ;parameter (0|0|C|Lf|Lt|T|W|G) */
    MMRfCalibrationItem    ratmap_support_RfSelf_cal;          /**< [2] bitmap for Multi-RAT to support Rf-Self cal.         ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_RfSelf_cal_v2;       /**< [3] bitmap for Multi-RAT to support post Rf-Self cal.    ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_dpd_cal;             /**< [4] bitmap for Multi-RAT to support DPD cal.             ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_cim3_cal;            /**< [5] bitmap for Multi-RAT to support CIM3 cal.            ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_et_cal;              /**< [6] bitmap for Multi-RAT to support ET cal.              ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_TAS;                 /**< [7] bitmap for Multi-RAT to support TAS.                 ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_WM;                  /**< [8] bitmap for Multi-RAT to world mode ID.               ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    ratmap_support_tool_usage;          /**< [9] bitmap for Multi-RAT to tool usage.                  ;parameter (0|0|Lf|Lt|W|C|T|G) */
    MMRfCalibrationItem    support_query_temp_info;            // [10]query temperature DAC af temperature info.
    MMRfCalibrationItem    support_query_vpa_voltage_list;     // [11]query vpa voltage list.
    MMRfCalibrationItem    support_RfSelf_test_analyzer;       // [12] 
    MMRfCalibrationItem    support_query_max_et_route_num;     // [13] 
} MMRfCalibrationItemSet;
typedef struct
{
    int                     valid;
    int                     status;
    MMRfCapabilityItemSet   capabilityItems;
    MMRfCalibrationItemSet  calibrationItems;
} MMRfTestCmdRfCapabilityCnf;
META_RESULT __stdcall META_MMRf_GetRfCapability( const unsigned int ms_timeout, const MMRfTestCmdRfCapabilityReq* req, const unsigned int requestLength, MMRfTestCmdRfCapabilityCnf* resp, const unsigned int responseLength );
META_RESULT __stdcall META_MMRf_GetRfCapability_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdRfCapabilityReq* req, const unsigned int requestLength, MMRfTestCmdRfCapabilityCnf* resp, const unsigned int responseLength );
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
} MMRfTestCmdDpdFacStartReq;
META_RESULT __stdcall META_MMRf_StartDpdFacCal( const unsigned int ms_timeout, const MMRfTestCmdDpdFacStartReq* req);
META_RESULT __stdcall META_MMRf_StartDpdFacCal_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdDpdFacStartReq* req);
#define MMRF_MAX_BAND_NUM               21
#define MAX_FHC_TX_FREQ_NUM_EX          15
#define MAX_DPD_AM_LUT_GAIN_NUM          8 /*  8 PA*PGA gain combination */
#define MAX_DPD_AM_LUT_ACTUAL_PWR_NUM   32 /* 32 power level */
#define MAX_DPD_PM_LUT_GAIN_NUM          8 /*  8 PA*PGA gain combination */
#define MAX_DPD_PM_LUT_ACTUAL_PWR_NUM   32 /* 32 power level */
#define MAX_LTE_CBW_NUM                  6  /* 6 CBW: 1.4M, 3M, 5M, 10M, 15M, 20M */
#define DPD_IMPLICIT_NUM               512
typedef enum
{
    MMRF_TEST_DPD_ALGO_PARAM = 0,
    MMRF_TEST_DPD_AM = 1,
    MMRF_TEST_DPD_PM = 2,
    MMRF_TEST_DPD_ALGO_PARAM_RESULT = 3,
} MMRfTestDpdFacCmdType;
typedef struct
{
    unsigned short    lut[MAX_DPD_AM_LUT_GAIN_NUM][MAX_DPD_AM_LUT_ACTUAL_PWR_NUM];
} MMRfTestDpdAmLutSubBand;
typedef struct
{
    short             lut[MAX_DPD_PM_LUT_GAIN_NUM][MAX_DPD_PM_LUT_ACTUAL_PWR_NUM];
} MMRfTestDpdPmLutSubBand;
typedef struct
{
    unsigned short            dpd_subband_freq[MAX_FHC_TX_FREQ_NUM_EX];
} MMRfTestDPDFacParamToolSet;
typedef struct
{
    unsigned short    dpd_cal_done;
    short             dpdImplicitArray[DPD_IMPLICIT_NUM];
} MMRfTestDPDFacParamResult;
typedef union
{
    MMRfTestDPDFacParamToolSet  dpd_fac_tool_set;                        //  MMRF_TEST_DPD_ALGO_PARAM
    MMRfTestDpdAmLutSubBand     am_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];  //  MMRF_TEST_DPD_AM
    MMRfTestDpdPmLutSubBand     pm_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];  //  MMRF_TEST_DPD_PM
    MMRfTestDPDFacParamResult   dpd_fac_tool_result;                     //  MMRF_TEST_DPD_ALGO_PARAM_RESULT
} MMRfTestDpdFacIO;
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    am_pm_param_type;
    unsigned short    signal_path;       // 0:(default), 1 (HRM), 2:(filter)
} MMRfTestDpdGetFacParamReq;
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    am_pm_param_type;  // 0:(algorithm param) 1:(AM LUT) 2:(PM LUT)
    unsigned short    signal_path;       // 0:(default), 1 (HRM), 2:(filter)
    MMRfTestDpdFacIO  param;
} MMRfTestDpdGetFacParamCnf;
META_RESULT __stdcall META_MMRf_GetDpdFacCalParam( const unsigned int ms_timeout, const MMRfTestDpdGetFacParamReq* req, MMRfTestDpdGetFacParamCnf* cnf);
META_RESULT __stdcall META_MMRf_GetDpdFacCalParam_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestDpdGetFacParamReq* req, MMRfTestDpdGetFacParamCnf* cnf);
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    am_pm_param_type;  // 0:(algorithm param) 1:(AM LUT) 2:(PM LUT)
    unsigned short    signal_path;       // 0:(default), 1 (HRM), 2:(filter)
    MMRfTestDpdFacIO param;
} MMRfTestDpdSetFacParamReq;
META_RESULT __stdcall META_MMRf_SetDpdFacCalParam( const unsigned int ms_timeout, const MMRfTestDpdSetFacParamReq* req);
META_RESULT __stdcall META_MMRf_SetDpdFacCalParam_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestDpdSetFacParamReq* req);
typedef struct
{
    unsigned short  rat_idx;         /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
    unsigned short  dpd_switch;
} MMRfTestDpdFacEnDisReq;
META_RESULT __stdcall META_MMRf_DpdEnable( const unsigned int ms_timeout, const MMRfTestDpdFacEnDisReq* req);
META_RESULT __stdcall META_MMRf_DpdEnable_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestDpdFacEnDisReq* req);
#define MAX_DPD_PA_GAIN_NUM                 8
#define MAX_DPD_PA_CAL_EARFCN_SECTION      15
#define MAX_DPD_PA_CAL_TEMP_SECTION         8
#define DPD_PA_IMPLICIT_NUM               512
#define MAX_DPD_DELAY_K_SUBBAND_NUM         5
#define MAX_DPD_DELAY_K_SPLIT_BAND_NUM      2

typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    apt_ref_channel;
} MMRfTestCmdDpdPaProfileFacStartReq;
META_RESULT __stdcall META_MMRf_StartDpdPaProfileFacCal( const unsigned int ms_timeout, const MMRfTestCmdDpdPaProfileFacStartReq* req);
META_RESULT __stdcall META_MMRf_StartDpdPaProfileFacCal_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdDpdPaProfileFacStartReq* req);
typedef enum
{
    MMRF_TEST_DPD_PA_PROFILE = 0,
    MMRF_TEST_DPD_PA_ALGO_PARAM_RESULT = 1
} MMRfTestDPDPaProfileFacCmdType;
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    pa_param_type;
    unsigned short    signal_path;       // 0:(default), 1 (HRM), 2:(filter)
} MMRfTestDpdGetPaProfileFacParamReq;
typedef struct
{
    unsigned short    tr[MAX_DPD_DELAY_K_SUBBAND_NUM][MAX_LTE_CBW_NUM];
} MMRfTestDpdTrAbsolute;
typedef struct
{
    /* PA Control */
    unsigned char     paControlLevel; /* 2~8 */
    unsigned char     calRoomTempIdx;
    short             hysteresisStart0;
    short             hysteresisEnd0;
    short             hysteresisStart1;
    short             hysteresisEnd1;
    unsigned char     paMode[MAX_DPD_PA_GAIN_NUM]; /* 0:high, 1:middle, 2:low */
    short             pRf[MAX_DPD_PA_GAIN_NUM];
    unsigned short    paGain[MAX_DPD_PA_GAIN_NUM];
    unsigned char     dc2dcLevel[MAX_DPD_PA_GAIN_NUM]; /* voltage map by chip */
    unsigned short    vBiasDac[MAX_DPD_PA_GAIN_NUM];
    unsigned char     vm0[MAX_DPD_PA_GAIN_NUM];
    unsigned char     vm1[MAX_DPD_PA_GAIN_NUM];
    /* TX Compensation */
    unsigned short           ulFrequency[MAX_DPD_PA_CAL_EARFCN_SECTION];//100kHz unit
    short                    paGainHigh[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    short                    paGainMiddle[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    short                    paGainLow[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    short                    couplerLossHigh;
    short                    couplerLossMiddle;
    short                    couplerLossLow;
    short                    powerDetectorHigh[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    short                    powerDetectorMiddle[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    short                    powerDetectorLow[MAX_DPD_PA_CAL_TEMP_SECTION][MAX_DPD_PA_CAL_EARFCN_SECTION];
    MMRfTestDpdTrAbsolute    tr_absolute[MAX_DPD_DELAY_K_SPLIT_BAND_NUM];
} MMRfTestDPDPaProfileFacParam;
typedef struct
{
    unsigned short     dpd_pa_cal_done;
    short              dpdPaImplicitArray[DPD_PA_IMPLICIT_NUM];
} MMRfTestDPDPaFacParamToolSet;
typedef union
{
    MMRfTestDPDPaProfileFacParam   dpd_pa_fac_param;        // MMRF_TEST_DPD_PA_PROFILE
    MMRfTestDPDPaFacParamToolSet   dpd_pa_fac_tool_result;  // MMRF_TEST_DPD_PA_ALGO_PARAM_RESULT
} MMRfTestDPDPaProfileFacIO;
typedef struct
{
    unsigned short               rat_idx;
    unsigned short               rf_band_idx;
    unsigned short               pa_param_type;
    unsigned short               signal_path;       // 0:(default), 1 (HRM), 2:(filter)
    MMRfTestDPDPaProfileFacIO    dpd_pa_fac_io;
} MMRfTestDpdGetPaProfileFacParamCnf;
META_RESULT __stdcall META_MMRf_GetDpdPaProfileFacCalParam( const unsigned int ms_timeout, const MMRfTestDpdGetPaProfileFacParamReq* req, MMRfTestDpdGetPaProfileFacParamCnf* cnf);
META_RESULT __stdcall META_MMRf_GetDpdPaProfileFacCalParam_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestDpdGetPaProfileFacParamReq* req, MMRfTestDpdGetPaProfileFacParamCnf* cnf);
typedef struct
{
    unsigned short             rat_idx;
    unsigned short             rf_band_idx;
    unsigned short             pa_param_type;
    unsigned short             signal_path;       // 0:(default), 1 (HRM), 2:(filter)
    MMRfTestDPDPaProfileFacIO  dpd_pa_fac_io;
} MMRfTestDpdSetPaProfileFacParamReq;
META_RESULT __stdcall META_MMRf_SetDpdPaProfileFacCalParam( const unsigned int ms_timeout, const MMRfTestDpdSetPaProfileFacParamReq* req);
META_RESULT __stdcall META_MMRf_SetDpdPaProfileFacCalParam_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestDpdSetPaProfileFacParamReq* req);
//-----------------------------------------------------//
//  DPD Factory CalibrationTool Interface             //
//-----------------------------------------------------//
/* Multi-mode */
#define MMRF_MAX_LTE_DPD_SPLIT_BAND_NUM            (2)
#define MMRF_MAX_DPD_DELAY_K_SUBBAND_NUM        (5)
#define MMRF_MAX_LTE_CBW_NUM                    (6)
#define MMRF_MAX_DPD_AM_LUT_PWR_NUM_REDUCE_V2   (16)
#define MMRF_MAX_DPD_PM_LUT_PWR_NUM_REDUCE_V2   (MMRF_MAX_DPD_AM_LUT_PWR_NUM_REDUCE_V2)
/* Multi-mode */

/* LTE */
#define MAX_TX_PA_MODE_NUM            3
#define MAX_TEMP_SECTION_NUM        8

#define MMRF_MAX_DPD_PA_LEVEL_NUM               (8)
#define MMRF_MAX_DPD_PGA_NUM_PER_PA                (1)
#define MMRF_MAX_DPD_AM_LUT_GAIN_NUM            (MMRF_MAX_DPD_PA_LEVEL_NUM * MMRF_MAX_DPD_PGA_NUM_PER_PA)
#define MMRF_MAX_DPD_PM_LUT_GAIN_NUM            (MMRF_MAX_DPD_AM_LUT_GAIN_NUM)
#define MMRF_MAX_DPD_PGA_SWING_NUM                (MAX_FHC_TX_FREQ_NUM_EX * MMRF_MAX_DPD_AM_LUT_GAIN_NUM)
#define MMRF_MAX_DPD_PTAR_TH_NUM                (MAX_FHC_TX_FREQ_NUM_EX * MMRF_MAX_DPD_PA_LEVEL_NUM)
#define MMRF_MAX_DPD_PA_PGA_TABLE_NUM            (MAX_FHC_TX_FREQ_NUM_EX * MMRF_MAX_DPD_AM_LUT_GAIN_NUM * 2)
#define MMRF_MAX_DPD_IMPLICIT_RSV_NUM            (32) 
#define MMRF_MAX_DPD_IMPLICIT_NUM               (256)
#define MMRF_MAX_DPD_AM_LUT_ACTUAL_PWR_NUM        (16)
#define MMRF_MAX_DPD_PM_LUT_ACTUAL_PWR_NUM        (MMRF_MAX_DPD_AM_LUT_ACTUAL_PWR_NUM)
#define MMRF_MAX_LTE_DPD_SET_ALL_DATA_NUM        (6)
#define MMRF_MAX_LTE_DPD_GET_ALL_DATA_NUM        (MMRF_MAX_LTE_DPD_SET_ALL_DATA_NUM)
#define MMRF_MAX_LTE_DPD_SET_PARTIAL_DATA_NUM    (63)
#define MAX_TX_ROUTE_AND_PS_NUM                    (256 * 4)
/* LTE */

/* WCDMA */
#define MMRF_MAX_WCDMA_DPD_BAND_NUM_V2              (5)
#define MMRF_MAX_WCDMA_DPD_PA_LEVEL_NUM_V2          (8)
#define MMRF_MAX_WCDMA_DPD_PGA_NUM_PER_PA_V2        (1)
#define MMRF_MAX_WCDMA_DPD_AM_LUT_GAIN_NUM_V2        (MMRF_MAX_WCDMA_DPD_PA_LEVEL_NUM_V2 * MMRF_MAX_WCDMA_DPD_PGA_NUM_PER_PA_V2)
#define MMRF_MAX_WCDMA_DPD_PM_LUT_GAIN_NUM_V2        (MMRF_MAX_WCDMA_DPD_AM_LUT_GAIN_NUM_V2)
#define MMRF_MAX_WCDMA_DPD_PA_MODE_NUM_V2           (3)
#define MMRF_MAX_WCDMA_DPD_PA_HYST_NUM_V2           (MMRF_MAX_WCDMA_DPD_PA_MODE_NUM_V2 - 1)

#define MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2    (15)
#define MMRF_MAX_WCDMA_DPD_PGA_SWING_NUM_V2            (MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2 * MMRF_MAX_WCDMA_DPD_AM_LUT_GAIN_NUM_V2) 
#define MMRF_MAX_WCDMA_DPD_PTAR_TH_NUM_V2            (MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2 * MMRF_MAX_WCDMA_DPD_PA_LEVEL_NUM_V2) 
#define MMRF_MAX_WCDMA_DPD_IMPLICIT_RSV_NUM_V2        (16)
#define MMRF_MAX_WCDMA_DPD_IMPLICIT_NUM_V2            (MMRF_MAX_WCDMA_DPD_PGA_SWING_NUM_V2 + MMRF_MAX_WCDMA_DPD_PTAR_TH_NUM_V2 + MMRF_MAX_WCDMA_DPD_IMPLICIT_RSV_NUM_V2)
#define MMRF_MAX_WCDMA_DPD_SET_ALL_DATA_NUM_V2        (7) 
#define MMRF_MAX_WCDMA_DPD_GET_ALL_DATA_NUM_V2        (MMRF_MAX_WCDMA_DPD_SET_ALL_DATA_NUM_V2)
#define MMRF_MAX_WCDMA_DPD_SET_PARTIAL_DATA_NUM_V2    (239)
/* WCDMA */

typedef enum
{
   ERF_TEST_LTE_DPD_V1 = 0,
   ERF_TEST_LTE_DPD_V2 = 1
}ERfTestLteDpdGeneration;
typedef enum
{
   URF_TEST_WCDMA_DPD_V1 = 0,
   URF_TEST_WCDMA_DPD_V2 = 1
}URfTestWcdmaDpdGeneration;
typedef struct
{
   unsigned short  lut[MMRF_MAX_DPD_AM_LUT_GAIN_NUM][MMRF_MAX_DPD_AM_LUT_ACTUAL_PWR_NUM];
} MMRfTestCmdDPDAMLutSubBand;
typedef struct
{
    short               lut[MMRF_MAX_DPD_PM_LUT_GAIN_NUM][MMRF_MAX_DPD_PM_LUT_ACTUAL_PWR_NUM];
} MMRfTestCmdDPDPMLutSubBand;
typedef struct
{
    unsigned short        rf_band;
    unsigned short        route_idx;
    unsigned short        path_select;                          
    unsigned char        paControlLevel; /* 2~8 */
    unsigned char        calRoomTempIdx;
    short               hysteresisStart0;
    short               hysteresisEnd0;
    short               hysteresisStart1;
    short               hysteresisEnd1;
    unsigned char       paMode[MMRF_MAX_DPD_PA_LEVEL_NUM]; /* ERfTestTxPaModeE */
    short                pRf[MMRF_MAX_DPD_PA_LEVEL_NUM];
    unsigned short      paGain[MMRF_MAX_DPD_PA_LEVEL_NUM];
    unsigned char       dc2dcLevel[MMRF_MAX_DPD_PA_LEVEL_NUM]; /* voltage map by chip, TODO */
    unsigned short      vBiasDac[MMRF_MAX_DPD_PA_LEVEL_NUM];
    unsigned char        vm0[MMRF_MAX_DPD_PA_LEVEL_NUM];
    unsigned char        vm1[MMRF_MAX_DPD_PA_LEVEL_NUM];
    short                paGainSbWeight[MAX_TX_PA_MODE_NUM][MAX_TEMP_SECTION_NUM][MAX_FHC_TX_FREQ_NUM_EX]; 
    unsigned short        dpd_pa_dpd_cal_done;             
    short dpd_tr[MAX_FHC_TX_FREQ_NUM_EX][MMRF_MAX_LTE_CBW_NUM];
} MMRfTestCmdSetGetLteDpdTpcPeer;
typedef struct
{
   short                         dpdImplicitArray[MMRF_MAX_DPD_IMPLICIT_NUM]; /* For the parameters whose name will not be shown in cal file */
   MMRfTestCmdDPDAMLutSubBand    am_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];
   MMRfTestCmdDPDPMLutSubBand    pm_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];
} MMRfTestCmdSetGetLteDpdDpdPeer;

typedef struct
{
   MMRfTestCmdSetGetLteDpdTpcPeer    dpdtpc_peer;
   MMRfTestCmdSetGetLteDpdDpdPeer    dpd_peer;   
}MMRfTestCmdSetLteDpdPaAndDpdFacCalAllOneRoute;

typedef struct
{
   unsigned short    start;
   unsigned short    end;
} MMRfTestCmdWcdmaDpdHysteresisData;

typedef struct
{
   unsigned char    pa_mode;
   char                prf;
   unsigned char    dc2dc_lvl;
   unsigned char    vm1;
   unsigned char    vm2;
   unsigned short    vbias_dac;
   unsigned short    pa_gain;
} MMRfTestCmdWcdmaDpdPmuLevHandle;

typedef struct
{
   unsigned short                        rf_band;  
   unsigned short                        dpd_pa_dpd_cal_done;
   short                                dpd_tr[MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2];
   short                                vga_comp_subband[MMRF_MAX_WCDMA_DPD_PA_MODE_NUM_V2][MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2];
   short                                vga_comp_temperature[MMRF_MAX_WCDMA_DPD_PA_MODE_NUM_V2][MMRF_MAX_WCDMA_DPD_PA_LEVEL_NUM_V2];
   MMRfTestCmdWcdmaDpdHysteresisData    tx_hysteresis[MMRF_MAX_WCDMA_DPD_PA_HYST_NUM_V2];
   unsigned char                        octlev_num_section;
   unsigned int                            pa_phase_compensation[MMRF_MAX_WCDMA_DPD_PA_MODE_NUM_V2];
   MMRfTestCmdWcdmaDpdPmuLevHandle        pmu_level_handle[MMRF_MAX_WCDMA_DPD_PA_LEVEL_NUM_V2];
}MMRfTestCmdSetGetWcdmaDpdTpcPeer;

typedef struct
{                                                             
   unsigned short  lut[MMRF_MAX_WCDMA_DPD_AM_LUT_GAIN_NUM_V2][MMRF_MAX_DPD_AM_LUT_PWR_NUM_REDUCE_V2];
} MMRfTestCmdWcdmaDPDAMLutSubBand;

typedef struct
{
   short  lut[MMRF_MAX_WCDMA_DPD_PM_LUT_GAIN_NUM_V2][MMRF_MAX_DPD_PM_LUT_PWR_NUM_REDUCE_V2];
} MMRfTestCmdWcdmaDPDPMLutSubBand;

typedef struct
{
   short                            dpdImplicitArray[MMRF_MAX_WCDMA_DPD_IMPLICIT_NUM_V2];     
   MMRfTestCmdWcdmaDPDAMLutSubBand    am_lut_subband[MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2];
   MMRfTestCmdWcdmaDPDPMLutSubBand    pm_lut_subband[MMRF_MAX_WCDMA_DPD_CAL_UARFCN_SECTION_V2];
}MMRfTestCmdSetGetWcdmaDpdDpdPeer;

typedef struct
{
   MMRfTestCmdSetGetWcdmaDpdTpcPeer     dpdtpc_peer;
   MMRfTestCmdSetGetWcdmaDpdDpdPeer     dpd_peer;
}MMRfTestCmdSetWcdmaDpdPaAndDpdFacCalAllOneBand;

typedef struct
{
   unsigned short            route_num;
}MMRfTestCmdSetLteDpdAllReqInfo;

typedef struct
{
   unsigned short            num_of_band;
}MMRfTestCmdSetWcdmaDpdAllReqInfo;

typedef union
{
   MMRfTestCmdSetLteDpdAllReqInfo    lte_dpd_req; 
   MMRfTestCmdSetWcdmaDpdAllReqInfo wcdma_dpd_req;
}MMRfTestCmdSetMmDpdAllReqInfo;

typedef struct
{   
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                    rat_idx;
   MMRfTestCmdSetMmDpdAllReqInfo    mm_dpd_info;    
}MMRfTestCmdSetDpdPaAndDpdFacCalAllReqParam;

typedef struct
{
   MMRfTestCmdSetDpdPaAndDpdFacCalAllReqParam reqParam;
   union
   {
        MMRfTestCmdSetLteDpdPaAndDpdFacCalAllOneRoute   reqPeer[MMRF_MAX_LTE_DPD_SET_ALL_DATA_NUM];
        MMRfTestCmdSetWcdmaDpdPaAndDpdFacCalAllOneBand  wcdmaReqPeer[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];
   };
} MMRfTestSetDpdPaAndDpdFacCalAllReq;

typedef enum
{
   MMRF_TEST_SET_LTE_DPDPA_DPD_COARSE_INVALID    = 0,
   MMRF_TEST_SET_LTE_DPDPA_DPD_COARSE_OK        = 1,
   MMRF_TEST_SET_LTE_DPDPA_DPD_COARSE_PEER_SIZE_MISMATCH    = 2  /* count/offset mismatch */   
}MMRfTestSetLteDpdPaAndDpdFacCalCoarseStatus;

typedef enum
{
   MMRF_TEST_SET_LTE_DPDPA_DPD_ROUTE_INVALID    = 0,
   MMRF_TEST_SET_LTE_DPDPA_DPD_ROUTE_OK        = 1,
   MMRF_TEST_SET_LTE_DPDPA_DPD_ROUTE_BAND_MISMATCH    = 2   
}MMRfTestSetLteDpdPaAndDpdFacCalRouteStatus;

typedef struct
{
   unsigned short    route_num;
   unsigned short     coarse_status; /* MMRfTest_SetLteDpdPaAndDpdFacCal_CoarseStatus */
   unsigned short     route_status[MMRF_MAX_LTE_DPD_SET_ALL_DATA_NUM]; /* MMRfTest_SetLteDpdPaAndDpdFacCal_RouteStatus */
}MMRfTestResultSetLteDpdAllCnfInfo;

typedef enum
{
   MMRF_TEST_SET_WCDMA_DPD_INVALID              = 0,
   MMRF_TEST_SET_WCDMA_DPD_OK                    = 1,
   MMRF_TEST_SET_WCDMA_DPD_PEER_SIZE_MISMATCH   = 2   
}MMRfTestSetWcdmaDpdPaAndDpdFacCalRouteStatus;

typedef struct
{
   unsigned short        num_of_band;
   unsigned short        status; /* MMRfTestSetWcdmaDpdPaAndDpdFacCalRouteStatus */
}MMRfTestResultSetWcdmaDpdAllCnfInfo;

typedef union
{
   MMRfTestResultSetLteDpdAllCnfInfo    lte_dpd_cnf; 
   MMRfTestResultSetWcdmaDpdAllCnfInfo    wcdma_dpd_cnf;
}MMRfTestResultSetMmDpdAllCnfInfo;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                   rat_idx;
   MMRfTestResultSetMmDpdAllCnfInfo    mm_dpd_cnf;   
}MMRfTestResultSetDpdPaAndDpdFacCalAllCnfParam;

typedef struct
{
   MMRfTestResultSetDpdPaAndDpdFacCalAllCnfParam cnfParam;
} MMRfTestSetDpdPaAndDpdFacCalAllCnf;
META_RESULT __stdcall META_MMRf_SetDpdPaAndDpdFacCalAll_V2( const unsigned int ms_timeout, const MMRfTestSetDpdPaAndDpdFacCalAllReq *req, MMRfTestSetDpdPaAndDpdFacCalAllCnf *cnf);
META_RESULT __stdcall META_MMRf_SetDpdPaAndDpdFacCalAll_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestSetDpdPaAndDpdFacCalAllReq *req, MMRfTestSetDpdPaAndDpdFacCalAllCnf *cnf); 

typedef struct
{
   MMRfTestCmdSetGetLteDpdTpcPeer     dpdtpc_peer;
}MMRfTestCmdSetLteDpdPaAndDpdFacCalPartialOneRoute;

typedef struct
{
   unsigned short            route_num;
}MMRfTestCmdSetLteDpdPartialReqInfo;

typedef struct
{
   MMRfTestCmdSetGetWcdmaDpdTpcPeer     dpdtpc_peer;
}MMRfTestCmdSetWcdmaDpdPaAndDpdFacCalPartialOneBand;

typedef struct
{
   unsigned short            num_of_band;
}MMRfTestCmdSetWcdmaDpdPartialReqInfo;

typedef union
{
   MMRfTestCmdSetLteDpdPartialReqInfo    lte_dpd_req;
   MMRfTestCmdSetWcdmaDpdPartialReqInfo    wcdma_dpd_req; 
}MMRfTestCmdSetMmDpdPartialReqInfo;

typedef struct
{   
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                        rat_idx;
   MMRfTestCmdSetMmDpdPartialReqInfo    mm_dpd_info;    
}MMRfTestCmdSetDpdPaAndDpdFacCalPartialReqParam;

typedef struct
{
   MMRfTestCmdSetDpdPaAndDpdFacCalPartialReqParam reqParam;
   union
   {
        MMRfTestCmdSetLteDpdPaAndDpdFacCalPartialOneRoute   reqPeer[MMRF_MAX_LTE_DPD_SET_PARTIAL_DATA_NUM];
        MMRfTestCmdSetWcdmaDpdPaAndDpdFacCalPartialOneBand  wcdmaReqPeer[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];
   };
}MMRfTestCmdSetDpdPaAndDpdFacCalPartialReq;

typedef struct
{
   unsigned short    route_num;
   unsigned short    coarse_status; /* MMRfTest_SetLteDpdPaAndDpdFacCal_CoarseStatus */
   unsigned short    route_status[MMRF_MAX_LTE_DPD_SET_PARTIAL_DATA_NUM]; /* MMRfTest_SetLteDpdPaAndDpdFacCal_RouteStatus */
}MMRfTestResultSetLteDpdPartialCnfInfo;

typedef struct
{
   unsigned short    num_of_band;
   unsigned short    status; 
}MMRfTestResultSetWcdmaDpdPartialCnfInfo;

typedef union
{
   MMRfTestResultSetLteDpdPartialCnfInfo    lte_dpd_cnf;
   MMRfTestResultSetWcdmaDpdPartialCnfInfo    wcdma_dpd_cnf; 
}MMRfTestResultSetMmDpdPartialCnfInfo;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                       rat_idx;
   MMRfTestResultSetMmDpdPartialCnfInfo    mm_dpd_cnf;   
}MMRfTestResultSetDpdPaAndDpdFacCalPartialCnfParam;

typedef struct
{
   MMRfTestResultSetDpdPaAndDpdFacCalPartialCnfParam cnfParam;
}MMRfTestResultSetDpdPaAndDpdFacCalPartialCnf;
META_RESULT __stdcall META_MMRf_SetDpdPaAndDpdFacCalPartial_V2( const unsigned int ms_timeout, const MMRfTestCmdSetDpdPaAndDpdFacCalPartialReq *req, MMRfTestResultSetDpdPaAndDpdFacCalPartialCnf *cnf);
META_RESULT __stdcall META_MMRf_SetDpdPaAndDpdFacCalPartial_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetDpdPaAndDpdFacCalPartialReq *req, MMRfTestResultSetDpdPaAndDpdFacCalPartialCnf *cnf); 

typedef struct
{
   unsigned short            route_idx;
   unsigned short            path_select;    
}MMRfTestCmdRouteInfo;

typedef struct
{             
   unsigned short            route_num;             
   MMRfTestCmdRouteInfo        route_info[MMRF_MAX_LTE_DPD_GET_ALL_DATA_NUM];             
}MMRfTestCmdGetLteDpdAllReqInfo;            

typedef struct
{ 
   unsigned short            num_of_band;
   unsigned short            rf_band[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];             
}MMRfTestCmdGetWcdmaDpdAllReqInfo;

typedef union
{             
   MMRfTestCmdGetLteDpdAllReqInfo    lte_dpd_req;
   MMRfTestCmdGetWcdmaDpdAllReqInfo    wcdma_dpd_req;
}MMRfTestCmdGetMmDpdAllReqInfo;             

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                    rat_idx;
   MMRfTestCmdGetMmDpdAllReqInfo    mm_dpd_req;   
}MMRfTestCmdGetDpdPaAndDpdFacCalAllReqParam;

typedef struct
{
   MMRfTestCmdGetDpdPaAndDpdFacCalAllReqParam reqParam;
}MMRfTestCmdGetDpdPaAndDpdFacCalAllReq;

typedef enum
{
   MMRF_TEST_GET_LTE_DPDPA_DPD_INVALID    = 0,
   MMRF_TEST_GET_LTE_DPDPA_DPD_OK    = 1   
}MMRfTest_GetLteDpdPaAndDpdFacCal_Status;

typedef struct
{ 
   MMRfTestCmdSetGetLteDpdTpcPeer    dpdtpc_peer;
   MMRfTestCmdSetGetLteDpdDpdPeer    dpd_peer;  
}MMRfTestResultGetLteDpdPaAndDpdFacCalAllOneRoute;

typedef struct
{ 
   MMRfTestCmdSetGetWcdmaDpdTpcPeer    dpdtpc_peer;
   MMRfTestCmdSetGetWcdmaDpdDpdPeer    dpd_peer;  
}
MMRfTestResultGetWcdmaDpdPaAndDpdFacCalAllOneBand;

typedef struct
{             
   unsigned short            route_num;
   unsigned short            get_status; /* MMRfTest_GetLteDpdPaAndDpdFacCal_Status */                
}MMRfTestResultGetLteDpdAllCnfInfo;            

typedef enum
{
   MMRF_TEST_GET_WCDMA_DPD_INVALID    = 0,
   MMRF_TEST_GET_WCDMA_DPD_OK        = 1
} MMRfTestResultGetWcdmaDpdFacCalStatus;

typedef struct
{             
   unsigned short            num_of_band;
   unsigned short            get_status; // MMRfTestResultGetWcdmaDpdFacCalStatus
} MMRfTestResultGetWcdmaDpdAllCnfInfo;

typedef union             
{             
   MMRfTestResultGetLteDpdAllCnfInfo    lte_dpd_cnf;
   MMRfTestResultGetWcdmaDpdAllCnfInfo    wcdma_dpd_cnf; 
}MMRfTestResultGetMmDpdAllCnfInfo;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short                    rat_idx;    
   MMRfTestResultGetMmDpdAllCnfInfo    mm_dpd_cnf;
}MMRfTestResultGetDpdPaAndDpdFacCalAllCnfParam;

typedef struct
{
   MMRfTestResultGetDpdPaAndDpdFacCalAllCnfParam cnfParam;
   union
   {
        MMRfTestResultGetLteDpdPaAndDpdFacCalAllOneRoute    cnfPeer[MMRF_MAX_LTE_DPD_GET_ALL_DATA_NUM];
        MMRfTestResultGetWcdmaDpdPaAndDpdFacCalAllOneBand   wcdmaCnfPeer[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];
   };
}MMRfTestResultGetDpdPaAndDpdFacCalAllCnf;
META_RESULT __stdcall META_MMRf_GetDpdPaAndDpdFacCalAll_V2( const unsigned int ms_timeout, MMRfTestCmdGetDpdPaAndDpdFacCalAllReq *req, const MMRfTestResultGetDpdPaAndDpdFacCalAllCnf *cnf);
META_RESULT __stdcall META_MMRf_GetDpdPaAndDpdFacCalAll_V2_r( const int meta_handle, const unsigned int ms_timeout, MMRfTestCmdGetDpdPaAndDpdFacCalAllReq *req, const MMRfTestResultGetDpdPaAndDpdFacCalAllCnf *cnf); 

typedef struct
{
   unsigned short    comp_route;
   unsigned short    path_select;
   unsigned short    apt_ref_channel;
} MMRfTestCmdLteAptRefChannelOneRoute;

typedef struct
{
   unsigned short    rf_band;
   unsigned short    apt_ref_channel;
   short             tpc_wanted_p_offset;
} MMRfTestCmdWcdmaAptRefChannelOneBand;

typedef struct
{
   unsigned short            route_ps_num;
}MMRfTestCmdStartLteDpdReqInfo;

typedef struct
{
   unsigned short   num_of_band;
   unsigned short    cal_rf_band[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];
}MMRfTestCmdStartWcdmaDpdReqInfo;

typedef union
{
   MMRfTestCmdStartLteDpdReqInfo    lte_dpd_req; 
   MMRfTestCmdStartWcdmaDpdReqInfo    wcdma_dpd_req; 
}MMRfTestCmdStartMmDpdReqInfo;

typedef struct
{   
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   unsigned short               rat_idx;
   MMRfTestCmdStartMmDpdReqInfo    mm_dpd_info;
}MMRfTestCmdStartDpdPaAndDpdFacCalReqParam;

typedef struct
{
   MMRfTestCmdStartDpdPaAndDpdFacCalReqParam reqParam;
   union
   {
        MMRfTestCmdLteAptRefChannelOneRoute     reqPeer[MAX_TX_ROUTE_AND_PS_NUM];
        MMRfTestCmdWcdmaAptRefChannelOneBand    wcdmaReqPeer[MMRF_MAX_WCDMA_DPD_BAND_NUM_V2];
   };
}MMRfTestCmdStartDpdPaAndDpdFacCalReq;

typedef enum
{
   MMRF_TEST_START_LTE_DPDPA_DPD_INVALID            = 0,
   MMRF_TEST_START_LTE_DPDPA_DPD_OK                    = 1,
   MMRF_TEST_START_LTE_DPDPA_DPD_PEER_SIZE_MISMATCH    = 2
}MMRfTestResultStartLteDpdPaAndDpdFacCalStatus;

typedef enum
{
   MMRF_TEST_START_WCDMA_DPD_INVALID                = 0,
   MMRF_TEST_START_WCDMA_DPD_OK                        = 1,
   MMRF_TEST_START_WCDMA_DPD_PEER_SIZE_MISMATCH        = 2,
   MMRF_TEST_START_WCDMA_DPD_EXCEED_TTG_LIMIT_INIT  = 3,
   MMRF_TEST_START_WCDMA_DPD_EXCEED_TTG_LIMIT        = 4,
   MMRF_TEST_START_WCDMA_DPD_NEGATIVE_TR            = 5,
   MMRF_TEST_START_WCDMA_DPD_LARGE_PA_GAIN_DIFF        = 6 
}MMRfTestResultStartWcdmaDpdPaAndDpdFacCalStatus;

typedef struct
{        
   unsigned short    wcdma_dpd_status; /* MMRfTestResultStartWcdmaDpdPaAndDpdFacCalStatus */
   unsigned short    curr_rf_band;     
   unsigned short        curr_subband_idx;
   unsigned short        curr_gain_idx;
   short            pa_gain;
} MMRfTestResultStartWcdmaDpdCnfInfo;

typedef union
{
   unsigned short                        lte_dpd_status;  /* MMRfTest_StartLteDpdPaAndDpdFacCal_Status */
   MMRfTestResultStartWcdmaDpdCnfInfo    wcdma_dpd_status;
}MMRfTestResultStartMmDpdCnfInfo;

typedef struct
{
   unsigned short                    rat_idx;
   MMRfTestResultStartMmDpdCnfInfo    mm_dpd_cnf;   
}MMRfTestResultStartDpdPaAndDpdFacCalCnfParam;

typedef struct
{
   MMRfTestResultStartDpdPaAndDpdFacCalCnfParam cnfParam;
}MMRfTestResultStartDpdPaAndDpdFacCalCnf;
META_RESULT __stdcall META_MMRf_StartDpdPaAndDpdFacCal_V2( const unsigned int ms_timeout, const MMRfTestCmdStartDpdPaAndDpdFacCalReq *req, MMRfTestResultStartDpdPaAndDpdFacCalCnf *cnf);
META_RESULT __stdcall META_MMRf_StartDpdPaAndDpdFacCal_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartDpdPaAndDpdFacCalReq *req, MMRfTestResultStartDpdPaAndDpdFacCalCnf *cnf); 
//-----------------------------------------------------//
//  DPD Factory CalibrationTool Interface             //
//-----------------------------------------------------//

typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
} MMRfTestCmdCim3FacStartReq;
META_RESULT __stdcall META_MMRf_StartCim3FacCal( const unsigned int ms_timeout, const MMRfTestCmdCim3FacStartReq* req);
META_RESULT __stdcall META_MMRf_StartCim3FacCal_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdCim3FacStartReq* req);
#define MAX_CIM3_PA_GAIN_NUM               MAX_DPD_PA_GAIN_NUM
#define MAX_CIM3_LUT_GAIN_NUM              60 /* 40 PA*PGA gain combination */
#define MAX_CIM3_LUT_CHANNEL_NUM            2 /* 2 TX channel type (PRACH and PUxCH) */
typedef enum
{
    MMRF_TEST_CIM3_ALGO_PARAM = 0,
    MMRF_TEST_CIM3_LUT = 1
} MMRfTestCIM3FacCmdType;

typedef struct
{
    short  a1; /* bit  0~15, actual: S1.10 */
    short  a2; /* bit 16~31, actual: S1.10 */
} MMRfTestCim3Lut;
typedef struct
{
    MMRfTestCim3Lut    lut[MAX_CIM3_LUT_GAIN_NUM][MAX_CIM3_LUT_CHANNEL_NUM];
} MMRfTestCim3LutSubBand;
typedef struct
{
    MMRfTestCim3LutSubBand    cim3_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];
} MMRfTestCim3LutPerBand;
typedef struct
{
    unsigned short  lte_cim3_meas_ofst_reg[MAX_LTE_CBW_NUM];
} MMRfTestCIM3FacAlgoParam;
typedef struct
{
    unsigned short              cim3_subband_freq[MAX_FHC_TX_FREQ_NUM_EX];
    MMRfTestCIM3FacAlgoParam    cim3_algo_param;
} MMRfTestCim3FacParamSet;
typedef union
{
    MMRfTestCim3FacParamSet    cim3_fac_set;
    MMRfTestCim3LutPerBand     cim3_lut_per_band;
} MMRfTestCim3FacIO;
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    lut_param_type;    /* 0:MMRF_TEST_CIM3_ALGO_PARAM  1:MMRF_TEST_CIM3_LUT  */
    unsigned short    signal_path;
} MMRfTestCim3GetFacParamReq;
typedef struct
{
    unsigned short       rat_idx;
    unsigned short       rf_band_idx;
    unsigned short       lut_param_type;
    unsigned short       signal_path;
    MMRfTestCim3FacIO    param;
} MMRfTestCim3GetFacParamCnf;
META_RESULT __stdcall META_MMRf_GetCim3FacCalParam( const unsigned int ms_timeout, const MMRfTestCim3GetFacParamReq* req, MMRfTestCim3GetFacParamCnf* cnf);
META_RESULT __stdcall META_MMRf_GetCim3FacCalParam_r(  const int meta_handle, const unsigned int ms_timeout, const MMRfTestCim3GetFacParamReq* req, MMRfTestCim3GetFacParamCnf* cnf);
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    rf_band_idx;
    unsigned short    lut_param_type;
    unsigned short    signal_path;
    MMRfTestCim3FacIO param;
} MMRfTestCim3SetFacParamReq;
META_RESULT __stdcall META_MMRf_SetCim3FacCalParam( const unsigned int ms_timeout, const MMRfTestCim3SetFacParamReq* req);
META_RESULT __stdcall META_MMRf_SetCim3FacCalParam_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCim3SetFacParamReq* req);
typedef struct
{
    unsigned short  rat_idx;    /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
    unsigned short  cim3_switch;
} MMRfTestCim3FacEnDisReq;
META_RESULT __stdcall META_MMRf_Cim3Enable( const unsigned int ms_timeout, const MMRfTestCim3FacEnDisReq* req);
META_RESULT __stdcall META_MMRf_Cim3Enable_r(  const int meta_handle, const unsigned int ms_timeout, const MMRfTestCim3FacEnDisReq* req);

/* MMRF Self K */
#define MMRF_MAX_RF_SELF_K_LID_COUNT          (64)
#define MMRF_MAX_RF_SELF_K_STRING_LENGTH      (64)
#define MMRF_MAX_RF_SELF_K_DBG_INFO_COUNT     (128)

#define MMRF_MAX_RF_SELF_K_LID_COUNT_V2       (256)
#define MMRF_MAX_RF_SELF_K_LID_COUNT_PDU      (16)
#define MMRF_MAX_RF_SELF_K_PDU_SIZE           (60<<10)
#define MMRF_MAX_RF_SELF_K_DBG_INFO_COUNT_V2  (256)



typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  do_self_k;      // 0: get total LID num, bypass cal; 1: get total LID num and do cal
} MMRfTestCmdStartRfSelfKReq;

typedef struct
{
   unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
   unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
   unsigned short  do_self_k;      // 0: get total LID num, bypass cal; 1: get total LID num and do cal
} MMRfTestCmdStartRfSelfKReqV2;

typedef struct
{
    unsigned short  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_total_num;
    unsigned short  is_error_occur;
} MMRfTestResultStartRfSelfKCnf;

typedef struct
{
   unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
   unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
   unsigned short  stage_set_sts;  // 0: stage not support, 1: process OK
   unsigned short  total_item_cnt;
   unsigned short  item_index[MMRF_MAX_RF_SELF_K_LID_COUNT_V2];
   unsigned short  item_size[MMRF_MAX_RF_SELF_K_LID_COUNT_V2];  
} MMRfTestResultStartRfSelfKCnfV2;

META_RESULT __stdcall META_MMRf_StartSelfCal( const unsigned int ms_timeout, const MMRfTestCmdStartRfSelfKReq* req, MMRfTestResultStartRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_StartSelfCal_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartRfSelfKReq* req, MMRfTestResultStartRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_StartSelfCal_V2( const unsigned int ms_timeout, const MMRfTestCmdStartRfSelfKReqV2* req, MMRfTestResultStartRfSelfKCnfV2* cnf);
META_RESULT __stdcall META_MMRf_StartSelfCal_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartRfSelfKReqV2* req, MMRfTestResultStartRfSelfKCnfV2* cnf);
typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
} MMRfTestCmdGetRfSelfKReq;

typedef struct
{
   unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
   unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
   unsigned short  total_item_cnt; // total count should be less than 16
   unsigned short  item_index[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // total size should be less than 37kB

} MMRfTestCmdGetRfSelfKReqV2;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
    unsigned short  lid_size;
    unsigned char   cal_data[16 * 1024]; // Max size: 16K
} MMRfTestCmdGetRfSelfKCnf;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
    unsigned short  stage_set_sts;  // 0: stage not support, 1: process OK
    unsigned short  total_item_cnt; // total count should be less than 16
    unsigned short  item_index[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // list of item index
    unsigned short  item_size [MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // size of item
    unsigned short  mem_offset[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // mem offset in peer buffer of each item
    unsigned char   data_buffer[MMRF_MAX_RF_SELF_K_PDU_SIZE];  // total size should be less than 37kB
} MMRfTestCmdGetRfSelfKCnfV2;

META_RESULT __stdcall META_MMRf_GetSelfCalData(  const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKReq* req, MMRfTestCmdGetRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalData_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKReq* req, MMRfTestCmdGetRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalData_V2( const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKReqV2* req, MMRfTestCmdGetRfSelfKCnfV2* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalData_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKReqV2* req, MMRfTestCmdGetRfSelfKCnfV2* cnf);

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
    unsigned short  lid_size;
    unsigned char   cal_data[16 * 1024]; // Max size: 16K
} MMRfTestCmdSetRfSelfKReq;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
    unsigned short  total_item_cnt; // total count should be less than 16
    unsigned short  item_index[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // list of item index
    unsigned short  item_size [MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // size of item
    unsigned short  mem_offset[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // mem offset in peer buffer of each item
    unsigned char   data_buffer[MMRF_MAX_RF_SELF_K_PDU_SIZE];  // total size should be less than 37kB
} MMRfTestCmdSetRfSelfKReqV2;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
} MMRfTestResultSetRfSelfKCnf;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
    unsigned short  stage_set_sts;  // 0: stage not support, 1: process OK
    unsigned short  total_item_cnt; // total count should be less than 16
    unsigned short  item_index[MMRF_MAX_RF_SELF_K_LID_COUNT_PDU]; // total size should be less than 37kB
} MMRfTestResultSetRfSelfKCnfV2;

META_RESULT __stdcall META_MMRf_SetSelfCalData(  const unsigned int ms_timeout, const MMRfTestCmdSetRfSelfKReq* req, MMRfTestResultSetRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_SetSelfCalData_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetRfSelfKReq* req, MMRfTestResultSetRfSelfKCnf* cnf);
META_RESULT __stdcall META_MMRf_SetSelfCalData_V2( const unsigned int ms_timeout, const MMRfTestCmdSetRfSelfKReqV2* req, MMRfTestResultSetRfSelfKCnfV2* cnf);
META_RESULT __stdcall META_MMRf_SetSelfCalData_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetRfSelfKReqV2* req, MMRfTestResultSetRfSelfKCnfV2* cnf);

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
} MMRfTestCmdGetRfSelfKDataLenReq;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_index;
    unsigned short  lid_size;
} MMRfTestCmdGetRfSelfKDataLenCnf;

META_RESULT __stdcall META_MMRf_GetSelfCalDataLen(  const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDataLenReq* req, MMRfTestCmdGetRfSelfKDataLenCnf* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDataLen_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDataLenReq* req, MMRfTestCmdGetRfSelfKDataLenCnf* cnf);

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
} MMRfTestCmdGetRfSelfKStrReq;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
} MMRfTestCmdGetRfSelfKStrReqV2;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_total_num;
    char    key[64/*LID index*/][64/*string length*/];
} MMRfTestCmdGetRfSelfKStrCnf;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
    unsigned short  stage_set_sts;  // 0: stage not support, 1: process OK
    unsigned short  total_item_cnt;
    char            key[MMRF_MAX_RF_SELF_K_LID_COUNT_V2][MMRF_MAX_RF_SELF_K_STRING_LENGTH];
} MMRfTestCmdGetRfSelfKStrCnfV2;

META_RESULT __stdcall META_MMRf_GetSelfCalDataString(  const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKStrReq* req, MMRfTestCmdGetRfSelfKStrCnf* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDataString_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKStrReq* req, MMRfTestCmdGetRfSelfKStrCnf* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDataString_V2( const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKStrReqV2* req, MMRfTestCmdGetRfSelfKStrCnfV2* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDataString_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKStrReqV2* req, MMRfTestCmdGetRfSelfKStrCnfV2* cnf);

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
} MMRfTestCmdGetRfSelfKDbgInfo;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
} MMRfTestCmdGetRfSelfKDbgInfoReqV2;


typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  lid_entry_num;
    char    dbg_info[128/*Entry index*/][64/*string length*/];
} MMRfTestResultGetRfSelfKDbgInfo;

typedef struct
{
    unsigned short  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
    unsigned short  self_k_stage;   // 0: pre-self-K, 1: post-self-K
    unsigned short  stage_set_sts;  // 0: stage not support, 1: process OK
    unsigned short  dbg_info_entry_num;
    char    dbg_info[MMRF_MAX_RF_SELF_K_DBG_INFO_COUNT][MMRF_MAX_RF_SELF_K_STRING_LENGTH];

} MMRfTestResultGetRfSelfKDbgInfoCnfV2;

META_RESULT __stdcall META_MMRf_GetSelfCalDebugInfo( const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDbgInfo* req, MMRfTestResultGetRfSelfKDbgInfo* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDebugInfo_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDbgInfo* req, MMRfTestResultGetRfSelfKDbgInfo* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDebugInfo_V2( const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDbgInfoReqV2* req, MMRfTestResultGetRfSelfKDbgInfoCnfV2* cnf);
META_RESULT __stdcall META_MMRf_GetSelfCalDebugInfo_V2_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfSelfKDbgInfoReqV2* req, MMRfTestResultGetRfSelfKDbgInfoCnfV2* cnf);

#define MMRFC_RSLT_DUMP_TONE_SUPPORT            28
#define MMRFC_RSLT_DUMP_GAIN_SUPPORT            8
#define MMRFC_RSLT_DUMP_CABAND_SUPPORT          5
// Dump Config Margin Check
#define MMRFC_RSLT_DUMP_CFG_MARGIN_NUM          10
#define MMRFC_RSLT_DUMP_DUMP_CFG_NUM            2
#define MMRFC_RSLT_DUMP_RESERVE_NUM             (MMRFC_RSLT_DUMP_CFG_MARGIN_NUM - MMRFC_RSLT_DUMP_DUMP_CFG_NUM)
// Dump Postdata Margin Check
#define MMRFC_RSLT_DUMP_POSTDATA_MARGIN_NUM     5000
#define MMRFC_RSLT_DUMP_POSTDATA_FS_RATE_NUM    1
#define MMRFC_RSLT_DUMP_RESERVE_POSTDATA_NUM    (MMRFC_RSLT_DUMP_POSTDATA_MARGIN_NUM-MMRFC_RSLT_DUMP_POSTDATA_FS_RATE_NUM)



typedef struct
{
    int opt_code;     // IRR/Gain/Phase/GA...etc
    int opt_code2;   // Reserve
    int rat_idx;        // MMRfTestCmd_RatIndicator
    int ca_band[MMRFC_RSLT_DUMP_CABAND_SUPPORT];
    int meas_band_index;
    int test_idx;  // 0:1st_run, 1:rerun, 2:rerun_w_nvram_result
    int test_item;       // 0:MMPOC_RXIRR_IQ_CAL, 1:MMPOC_RXIRR_IQ_CAL(RXIQ), 2:MMPOC_DETIQDC_DNL_CAL, 3:MMPOC_TXIQ_CAL, 4:MMPOC_TXGA_CAL
    int mode_idx;       // RX(0:Primary, 1:Diversity), TX(0:Normal, 1:DPD)
    int cbw_idx;          // 0x0:BW1p4, 0x1:BW3, 0x2:BW5, 0x3:BW10, 0x4:BW15, 0x5:BW20, 0x6:BW30, 0x7:BW35, 0x8:BW40, 0x9:BW50, 0xA:BW60, 0x10GSM_SC, 0x20:WCDMA_SC, 0x21:WCDMA_DC, 0x22:WCDMA_3C, 0x30:TDS_SC, 0x31TDS_DC, 
    int dump_cfg[MMRFC_RSLT_DUMP_DUMP_CFG_NUM]; // MMPOC_RXIRR_IQ_CAL: gain, MMPOC_TXIQ_CAL: subband ; MMPOC_RXIRR_IQ_CAL: tone, MMPOC_TXIQ_CAL: tx_route
    int reserve[MMRFC_RSLT_DUMP_RESERVE_NUM];
}MMRfTestCmdStartRFSelfTestAnalyzer;

typedef struct
{
   int  opt_code;
   int  opt_code2;   
   int  n_tone;
   int  n_gain;     // Dimension depend on RF (8 Slice)
   int  tone_freq[MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  gain_est_pos[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  gain_est_neg[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  phase_est_pos[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  phase_est_neg[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  mean_tone_pos_re[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  mean_tone_pos_im[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];   
   int  mean_tone_neg_re[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];
   int  mean_tone_neg_im[MMRFC_RSLT_DUMP_GAIN_SUPPORT][MMRFC_RSLT_DUMP_TONE_SUPPORT];   
   short  data_dump_i[8192];
   short  data_dump_q[8192];
   /******* Below region share memory size of kal_int32*5400 *******/
   int  fs_rate;  // Change MMRFC_RSLT_DUMP_POSTDATA_FS_RATE_NUM when sizeof(fs_rate) modified
   int  reserve[MMRFC_RSLT_DUMP_RESERVE_POSTDATA_NUM];    // To avoid violate META command buffer limitation, please use these reserve memory size to create new test condition
   /******* Above region share memory size of kal_int32*5400 *******/
   int  status;    // 0:not start, 1:pass, 2:wrong rat, 3:wrong cal item
}MMRfAnalyzerMeasureResult;

typedef struct
{
   MMRfAnalyzerMeasureResult post_result;
}MMRfTestResultStartRFSelfTestAnalyzerRpt;

META_RESULT __stdcall META_MMRf_StartSelfTestAnalyzer( const unsigned int ms_timeout, const MMRfTestCmdStartRFSelfTestAnalyzer* req, MMRfTestResultStartRFSelfTestAnalyzerRpt* cnf);
META_RESULT __stdcall META_MMRf_StartSelfTestAnalyzer_r( const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartRFSelfTestAnalyzer* req, MMRfTestResultStartRFSelfTestAnalyzerRpt* cnf);

typedef struct
{
    unsigned short  dpdAmValueCheckMax;
    unsigned short  dpdAmValueCheckMin;
    short  dpdPmValueCheckMax;
    short  dpdPmValueCheckMin;
} MMRfDpdValueRangeCheck;

typedef struct
{
    short  cim3ValueCheckMax;
    short  cim3ValueCheckMin;
} MMRfCIM3ValueRangeCheck;

typedef struct
{
    unsigned short  paIdx;
    unsigned short  pgaIdx;
} MMRfEachLutIdxMapInfo;

typedef struct
{
    unsigned short  band;
    unsigned short  supportSubBandNum;
} MMRfSubBandInfo;

typedef struct
{
    unsigned short  supportGainNum;
    unsigned short  supportpaSettingNum;
    unsigned short  pgaMaxNumForEachPA[MAX_DPD_PA_GAIN_NUM];
    MMRfSubBandInfo         subBandInfo[MMRF_MAX_BAND_NUM];
    MMRfDpdValueRangeCheck  valueRangeCheck;
    MMRfEachLutIdxMapInfo   eachLutIdxInfo[MAX_DPD_AM_LUT_GAIN_NUM] ;
} MMRfDpdLutConfig;

typedef struct
{
    unsigned short  supportGainNum;
    unsigned short  supportpaSettingNum;
    unsigned short  pgaMaxNumForEachPA[MAX_CIM3_PA_GAIN_NUM];
    MMRfSubBandInfo          subBandInfo[MMRF_MAX_BAND_NUM];
    MMRfCIM3ValueRangeCheck  valueRangeCheck;
    MMRfEachLutIdxMapInfo    eachLutIdxInfo[MAX_CIM3_LUT_GAIN_NUM];
} MMRfCim3LutConfig;

typedef union
{
    MMRfDpdLutConfig   dpdLutConfig;
    MMRfCim3LutConfig  cim3LutConfig;
} MMRfDpdCim3LutConfig;

typedef struct
{
    unsigned short  rat_idx;
    unsigned short  lut_type;  ///< 0 for DDP, 1 for Cim3
} MMRfTestCmdGetLUTConfig;

typedef struct
{
    unsigned short  rat_idx;
    unsigned short  lut_type;
    MMRfDpdCim3LutConfig  param;
} MMRfTestResultGetLUTConfig;

/**
 * \brief non-reentrant version of META_MMRf_GetDpdCim3LUTConfig_r
 */
META_RESULT __stdcall META_MMRf_GetDpdCim3LUTConfig(const unsigned int ms_timeout, const MMRfTestCmdGetLUTConfig* req, MMRfTestResultGetLUTConfig* cnf);

/**
 * \details Get DPD CIM3 LUT configuration for MMRF tool GUI usage
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req Get DPD CIM3 LUT configuration parameter
 * \param cnf Result for DPD CIM3 LUT configuration
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_GetDpdCim3LUTConfig_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetLUTConfig* req, MMRfTestResultGetLUTConfig* cnf);
typedef struct
{
    unsigned short  rat_idx;       
    unsigned char   tas_cfg;
} MMRfTestCmdCfgTas;
typedef struct
{
    unsigned short rat_idx;
} MMRfTestResultCfgTas;
/**
 * \brief non-reentrant version of META_MMRf_ForceTasSwitch_r
 */
META_RESULT __stdcall META_MMRf_ForceTasSwitch(const unsigned int ms_timeout, const MMRfTestCmdCfgTas* req, MMRfTestResultCfgTas* cnf);
/**
 * \details Configure DPDT switch mode
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param tas_cfg DPDT switch configuration
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_ForceTasSwitch_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdCfgTas* req, MMRfTestResultCfgTas* cnf);
#define MAX_MMRF_ET_NUM_BAND                  31
#define MAX_MMRF_ET_NUM_SUBBAND                8
#define MAX_MMRF_ET_NUM_RB_IDX                16
#define MAX_MMRF_ET_NUM_RB_IDX_V2             36
#define MAX_MMRF_ET_LUT_PWR_NUM               32
#define MAX_MMRF_ET_NUM_CBW                    6
#define MAX_MMRF_ET_NUM_TEMP                   8
#define MMRF_MAX_LTE_ET_SET_DATA_NUM          13
#define MMRF_MAX_LTE_ET_GET_DATA_NUM       MMRF_MAX_LTE_ET_SET_DATA_NUM
#define ET_NUM_BACKOFF                         2
#define ET_NUM_POUTGAINOFF                     4
#define ERF_FILTER_MAX_SUPPORT_BAND_NUM        5
#define ERF_HRM_MAX_SUPPORT_BAND_NUM           5
#define MAX_FHC_TX_TYPE1_ROUTE_NUM_V2_FOR_ET 256
#define ERF_MAX_BAND_NUM_V2_FOR_ET            35
#define MMRF_MAX_ET_NUM_ROUTE              (MAX_FHC_TX_TYPE1_ROUTE_NUM_V2_FOR_ET + ERF_MAX_BAND_NUM_V2_FOR_ET + ERF_FILTER_MAX_SUPPORT_BAND_NUM + ERF_HRM_MAX_SUPPORT_BAND_NUM)
#define MMRF_MAX_ET_START_ROUTE_NUM_V2        49
#define MAX_MMRF_ET_NUM_CBW_V2                 9
#define MMRF_MAX_ET_NUM_ROUTE_EX             522   

typedef enum
{
   ERF_TEST_LTE_ET_V1 = 0,
   ERF_TEST_LTE_ET_V2 = 1
}ERfTestLteEtGeneration;

typedef struct
{
   unsigned short rat_idx; /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
} MMRfTestCmdEtCalStartDim;
typedef struct
{
   unsigned short GainComp_dB_0[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   short GainComp_dB_1[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   short pa_gain_adjustment[MAX_MMRF_ET_NUM_BAND];
   short GrpDelayoffset_0[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   short GrpDelayoffset_1[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   unsigned short ETKStep2VpaTarget[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short ETKStep2Gain[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short ETKStep2DC[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short ETKFlag;
} MMRfTestCmdEtCalStartParam;
typedef struct
{
    MMRfTestCmdEtCalStartDim   et_cal_start_dim;
    MMRfTestCmdEtCalStartParam et_cal_start_param;
} MMRfTestCmdStartEtCalReq;
/**
 * \brief non-reentrant version of META_MMRf_StartEtCal_r
 */
META_RESULT __stdcall META_MMRf_StartEtCal(const unsigned int ms_timeout, const MMRfTestCmdStartEtCalReq* req);
/**
 * \details Start ET calibration
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req ET cal parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_StartEtCal_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartEtCalReq* req);
typedef struct
{
   unsigned short rat_idx;   
   unsigned short rf_band_idx;
   unsigned short signal_path;
} MMRfTestCmdEtCalSetGetDim;
typedef struct
{
   MMRfTestCmdEtCalSetGetDim et_cal_set_get_dim;
} MMRfTestCmdGetEtCalSetting;
typedef struct
{
   unsigned short VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   short          VinPmLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   unsigned short VinAmLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   short          PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW];
   short          Pout_max[MAX_MMRF_ET_NUM_SUBBAND];
   short          Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short GainComp_dB [MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
   short          PathDelayOffsetByTemp[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW][MAX_MMRF_ET_NUM_TEMP];
   short          GrpDlyOfstBySubband[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   short          PaGainAdjustStep1;
   short          PaGainFineTuneStep1[MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short TwoLUTPwrThreshold[MAX_MMRF_ET_NUM_SUBBAND];
   unsigned int   EtCalDoneFlag;
} MMRfTestCmdEtCalResult_0;
typedef struct
{
   unsigned short VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   short          VinPmLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   unsigned short VinAmLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM];
   short          PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW];
   short          Pout_max[MAX_MMRF_ET_NUM_SUBBAND];
   short          Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short GainComp_dB[MAX_MMRF_ET_NUM_SUBBAND];
   unsigned short GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
   short          GrpDlyOfstBySubband[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
} MMRfTestCmdEtCalResult_1;
typedef struct
{
   MMRfTestCmdEtCalResult_0 et_cal_fac_param_0;   
   MMRfTestCmdEtCalResult_1 et_cal_fac_param_1;
} MMRfTestResultGetEtCalSetting;
/**
 * \brief non-reentrant version of META_MMRf_GetEtCalSetting_r
 */
META_RESULT __stdcall META_MMRf_GetEtCalSetting(const unsigned int ms_timeout, const MMRfTestCmdGetEtCalSetting* req, MMRfTestResultGetEtCalSetting* cnf);
/**
 * \details Get ET calibration result
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req get ET cal setting parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_GetEtCalSetting_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetEtCalSetting* req, MMRfTestResultGetEtCalSetting* cnf);
typedef struct
{
   MMRfTestCmdEtCalSetGetDim     et_cal_set_get_dim;
   MMRfTestResultGetEtCalSetting et_cal_fac_param;
} MMRfTestCmdSetEtCalSetting;
/**
 * \brief non-reentrant version of META_MMRf_GetEtCalSetting_r
 */
META_RESULT __stdcall META_MMRf_SetEtCalSetting(const unsigned int ms_timeout, const MMRfTestCmdSetEtCalSetting* req);
/**
 * \details Get ET calibration result
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req get ET cal setting parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_SetEtCalSetting_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetEtCalSetting* req);
typedef struct
{
    unsigned short rat_idx;
} MMRfTestCmdEtPathDelayCheckResult;
typedef struct
{
    unsigned int   EtCalDoneFlag[MAX_MMRF_ET_NUM_BAND];                        /*to check if FHC/ETK done already*/
    unsigned short Band[MAX_MMRF_ET_NUM_BAND];                                 /*band indicator*/
    unsigned short SubbandFreq[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND]; /*subband frequency*/
} MMRfTestResultEtPathDelayCheckResult;
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResult(const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResult* req, MMRfTestResultEtPathDelayCheckResult* cnf);
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResult_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResult* req, MMRfTestResultEtPathDelayCheckResult* cnf);
typedef struct
{
    unsigned short rat_idx;
    unsigned short Band;
    unsigned short SubbandFreq;
    unsigned short RbIdx;
    short          Offset;
    unsigned short signal_path;
} MMRfTestCmdEtPathDelayStartSetting;
META_RESULT __stdcall META_MMRf_StartEtPathDelaySearch(const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayStartSetting* req);
META_RESULT __stdcall META_MMRf_StartEtPathDelaySearch_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayStartSetting* req);
typedef enum
{
    MMRF_TEST_ET_NORMAL_TX_MODE = 0,
    MMRF_TEST_ET_FORCE_APT_MDOE = 1,
    MMRF_TEST_ET_FORCE_ET_MDOE = 2
} MMRfTestETMode;

typedef struct  
{
    short la_gain;
    short la_dac;
    short lfp_dac;
    short hfp_dac;
} MMRfForceEtSetting;

typedef union  
{
    MMRfForceEtSetting force_et_setting;
} MMRfEtSetting;
typedef struct
{
    unsigned short rat_idx;
    unsigned short et_mode; 
    MMRfEtSetting et_setting;
} MMRfTestCmdEtModeSetting;
/**
 * \brief non-reentrant version of META_MMRf_EtModeSetting_r
 */
META_RESULT __stdcall META_MMRf_EtModeSetting(const unsigned int ms_timeout, const MMRfTestCmdEtModeSetting* req);
/**
 * \details ET mode setting before staring TX
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req ET mode setting configuration
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_EtModeSetting_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtModeSetting* req);


typedef enum
{
   MMRF_TEST_TOOL_USAGE_NORMAL      = 0,
   MMRF_TEST_TOOL_USAGE_K           = 1,
   MMRF_TEST_TOOL_USAGE_ET_K        = 2,
   MMRF_TEST_TOOL_USAGE_DPD_START   = 3,
   MMRF_TEST_TOOL_USAGE_DPD_DEFAULT = 4
   
} MMRfTestSetToolUsageToL1ModeType;

typedef struct
{
    unsigned short  rat_idx;               /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
    unsigned short  route_num;         /* The number of route in this start command */ 
    unsigned short  cmd_set_done;   /* last start command indicator. 0:No, 1:Yes */
} MMRfTestCmdEtCalStartDimV2;

typedef struct
{
    /* 92 ET increase */
    unsigned short    rf_band;
    unsigned short    route_idx;
    unsigned short    path_select;
    /*92 ET PA Gain k increase*/
    unsigned short    pa_supply_voltage_et;
    unsigned short    GainComp_dB_0[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    GainComp_dB_1[MAX_MMRF_ET_NUM_SUBBAND];
    short             pa_gain_adjustment[MAX_MMRF_ET_NUM_SUBBAND];
    short             GrpDelayoffset_0[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX_V2];
    short             GrpDelayoffset_1[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX_V2];
    unsigned short    ETKStep2VpaTarget[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    ETKStep2Gain[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    ETKStep2DC[MAX_MMRF_ET_NUM_SUBBAND]; 
    unsigned short    ETKFlag;
} MMRfTestCmdEtCalStartParamV2;


typedef struct
{
    MMRfTestCmdEtCalStartDimV2   et_cal_start_dim_v2;
    MMRfTestCmdEtCalStartParamV2 et_cal_start_param_v2[MMRF_MAX_ET_START_ROUTE_NUM_V2];
} MMRfTestCmdStartEtCalReqV2;

/**
 * \brief non-reentrant version of META_MMRf_StartEtCal_V2_r
 */
META_RESULT __stdcall META_MMRf_StartEtCal_V2(const unsigned int ms_timeout, const MMRfTestCmdStartEtCalReqV2* req);
/**
 * \details Start ET calibration for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req ET cal parameters
 * \param cnf ET cal confirm parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_StartEtCal_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartEtCalReqV2* req);

typedef struct
{
    unsigned short  route_idx;
    unsigned short  path_select;
} MMRfTestEtRouteInfo;

typedef struct
{
    unsigned short               route_num;
    MMRfTestEtRouteInfo  route_info[MMRF_MAX_LTE_ET_GET_DATA_NUM];
} MMRfTestCmdGetEtCalSettingV2;

typedef struct
{
    unsigned short    rf_band;
    unsigned short    route_idx;
    unsigned short    path_select;
    unsigned short    VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    short             VinPmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    unsigned short    VinAmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    short             PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW_V2];     /* by subband, by number of CBWs */
    short             Pout_max [MAX_MMRF_ET_NUM_SUBBAND];
    short             Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    GainComp_dB[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
    short             GrpDlyOfstBySubband  [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX_V2];
    short             PaGainAdjustStep1[MAX_MMRF_ET_NUM_SUBBAND];     //92 increase by subband
    short             PaGainFineTuneStep1[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short    TwoLUTPwrThreshold[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned int      EtCalDoneFlag;
} MMRfTestCmdEtCalResultV2_0;

typedef struct
{
    unsigned short   VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    short            VinPmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    unsigned short   VinAmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
    short            PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW_V2];     /* by subband, by number of CBWs */
    short            Pout_max [MAX_MMRF_ET_NUM_SUBBAND];
    short            Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short   GainComp_dB[MAX_MMRF_ET_NUM_SUBBAND];
    unsigned short   GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
    short            GrpDlyOfstBySubband[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX_V2];
    unsigned short   reserve1;                      // pm_switch
    unsigned short   reserve2[ET_NUM_BACKOFF];      //backoff_case
    short            reserve3[ET_NUM_POUTGAINOFF];  //Pout_gain_offset_temp
    /* 92 ET increase, PA gain-K */
    unsigned short   pa_supply_voltage_et;     
} MMRfTestCmdEtCalResultV2_1;

typedef enum
{
    MMRF_TEST_GET_ET_INVALID  = 0,
    MMRF_TEST_GET_ET_OK       = 1
} MMRfTest_GetEtCalResult_CoarseStatus;

typedef struct
{
    MMRfTest_GetEtCalResult_CoarseStatus   get_status;
    unsigned short                         route_num;
} MMRfTestResultGetEtRptV2;

typedef struct
{
    MMRfTestCmdEtCalResultV2_0 et_cal_fac_param_v2_0;
    MMRfTestCmdEtCalResultV2_1 et_cal_fac_param_v2_1;
} MMRfTestEtCalDataV2;

typedef struct
{
    MMRfTestResultGetEtRptV2   et_get_result_rpt;
    MMRfTestEtCalDataV2        et_get_cal_data_param[MMRF_MAX_LTE_ET_GET_DATA_NUM];
} MMRfTestResultGetEtCalSettingV2;

/**
 * \brief non-reentrant version of META_MMRf_GetEtCalSetting_V2_r
 */
META_RESULT __stdcall META_MMRf_GetEtCalSetting_V2(const unsigned int ms_timeout, const MMRfTestCmdGetEtCalSettingV2* req, MMRfTestResultGetEtCalSettingV2* cnf);
/**
 * \details Get ET calibration result for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req get ET cal setting parameters
 * \param cnf ET cal setting result parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_GetEtCalSetting_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetEtCalSettingV2* req, MMRfTestResultGetEtCalSettingV2* cnf);

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
    unsigned short  rat_idx;
    unsigned short  route_num;
} MMRfTestCmdEtCalSetDimV2;

typedef struct
{
    MMRfTestCmdEtCalSetDimV2     et_cal_set_dim_v2;
    MMRfTestEtCalDataV2          et_cal_fac_param_v2[MMRF_MAX_LTE_ET_SET_DATA_NUM];
} MMRfTestCmdSetEtCalSettingV2;
/**
 * \brief non-reentrant version of META_MMRf_SetEtCalSetting_V2_r
 */
META_RESULT __stdcall META_MMRf_SetEtCalSetting_V2(const unsigned int ms_timeout, const MMRfTestCmdSetEtCalSettingV2* req);
/**
 * \details Get ET calibration result for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req set ET cal setting parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_SetEtCalSetting_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetEtCalSettingV2* req);


typedef struct
{
   unsigned short    rat_idx;
} MMRfTestCmdEtPathDelayCheckResultV2;

#define MMRF_MAX_ET_ROUTE_NUM_TYPE_1 (0)
#define MMRF_MAX_ET_ROUTE_NUM_TYPE_2 (1)
typedef struct
{
   unsigned int     SwOptMode[MMRF_MAX_ET_NUM_ROUTE]; // 0:invalid 1: ET mode 2:APT mode
   unsigned short   Band[MMRF_MAX_ET_NUM_ROUTE];
   unsigned short   Route[MMRF_MAX_ET_NUM_ROUTE];
   unsigned short   PathSelect[MMRF_MAX_ET_NUM_ROUTE];
   unsigned short   SubbandFreq[MMRF_MAX_ET_NUM_ROUTE][MAX_MMRF_ET_NUM_SUBBAND];
} MMRfTestResultEtPathDelayCheckResultV2;

typedef struct
{
   unsigned int     SwOptMode[MMRF_MAX_ET_NUM_ROUTE_EX]; // 0:invalid 1: ET mode 2:APT mode
   unsigned short   Band[MMRF_MAX_ET_NUM_ROUTE_EX];
   unsigned short   Route[MMRF_MAX_ET_NUM_ROUTE_EX];
   unsigned short   PathSelect[MMRF_MAX_ET_NUM_ROUTE_EX];
   unsigned short   SubbandFreq[MMRF_MAX_ET_NUM_ROUTE_EX][MAX_MMRF_ET_NUM_SUBBAND];
} MMRfTestResultEtPathDelayCheckResultExV2;

/**
 * \brief non-reentrant version of META_MMRf_GetEtPathDelayCheckResult_V2_r
 */
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResult_V2(const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResultV2* req, MMRfTestResultEtPathDelayCheckResultV2* cnf);
/**
 * \details check ET delay search result for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req check path delay result parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResult_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResultV2* req, MMRfTestResultEtPathDelayCheckResultV2* cnf);

/**
 * \brief non-reentrant version of META_MMRf_GetEtPathDelayCheckResulteEx_V2_r
 */
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResultEx_V2(const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResultV2* req, MMRfTestResultEtPathDelayCheckResultExV2* cnf);
META_RESULT __stdcall META_MMRf_GetEtPathDelayCheckResultEx_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayCheckResultV2* req, MMRfTestResultEtPathDelayCheckResultExV2* cnf);

typedef struct
{
   unsigned short    rf_band;
   unsigned short    route_idx;
   unsigned short    path_select;
   unsigned short    rat_idx;
   unsigned short    SubbandFreq;
   unsigned short    RbIdx;
   short             Offset;
} MMRfTestCmdEtPathDelayStartSettingV2;
/**
 * \brief non-reentrant version of META_MMRf_StartEtPathDelaySearch_V2_r
 */
META_RESULT __stdcall META_MMRf_StartEtPathDelaySearch_V2(const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayStartSettingV2* req);
/**
 * \details start ET delay search for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req start ET delay search parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_StartEtPathDelaySearch_V2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtPathDelayStartSettingV2* req);    
typedef enum
{
    MMRF_TEST_PA_GAIN_ADJUST_OFF  = 0,
    MMRF_TEST_PA_GAIN_ADJUST_ON   = 1
} MMRfTestPaGainAdjustModeType;
typedef struct
{
   unsigned short                  rat_idx;
   unsigned short                  pa_supply_voltage_et;
   unsigned short                  target_power_level; 
   MMRfTestPaGainAdjustModeType    mode_type; 
} MMRfTestCmdPaGainAdjustReqParam;
/**
 * \brief non-reentrant version of META_MMRf_StartEtPaGainAdjust
 */
META_RESULT __stdcall META_MMRf_StartEtPaGainAdjust(const unsigned int ms_timeout, const MMRfTestCmdPaGainAdjustReqParam* req);
/**
 * \details start ET PA gain adjust for 92 modem version
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param req PA gain adjust parameters
 * \retval META_SUCCESS Successful
 */
META_RESULT __stdcall META_MMRf_StartEtPaGainAdjust_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdPaGainAdjustReqParam* req);    
typedef struct
{
   unsigned short rat_idx;
   unsigned short toolUsage;  /* 0:Normal; 1:Calibration; 2:ET calibration mode */
} MMRfTestCmdEtSetToolUsage;
META_RESULT __stdcall META_MMRf_SetToolUsage(const unsigned int ms_timeout, const MMRfTestCmdEtSetToolUsage* req);
META_RESULT __stdcall META_MMRf_SetToolUsage_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdEtSetToolUsage* req);
#define MMRF_MAX_TADC_LEV_NUM                     (8)
#define MMRF_MAX_TADC_SET_NUM                     (8)
typedef struct
{
    unsigned short temp_dac[MMRF_MAX_TADC_SET_NUM][MMRF_MAX_TADC_LEV_NUM];
} MMRfTestCmdSetTadcSetting;
META_RESULT __stdcall META_MMRf_SetTadcSetting(const unsigned int ms_timeout, const MMRfTestCmdSetTadcSetting* req);
META_RESULT __stdcall META_MMRf_SetTadcSetting_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetTadcSetting* req);
typedef struct
{
    short temp_degree[MMRF_MAX_TADC_LEV_NUM];
    unsigned short temp_dac[MMRF_MAX_TADC_SET_NUM][MMRF_MAX_TADC_LEV_NUM];
} MMRfTestResultGetTadcSetting;
META_RESULT __stdcall META_MMRf_GetTadcSetting(const unsigned int ms_timeout, MMRfTestResultGetTadcSetting* cnf);
META_RESULT __stdcall META_MMRf_GetTadcSetting_r(const int meta_handle, const unsigned int ms_timeout, MMRfTestResultGetTadcSetting* cnf);
typedef struct
{
    unsigned short measure_count;
} MMRfTestCmdGetRfTemp;
typedef struct
{
    unsigned int sum[MMRF_MAX_TADC_SET_NUM];
} MMRfTestResultGetRfTemp;
META_RESULT __stdcall META_MMRf_GetRfTemp(const unsigned int ms_timeout, const MMRfTestCmdGetRfTemp* req, MMRfTestResultGetRfTemp* cnf);
META_RESULT __stdcall META_MMRf_GetRfTemp_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetRfTemp* req, MMRfTestResultGetRfTemp* cnf);
typedef struct
{
    short status[MMRF_MAX_TADC_SET_NUM];
    short tadc_dac[MMRF_MAX_TADC_SET_NUM];
    short temperature[MMRF_MAX_TADC_SET_NUM];
    short temp_idx[MMRF_MAX_TADC_SET_NUM];
} MMRfTestResultGetTemperatureInfo;
META_RESULT __stdcall META_MMRf_GetTemperatureInfo(const unsigned int ms_timeout, MMRfTestResultGetTemperatureInfo* cnf);
META_RESULT __stdcall META_MMRf_GetTemperatureInfo_r(const int meta_handle, const unsigned int ms_timeout, MMRfTestResultGetTemperatureInfo* cnf);
typedef struct
{
    unsigned short freq[MAX_DPD_DELAY_K_SUBBAND_NUM][MAX_MMRF_ET_NUM_CBW];
} MMRfTestDpdPathDelaySubbandFreq;
typedef struct
{
    unsigned short rat_idx;
} MMRfTestCmdDpdPathDelayCheckResult;
typedef struct
{
    unsigned int                     dpd_cal_done_flag[MAX_MMRF_ET_NUM_BAND];
    unsigned short                   band[MAX_MMRF_ET_NUM_BAND];
    MMRfTestDpdTrAbsolute            tr_init[MAX_MMRF_ET_NUM_BAND][MAX_DPD_DELAY_K_SPLIT_BAND_NUM];
    MMRfTestDpdPathDelaySubbandFreq  subband_freq[MAX_MMRF_ET_NUM_BAND][MAX_DPD_DELAY_K_SPLIT_BAND_NUM];
} MMRfTestResultDpdPathDelayCheckResult;
META_RESULT __stdcall META_MMRf_GetDpdPathDelayCheckResult(const unsigned int ms_timeout, const MMRfTestCmdDpdPathDelayCheckResult* req, MMRfTestResultDpdPathDelayCheckResult* cnf);
META_RESULT __stdcall META_MMRf_GetDpdPathDelayCheckResult_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdDpdPathDelayCheckResult* req, MMRfTestResultDpdPathDelayCheckResult* cnf);
typedef struct
{
    unsigned short    rat_idx;
    unsigned short    band;
    unsigned short    subband_freq;
    unsigned short    cbw_idx;
    short             tr_value;
    unsigned short    signal_path;
} MMRfTestCmdDpdPathDelayStartSetting;
META_RESULT __stdcall META_MMRf_StartDpdPathDelaySearch(const unsigned int ms_timeout, const MMRfTestCmdDpdPathDelayStartSetting* req);
META_RESULT __stdcall META_MMRf_StartDpdPathDelaySearch_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdDpdPathDelayStartSetting* req);
#define MMRF_DPD_LTE_MAX_PATH_DELAY_SET_SUPPORT_ROUTE_NUM_V2   (210)
#define MMRF_DPD_LTE_MAX_PATH_DELAY_GET_SUPPORT_ROUTE_NUM_V2   (260)
#define MMRF_DPD_LTE_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2        (35)
#define MMRF_DPD_WCDMA_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2      (5)
typedef struct
{
    unsigned short    rf_band;
    unsigned short    comp_route;
    unsigned short    path_select;
    unsigned short    subband_freq[MAX_FHC_TX_FREQ_NUM_EX];
    short             dpd_tr[MAX_FHC_TX_FREQ_NUM_EX][MMRF_MAX_LTE_CBW_NUM];
} MMRfTestCmdSetLteDpdPathDelaySearchRouteInfoV2;
typedef struct
{
    unsigned short                                    route_num;
    MMRfTestCmdSetLteDpdPathDelaySearchRouteInfoV2    route_info[MMRF_DPD_LTE_MAX_PATH_DELAY_SET_SUPPORT_ROUTE_NUM_V2];
} MMRfTestCmdSetLteDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short    rf_band;
    unsigned short    subband_freq[CAL_UARFCN_SECTION];
    short             dpd_tr[CAL_UARFCN_SECTION];
} MMRfTestCmdSetWcdmaDpdPathDelaySearchBandInfoV2;
typedef struct
{
    unsigned short                                     band_num;
    MMRfTestCmdSetWcdmaDpdPathDelaySearchBandInfoV2    band_info[MMRF_DPD_WCDMA_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2];
} MMRfTestCmdSetWcdmaDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short                                     rat_idx;
    union
    {
        MMRfTestCmdSetLteDpdPathDelaySearchInfoV2      lte_dpd_delay_req;
        MMRfTestCmdSetWcdmaDpdPathDelaySearchInfoV2    wcdma_dpd_delay_req;
    };
} MMRfTestCmdSetDpdPathDelaySearchV2;
META_RESULT __stdcall META_MMRf_SetDpdPathDelaySearchSettingV2(const unsigned int ms_timeout, const MMRfTestCmdSetDpdPathDelaySearchV2* req);
META_RESULT __stdcall META_MMRf_SetDpdPathDelaySearchSettingV2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdSetDpdPathDelaySearchV2* req);
typedef struct
{
    unsigned short    test_times;
    unsigned short    search_band[MMRF_DPD_LTE_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2];
} MMRfTestCmdStartLteDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short    test_times;
    unsigned short    search_band[MMRF_DPD_WCDMA_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2];
} MMRfTestCmdStartWcdmaDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short                                       rat_idx;
    union
    {
        MMRfTestCmdStartLteDpdPathDelaySearchInfoV2      lte_dpd_delay_req;
        MMRfTestCmdStartWcdmaDpdPathDelaySearchInfoV2    wcdma_dpd_delay_req;
    };
} MMRfTestCmdStartDpdPathDelayV2;
typedef struct
{
    unsigned short                                       status;
} MMRfTestResultStartDpdPathDelayV2;
META_RESULT __stdcall META_MMRf_StartDpdPathDelaySearchV2(const unsigned int ms_timeout, const MMRfTestCmdStartDpdPathDelayV2* req, MMRfTestResultStartDpdPathDelayV2* cnf);
META_RESULT __stdcall META_MMRf_StartDpdPathDelaySearchV2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdStartDpdPathDelayV2* req, MMRfTestResultStartDpdPathDelayV2* cnf);
typedef struct
{
    unsigned short    comp_route;
    unsigned short    path_select;
} MMRfTestCmdGetLteDpdPathDelaySearchRouteInfoV2;
typedef struct
{
    unsigned short                                    route_num;
    MMRfTestCmdGetLteDpdPathDelaySearchRouteInfoV2    route_info[MMRF_DPD_LTE_MAX_PATH_DELAY_GET_SUPPORT_ROUTE_NUM_V2];
} MMRfTestCmdGetLteDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short                                    band_num;
} MMRfTestCmdGetWcdmaDpdPathDelaySearchInfoV2;
typedef union
{
    MMRfTestCmdGetLteDpdPathDelaySearchInfoV2      lte_dpd_delay_req;
    MMRfTestCmdGetWcdmaDpdPathDelaySearchInfoV2    wcdma_dpd_delay_req;
} MMRfTestCmdGetDpdPathDelaySearchInfoV2;
typedef struct
{
    unsigned short                                     rat_idx;
    union
    {
        MMRfTestCmdGetLteDpdPathDelaySearchInfoV2      lte_dpd_delay_req;
        MMRfTestCmdGetWcdmaDpdPathDelaySearchInfoV2    wcdma_dpd_delay_req;
    };
} MMRfTestCmdGetDpdPathDelaySearchV2;
typedef struct
{
    unsigned short    rf_band;
    unsigned short    comp_route;
    unsigned short    path_select;
    short             dpd_tr[MAX_FHC_TX_FREQ_NUM_EX][MMRF_MAX_LTE_CBW_NUM];
} MMRfTestResultLteDpdPathDelaySearchRouteInfoV2;
typedef struct
{
    MMRfTestResultLteDpdPathDelaySearchRouteInfoV2 route_info[MMRF_DPD_LTE_MAX_PATH_DELAY_GET_SUPPORT_ROUTE_NUM_V2];
} MMRfTestResultLteDpdPathDelaySearchV2;
typedef struct
{
    unsigned short    rf_band;
    short             dpd_tr[MAX_FHC_TX_FREQ_NUM_EX];
} MMRfTestResultWcdmaDpdPathDelaySearchBandInfoV2;
typedef struct
{
    MMRfTestResultWcdmaDpdPathDelaySearchBandInfoV2    band_info[MMRF_DPD_WCDMA_MAX_PATH_DELAY_SUPPORT_BAND_NUM_V2];
} MMRfTestResultWcdmaDpdPathDelaySearchV2;
typedef struct
{
    union
    {
        MMRfTestResultLteDpdPathDelaySearchV2      lte_dpd_result;
        MMRfTestResultWcdmaDpdPathDelaySearchV2    wcdma_dpd_result;
    };
} MMRfTestResultGetDpdPathDelaySearchV2;
META_RESULT __stdcall META_MMRf_GetDpdPathDelaySearchResultV2(const unsigned int ms_timeout, const MMRfTestCmdGetDpdPathDelaySearchV2* req, MMRfTestResultGetDpdPathDelaySearchV2* cnf);
META_RESULT __stdcall META_MMRf_GetDpdPathDelaySearchResultV2_r(const int meta_handle, const unsigned int ms_timeout, const MMRfTestCmdGetDpdPathDelaySearchV2* req, MMRfTestResultGetDpdPathDelaySearchV2* cnf);

//--------------------------------------------------------------------------//
//  NVRAM                                                                   //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  NVRAM: data structure definition                   //
//-----------------------------------------------------//

// Reset NVRAM
typedef enum
{
    NVRAM_RESET_ALL,        ///< Reset all data items in both of user and system category
    NVRAM_RESET_USER,       ///< Reset data items in user category    --> obsolete! just keep the enum value for backward compatibility.
    NVRAM_RESET_SYSTEM,     ///< Reset data items in system category  --> obsolete! just keep the enum value for backward compatibility.
    NVRAM_RESET_CERTAIN,    ///< Reset certain data item according to LID
    NVRAM_RESET_FACTORY     ///< Reset to factory default value, all the LIDs has FACTORY attribute will be reseted
} ResetCategory;

typedef struct
{
    ResetCategory   category;   ///< Reset category

    const char*      LID;       /**< The name of logical data item ID , it will be used
                                 * if and only if ResetCategory = NVRAM_RESET_CERTAIN,
                                 * in other case you can just assign NULL.
                                 */
} FT_NVRAM_RESET_REQ;

typedef struct
{
    unsigned char   status;     ///< The status of Reset
} FT_NVRAM_RESET_CNF;

// Read from NVRAM
typedef struct
{
    const char*          LID;       ///< The name of logical data item ID
    unsigned short      RID;        ///< Record ID (the first record is 1)
} FT_NVRAM_READ_REQ;

typedef struct
{
    unsigned short      LID;        ///< Logical data item ID of a EF
    unsigned short      RID;        ///< Record ID (the first record is 1)
    unsigned char       status;     ///< 0: read ok; others: read failed.

    unsigned int        len;        /**< [IN] Length of Buffer, [OUT] Length of read data
                                     * The "len" field indicates the size of "buf" you
                                     * allocated. When the data is read back, "len" will
                                     * be replaced with the actual size of the data.
                                     */

    unsigned char*       buf;       ///< Buffer that will contains the content of record
} FT_NVRAM_READ_CNF;

//Write to NVRAM
typedef struct
{
    const char*          LID;       ///< The name of logical data item ID
    unsigned short      RID;        ///< Record ID (the first record is 1)
    unsigned int        len;        ///< Length of write data
    unsigned char*       buf;       ///< Buffer that contains the content of record
} FT_NVRAM_WRITE_REQ;

typedef struct
{
    unsigned short      LID;        ///< Logical data item ID of a EF
    unsigned short      RID;        ///< Record ID (the first record is 1)
    unsigned char       status;     ///< 0: write ok; others: write failed.
} FT_NVRAM_WRITE_CNF;



typedef  struct
{
    short        max_arfcn;          ///< The maximum ARFCN of the indicated sub-band
    char         gain_offset;        ///< The maximum available gain of transceiver of the indicated sub-band
} sAGCGAINOFFSET;

typedef struct
{
    sAGCGAINOFFSET     agcPathLoss[FrequencyBandCount][PLTABLE_SIZE];
} l1cal_agcPathLoss_T;

typedef struct
{
    char gain_offset_middle;
    char gain_offset_low;
} sLNAGAINOFFSET;
/*****************************************************************
 * The lna middle/low depends on the high mode max_arfcn setting
 * (l1cal_agcPathLoss_T: high mode)
 * (l1cal_agcLnaPathLoss_T: middle/low mode)
 ****************************************************************/
typedef struct
{
    sLNAGAINOFFSET     lnaPathLoss[FrequencyBandCount][PLTABLE_SIZE];
} l1cal_lnaPathLoss_T;

typedef struct
{
    unsigned short data[8];    /**< temperature ADC */
} sTEMPERATURE_ADC_L1CAL;

typedef sTEMPERATURE_ADC_L1CAL l1cal_temperatureADC_T;

// crystalAfcData
#define XO_SlopeArea_Num       33  // change from 8 to 33, 8 is obsolete

typedef struct
{
    int     min_freq;
    short   min_dac;
    //int       inv_slope;
} XO_SLOPE_AREA_DATA;

typedef struct
{
    XO_SLOPE_AREA_DATA      XO_SlopeAreaData[XO_SlopeArea_Num];
} l1cal_crystalAfcData_T;

// IMEISV
typedef struct
{
    char            imei[16];
    unsigned char   svn;
    unsigned char   pad;
} IMEISV_struct_T;

// S/W Change
typedef enum
{
    LID_VER_SAME = 0,
    LID_VER_CHANGED
} LID_STATUS;

typedef struct
{
    int     OldVer;
    int     NewVer;
    char    LID[64];
} LID_Info;

typedef struct
{
    int      target_nvramsize;   ///< current NVRAM size on target FAT file system
    int      target_freespace;   ///< current freespace of target FAT file system
    int      target_overhead;    ///< S/W upgrade operation overhead
    int      newdb_nvramsize;    ///< new NVRAM size
    unsigned char    status;     /**< 0 -> [OK] safe to upgrade to new NVRAM
                                  * 1 -> [ERROR] can't retrieve info from target
                                  * 2 -> [ERROR] freespace is not enough to upgrade to new NVRAM
                                  */
} NVRAM_GetDiskInfo_Cnf;

typedef struct
{
    unsigned short tst_port_ps;
    unsigned short         ps_port;
    unsigned long   tst_baudrate_ps;
    unsigned long   ps_baudrate;
    bool           High_Speed_SIM_Enabled;
    unsigned char          swdbg;
    unsigned char          uart_power_setting; /* For DCM, Start [Set UART POWER], CTI  */
    unsigned char          cti_uart_port;
    unsigned long   cti_baudrate;
    unsigned char           tst_port_l1;
    unsigned long   tst_baudrate_l1;
    // Support tst output to memory card
    unsigned char          tst_output_mode;
    unsigned char  usb_logging_mode;
    unsigned short  tst_port_dsp;
    unsigned long   tst_baud_rate_dsp;
} port_setting_struct;
// from: mcu\interface\hwdrv\uart_sw.h

//-----------------------------------------------------//
//  NVRAM: callback function definition                //
//-----------------------------------------------------//
typedef void (__stdcall* META_NVRAM_Reset_CNF)(const FT_NVRAM_RESET_CNF* cnf, const short token, void* usrData);
typedef void (__stdcall* META_NVRAM_Read_CNF)(const FT_NVRAM_READ_CNF* cnf, const short token, void* usrData);
typedef void (__stdcall* META_NVRAM_Write_CNF)(const FT_NVRAM_WRITE_CNF* cnf, const short token, void* usrData);
typedef void (__stdcall* CB_META_NVRAM_GET_DISK_INFO_CNF)(const NVRAM_GetDiskInfo_Cnf* cnf, const short token, void* usrData);

//-----------------------------------------------------//
//  NVRAM: exported function definition                //
//-----------------------------------------------------//
typedef int (__stdcall* CB_META_NVRAM_GET_REMOTE_KEY_LENGTH)(unsigned int* const length, void* usrData);
typedef int (__stdcall* CB_META_NVRAM_GET_REMOTE_KEY)(char* const key, unsigned int key_length, void* usrData);
typedef int (__stdcall* CB_META_NVRAM_GET_REMOTE_DATABASE_LENGTH)(unsigned int* const length, void* usrData);
typedef int (__stdcall* CB_META_NVRAM_GET_REMOTE_DATABASE)(char* const database, unsigned int database_length, void* usrData);
/**
 * Please set before calling META_NVRAM_Init_r if you need to customize the load database/load key operation.
 * getKey/ getKeyLength must be set at the same time (if one of the callback is NULL, then the key is retrieved by file system operation)
 * getDatabase/getDatabaseLength must be set at the same time (if one of the callback is NULL, then database is retrieved by file system operation)
 * \param getKeyLength callback function for remote get length of key
 * \param getKeyLengthArgument argument for remote get length of key callback
 * \param getKey callback function for remote get key
 * \param getKeyArgument argument for remote get key callback
 * \param getDatabaseLength callback function for remote get length of database
 * \param getDatabaseLengthArgument argument for remote get length of key callback
 * \param getDatabase callback function for remote get database
 * \param getDatabaseArgument argument for remote get database callback
 */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SetCallback(
    CB_META_NVRAM_GET_REMOTE_KEY_LENGTH      getKeyLength,      void* getKeyLengthArgument,
    CB_META_NVRAM_GET_REMOTE_KEY             getKey,            void* getKeyArgument,
    CB_META_NVRAM_GET_REMOTE_DATABASE_LENGTH getDatabaseLength, void* getDatabaseLengthArgument,
    CB_META_NVRAM_GET_REMOTE_DATABASE        getDatabase,       void* getDatabaseArgument
);
/**
 * \brief non-reentrant version of META_NVRAM_Init_r
 */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Init(const char* PathName, unsigned long* p_nvram_CatcherTranAddr);
/**
 * \brief init NVRAM database for current handle
 * \deprecated This API is deprecated. Please use META_NVRAM_Init_Ex_Mdtype_r instead
 * \param meta_handle meta handle
 * \param PathName the path to database file
 * \param p_nvram_CatcherTranAddr the handle to the database
 * \sa META_NVRAM_Init_Ex_Mdtype_r
 */
META_RESULT  __stdcall META_NVRAM_Init_r(const int meta_handle, const char* PathName, unsigned long* p_nvram_CatcherTranAddr);
/**
 * \brief non-reentrant version of META_NVRAM_Init_Ex_r
 */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Init_Ex(const unsigned int md_index, const char* db_path, unsigned long* p_active_db_addr);
/**
 * \brief init NVRAM database for specified MD on current handle
 * \deprecated This API is deprecated. Please use META_NVRAM_Init_Ex_Mdtype_r instead
 * \param meta_handle meta handle
 * \param md_index the index of MD
 * \param db_path the path to database file
 * \param p_active_db_addr the handle to the database
 * \sa META_NVRAM_Init_Ex_Mdtype_r
 */
META_RESULT  __stdcall META_NVRAM_Init_Ex_r(const int meta_handle, const unsigned int md_index, const char* db_path, unsigned long* p_active_db_addr);
/**
 * \brief non-reentrant version of META_NVRAM_Init_2_r
 */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Init_2(const char* db1_path, const char* db2_path, unsigned long* p_active_db_addr);
/**
 * \brief init NVRAM database for dual talk project
 * \deprecated This API is deprecated. Please use META_NVRAM_Init_Ex_Mdtype_r instead
 * \param db1_path the path to database file for MD1
 * \param db2_path the path to database file for MD2
 * \param p_active_db_addr the handle to the database
 * \sa META_NVRAM_Init_Ex_Mdtype_r
 */
META_RESULT  __stdcall META_NVRAM_Init_2_r(const int meta_handle, const char* db1_path, const char* db2_path, unsigned long* p_active_db_addr);
/**
 * \brief non-reentrant version of META_NVRAM_Init_Ex_Mdtype_r
 */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Init_Ex_Mdtype(const unsigned int md_index, const unsigned int mdtype_index, const char* db_path, unsigned long* p_active_db_addr);
/**
 * \brief init NVRAM database for specified MD and MDType
 * \param meta_handle meta handle
 * \param md_index the index of MD
 * \param mdtype_index the index of MD software type
 * \param db_path the path to database file
 * \param p_active_db_addr the handle to the database
 * \sa META_NVRAM_Init_Ex_Mdtype_r
 */
META_RESULT  __stdcall META_NVRAM_Init_Ex_Mdtype_r(const int meta_handle, const unsigned int md_index, const unsigned int mdtype_index, const char* db_path, unsigned long* p_active_db_addr);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Reset(const FT_NVRAM_RESET_REQ* req, const META_NVRAM_Reset_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_NVRAM_Reset_r(const int meta_handle, const FT_NVRAM_RESET_REQ* req, const META_NVRAM_Reset_CNF cb, short* token, void* usrData);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Read(const FT_NVRAM_READ_REQ* req, FT_NVRAM_READ_CNF* cnf, const META_NVRAM_Read_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_NVRAM_Read_r(const int meta_handle, const FT_NVRAM_READ_REQ* req, FT_NVRAM_READ_CNF* cnf, const META_NVRAM_Read_CNF cb, short* token, void* usrData);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Write(const FT_NVRAM_WRITE_REQ* req, const META_NVRAM_Write_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_NVRAM_Write_r(const int meta_handle, const FT_NVRAM_WRITE_REQ* req, const META_NVRAM_Write_CNF cb, short* token, void* usrData);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllLIDNameLength(int* len);
META_RESULT  __stdcall META_NVRAM_GetAllLIDNameLength_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllLIDName(char* buf, const int buf_len, int* NofLID);
META_RESULT  __stdcall META_NVRAM_GetAllLIDName_r(const int meta_handle, char* buf, const int buf_len, int* NofLID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetLIDEnumbyName(const char* LID, unsigned int* LID_enum);
META_RESULT  __stdcall META_NVRAM_GetLIDEnumbyName_r(const int meta_handle, const char* LID, unsigned int* LID_enum);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetLIDVersion(const char* LID, unsigned short* ver);
META_RESULT  __stdcall META_NVRAM_GetLIDVersion_r(const int meta_handle, const char* LID, unsigned short* ver);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetDBSWVersion(char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_GetDBSWVersion_r(const int meta_handle, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_CheckDbVersion(const unsigned int md_index, const unsigned int mdtype_index);
META_RESULT  __stdcall META_NVRAM_CheckDbVersion_r(const int meta_handle, const unsigned int md_index, const unsigned int mdtype_index);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecStructNameLength(const char* LID, int* len);
META_RESULT  __stdcall META_NVRAM_GetRecStructNameLength_r(const int meta_handle, const char* LID, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecStructName(const char* LID, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_GetRecStructName_r(const int meta_handle, const char* LID, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllRecFieldNameLength(const char* LID, int* len);
META_RESULT  __stdcall META_NVRAM_GetAllRecFieldNameLength_r(const int meta_handle, const char* LID, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllRecFieldName(const char* LID, char* buf, const int buf_len, int* NofField);
META_RESULT  __stdcall META_NVRAM_GetAllRecFieldName_r(const int meat_handle, const char* LID, char* buf, const int buf_len, int* NofField);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_CheckFieldNameExist(const char* LID, const char* Field, bool* result);
META_RESULT  __stdcall META_NVRAM_CheckFieldNameExist_r(const int meta_handle, const char* LID, const char* Field, bool* result);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecNum(const char* LID, int* num);
META_RESULT  __stdcall META_NVRAM_GetRecNum_r(const int meta_handle, const char* LID, int* num);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecLen(const char* LID, int* len);
META_RESULT  __stdcall META_NVRAM_GetRecLen_r(const int meta_handle, const char* LID, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SetRecFieldValue(const char* LID, const char* field, char* buf, const int buf_len, void* value, const int value_len);
META_RESULT  __stdcall META_NVRAM_SetRecFieldValue_r(const int meta_handle, const char* LID, const char* field, char* buf, const int buf_len, void* value, const int value_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecFieldValue(const char* LID, const char* field, const char* buf, const int buf_len, void* value, const int value_len);
META_RESULT  __stdcall META_NVRAM_GetRecFieldValue_r(const int meta_handle, const char* LID, const char* field, const char* buf, const int buf_len, void* value, const int value_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SetRecFieldBitValue(const char* LID, const char* field, const char* bitname, char* buf, const int buf_len, const int bitvalue);
META_RESULT  __stdcall META_NVRAM_SetRecFieldBitValue_r(const int meta_handle, const char* LID, const char* field, const char* bitname, char* buf, const int buf_len, const int bitvalue);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetRecFieldBitValue(const char* LID, const char* field, const char* bitname, const char* buf, const int buf_len, int* bitvalue);
META_RESULT  __stdcall META_NVRAM_GetRecFieldBitValue_r(const int meta_handle, const char* LID, const char* field, const char* bitname, const char* buf, const int buf_len, int* bitvalue);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_QueryRecField(const char* LID, const char* field, unsigned int* fieldSize, unsigned int* fieldOffset);
META_RESULT  __stdcall META_NVRAM_QueryRecField_r(const int meta_handle, const char* LID, const char* field, unsigned int* fieldSize, unsigned int* fieldOffset);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_QueryIsLIDExist(const char* LID);
META_RESULT  __stdcall META_NVRAM_QueryIsLIDExist_r(const int meta_handle, const char* LID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_ResetToFactoryDefault(unsigned int ms_timeout);
META_RESULT  __stdcall META_NVRAM_ResetToFactoryDefault_r(const int meta_handle, unsigned int ms_timeout);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_LockDown(unsigned int ms_timeout);
META_RESULT  __stdcall META_NVRAM_LockDown_r(const int meta_handle, unsigned int ms_timeout);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_OTP_LockDown(unsigned int ms_timeout);
META_RESULT  __stdcall META_NVRAM_OTP_LockDown_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_NVRAM_GetFilebyEnum_r(const int meta_handle, char* p_output_file, char* file_enum_type);
META_RESULT  __stdcall META_NVRAM_MemoryDump_r(const int meta_handle, char* p_output_file);

//for NVRAM Editor
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_QueryIsFieldStruct(const char* struct_name, const char* field);
META_RESULT  __stdcall META_NVRAM_QueryIsFieldStruct_r(const int meta_handle, const char* struct_name, const char* field);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllFieldNameLength(const char* struct_name, int* len);
META_RESULT  __stdcall META_NVRAM_GetAllFieldNameLength_r(const int meta_handle, const char* struct_name, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAllFieldNameName(const char* struct_name, char* buf, const int buf_len, int* NofField);
META_RESULT  __stdcall META_NVRAM_GetAllFieldNameName_r(const int meta_handle, const char* struct_name, char* buf, const int buf_len, int* NofField);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetFieldTypeNameLength(const char* struct_name, const char* field, int* len);
META_RESULT  __stdcall META_NVRAM_GetFieldTypeNameLength_r(const int meta_handle, const char* struct_name, const char* field, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetFieldTypeName(const char* struct_name, const char* field, const int buf_len, char* buf);
META_RESULT  __stdcall META_NVRAM_GetFieldTypeName_r(const int meta_handle, const char* struct_name, const char* field, const int buf_len, char* buf);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetStructSize(const char* struct_name, int* size);
META_RESULT  __stdcall META_NVRAM_GetStructSize_r(const int meta_handle, const char* struct_name, int* size);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_QueryField(const char* struct_name, const char* field, unsigned int* fieldSize, unsigned int* fieldOffset);
META_RESULT  __stdcall META_NVRAM_QueryField_r(const int meta_handle, const char* struct_name, const char* field, unsigned int* fieldSize, unsigned int* fieldOffset);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetFieldDimension(const char* struct_name, const char* field, int* dim_len);
META_RESULT  __stdcall META_NVRAM_GetFieldDimension_r(const int meta_handle, const char* struct_name, const char* field, int* dim_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetFieldDimensionDefinition(const char* struct_name, const char* field, int dim_len, int* dim_buf);
META_RESULT  __stdcall META_NVRAM_GetFieldDimensionDefinition_r(const int meta_handle, const char* struct_name, const char* field, int dim_len, int* dim_buf);

// S/W Change
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_RetrieveChangeList(void);
META_RESULT  __stdcall META_NVRAM_SWC_RetrieveChangeList_r(const int meta_handle);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_UpdateChangeList(void);
META_RESULT  __stdcall META_NVRAM_SWC_UpdateChangeList_r(const int meta_handle);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_GetAllChangedLIDCount(int* NofLID);
META_RESULT  __stdcall META_NVRAM_SWC_GetAllChangedLIDCount_r(const int meta_handle, int* NofLID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_GetAllChangedLIDName(LID_Info* p_ArrayOfLID, const int NofLID);
META_RESULT  __stdcall META_NVRAM_SWC_GetAllChangedLIDName_r(const int meta_handle, LID_Info* p_ArrayOfLID, const int NofLID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_QueryIfLIDChanged(const char* LID, LID_STATUS*  result);
META_RESULT  __stdcall META_NVRAM_SWC_QueryIfLIDChanged_r(const int meta_handle, const char* LID, LID_STATUS*  result);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_ImportData(LID_Info* p_import_multiple_lid, int num_of_import_multiple_lid, int import_1st_sys_record_size );
META_RESULT  __stdcall META_NVRAM_SWC_ImportData_r(const int meta_handle, LID_Info* p_import_multiple_lid, int num_of_import_multiple_lid, int import_1st_sys_record_size );
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_Database_Compare(const char* PathName, int* p_NumOfNewAddLID, int* p_NumOfModifiedLID, int* p_NumOfDeletedLID);
META_RESULT  __stdcall META_NVRAM_SWC_Database_Compare_r(const int meta_handle, const char* PathName, int* p_NumOfNewAddLID, int* p_NumOfModifiedLID, int* p_NumOfDeletedLID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_Get_Database_Compare_Result(LID_Info* p_ArrayOfNewAddLID, const int NumOfNewAddLID, LID_Info* p_ArrayOfModifiedLID, const int NumOfModifiedLID, LID_Info* p_ArrayOfDeletedLID, const int NumOfDeletedLID);
META_RESULT  __stdcall META_NVRAM_SWC_Get_Database_Compare_Result_r(const int meta_handle, LID_Info* p_ArrayOfNewAddLID, const int NumOfNewAddLID, LID_Info* p_ArrayOfModifiedLID, const int NumOfModifiedLID, LID_Info* p_ArrayOfDeletedLID, const int NumOfDeletedLID);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_Check_FAT_FreeSpace(const CB_META_NVRAM_GET_DISK_INFO_CNF  cb, short* token, void* usrData);
META_RESULT  __stdcall META_NVRAM_SWC_Check_FAT_FreeSpace_r(const int meta_handle, const CB_META_NVRAM_GET_DISK_INFO_CNF  cb, short* token, void* usrData);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_Enable_ForceUpgrade(void);
META_RESULT  __stdcall META_NVRAM_SWC_Enable_ForceUpgrade_r(const int meta_handle);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SWC_Disable_ForceUpgrade(void);
META_RESULT  __stdcall META_NVRAM_SWC_Disable_ForceUpgrade_r(const int meta_handle);

// AGC path loss
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_agcPathLoss_Len(int* len);
META_RESULT  __stdcall META_NVRAM_agcPathLoss_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_agcPathLoss(const l1cal_agcPathLoss_T* loss, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_agcPathLoss_r(const int meta_handle, const l1cal_agcPathLoss_T* loss, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_agcPathLoss(l1cal_agcPathLoss_T* loss, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_agcPathLoss_r(const int meta_handle, l1cal_agcPathLoss_T* loss, const char* buf, const int buf_len);
// AGC path loss (middle/low mode)
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_lnaPathLoss_Len(int* len);
META_RESULT  __stdcall META_NVRAM_lnaPathLoss_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_lnaPathLoss(const l1cal_lnaPathLoss_T* loss, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_lnaPathLoss_r(const int meta_handle, const l1cal_lnaPathLoss_T* loss, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_lnaPathLoss(l1cal_lnaPathLoss_T* loss, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_lnaPathLoss_r(const int meta_handle, l1cal_lnaPathLoss_T* loss, const char* buf, const int buf_len);
// rampTable
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_rampTable_Len(int* len);
META_RESULT  __stdcall META_NVRAM_rampTable_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_rampTable(const l1cal_rampTable_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_rampTable_r(const int meta_handle, const l1cal_rampTable_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_rampTable(l1cal_rampTable_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_rampTable_r(const int meta_handle, l1cal_rampTable_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_rampTable_Len_Ex(int* len);
META_RESULT  __stdcall META_NVRAM_rampTable_Len_Ex_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_rampTable_Ex(const l1cal_rampTable_T_Ex* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_rampTable_Ex_r(const int meta_handle, const l1cal_rampTable_T_Ex* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_rampTable_Ex(l1cal_rampTable_T_Ex* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_rampTable_Ex_r(const int meta_handle, l1cal_rampTable_T_Ex* tbl, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_rampTable_Len_Ex2(int* len);
META_RESULT  __stdcall META_NVRAM_rampTable_Len_Ex2_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_rampTable_Ex2(const l1cal_rampTable_T_Ex2* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_rampTable_Ex2_r(const int meta_handle, const l1cal_rampTable_T_Ex2* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_rampTable_Ex2(l1cal_rampTable_T_Ex2* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_rampTable_Ex2_r(const int meta_handle, l1cal_rampTable_T_Ex2* tbl, const char* buf, const int buf_len);
// GGE temperature ADC
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_temperatureADC(const l1cal_temperatureADC_T* dac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_temperatureADC_r(const int meta_handle, const l1cal_temperatureADC_T* dac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_temperatureADC(l1cal_temperatureADC_T* dac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_temperatureADC_r(const int meta_handle, l1cal_temperatureADC_T* dac, const char* buf, const int buf_len);

// gain rf table : NVRAM_EF_L1_GAINRF_LID
typedef struct
{
    unsigned char m_ucNumOfGainRf;
    short         gain_rf[FrequencyBandCount][MAX_GAIN_RF_NUM];
} l1cal_gainrf_T;
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_gainRf(const l1cal_gainrf_T* gainrf, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_gainRf_r(const int meta_handle, const l1cal_gainrf_T* gainrf, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_gainRf(l1cal_gainrf_T* gainrf, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_gainRf_r(const int meta_handle, l1cal_gainrf_T* gainrf, const char* buf, const int buf_len);

// interRampData
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_interRampData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_interRampData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_interRampData(const l1cal_interRampData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_interRampData_r(const int meta_handle, const l1cal_interRampData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_interRampData(l1cal_interRampData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_interRampData_r(const int meta_handle, l1cal_interRampData_T* tbl, const char* buf, const int buf_len);
// crystalAfcData
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_crystalAfcData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_crystalAfcData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_crystalAfcData(const l1cal_crystalAfcData_T* xo_afc, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_crystalAfcData_r(const int meta_handle, const l1cal_crystalAfcData_T* xo_afc, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_crystalAfcData(l1cal_crystalAfcData_T* xo_afc, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_crystalAfcData_r(const int meta_handle, l1cal_crystalAfcData_T* xo_afc, const char* buf, const int buf_len);
// IMEISV
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Calculate_IMEI_CD(const char* imei, unsigned short* p_cd);
META_RESULT  __stdcall META_NVRAM_Calculate_IMEI_CD_r(const int meta_handle, const char* imei, unsigned short* p_cd);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_IMEISV_Len(int* len);
META_RESULT  __stdcall META_NVRAM_IMEISV_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_IMEISV(const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_IMEISV_r(const int meta_handle, const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_IMEISV_NoCheck(const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_IMEISV_NoCheck_r(const int meta_handle, const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_IMEISV_ex(const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len, bool DoCheckSum);
META_RESULT  __stdcall META_NVRAM_Compose_IMEISV_ex_r(const int meta_handle, const IMEISV_struct_T*  p_imeisv, char* buf, const int buf_len, bool DoCheckSum);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_IMEISV(IMEISV_struct_T*  p_imeisv, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_IMEISV_r(const int meta_handle, IMEISV_struct_T*  p_imeisv, const char* buf, const int buf_len);
// RF Module Configuration
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_RFSpecialCoef_Len(int* len);
META_RESULT  __stdcall META_NVRAM_RFSpecialCoef_Len_r(const int meta_handle, int* len);
// Skyworks
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_SKY74045_RFSpecialCoef(const RF_SKY74045_Coef_T* rf_mod_coef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_SKY74045_RFSpecialCoef_r(const int meta_handle, const RF_SKY74045_Coef_T* rf_mod_coef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_SKY74045_RFSpecialCoef(RF_SKY74045_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_SKY74045_RFSpecialCoef_r(const int meta_handle, RF_SKY74045_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_SKY74117_RFSpecialCoef(const RF_SKY74117_Coef_T* rf_mod_coef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_SKY74117_RFSpecialCoef_r(const int meta_handle, const RF_SKY74117_Coef_T* rf_mod_coef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_SKY74117_RFSpecialCoef(RF_SKY74117_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_SKY74117_RFSpecialCoef_r(const int meta_handle, RF_SKY74117_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
// MT6139B
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_MT6139B_RFSpecialCoef(const RF_MT6139B_Coef_T* rf_mod_coef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_MT6139B_RFSpecialCoef_r(const int meta_handle, const RF_MT6139B_Coef_T* rf_mod_coef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_MT6139B_RFSpecialCoef(RF_MT6139B_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_MT6139B_RFSpecialCoef_r(const int meta_handle, RF_MT6139B_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
// MT6140
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_MT6140tx_PaVbias(const mt6140tx* pavbias, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_MT6140tx_PaVbias_r(const int meta_handle, const mt6140tx* pavbias, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_MT6140tx_PaVbias(mt6140tx* pavbias, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_MT6140tx_PaVbias_r(const int meta_handle, mt6140tx* pavbias, const char* buf, const int buf_len);
// Renesas Bright5P
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_BRIGHT5P_RFSpecialCoef(const RF_BRIGHT5P_Coef_T* rf_mod_coef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_BRIGHT5P_RFSpecialCoef_r(const int meta_handle, const RF_BRIGHT5P_Coef_T* rf_mod_coef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_BRIGHT5P_RFSpecialCoef(RF_BRIGHT5P_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_BRIGHT5P_RFSpecialCoef_r(const int meta_handle, RF_BRIGHT5P_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
// EPSK interRampData
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_EPSK_interRampData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_EPSK_interRampData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_EPSK_interRampData(const l1cal_EPSK_interRampData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_EPSK_interRampData_r(const int meta_handle, const l1cal_EPSK_interRampData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_EPSK_interRampData(l1cal_EPSK_interRampData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_EPSK_interRampData_r(const int meta_handle, l1cal_EPSK_interRampData_T* tbl, const char* buf, const int buf_len);
// TX power rollback table
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TX_Rollback_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TX_Rollback_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TX_Rollback(const l1cal_tx_power_rollback_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TX_Rollback_r(const int meta_handle, const l1cal_tx_power_rollback_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TX_Rollback(l1cal_tx_power_rollback_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TX_Rollback_r(const int meta_handle, l1cal_tx_power_rollback_T* tbl, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_ClosedLoopTXPC_Len(int* len);
META_RESULT  __stdcall META_NVRAM_ClosedLoopTXPC_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_ClosedLoopTXPC(const l1cal_txpc_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_ClosedLoopTXPC_r(const int meta_handle, const l1cal_txpc_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_ClosedLoopTXPC(l1cal_txpc_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_ClosedLoopTXPC_r(const int meta_handle, l1cal_txpc_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AvgW_RFSpecialCoef(const RF_AvgW_Coef_T* rf_mod_coef, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AvgW_RFSpecialCoef_r(const int meta_handle, const RF_AvgW_Coef_T* rf_mod_coef, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AvgW_RFSpecialCoef(RF_AvgW_Coef_T* rf_mod_coef, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AvgW_RFSpecialCoef_r(const int meta_handle, RF_AvgW_Coef_T* rf_mod_coef, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_tempdacData(const ul1cal_tempdacData_T*  dac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_tempdacData_r(const int meta_handle, const ul1cal_tempdacData_T*  dac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_tempdacData(ul1cal_tempdacData_T*  dac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_tempdacData_r(const int meta_handle, ul1cal_tempdacData_T*  dac, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_pathlossData(const ul1cal_pathlossData_T*  pathloss, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_pathlossData_r(const int meta_handle, const ul1cal_pathlossData_T*  pathloss, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_pathlossData(ul1cal_pathlossData_T*  pathloss, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_pathlossData_r(const int meta_handle, ul1cal_pathlossData_T*  pathloss, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_txdacData(const ul1cal_txdacData_T*  txdac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_txdacData_r(const int meta_handle, const ul1cal_txdacData_T*  txdac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_txdacData(ul1cal_txdacData_T*  txdac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_txdacData_r(const int meta_handle, ul1cal_txdacData_T*  txdac, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_txdacData_B(const ul1cal_txdacData_T_B* txdac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_txdacData_B_r(const int meta_handle, const ul1cal_txdacData_T_B* txdac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_txdacData_B(ul1cal_txdacData_T_B*  txdac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_txdacData_B_r(const int meta_handle, ul1cal_txdacData_T_B*  txdac, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_txPaOctLevData(const ul1cal_txPaOctLevData_T* paoctlevdata, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_txPaOctLevData_r(const int meta_handle, const ul1cal_txPaOctLevData_T* paoctlevdata, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPaOctLevData(ul1cal_txPaOctLevData_T* paoctlevdata, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPaOctLevData_r(const int meta_handle, ul1cal_txPaOctLevData_T* paoctlevdata, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_pathlossRxdData(const ul1cal_pathlossRxdData_T*  pathloss, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_pathlossRxdData_r(const int meta_handle, const ul1cal_pathlossRxdData_T*  pathloss, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_pathlossRxdData(ul1cal_pathlossRxdData_T*  pathloss, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_pathlossRxdData_r(const int meta_handle, ul1cal_pathlossRxdData_T*  pathloss, const char* buf, const int buf_len);

/* PA drift compensation data */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_txPaDriftCompData(const ul1Cal_txPaDriftCompData_T* txPaDriftCompData, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_txPaDriftCompData_r(const int meta_handle, const ul1Cal_txPaDriftCompData_T* txPaDriftCompData, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPaDriftCompData(ul1Cal_txPaDriftCompData_T* txPaDriftCompData, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPaDriftCompData_r(const int meta_handle, ul1Cal_txPaDriftCompData_T* txPaDriftCompData, const char* buf, const int buf_len);

/*20130425 for PRACH TX Temp. Comp. */
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Compose_txPRACHTempCompData(const ul1cal_txPrachTmCompData_T* txPrachTmCompData, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Compose_txPRACHTempCompData_r(const int meta_handle, const ul1cal_txPrachTmCompData_T* txPrachTmCompData, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPRACHTempCompData(ul1cal_txPrachTmCompData_T* txPrachTmCompData, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_3G_Decompose_txPRACHTempCompData_r(const int meta_handle, ul1cal_txPrachTmCompData_T* txPrachTmCompData, const char* buf, const int buf_len);

// sBBTxParameters
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BBTXParameters_Len(int* len);
META_RESULT  __stdcall META_NVRAM_BBTXParameters_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_BBTXParameters(const BBTXParameters_T* bbtx, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_BBTXParameters_r(const int meta_handle, const BBTXParameters_T* bbtx, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_BBTXParameters(BBTXParameters_T* bbtx, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_BBTXParameters_r(const int meta_handle, BBTXParameters_T* bbtx, const char* buf, const int buf_len);

// ad6546tx
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_ad6546tx(const ad6546tx* adtx, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_ad6546tx_r(const int meta_handle, const ad6546tx* adtx, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_ad6546tx(ad6546tx* adtx, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_ad6546tx_r(const int meta_handle, ad6546tx* adtx, const char* buf, const int buf_len);

// PORT setting
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_PortSetting_Len(int* len);
META_RESULT  __stdcall META_NVRAM_PortSetting_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_PortSetting(const port_setting_struct* port_setting, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_PortSetting_r(const int meta_handle, const port_setting_struct* port_setting, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_PortSetting(port_setting_struct* port_setting, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_PortSetting_r(const int meta_handle, port_setting_struct* port_setting, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_PortSetting_ex(const port_setting_struct* port_setting, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_PortSetting_ex_r(const int meta_handle, const port_setting_struct* port_setting, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_PortSetting_ex(port_setting_struct* port_setting, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_PortSetting_ex_r(const int meta_handle, port_setting_struct* port_setting, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_GetAutoTestiFlagEnumValue(int* value);
META_RESULT  __stdcall META_NVRAM_GetAutoTestiFlagEnumValue_r(const int meta_handle, int* value);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_SetAutoTestiFlag(void);
META_RESULT  __stdcall META_NVRAM_SetAutoTestiFlag_r(const int meta_handle);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Read_Ex( const unsigned int ms_timeout, const FT_NVRAM_READ_REQ* req, FT_NVRAM_READ_CNF* cnf);
META_RESULT  __stdcall META_NVRAM_Read_Ex_r( const int meta_handle, unsigned int ms_timeout, const FT_NVRAM_READ_REQ* req, FT_NVRAM_READ_CNF* cnf);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Write_Ex(const unsigned int ms_timeout, const FT_NVRAM_WRITE_REQ* req, FT_NVRAM_WRITE_CNF* cnf);
META_RESULT  __stdcall META_NVRAM_Write_Ex_r(const int meta_handle, const unsigned int ms_timeout, const FT_NVRAM_WRITE_REQ* req, FT_NVRAM_WRITE_CNF* cnf);


//---------------------------------------------------------------------------//
//  ASTRONAUT: NVRAM                                                         //
//---------------------------------------------------------------------------//
#if defined(__META_DLL_TD_A__)
/**
 * \addtogroup TDSCDMA
 * @{
 */
#define TD_A_CAL_TEMP_SECTION 8
#define TD_A_CAL_UARFCN_SECTION 15
#define META_TD_A_CAL_LNA_MODE_NUM 3
#define META_TD_A_CAL_PA_MODE_NUM 3
#define META_TD_A_CAL_PA_DATA_NUM 4
#define META_TD_A_CAL_HYSTERESIS_NUM 2
#define META_TD_A_CAL_HYSTERESIS_POINTS 2
typedef struct
{
    unsigned short  tempdacData[TD_A_CAL_TEMP_SECTION];
} a_tl1cal_tempdacData_T;
typedef struct
{
    unsigned short initDac;
    unsigned short slope;
} a_tl1cal_afcData_T;
typedef struct
{
    unsigned int capId;
} a_tl1cal_capData_T;
typedef struct
{
    unsigned short freqTable[TD_A_CAL_UARFCN_SECTION];
    short  compByFreq[META_TD_A_CAL_LNA_MODE_NUM][TD_A_CAL_UARFCN_SECTION];
    short  compByTemp[META_TD_A_CAL_LNA_MODE_NUM][TD_A_CAL_TEMP_SECTION];
} a_tl1cal_pathlossData_T;
typedef struct
{
    unsigned short paData[META_TD_A_CAL_PA_MODE_NUM][META_TD_A_CAL_PA_DATA_NUM];
    short          paPower[META_TD_A_CAL_PA_MODE_NUM][META_TD_A_CAL_PA_DATA_NUM];
    unsigned short freqTable[TD_A_CAL_UARFCN_SECTION];
    short          compByFreq[META_TD_A_CAL_PA_MODE_NUM][TD_A_CAL_UARFCN_SECTION];
    short          compByTemp[META_TD_A_CAL_PA_MODE_NUM][TD_A_CAL_TEMP_SECTION];
    unsigned short paSwitch[META_TD_A_CAL_HYSTERESIS_NUM][META_TD_A_CAL_HYSTERESIS_POINTS];
    short          maxPaPower;
    unsigned short maxPaData;
} a_tl1cal_txdacData_T;
typedef struct
{
    short          pdCompMidChannel[3];
    short          pdCompByFreq[15];
} a_tl1cal_txPdData_T;
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TD_A_TempADC_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TD_A_TempADC_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TempADC(const a_tl1cal_tempdacData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TempADC_r(const int meta_handle, const a_tl1cal_tempdacData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TempADC(a_tl1cal_tempdacData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TempADC_r(const int meta_handle, a_tl1cal_tempdacData_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TD_A_AFCData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TD_A_AFCData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TD_A_AFCData(const a_tl1cal_afcData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TD_A_AFCData_r(const int meta_handle, const a_tl1cal_afcData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_AFCData(a_tl1cal_afcData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_AFCData_r(const int meta_handle, a_tl1cal_afcData_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TD_A_PathLossData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TD_A_PathLossData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TD_A_PathLossData(const a_tl1cal_pathlossData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TD_A_PathLossData_r(const int meta_handle, const a_tl1cal_pathlossData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_PathLossData(a_tl1cal_pathlossData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_PathLossData_r(const int meta_handle, a_tl1cal_pathlossData_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TD_A_TxDacData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TD_A_TxDacData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TxDacData(const a_tl1cal_txdacData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TxDacData_r(const int meta_handle, const a_tl1cal_txdacData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TxDacData(a_tl1cal_txdacData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TxDacData_r(const int meta_handle, a_tl1cal_txdacData_T* tbl, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TD_A_TxPdData_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TD_A_TxPdData_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TxPdData(const a_tl1cal_txPdData_T* tbl, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_TD_A_TxPdData_r(const int meta_handle, const a_tl1cal_txPdData_T* tbl, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TxPdData(a_tl1cal_txPdData_T* tbl, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_TD_A_TxPdData_r(const int meta_handle, a_tl1cal_txPdData_T* tbl, const char* buf, const int buf_len);
/**
 * @}
 */
#endif // end of #if defined(__META_DLL_TD_A__)

//--------------------------------------------------------------------------//
//  BaseBand Testing                                                        //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  BaseBand Testing: data structure definition        //
//-----------------------------------------------------//
typedef struct
{
    unsigned int    addr;       ///< The address of register that is to be read.
} RegRead_Req;

typedef struct
{
    unsigned short  value;      ///< The read back value
    unsigned char   status;     ///< 0: success, others: read register fail.
} RegRead_Cnf;

typedef struct
{
    unsigned int    addr;       ///< The address of register that is to be written.
    unsigned short  value;      ///< The value that is to be written.
} RegWrite_Req;

typedef struct
{
    unsigned char   status;     ///< 0: success, others: write register fail.
} RegWrite_Cnf;

typedef struct
{
    unsigned char   channel;    ///< ADC channel number.
    unsigned short  Meacount;   ///< Number of measure times.
} ADCMeaData_Req;

typedef struct
{
    unsigned int    value;      ///< ADC value, it a sum value of each measurement data.
    unsigned char   status;     ///< 0: success, others: get ADC measurement fail.
} ADCMeaData_Cnf;

//-----------------------------------------------------//
//  BaseBand Testing: callback function definition     //
//-----------------------------------------------------//
typedef void (__stdcall* META_BB_READREG_CNF)(const RegRead_Cnf* result, const short token, void* usrData);
typedef void (__stdcall* META_BB_WRITEREG_CNF)(const RegWrite_Cnf* result, const short token, void* usrData);
typedef void (__stdcall* META_BB_ADCGETMEADATA_CNF)(const ADCMeaData_Cnf* result, const short token, void* usrData);

//-----------------------------------------------------//
//  BaseBand Testing: exported function definition     //
//-----------------------------------------------------//
META_RESULT  __stdcall META_BB_RegRead(const RegRead_Req* req, const META_BB_READREG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_BB_RegRead_r(const int meta_handle, const RegRead_Req* req, const META_BB_READREG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_BB_RegWrite(const RegWrite_Req* req, const META_BB_WRITEREG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_BB_RegWrite_r(const int meta_handle, const RegWrite_Req* req, const META_BB_WRITEREG_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_PMIC_RegRead(unsigned int ms_timeout, const RegRead_Req* req, RegRead_Cnf* cnf);
META_RESULT  __stdcall META_PMIC_RegRead_r(const int meta_handle, unsigned int ms_timeout, const RegRead_Req* req, RegRead_Cnf* cnf);
META_RESULT  __stdcall META_PMIC_RegWrite(unsigned int ms_timeout, const RegWrite_Req* req, RegWrite_Cnf* cnf);
META_RESULT  __stdcall META_PMIC_RegWrite_r(const int meta_handle, unsigned int ms_timeout, const RegWrite_Req* req, RegWrite_Cnf* cnf);
META_RESULT  __stdcall META_BB_ADCGetMeaSumData(const ADCMeaData_Req* req, const META_BB_ADCGETMEADATA_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_BB_ADCGetMeaSumData_r(const int meta_handle, const ADCMeaData_Req* req, const META_BB_ADCGETMEADATA_CNF cb, short* token, void* usrData);
META_RESULT  __stdcall META_BB_ADCGetMeaSumData_Ex(const unsigned int ms_timeout, const ADCMeaData_Req* req, ADCMeaData_Cnf* cnf);
META_RESULT  __stdcall META_BB_ADCGetMeaSumData_Ex_r(const int meta_handle, const unsigned int ms_timeout, const ADCMeaData_Req* req, ADCMeaData_Cnf* cnf);
META_RESULT  __stdcall META_BB_RegRead_Ex(unsigned int ms_timeout, const RegRead_Req* req, RegRead_Cnf* cnf);
META_RESULT  __stdcall META_BB_RegRead_Ex_r(const int meta_handle, unsigned int ms_timeout, const RegRead_Req* req, RegRead_Cnf* cnf);
META_RESULT  __stdcall META_BB_RegWrite_Ex(unsigned int ms_timeout, const RegWrite_Req* req, RegWrite_Cnf* cnf);
META_RESULT  __stdcall META_BB_RegWrite_Ex_r(const int meta_handle, unsigned int ms_timeout, const RegWrite_Req* req, RegWrite_Cnf* cnf);
//----------------------------------------------------//
//                     RTC control                    //
//----------------------------------------------------//
//--------------------------------------------------------------------------//
//  FAT Access                                                              //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  FAT Access: data structure definition              //
//-----------------------------------------------------//
typedef enum
{
    FAT_OPEN_READ = 0,
    FAT_OPEN_WRITE
} FAT_OPEN_MODE;

typedef enum
{
    FAT_FIND_FILE = 0,
    FAT_FIND_FILE_RECURSIVE,
    FAT_FIND_DIR_RECURSIVE
} FAT_FIND_MODE;

typedef enum
{
    FAT12 = 0,
    FAT16,
    FAT32
} FAT_TYPE;

typedef struct
{
    FAT_TYPE        Type;
    unsigned int    SectorsPerCluster;
    unsigned int    TotalSize;
    unsigned int    FreeSpace;
} FAT_DiskInfo_T;

typedef struct
{
    FAT_TYPE        Type;
    unsigned int    SectorsPerCluster;
    unsigned int    TotalSize_high;
    unsigned int    FreeSpace_high;
    unsigned int    TotalSize_low;
    unsigned int    FreeSpace_low;
} FAT_DiskInfo_EX_T;

typedef struct
{
    char m_cDriveLetter;   ///< Target FAT disk drive letter such as: 'C'
    char* m_pcfilepath;    ///< File path of the file we intend to write into target FAT

} FAT_FILE_INFO_REQ_T;

typedef struct
{
    FAT_FILE_INFO_REQ_T req;
    /// target side file path to check whether existing file presents
    const char* targetFilePath;
} FAT_FILE_INFO_REQ_EX_T;

typedef struct
{
    WCHAR m_wDriveLetter;   ///< Target FAT disk drive letter such as: 'C'
    WCHAR* m_pwcFilePath;   ///< File path of the file we intend to write into target FAT
} FAT_UTF_FILE_INFO_REQ_T;

typedef struct
{
    FAT_UTF_FILE_INFO_REQ_T req;
    /// target side file path to check whether existing file presents
    const WCHAR* pwcTargetFilePath;
} FAT_UTF_FILE_INFO_REQ_EX_T;
//-----------------------------------------------------/n
//  FAT Access: callback function definition           //
//-----------------------------------------------------//
typedef int (__stdcall* CALLBACK_META_FAT_PROGRESS)(unsigned char percent, int sent_bytes, int total_bytes, const short token, void* usr_arg);

//-----------------------------------------------------//
//  FAT Access: exported function definition           //
//-----------------------------------------------------//
META_RESULT  __stdcall META_FAT_Open(const char* fat_filepath, FAT_OPEN_MODE  mode, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_Open_r(const int meta_handle, const char* fat_filepath, FAT_OPEN_MODE  mode, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_Close(int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_Close_r(const int meta_handle, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_GetFileSize(const int fs_handle, int* filesize, short* p_token);
META_RESULT  __stdcall META_FAT_GetFileSize_r(const int meta_handle, const int fs_handle, int* filesize, short* p_token);
META_RESULT  __stdcall META_FAT_Read(const int fs_handle, char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Read_r(const int meta_handle, const int fs_handle, char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Write(const int fs_handle, const char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Write_r(const int meta_handle, const int fs_handle, const char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Read_To_File(const int fs_handle, const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Read_To_File_r(const int meta_handle, const int fs_handle, const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Write_By_File(const int fs_handle, const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Write_By_File_r(const int meta_handle, const int fs_handle, const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_Delete(const char* fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_Delete_r(const int meta_handle, const char* fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_Move(const char* fat_filepath, const char* new_fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_Move_r(const int meta_handle, const char* fat_filepath, const char* new_fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_Find_Start(const char* fat_base_dir, const char* fat_find_pattern, FAT_FIND_MODE     find_mode, int* p_find_handle, short* p_token);
META_RESULT  __stdcall META_FAT_Find_Start_r(const int meta_handle, const char* fat_base_dir, const char* fat_find_pattern, FAT_FIND_MODE    find_mode, int* p_find_handle, short* p_token);
META_RESULT  __stdcall META_FAT_Find_Head(int find_handle);
META_RESULT  __stdcall META_FAT_Find_Prev(int find_handle);
META_RESULT  __stdcall META_FAT_Find_Next(int find_handle);
META_RESULT  __stdcall META_FAT_Find_GetFileInfo(int find_handle, char* p_filepath, const int filepath_len, int* p_filesize);
META_RESULT  __stdcall META_FAT_Find_Close(int* p_find_handle);
META_RESULT  __stdcall META_FAT_GetDiskInfo(const char DriveLetter, FAT_DiskInfo_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_GetDiskInfo_r(const int meta_handle, const char DriveLetter, FAT_DiskInfo_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_GetDiskInfo_Ex(const char DriveLetter, FAT_DiskInfo_EX_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_GetDiskInfo_Ex_r(const int meta_handle, const char DriveLetter, FAT_DiskInfo_EX_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_RemoveDir(const char* fat_dirpath);
META_RESULT  __stdcall META_FAT_RemoveDir_r(const int meta_handle, const char* fat_dirpath);

META_RESULT __stdcall META_FAT_CheckEnoughSpace(FAT_FILE_INFO_REQ_T* req);
META_RESULT __stdcall META_FAT_CheckEnoughSpace_r(const int meta_handle, FAT_FILE_INFO_REQ_T* req);
META_RESULT __stdcall META_FAT_CheckEnoughSpaceEx(FAT_FILE_INFO_REQ_EX_T* req_ex);
META_RESULT __stdcall META_FAT_CheckEnoughSpaceEx_r(const int meta_handle, FAT_FILE_INFO_REQ_EX_T* req_ex);

META_RESULT  __stdcall META_FAT_Read_To_File_Ex(const int fs_handle, const char* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg, short* p_token,
        int*   p_stopflag);

META_RESULT  __stdcall META_FAT_Read_To_File_Ex_r(const int meta_handle, const int fs_handle,
        const char* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg, short* p_token,
        int*   p_stopflag);

META_RESULT  __stdcall META_FAT_Write_By_File_Ex(const int fs_handle,
        const char* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg,
        short* p_token,
        int* p_stopfalg);

META_RESULT  __stdcall META_FAT_Write_By_File_Ex_r(const int meta_handle,
        const int fs_handle,
        const char* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg,
        short* p_token,
        int* p_stopflag);

META_RESULT  __stdcall META_FAT_CopyDirFromTarget(const char* dstDir, unsigned int dstDirLength, const char* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_CopyDirFromTarget_r(const int meta_handle, const char* dstDir, unsigned int dstDirLength, const char* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_CopyDirFromPc(const char* dstDir, unsigned int dstDirLength, const char* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_CopyDirFromPc_r(const int meta_handle, const char* dstDir, unsigned int dstDirLength, const char* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_RemoveDirEx(const char* fat_dirpath, int* p_stopflag);
META_RESULT  __stdcall META_FAT_RemoveDirEx_r(const int meta_handle, const char* fat_dirpath, int* p_stopflag);
META_RESULT  __stdcall META_FAT_DeleteEx(const char* fat_filepath, short* p_token, int* p_stopflag);
META_RESULT  __stdcall META_FAT_DeleteEx_r(const int meta_handle, const char* fat_filepath, short* p_token, int* p_stopflag);
/**
 * \brief the non-reentrant version of META_FAT_GetDriveType_r
 */
META_RESULT  __stdcall META_FAT_GetDriveType(unsigned int ms_timeout, const char DriveLetter, int* p_DriveType);
/**
 * \details get the FS drive type by given drive letter
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param DriveLetter the drive letter to be checked (MBCS)
 * \param p_DriveType the drive type NOR_DRIVE = 1,
 * NAND_DRIVE=2,
 * CARD_DRIVE = 3,
 * EXTERNAL_DRIVE = 4
 */
META_RESULT  __stdcall META_FAT_GetDriveType_r(const int meta_handle, unsigned int ms_timeout, const char DriveLetter, int* p_DriveType);

//-----------------------------------------------------------------------------
// FAT UTF(Unicode) API
//-----------------------------------------------------------------------------
META_RESULT  __stdcall META_FAT_UTF_Open(const WCHAR* fat_filepath, FAT_OPEN_MODE  mode, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Open_r(const int meta_handle, const WCHAR* fat_filepath, FAT_OPEN_MODE  mode, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Close(int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Close_r(const int meta_handle, int* fs_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_GetFileSize(const int fs_handle, int* filesize, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_GetFileSize_r(const int meta_handle, const int fs_handle, int* filesize, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Read(const int fs_handle, char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Read_r(const int meta_handle, const int fs_handle, char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Write(const int fs_handle, const char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Write_r(const int meta_handle, const int fs_handle, const char* buf, const int buf_len, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Read_To_File(const int fs_handle, const WCHAR* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Read_To_File_r(const int meta_handle, const int fs_handle, const WCHAR* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Write_By_File(const int fs_handle, const WCHAR* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Write_By_File_r(const int meta_handle, const int fs_handle, const WCHAR* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Delete(const WCHAR* fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Delete_r(const int meta_handle, const WCHAR* fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Move(const WCHAR* fat_filepath, const WCHAR* new_fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Move_r(const int meta_handle, const WCHAR* fat_filepath, const WCHAR* new_fat_filepath, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Find_Start(const WCHAR* fat_base_dir, const WCHAR* fat_find_pattern, FAT_FIND_MODE find_mode, int* p_find_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Find_Start_r(const int meta_handle, const WCHAR* fat_base_dir, const WCHAR* fat_find_pattern, FAT_FIND_MODE find_mode, int* p_find_handle, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_Find_Head(int find_handle);
META_RESULT  __stdcall META_FAT_UTF_Find_Prev(int find_handle);
META_RESULT  __stdcall META_FAT_UTF_Find_Next(int find_handle);
META_RESULT  __stdcall META_FAT_UTF_Find_GetFileInfo(int find_handle, WCHAR* p_filepath, const int filepath_len, int* p_filesize);
META_RESULT  __stdcall META_FAT_UTF_Find_Close(int* p_find_handle);
META_RESULT  __stdcall META_FAT_UTF_GetDiskInfo(const WCHAR DriveLetter, FAT_DiskInfo_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_GetDiskInfo_r(const int meta_handle, const WCHAR DriveLetter, FAT_DiskInfo_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_GetDiskInfo_Ex(const WCHAR DriveLetter, FAT_DiskInfo_EX_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_GetDiskInfo_Ex_r(const int meta_handle, const WCHAR DriveLetter, FAT_DiskInfo_EX_T*  p_DiskInfo, short* p_token);
META_RESULT  __stdcall META_FAT_UTF_RemoveDir(const WCHAR* fat_dirpath);
META_RESULT  __stdcall META_FAT_UTF_RemoveDir_r(const int meta_handle, const WCHAR* fat_dirpath);

META_RESULT __stdcall META_FAT_UTF_CheckEnoughSpace(FAT_FILE_INFO_REQ_T* req);
META_RESULT __stdcall META_FAT_UTF_CheckEnoughSpace_r(const int meta_handle, FAT_UTF_FILE_INFO_REQ_T* req);
META_RESULT __stdcall META_FAT_UTF_CheckEnoughSpaceEx(FAT_FILE_INFO_REQ_EX_T* req_ex);
META_RESULT __stdcall META_FAT_UTF_CheckEnoughSpaceEx_r(const int meta_handle, FAT_UTF_FILE_INFO_REQ_EX_T* req_ex);

META_RESULT  __stdcall META_FAT_UTF_Read_To_File_Ex(const int fs_handle, const WCHAR* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg, short* p_token,
        int*   p_stopflag);

META_RESULT  __stdcall META_FAT_UTF_Read_To_File_Ex_r(const int meta_handle, const int fs_handle,
        const WCHAR* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg, short* p_token,
        int*   p_stopflag);

META_RESULT  __stdcall META_FAT_UTF_Write_By_File_Ex(const int fs_handle,
        const WCHAR* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg,
        short* p_token,
        int* p_stopfalg);

META_RESULT  __stdcall META_FAT_UTF_Write_By_File_Ex_r(const int meta_handle,
        const int fs_handle,
        const WCHAR* filepath,
        CALLBACK_META_FAT_PROGRESS  cb_progress,
        void*  cb_progress_arg,
        short* p_token,
        int* p_stopflag);

META_RESULT  __stdcall META_FAT_UTF_CopyDirFromTarget(const WCHAR* dstDir, unsigned int dstDirLength, const WCHAR* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_CopyDirFromTarget_r(const int meta_handle, const WCHAR* dstDir, unsigned int dstDirLength, const WCHAR* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_CopyDirFromPc(const WCHAR* dstDir, unsigned int dstDirLength, const WCHAR* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS  cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_CopyDirFromPc_r(const int meta_handle, const WCHAR* dstDir, unsigned int dstDirLength, const WCHAR* srcDir, unsigned int srcDirLength, CALLBACK_META_FAT_PROGRESS cb_progress, void* cb_progress_arg, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_RemoveDirEx(const WCHAR* fat_dirpath, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_RemoveDirEx_r(const int meta_handle, const WCHAR* fat_dirpath, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_DeleteEx(const WCHAR* fat_filepath, short* p_token, int* p_stopflag);
META_RESULT  __stdcall META_FAT_UTF_DeleteEx_r(const int meta_handle, const WCHAR* fat_filepath, short* p_token, int* p_stopflag);
/**
 * \brief the non-reentrant version of META_FAT_UTF_GetDriveType_r
 */
META_RESULT  __stdcall META_FAT_UTF_GetDriveType(unsigned int ms_timeout, const WCHAR DriveLetter, int* p_DriveType);
/**
 * \details get the FS drive type by given drive letter
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param DriveLetter the drive letter to be checked (unicode)
 * \param p_DriveType the drive type NOR_DRIVE = 1,
 * NAND_DRIVE=2,
 * CARD_DRIVE = 3,
 * EXTERNAL_DRIVE = 4
 */
META_RESULT  __stdcall META_FAT_UTF_GetDriveType_r(const int meta_handle, unsigned int ms_timeout, const WCHAR DriveLetter, int* p_DriveType);



META_RESULT  __stdcall META_Check_ULC_support(unsigned int ms_timeout);
META_RESULT  __stdcall META_Check_ULC_support_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Check_SmartPhoneModem_support(unsigned int ms_timeout);
META_RESULT  __stdcall META_Check_SmartPhoneModem_support_r(const int meta_handle, unsigned int ms_timeout);


typedef enum
{
    META_VERSION_USER_DEFINE
    , META_VERSION_META_DLL_UTIL_VER
    , VER_TYPE_END

} META_VERSION_TYPE;

typedef struct
{

    META_VERSION_TYPE   m_eVerType;
    unsigned int        m_u4MainVersion;  ///< valid when m_eVerType = META_VERSION_USER_DEFINE
    unsigned int        m_u4MinorVersion; ///< valid when m_eVerType = META_VERSION_USER_DEFINE
    unsigned int        m_u4BuildNum;     ///< valid when m_eVerType = META_VERSION_USER_DEFINE


} META_UTIL_CHECK_TARGET_VER_REQ_T;

typedef struct
{
    bool         m_bCheckPass;
    unsigned int m_u4TargetMainVersion;
    unsigned int m_u4TargetMinorVersion;
    unsigned int m_u4TargetBuildNum;
} META_UTIL_CHECK_TARGET_VER_CNF_T;

typedef struct
{
    bool  b_TargetAssertCheckFlag;
    bool  b_SetCurRecvMsgTimes;
    unsigned char m_u1CurRecvMsgTimes;  ///< valid when b_SetCurRecvMsgTimes = true
} META_UTIL_SET_ASSERT_CHECK_PARAs_REQ_T;


META_RESULT  __stdcall META_Util_CheckTargetRequiredVersion(unsigned int ms_timeout, const META_UTIL_CHECK_TARGET_VER_REQ_T* req, META_UTIL_CHECK_TARGET_VER_CNF_T* cnf );
META_RESULT  __stdcall META_Util_CheckTargetRequiredVersion_r(const int meta_handle, unsigned int ms_timeout, const META_UTIL_CHECK_TARGET_VER_REQ_T* req, META_UTIL_CHECK_TARGET_VER_CNF_T* cnf );
META_RESULT  __stdcall META_Util_SetTargetAssertCheckParas(unsigned int ms_timeout, const META_UTIL_SET_ASSERT_CHECK_PARAs_REQ_T* req);
META_RESULT  __stdcall META_Util_SetTargetAssertCheckParas_r(const int meta_handle, unsigned int ms_timeout, const META_UTIL_SET_ASSERT_CHECK_PARAs_REQ_T* req);


META_RESULT  __stdcall META_Util_CheckIfTargetNVSecOn(unsigned int ms_timeout, bool* bOn);
META_RESULT  __stdcall META_Util_CheckIfTargetNVSecOn_r(const int meta_handle, unsigned int ms_timeout, bool* bOn);

META_RESULT __stdcall META_Util_RebootToNormalMode(unsigned int ms_timeout, unsigned short timeout);
META_RESULT __stdcall META_Util_RebootToNormalMode_r(const int meta_handle, unsigned int ms_timeout, unsigned short timeout);

META_RESULT __stdcall META_Util_QueryBTWiFiSingleAntennaCap(unsigned int ms_timeout, bool* bOn);
META_RESULT __stdcall META_Util_QueryBTWiFiSingleAntennaCap_r(const int meta_handle, unsigned int ms_timeout, bool* bOn);

META_RESULT __stdcall META_Util_SetAntennaPathToBT(const unsigned int ms_timeout);
META_RESULT __stdcall META_Util_SetAntennaPathToBT_r(const int meta_handle, const unsigned int ms_timeout);

META_RESULT __stdcall META_Util_SetAntennaPathToWiFi(const unsigned int ms_timeout);
META_RESULT __stdcall META_Util_SetAntennaPathToWiFi_r(const int meta_handle, const unsigned int ms_timeout);

#define META_LIPTON_OPTION_ON   0x00000001
#define META_TC01_OPTION_ON     0x00000002
#define META_AST_TD_OPTION_ON   0x00000004

META_RESULT __stdcall META_Util_QueryTargetOptionInfo(const unsigned int ms_timeout, unsigned int* info);
META_RESULT __stdcall META_Util_QueryTargetOptionInfo_r(const int meta_handle, const unsigned int ms_timeout, unsigned int* info);

META_RESULT __stdcall META_Util_QueryTargetLimitedStateIndicator(const unsigned int ms_timeout, unsigned int* info);
META_RESULT __stdcall META_Util_QueryTargetLimitedStateIndicator_r(const int meta_handle, const unsigned int ms_timeout, unsigned int* info);

typedef struct
{
    /// number of elements in the list
    unsigned int validNumber;
    /// voltage list (unit: micro volt 10^-6)
    unsigned int voltageList[255];
    /// register value of each voltageList
    unsigned int registerValue[255];
} MetaVpaVoltageList;

META_RESULT __stdcall META_Util_QueryVpaVoltageList(const unsigned int ms_timeout, MetaVpaVoltageList* vpaVoltageList);
META_RESULT __stdcall META_Util_QueryVpaVoltageList_r(const int meta_handle, const unsigned int ms_timeout, MetaVpaVoltageList* vpaVoltageList);
META_RESULT __stdcall META_Util_QueryDriveAvailableForFileSize(unsigned int ms_timeout, unsigned int size, short* driveLetter);
META_RESULT __stdcall META_Util_QueryDriveAvailableForFileSize_r(const int meta_handle, unsigned int ms_timeout, unsigned int size, short* driveLetter);
META_RESULT __stdcall META_Util_QueryMaxControlBuffer(unsigned int ms_timeout, unsigned int* size);
META_RESULT __stdcall META_Util_QueryMaxControlBuffer_r(const int meta_handle, unsigned int ms_timeout, unsigned int* size);
/**
 * \brief non-reentrant version of META_Util_QueryAdcModuleSupport_r
 */
META_RESULT __stdcall META_Util_QueryAdcModuleSupport(unsigned int ms_timeout, unsigned char* support);
/**
 * \details query the ADC module support
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param support 1:suport 0:not support
 */
META_RESULT __stdcall META_Util_QueryAdcModuleSupport_r(const int meta_handle, unsigned int ms_timeout, unsigned char* support);
/**
 * \brief non-reentrant version of META_Util_QueryRtcModuleSupport_r
 */
META_RESULT __stdcall META_Util_QueryRtcModuleSupport(unsigned int ms_timeout, unsigned char* support);
/**
 * \details query the RTC module support
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param support 1:suport 0:not support
 */
META_RESULT __stdcall META_Util_QueryRtcModuleSupport_r(const int meta_handle, unsigned int ms_timeout, unsigned char* support);
/**
 * \brief non-reentrant version of META_Util_EnableTstMetaTraceMode_r
 */
META_RESULT __stdcall META_Util_EnableTstMetaTraceMode(const unsigned int ms_timeout, const unsigned char trace_mode);
/**
 * \details enable META mode trace
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param trace_mode 0: disable 1: catcher relay 2: file dump
 */
META_RESULT __stdcall META_Util_EnableTstMetaTraceMode_r(const int meta_handle, const unsigned int ms_timeout, const unsigned char trace_mode);
META_RESULT __stdcall META_Util_QueryTstMetaTraceMode(const unsigned int ms_timeout, unsigned char* trace_mode);
/**
 * \details query status of META mode trace
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param trace_mode 0: disable 1: catcher relay 2: file dump
 */
META_RESULT __stdcall META_Util_QueryTstMetaTraceMode_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* trace_mode);
//----------------------------------------------------------------------//
//       META MDLogging: exported functions for modem logging
//----------------------------------------------------------------------//
/**
* \brief non-reentrant version of META_MDLogging_SetModemLogFilterToTarget_r
*/
META_RESULT __stdcall META_MDLogging_SetFilterToTarget (const char* filter_file_path);
/**
 * \details set the modem log filter to target
 * \param meta_handle meta handle
 * \param filter_file_path the path of the modem log filter
 * \retval META_SUCCESS  success in transmitting the modem log filter to target
 * \retval Other error code  use META_GetErrorString to translate the meaning.
 */
META_RESULT __stdcall META_MDLogging_SetFilterToTarget_r (const int meta_handle, const char* filter_file_path);
/**
* \brief non-reentrant version of META_MDLogging_SetModemLogFilterToTarget_Unicode_r
*/
META_RESULT __stdcall META_MDLogging_SetFilterToTarget_Unicode (WCHAR* filter_file_path);
/**
 * \details set the modem log filter to target
 * \param meta_handle meta handle
 * \param filter_file_path the path of the modem log filter
 * \retval META_SUCCESS  success in transmitting the modem log filter to target
 * \retval Other error code  use META_GetErrorString to translate the meaning.
 */
META_RESULT __stdcall META_MDLogging_SetFilterToTarget_Unicode_r (const int meta_handle, WCHAR* filter_file_path);

META_RESULT  __stdcall META_MDLogging_GetMetaDefaultFilterFile_r(const int meta_handle, const char* db_path, char* p_output_filter_folder);

META_RESULT  __stdcall META_MDlogging_GetMemoryDumpFile_r(const int meta_handle, const char* db_path, char* p_output_file);
//----------------------------------------------------------------------//
//       META Misc: backup and restore calibration Data
//----------------------------------------------------------------------//
/**
 * \addtogroup Misc
 * @{
 */
typedef void (__stdcall* CALLBACK_MISC_PROGRESS)(unsigned char m_u1TotalNum, unsigned char m_u1BackupNum, void* usr_arg);
typedef void (__stdcall* CALLBACK_MISC_IMEI_PROGRESS)(const int imei_max_num, const char** errMsg, const char** imei, void* usr_arg);
typedef void (__stdcall* CALLBACK_MISC_MACADDR_PROGRESS)(const char* message, const char* mac_addr, void* usr_arg);

typedef enum
{
    META_STORAGE_TYPE_FAT = 0,
    META_STORAGE_TYPE_OTP,
    META_STORAGE_TYPE_SECRO,
    META_STORAGE_TYPE_END
} META_IMEI_LOC_enum;

typedef struct
{
    char*                    m_pIniFilePath;
    char*                    m_pBackupFolderPath; // Let customer choose the backup folder
    //Note: it should be different by meta_handle!
    CALLBACK_MISC_PROGRESS  cb_progress;
    void*                    cb_progress_arg;
} MISC_BACKUP_REQ_T;



typedef struct
{
    char*                    m_pIniFilePath;
    char*                    m_pBackupFolderPath; // the folder which store the backup data
    CALLBACK_MISC_PROGRESS   cb_progress;
    void*                     cb_progress_arg;

} MISC_RESTORE_REQ_T;

typedef struct
{
    /// restore request
    MISC_RESTORE_REQ_T              restoreRequest;
    /// file transfer progress callback function
    CALLBACK_META_FAT_PROGRESS      cb_filetransfer_progress;
    /// user argument for file transfer progress callback
    void*                           filetransfer_arg;
} MISC_RESTORE_REQ_EX_T;

typedef struct
{
    char                 m_strBackupFolder[MAX_PATH];
    bool                 m_bISNewLoad;
    META_IMEI_LOC_enum   m_enumImeiLoc; // only valid when m_bISNewLoad = true;
    unsigned  char       m_ImeiData[10]; // only valid when m_bISNewLoad = true
    int                  m_i4ComPort;
    int                  m_i4BackupFileNum;

} BACKUP_RESULT_T;

typedef struct
{

    char                    m_strRestoreFromFolder[MAX_PATH];
    bool                    m_bISNewLoad;
    META_IMEI_LOC_enum      m_enumImeiLoc; // only valid when m_bISNewLoad = true;
    unsigned char           m_ImeiData[10]; // only valid when m_bISNewLoad = true;
    int                     m_i4ComPort;
    int                     m_i4BackupFileNum;


} RESTORE_RESULT_T;

typedef struct
{
    char*                    m_pIniFilePath; // the INI file path
    CALLBACK_MISC_PROGRESS   cb_progress;
    void*                     cb_progress_arg;

} MISC_UPLOAD_REQ_T;

typedef struct
{
    char*                    m_pIniFilePath; // the INI file path
    CALLBACK_MISC_PROGRESS   cb_progress;
    void*                     cb_progress_arg;
    CALLBACK_MISC_IMEI_PROGRESS   cb_imei_progress;
    void*                     cb_imei_progress_arg;
} MISC_UPLOAD_REQ_EX_T;

typedef struct
{
    MISC_UPLOAD_REQ_EX_T            uploadRequest;
    CALLBACK_META_FAT_PROGRESS      cb_filetransfer_progress;
    void*                           filetransfer_arg;
    CALLBACK_MISC_MACADDR_PROGRESS  cb_macaddr_progress;
    void*                           macaddr_arg;
} MISC_UPLOAD_REQ_EX2_T;

typedef struct
{
    unsigned short record_index;  /**< \brief [IN]  the index of imei record, if want to read record1 must be set 1 */
    char           imei[16];      /**< \brief [OUT] the value of IMEI */
    unsigned char  svn;           /**< \brief [OUT] the svn of IMEI */
} META_GET_IMEI_T;

typedef struct
{
    unsigned short record_index;  /**< \brief [IN]  the index of barcode record, if want to read record1 must be set 1 */
    unsigned int   bufferLength;  /**< \brief [IN]  the length of barcode buffer */
    char*          buffer;        /**< \brief [OUT] the buffer of barcode */
} META_GET_BARCODE_T;

META_RESULT __stdcall META_MISC_GetIMEILocation(const unsigned int ms_timeout, META_IMEI_LOC_enum* storagetype);
META_RESULT __stdcall META_MISC_GetIMEILocation_r(const int meta_handle, const unsigned int ms_timeout, META_IMEI_LOC_enum* storagetype);
META_RESULT __stdcall META_MISC_GetIMEIRecNum(const unsigned int ms_timeout, unsigned short* rec_num);
META_RESULT __stdcall META_MISC_GetIMEIRecNum_r(const int meta_handle, const unsigned int ms_timeout, unsigned short* rec_num);

META_RESULT __stdcall META_MISC_QueryNVRAMFolderAmount(const unsigned int ms_timeout, unsigned char* folder_amount);
META_RESULT __stdcall META_MISC_QueryNVRAMFolderAmount_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* folder_amount);
/**
 * \brief non-reentrant version of META_MISC_CheckSIM1Inserted_r
 */
META_RESULT __stdcall META_MISC_CheckSIM1Inserted(const unsigned int ms_timeout, unsigned char* inserted);
/**
 * \details check the SIM1 HW status via SIM module
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param inserted 1: inserted 0: not inserted
 */
META_RESULT __stdcall META_MISC_CheckSIM1Inserted_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* inserted);

/**
 * \brief non-reentrant version of META_MISC_CheckSIM2Inserted_r
 */
META_RESULT __stdcall META_MISC_CheckSIM2Inserted(const unsigned int ms_timeout, unsigned char* inserted);
/**
 * \details check the SIM2 HW status via SIM module
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param inserted 1: inserted 0: not inserted
 */

META_RESULT __stdcall META_MISC_CheckSIM2Inserted_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* inserted);

/**
 * \brief non-reentrant version of META_MISC_CheckGeminiPlusSIMInserted_r
 */
META_RESULT __stdcall META_MISC_CheckGeminiPlusSIMInserted(const unsigned int ms_timeout, unsigned char sim_module_index, unsigned char* inserted);
/**
 * \details check the SIM HW status via SIM module
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param sim_module_index index of SIM module
 * \param inserted 1: inserted 0: not inserted
 */
META_RESULT __stdcall META_MISC_CheckGeminiPlusSIMInserted_r(const int meta_handle, const unsigned int ms_timeout, unsigned char sim_module_index, unsigned char* inserted);

/**
 * \brief non-reentrant version of META_MISC_SimHwTest_r
 */
META_RESULT __stdcall META_MISC_SimHwTest(const unsigned int ms_timeout, unsigned char simModuleId, int* status);
/**
 * \details check the SIM HW status via SIM driver
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param simModuleId index of SIM driver module (0: sim1, 1: sim2...)
 * \param status the status of HW test (0: OK, otherwise: error code for SIM driver)
 */
META_RESULT __stdcall META_MISC_SimHwTest_r(const int meta_handle, const unsigned int ms_timeout, unsigned char simModuleId, int* status);
#define MUIC_MODE_CHARGE_ON     0
#define MUIC_MODE_CHARGE_OFF    1
#define MUIC_MODE_USB_500       2
#define MUIC_MODE_ISET_PROGRAM  3
#define MUIC_MODE_USB_100       4
#define MUIC_MODE_TEST_MODE     5
#define MUIC_MODE_USB_100_2     6

META_RESULT __stdcall META_MISC_SetMuicChargerMode(const unsigned int ms_timeout, const unsigned char* req_mode);
META_RESULT __stdcall META_MISC_SetMuicChargerMode_r(const int meta_handle, const unsigned int ms_timeout, const unsigned char* req_mode);


typedef struct
{
    const char*          LID;   /**< The name of logical data item ID */
    unsigned short      u2RID;  /**< Record ID (the first record is 1) */
} META_MISC_CAL_DATA_INTEGRITY_ENTRY;

typedef struct
{

    bool                bAllPass;  /**< true: check pass, false: no items or check fail */
    unsigned short      u2LastLID;  /**< valid when bAllPass == false */
    unsigned short      u2LastRID;  /**< valid when bAllPass == false */
} META_MISC_CAL_DATA_INTEGRITY_CHECK_CNF_T;


META_RESULT __stdcall META_MISC_CalDataIntegrity_StartRec(const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StartRec_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StartRec_Ex(const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StartRec_Ex_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StopRec(const unsigned int ms_timeout, int* rec_num);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StopRec_r(const int meta_handle, const unsigned int ms_timeout, int* rec_num);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StopRec_Ex(const unsigned int ms_timeout, int* rec_num);
META_RESULT __stdcall META_MISC_CalDataIntegrity_StopRec_Ex_r(const int meta_handle, const unsigned int ms_timeout, int* rec_num);
META_RESULT __stdcall META_MISC_CalDataIntegrity_AddOne(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_AddOne_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_AddOne_Ex(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_AddOne_Ex_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);

META_RESULT __stdcall META_MISC_CalDataIntegrity_DelOne(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelOne_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelOne_Ex(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelOne_Ex_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelAll(const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelAll_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelAll_Ex(const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_DelAll_Ex_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_CalDataIntegrity_CheckOne(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_CheckOne_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_ENTRY* req);
META_RESULT __stdcall META_MISC_CalDataIntegrity_CheckAll(const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_CHECK_CNF_T* cnf);
META_RESULT __stdcall META_MISC_CalDataIntegrity_CheckAll_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_CAL_DATA_INTEGRITY_CHECK_CNF_T* cnf);

#define META_MISC_SUPPORTED_MAX_ADC_CHN_NUM 20

typedef struct
{
    bool bADCStoredInEfuse;  /**< true: ADC is stored in EFUSE, not in NVRAM data. */
    int  i4ADCChnNum;  /**< specify the adc channel number supported by this phone */
    int  i4ADCSlope[META_MISC_SUPPORTED_MAX_ADC_CHN_NUM]; /**< [0 ~ iADCChnNum-1] is valid when bADCStoredInEfuse = true */
    int  i4ADCOffset[META_MISC_SUPPORTED_MAX_ADC_CHN_NUM];/**< [0 ~ iADCChnNum-1] is valid when bADCStoredInEfuse = true */
} META_MISC_GET_ADC_FROM_EFUSE_CNF_T;

META_RESULT __stdcall META_MISC_GetADCFromEFuse(const unsigned int ms_timeout, META_MISC_GET_ADC_FROM_EFUSE_CNF_T* cnf);
META_RESULT __stdcall META_MISC_GetADCFromEFuse_r(const int meta_handle, const unsigned int ms_timeout, META_MISC_GET_ADC_FROM_EFUSE_CNF_T* cnf);

META_RESULT __stdcall META_MISC_GetCalFlagEnum(const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetCalFlagEnum_r(const int meta_handle, const unsigned int ms_timeout, unsigned short* u2EnumVal);

META_RESULT __stdcall META_MISC_GetRfCalEnvEnum(const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetRfCalEnvEnum_r(const int meta_handle, const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetRfCalLossSettingEnum(const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetRfCalLossSettingEnum_r(const int meta_handle, const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetRfTestPowerResultEnum(const unsigned int ms_timeout, unsigned short* u2EnumVal);
META_RESULT __stdcall META_MISC_GetRfTestPowerResultEnum_r(const int meta_handle, const unsigned int ms_timeout, unsigned short* u2EnumVal);

META_RESULT __stdcall META_MISC_GetADCMaxChannel(const unsigned int ms_timeout, unsigned char* u1Val);
META_RESULT __stdcall META_MISC_GetADCMaxChannel_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* u1Val);
META_RESULT __stdcall META_MISC_GetTADCChannelIndex(const unsigned int ms_timeout, unsigned char* u1Val);
META_RESULT __stdcall META_MISC_GetTADCChannelIndex_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* u1Val);

META_RESULT __stdcall META_MISC_GetRID(const unsigned int ms_timeout, unsigned char* u1Rid, const unsigned int ui_RidLen);
META_RESULT __stdcall META_MISC_GetRID_r(const int meta_handle, const unsigned int ms_timeout, unsigned char* u1Rid, const unsigned int ui_RidLen);

META_RESULT __stdcall META_MISC_GetIMEIValue(const unsigned int ms_timeout, META_GET_IMEI_T* req);
META_RESULT __stdcall META_MISC_GetIMEIValue_r(const int meta_handle, const unsigned int ms_timeout, META_GET_IMEI_T* req);
META_RESULT __stdcall META_MISC_GetBarCodeValue(const unsigned int ms_timeout, META_GET_BARCODE_T* req);
META_RESULT __stdcall META_MISC_GetBarCodeValue_r(const int meta_handle, const unsigned int ms_timeout, META_GET_BARCODE_T* req);

META_RESULT __stdcall META_BackupCalibrationData(const MISC_BACKUP_REQ_T* req, int* p_backupstop );
META_RESULT __stdcall META_BackupCalibrationData_r(const int meta_handle, const MISC_BACKUP_REQ_T* req, int* p_backupstop);
META_RESULT __stdcall META_RestoreCalibrationData(const MISC_RESTORE_REQ_T* req, int* p_restorestop);
META_RESULT __stdcall META_RestoreCalibrationData_r(const int meta_handle, const MISC_RESTORE_REQ_T* req, int* p_restorestop);
META_RESULT __stdcall META_RestoreCalibrationDataEx(const MISC_RESTORE_REQ_EX_T* req, int* p_restorestop);
META_RESULT __stdcall META_RestoreCalibrationDataEx_r(const int meta_handle, const MISC_RESTORE_REQ_EX_T* req, int* p_restorestop);

typedef struct
{
    /// full path to the file
    const char*   fullPath;
    /// file size (0: means not-avaialble in the context)
    int           fileSize;
    /// LID name or enum value
    const char*   lidOrEnum;
    /// type of the NVRAM file (0: normal, 1: imei, 2: SML)
    unsigned char fileType;
} META_MISC_RestoreFileNotFoundInBackupResult_T;
typedef struct
{
    /// file prefix of the NVRAM item
    const char*    filePrefix;
    /// verno of the NVRAM item
    const char*    versionNumber;
    /// enum value
    unsigned short enumValue;
    /// type of the NVRAM file (0: normal, 1: imei, 2: SML)
    unsigned char  fileType;
    /// file size (0: means not-avaialble in the context)
    unsigned int   fileSize;
} META_MISC_BackupFileNotFoundInNvram_T;
typedef META_MISC_BackupFileNotFoundInNvram_T META_MISC_RestoreTargetNotFoundInNvram_T;
typedef struct
{
    /// key name
    const char*   keyName;
    /// value string
    const char*   value;
} META_MISC_BackupMoreFileNotFoundInNvram_T;
typedef struct
{
    /// where we download from the target side
    const char*     backupPath;
    unsigned int    fileSize;
    /// 1: nvram sec, 2: target sec
    unsigned char   fileSection;
    /// where we store the files in PC side
    const char*     localPath;
    bool            hasLidInfo;
    /// meaningful when m_bHasLID == true;
    const char*     lidInfo;
    /// -1: not exist 0: general LID, 1: IMEI, 2: SML
    char            lidType;
    /// store the target file path we will restore!
    const char*     restorePath;
} META_MISC_BackupFileResultEntry_T;
typedef struct
{
    META_MISC_BackupFileResultEntry_T               backupResult;
    META_MISC_RestoreFileNotFoundInBackupResult_T   restoreFileInfo;
} META_MISC_BackupFileRestoreTargetSizeMismatch_T;
typedef union
{
    META_MISC_RestoreFileNotFoundInBackupResult_T   restoreFileNotFoundInBackupResultInfo;
    META_MISC_BackupFileNotFoundInNvram_T           backupFileNotFoundInNvramInfo;
    META_MISC_RestoreTargetNotFoundInNvram_T        restoreTargetNotFoundInNvramInfo;
    META_MISC_BackupMoreFileNotFoundInNvram_T       backupMoreFileNotFoundInNvramInfo;
    META_MISC_BackupFileRestoreTargetSizeMismatch_T backupFileRestoreTargetSizeMismatchInfo;
    DWORD                                           systemErrorCode;
} META_MISC_BKRSCustomizedInformation;
typedef struct
{
    META_RESULT errorCode;
    const char* message;
    int messageLength;
    META_MISC_BKRSCustomizedInformation info;
} META_MISC_BKRSCustomizedCallbackParameter;
typedef int (__stdcall* CALLBACK_BKRS_ERROR_HANDLER)(const META_MISC_BKRSCustomizedCallbackParameter* param, void* userArg);
META_RESULT __stdcall META_MISC_SetBackupRestoreErrorCallback(CALLBACK_BKRS_ERROR_HANDLER cb, void* user_arg);
META_RESULT __stdcall META_MISC_SetBackupRestoreErrorCallback_r(const int meta_handle, CALLBACK_BKRS_ERROR_HANDLER cb, void* user_arg);

META_RESULT __stdcall META_DeleteAllFilesInBackupFolder(const char* pBackupFolderPath);
META_RESULT __stdcall META_DeleteAllFilesInBackupFolder_r(const int meta_handle, const char* pBackupFolderPath);


META_RESULT __stdcall META_GetRestoreResultInfo_r(const int meta_handle, const char* backup_folder, RESTORE_RESULT_T* cnf);
META_RESULT __stdcall META_GetRestoreResultInfo(const char* backup_folder, RESTORE_RESULT_T* cnf);
META_RESULT __stdcall META_GetBackupResultInfo(const char* backup_folder, BACKUP_RESULT_T* cnf);
META_RESULT __stdcall META_GetBackupResultInfo_r(const int meta_handle, const char* backup_folder, BACKUP_RESULT_T* cnf);

// be used in old load when IMEI and SML NVRAM files can not be accessed by File System APIs!
// i.e., IMEI and SML NVRAM files will not be backuped and restored!
META_RESULT __stdcall META_BasicBackupCalibrationData_r(const int meta_handle, const MISC_BACKUP_REQ_T* req, int* p_backupstop);
META_RESULT __stdcall META_BasicBackupCalibrationData(const MISC_BACKUP_REQ_T* req, int* p_backupstop);
META_RESULT __stdcall META_BasicRestoreCalibrationData_r(const int meta_handle, const MISC_RESTORE_REQ_T* req, int* p_restorestop);
META_RESULT __stdcall META_BasicRestoreCalibrationData(const MISC_RESTORE_REQ_T* req, int* p_restorestop);

META_RESULT __stdcall META_UploadFilesToTarget(MISC_UPLOAD_REQ_T* req, int* p_uploadstop);
META_RESULT __stdcall META_UploadFilesToTarget_r(const int meta_handle, MISC_UPLOAD_REQ_T* req, int* p_uploadstop);
META_RESULT __stdcall META_UploadFilesToTarget_Ex(MISC_UPLOAD_REQ_EX_T* req, int* p_uploadstop);
META_RESULT __stdcall META_UploadFilesToTarget_Ex_r(const int meta_handle, MISC_UPLOAD_REQ_EX_T* req, int* p_uploadstop);
META_RESULT __stdcall META_UploadFilesToTarget_Ex2(MISC_UPLOAD_REQ_EX2_T* req, int* p_uploadstop);
META_RESULT __stdcall META_UploadFilesToTarget_Ex2_r(const int meta_handle, MISC_UPLOAD_REQ_EX2_T* req, int* p_uploadstop);

META_RESULT __stdcall META_MISC_GetMmiCacheEnumIndex(const unsigned int ms_timeout, unsigned short enum_value, unsigned short* index);
META_RESULT __stdcall META_MISC_GetMmiCacheEnumIndex_r(const int meta_handle, const unsigned int ms_timeout, unsigned short enum_value, unsigned short* index);
typedef struct
{
    unsigned char sec;    /**< seconds after the minute   - [0,59] */
    unsigned char min;    /**< minutes after the hour     - [0,59] */
    unsigned char hour;   /**< hours after the midnight   - [0,23] */
    unsigned char day;    /**< day of the month           - [1,31] */
    unsigned char mon;    /**< months                         - [1,12] */
    unsigned char wday;   /**< days in a week                 - [1,7]; not correct information, so don't care. */
    unsigned char year;   /**< years                      - [0,127] */
} META_RCT_INFO_T;

#define META_ERS_FILE_NAME_WCHAR_CNT  100

typedef struct
{
    WCHAR            wQueryKey[META_ERS_FILE_NAME_WCHAR_CNT];//ers_filename[META_ERS_FILE_NAME_WCHAR_CNT];
    META_RCT_INFO_T  ers_ctime;
} META_ERS_INFO_T;


META_RESULT __stdcall META_MISC_EX_GetErsCount(const unsigned int ms_timeout,  int* pCnt);
META_RESULT __stdcall META_MISC_EX_GetErsCount_r(const int meta_handle, const unsigned int ms_timeout, int* pCnt);
META_RESULT __stdcall META_MISC_EX_GetErsDataInfoByIndex(const unsigned int ms_timeout,  const int index, META_ERS_INFO_T* pCnf);
META_RESULT __stdcall META_MISC_EX_GetErsDataInfoByIndex_r(const int meta_handle, const unsigned int ms_timeout, const int index, META_ERS_INFO_T* pCnf);

META_RESULT __stdcall META_MISC_EX_GetErsSize(const unsigned int ms_timeout, unsigned int* pSize);
META_RESULT __stdcall META_MISC_EX_GetErsSize_r(const int meta_handle, const unsigned int ms_timeout, unsigned int* pSize);
META_RESULT __stdcall META_MISC_EX_GetErsData(const unsigned int ms_timeout, WCHAR* wfilepath, const unsigned int ers_data_buf_size, unsigned char* ers_data_buffer);
META_RESULT __stdcall META_MISC_EX_GetErsData_r(const int meta_handle, const unsigned int ms_timeout, WCHAR* wfilepath, const unsigned int ers_data_buf_size, unsigned char* ers_data_buffer);

META_RESULT __stdcall META_MISC_EX_InitBPAreaFromNVRAM(const unsigned int ms_timeout);
META_RESULT __stdcall META_MISC_EX_InitBPAreaFromNVRAM_r(const int meta_handle, const unsigned int ms_timeout);
typedef enum
{
    META_BP_AREA_STATUS_OK = 0,
    META_BP_AREA_STATUS_EMPTY = 1,
    META_BP_AREA_STATUS_BROKEN = 2,
    META_BP_AREA_STATUS_NO_SYNC = 3,
    META_BP_AREA_STATUS_UNKNOWN = 4
} META_BP_AREA_STATUS_E;
META_RESULT __stdcall META_MISC_EX_VerifyBPArea(const unsigned int ms_timeout, bool* bFastVerify, META_BP_AREA_STATUS_E* cnf);
META_RESULT __stdcall META_MISC_EX_VerifyBPArea_r(const int meta_handle, const unsigned int ms_timeout, bool* bFastVerify, META_BP_AREA_STATUS_E* cnf);
META_RESULT __stdcall META_MISC_EX_BackupCalibrationToStorage(const unsigned int ms_timeout, unsigned int storage_mode, unsigned int* status);
META_RESULT __stdcall META_MISC_EX_BackupCalibrationToStorage_r(const int meta_handle, const unsigned int ms_timeout, unsigned int storage_mode, unsigned int* status);
typedef enum
{
    SET_DL_FLAG = 0,      ///< set brom download flag
    CLR_DL_FLAG = 1,      ///< clear download flag
    SET_BL_DL_FLAG = 2  ///< set bootloader download flag
} SYSTEM_EX_CMD;

META_RESULT  __stdcall META_MISC_EX_SetCommandToSystem(unsigned int ms_timeout, const SYSTEM_EX_CMD command);
META_RESULT  __stdcall META_MISC_EX_SetCommandToSystem_r(const int meta_handle, unsigned int ms_timeout, const SYSTEM_EX_CMD command);

typedef struct
{
    char            imei[16];
    unsigned short  record_index;
    unsigned char   svn;
} META_SET_IMEI_T;
typedef struct
{
    unsigned char wifi_mac[6];
} META_SET_WIFI_T;

/**
 * \internal
 * \details Set IMEI Value API for internal flashtool usage
 * \param req IMEI record setting
 * \param record_index the index of RID
 * \endinternal
 */
META_RESULT __stdcall META_MISC_SetIMEIValue_r(const int meta_handle, const unsigned int ms_timeout, META_SET_IMEI_T* req, unsigned short* record_index);
/**
 * \internal
 * \brief non-reentrant version of META_MISC_SetIMEIValue_r
 * \endinternal
 */
META_RESULT __stdcall META_MISC_SetIMEIValue(const unsigned int ms_timeout, META_SET_IMEI_T* req, unsigned short* record_index);


/**
 * \internal
 * \brief non-reentrant version of META_MISC_SetWifiMacAddr
 * \endinternal
 */
META_RESULT __stdcall META_MISC_SetWifiMacAddr_r(const int meta_handle, const unsigned int ms_timeout, META_SET_WIFI_T* req, unsigned int* status);
/**
 * \internal
 * \details Set WiFi MAC Value API for internal flashtool usage
 * \param req Wifi MAC Addresss etting
 * \param status the status code
 * \endinternal
 */
META_RESULT __stdcall META_MISC_SetWifiMacAddr(const unsigned int ms_timeout, META_SET_WIFI_T* req, unsigned int* status);

/*********************
 * Ram Disk dump API *
 *********************/
/**
 * \brief non-reentrant version of META_MISC_EX_CheckRamDiskExist_r
 */
META_RESULT  __stdcall  META_MISC_EX_CheckRamDiskExist(const int timeout, char* cExist);
/**
 * \details Check ram disk existing or not.
 * \param[in] meta_handle meta handler
 * \param [in] timeout time out (ms)
 * \param [out] cExist 0: ramdisk is not existing. 1: ramdisk is existing.
 * \retval META_SUCCESS ram disk is existing
 * \retval META_FAILED  ram disk is not existing
 **/
META_RESULT  __stdcall  META_MISC_EX_CheckRamDiskExist_r(const int meta_handle, const int timeout, char* cExist);
/**
 * \brief non-reentrant version of META_MISC_EX_RamDisk_GetSize_r
 */
META_RESULT  __stdcall  META_MISC_EX_RamDisk_GetSize(const int timeout, unsigned int* i4Size);
/**
 * \brief Get ram disk size.
 * \param [in] meta_handle meta handler
 * \param [in] timeout time out (ms)
 * \param [out] i4Size ram disk size
 * \retval META_SUCCESS ram disk size getting successed
 * \retval META_FAILED ram disk size getting failed
 **/
META_RESULT  __stdcall  META_MISC_EX_RamDisk_GetSize_r(const int meta_handle, const int timeout, unsigned int* i4Size);
META_RESULT  __stdcall  META_MISC_EX_RamDisk_Backup_To_File(const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token, int* p_stopflag);
/**
 * \brief Back up ram disk to file
 * \param [in] meta_handle meta handler
 * \param [in] local_filepath the path and file name to store the back up binary image
 * \param [in] cb_progress the callback of progress report
 * \param [in] cb_progress_arg the arugement of callback of progress report
 * \param [out] p_token identify token
 * \param [in] p_stopflag the stop control flag, when the flag set to true. The back up progress will stop.
 * \retval META_SUCCESS back up successfuly
 * \retval META_FAILED back up failed
 **/
META_RESULT  __stdcall  META_MISC_EX_RamDisk_Backup_To_File_r(const int meta_handle, const char* local_filepath, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg, short* p_token, int* p_stopflag);

/**
 * @}
 */
/**
 * \brief non-reentrant version of META_Customer_Func_r
 */
META_RESULT __stdcall META_Customer_Func(int ms_timeout, const unsigned char* data_in, const int data_in_len, unsigned char* data_out, int* data_out_len);
/**
 * \details the virtual channel for customized test commands
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param data_in virtual channel data (input: to target side)
 * \param data_in_len length of input data
 * \param data_out virtual channel data (output: to host side)
 * \param data_out_len length of output data
 */
META_RESULT __stdcall META_Customer_Func_r(int meta_handle, int ms_timeout, const unsigned char* data_in, const int data_in_len, unsigned char* data_out, int* data_out_len);

/**
 * \brief non-reentrant version of META_Aux_Func_r
 */
META_RESULT __stdcall META_Aux_Func(int ms_timeout, const unsigned char* data_in, const int data_in_len, unsigned char* data_out, int* data_out_len);
/**
 * \details the virtual channel for TD test commands
 * \param meta_handle meta handle
 * \param ms_timeout time out in ms
 * \param data_in virtual channel data (input: to target side)
 * \param data_in_len length of input data
 * \param data_out virtual channel data (output: to host side)
 * \param data_out_len length of output data
 */
META_RESULT __stdcall META_Aux_Func_r(int meta_handle, int ms_timeout, const unsigned char* data_in, const int data_in_len, unsigned char* data_out, int* data_out_len);
//--------------------------------------------------------------------------//
//  META Audio / Speech APIs
//--------------------------------------------------------------------------//
#include "meta_dll_audio.h"
//--------------------------------------------------------------------------//
//  META Multi-Media APIs
//--------------------------------------------------------------------------//
#include "meta_dll_mm.h"
//--------------------------------------------------------------------------//
//  META Connecitivty APIs
//--------------------------------------------------------------------------//
#include "meta_dll_connectivity.h"

//--------------------------------------------------------------------------//
//  META Virtual Channel APIs
//--------------------------------------------------------------------------//
typedef enum
{
    META_MODEM_SRV_INVALID = 0,
    META_MODEM_SRV_TST = 1,
    META_MODEM_SRV_DHL = 2,
    META_MODEM_SRV_ETS = 3,
    META_MODEM_SRV_NUM,
    META_MODEM_SRV_END = 0x0fffffff
} META_MODEM_SRV;

typedef enum
{
    META_MODEM_CH_NATIVE_INVALID = 0,
    META_MODEM_CH_NATIVE_TST = 1,
    META_MODEM_CH_TUNNELING = 2,
    META_MODEM_CH_TUNNELING_IGNORE_CKSM = 3,
    META_MODEM_CH_NATIVE_ETS = 4,
    META_MODEM_CH_NUM,
    META_MODEM_CH_END = 0x0fffffff
} META_MODEM_CH_TYPE;

typedef void (*MetaVCRxMsgHandler_CB)(const unsigned char* frameBuffer, unsigned int length, void* arg);

META_RESULT __stdcall META_VC_SendData_r(int meta_handle, int vc_idx, char* buf, unsigned int len);
META_RESULT __stdcall META_VC_RegisterReceiveHandler_r(int meta_handle, int vc_idx, MetaVCRxMsgHandler_CB  cb, void* para);

typedef void (*MetaCrfRxMsgHandler_CB)(const unsigned char* frameBuffer, unsigned int length, void* arg);
META_RESULT __stdcall META_Crf_SendData_r(int meta_handle, char* buf, unsigned int len);
META_RESULT __stdcall META_Crf_RegisterReceiveHandler_r(int meta_handle, MetaVCRxMsgHandler_CB  cb, void* para);

/* set dump trace file */
bool __stdcall META_SetModemLogDumpFilePath_r(const int meta_handle, char* p_dump_file_path);
bool __stdcall META_SetModemLogDumpFileName_r(const int meta_handle, char* p_dump_file_name);

void __stdcall META_SetAPITimoutValue(unsigned long msMinTime, unsigned long msDebugTime);
typedef struct
{
    int req_id;
    int cnf_id;
    unsigned int cmdType;
    char* reqLocal;
    unsigned int reqLocalLength;
    char* reqPeer;
    unsigned int reqPeerLength;
} META_Engineering_Request_Struct_t;
typedef struct
{
    char* cnfLocal;
    unsigned int cnfLocalLength;
    char* cnfPeer;
    unsigned int cnfPeerLength;
} META_Engineering_Confirm_Struct_t;
META_RESULT __stdcall META_EngineeringFunction_r(const int metaHandle, const unsigned int msTimeout,
                                       const META_Engineering_Request_Struct_t* req,
                                       META_Engineering_Confirm_Struct_t* cnf);
typedef void (__stdcall* TYPE_EngineeringCallbackFunction_fp)(const int metaHandle, const unsigned short cnfId, const unsigned int cmdType, const short token, const char* cnfParamBuf, const int cnfParamBufLen, const char* cnfPduBuf, const int cnfPduBufLen, void* arg);
META_RESULT __stdcall META_EngineeringFunctionNonBlocking_r(const int metaHandle,
                                       const META_Engineering_Request_Struct_t* req,
                                       TYPE_EngineeringCallbackFunction_fp cb, void* arg, short* token);

META_RESULT  __stdcall META_L4_SwitchMetaModeReady_r(const int meta_handle, unsigned int ms_waiting_time, unsigned int mode);

#if defined(__cplusplus)
}
#endif // #if defined(__cplusplus)

#endif // #ifndef META_DLL_H

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * meta_dll_nfc.h
 *
 * Project:
 * --------
 *   META
 *
 * Description:
 * ------------
 *   This module contains the META DLL NFC exported API.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __META_DLL_NFC_H__
#define __META_DLL_NFC_H__
#if !defined(__GNUC__) || !defined(WIN32)
#include "meta.h"
#ifdef __cplusplus
extern "C" {
#endif
/**
 * \addtogroup Connectivity
 *  @{
 */
/*****************************************************
 * NFC test mode commands
 ****************************************************/
typedef struct
{
    unsigned int type;
    unsigned int action;
    unsigned int length;
} META_NFC_SCRIPT_REQUEST_T;
typedef struct
{
    unsigned int result;
    unsigned int length;
} META_NFC_SCRIPT_RESPONSE_T;
META_RESULT __stdcall META_NFC_TestModeCardModeTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeCardModeTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeReaderModeTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeReaderModeTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeP2PModeTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeP2PModeTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeSwpSelfTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeSwpSelfTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeAntennaSelfTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeAntennaSelfTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SCRIPT_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int   type;    /*Test type: currently, always set 1*/
    unsigned int   action;  /*Test action, 1: start test, 0:stop test*/
    unsigned char  modulation_type;   /* 0:type A, 1:type B, 2:type F, 3:No Modulation */
    unsigned char  bitrate;           /* 0:106kbps, 1:212kbps, 2:424kbps */
} META_NFC_TX_ALWAYSON_REQUEST_T;
META_RESULT __stdcall META_NFC_TestModeTxAlwaysOnTest(const unsigned int ms_timeout, const META_NFC_TX_ALWAYSON_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeTxAlwaysOnTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_TX_ALWAYSON_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeTxAlwaysOnWithoutAckTest(const unsigned int ms_timeout, const META_NFC_TX_ALWAYSON_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeTxAlwaysOnWithoutAckTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_TX_ALWAYSON_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int    type;           /*Test type: currently, always set 1*/
    unsigned int    action;        /*Test action, 1: start test, 0:stop test*/
    unsigned short  technology;    /*bitmask: MifareUL=bit 0, MifareStd=bit1, ISO14443_4A=bit 2, ISO14443_4B=bit 3, Jewel=bit 4, Felica=bit 5, ISO15693=bit 6 */
    unsigned short  protocols;     /*bitmask: Iso14443A=bit 0, Iso14443B=bit 1, Felica212=bit 2, Felica424=bit 3, Iso15693=bit 4 */
} META_NFC_CARD_EMULATION_REQUEST_T;
META_RESULT __stdcall META_NFC_TestModeCardEmulationTest(const unsigned int ms_timeout, const META_NFC_CARD_EMULATION_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeCardEmulationTest_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_CARD_EMULATION_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int  type;
    unsigned int  action;
    unsigned int  uid_length;
    unsigned char data[10];
} META_NFC_SCRIPT_UID_REQUEST_T;
typedef struct
{
    int           result;
    unsigned int  uid_length;
    unsigned char data[10];
} META_NFC_SCRIPT_UID_RESPONSE_T;
META_RESULT __stdcall META_NFC_TestModeUidReadWriteTest(const unsigned int ms_timeout, const META_NFC_SCRIPT_UID_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_UID_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_TestModeUidReadWriteTest_r(const int meta_handle, const unsigned int ms_timeout,  const META_NFC_SCRIPT_UID_REQUEST_T* request, unsigned int requestLength, META_NFC_SCRIPT_UID_RESPONSE_T* response, unsigned int responseLength);
/*****************************************************
 * NFC Init commands
 ****************************************************/
typedef struct
{
    unsigned int nfc_enable;
    unsigned int debug_enable;
    unsigned int sw_protocol;
    unsigned int get_capabilities;
} META_NFC_SETTING_REQUEST_T;
typedef struct
{
    unsigned int status;
    unsigned int nfc_enable;
    unsigned int debug_enable;
    unsigned int sw_protocol;
    unsigned int get_capabilities;
    unsigned int sw_ver;
    unsigned int hw_ver;
    unsigned int fw_ver;
    unsigned int reader_mode;
    unsigned int card_mode;
} META_NFC_SETTING_RESPONSE_T;
META_RESULT __stdcall META_NFC_InitQuery(const unsigned int ms_timeout, const META_NFC_SETTING_REQUEST_T* request, unsigned int requestLength, META_NFC_SETTING_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_InitQuery_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SETTING_REQUEST_T* request, unsigned int requestLength, META_NFC_SETTING_RESPONSE_T* response, unsigned int responseLength);
/*****************************************************
 * NFC SWP commands
 ****************************************************/
typedef struct
{
    unsigned int reg_type;
} META_NFC_SWP_REGISTER_NOTIFICATION_REQUEST_T;
typedef struct
{
    unsigned int status;
    unsigned int se;
    unsigned int se_status;
    unsigned int se_type;
} META_NFC_SWP_REGISTER_NOTIFICATION_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpRegisterNotification(const unsigned int ms_timeout, const META_NFC_SWP_REGISTER_NOTIFICATION_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_REGISTER_NOTIFICATION_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpRegisterNotification_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_REGISTER_NOTIFICATION_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_REGISTER_NOTIFICATION_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int set_type;
} META_NFC_SWP_SECURE_ELEMENT_REQUEST_T;
typedef struct
{
    unsigned int status;
} META_NFC_SWP_SECURE_ELEMENT_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpSecureElementSet(const unsigned int ms_timeout, const META_NFC_SWP_SECURE_ELEMENT_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_SECURE_ELEMENT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpSecureElementSet_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_SECURE_ELEMENT_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_SECURE_ELEMENT_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int dis_type;
    unsigned int duration;
} META_NFC_SWP_DISCOVERY_REQUEST_T;
typedef struct
{
    unsigned int  tag_type;
    unsigned int  card_type;
    unsigned char uid[10];
    unsigned int  sak;
    unsigned int  atag;
    unsigned int  appdata;
    unsigned int  maxdatarate;
} META_NFC_SWP_TAG_DETECTED_RESPONSE_T;
typedef struct
{
    unsigned int p2p_type;
} META_NFC_SWP_P2P_DETECTED_RESPONSE_T;
typedef union
{
    META_NFC_SWP_TAG_DETECTED_RESPONSE_T tag_data;
    META_NFC_SWP_P2P_DETECTED_RESPONSE_T p2p_data;
} META_NFC_SWP_DETECTED_TYPE_U;
typedef struct
{
    unsigned int status;
    unsigned char type;
    META_NFC_SWP_DETECTED_TYPE_U detect_target;
} META_NFC_SWP_DISCOVERY_RESPONSE_T;
typedef void (__stdcall* META_NFC_DISCOVERY_CALLBACK)(const void* buffer, unsigned int bufferLength, void* cb_arg);
META_RESULT __stdcall META_NFC_SwpDiscovery(const unsigned int ms_timeout, const META_NFC_SWP_DISCOVERY_REQUEST_T* request, unsigned int requestLength, META_NFC_DISCOVERY_CALLBACK cb, void* cb_arg);
META_RESULT __stdcall META_NFC_SwpDiscovery_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_DISCOVERY_REQUEST_T* request, unsigned int requestLength, META_NFC_DISCOVERY_CALLBACK cb, void* cb_arg);
typedef struct
{
    unsigned int action;
} META_NFC_SWP_TAG_DISCONNECT_REQUEST_T;
typedef struct
{
    unsigned int status;
} META_NFC_SWP_TAG_DISCONNECT_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpTagDisconnect(const unsigned int ms_timeout, const META_NFC_SWP_TAG_DISCONNECT_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_DISCONNECT_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpTagDisconnect_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_TAG_DISCONNECT_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_DISCONNECT_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int action;
} META_NFC_SWP_TAG_FORMAT_TO_NDEF_REQUEST_T;
typedef struct
{
    unsigned int status;
} META_NFC_SWP_TAG_FORMAT_TO_NDEF_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpTagFormatToNdef(const unsigned int ms_timeout, const META_NFC_SWP_TAG_FORMAT_TO_NDEF_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_FORMAT_TO_NDEF_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpTagFormatToNdef_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_TAG_FORMAT_TO_NDEF_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_FORMAT_TO_NDEF_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned char read_type;
    unsigned int  sector;
    unsigned int  block;
    unsigned char AuthentificationKey;
} META_NFC_SWP_TAG_READ_REQUEST_T;
typedef struct
{
    unsigned int   length;
    unsigned char  data[16];
} META_NFC_SWP_TAG_READ_MIFARE4K_DATA_T;
typedef struct
{
    unsigned int   length;
    unsigned char  data[4];
} META_NFC_SWP_TAG_READ_ISO15693_DATA_T;
typedef struct
{
    unsigned char ndef_type;
    unsigned char lang[3];
    unsigned char recordFlags;
    unsigned char recordId[32];
    unsigned char recordTnf;
    unsigned int  length;
    unsigned char data[512];
} META_NFC_SWP_TAG_READ_NDEF_DATA_T;
typedef union
{
    META_NFC_SWP_TAG_READ_MIFARE4K_DATA_T mifare4k;
    META_NFC_SWP_TAG_READ_ISO15693_DATA_T iso15693;
    META_NFC_SWP_TAG_READ_NDEF_DATA_T     ndef;
} META_NFC_SWP_TAG_READ_BUFFER_T;
typedef struct
{
    unsigned int  status;
    unsigned char type;
    META_NFC_SWP_TAG_READ_BUFFER_T data;
} META_NFC_SWP_TAG_READ_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpTagRead(const unsigned int ms_timeout, const META_NFC_SWP_TAG_READ_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_READ_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpTagRead_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_TAG_READ_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_READ_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int   sector;
    unsigned int   block;
    unsigned char  data[16];
    unsigned char  AuthentificationKey;
} META_NFC_SWP_TAG_WRITE_MIFARE4K_DATA_T;
typedef struct
{
    unsigned int   sector;
    unsigned int   block;
    unsigned char  data[4];
} META_NFC_SWP_TAG_WRITE_ISO15693_DATA_T;

typedef struct
{
    char Name[64];
    char Company[64];
    char Titlep[64];
    char Tel[32];
    char Email[64];
    char Adress[128];
    char PostalCode[32];
    char City[64];
    char CompanyUrl[64];
} META_NFC_SWP_TAG_WRITE_NDEF_VCARD_T;

typedef struct
{
    unsigned char  Company[64];
    unsigned short CompanyLength;
    unsigned char  CompanyUrl[64];
    unsigned short CompanyUrlLength;
} META_NFC_SWP_TAG_WRITE_NDEF_SMARTPOSTER_T;

typedef struct
{
    unsigned char  data[128];
    unsigned short DataLength;
} META_NFC_SWP_TAG_WRITE_NDEF_TEXT_T;

typedef struct
{
    unsigned char  URLtype;
    unsigned char  URLData[64];
    unsigned short URLLength;
} META_NFC_SWP_TAG_WRITE_NDEF_URL_T;

typedef struct
{
    char  EXTTagType[64];
    char  EXTData[128];
    unsigned short EXTLength;
} META_NFC_SWP_TAG_WRITE_NDEF_EXTTAG_T;


typedef union
{
    META_NFC_SWP_TAG_WRITE_NDEF_SMARTPOSTER_T  SP_Data;
    META_NFC_SWP_TAG_WRITE_NDEF_VCARD_T        VC_Data;
    META_NFC_SWP_TAG_WRITE_NDEF_TEXT_T         TX_Data;
    META_NFC_SWP_TAG_WRITE_NDEF_URL_T          URL_Data;
    META_NFC_SWP_TAG_WRITE_NDEF_EXTTAG_T       EXT_Data;
    char                                       buffer[576];
} META_NFC_SWP_TAG_WRITE_NDEF_DATA_U;

typedef struct
{
    unsigned char  ndef_type;
    unsigned char  language;
    unsigned int   length;
    META_NFC_SWP_TAG_WRITE_NDEF_DATA_U  ndef_data;
} META_NFC_SWP_TAG_WRITE_NDEF_DATA_T;
typedef union
{
    META_NFC_SWP_TAG_WRITE_MIFARE4K_DATA_T mifare4k;
    META_NFC_SWP_TAG_WRITE_ISO15693_DATA_T iso15693;
    META_NFC_SWP_TAG_WRITE_NDEF_DATA_T     ndef;
} META_NFC_SWP_TAG_WRITE_BUFFER_T;
typedef struct
{
    unsigned char write_type;
    META_NFC_SWP_TAG_WRITE_BUFFER_T payload;
} META_NFC_SWP_TAG_WRITE_REQUEST_T;
typedef struct
{
    unsigned char write_type;
    unsigned int  status;
} META_NFC_SWP_TAG_WRITE_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpTagWrite(const unsigned int ms_timeout, const META_NFC_SWP_TAG_WRITE_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_WRITE_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpTagWrite_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_TAG_WRITE_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_WRITE_RESPONSE_T* response, unsigned int responseLength);

typedef struct
{
    unsigned char type;
    unsigned int  length;
    unsigned char data[256];
} META_NFC_SWP_TAG_RAW_COMM_REQUEST_T;
typedef struct
{
    unsigned char type;
    unsigned int  status;
    unsigned int  length;
    unsigned char data[256];
} META_NFC_SWP_TAG_RAW_COMM_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpTagRawCommunication(const unsigned int ms_timeout, const META_NFC_SWP_TAG_RAW_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_RAW_COMM_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpTagRawCommunication_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_TAG_RAW_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_TAG_RAW_COMM_RESPONSE_T* response, unsigned int responseLength);
typedef struct
{
    unsigned int action;
    unsigned int length;
    void* buffer;
} META_NFC_SWP_P2P_COMM_REQUEST_T;
typedef struct
{
    unsigned int status;
    /// [IN/OUT] output: modified as the length of return buffer length
    unsigned int length;
    /// [IN] output: returned buffer (DO not free/delete the buffer, the buffer is maintained in META DLL)
    void* buffer;
} META_NFC_SWP_P2P_COMM_RESPONSE_T;
META_RESULT __stdcall META_NFC_SwpP2PCommunication(const unsigned int ms_timeout, const META_NFC_SWP_P2P_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_P2P_COMM_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_SwpP2PCommunication_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_SWP_P2P_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_SWP_P2P_COMM_RESPONSE_T* response, unsigned int responseLength);
/*****************************************************
 * NFC RAW DATA commands
 ****************************************************/
typedef struct
{
    unsigned int action;
    unsigned int length;
    void* buffer;
} META_NFC_RAW_COMM_REQUEST_T;
typedef struct
{
    unsigned int status;
    /// [IN/OUT] output: modified as the length of return buffer length
    unsigned int length;
    /// [IN] output: returned buffer (DO not free/delete the buffer, the buffer is maintained in META DLL)
    void* buffer;
} META_NFC_RAW_COMM_RESPONSE_T;
META_RESULT __stdcall META_NFC_RawDataCommunication(const unsigned int ms_timeout, const META_NFC_RAW_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_RAW_COMM_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_NFC_RawDataCommunication_r(const int meta_handle, const unsigned int ms_timeout, const META_NFC_RAW_COMM_REQUEST_T* request, unsigned int requestLength, META_NFC_RAW_COMM_RESPONSE_T* response, unsigned int responseLength);
/**
 * @}
 */
#ifdef __cplusplus
}
#endif
#endif // #if !defined(__GNUC__) || !defined(WIN32)
#endif // __META_DLL_NFC_H__

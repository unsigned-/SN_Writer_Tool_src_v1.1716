#ifndef HDCP_ENCRYPTION_H
#define HDCP_ENCRYPTION_H

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the HDCPENCRYPTION_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// HDCPENCRYPTION_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef HDCPENCRYPTION_EXPORTS
#define HDCPENCRYPTION_API extern "C" __declspec(dllexport)
#else
#define HDCPENCRYPTION_API extern "C" __declspec(dllimport)
#endif



//return value
typedef enum _EN_HDCP_RET
{
    R_OK = 0,                       //successfull
    R_INV_ARG,                      //invalid arguments
    R_NOT_DEFINE_CONTROL_TYPE,      //not defined control type
    R_NOT_ENCRYPTED_BIN,            //not encrypted HDCP binary
    R_SET_DECRYPT_KEY_ERR,          //set decrypted AES key error
    R_ENCRYPT_IC_ERR                //encrypted IC error
} EN_HDCP_RET;


//length info
#define  CUST_KEY_LEN               16
#define  IV_LEN                     16
#define  ORGINAL_HDCP_LEN           287
#define  ENCRYPTED_HDCP_LEN         305
#define HDCP_KEY_ARRAY_NUMBER_FILE  305


//export API

/*****************************************************************************/
//Name       :  HdcpProcess
//Description:  do further cryptographic process for encrypted HDCP data
//Input      :  acEncryptedHdcp - encrypted data
//Ouput      :  acOut - proecessed data by this function
//Returns    :  please refer to "return value" comments 
/*****************************************************************************/
HDCPENCRYPTION_API EN_HDCP_RET __stdcall HdcpProcess(
                        const unsigned char acEncryptedHdcp[ENCRYPTED_HDCP_LEN],
                        unsigned char acOut[ORGINAL_HDCP_LEN]);
                        

#endif



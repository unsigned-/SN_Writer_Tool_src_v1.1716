#ifndef _DES_H
#define _DES_H

#include <windows.h>

#define DES_KEY_LEN 8
#define DES_DATA_LEN 64

typedef enum {
  S_DES_SUCCESS,
  S_DES_FAIL,
  S_DDES_FAIL,
  S_DES_DATALEN_TOO_BIG,
  S_DES_KEYLEN_TOO_BIG,
  S_DES_OPEN_FILE_ERROR
}STATUS_DES;

#ifdef __cplusplus
extern "C"
{
#endif

/*
Function Name: des
Function Description: use DES to encrypt the data;
intput: 
   data: the data need to be encrypted
   datelen: datalen
   key: 64 bit key (Must be 64bit)
output:
   data: encrypted data by DES

return: 
   S_DES_SUCCESS: indicates success;
   S_DES_FAIL: indicates fail;
*/
__declspec(dllexport) INT32 __stdcall WriteDataToFile(BYTE *data,INT32 datelen, BYTE *key, char* pcPathBuf);

/*
Function Name: Ddes
Function Description: use DES to Decrypt the data;
intput: 
   data: the data need to be Decrypt
   datelen: datalen
   key: 64 bit key (Must be 64bit and be the same as the key used in des() function)
output:
   data: Decrypt data by DES
*/
 __declspec(dllexport) INT32 __stdcall ReadDataFromFile(BYTE *data,INT32 datelen, BYTE *key, char* pcPathBuf);

#ifdef __cplusplus
};
#endif

#endif
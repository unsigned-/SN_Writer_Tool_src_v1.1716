#ifndef _AUTO_GEN_H_
#define _AUTO_GEN_H_

#include <windows.h>

typedef enum
{
    AutoGen_WITHOUT_OPTION = 0,
    AutoGen_IMEI_CHECKSUM_OPTION,
    AutoGen_BARC_DENARY_OPTION,
    AutoGen_RESERVE_OPTION = 255
}AutoGenOption_e;

typedef enum
{
    AutoGen_Barcode = 0,
    AutoGen_IMEI = 1,
    AutoGen_BT = 2,
    AutoGen_Wifi = 3,
	AutoGen_Ethernet = 4,
    AutoGen_DRMKeyMCID = 5
}AutoGenType_e;

typedef enum
{
    AutoGen_Success = 0,
    AutoGen_Fail,
    AutoGen_Invalid_Argument,
    AutoGen_Not_Support_Type,
    AutoGen_Not_Enough_Buf,
    AutoGen_Unknow = 255
}AutoGenResult_e;

#ifdef _AUTOGEN_API_EXPORT_
#define AUTOGEN_API __declspec(dllexport)
#else
#define AUTOGEN_API __declspec(dllimport)
#endif

/*
*Denary notation max digit is 2147483648
*Hexadecimal notation max digit is 7FFFFFFF
*/

#ifdef __cplusplus
extern "C"
{
#endif
    
    AUTOGEN_API AutoGenResult_e __stdcall strTolong(const char *nptr, long *value, int radix);
    AUTOGEN_API AutoGenResult_e __stdcall longTostr(long value,char *string, int radix);
    AUTOGEN_API AutoGenResult_e __stdcall AutoIncrease(AutoGenType_e eDataType, long step, char pOutData[], int bufSize);
    AUTOGEN_API AutoGenResult_e __stdcall AutoIncrease_Ex(AutoGenType_e eDataType, long step, char pOutData[], int bufSize, AutoGenOption_e eOption = AutoGen_WITHOUT_OPTION);

#ifdef __cplusplus
};
#endif

#endif
#include "StdAfx.h"
#include "Common.h"
#include "SNFstream.h"
#include "meta.h"
#include "C2kAgent_api.h"

#include "xboot_debug.h"
#include "Mdebug.h"
#include "USBSwitchDLLibrary.h"
#include "des.h"
#include "AutoGen.h"
#include "SNbase.h"

namespace SPMETA_DLL
{
    #include "Spmeta.h"
};


void *g_hSwitchTool = NULL;
//DWORD g_MainDlgHandle; 
META_Common_struct g_sMetaComm;
int  g_iMetaStopFlag;
char g_pSetupFilepath[MAX_PATH];
char g_pPasswdFilepath[MAX_PATH];
Login_Identify_e g_LoginIdentify;

#ifdef _AUTO_GEN_FEATURE_
char g_pAutoGenSetupFilepath[MAX_PATH];
AutoGenData_struct  g_AutoGenData;
IniData_struct g_AutoGenSetup[] =
{
    {"Enable AutoGen", (bool*)&g_AutoGenData.bEnableAutoGen, INI_BOOLEAN},
    {"Barcode Increase Radix", (int*)&g_AutoGenData.eIncreaseRadix, INI_INTEGER},
    {"AutoGen Barcode", (bool*)&g_AutoGenData.bAutoGenBarcode, INI_BOOLEAN},
    {"AutoGen IMEI", (bool*)&g_AutoGenData.bAutoGenIMEI, INI_BOOLEAN},
    {"AutoGen BT", (bool*)&g_AutoGenData.bAutoGenBT, INI_BOOLEAN},
    {"AutoGen Wifi", (bool*)&g_AutoGenData.bAutoGenWifi, INI_BOOLEAN},
    {"AutoGen Ethernet", (bool*)&g_AutoGenData.bAutoGenEthernet, INI_BOOLEAN},
    {"AutoGen DRMKey MCID", (bool*)&g_AutoGenData.bAutoGenDRMKeyMCID, INI_BOOLEAN},

    {"Barcode Step", (int*)&g_AutoGenData.sBarcode.iStep, INI_INTEGER},
    {"Barcode Start", (char*)&g_AutoGenData.sBarcode.Start, INI_STRING},
    {"Barcode End", (char*)&g_AutoGenData.sBarcode.End, INI_STRING},
    {"Barcode Next", (char*)&g_AutoGenData.sBarcode.Next, INI_STRING},

    {"IMEI Step", (int*)&g_AutoGenData.sIMEI.iStep, INI_INTEGER},
    {"IMEI Start", (char*)&g_AutoGenData.sIMEI.Start, INI_STRING},
    {"IMEI End", (char*)&g_AutoGenData.sIMEI.End, INI_STRING},
    {"IMEI Next", (char*)&g_AutoGenData.sIMEI.Next, INI_STRING},

    {"BT Step", (int*)&g_AutoGenData.sBtAddress.iStep, INI_INTEGER},
    {"BT Start", (char*)&g_AutoGenData.sBtAddress.Start, INI_STRING},
    {"BT End", (char*)&g_AutoGenData.sBtAddress.End, INI_STRING},
    {"BT Next", (char*)&g_AutoGenData.sBtAddress.Next, INI_STRING},

    {"Wifi Step", (int*)&g_AutoGenData.sWifiAddress.iStep, INI_INTEGER},
    {"Wifi Start", (char*)&g_AutoGenData.sWifiAddress.Start, INI_STRING},
    {"Wifi End", (char*)&g_AutoGenData.sWifiAddress.End, INI_STRING},
    {"Wifi Next", (char*)&g_AutoGenData.sWifiAddress.Next, INI_STRING},

    {"Ethernet Step", (int*)&g_AutoGenData.sEthernetAddress.iStep, INI_INTEGER},
    {"Ethernet Start", (char*)&g_AutoGenData.sEthernetAddress.Start, INI_STRING},
    {"Ethernet End", (char*)&g_AutoGenData.sEthernetAddress.End, INI_STRING},
    {"Ethernet Next", (char*)&g_AutoGenData.sEthernetAddress.Next, INI_STRING},

    {"DRMKey MCID Step", (int*)&g_AutoGenData.sDRMKeyMCID.iStep, INI_INTEGER},
    {"DRMKey MCID Start", (char*)&g_AutoGenData.sDRMKeyMCID.Start, INI_STRING},
    {"DRMKey MCID End", (char*)&g_AutoGenData.sDRMKeyMCID.End, INI_STRING},
    {"DRMKey MCID Next", (char*)&g_AutoGenData.sDRMKeyMCID.Next, INI_STRING},
};

#endif //#ifdef _AUTO_GEN_FEATURE_

IniData_struct g_IniData[] =
{
    {"Stress Test", &g_sMetaComm.iStressTest, INI_INTEGER},
    {"Already in Meta", &g_sMetaComm.bAlreadyInMeata, INI_BOOLEAN},
    {"Keep in Meta", &g_sMetaComm.bKeepInMeta, INI_BOOLEAN},
    {"Clear Meta Boot Flag", &g_sMetaComm.bClearMetaBootFlag, INI_BOOLEAN},
    {"Operator Mode", (int*)&g_sMetaComm.eOperatorMode, INI_INTEGER},
    {"Preloader Connect Timeout", (int*)&g_sMetaComm.iPre_Connect_Timeout, INI_INTEGER},
    {"Kernel Connect Timeout", (int*)&g_sMetaComm.iKernel_Connect_Timeout, INI_INTEGER},
    {"Target type", (int*)&g_sMetaComm.eTargetType, INI_INTEGER},
    {"Brom Port Filter", (char*)g_sMetaComm.sPortFilter.strBromFilter, INI_STRING},
    {"Preloader Port Filter", (char*)g_sMetaComm.sPortFilter.strPreloaderFilter, INI_STRING},
    {"Kernel Port Filter", (char*)g_sMetaComm.sPortFilter.strKernelFilter, INI_STRING},
    {"Composite Device Enable", (bool*)&g_sMetaComm.bCompositeDeviceEnable, INI_BOOLEAN},
    {"Usb Enable", (bool*)&g_sMetaComm.bUsbEnable, INI_BOOLEAN},
    {"USBSwitchTool Enable", (bool*)&g_sMetaComm.bSwithTool, INI_BOOLEAN},
    {"DualTalk Enable", (bool*)&g_sMetaComm.bDualTalk, INI_BOOLEAN},
    {"Security USB Enable", (bool*)&g_sMetaComm.bSecurityUSB, INI_BOOLEAN},
    {"USB Without Battery Enable", (bool*)&g_sMetaComm.bWithoutBattery, INI_BOOLEAN},
    {"Skip Write Prod_Info Enable", (bool*)&g_sMetaComm.bSkipWriteProdInfo, INI_BOOLEAN},
    {"Check BackupNv to PC Enable", (bool*)&g_sMetaComm.bCheckBackNVtoPC, INI_BOOLEAN},    
    {"Check Fastboot OEM Lock Enable", (bool*)&g_sMetaComm.bCheckFastbootLock, INI_BOOLEAN},
    {"Check Calibration flag Enable", (bool*)&g_sMetaComm.bCheckCalFlag, INI_BOOLEAN},
    {"Check FinalTest flag Enable", (bool*)&g_sMetaComm.bCheckFtFlag, INI_BOOLEAN},
    // C2K Modem
    {"Write Meid", (bool*)&g_sMetaComm.sWriteOption.bWriteMeid, INI_BOOLEAN},
    {"Write Esn", (bool*)&g_sMetaComm.sWriteOption.bWriteEsn, INI_BOOLEAN},
    {"Write Barcode", (bool*)&g_sMetaComm.sWriteOption.bWriteBarcode, INI_BOOLEAN},
    {"Write IMEI", (bool*)&g_sMetaComm.sWriteOption.bWriteIMEI, INI_BOOLEAN},
    {"Write Serial No.", (bool*)&g_sMetaComm.sWriteOption.bWriteSerialNo, INI_BOOLEAN},
    {"Write BT", (bool*)&g_sMetaComm.sWriteOption.bWriteBT, INI_BOOLEAN},
    {"Write Wifi", (bool*)&g_sMetaComm.sWriteOption.bWriteWifi, INI_BOOLEAN},
    {"Write Hdcp", (bool*)&g_sMetaComm.sWriteOption.bWriteHdcp, INI_BOOLEAN},
    {"Write DRMKey", (bool*)&g_sMetaComm.sWriteOption.bWriteDrm, INI_BOOLEAN},
    {"Install Hdcp Data", (bool*)&g_sMetaComm.sWriteOption.bInstallHdcpData, INI_BOOLEAN},   
    {"Write Ethernet Mac Address", (bool*)&g_sMetaComm.sWriteOption.bWriteEthernetMac, INI_BOOLEAN},
    {"Write DRMkey MCID", (bool*)&g_sMetaComm.sWriteOption.bWriteDrmkeyMCID, INI_BOOLEAN},
    {"IMEI Nums", (int*)&g_sMetaComm.sIMEIOption.iImeiNums, INI_INTEGER},
    {"IMEI CheckSum", (bool*)&g_sMetaComm.sIMEIOption.bCheckSum, INI_BOOLEAN},
    {"IMEI Lock", (bool*)&g_sMetaComm.sIMEIOption.bLockIMEI, INI_BOOLEAN},
    {"DualIMEI same", (bool*)&g_sMetaComm.sIMEIOption.bDualIMEISame, INI_BOOLEAN},
    {"IMEI_1 Check header", (bool*)&g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader, INI_BOOLEAN},
    {"IMEI_2 Check header", (bool*)&g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader, INI_BOOLEAN},
    {"IMEI_3 Check header", (bool*)&g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader, INI_BOOLEAN},
    {"IMEI_4 Check header", (bool*)&g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader, INI_BOOLEAN},
    //C2K modem
    {"Meid Check header", (bool*)&g_sMetaComm.sMeidHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Esn Check header", (bool*)&g_sMetaComm.sEsnHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Serial No. Check header", (bool*)&g_sMetaComm.sSerialNoHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Barcode Check header", (bool*)&g_sMetaComm.sBarcHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"BT Check header", (bool*)&g_sMetaComm.sBTHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Wifi Check header", (bool*)&g_sMetaComm.sWifiHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Ethernet Check header", (bool*)&g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"DRMKey MCID Check header", (bool*)&g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader, INI_BOOLEAN},
    {"Enable Check BTWifi", (bool*)&g_sMetaComm.bCheckBTWifi, INI_BOOLEAN},    
    {"IMEI_1 header string", (char*)g_sMetaComm.sIMEIHeader_Option[0].strHeader, INI_STRING},
    {"IMEI_2 header string", (char*)g_sMetaComm.sIMEIHeader_Option[1].strHeader, INI_STRING},
    {"IMEI_3 header string", (char*)g_sMetaComm.sIMEIHeader_Option[2].strHeader, INI_STRING},
    {"IMEI_4 header string", (char*)g_sMetaComm.sIMEIHeader_Option[3].strHeader, INI_STRING},
    //C2K Modem
    {"Meid header string", (char*)g_sMetaComm.sMeidHeader_Option.strHeader, INI_STRING},
    {"Esn header string", (char*)g_sMetaComm.sEsnHeader_Option.strHeader, INI_STRING},
    {"Serial No. header string", (char*)g_sMetaComm.sSerialNoHeader_Option.strHeader, INI_STRING},
    {"Barcode header string", (char*)g_sMetaComm.sBarcHeader_Option.strHeader, INI_STRING},
    {"BT header string", (char*)g_sMetaComm.sBTHeader_Option.strHeader, INI_STRING},
    {"Wifi header string", (char*)g_sMetaComm.sWifiHeader_Option.strHeader, INI_STRING},
    {"Ethernet header string", (char*)g_sMetaComm.sEthernetMacHeader_Option.strHeader, INI_STRING},
    {"DRMKey MCID header string", (char*)g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader, INI_STRING},
    {"DB from DUT", (bool*)&g_sMetaComm.sDBFileOption.bDBFromDUT, INI_BOOLEAN},
    {"Modem_1 database path", (char*)g_sMetaComm.sDBFileOption.strMD1Dbpath, INI_STRING},
    {"Modem_2 database path", (char*)g_sMetaComm.sDBFileOption.strMD2Dbpath, INI_STRING},
    {"AP database path", (char*)g_sMetaComm.sDBFileOption.strAPDbpath, INI_STRING},   
    {"FP Auth path", (char*)g_sMetaComm.sLoadFile.strFPAuthPath, INI_STRING},
    {"SP Auth path", (char*)g_sMetaComm.sLoadFile.strSPAuthPath, INI_STRING},
    {"Hdcp Bin path", (char*)g_sMetaComm.sLoadFile.strHdcpBinPath, INI_STRING},
    {"DrmKey path", (char*)g_sMetaComm.sLoadFile.strDrmKeyPath, INI_STRING},
    {"Hdcp data path", (char*)g_sMetaComm.sLoadFile.strHdcpDataPath, INI_STRING},
    {"Hdcp cek path", (char*)g_sMetaComm.sLoadFile.strHdcpCekPath, INI_STRING}, 
    //{"Trigger extern modem download", (bool*)&g_sMetaComm.sBarcodeOption.bExtMdDl, INI_BOOLEAN},

    {"Enable Write Temperature", (bool*)&g_sMetaComm.sIMEIOption.Temp_Option.bWriteTemperature,INI_BOOLEAN},
    {"The Current Temperature", (char*)&g_sMetaComm.sIMEIOption.Temp_Option.strTemperatureData,INI_STRING},

    {"Log Dir", (char*)g_sMetaComm.strLogDir, INI_STRING},
    {"ModemLog", (bool *)&g_sMetaComm.bMDLog, INI_BOOLEAN},

    //for C2K
    {"Enable Serial No", (bool*)&g_sMetaComm.EnableSerialNo, INI_BOOLEAN},
    {"Ignore Database Inconsistent", (bool*)&g_sMetaComm.IgnoreDBInconsistent, INI_BOOLEAN},
    {"Serial Num From IMEI", (bool*)&g_sMetaComm.SerialNumFromIMEI, INI_BOOLEAN},
    {"IMEI Lock Hidden", (bool*)&g_sMetaComm.ImeiLockHidden, INI_BOOLEAN},
};

bool ResultToString_Win(DWORD ED, char* lpBuffer, DWORD nSize)
{
    DWORD ret_dw = 0u;
    DWORD i_dw = 0u, j_dw = 0u;

    if (lpBuffer == NULL || nSize < 64u)
        return false;

    ret_dw = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        ED,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        lpBuffer,
        nSize,
        NULL);
    if (ret_dw == 0u)
        return false;

    // remove '\r' '\n'
    j_dw = 0u;
    for (i_dw = 0u; i_dw < ret_dw && lpBuffer[i_dw] != '\0'; i_dw++)
    {
        if (lpBuffer[i_dw] != '\r' && lpBuffer[i_dw] != '\n')
        {
            if (j_dw == i_dw)
                j_dw++;
            else
                lpBuffer[j_dw++] = lpBuffer[i_dw];
        }
    }
    lpBuffer[j_dw] = '\0';

    return true;
}

char* ResultToString_SP(int MR)
{
    switch((META_RESULT)MR)
    { 
    case SPMETA_DLL::META_SUCCESS:
        return M2S(SPMETA_DLL::META_SUCCESS);

    case SPMETA_DLL::META_FAILED:
        return M2S(SPMETA_DLL::META_FAILED);

    case SPMETA_DLL::META_COMM_FAIL:
        return M2S(SPMETA_DLL::META_COMM_FAIL);

    case SPMETA_DLL::META_NORESPONSE:
        return M2S(SPMETA_DLL::META_NORESPONSE);

    case SPMETA_DLL::META_BUFFER_LEN:
        return M2S(SPMETA_DLL::META_BUFFER_LEN);

    case SPMETA_DLL::META_FILE_BAD:
        return M2S(SPMETA_DLL::META_FILE_BAD);

    case SPMETA_DLL::META_LID_INVALID:
        return M2S(SPMETA_DLL::META_LID_INVALID);

    case SPMETA_DLL::META_INTERNAL_DB_ERR:
        return M2S(SPMETA_DLL::META_INTERNAL_DB_ERR);

    case SPMETA_DLL::META_NO_MEMORY:
        return M2S(SPMETA_DLL::META_NO_MEMORY);

    case SPMETA_DLL::META_INVALID_ARGUMENTS:
        return M2S(SPMETA_DLL::META_INVALID_ARGUMENTS);

    case SPMETA_DLL::META_TIMEOUT:
        return M2S(SPMETA_DLL::META_TIMEOUT);

    case SPMETA_DLL::META_BUSY:
        return M2S(SPMETA_DLL::META_BUSY);

    case SPMETA_DLL::META_INVALID_HANDLE:
        return M2S(SPMETA_DLL::META_INVALID_HANDLE);

    case SPMETA_DLL::META_FAT_ERROR:
        return M2S(SPMETA_DLL::META_FAT_ERROR);

    case SPMETA_DLL::META_FAT_DISK_FULL:
        return M2S(SPMETA_DLL::META_FAT_DISK_FULL);

    case SPMETA_DLL::META_FAT_ROOT_DIR_FULL:
        return M2S(SPMETA_DLL::META_FAT_ROOT_DIR_FULL);

    case SPMETA_DLL::META_FAT_INVALID_FILENAME:
        return M2S(SPMETA_DLL::META_FAT_INVALID_FILENAME);

    case SPMETA_DLL::META_FAT_INVALID_FILE_HANDLE:
        return M2S(SPMETA_DLL::META_FAT_INVALID_FILE_HANDLE);

    case SPMETA_DLL::META_FAT_FILE_NOT_FOUND:
        return M2S(SPMETA_DLL::META_FAT_FILE_NOT_FOUND);

    case SPMETA_DLL::META_FAT_DRIVE_NOT_FOUND:
        return M2S(SPMETA_DLL::META_FAT_DRIVE_NOT_FOUND);

    case SPMETA_DLL::META_FAT_PATH_NOT_FOUND:
        return M2S(SPMETA_DLL::META_FAT_PATH_NOT_FOUND);

    case SPMETA_DLL::META_FAT_ACCESS_DENIED:
        return M2S(SPMETA_DLL::META_FAT_ACCESS_DENIED);

    case SPMETA_DLL::META_FAT_TOO_MANY_FILES:
        return M2S(SPMETA_DLL::META_FAT_TOO_MANY_FILES);

    case SPMETA_DLL::META_INCORRECT_TARGET_VER:
        return M2S(SPMETA_DLL::META_INCORRECT_TARGET_VER);

    case SPMETA_DLL::META_COM_ERROR:
        return M2S(SPMETA_DLL::META_COM_ERROR);

    case SPMETA_DLL::META_BROM_CMD_ERROR:
        return M2S(SPMETA_DLL::META_BROM_CMD_ERROR);

    case SPMETA_DLL::META_INCORRECT_BBCHIP_TYPE:
        return M2S(SPMETA_DLL::META_INCORRECT_BBCHIP_TYPE);

    case SPMETA_DLL::META_BROM_ERROR:
        return M2S(SPMETA_DLL::META_BROM_ERROR);

    case SPMETA_DLL::META_STOP_BOOTUP_PROCEDURE:
        return M2S(SPMETA_DLL::META_STOP_BOOTUP_PROCEDURE);

    case SPMETA_DLL::META_CANCEL:
        return M2S(SPMETA_DLL::META_CANCEL);

    case SPMETA_DLL::META_CCT_NOT_IMPORT_PROFILE:
        return M2S(SPMETA_DLL::META_CCT_NOT_IMPORT_PROFILE);

    case SPMETA_DLL::META_CCT_INVALID_SENSOR_ID:
        return M2S(SPMETA_DLL::META_CCT_INVALID_SENSOR_ID);

    case SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_SINGLE_SHOT:
        return M2S(SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_SINGLE_SHOT);

    case SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_MULTI_SHOT:
        return M2S(SPMETA_DLL::META_CCT_TGT_NO_MEM_FOR_MULTI_SHOT);

    case SPMETA_DLL::META_FUNC_NOT_IMPLEMENT_YET:
        return M2S(SPMETA_DLL::META_FUNC_NOT_IMPLEMENT_YET);

    //case SPMETA_DLL::META_CCT_NOT_IMPLEMENT_YET:
    //    return M2S(SPMETA_DLL::META_CCT_NOT_IMPLEMENT_YET);

    case SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STARTED:
        return M2S(SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STARTED);

    case SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STOPPED:
        return M2S(SPMETA_DLL::META_CCT_PREVIEW_ALREADY_STOPPED);

    case SPMETA_DLL::META_CCT_READ_REG_NO_CNF:
        return M2S(SPMETA_DLL::META_CCT_READ_REG_NO_CNF);

    case SPMETA_DLL::META_CCT_WRITE_REG_NO_CNF:
        return M2S(SPMETA_DLL::META_CCT_WRITE_REG_NO_CNF);

    case SPMETA_DLL::META_CCT_TGT_ABORT_IMAGE_SENDING:
        return M2S(SPMETA_DLL::META_CCT_TGT_ABORT_IMAGE_SENDING);

    case SPMETA_DLL::META_CCT_READ_ONLY_REGISTER:
        return M2S(SPMETA_DLL::META_CCT_READ_ONLY_REGISTER);

    case SPMETA_DLL::META_CCT_LOAD_FROM_NVRAM_FAIL:
        return M2S(SPMETA_DLL::META_CCT_LOAD_FROM_NVRAM_FAIL);

    case SPMETA_DLL::META_CCT_SAVE_TO_NVRAM_FAIL:
        return M2S(SPMETA_DLL::META_CCT_SAVE_TO_NVRAM_FAIL);

    case SPMETA_DLL::META_CCT_AE_INVALID_EC_LEVEL:
        return M2S(SPMETA_DLL::META_CCT_AE_INVALID_EC_LEVEL);

    case SPMETA_DLL::META_CCT_AE_INVALID_EC_STEP:
        return M2S(SPMETA_DLL::META_CCT_AE_INVALID_EC_STEP);

    case SPMETA_DLL::META_CCT_AE_ALREADY_ENABLED:
        return M2S(SPMETA_DLL::META_CCT_AE_ALREADY_ENABLED);

    case SPMETA_DLL::META_CCT_AE_ALREADY_DISABLED:
        return M2S(SPMETA_DLL::META_CCT_AE_ALREADY_DISABLED);

    case SPMETA_DLL::META_CCT_WB_INVALID_INDEX:
        return M2S(SPMETA_DLL::META_CCT_WB_INVALID_INDEX);

    case SPMETA_DLL::META_CCT_NO_TGT_SENSOR_MATCH_IN_PROFILE:
        return M2S(SPMETA_DLL::META_CCT_NO_TGT_SENSOR_MATCH_IN_PROFILE);

    case SPMETA_DLL::META_CCT_IMAGE_SENDING_FAME_NUM_ERROR:
        return M2S(SPMETA_DLL::META_CCT_IMAGE_SENDING_FAME_NUM_ERROR);

    case SPMETA_DLL::META_CCT_AE_IS_NOT_DISABLED:
        return M2S(SPMETA_DLL::META_CCT_AE_IS_NOT_DISABLED);

    case SPMETA_DLL::META_FAT_APP_QUOTA_FULL:
        return M2S(SPMETA_DLL::META_FAT_APP_QUOTA_FULL);

    case SPMETA_DLL::META_IMEI_CD_ERROR:
        return M2S(SPMETA_DLL::META_IMEI_CD_ERROR);

    case SPMETA_DLL::META_RFID_MISMATCH:
        return M2S(SPMETA_DLL::META_RFID_MISMATCH);

    case SPMETA_DLL::META_NVRAM_DB_IS_NOT_LOADED_YET:
        return M2S(SPMETA_DLL::META_NVRAM_DB_IS_NOT_LOADED_YET);

    case SPMETA_DLL::META_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL:
        return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_WIDTH_HEIGHT_TOO_SMALL);

    case SPMETA_DLL::META_WAIT_FOR_TARGET_READY_TIMEOUT:
        return M2S(SPMETA_DLL::META_WAIT_FOR_TARGET_READY_TIMEOUT);

    case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE:
        return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_SET_INVALID_VALUE);

    case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST:
        return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_GROUP_NOT_EXIST);

    case SPMETA_DLL::META_CCT_NO_TGT_ISP_MATCH_IN_PROFILE:
        return M2S(SPMETA_DLL::META_CCT_NO_TGT_ISP_MATCH_IN_PROFILE);

    case SPMETA_DLL::META_CCT_TGT_ISP_SUPPORT_NOT_DEFINED:
        return M2S(SPMETA_DLL::META_CCT_TGT_ISP_SUPPORT_NOT_DEFINED);

    case SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST:
        return M2S(SPMETA_DLL::META_CCT_ERR_SENSOR_ENG_ITEM_NOT_EXIST);

    case SPMETA_DLL::META_CCT_ERR_INVALID_COMPENSATION_MODE:
        return M2S(SPMETA_DLL::META_CCT_ERR_INVALID_COMPENSATION_MODE);

    case SPMETA_DLL::META_CCT_ERR_USB_COM_NOT_READY:
        return M2S(SPMETA_DLL::META_CCT_ERR_USB_COM_NOT_READY);

    case SPMETA_DLL::META_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING:
        return M2S(SPMETA_DLL::META_CCT_DEFECTPIXEL_CAL_UNDER_PROCESSING);

    case SPMETA_DLL::META_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM:
        return M2S(SPMETA_DLL::META_CCT_ERR_DEFECTPIXEL_CAL_NO_MEM);

    case SPMETA_DLL::META_CCT_ERR_TOO_MANY_DEFECT_PIXEL:
        return M2S(SPMETA_DLL::META_CCT_ERR_TOO_MANY_DEFECT_PIXEL);

    case SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_FAIL:
        return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_FAIL);

    case SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_TIMEOUT:
        return M2S(SPMETA_DLL::META_CCT_ERR_CAPTURE_JPEG_TIMEOUT);

    case SPMETA_DLL::META_CCT_ERR_AF_FAIL:
        return M2S(SPMETA_DLL::META_CCT_ERR_AF_FAIL);

    case SPMETA_DLL::META_CCT_ERR_AF_TIMEOUT:
        return M2S(SPMETA_DLL::META_CCT_ERR_AF_TIMEOUT);

    case SPMETA_DLL::META_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL:
        return M2S(SPMETA_DLL::META_CCT_ERR_AF_LENS_OFFSET_CAL_FAIL);

    case SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_ENABLE:
        return M2S(SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_ENABLE);

    case SPMETA_DLL::META_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT:
        return M2S(SPMETA_DLL::META_CCT_ERR_UNSUPPORT_CAPTURE_FORMAT);

    case SPMETA_DLL::META_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL:
        return M2S(SPMETA_DLL::META_CCT_ERR_EXCEED_MAX_DEFECT_PIXEL);

    case SPMETA_DLL::META_ERR_EXCEED_MAX_PEER_BUF_SIZE:
        return M2S(SPMETA_DLL::META_ERR_EXCEED_MAX_PEER_BUF_SIZE);

    case SPMETA_DLL::META_CCT_ERR_INVALID_WIDTH_FACTOR:
        return M2S(SPMETA_DLL::META_CCT_ERR_INVALID_WIDTH_FACTOR);

    case SPMETA_DLL::META_BROM_SECURITY_CHECK_FAIL:
        return M2S(SPMETA_DLL::META_BROM_SECURITY_CHECK_FAIL);

    case SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_DISABLE:
        return M2S(SPMETA_DLL::META_CCT_ERR_PREVIEW_MUST_DISABLE);

    case SPMETA_DLL::META_MAUI_DB_INCONSISTENT:
        return M2S(SPMETA_DLL::META_MAUI_DB_INCONSISTENT);

    case SPMETA_DLL::META_FAT_FILEPATH_TOO_LONG:
        return M2S(SPMETA_DLL::META_FAT_FILEPATH_TOO_LONG);

    case SPMETA_DLL::META_FAT_RESTRICTED_FILEPATH:
        return M2S(SPMETA_DLL::META_FAT_RESTRICTED_FILEPATH);

    case SPMETA_DLL::META_FAT_DIR_NOT_EXIST:
        return M2S(SPMETA_DLL::META_FAT_DIR_NOT_EXIST);

    case SPMETA_DLL::META_FAT_DISK_SPACE_IS_NOT_ENOUGH:
        return M2S(SPMETA_DLL::META_FAT_DISK_SPACE_IS_NOT_ENOUGH);

    case SPMETA_DLL::META_TDMB_ERR_BAND_NOT_EXIST:
        return M2S(SPMETA_DLL::META_TDMB_ERR_BAND_NOT_EXIST);

    case SPMETA_DLL::META_TDMB_ERR_FREQ_NOT_EXIST:
        return M2S(SPMETA_DLL::META_TDMB_ERR_FREQ_NOT_EXIST);

    case SPMETA_DLL::META_TDMB_ERR_ENSM_NOT_EXIST:
        return M2S(SPMETA_DLL::META_TDMB_ERR_ENSM_NOT_EXIST);

    case SPMETA_DLL::META_TDMB_ERR_SERV_NOT_EXIST:
        return M2S(SPMETA_DLL::META_TDMB_ERR_SERV_NOT_EXIST);

    case SPMETA_DLL::META_TDMB_ERR_SUB_CHAN_NOT_EXIST:
        return M2S(SPMETA_DLL::META_TDMB_ERR_SUB_CHAN_NOT_EXIST);

    case SPMETA_DLL::META_TDMB_ERR_DEMOD_STATE:
        return M2S(SPMETA_DLL::META_TDMB_ERR_DEMOD_STATE);

    case SPMETA_DLL::META_PERMISSION_DENIED:
        return M2S(SPMETA_DLL::META_PERMISSION_DENIED);

    case SPMETA_DLL::META_ENUMERATE_USB_FAIL:
        return M2S(SPMETA_DLL::META_ENUMERATE_USB_FAIL);

    case SPMETA_DLL::META_STOP_ENUM_USB_PROCEDURE:
        return M2S(SPMETA_DLL::META_STOP_ENUM_USB_PROCEDURE);

    case SPMETA_DLL::META_CCT_6238_AE_ALREADY_ENABLED:
        return M2S(SPMETA_DLL::META_CCT_6238_AE_ALREADY_ENABLED);

    case SPMETA_DLL::META_CCT_6238_AE_ALREADY_DISABLED:
        return M2S(SPMETA_DLL::META_CCT_6238_AE_ALREADY_DISABLED);

    case SPMETA_DLL::META_CCT_6238_AE_IS_NOT_DISABLED:
        return M2S(SPMETA_DLL::META_CCT_6238_AE_IS_NOT_DISABLED);

    case SPMETA_DLL::META_CCT_6238_ISP_FLASHLIGHT_LINEARITY_PRESTROBE_FAIL:
        return M2S(SPMETA_DLL::META_CCT_6238_ISP_FLASHLIGHT_LINEARITY_PRESTROBE_FAIL);

    case SPMETA_DLL::META_NOT_SUPPORT:
        return M2S(SPMETA_DLL::META_NOT_SUPPORT);

    case SPMETA_DLL::META_LAST_RESULT:
        return M2S(SPMETA_DLL::META_LAST_RESULT);
    default:
        return M2S(DEFAULT_FAIL);
    }
}

char* ResultToString(int MR)
{
    switch((META_RESULT)MR)
    {

    case META_SUCCESS:
        return M2S(META_SUCCESS);

    case META_FAILED:
        return M2S(META_FAILED);

    case META_COMM_FAIL:
        return M2S(META_COMM_FAIL);

    case META_NORESPONSE:
        return M2S(META_NORESPONSE);

    case META_EBOOT_FAILED:
        return M2S(META_EBOOT_FAILED);

    case META_BUFFER_LEN:
        return M2S(META_BUFFER_LEN);

    case META_FILE_BAD:
        return M2S(META_FILE_BAD);

    case META_LID_INVALID:
        return M2S(META_LID_INVALID);

    case META_INTERNAL_DB_ERR:
        return M2S(META_INTERNAL_DB_ERR);

    case META_NO_MEMORY:
        return M2S(META_NO_MEMORY);

    case META_INVALID_ARGUMENTS:
        return M2S(META_INVALID_ARGUMENTS);

    case META_TIMEOUT:
        return M2S(META_TIMEOUT);

    case META_BUSY:
        return M2S(META_BUSY);

    case META_INVALID_HANDLE:
        return M2S(META_INVALID_HANDLE);

    case META_FAT_ERROR:
        return M2S(META_FAT_ERROR);

    case META_FAT_DISK_FULL:
        return M2S(META_FAT_DISK_FULL);

    case META_FAT_ROOT_DIR_FULL:
        return M2S(META_FAT_ROOT_DIR_FULL);

    case META_FAT_INVALID_FILENAME:
        return M2S(META_FAT_INVALID_FILENAME);

    case META_FAT_INVALID_FILE_HANDLE:
        return M2S(META_FAT_INVALID_FILE_HANDLE);

    case META_FAT_FILE_NOT_FOUND:
        return M2S(META_FAT_FILE_NOT_FOUND);

    case META_FAT_DRIVE_NOT_FOUND:
        return M2S(META_FAT_DRIVE_NOT_FOUND);

    case META_FAT_PATH_NOT_FOUND:
        return M2S(META_FAT_PATH_NOT_FOUND);

    case META_FAT_ACCESS_DENIED:
        return M2S(META_FAT_ACCESS_DENIED);

    case META_FAT_TOO_MANY_FILES:
        return M2S(META_FAT_TOO_MANY_FILES);

    case META_INCORRECT_TARGET_VER:
        return M2S(META_INCORRECT_TARGET_VER);

    case META_COM_ERROR:
        return M2S(META_COM_ERROR);

    case META_BROM_CMD_ERROR:
        return M2S(META_BROM_CMD_ERROR);

    case META_INCORRECT_BBCHIP_TYPE:
        return M2S(META_INCORRECT_BBCHIP_TYPE);

    case META_BROM_ERROR:
        return M2S(META_BROM_ERROR);

    case META_STOP_BOOTUP_PROCEDURE:
        return M2S(META_STOP_BOOTUP_PROCEDURE);

    case META_CANCEL:
        return M2S(META_CANCEL);

    case META_FUNC_NOT_IMPLEMENT_YET:
        return M2S(META_FUNC_NOT_IMPLEMENT_YET);

    case META_FAT_APP_QUOTA_FULL:
        return M2S(META_FAT_APP_QUOTA_FULL);

    case META_IMEI_CD_ERROR:
        return M2S(META_IMEI_CD_ERROR);

    case META_RFID_MISMATCH:
        return M2S(META_RFID_MISMATCH);

    case META_NVRAM_DB_IS_NOT_LOADED_YET:
        return M2S(META_NVRAM_DB_IS_NOT_LOADED_YET);

    case META_WAIT_FOR_TARGET_READY_TIMEOUT:
        return M2S(META_WAIT_FOR_TARGET_READY_TIMEOUT);

    case META_ERR_EXCEED_MAX_PEER_BUF_SIZE:
        return M2S(META_ERR_EXCEED_MAX_PEER_BUF_SIZE);

    case META_BROM_SECURITY_CHECK_FAIL:
        return M2S(META_BROM_SECURITY_CHECK_FAIL);

    case META_MAUI_DB_INCONSISTENT:
        return M2S(META_MAUI_DB_INCONSISTENT);

    case META_FAT_FILEPATH_TOO_LONG:
        return M2S(META_FAT_FILEPATH_TOO_LONG);

    case META_FAT_RESTRICTED_FILEPATH:
        return M2S(META_FAT_RESTRICTED_FILEPATH);

    case META_FAT_DIR_NOT_EXIST:
        return M2S(META_FAT_DIR_NOT_EXIST);

    case META_FAT_DISK_SPACE_IS_NOT_ENOUGH:
        return M2S(META_FAT_DISK_SPACE_IS_NOT_ENOUGH);

    case META_TDMB_ERR_BAND_NOT_EXIST:
        return M2S(META_TDMB_ERR_BAND_NOT_EXIST);

    case META_TDMB_ERR_FREQ_NOT_EXIST:
        return M2S(META_TDMB_ERR_FREQ_NOT_EXIST);

    case META_TDMB_ERR_ENSM_NOT_EXIST:
        return M2S(META_TDMB_ERR_ENSM_NOT_EXIST);

    case META_TDMB_ERR_SERV_NOT_EXIST:
        return M2S(META_TDMB_ERR_SERV_NOT_EXIST);

    case META_TDMB_ERR_SUB_CHAN_NOT_EXIST:
        return M2S(META_TDMB_ERR_SUB_CHAN_NOT_EXIST);

    case META_TDMB_ERR_DEMOD_STATE:
        return M2S(META_TDMB_ERR_DEMOD_STATE);

    case META_ENUMERATE_USB_FAIL:
        return M2S(META_ENUMERATE_USB_FAIL);

    case META_STOP_ENUM_USB_PROCEDURE:
        return M2S(META_STOP_ENUM_USB_PROCEDURE);

    case META_MISC_TARGET_LOAD_NEED_TO_BE_PATCHED:
        return M2S(META_MISC_TARGET_LOAD_NEED_TO_BE_PATCHED);

    case META_MISC_INI_FILE_SETTINGS_WRONG:
        return M2S(META_MISC_INI_FILE_SETTINGS_WRONG);

    case META_MISC_FAIL_TO_READ_IMEI:
        return M2S(META_MISC_FAIL_TO_READ_IMEI);

    case META_MISC_FAIL_TO_BACKUP_FILE:
        return M2S(META_MISC_FAIL_TO_BACKUP_FILE);

    case META_MISC_FAIL_TO_WRITE_BACKUP_RESULT:
        return M2S(META_MISC_FAIL_TO_WRITE_BACKUP_RESULT);

    case META_MISC_FAIL_TO_GET_NVRAM_FOLDER_PATH:
        return M2S(META_MISC_FAIL_TO_GET_NVRAM_FOLDER_PATH);

    case META_MISC_FAIL_TO_GET_NVRAM_MUST_LIST:
        return M2S(META_MISC_FAIL_TO_GET_NVRAM_MUST_LIST);

    case META_STOP_CURRENT_PROCEDURE:
        return M2S(META_STOP_CURRENT_PROCEDURE);

    case META_MISC_CUSTOMIZED_NVRAM_ERROR:
        return M2S(META_MISC_CUSTOMIZED_NVRAM_ERROR);

    case META_MISC_FOLDER_EMPTY_CHECKING_FAIL:
        return M2S(META_MISC_FOLDER_EMPTY_CHECKING_FAIL);

    case META_MISC_TOO_MANY_BACKUP_RESULT_FILE:
        return M2S(META_MISC_TOO_MANY_BACKUP_RESULT_FILE);

    case META_MISC_TOO_MANY_RESTORE_RESULT_FILE:
        return M2S(META_MISC_TOO_MANY_RESTORE_RESULT_FILE);

    case META_MISC_RESTORE_RESULT_FILE_NOT_EXIST:
        return M2S(META_MISC_RESTORE_RESULT_FILE_NOT_EXIST);

    case META_MISC_RESTORE_RESULT_FILE_INCOMPLETE:
        return M2S(META_MISC_RESTORE_RESULT_FILE_INCOMPLETE);

    case META_FAIL_TO_CELAR_ALL_IN_BACUP_FOLDER:
        return M2S(META_FAIL_TO_CELAR_ALL_IN_BACUP_FOLDER);

    case META_MISC_BACKUP_RESULT_FILE_NOT_EXIST:
        return M2S(META_MISC_BACKUP_RESULT_FILE_NOT_EXIST);

    case META_MISC_BACKUP_RESULT_FILE_INCOMPLETE:
        return M2S(META_MISC_BACKUP_RESULT_FILE_INCOMPLETE);

    case META_MISC_IMEI_MISMATCH:
        return M2S(META_MISC_IMEI_MISMATCH);

    case META_MISC_SML_FILE_VERIFY_FAIL:
        return M2S(META_MISC_SML_FILE_VERIFY_FAIL);

    case META_MISC_BACKUP_RESULT_NOT_ENOUGH_FOR_NEW_LOAD:
        return M2S(META_MISC_BACKUP_RESULT_NOT_ENOUGH_FOR_NEW_LOAD);

    case META_MISC_FAIL_TO_RESTORE_FILE:
        return M2S(META_MISC_FAIL_TO_RESTORE_FILE);

    case META_MISC_FAIL_TO_WRITE_RESTORE_RESULT:
        return M2S(META_MISC_FAIL_TO_WRITE_RESTORE_RESULT);

    case META_MISC_USE_WRONG_API_FOR_NEW_LOAD:
        return M2S(META_MISC_USE_WRONG_API_FOR_NEW_LOAD);

    case META_MISC_QUERY_TARGET_CAPABILITY_FAIL:
        return M2S(META_MISC_QUERY_TARGET_CAPABILITY_FAIL);

    case META_MISC_INI_SETTINGS_ERR_IN_NVRAM_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_NVRAM_SEC);

    case META_MISC_INI_SETTINGS_ERR_IN_TARGET_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_TARGET_SEC);

    case META_MISC_INI_SETTINGS_ERR_IN_PC_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_PC_SEC);

    case META_MISC_NO_FILES_NEED_TO_BE_UPLOAD:
        return M2S(META_MISC_NO_FILES_NEED_TO_BE_UPLOAD);

    case META_FAT_ACTION_NOT_SUPPORT:
        return M2S(META_FAT_ACTION_NOT_SUPPORT);

    case META_MISC_EMPTY_UPLOADFILES_AND_IMEI_SEC:
        return M2S(META_MISC_EMPTY_UPLOADFILES_AND_IMEI_SEC);

    case META_MISC_INI_SETTINGS_ERR_IN_MORE_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_MORE_SEC);

    case META_MISC_INI_SETTINGS_ERR_IN_DELETE_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_DELETE_SEC);

    case META_MISC_CHECK_TARGET_NVRAM_FILES_FAIL:
        return M2S(META_MISC_CHECK_TARGET_NVRAM_FILES_FAIL);

    case META_MISC_FAIL_TO_GET_NVRAM_FOLDER_AMOUNT:
        return M2S(META_MISC_FAIL_TO_GET_NVRAM_FOLDER_AMOUNT);

    case META_AUDIO_CHECK_WAVE_FILE_FAIL:
        return M2S(META_AUDIO_CHECK_WAVE_FILE_FAIL);

    case META_MISC_COLLECT_NVRAM_FOLDER_FILES_FAILED:
        return M2S(META_MISC_COLLECT_NVRAM_FOLDER_FILES_FAILED);

    case META_MISC_COLLECT_NVRAM_FOLDER_FILES_FIRST:
        return M2S(META_MISC_COLLECT_NVRAM_FOLDER_FILES_FIRST);

    case META_MISC_BACKUP_FILE_NOT_FOUND_IN_NVRAM:
        return M2S(META_MISC_BACKUP_FILE_NOT_FOUND_IN_NVRAM);

    case META_MISC_BACKUP_MORE_FILE_NOT_FOUND_IN_NVRAM:
        return M2S(META_MISC_BACKUP_MORE_FILE_NOT_FOUND_IN_NVRAM);

    case META_MISC_LOCAL_FS_UNKNOWN_ERROR:
        return M2S(META_MISC_LOCAL_FS_UNKNOWN_ERROR);

    case META_MISC_RETORE_FILE_NOT_FOUND_IN_BACKUP_RESULT:
        return M2S(META_MISC_RETORE_FILE_NOT_FOUND_IN_BACKUP_RESULT);

    case META_MISC_LEGACY_ADC_FILE_NOT_FOUND:
        return M2S(META_MISC_LEGACY_ADC_FILE_NOT_FOUND);

    case META_MISC_LEGACY_BARCODE_FILE_NOT_FOUND:
        return M2S(META_MISC_LEGACY_BARCODE_FILE_NOT_FOUND);

    case META_MISC_FILE_SIZE_MISMATCH:
        return M2S(META_MISC_FILE_SIZE_MISMATCH);

    case META_MISC_RESTORE_TARGET_NOT_FOUND_IN_NVRAM:
        return M2S(META_MISC_RESTORE_TARGET_NOT_FOUND_IN_NVRAM);

    case META_UTIL_CONVERT_MULTIBYTE_TO_WCHAR_FAILED:
        return M2S(META_UTIL_CONVERT_MULTIBYTE_TO_WCHAR_FAILED);

    case META_FAT_RECURSIVE_CREATE_FOLDER_FAILED:
        return M2S(META_FAT_RECURSIVE_CREATE_FOLDER_FAILED);

    case META_FAT_COPY_INVALID_SOURCE_FOLDER:
        return M2S(META_FAT_COPY_INVALID_SOURCE_FOLDER);

    case META_FAT_COPY_EMPTY_SOURCE_FOLDER:
        return M2S(META_FAT_COPY_EMPTY_SOURCE_FOLDER);

    case META_MISC_MULTIPLE_ENTRY_NOT_SUPPORTED:
        return M2S(META_MISC_MULTIPLE_ENTRY_NOT_SUPPORTED);

    case META_MISC_INVALID_FORMAT:
        return M2S(META_MISC_INVALID_FORMAT);

    case META_FAT_FILE_LENGTH_ZERO:
        return M2S(META_FAT_FILE_LENGTH_ZERO);

    case META_MISC_INI_SETTINGS_ERR_IN_PC_FOLDER_SEC:
        return M2S(META_MISC_INI_SETTINGS_ERR_IN_PC_FOLDER_SEC);

    case META_PC_FILE_NOT_FOUND:
        return M2S(META_PC_FILE_NOT_FOUND);

    case META_MEMBER_FIELD_TYPE_NOT_FOUND:
        return M2S(META_MEMBER_FIELD_TYPE_NOT_FOUND);

    case META_MEMBER_FIELD_OFFSET_NOT_FOUND:
        return M2S(META_MEMBER_FIELD_OFFSET_NOT_FOUND);

    case META_NVRAM_GET_KEY_LENGTH_CALLBACK_ERROR:
        return M2S(META_NVRAM_GET_KEY_LENGTH_CALLBACK_ERROR);

    case META_NVRAM_ALLOCATE_KEY_BUFFER_ERROR:
        return M2S(META_NVRAM_ALLOCATE_KEY_BUFFER_ERROR);

    case META_NVRAM_GET_KEY_BUFFER_CALLBACK_ERROR:
        return M2S(META_NVRAM_GET_KEY_BUFFER_CALLBACK_ERROR);

    case META_NVRAM_KEY_ENTRY_MISSING:
        return M2S(META_NVRAM_KEY_ENTRY_MISSING);

    case META_NVRAM_KEY_ENTRY_ERROR:
        return M2S(META_NVRAM_KEY_ENTRY_ERROR);

    case META_NVRAM_KEY_LENGTH_EXCEEDS_INTERNAL_BUFFER:
        return M2S(META_NVRAM_KEY_LENGTH_EXCEEDS_INTERNAL_BUFFER);

    case META_FAT_SPACE_SIZE_OVERFLOW:
        return M2S(META_FAT_SPACE_SIZE_OVERFLOW);

    case META_LIB_INCONSISTENT:
        return M2S(META_LIB_INCONSISTENT);

    case META_INTERNAL_DB_ERROR:
        return M2S(META_INTERNAL_DB_ERROR);

    case META_REQUIRED_TOOL_VERSION_CHECK_FAILD:
        return M2S(META_REQUIRED_TOOL_VERSION_CHECK_FAILD);

    case META_CROSS_BRANCH_BACKUP_OPEN_FAILED:
        return M2S(META_CROSS_BRANCH_BACKUP_OPEN_FAILED);

    case META_CROSS_BRANCH_BACKUP_PARSE_FAILED:
        return M2S(META_CROSS_BRANCH_BACKUP_PARSE_FAILED);

    case META_CROSS_BRANCH_BACKUP_FILE_ATT_NOT_MATCH:
        return M2S(META_CROSS_BRANCH_BACKUP_FILE_ATT_NOT_MATCH);

    case META_NVRAM_VALUE_NOT_LEGAL:
        return M2S(META_NVRAM_VALUE_NOT_LEGAL);

    case META_INIT_CONNECTION_STARTED:
        return M2S(META_INIT_CONNECTION_STARTED);

    case META_QUERY_NO_MODEM_SUPPORT:
        return M2S(META_QUERY_NO_MODEM_SUPPORT);

    case META_MEMBER_FIELD_SIZE_NOT_FOUND:
        return M2S(META_MEMBER_FIELD_SIZE_NOT_FOUND);

    case META_LAST_RESULT:
        return M2S(META_LAST_RESULT);

    default:
        return M2S(DEFAULT_FAIL);
    }
}

int InitSNIni()
{
    int initStatus = 0;

    InitGlobalValue();

    RW_SetupFile_Status status = INI_RW_SUCCESS;
    status = GetParaFromSetupFile();
    if (status == INI_RW_SUCCESS)
    {
        initStatus = 1;
    }
    else
    {
        initStatus = 0;
    }

    AuthHandle_Init();

    return initStatus;

}

bool AuthHandle_Init()
{
    bool bAuthHandleInitDone = true;

    if(REQ_AUTH_Create() == -1)
    {
        bAuthHandleInitDone = false;
    }

    if(SPATE_AUTH_Create() == false)
    {
        bAuthHandleInitDone = false;
    }

    if (SPATE_SCERT_Create() == false)
    {
        bAuthHandleInitDone = false;
    }

    return bAuthHandleInitDone;
}

void AuthHandle_DeInit()
{
    REQ_AUTH_Unload ();
    REQ_AUTH_Destroy ();
    SPATE_SCERT_Destroy();
}

bool AuthInit(const char *strAuthFilePath)
{
    if (!strAuthFilePath || strlen(strAuthFilePath) == 0)
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Invalid auth file path!!");
        return false;
    }

    if(REQ_AUTH_Load(strAuthFilePath) == -1)
        return false;
    else
        return true;
}

bool SPAuthInit(const char *strSPAuthFilePath)
{
    if (!strSPAuthFilePath || strlen(strSPAuthFilePath) == 0)
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Invalid SP auth file path!!");
        return false;
    }

    return SPATE_AUTH_Load(strSPAuthFilePath);

}

bool SPScertInit(const char *strSPScertFilePath)
{
    if (!strSPScertFilePath || strlen(strSPScertFilePath) == 0)
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Invalid SP Scert file path!!");
        return false;
    }

    return SPATE_SCERT_Load(strSPScertFilePath);
}

E_TARGET_TYPE GetTargetType()
{
    return g_sMetaComm.eTargetType;
}

bool CheckFileSize( const char *strFilePath, const long fileSize )
{
    long size = 0;

    FILE *pFile = fopen(strFilePath, "rb");   
    if (NULL == pFile )
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Execution Failure: Open data file error!!");
        return false;
    }

    size = GetFilesize(pFile);
    if (size != fileSize)
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Execution Failure: data file size error!!");
        return false;
    }

    return true;
}

long GetFilesize( FILE *fp )
{
    long int save_pos = 0;
    long size_of_file = 0;

    if(fp == NULL)
    {
        return 0;
    }


    /* Save the current position. */
    save_pos = ftell( fp );

    /* Jump to the end of the file. */
    fseek( fp, 0L, SEEK_END );

    /* Get the end position. */
    size_of_file = ftell( fp );

    /* Jump back to the original position. */
    fseek( fp, save_pos, SEEK_SET );

    return( size_of_file );   
}


Login_Identify_e GetLoginIdentify()
{
    BYTE key[10]="03055030";    
    BYTE strPassword[LOGIN_PASSWORD_MAX] = {0};
    Login_Identify_e Identify = UNKNOW_IDENTIFY;

    if(ReadDataFromFile(strPassword, LOGIN_PASSWORD_MAX, key, g_pPasswdFilepath) == S_DES_SUCCESS)
    {
        if(strPassword[0] == '0' && strPassword[1] == '0')
        {
            Identify = OPERATOR;
        }
        else if(strPassword[0] == '0' && strPassword[1] == '1')
        {
            Identify = ENGINEER;
        }
        else
        {
            Identify = UNKNOW_IDENTIFY;
        }
    }

    return Identify;
}

UINT SaveLoginPasswd(const char *strPasswd)
{
    bool bRet = false;
    BYTE key[10]="03055030";
    int iDatalen=0;
    char tmpStr[LOGIN_PASSWORD_MAX+2] = {0};
    char *pTmpStr = tmpStr;

    pTmpStr[0] = '0';
    pTmpStr[1] = '1';
    strncat(pTmpStr, strPasswd, strlen(strPasswd));
    if(WriteDataToFile((unsigned char*)pTmpStr, LOGIN_PASSWORD_MAX, key, g_pPasswdFilepath)  == S_DES_SUCCESS)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }

}

UINT SaveLoginIdentify(const Login_Identify_e identify)
{
    bool bRet = false;
    BYTE key[10]="03055030";
    int iDatalen=0;
    BYTE tmpStr[LOGIN_PASSWORD_MAX+2] = {0};

    if(ReadDataFromFile(tmpStr, LOGIN_PASSWORD_MAX, key, g_pPasswdFilepath) == S_DES_SUCCESS)
    {
        switch(identify)
        {
        case ENGINEER:
            tmpStr[0] = '0';
            tmpStr[1] = '1';
            break;

        case OPERATOR:
            tmpStr[0] = '0';
            tmpStr[1] = '0';
            break;

        default:
            break;
        }
    }
    else
    {
        return ERROR;
    }

    if(WriteDataToFile((unsigned char*)tmpStr, LOGIN_PASSWORD_MAX, key, g_pPasswdFilepath)  == S_DES_SUCCESS)
    {
        return OK;
    }  
    else
    {
        return ERROR;
    }   
}

void DisableUSBSwitch()
{   
    if (g_hSwitchTool != NULL)
    {
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::DisableUSBSwitch(): Quit UsbSwitchtool start...");
        DisableUSBSwitch(g_hSwitchTool);
        g_hSwitchTool = NULL;
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::DisableUSBSwitch(): Quit UsbSwitchtool end...");
    }
    else
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::DisableUSBSwitch(): Had quit UsbSwitchtool.");
}

void EnableUSBSwitch()
{
    if(g_hSwitchTool == NULL)
    {
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::EnableUSBSwitch(): Enable UsbSwitchtool for dongle project start...");
        g_hSwitchTool = EnableUSBSwitch("-m");
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::EnableUSBSwitch(): Enable UsbSwitchtool for dongle project end...");
    }
    else
        MTRACE (g_hEBOOT_DEBUG, "SmartPhoneSN::EnableUSBSwitch(): Had enabled UsbSwitchtool.");
}

void InitGlobalValue()
{
    memset(&g_sMetaComm, 0, sizeof(META_Common_struct));
    g_sMetaComm.sAuthOption.bAuthenEnable = false;
}

int GetSNSetupFilePath()
{
    memset(&g_pSetupFilepath, 0, MAX_PATH);
    memset(&g_pPasswdFilepath, 0, MAX_PATH);

    char FolderPath[MAX_PATH];
    char FileFullPath[MAX_PATH];

    GetCurrentDirectory( MAX_PATH, FolderPath );

    sprintf(FileFullPath, "%s\\%s", FolderPath, "SN_Setup.ini");      
    if (strlen(FileFullPath) == 0)
    {
        return ERROR;
    }
    memcpy(g_pSetupFilepath, FileFullPath, strlen(FileFullPath)+1);

#ifdef _AUTO_GEN_FEATURE_
    sprintf(FileFullPath, "%s\\%s", FolderPath, "SN_AutoGen.ini");      
    if (strlen(FileFullPath) == 0)
    {
        return ERROR;
    }
    memcpy(g_pAutoGenSetupFilepath, FileFullPath, strlen(FileFullPath)+1);
#endif


    sprintf(FileFullPath, "%s\\%s", FolderPath, "SNDATA");    
    if (strlen(FileFullPath) == 0)
    {
        return ERROR;
    }  
    memcpy(g_pPasswdFilepath, FileFullPath, strlen(FileFullPath)+1);

    return OK;
}

RW_SetupFile_Status GetItemParaFromSetupFile(const char *strFilePath, LPCTSTR lpKeyName, void* lpValue, E_INI_DATA_TYPE dataType)
{
    RW_SetupFile_Status readIniStatus;
    IniData_struct iniData;
    iniData.dataType = dataType;
    iniData.pItemKeyWord = lpKeyName;
    iniData.pItemData = lpValue;

    readIniStatus = ReadIniItemData(strFilePath, iniData);
    return readIniStatus;   
}

RW_SetupFile_Status SaveItemParaToSetupFile(const char *strFilePath, LPCTSTR lpKeyName, void* lpValue, E_INI_DATA_TYPE dataType)
{
    RW_SetupFile_Status writeIniStatus;
    IniData_struct iniData;
    iniData.dataType = dataType;
    iniData.pItemKeyWord = lpKeyName;
    iniData.pItemData = lpValue;

    writeIniStatus = WriteIniItemData(strFilePath, iniData);
    return writeIniStatus;   
}

RW_SetupFile_Status GetParaFromSetupFile()
{   
    RW_SetupFile_Status readIniStatus;

#ifdef _AUTO_GEN_FEATURE_
    readIniStatus = GetAutoGenParaFromSetupFile();
    if (readIniStatus != INI_RW_SUCCESS)
    {
        return readIniStatus;
    }
#endif

    int size = (sizeof(g_IniData) / sizeof(IniData_struct));

    readIniStatus = ReadIniData(g_pSetupFilepath, g_IniData, size);
    if (readIniStatus != INI_RW_SUCCESS)
    {
        return readIniStatus;
    }

    switch (g_sMetaComm.sIMEIOption.iImeiNums)
    {
    case ONE_IMEI:
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        break;

    case DUAL_IMEI:
        g_sMetaComm.sIMEIOption.bDualIMEI = true;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        break;

    case THREE_IMEI:
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = true;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        break;

    case FOUR_IMEI:
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI = true;
        break;

    default:
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        break;
    }

    return INI_RW_SUCCESS;
}

RW_SetupFile_Status SaveParaToSetupFile()
{
    RW_SetupFile_Status writeIniStatus;
#ifdef _AUTO_GEN_FEATURE_    
    writeIniStatus = SaveAutoGenParaToSetupFile();
    if (writeIniStatus != INI_RW_SUCCESS)
    {
        return writeIniStatus;
    }
#endif


    int size = (sizeof(g_IniData) / sizeof(IniData_struct));

    writeIniStatus = WriteIniData(g_pSetupFilepath, g_IniData, size);

    return writeIniStatus;
}

#ifdef _AUTO_GEN_FEATURE_
RW_SetupFile_Status GetAutoGenParaFromSetupFile()
{
    RW_SetupFile_Status readIniStatus;
    int genSize = (sizeof(g_AutoGenSetup) / sizeof(IniData_struct));
    readIniStatus = ReadIniData(g_pAutoGenSetupFilepath, g_AutoGenSetup, genSize);
    return readIniStatus;
}

RW_SetupFile_Status SaveAutoGenParaToSetupFile()
{
    RW_SetupFile_Status writeIniStatus;
    int genSize = (sizeof(g_AutoGenSetup) / sizeof(IniData_struct));
    writeIniStatus = WriteIniData(g_pAutoGenSetupFilepath, g_AutoGenSetup, genSize);   
    return writeIniStatus;   
}

RW_SetupFile_Status UpdateAutoGenParaToSetupFile()
{
    AutoGenResult_e genResult = AutoGen_Success;

    if (g_sMetaComm.sWriteOption.bWriteBarcode && g_AutoGenData.bAutoGenBarcode)
    {
        if (g_AutoGenData.eIncreaseRadix == HEX_RADIX)
        {
            genResult = AutoIncrease(AutoGen_Barcode, g_AutoGenData.sBarcode.iStep, g_AutoGenData.sBarcode.Next, BARCODE_ARRAY_LEN);
        }
        else if (g_AutoGenData.eIncreaseRadix == DENARY_RADIX)
        {
            genResult = AutoIncrease_Ex(AutoGen_Barcode, g_AutoGenData.sBarcode.iStep, g_AutoGenData.sBarcode.Next, BARCODE_ARRAY_LEN, AutoGen_BARC_DENARY_OPTION);
        }

        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "Barcode Next", g_AutoGenData.sBarcode.Next, INI_STRING);
        } 
    } 

    if (g_sMetaComm.sWriteOption.bWriteIMEI && g_AutoGenData.bAutoGenIMEI)
    {      
        if (g_sMetaComm.sIMEIOption.bCheckSum)
        {
            genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
        } 
        else
        {
            genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
        }

        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "IMEI Next", g_AutoGenData.sIMEI.Next, INI_STRING);
        }    
    }

    if (g_sMetaComm.sWriteOption.bWriteBT && g_AutoGenData.bAutoGenBT)
    {
        genResult = AutoIncrease(AutoGen_BT, g_AutoGenData.sBtAddress.iStep, g_AutoGenData.sBtAddress.Next, BT_ARRAY_LEN);
        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "BT Next", g_AutoGenData.sBtAddress.Next, INI_STRING);
        } 
    }  

    if (g_sMetaComm.sWriteOption.bWriteWifi && g_AutoGenData.bAutoGenWifi)
    {
        genResult = AutoIncrease(AutoGen_Wifi, g_AutoGenData.sWifiAddress.iStep, g_AutoGenData.sWifiAddress.Next, WIFI_ARRAY_LEN);
        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "Wifi Next", g_AutoGenData.sWifiAddress.Next, INI_STRING);
        } 
    } 

    if (g_sMetaComm.sWriteOption.bWriteEthernetMac && g_AutoGenData.bAutoGenEthernet)
    {
        genResult = AutoIncrease(AutoGen_Ethernet, g_AutoGenData.sEthernetAddress.iStep, g_AutoGenData.sEthernetAddress.Next, ETHERNET_MAC_ARRAY_LEN);
        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "Ethernet Next", g_AutoGenData.sEthernetAddress.Next, INI_STRING);
        } 
    } 

    if (g_sMetaComm.sWriteOption.bWriteDrmkeyMCID && g_AutoGenData.bAutoGenDRMKeyMCID)
    {
        genResult = AutoIncrease(AutoGen_DRMKeyMCID, g_AutoGenData.sDRMKeyMCID.iStep, g_AutoGenData.sDRMKeyMCID.Next, DRMKEY_MCID_ARRAY_LEN);
        if (genResult == AutoGen_Success)
        {
            SaveItemParaToSetupFile(g_pAutoGenSetupFilepath, "DRMKey MCID Next", g_AutoGenData.sDRMKeyMCID.Next, INI_STRING);
        } 
    }

    return INI_RW_SUCCESS;
}
#endif




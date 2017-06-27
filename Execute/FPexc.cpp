#include "StdAfx.h"
#include "FPexc.h"
#include "xboot_debug.h"
#include "Common.h"
#include "AutoGen.h"
#include "SN Writer.h"
#include "SN WriterDlg.h"
#include "ScanData.h"

extern CSNWriterDlg *g_pMainDlg;

FeaturePhoneSN::FeaturePhoneSN()
{
    m_hMauiMetaHandle = INVALID_META_HANDLE;
}

FeaturePhoneSN:: ~FeaturePhoneSN()
{

}

void FeaturePhoneSN::SetupMetaModeParameters()
{
    m_tMetaReq_Ex.com_port = g_sMetaComm.iCOMPort;
    m_tMetaReq_Ex.ms_connect_timeout = 400000;
    m_tMetaReq_Ex.close_com_port = _TRUE;
    m_tMetaReq_Ex.InMetaMode=_FALSE;
    m_tMetaReq_Ex.protocol = 0;         // DHL
    m_tMetaReq_Ex.channel_type = 0;     // Native channel
    m_tMetaReq_Ex.boot_meta_arg.m_bbchip_type = AUTO_DETECT_BBCHIP;
    m_tMetaReq_Ex.boot_meta_arg.m_ext_clock = AUTO_DETECT_EXT_CLOCK;

    if (g_sMetaComm.bUsbEnable)
    {
        m_tMetaReq_Ex.boot_meta_arg.m_usb_enable = _TRUE;
        m_tMetaReq_Ex.usb_enable = _TRUE;
        if (g_sMetaComm.bWithoutBattery)
        {
            m_tMetaReq_Ex.boot_meta_arg.m_enable_without_battery = _TRUE;
        }
        else
        {
            m_tMetaReq_Ex.boot_meta_arg.m_enable_without_battery = _FALSE;
        }
    }
    else
    {
        m_tMetaReq_Ex.usb_enable = _FALSE;
        m_tMetaReq_Ex.boot_meta_arg.m_usb_enable = _FALSE;
        m_tMetaReq_Ex.flowctrl = META_SW_FLOWCTRL;
    }


    m_tMetaReq_Ex.baudrate[0] = META_BAUD115200;
    m_tMetaReq_Ex.baudrate[1] = META_BAUD230400;
    m_tMetaReq_Ex.baudrate[2] = META_BAUD460800;
    m_tMetaReq_Ex.baudrate[3] = META_BAUD921600;
    m_tMetaReq_Ex.baudrate[4] = META_BAUD57600;
    m_tMetaReq_Ex.baudrate[5] = META_BAUD_END;

    m_tMetaReq_Ex.boot_meta_arg.m_ms_boot_timeout = 30000;
    m_tMetaReq_Ex.boot_meta_arg.m_scert_handle = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_cb_in_brom_stage = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_cb_in_brom_stage_arg = NULL;
    // security level2
    m_tMetaReq_Ex.boot_meta_arg.m_speedup_brom_baudrate = _TRUE; //115200
    m_tMetaReq_Ex.boot_meta_arg.m_ready_power_on_wnd_handle = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_ready_power_on_wparam = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_ready_power_on_lparam = NULL;

    if (g_sMetaComm.bSecurityUSB)
    {
        m_tMetaReq_Ex.boot_meta_arg.m_auth_handle = Get_AuthHandle();
        m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge = SLA_Challenge;//SLA_Challenge(NULL,NULL,0,NULL,NULL);
        m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge_end = SLA_Challenge_END; // NULL;
    }
    else
    {
        m_tMetaReq_Ex.boot_meta_arg.m_auth_handle = NULL;
        m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge = NULL;//SLA_Challenge(NULL,NULL,0,NULL,NULL);
        m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge_end = NULL; // NULL;
    }

    m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge_arg = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_cb_sla_challenge_end_arg = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_cb_com_init_stage = NULL;
    m_tMetaReq_Ex.boot_meta_arg.m_cb_com_init_stage_arg = NULL;
}

META_RESULT FeaturePhoneSN::MetaHandle_Init()
{
    META_RESULT meta_result = META_SUCCESS;
    if (m_hMauiMetaHandle == INVALID_META_HANDLE)
    {
        meta_result = ModemMetaHandle_Init();
        if (meta_result != META_SUCCESS)
        {
            UpdateUIMsg("Init meta handle fail, MetaResult = %s", ResultToString(meta_result));
        }
    }

    return meta_result;
}

void FeaturePhoneSN::MetaHandle_DeInit()
{
    if (m_hMauiMetaHandle != INVALID_META_HANDLE)
    {
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::MetaHandle_DeInit() : DeInit meta handle start...");
        ModemMetaHandle_DeInit();
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::MetaHandle_DeInit() : DeInit meta handle end...");
    }
}

META_RESULT FeaturePhoneSN::ModemMetaHandle_Init()
{
    META_RESULT MetaResult = META_SUCCESS;
    MetaResult = META_GetAvailableHandle( &m_hMauiMetaHandle );
    if(MetaResult != META_SUCCESS)
    {
        MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_GetAvailableHandle(): Get available modem meta handle Fail, MetaResult = %s", ResultToString(MetaResult));
        return MetaResult;
    }
    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_GetAvailableHandle(): Get available modem meta handle success!");

    MetaResult = META_Init_r( m_hMauiMetaHandle, NULL);
    if(MetaResult != META_SUCCESS)
    {
        MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_Init_r(): Init modem meta handle Fail, MetaResult = %s", ResultToString(MetaResult));
        return MetaResult;
    }
    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_Init_r(): Init modem meta handle success!");

    return META_SUCCESS;
}

void FeaturePhoneSN::ModemMetaHandle_DeInit()
{
    META_Deinit_r(&m_hMauiMetaHandle);
    m_hMauiMetaHandle = INVALID_META_HANDLE;
}

META_RESULT FeaturePhoneSN::EnterModemMeta()
{
    unsigned short comPort = 0;
    META_RESULT MetaResult = META_SUCCESS;
    char info[512] = {0};

    PortEnumHelper cBromHelper;
    PortEnumHelper cPreloaderHelper;
    char * szBromFilter = NULL;
    char * szPreloaderFilter = NULL;

    cBromHelper.SetFilter(SP_WHITE_LIST, g_sMetaComm.sPortFilter.strBromFilter);
    if (cBromHelper.GetFilter()->m_uCount > 0)
        szBromFilter = cBromHelper.GetFilter()->m_ppFilterID[0];
    else
        szBromFilter = "";
    cPreloaderHelper.SetFilter(SP_WHITE_LIST, g_sMetaComm.sPortFilter.strPreloaderFilter);
    if (cPreloaderHelper.GetFilter()->m_uCount > 0)
        szPreloaderFilter = cPreloaderHelper.GetFilter()->m_ppFilterID[0];
    else
        szPreloaderFilter = "";

    if (g_sMetaComm.bUsbEnable == false)
    {
        UpdateUIMsg("Start enter meta mode...");
        MetaResult = META_ConnectWithMultiModeTarget_r(m_hMauiMetaHandle, &m_tMetaReq_Ex, sizeof(m_tMetaReq_Ex), m_pMetaStopFlag, &m_tMetaConnReport_Ex);
    }
    else
    {
        if (g_sMetaComm.bDualTalk)
        {
            SP_BOOT_ARG_S stArg;
            int BootStop = SP_BOOT_INFINITE;
            int iRet = S_DONE;
            int ms_connect_timeout = 30000;

            memset(&stArg, 0, sizeof(SP_BOOT_ARG_S));
            //Parameter settings
            stArg.m_bbchip_type = SP_AUTO_DETECT_BBCHIP;
            stArg.m_ext_clock = SP_AUTO_DETECT_EXT_CLOCK;
            stArg.m_ms_boot_timeout = SP_BOOT_INFINITE;
            stArg.m_max_start_cmd_retry_count = SP_DEFAULT_BROM_START_CMD_RETRY_COUNT;

            stArg.m_uTimeout = 20000;
            stArg.m_uRetryTime = 2000;
            stArg.m_uInterval = 10;
            stArg.m_uBaudrate = CBR_115200;

            stArg.m_auth_handle = NULL;
            stArg.m_scert_handle = NULL;
            stArg.m_cb_sla_challenge = NULL;
            stArg.m_cb_sla_challenge_arg = NULL;
            stArg.m_cb_sla_challenge_end = NULL;
            stArg.m_cb_sla_challenge_end_arg = NULL;

            stArg.m_pStopFlag = m_pMetaStopFlag;
            stArg.m_bIsUSBEnable = g_sMetaComm.bUsbEnable;
            stArg.m_bIsSymbolicEnable = false;
            stArg.m_bIsCompositeDeviceEnable = g_sMetaComm.bCompositeDeviceEnable;
            stArg.m_euBootMode = SP_DUALTALK_SWITCH;
            memset(stArg.m_szPortSymbolic, 0, 256);

            // step1: Get Preloader Port
            UpdateUIMsg("Wait for usb insert...");
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Step1, Get preloader comport...");
            MetaResult = META_GetDynamicUSBComPortExWithFilter_r(m_hMauiMetaHandle,
                ms_connect_timeout, &comPort, m_pMetaStopFlag, info, 1000, szPreloaderFilter);
            if(META_SUCCESS != MetaResult)
            {
                MTRACE_ERR ( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Get preloader comport fail!");
                return MetaResult;
            }
            MTRACE( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Get preloader comport successfully, comport = %d!", comPort);

            // step2: switch to modem
            stArg.m_uPortNumber = comPort;
            UpdateUIMsg("Handshake with preloader.");
            MTRACE ( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Step2, Switch to modem ...");
            iRet = SP_Preloader_BootMode(&stArg);
            if(S_DONE != iRet)
            {
                MTRACE_ERR ( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Switch to modem fail!");
                return (META_RESULT)iRet;
            }
            MTRACE( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Switch to modem successfully!");

            // step3: get modem comport
            UpdateUIMsg("Wait for device enter meta mode...");
            MTRACE ( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Step3, Get Modem Brom Port...");
            MetaResult = META_GetDynamicUSBComPortExWithFilter_r(m_hMauiMetaHandle,
                ms_connect_timeout, &comPort, m_pMetaStopFlag, info, 512, szBromFilter);
            if(META_SUCCESS != MetaResult)
            {
                MTRACE_ERR( g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Get Modem Brom Port fail!");
                return MetaResult;
            }
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::EnterModemMeta(): Get Modem Brom Port successfully, comPort = %d!", comPort);
        }
        else
        {
            UpdateUIMsg("Wait for usb insert...");
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_GetDynamicUSBComPortExWithFilter_r(): Start...");
            MetaResult = META_GetDynamicUSBComPortExWithFilter_r(m_hMauiMetaHandle,
                m_tMetaReq_Ex.ms_connect_timeout, &comPort, m_pMetaStopFlag, info, 512, szBromFilter);
            if (MetaResult != META_SUCCESS)
            {
                MTRACE_ERR(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_GetDynamicUSBComPortExWithFilter_r(): fail, %s.", ResultToString(MetaResult));
                return MetaResult;
            }
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_GetDynamicUSBComPortExWithFilter_r(): ok, COM%u.", comPort);
        }

        UpdateUIMsg("Start enter meta mode...");
        m_tMetaReq_Ex.com_port = comPort;
        MetaResult = META_ConnectWithMultiModeTarget_r(m_hMauiMetaHandle, &m_tMetaReq_Ex, sizeof(m_tMetaReq_Ex), m_pMetaStopFlag, &m_tMetaConnReport_Ex);
    }

    if (MetaResult == META_SUCCESS)
    {
        m_bStopBeforeUSBInsert = false;
        m_bTargetInMetaMode = true;
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_ConnectWithMultiModeTarget_r(): ok.");
    }
    else if (MetaResult == META_MAUI_DB_INCONSISTENT)
    {
        m_bStopBeforeUSBInsert = false;
        m_bTargetInMetaMode = true;
        if (!g_sMetaComm.sDBFileOption.bDBInitModem_1)
        {
            MetaResult = META_SUCCESS;
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_ConnectWithMultiModeTarget_r(): ok, md db inconsistent, directly ignore.");
        }
        else if (g_sMetaComm.IgnoreDBInconsistent)
        {
            MetaResult = META_SUCCESS;
            MTRACE_WARN(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_ConnectWithMultiModeTarget_r(): ok, md db inconsistent, but ignore.");
        }
        else
        {
            UpdateUIMsg("Enter meta mode fail, md db inconsistent.");
            MTRACE_ERR(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_ConnectWithMultiModeTarget_r(): fail, md db inconsistent.");
        }
    }
    else
    {
        m_bStopBeforeUSBInsert = true;
        m_bTargetInMetaMode = false;
        UpdateUIMsg("Enter meta mode fail, %s", ResultToString(MetaResult));
        MTRACE_ERR(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_ConnectWithMultiModeTarget_r(): fail, %s.", ResultToString(MetaResult));
    }

    return MetaResult;
}

META_RESULT FeaturePhoneSN::ExitModemMeta()
{
    META_RESULT MetaResult = META_SUCCESS;
    char strTmp[1024] = {0};

    if (m_bTargetInMetaMode)
    {
        char *pFuncName = "META_DisconnectWithTarget_r";
        MetaResult = META_DisconnectWithTarget_r (m_hMauiMetaHandle);

        if (MetaResult == META_SUCCESS)
        {
            m_bTargetInMetaMode = false;
            MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::ExitModemMeta(): Exit meta mode by %s successfully! MetaResult = %s",
                pFuncName, ResultToString(MetaResult));
        }
        else
        {
            MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::ExitModemMeta(): Exit meta mode by %s Fail! MetaResult = %s", pFuncName, ResultToString(MetaResult));
        }
    }

    return MetaResult;
}

META_RESULT FeaturePhoneSN::LoadModemDatabase(int MDindex)
{
    unsigned long db;
    bool bEnterCritSetion = false;
    META_RESULT meta_result;

    if (!g_sMetaComm.sDBFileOption.strMD1Dbpath)
    {
        MTRACE_ERR(g_hEBOOT_DEBUG, "FeaturePhoneSN::LoadModemDatabase(): Incorrect database file path!");
        return META_INVALID_ARGUMENTS;
    }

    if (g_sMetaComm.sDBFileOption.bDBInitModem_1)
    {
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): Modem database already init done!");
        return META_SUCCESS;
    }

    MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): Start init modem database, DB path = %s...", g_sMetaComm.sDBFileOption.strMD1Dbpath);

    meta_result = META_NVRAM_Init_r( m_hMauiMetaHandle, g_sMetaComm.sDBFileOption.strMD1Dbpath, &db);
    if (meta_result == META_SUCCESS)
    {
        g_sMetaComm.sDBFileOption.bDBInitModem_1 = true;
        MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): ok.");
    }
    else if (meta_result == META_MAUI_DB_INCONSISTENT)
    {
        if (g_sMetaComm.IgnoreDBInconsistent)
        {
            meta_result = META_SUCCESS;
            g_sMetaComm.sDBFileOption.bDBInitModem_1 = true;
            MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): ok, md db inconsistent, but ignore.");
        }
        else
        {
            g_sMetaComm.sDBFileOption.bDBInitModem_1 = false;
            MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): fail, md db inconsistent.");
        }
    }
    else
    {
        g_sMetaComm.sDBFileOption.bDBInitModem_1 = false;
        MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_Init_r(): fail, %s", ResultToString(meta_result));
    }

    return meta_result;
}

META_RESULT FeaturePhoneSN::REQ_ReadModem_NVRAM_Start(WriteData_Type_e dataType, char *pOutData, unsigned short iRID)
{
    if(!pOutData)
    {
        return META_INVALID_ARGUMENTS;
    }
    m_bWriteNvram = true;

    int iBufLen = 0;
    char *pLID = NULL;
    pConductDataFunc pDataFunc = NULL;
    char *pFuncName = NULL;
    char *pDataType = NULL;

    switch(dataType)
    {
    case WRITE_BARCODE:
        iBufLen = 64;
        pDataType = "Barcode";
        pLID = "NVRAM_EF_BARCODE_NUM_LID";
        pDataFunc = &FeaturePhoneSN::ConductBarcodeData;
        pFuncName = "ConductBarcodeData";
        break;

    case WRITE_IMEI:
        iBufLen = 10;
        pDataType = "IMEI";
        pLID = "NVRAM_EF_IMEI_IMEISV_LID";
        pDataFunc = ConductIMEIData;
        pFuncName = "ConductIMEIData";
        break;

    case WRITE_BT:
        iBufLen = 6;
        pDataType = "BT";
        pLID = "NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID";
        pDataFunc = &FeaturePhoneSN::ConductBTAddrData;
        pFuncName = "ConductBTAddrData";
        break;

    case WRITE_WIFI:
        iBufLen = 6;
        pDataType = "Wifi";
        pLID = "NVRAM_EF_WNDRV_MAC_ADDRESS_LID";
        pDataFunc = &FeaturePhoneSN::ConductWifiAddrData;
        pFuncName = "ConductWifiAddrData";
        break;
    }

    META_RESULT meta_result = META_SUCCESS;
    FT_NVRAM_READ_REQ   sNVRAM_ReadReq;
    FT_NVRAM_READ_CNF   sNVRAM_ReadCnf;

    int iMetaTimeout = 5000;
    int iReadBufSize = 0;
    unsigned char pReadData[64] = {0};

    memset(&sNVRAM_ReadReq, 0, sizeof(FT_NVRAM_READ_REQ));
    memset(&sNVRAM_ReadCnf, 0, sizeof(FT_NVRAM_READ_CNF));

    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Start to get nvram struct size via LID = \"%s\"...", pLID);
    meta_result = META_NVRAM_GetRecLen(pLID,&iReadBufSize);
    if ( META_SUCCESS != meta_result)
    {
        MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Get nvram struct size fail, MetaResult = %s...",  ResultToString(meta_result));
        UpdateUIMsg(ResultToString(meta_result));
        return meta_result;
    }
    else
    {
        MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Get nvram struct size = %d successfully!", iReadBufSize);
        if( NULL != sNVRAM_ReadCnf.buf)
        {
            free(sNVRAM_ReadCnf.buf);
            sNVRAM_ReadCnf.buf = NULL;
        }

        sNVRAM_ReadReq.LID = pLID;
        sNVRAM_ReadReq.RID = iRID;
        sNVRAM_ReadCnf.len = iReadBufSize;
        sNVRAM_ReadCnf.buf = (unsigned char*) malloc (iReadBufSize * sizeof(unsigned char));
        if (NULL == sNVRAM_ReadCnf.buf)
        {
            MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::Malloc heap memory fail!");
            return META_FAILED;
        }
    }

    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_ReadFromModemNVRAM(): Start to read nvram data...");
    meta_result =  REQ_ReadFromModemNVRAM(&sNVRAM_ReadReq, &sNVRAM_ReadCnf);
    if (meta_result != META_SUCCESS )
    {
        pFuncName = "FeaturePhoneSN::REQ_ReadFromModemNVRAM()";
        goto Err;
    }
	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_ReadFromModemNVRAM(): Read nvram data successfully!");

    memcpy(pOutData, sNVRAM_ReadCnf.buf, iReadBufSize);

    if (sNVRAM_ReadCnf.buf != NULL)
    {
        free (sNVRAM_ReadCnf.buf);
        sNVRAM_ReadCnf.buf = NULL;
    }

    return meta_result;

Err:
    if (sNVRAM_ReadCnf.buf != NULL)
    {
        free (sNVRAM_ReadCnf.buf);
        sNVRAM_ReadCnf.buf = NULL;
    }
    MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::%s cause fail! MetaResult = %s", pFuncName, ResultToString(meta_result));
    return meta_result;
}

META_RESULT FeaturePhoneSN::REQ_WriteModem_NVRAM_Start(WriteData_Type_e dataType, char *pInData, unsigned short iRID)
{
    if(!pInData)
    {
        return META_INVALID_ARGUMENTS;
    }

    m_bWriteNvram = true;

    int iBufLen = 0;
    char *pLID = NULL;
    pConductDataFunc pDataFunc = NULL;
	char *pFuncName = NULL;
	char *pDataType = NULL;

    switch(dataType)
    {
    case WRITE_BARCODE:
        iBufLen = 64;
		pDataType = "Barcode";
        pLID = "NVRAM_EF_BARCODE_NUM_LID";
        pDataFunc = &FeaturePhoneSN::ConductBarcodeData;
		pFuncName = "ConductBarcodeData";
        break;

    case WRITE_IMEI:
        iBufLen = 10;
		pDataType = "IMEI";
        pLID = "NVRAM_EF_IMEI_IMEISV_LID";
        pDataFunc = &FeaturePhoneSN::ConductIMEIData;
		pFuncName = "ConductIMEIData";
        break;

    case WRITE_BT:
        iBufLen = 6;
		pDataType = "BT";
        pLID = "NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID";
        pDataFunc = &FeaturePhoneSN::ConductBTAddrData;
		pFuncName = "ConductBTAddrData";
        break;

    case WRITE_WIFI:
        iBufLen = 6;
		pDataType = "Wifi";
        pLID = "NVRAM_EF_WNDRV_MAC_ADDRESS_LID";
        pDataFunc = &FeaturePhoneSN::ConductWifiAddrData;
		pFuncName = "ConductWifiAddrData";
        break;
    }


    META_RESULT meta_result;
	FT_NVRAM_WRITE_REQ  sNVRAM_WriteReq;
    FT_NVRAM_WRITE_CNF  sNVRAM_WriteCnf;
    FT_NVRAM_READ_REQ   sNVRAM_ReadReq;
    FT_NVRAM_READ_CNF   sNVRAM_ReadCnf;

	DWORD wait_result = 0;
    int iMetaTimeout = 5000;
    int iWriteBufSize = 0;
    unsigned char pWriteData[64] = {0};
	unsigned char pReadData[64] = {0};

	memset(&sNVRAM_WriteReq, 0, sizeof(FT_NVRAM_WRITE_REQ));
    memset(&sNVRAM_WriteCnf, 0, sizeof(FT_NVRAM_WRITE_CNF));
    memset(&sNVRAM_ReadReq, 0, sizeof(FT_NVRAM_READ_REQ));
    memset(&sNVRAM_ReadCnf, 0, sizeof(FT_NVRAM_READ_CNF));

    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Start to get nvram struct size via LID = \"%s\"...", pLID);
    meta_result = META_NVRAM_GetRecLen(pLID,&iWriteBufSize);
    if ( META_SUCCESS != meta_result)
    {
        MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Get nvram struct size fail, MetaResult = %s...",  ResultToString(meta_result));
        UpdateUIMsg(ResultToString(meta_result));
        return meta_result;
    }
    else
    {
        MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_NVRAM_GetRecLen(): Get nvram struct size = %d successfully!", iWriteBufSize);
		if( NULL != sNVRAM_ReadCnf.buf)
		{
		   free(sNVRAM_ReadCnf.buf);
		   sNVRAM_ReadCnf.buf = NULL;
		}

		sNVRAM_ReadReq.LID = pLID;
        sNVRAM_ReadReq.RID = iRID;
        sNVRAM_ReadCnf.len = iWriteBufSize;
		sNVRAM_ReadCnf.buf = (unsigned char*) malloc (iWriteBufSize * sizeof(unsigned char));
        if (NULL == sNVRAM_ReadCnf.buf)
        {
            MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::Malloc heap memory fail!");
            return META_FAILED;
        }
    }

    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_ReadFromModemNVRAM(): Start to read nvram data...");
    meta_result =  REQ_ReadFromModemNVRAM(&sNVRAM_ReadReq, &sNVRAM_ReadCnf);
    if (meta_result != META_SUCCESS )
    {
        pFuncName = "FeaturePhoneSN::REQ_ReadFromModemNVRAM()";
        goto Err;
    }
	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_ReadFromModemNVRAM(): Read nvram data successfully!");


    meta_result = (this->*pDataFunc)((char*)sNVRAM_ReadCnf.buf, iRID, pInData, iBufLen);
    if (meta_result != META_SUCCESS)
    {
        goto Err;
    }
	else
	{
	    memcpy(pWriteData, sNVRAM_ReadCnf.buf, sNVRAM_ReadCnf.len);
	    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::%s(): Conduct nvram data successfully!", pFuncName);
	}

    sNVRAM_WriteReq.LID = pLID;
    sNVRAM_WriteReq.RID = iRID;
    sNVRAM_WriteReq.len = iWriteBufSize;
    sNVRAM_WriteReq.buf = sNVRAM_ReadCnf.buf;

    //sNVRAM_WriteCnf.status = 0;
    //sNVRAM_WriteCnf.LID = pLID;
    sNVRAM_WriteCnf.RID = iRID;

    m_sNVRAM_OPID = iRID;

	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_WriteToModemNVRAM(): Start to write nvram data...");
    meta_result =  REQ_WriteToModemNVRAM(&sNVRAM_WriteReq, &sNVRAM_WriteCnf);
    if (meta_result != SPMETA_DLL::META_SUCCESS )
    {
        pFuncName = "FeaturePhoneSN::REQ_WriteToModemNVRAM()";
        goto Err;
    }
	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_WriteToModemNVRAM(): Write nvram data successfully!");

	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_WriteToModemNVRAM(): Read nvram data for check start...");
    memset(sNVRAM_ReadCnf.buf, 0 , sNVRAM_ReadCnf.len);
	meta_result = REQ_ReadFromModemNVRAM (&sNVRAM_ReadReq, &sNVRAM_ReadCnf);
	if (meta_result != SPMETA_DLL::META_SUCCESS )
    {
        pFuncName = "FeaturePhoneSN::REQ_WriteToModemNVRAM()";
        goto Err;
    }
	else
	{
        char tmpReadData[64] = {0};
		m_bWriteNvram = false;

		memcpy(pReadData, sNVRAM_ReadCnf.buf, iBufLen);
		(this->*pDataFunc)(tmpReadData, iRID, (char*)pReadData, iBufLen);
		if(memcmp(pWriteData, pReadData, iBufLen) != 0)
		{
			MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN: Write_%s[%s]", pDataType, pInData);
			MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN: Read_%s[%s]", pDataType, tmpReadData);
            MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN: Check nvram data FAIL!!");
			meta_result = META_FAILED;
		}
		else
		{

			MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN: Write_%s[%s]", pDataType, pInData);
			MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN: Read_%s[%s]", pDataType, tmpReadData);
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN: Check nvram data PASS!!");
		}
	}
	MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_WriteToModemNVRAM(): Read nvram data for check end...");

	if (sNVRAM_ReadCnf.buf != NULL)
    {
        free (sNVRAM_ReadCnf.buf);
        sNVRAM_ReadCnf.buf = NULL;
    }

    return meta_result;

Err:
	if (sNVRAM_ReadCnf.buf != NULL)
    {
        free (sNVRAM_ReadCnf.buf);
        sNVRAM_ReadCnf.buf = NULL;
    }
    MTRACE_ERR (g_hEBOOT_DEBUG, "FeaturePhoneSN::%s cause fail! MetaResult = %s", pFuncName, ResultToString(meta_result));
    return meta_result;
}

META_RESULT FeaturePhoneSN::REQ_BackupNvram2SDS_Start()
{
    MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Start backup nvram to SDS/Backup_Partition if target support...");
    UINT status;
    META_RESULT MetaResult = META_SUCCESS;

    UpdateUIMsg("Query target support SDS/Backup_Partition...");
    MetaResult = META_QueryIfFunctionSupportedByTarget_r(m_hMauiMetaHandle, 500, "META_MISC_EX_BackupCalibrationToStorage_r");

    if(META_SUCCESS == MetaResult)
    {
        UpdateUIMsg( "Trigger backup nvram to SDS/Backup_Partition start..." );
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Trigger backup nvram to SDS/Backup_Partition start...");
        MetaResult = META_MISC_EX_BackupCalibrationToStorage_r(m_hMauiMetaHandle, 5000, 0, &status);
        if(MetaResult == META_SUCCESS)
        {
            MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Trigger backup nvram to SDS/Backup_Partition successfully!!");
        }
        else
        {
            MTRACE_ERR(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Trigger backup nvram to SDS/Backup_Partition Fail, MetaResult = %s", ResultToString(MetaResult));
        }
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Trigger backup nvram to SDS/Backup_Partition end...");
    }
    else
    {
        MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): Target without SDS/Backup_Partition feature");
        return META_SUCCESS;;
    }

    MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::REQ_BackupNvram2SDS_Start(): End backup nvram to SDS/Backup_Partition...");
    return MetaResult;
}

META_RESULT FeaturePhoneSN::WriteNvramLoop()
{
    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::WriteNvramLoop() start...");

    FEATURE_PHONE_STAGE_e fpStage = FP_START_STAGE;
    FEATURE_PHONE_STAGE_e fpNextStage = FP_END_STAGE;
    META_RESULT MetaResult = META_SUCCESS;
    double fBeginProcess = 0.25;
    double fStep = 0.04;
    m_bBackupNvramSuccess = false;

    int iIMEINums = g_sMetaComm.sIMEIOption.iImeiNums;

    char tmpBuf[2048] = {0};
    if (g_sMetaComm.bCheckCalFlag || g_sMetaComm.bCheckFtFlag)
    {
        if(REQ_ReadModem_NVRAM_Start(WRITE_BARCODE, tmpBuf, 1) == META_SUCCESS)
        {
            bool bCheckPass = true;
            bCheckPass = CheckCalFinalTestStatus(tmpBuf);
            if (bCheckPass == false)
            {
                return META_FAILED;
            }
        }
    }

    while((fpStage != FP_END_STAGE) && (*m_pMetaStopFlag != BOOT_STOP))
    {
        switch(fpStage)
        {
        case FP_START_STAGE:
            fpNextStage = FP_BARCODE_STAGE;
            break;

        case FP_BARCODE_STAGE:
            fBeginProcess += fStep;
            if (g_sMetaComm.sWriteOption.bWriteBarcode)
            {
                MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::Barcode = \"%s\"", m_sScanData.strBarcode);
                MetaResult = REQ_WriteModem_NVRAM_Start(WRITE_BARCODE, m_sScanData.strBarcode, 1);
                if (MetaResult == META_SUCCESS)
                {
                    fpNextStage = FP_IMEI_STAGE;
                }
                else
                {
                    UpdateUIMsg("FeaturePhoneSN::Barcode : MetaResult = %s", ResultToString(MetaResult));
                    fpNextStage = FP_END_STAGE;
                }
            }
            else
            {
                fpNextStage = FP_IMEI_STAGE;
            }
            break;

        case FP_IMEI_STAGE:

            if (g_sMetaComm.sWriteOption.bWriteIMEI)
            {
                for (int i = 0; i < iIMEINums; i++)
                {
                    fBeginProcess += fStep;
                    MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::IMEI[%d] = \"%s\"", i, m_sScanData.strIMEI[i]);
                    MetaResult = REQ_WriteModem_NVRAM_Start(WRITE_IMEI, m_sScanData.strIMEI[i], i+1);
                    if (MetaResult == META_SUCCESS)
                    {
                        if (i+1 == iIMEINums)
                        {
                            if (g_sMetaComm.sIMEIOption.bLockIMEI)
                            {
                                MetaResult = META_NVRAM_LockDown_r(m_hMauiMetaHandle, 5000);
                                if (MetaResult == META_SUCCESS)
                                {
                                    fpNextStage = FP_BT_ADDRESS_STAGE;
                                }
                                else
                                {
                                    fpNextStage = FP_END_STAGE;
                                }
                            }
                            else
                            {
                                fpNextStage = FP_BT_ADDRESS_STAGE;
                            }

                            break;
                        }
                    }
                    else
                    {
                        if (m_bNeedBackupIMEI)
                        {
                            strncpy(g_AutoGenData.sIMEI.Next, m_strBackupIMEI, strlen(m_strBackupIMEI));
                        }
                        UpdateUIMsg("FeaturePhoneSN::IMEI[%d] : MetaResult = %s", i, ResultToString(MetaResult));
                        fpNextStage = FP_END_STAGE;
                        break;
                    }
                }
            }
            else
            {
                fpNextStage = FP_BT_ADDRESS_STAGE;
            }
            break;

        case FP_BT_ADDRESS_STAGE:
            if (g_sMetaComm.sWriteOption.bWriteBT)
            {
                fBeginProcess += fStep;
                MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::BT = \"%s\"", m_sScanData.strBTAddr);
                MetaResult = REQ_WriteModem_NVRAM_Start(WRITE_BT, m_sScanData.strBTAddr, 1);
                if (MetaResult == META_SUCCESS)
                {
                    fpNextStage = FP_WIFI_ADDRESS_STAGE;
                }
                else
                {
                    UpdateUIMsg("FeaturePhoneSN::BT : MetaResult = %s", ResultToString(MetaResult));
                    fpNextStage = FP_END_STAGE;
                }
            }
            else
            {
                fpNextStage = FP_WIFI_ADDRESS_STAGE;
            }
            break;

        case FP_WIFI_ADDRESS_STAGE:
            if (g_sMetaComm.sWriteOption.bWriteWifi)
            {
                fBeginProcess += fStep;
                MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::Wifi = \"%s\"", m_sScanData.strWifiAddr);
                MetaResult = REQ_WriteModem_NVRAM_Start(WRITE_WIFI, m_sScanData.strWifiAddr, 1);
                if (MetaResult == META_SUCCESS)
                {
                    fpNextStage = FP_BACKUP_NVRAM_STAGE;
                }
                else
                {
                    UpdateUIMsg("FeaturePhoneSN::Wifi : MetaResult = %s", ResultToString(MetaResult));
                    fpNextStage = FP_END_STAGE;
                }
            }
            else
            {
                fpNextStage = FP_BACKUP_NVRAM_STAGE;
            }
            break;

        case FP_BACKUP_NVRAM_STAGE:
            fBeginProcess += fStep;
            MetaResult = REQ_BackupNvram2SDS_Start();
            if (MetaResult == META_SUCCESS)
            {
                m_bBackupNvramSuccess = true;
            }
            else
            {
                m_bBackupNvramSuccess = false;
            }
            fpNextStage = FP_END_STAGE;
            break;
        }

        fpStage = fpNextStage;
    }

    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::WriteNvramLoop() end...");
    return MetaResult;
}

void FeaturePhoneSN::ThreadMainEntryPoint()
{
    bool bNeedScanData = false;

    /*For dual talk project
    * Due to dual talk project can`t switch back and forth between ap and modem
    * When target type select feature phone, mean will write modem nvram, so need disable write ap nvram
    */
    bool bWriteBT = g_sMetaComm.sWriteOption.bWriteBT;
    bool bWriteWifi = g_sMetaComm.sWriteOption.bWriteWifi;
    if (g_sMetaComm.bDualTalk)
    {
        g_sMetaComm.sWriteOption.bWriteBT = false;
        g_sMetaComm.sWriteOption.bWriteWifi = false;
    }

    bNeedScanData = NeedScanData();
    if (bNeedScanData == false)
    {
        PopupMsgBox("Warning", MB_OK|MB_ICONWARNING, "At least select one write option!!");
        return;
    }

    META_RESULT MetaResult = META_SUCCESS;
    bool bAnyOperationFail = false;
    char strChipID[100] = {0};

    if (g_sMetaComm.bSwithTool)
        EnableUSBSwitch();

    m_hMauiMetaHandle = INVALID_META_HANDLE;
    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::Meta_Init(): Start...");
    MetaResult = MetaHandle_Init();
    if (MetaResult != META_SUCCESS)
    {
        bAnyOperationFail = true;
        *m_pMetaStopFlag = BOOT_STOP;
    }
    MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::Meta_Init(): End...");

    CScanData scanDlg;
    while((*m_pMetaStopFlag != BOOT_STOP) && (IDOK == scanDlg.DoModal()))
    {
        DebugOnOff(true);
        MTRACE(g_hEBOOT_DEBUG, "------------------------------------ START -------------------------------------");
        LogConfig();
        bAnyOperationFail = false;
        UpdateMainDlgUI(false, NORMAL);

        EnableStartBTN(false);

        SNThread_Init();
        UpdateProgress(0.05);

        SetupMetaModeParameters();
        UpdateProgress(0.10);

        EnableStartBTN(true);

        MetaResult = (META_RESULT)EnterModemMeta();
        if (MetaResult != META_SUCCESS)
        {
            bAnyOperationFail = true;
            UpdateUIMsg("EnterModemMeta() : MetaResult = %s", ResultToString(MetaResult));
            goto End;
        }
        UpdateProgress(0.15);

        UpdateUIMsg("Start load and init database...");
        MetaResult = LoadModemDatabase(0);
        if (MetaResult != META_SUCCESS)
        {
            bAnyOperationFail = true;
            UpdateUIMsg("LoadModemDatabase() : MetaResult = %s", ResultToString(MetaResult));
            PopupMsgBox("Error", MB_OK|MB_ICONERROR, "LoadModemDatabase() : MetaResult = %s", ResultToString(MetaResult));
            goto End;
        }
        UpdateProgress(0.20);

        /*
        META_MISC_GetRID_r(m_hMauiMetaHandle, 5000, (unsigned char*)strChipID,16);
        if(strlen(strChipID) != 0)
        {
            MTRACE (g_hEBOOT_DEBUG, "FeaturePhoneSN::META_MISC_GetRID_r(): Get chip_id success, chip_id = %s!", strChipID);
            goto End;
        }
        */

        EnableStartBTN(false);
        UpdateProgress(0.22);
        UpdateUIMsg("Start loop write data to nvram...");
        MetaResult = WriteNvramLoop();
        if (MetaResult != META_SUCCESS)
        {
            bAnyOperationFail = true;
            goto End;
        }

End:
        if (m_bStopBeforeUSBInsert == true)
        {
            UpdateProgress(0.0);
            UpdateUIMsg("...");
        }
        else
        {
            if (bAnyOperationFail)
            {
                m_Process->SendMessage(PBM_SETBARCOLOR, 0, RGB(255, 0, 0));
                UpdateUICountResult(FAIL);
            }
            else
            {
                UpdateUIMsg("All Operate successfully!!");
                MTRACE(g_hEBOOT_DEBUG, "FeaturePhoneSN::All Operate successfully!!");
#ifdef _AUTO_GEN_FEATURE_
                if (g_AutoGenData.bEnableAutoGen)
                {
                    UpdateAutoGenParaToSetupFile();
                }
#endif
                UpdateUICountResult(PASS);
            }

            ExitModemMeta();

            UpdateProgress(1.0);
        }

        EnableStartBTN(true);
        MTRACE(g_hEBOOT_DEBUG, "------------------------------------ END -------------------------------------");
        DebugOnOff(false);
    }

    g_sMetaComm.sWriteOption.bWriteBT = bWriteBT;
    g_sMetaComm.sWriteOption.bWriteWifi = bWriteWifi;

    if (g_sMetaComm.bSwithTool)
        DisableUSBSwitch();

    MetaHandle_DeInit();
    UpdateMainDlgUI(true, CANCEL);
}
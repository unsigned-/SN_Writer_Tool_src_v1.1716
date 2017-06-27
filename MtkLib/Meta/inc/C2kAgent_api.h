#ifndef _C2KAGENT_API_H_
#define _C2KAGENT_API_H_

#include "meta.h"
#include "C2kAgent_api_datatype.h"
#ifdef __cplusplus
extern "C" {
#endif

/*************************** Functions Declaration ****************************/
int __stdcall META_C2K_GetDLLVer(unsigned int* major_ver, unsigned int* minor_ver, unsigned int* build_num, unsigned int* patch_num);
const char* __stdcall META_C2K_GetErrorString(const int metaHandle);
META_RESULT __stdcall META_C2K_Init(const int metaHandle, C2K_LIBCONFIGPARMS* libConfig, PHONEATTRIBUTE_PARMS* phoneAttr);
META_RESULT __stdcall META_C2K_DeInit(const int metaHandle);
META_RESULT __stdcall META_C2K_ConnectWithTarget(unsigned int msTimeout, C2K_CONNECT_PARAMS* connectReq);
META_RESULT __stdcall META_C2K_ConnectWithTarget_r(const int metaHandle, unsigned int msTimeout, C2K_CONNECT_PARAMS* connectReq);
META_RESULT __stdcall META_C2K_DisconnectWithTarget(void);
META_RESULT __stdcall META_C2K_DisconnectWithTarget_r(const int metaHandle);
META_RESULT __stdcall META_C2K_LoadMessage(char* PathName);
META_RESULT __stdcall META_C2K_LoadMessage_r(const int metaHandle, char* PathName);
META_RESULT __stdcall META_C2K_LoadLogFilter(char* PathName);
META_RESULT __stdcall META_C2K_LoadLogFilter_r(const int metaHandle, char* PathName);

META_RESULT __stdcall META_C2K_SetSpi(unsigned int msTimeout, C2K_SPI_TYPE spiType, unsigned int spiAddress, unsigned int spiData);
META_RESULT __stdcall META_C2K_SetSpi_r(const int metaHandle, unsigned int msTimeout, C2K_SPI_TYPE spiType, unsigned int spiAddress, unsigned int spiData);
META_RESULT __stdcall META_C2K_GetSpi(unsigned int msTimeout, C2K_SPI_TYPE spiType, unsigned int spiAddress, unsigned int* spiData);
META_RESULT __stdcall META_C2K_GetSpi_r(const int metaHandle, unsigned int msTimeout, C2K_SPI_TYPE spiType, unsigned int spiAddress, unsigned int* spiData);
META_RESULT __stdcall META_C2K_LogIq(unsigned int msTimeout, LOG_IQ_REQ* req);
META_RESULT __stdcall META_C2K_LogIq_r(const int metaHandle, unsigned int msTimeout, LOG_IQ_REQ* req);
META_RESULT __stdcall META_C2K_GetTemperatureAdc(unsigned int msTimeout, unsigned short* adcValue);
META_RESULT __stdcall META_C2K_GetTemperatureAdc_r(const int metaHandle, unsigned int msTimeout, unsigned short* adcValue);
META_RESULT __stdcall META_C2K_TransmitterCtrl(unsigned int msTimeout, bool enable, C2K_RF_MODE rfMode, unsigned int band, unsigned short channel);
META_RESULT __stdcall META_C2K_TransmitterCtrl_r(const int metaHandle, unsigned int msTimeout, bool enable, C2K_RF_MODE rfMode, unsigned int band, unsigned short channel);
META_RESULT __stdcall META_C2K_ReceiverCtrl(unsigned int msTimeout, bool enable, C2K_RF_MODE rfMode, unsigned int rxPathBitmap, unsigned int band, unsigned short channel);
META_RESULT __stdcall META_C2K_ReceiverCtrl_r(const int metaHandle, unsigned int msTimeout, bool enable, C2K_RF_MODE rfMode, unsigned int rxPathBitmap, unsigned int band, unsigned short channel);
META_RESULT __stdcall META_C2K_AfcConfig(unsigned int msTimeout, C2K_RF_MODE rfMode, unsigned int ctrlMode, bool capIdValid, unsigned short capId, bool dacValid, unsigned short initDac);
META_RESULT __stdcall META_C2K_AfcConfig_r(const int metaHandle, unsigned int msTimeout, C2K_RF_MODE rfMode, unsigned int ctrlMode, bool capIdValid, unsigned short capId, bool dacValid, unsigned short initDac);
META_RESULT __stdcall META_C2K_AfcGetParam(unsigned int msTimeout, C2K_RF_MODE rfMode, unsigned short* capId, unsigned short* initDac);
META_RESULT __stdcall META_C2K_AfcGetParam_r(const int metaHandle, unsigned int msTimeout, C2K_RF_MODE rfMode, unsigned short* capId, unsigned short* initDac);
META_RESULT __stdcall META_C2K_TxTone(unsigned int msTimeout, bool enable, unsigned int* frequencyHz);
META_RESULT __stdcall META_C2K_TxTone_r(const int metaHandle, unsigned int msTimeout, bool enable, unsigned int* frequencyHz);
META_RESULT __stdcall META_C2K_TxCdma(unsigned int msTimeout, bool enable, C2K_RF_MODE rfMode);
META_RESULT __stdcall META_C2K_TxCdma_r(const int metaHandle, unsigned int  msTimeout, bool enable, C2K_RF_MODE rfMode);
META_RESULT __stdcall META_C2K_TxAgcConfig(unsigned int msTimeout, TXAGC_CONFIG_REQ* req);
META_RESULT __stdcall META_C2K_TxAgcConfig_r(const int metaHandle, unsigned int msTimeout, TXAGC_CONFIG_REQ* req);
META_RESULT __stdcall META_C2K_ReadCurrentTxPower(unsigned int msTimeout, short* pdPower);
META_RESULT __stdcall META_C2K_ReadCurrentTxPower_r(const int metaHandle, unsigned int msTimeout, double* pdPower);
META_RESULT __stdcall META_C2K_RxAgcSetGain(unsigned int msTimeout, unsigned int ctrlMode, C2K_RF_MODE rfMode, unsigned int rxPathBitmap, unsigned int lnaMode, double cellPower);
META_RESULT __stdcall META_C2K_RxAgcSetGain_r(const int metaHandle, unsigned int msTimeout, unsigned int ctrlMode, C2K_RF_MODE rfMode, unsigned int rxPathBitmap, unsigned int lnaMode, double cellPower);
META_RESULT __stdcall META_C2K_FhcStart(unsigned int msTimeout, C2K_FHC_REQ* fhcReq, C2K_FHC_CNF* fhcCnf);
META_RESULT __stdcall META_C2K_FhcStart_r(const int metaHandle, unsigned int msTimeout, C2K_FHC_REQ* fhcReq, C2K_FHC_CNF* fhcCnf);
META_RESULT __stdcall META_C2K_EnableRxTxSpy(unsigned int msTimeout, bool enable);
META_RESULT __stdcall META_C2K_EnableRxTxSpy_r(const int metaHandle, unsigned int msTimeout, bool enable);
META_RESULT __stdcall META_C2K_Rssi(unsigned int msTimeout, int rssiCount, C2K_RSSI_CNF* rssiCnf);
META_RESULT __stdcall META_C2K_Rssi_r(const int metaHandle, unsigned int msTimeout, int rssiCount, C2K_RSSI_CNF* rssiCnf);
META_RESULT __stdcall META_C2K_QueryTargetCapability(unsigned int msTimeout, C2K_MS_CAPABILITY* msCapability);
META_RESULT __stdcall META_C2K_QueryTargetCapability_r(const int metaHandle, unsigned int msTimeout, C2K_MS_CAPABILITY* msCapability);
META_RESULT __stdcall META_C2K_PsPower(unsigned int msTimeout, bool enable);
META_RESULT __stdcall META_C2K_PsPower_r(const int metaHandle, unsigned int msTimeout, bool enable);
META_RESULT __stdcall META_C2K_MPATestRelease(unsigned int msTimeout);
META_RESULT __stdcall META_C2K_MPATestRelease_r(const int metaHandle, unsigned int msTimeout);
META_RESULT __stdcall META_C2K_NsftSetTestMode(unsigned int msTimeout);
META_RESULT __stdcall META_C2K_NsftSetTestMode_r(const int metaHandle, unsigned int msTimeout);
META_RESULT __stdcall META_C2K_NsftPowerUp(unsigned int msTimeout, unsigned int band, unsigned short channel, unsigned int walshCode, unsigned int rc, unsigned int numFrames, bool afcEnable);
META_RESULT __stdcall META_C2K_NsftPowerUp_r(const int metaHandle, unsigned int msTimeout, unsigned int band, unsigned short channel, unsigned int walshCode, unsigned int rc, unsigned int numFrames, bool afcEnable);
META_RESULT __stdcall META_C2K_NsftTxTrafficChannel(unsigned int msTimeout, unsigned int rc, unsigned int powerCtrlMode, double txPower);
META_RESULT __stdcall META_C2K_NsftTxTrafficChannel_r(const int metaHandle, unsigned int msTimeout, unsigned int rc, unsigned int powerCtrlMode, double txPower);
META_RESULT __stdcall META_C2K_NsftGetFer(unsigned int msTimeout, unsigned int* badFrames, unsigned int* totalFrames);
META_RESULT __stdcall META_C2K_NsftGetFer_r(const int metaHandle, unsigned int msTimeout, unsigned int* badFrames, unsigned int* totalFrames);
META_RESULT __stdcall META_C2K_NsftExitTestMode(unsigned int msTimeout);
META_RESULT __stdcall META_C2K_NsftExitTestMode_r(const int metaHandle, unsigned int msTimeout);
META_RESULT __stdcall META_C2K_NsftListModeStart(unsigned int msTimeout, NSTLISTMODE_PARMS* listModeParam);
META_RESULT __stdcall META_C2K_NsftListModeStart_r(const int metaHandle, unsigned int msTimeout, NSTLISTMODE_PARMS* listModeParam);
META_RESULT __stdcall META_C2K_NsftListModeGetFer(unsigned int msTimeout, unsigned int* count, unsigned int badFrames[], unsigned int totalFrames[]);
META_RESULT __stdcall META_C2K_NsftListModeGetFer_r(const int metaHandle, unsigned int msTimeout, unsigned int* count, unsigned int badFrames[], unsigned int totalFrames[]);

META_RESULT __stdcall META_C2K_ReadNvram(unsigned int msTimeout, unsigned int band, C2K_DB_SEGMENT dbSeg, void* buf, unsigned int len);
META_RESULT __stdcall META_C2K_ReadNvram_r(const int metaHandle, unsigned int msTimeout, unsigned int band, C2K_DB_SEGMENT dbSeg, void* buf, unsigned int len);
META_RESULT __stdcall META_C2K_WriteNvram(unsigned int msTimeout, unsigned int band, C2K_DB_SEGMENT dbSeg, void* buf, unsigned int len);
META_RESULT __stdcall META_C2K_WriteNvram_r(const int metaHandle, unsigned int msTimeout, unsigned int band, C2K_DB_SEGMENT dbSeg, void* buf, unsigned int len);
META_RESULT __stdcall META_C2K_ClearRfNvram(unsigned int msTimeout);
META_RESULT __stdcall META_C2K_ClearRfNvram_r(const int metaHandle, unsigned int msTimeout);
META_RESULT __stdcall META_C2K_CalInitNvram(unsigned int msTimeout, unsigned int mode);
META_RESULT __stdcall META_C2K_CalInitNvram_r(const int metaHandle, unsigned int msTimeout, unsigned int mode);
META_RESULT __stdcall META_C2K_FlushNvram(unsigned int msTimeout);
META_RESULT __stdcall META_C2K_FlushNvram_r(const int metaHandle, unsigned int msTimeout);

META_RESULT __stdcall META_C2K_CheckSIM1Inserted(unsigned int msTimeout, unsigned char* inserted);
META_RESULT __stdcall META_C2K_CheckSIM1Inserted_r(const int metaHandle, unsigned int msTimeout, unsigned char* inserted);
META_RESULT __stdcall META_C2K_CheckSIM2Inserted(unsigned int msTimeout, unsigned char* inserted);
META_RESULT __stdcall META_C2K_CheckSIM2Inserted_r(const int metaHandle, unsigned int msTimeout, unsigned char* inserted);

META_RESULT __stdcall META_C2K_SendCommand_r(const int metaHandle, unsigned short msgId, char* buffer, int size);
META_RESULT __stdcall META_C2K_WaitResponse_r(const int metaHandle, unsigned int msTimeout, unsigned short rspId, char* buffer, int size);
META_RESULT __stdcall META_C2K_ChangeBaudrate_r(const int metaHandle, int baudrate);
META_RESULT __stdcall META_C2K_SetCalibrationFlag_r(const int metaHandle, unsigned int msTimeout, int flag);
META_RESULT __stdcall META_C2K_GetCalibrationFlag_r(const int metaHandle, unsigned int msTimeout, int* flag);
META_RESULT __stdcall META_C2K_LoopbackTest_r(const int metaHandle, unsigned int msTimeout, unsigned char value);
META_RESULT __stdcall META_C2K_ReadCurrentTemperature_r(const int metaHandle, unsigned int msTimeout, unsigned char txPath, short* temperature);
META_RESULT __stdcall META_C2K_PocCalibration_r(const int metaHandle, unsigned int msTimeout, unsigned int calFlag, unsigned int* pocDataSize);
META_RESULT __stdcall META_C2K_ReadNvramEx_r(const int metaHandle, unsigned int msTimeout, const char* lid, unsigned short rid, void* buf, unsigned int size);
META_RESULT __stdcall META_C2K_WriteNvramEx_r(const int metaHandle, unsigned int msTimeout, const char* lid, unsigned short rid, void* buf, unsigned int size);
META_RESULT __stdcall META_C2K_CalInitNvramEx_r(const int metaHandle, unsigned int msTimeout, unsigned int mode, C2K_NVRAM_TYPE type);
META_RESULT __stdcall META_C2K_ReadCurrentTxPowerEx_r(const int metaHandle, unsigned int msTimeout, C2K_RF_MODE rfMode, double* pdPower);
META_RESULT __stdcall META_C2K_AfcConfigEx_r(const int metaHandle, unsigned int msTimeout, AFC_CONFIG_REQ* req);
META_RESULT __stdcall META_C2K_SendATCommand_r(const int metaHandle, unsigned int msTimeout, char* atCmd);
META_RESULT __stdcall META_C2K_SetLoggingRelay_r(const int metaHandle, bool enable);
META_RESULT __stdcall META_C2K_ReadMipi_r(const int metaHandle, unsigned int msTimeout, unsigned int rfIdx, unsigned char mipiPort, unsigned int mipiUsid, unsigned int mipiAddress, unsigned int* mipiData);
META_RESULT __stdcall META_C2K_WriteMipi_r(const int metaHandle, unsigned int msTimeout, unsigned int rfIdx, unsigned char mipiPort, unsigned int mipiUsid, unsigned int mipiAddress, unsigned int mipiData);
META_RESULT __stdcall META_C2K_GetTargetVerInfo_r(const int metaHandle, unsigned int msTimeout, C2K_VER_INFO* verInfo);
META_RESULT __stdcall META_C2K_NsftRssi_r(const int metaHandle, unsigned int msTimeout, unsigned int band, unsigned short channel, C2K_NSFT_RSSI_CNF* cnf);
META_RESULT __stdcall META_C2K_NsftListModeRssi_r(const int metaHandle, unsigned int msTimeout, C2K_NSFT_LIST_MODE_RSSI_CNF* cnf);
META_RESULT __stdcall META_C2K_DebugOn_With_FilePath(const char* filename);
META_RESULT __stdcall META_C2K_GetTemperatureAdcEx_r(const int metaHandle, unsigned int msTimeout, unsigned int rfIdx, unsigned short* adcValue);
META_RESULT __stdcall META_C2K_NsftListModeSetPower_r(const int metaHandle, unsigned int msTimeout, C2K_NSFT_LIST_MODE_SET_POWER_REQ* req);

/*************************** GEN93 Functions Declaration ****************************/
META_RESULT __stdcall META_MMC2K_SetTargetGenType_r(const int metaHandle, unsigned int type);
META_RESULT __stdcall META_MMC2K_GetTargetGenType_r(const int metaHandle, unsigned int* type);
META_RESULT __stdcall META_MMC2K_RegisterHandler_r(const int metaHandle);
META_RESULT __stdcall META_MMC2K_SendCommand_r(const int metaHandle, unsigned int msTimeout, unsigned short reqId, const char* req, unsigned int reqLen, char* cnf, unsigned int cnfLen);
META_RESULT __stdcall META_MMC2K_QueryTargetCapability_r(const int metaHandle, unsigned int msTimeout, C2kMsCapability* msCapability);
META_RESULT __stdcall META_MMC2K_SetMIPICodeWord_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdSetMIPICodeWord* req);
META_RESULT __stdcall META_MMC2K_GetMIPICodeWord_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdGetMIPICodeWord* req, C2kTestResultGetMIPICodeWord* cnf);
META_RESULT __stdcall META_MMC2K_SetBSI_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdSetBSI* req);
META_RESULT __stdcall META_MMC2K_GetBSI_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdGetBSI* req, C2kTestResultGetBSI* cnf);
META_RESULT __stdcall META_MMC2K_TxControl_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdTxControl* req);
META_RESULT __stdcall META_MMC2K_RxControl_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdRxControl* req);
META_RESULT __stdcall META_MMC2K_AfcConfig_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdAfcConfig* req);
META_RESULT __stdcall META_MMC2K_TxAgcConfig_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdTxAgcConfig* req);
META_RESULT __stdcall META_MMC2K_GetPowerDetectorResult_r(const int metaHandle, unsigned int msTimeout, double* power);
META_RESULT __stdcall META_MMC2K_RxAgcConfig_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdRxAgcConfig* req);
META_RESULT __stdcall META_MMC2K_Rssi_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdRssi* req, C2kTestResultRssi* cnf);
META_RESULT __stdcall META_MMC2K_SetAfcData_r(const int metaHandle, unsigned int msTimeout, bool updateNvram, const C2kTestCmdGetSetAfcData* req);
META_RESULT __stdcall META_MMC2K_GetAfcData_r(const int metaHandle, unsigned int msTimeout, C2kTestCmdGetSetAfcData* cnf);
META_RESULT __stdcall META_MMC2K_SetTxData_r(const int metaHandle, unsigned int msTimeout, bool updateNvram, unsigned int band, unsigned int mode, const C2kTestCmdGetSetTxData* req);
META_RESULT __stdcall META_MMC2K_GetTxData_r(const int metaHandle, unsigned int msTimeout, unsigned int band, unsigned int mode, C2kTestCmdGetSetTxData* cnf);
META_RESULT __stdcall META_MMC2K_SetRxData_r(const int metaHandle, unsigned int msTimeout, bool updateNvram, unsigned int band, unsigned int path, const C2kTestCmdGetSetRxData* req);
META_RESULT __stdcall META_MMC2K_GetRxData_r(const int metaHandle, unsigned int msTimeout, unsigned int band, unsigned int path, C2kTestCmdGetSetRxData* cnf);
META_RESULT __stdcall META_MMC2K_SetDpdPaData_r(const int metaHandle, unsigned int msTimeout, bool updateNvram, unsigned int band, unsigned int mode, const C2kTestCmdGetSetDpdPaData* req);
META_RESULT __stdcall META_MMC2K_GetDpdPaData_r(const int metaHandle, unsigned int msTimeout, unsigned int band, unsigned int mode, C2kTestCmdGetSetDpdPaData* cnf);
META_RESULT __stdcall META_MMC2K_SetDpdAmPmData_r(const int metaHandle, unsigned int msTimeout, bool updateNvram, unsigned int band, const C2kTestCmdGetSetDpdAmPmData* req);
META_RESULT __stdcall META_MMC2K_GetDpdAmPmData_r(const int metaHandle, unsigned int msTimeout, unsigned int band, C2kTestCmdGetSetDpdAmPmData* cnf);
META_RESULT __stdcall META_MMC2K_StartFhc_r(const int metaHandle, unsigned int msTimeout, const C2kTestCmdFhc* req, C2kTestResultFhc* cnf);
META_RESULT __stdcall META_MMC2K_InitRfDriver_r(const int metaHandle, unsigned int msTimeout);
META_RESULT __stdcall META_MMC2K_UbinModeSetup_r(const int metaHandle, unsigned int msTimeout, const unsigned char mode);
META_RESULT __stdcall META_MMC2K_SetMeid_r(const int metaHandle, unsigned int msTimeout, C2kTestCmdGetSetMeid* req);
META_RESULT __stdcall META_MMC2K_GetMeid_r(const int metaHandle, unsigned int msTimeout, C2kTestCmdGetSetMeid* cnf);

META_RESULT __stdcall META_MMC2K_NsftEnterTestMode_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdTestMode* req, C2kNsftResultStatus* cnf);
META_RESULT __stdcall META_MMC2K_NsftExitTestMode_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdTestMode* req, C2kNsftResultStatus* cnf);
META_RESULT __stdcall META_MMC2K_NsftPowerUp_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdPowerUp* req, C2kNsftResultStatus* cnf);
META_RESULT __stdcall META_MMC2K_NsftSetTxPower_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdSetTxPower* req, C2kNsftResultStatus* cnf);
META_RESULT __stdcall META_MMC2K_NsftGetFer_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdFer* req, C2kNsftResultFer* cnf);
META_RESULT __stdcall META_MMC2K_NsftGetRssi_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdRssi* req, C2kNsftResultRssi* cnf);
META_RESULT __stdcall META_MMC2K_NsftListMode_r(const int metaHandle, unsigned int msTimeout, const C2kNsftCmdListMode* req, C2kNsftResultListMode* cnf);

#ifdef __cplusplus
}
#endif

#endif

#ifndef _FP_EXC_H_
#define _FP_EXC_H_

#define _NEW_META_API_
#include "SNbase.h"

class FeaturePhoneSN : public SNBase
{
public:
    FeaturePhoneSN();
    virtual ~FeaturePhoneSN();
    
protected:
    virtual void SetupMetaModeParameters();
    virtual void ThreadMainEntryPoint();
    
    virtual META_RESULT MetaHandle_Init();  
    virtual void MetaHandle_DeInit();
    virtual META_RESULT ModemMetaHandle_Init();    
    virtual void ModemMetaHandle_DeInit();

    virtual META_RESULT EnterModemMeta();
    virtual META_RESULT ExitModemMeta();

    virtual META_RESULT LoadModemDatabase(int MDindex);

    virtual META_RESULT REQ_ReadModem_NVRAM_Start(WriteData_Type_e dataType, char *pOutData, unsigned short iRID);
    virtual META_RESULT REQ_WriteModem_NVRAM_Start(WriteData_Type_e dataType, char *pInData, unsigned short iRID);   
    virtual META_RESULT REQ_BackupNvram2SDS_Start();
    virtual META_RESULT WriteNvramLoop();
};

#endif
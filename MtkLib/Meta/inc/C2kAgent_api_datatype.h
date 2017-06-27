#ifndef _C2KAGENT_API_DATATYPE_H_
#define _C2KAGENT_API_DATATYPE_H_

#define C2K_BAND_SUPPORT_BC0             (1<<0)
#define C2K_BAND_SUPPORT_BC1             (1<<1)
#define C2K_BAND_SUPPORT_BC2             (1<<2)
#define C2K_BAND_SUPPORT_BC3             (1<<3)
#define C2K_BAND_SUPPORT_BC4             (1<<4)
#define C2K_BAND_SUPPORT_BC5             (1<<5)
#define C2K_BAND_SUPPORT_BC6             (1<<6)
#define C2K_BAND_SUPPORT_BC7             (1<<7)
#define C2K_BAND_SUPPORT_BC8             (1<<8)
#define C2K_BAND_SUPPORT_BC9             (1<<9)
#define C2K_BAND_SUPPORT_BC10            (1<<10)
#define C2K_BAND_SUPPORT_BC11            (1<<11)
#define C2K_BAND_SUPPORT_BC12            (1<<12)
#define C2K_BAND_SUPPORT_BC13            (1<<13)
#define C2K_BAND_SUPPORT_BC14            (1<<14)
#define C2K_BAND_SUPPORT_BC15            (1<<15)

#define C2K_SUPPORT_BAND_COUNT           16

#define C2K_RF_ID_UNKNOWN                0x00000000
#define C2K_RF_ID_MT6158                 0x00000003
#define C2K_RF_ID_MT6176                 0x00000004
#define C2K_RF_ID_MT6179                 0x00000005

#define C2K_LNA_MODE_NUM                 8
#define C2K_NSFT_LIST_MODE_NUM           50
#define C2K_TX_POWER_BACKOFF_NUM         2
#define C2K_FREQ_COMP_NUM                16
#define C2K_TEMP_COMP_NUM                8
#define C2K_PA_SECTION_NUM               8

#define C2K_FHC_MAX_STEP                 2000
#define C2K_FHC_RX_HIGH_POWER_MODE       0x00
#define C2K_FHC_RX_LOW_POWER_MODE        0x08
#define C2K_FHC_RX_MAIN_DIV              0x30
#define C2K_FHC_RX_MAIN_SHDR             0x50
#define C2K_FHC_RX_SHDR                  0x40

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    C2K_COM_SERIAL,
    C2K_COM_USB,
    C2K_COM_USBLTE,
    C2K_COM_VC
}
C2K_COM_TYPE;

typedef enum
{
    C2K_RX_CAL_MAIN_DIV,
    C2K_RX_CAL_MAIN,
    C2K_RX_CAL_DIV
} C2K_RX_CALIBRATION_TYPE;

typedef enum
{
    C2K_AFC_TCXO,
    C2K_AFC_DCXO
} C2K_AFC_CONTROL_MODE;

typedef enum
{
    C2K_TX_SPI,
    C2K_RX_SPI
} C2K_SPI_TYPE;

typedef enum
{
    C2K_RF_MODE_1XRTT,
    C2K_RF_MODE_EVDO,
    C2K_RF_MODE_BOTH
} C2K_RF_MODE;

typedef enum
{
    C2K_CTRL_MODE_AUTO,
    C2K_CTRL_MODE_DISABLE,
    C2K_CTRL_MODE_MANUAL
} C2K_CTRL_MODE;

typedef enum
{
    C2K_LNA_MODE_HIGH,
    C2K_LNA_MODE_MIDDLE,
    C2K_LNA_MODE_LOW
} C2K_LNA_MODE;

// For SIDB access mode
typedef enum
{
    C2K_SIDB_FSI,
    C2K_SIDB_FFS
} C2K_SIDB_ACCESS_MODE;

typedef enum
{
    C2K_NVRAM_RF_PARAM,
    C2K_NVRAM_RF_CAL,
    C2K_NVRAM_MIPI,
    C2K_NVRAM_POC
} C2K_NVRAM_TYPE;

typedef enum
{
    // OrionC DB segments
    C2K_DB_AFC,
    C2K_DB_TEMPERATURE,
    C2K_DB_TXAGC,
    C2K_DB_TXAGC_FREQ_ADJ,
    C2K_DB_TXAGC_TEMP_ADJ,
    C2K_DB_TX_COUPLE_LOSS,
    C2K_DB_TX_COUPLE_LOSS_FREQ_ADJ,
    C2K_DB_RXAGC_FREQ_ADJ,
    C2K_DB_RXAGC_TEMP_ADJ,
    C2K_DB_DIV_RXAGC_FREQ_ADJ,
    C2K_DB_DIV_RXAGC_TEMP_ADJ,
    C2K_DB_RF_VERSION,
    C2K_DB_MEID,
    C2K_DB_CUSTOM_DATA,
    C2K_DB_TAS_DATA,
    //MT6176 LID
    C2K_LID_POC_DATA,
    C2K_LID_AFC,
    C2K_LID_TEMPERATURE,
    C2K_LID_RX_LOSS_HIGH_POWER,
    C2K_LID_RX_DIV_LOSS_HIGH_POWER,
    C2K_LID_RX_SHDR_LOSS_HIGH_POWER,
    C2K_LID_RX_LOSS_LOW_POWER,
    C2K_LID_RX_DIV_LOSS_LOW_POWER,
    C2K_LID_RX_SHDR_LOSS_LOW_POWER,
    C2K_LID_TX_APC,
    C2K_LID_TX_COUPLER_LOSS,
    C2K_LID_TX_PA_GAIN_COMP,
    C2K_LID_TX_COUPLER_LOSS_COMP,
    C2K_LID_TX_PA_GAIN_COMP_1XRTT,
    C2K_LID_TX_COUPLER_LOSS_COMP_1XRTT,
    C2K_LID_AFC_S_CURVE,
    C2K_LID_TX_POWER_BACKOFF,
    C2K_LID_AGPS_GROUP_DELAY,
    C2K_LID_TEMPERATURE_2
} C2K_DB_SEGMENT;


typedef struct
{
    BOOL bLog;
    char* szLogPath;
    BOOL bScript;
    char* szScriptPath;
} C2K_LIBCONFIGPARMS, *LPC2K_LIBCONFIGPARMS;

typedef struct
{
    C2K_AFC_CONTROL_MODE eAfcControlMode;
    C2K_RF_MODE eRfMode;
    C2K_RX_CALIBRATION_TYPE eRxCalibrationType;
    C2K_SIDB_ACCESS_MODE eSidbAccessMode;
    BOOL bWriteSIDBFlag;
    UINT uBarcodeLength;
    UINT uPllSettleTime;
    UINT uRxCtrlSettleTime;
    UINT uRxGainStateSettleTime;
    UINT uRxAGCGainTableSelectSettleTime;
    UINT uEnableRxTxSpySettleTime;
    UINT uTxCtrlSettleTime;
    UINT uTxTestRateSettleTime;
    UINT uTxAGCConfigSettleTime;
    BOOL bAFCSlopeStepPerPpmWithQ6;
} PHONEATTRIBUTE_PARMS, *LPPHONEATTRIBUTE_PARMS;

typedef struct
{
    C2K_COM_TYPE eComType;
    UINT uComNum;
} C2K_CONNECT_PARAMS, *LPC2K_CONNECT_PARMS;

typedef struct
{
    unsigned int bandSupport;
    unsigned int rxdBandSupport; //RX diversity band support
    unsigned int rxdEnabled;
    unsigned int paOctLevel; //PA 8 level control or not, 1: 8 levels, 0: 25 levels
    unsigned int rfId; //RF chip ID
    unsigned char cpMajor;
    unsigned char cpMinor;
    unsigned char cpRev;
} C2K_MS_CAPABILITY;

typedef struct
{
    unsigned char ucAction; //0: off, 1: on
    unsigned char ucRfMode; //0: 1xRTT, 1: EVDO, 2: SHDR
    unsigned char ucAntennaBitmap; //Bit0: Rx main, Bit1: Rx diversity, Bit2: Tx path; 0: invalid, 1: valid
    unsigned char ucSampleRate; //0: 8x, 1: 4x, 2: 2x, 3: 1x
    unsigned char ucLogMode; //0: assert mode, 1: period mode
    unsigned short usLogPeriod; //unit: half slot or half PCG
    unsigned short usLogOffset1; //unit: half slot or half PCG
    unsigned short usLogOffset2; //unit: chip
    unsigned short usLogLength1; //unit: half slot or half PCG
    unsigned short usLogLength2; //unit: chip
} LOG_IQ_REQ;

typedef struct
{
    C2K_RF_MODE rfMode;
    C2K_CTRL_MODE ctrlMode;
    unsigned char ucPaMode; //0: high, 1: middle, 2: low
    double prf;
    double paGain;
    double coupleLoss;
    unsigned char ucVm1;
    unsigned char ucVm2;
    unsigned short usVoltCtrl; //unit: mV
    unsigned short ddpcCtrl; //0: bypass DDPC, 6: enable DDPC loop, 7: enable DDPC measurement
} TXAGC_CONFIG_REQ;

typedef struct
{
    double dMainPower;
    double dMainDigiGain;
    int nMainBitSel;
    int nMainDigiGain;
    int nMainGainState;
    double dDivPower;
    double dDivDigiGain;
    int nDivBitSel;
    int nDivDigiGain;
    int nDivGainState;
} C2K_RSSI_CNF;

typedef struct
{
    unsigned short nTxRxDelay; //unit: us
    unsigned short nTxStepLength; //unit: us
    unsigned short nTxRetuneLength; //unit: us
    unsigned short nRxStepLength; //unit: us
    unsigned short nRxRetuneLength; //unit: us
    unsigned char caVm1[22][3];
    unsigned char caVm2[22][3];
    unsigned short naVoltCtrl[22][8]; //unit: mV
} FHC_COMMON_REQ;

typedef struct
{
    unsigned char cRetuneInd;
    unsigned char cBand;
    unsigned short nChannel;
    unsigned char cPaMode; //PA mode: 0:high, 1:middle, 2:low
    unsigned char cSectionIndex; //PA section index
    double prf;
    double paGain;
    double coupleLoss;
} FHC_TX_FREQ_STEP;

typedef struct
{
    unsigned short usTxStepNum;
    FHC_TX_FREQ_STEP txFreqSteps[C2K_FHC_MAX_STEP];
} FHC_TX_REQ;

typedef struct
{
    unsigned char cRetuneInd;
    unsigned char cBand;
    unsigned short nChannel;
    unsigned char cLnaMode; //0:high, 1:middle, 2:low
    double cellPower;
} FHC_RX_FREQ_STEP;

typedef struct
{
    unsigned short usRxStepNum;
    FHC_RX_FREQ_STEP rxFreqSteps[C2K_FHC_MAX_STEP];
} FHC_RX_REQ;

typedef struct
{
    unsigned char cReqType; //0: common req, 1: tx req, 2: rx req
    unsigned char cReqNum;
    unsigned char cReqIndex;
    FHC_COMMON_REQ commonReq;
    FHC_TX_REQ txReq;
    FHC_RX_REQ rxReq;
} C2K_FHC_REQ;

typedef struct
{
    unsigned short usCnfNum;
    double pdResult[C2K_FHC_MAX_STEP];
} FHC_TX_CNF;

typedef struct
{
    unsigned short usCnfNum;
    double mainDigiGain[C2K_FHC_MAX_STEP];
    double divDigiGain[C2K_FHC_MAX_STEP];
    char caTemperature[C2K_FHC_MAX_STEP]; //Centigrade
} FHC_RX_CNF;

typedef struct
{
    unsigned char cCnfId;
    unsigned char cCnfNum;
    unsigned char cCnfIndex;
    FHC_TX_CNF txCnf;
    FHC_RX_CNF rxCnf;
} C2K_FHC_CNF;

/*********** NVRAM Data Structure definition for OrionC Calibration ***********/
typedef struct
{
    unsigned int idType;
    char meid[17];
    char esn[9];
} MEID_TABLE, *LPMEID_TABLE;

typedef struct
{
    unsigned short initDacValue;
    short afcSlopeInv;
    unsigned int capId;
} AFC_TABLE_SEG, *LPAFC_TABLE_SEG;

typedef struct
{
    char tempCelsius;
    unsigned short adcValue;
} TEMPERATURE_PAIR;

typedef struct
{
    TEMPERATURE_PAIR tempPair[8];
} TEMPERATURE_TABLE_SEG, *LPTEMPERATURE_TABLE_SEG;

typedef struct
{
    unsigned short channel;
    double adjData[C2K_LNA_MODE_NUM];
} RXFREQADJ_PAIR;

typedef struct
{
    RXFREQADJ_PAIR freqAdj[16];
} RXFREQADJ_TABLE_SEG, *LPRXFREQADJ_TABLE_SEG;

typedef struct
{
    RXFREQADJ_TABLE_SEG mainTable;
    RXFREQADJ_TABLE_SEG divTable;
} RXFREQADJ_TABLE_SEG_ALL, *LPRXFREQADJ_TABLE_SEG_ALL;

typedef struct
{
    char tempCelsius;
    double adjData;
} RXTEMPADJ_PAIR;

typedef struct
{
    RXTEMPADJ_PAIR tempAdj[8];
} RXTEMPADJ_TABLE_SEG, *LPRXTEMPADJ_TABLE_SEG;

typedef struct
{
    RXTEMPADJ_TABLE_SEG mainTable;
    RXTEMPADJ_TABLE_SEG divTable;
} RXTEMPADJ_TABLE_SEG_ALL, *LPRXTEMPADJ_TABLE_SEG_ALL;

typedef struct
{
    double paGain; //dBm
    double prf; //dBm
    unsigned short paMode; //0:high, 1:middle, 2:low
    unsigned short vm1;
    unsigned short vm2;
    unsigned short voltCtrl; //mV
} PA_SECTION;

typedef struct
{
    double start; //dBm
    double end; //dBm
} TX_HYSTERESIS;

typedef struct
{
    unsigned char paSectionNum;
    PA_SECTION paSection[8];
    TX_HYSTERESIS txHyst[2];
    short paPhaseComp[3];
} TXAGC_TABLE_SEG, *LPTXAGC_TABLE_SEG;

typedef struct
{
    unsigned short channel;
    double adjData[3];
} TXFREQADJ_PAIR;

typedef struct
{
    TXFREQADJ_PAIR freqAdj[16];
} TXFREQADJ_TABLE_SEG, *LPTXFREQADJ_TABLE_SEG;

typedef struct
{
    char tempCelsius;
    double adjData[3];
} TXTEMPADJ_PAIR;

typedef struct
{
    TXTEMPADJ_PAIR tempAdj[8];
} TXTEMPADJ_TABLE_SEG, *LPTXTEMPADJ_TABLE_SEG;

typedef struct
{
    double coupleLoss[3]; //dB
} TXCOUPLELOSS_TABLE_SEG, *LPTXCOUPLELOSS_TABLE_SEG;

typedef struct
{
    unsigned short channel;
    double adjData;
} TXCOUPLELOSSFREQADJ_PAIR;

typedef struct
{
    TXCOUPLELOSSFREQADJ_PAIR freqAdj[16];
} TXCOUPLELOSSFREQADJ_TABLE_SEG, *LPTXCOUPLELOSSFREQADJ_TABLE_SEG;

typedef struct
{
    unsigned char sysBandClass;
    unsigned char supported;
    unsigned int subClass;
} SUPPORTED_BAND_CLASS_T;

typedef struct
{
    /* BAND A BPI mask */
    unsigned int MASK_BAND_A_PR1;
    unsigned int MASK_BAND_A_PR2;
    unsigned int MASK_BAND_A_PR2B;
    unsigned int MASK_BAND_A_PR3;
    unsigned int MASK_BAND_A_PR3A;
    unsigned int MASK_BAND_A_PT1;
    unsigned int MASK_BAND_A_PT2;
    unsigned int MASK_BAND_A_PT2B;
    unsigned int MASK_BAND_A_PT3;
    unsigned int MASK_BAND_A_PT3A;
    unsigned int MASK_BAND_A_RXD_PR1;
    unsigned int MASK_BAND_A_RXD_PR2;
    unsigned int MASK_BAND_A_RXD_PR2B;
    unsigned int MASK_BAND_A_RXD_PR3;
    unsigned int MASK_BAND_A_RXD_PR3A;

    /* BAND B BPI mask */
    unsigned int MASK_BAND_B_PR1;
    unsigned int MASK_BAND_B_PR2;
    unsigned int MASK_BAND_B_PR2B;
    unsigned int MASK_BAND_B_PR3;
    unsigned int MASK_BAND_B_PR3A;
    unsigned int MASK_BAND_B_PT1;
    unsigned int MASK_BAND_B_PT2;
    unsigned int MASK_BAND_B_PT2B;
    unsigned int MASK_BAND_B_PT3;
    unsigned int MASK_BAND_B_PT3A;
    unsigned int MASK_BAND_B_RXD_PR1;
    unsigned int MASK_BAND_B_RXD_PR2;
    unsigned int MASK_BAND_B_RXD_PR2B;
    unsigned int MASK_BAND_B_RXD_PR3;
    unsigned int MASK_BAND_B_RXD_PR3A;

    /* BAND C BPI mask */
    unsigned int MASK_BAND_C_PR1;
    unsigned int MASK_BAND_C_PR2;
    unsigned int MASK_BAND_C_PR2B;
    unsigned int MASK_BAND_C_PR3;
    unsigned int MASK_BAND_C_PR3A;
    unsigned int MASK_BAND_C_PT1;
    unsigned int MASK_BAND_C_PT2;
    unsigned int MASK_BAND_C_PT2B;
    unsigned int MASK_BAND_C_PT3;
    unsigned int MASK_BAND_C_PT3A;
    unsigned int MASK_BAND_C_RXD_PR1;
    unsigned int MASK_BAND_C_RXD_PR2;
    unsigned int MASK_BAND_C_RXD_PR2B;
    unsigned int MASK_BAND_C_RXD_PR3;
    unsigned int MASK_BAND_C_RXD_PR3A;

    /* Band A Gate BPI mask */
    unsigned int MASK_BAND_A_PRG1;       /* Main Rx On */
    unsigned int MASK_BAND_A_PRG2;
    unsigned int MASK_BAND_A_PRG2B;
    unsigned int MASK_BAND_A_PRG3;       /* Main Rx Off */
    unsigned int MASK_BAND_A_PRG3A;
    unsigned int MASK_BAND_A_PTG1;       /* Tx On */
    unsigned int MASK_BAND_A_PTG2;
    unsigned int MASK_BAND_A_PTG2B;
    unsigned int MASK_BAND_A_PTG3;       /* Tx Off */
    unsigned int MASK_BAND_A_PTG3A;
    unsigned int MASK_BAND_A_RXD_PRG1;   /* Diversity Rx On */
    unsigned int MASK_BAND_A_RXD_PRG2;
    unsigned int MASK_BAND_A_RXD_PRG2B;
    unsigned int MASK_BAND_A_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int MASK_BAND_A_RXD_PRG3A;

    /* Band B Gate BPI mask */
    unsigned int MASK_BAND_B_PRG1;       /* Main Rx On */
    unsigned int MASK_BAND_B_PRG2;
    unsigned int MASK_BAND_B_PRG2B;
    unsigned int MASK_BAND_B_PRG3;       /* Main Rx Off */
    unsigned int MASK_BAND_B_PRG3A;
    unsigned int MASK_BAND_B_PTG1;       /* Tx On */
    unsigned int MASK_BAND_B_PTG2;
    unsigned int MASK_BAND_B_PTG2B;
    unsigned int MASK_BAND_B_PTG3;       /* Tx Off */
    unsigned int MASK_BAND_B_PTG3A;
    unsigned int MASK_BAND_B_RXD_PRG1;   /* Diversity Rx On */
    unsigned int MASK_BAND_B_RXD_PRG2;
    unsigned int MASK_BAND_B_RXD_PRG2B;
    unsigned int MASK_BAND_B_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int MASK_BAND_B_RXD_PRG3A;

    /* Band C Gate BPI mask */
    unsigned int MASK_BAND_C_PRG1;       /* Main Rx On */
    unsigned int MASK_BAND_C_PRG2;
    unsigned int MASK_BAND_C_PRG2B;
    unsigned int MASK_BAND_C_PRG3;       /* Main Rx Off */
    unsigned int MASK_BAND_C_PRG3A;
    unsigned int MASK_BAND_C_PTG1;       /* Tx On */
    unsigned int MASK_BAND_C_PTG2;
    unsigned int MASK_BAND_C_PTG2B;
    unsigned int MASK_BAND_C_PTG3;       /* Tx Off */
    unsigned int MASK_BAND_C_PTG3A;
    unsigned int MASK_BAND_C_RXD_PRG1;   /* Diversity Rx On */
    unsigned int MASK_BAND_C_RXD_PRG2;
    unsigned int MASK_BAND_C_RXD_PRG2B;
    unsigned int MASK_BAND_C_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int MASK_BAND_C_RXD_PRG3A;

    /* Power Control mask */
    unsigned int MASK_PRPC1;       /* Main Rx On */
    unsigned int MASK_PRPC2;
    unsigned int MASK_PRPC2B;
    unsigned int MASK_PRPC3;       /* Main Rx Off */
    unsigned int MASK_PRPC3A;
    unsigned int MASK_PTPC1;       /* Tx On */
    unsigned int MASK_PTPC2;
    unsigned int MASK_PTPC2B;
    unsigned int MASK_PTPC3;       /* Tx Off */
    unsigned int MASK_PTPC3A;
    unsigned int MASK_RXD_PRPC1;   /* Diversity Rx On */
    unsigned int MASK_RXD_PRPC2;
    unsigned int MASK_RXD_PRPC2B;
    unsigned int MASK_RXD_PRPC3;   /* Diversity Rx Off */
    unsigned int MASK_RXD_PRPC3A;
} BPI_MASK_T;

typedef struct
{
    /* BAND A BPI data */
    unsigned int DATA_BAND_A_PR1;
    unsigned int DATA_BAND_A_PR2;
    unsigned int DATA_BAND_A_PR2B;
    unsigned int DATA_BAND_A_PR3;
    unsigned int DATA_BAND_A_PR3A;
    unsigned int DATA_BAND_A_PT1;
    unsigned int DATA_BAND_A_PT2;
    unsigned int DATA_BAND_A_PT2B;
    unsigned int DATA_BAND_A_PT3;
    unsigned int DATA_BAND_A_PT3A;
    unsigned int DATA_BAND_A_RXD_PR1;
    unsigned int DATA_BAND_A_RXD_PR2;
    unsigned int DATA_BAND_A_RXD_PR2B;
    unsigned int DATA_BAND_A_RXD_PR3;
    unsigned int DATA_BAND_A_RXD_PR3A;

    /* BAND B BPI data */
    unsigned int DATA_BAND_B_PR1;
    unsigned int DATA_BAND_B_PR2;
    unsigned int DATA_BAND_B_PR2B;
    unsigned int DATA_BAND_B_PR3;
    unsigned int DATA_BAND_B_PR3A;
    unsigned int DATA_BAND_B_PT1;
    unsigned int DATA_BAND_B_PT2;
    unsigned int DATA_BAND_B_PT2B;
    unsigned int DATA_BAND_B_PT3;
    unsigned int DATA_BAND_B_PT3A;
    unsigned int DATA_BAND_B_RXD_PR1;
    unsigned int DATA_BAND_B_RXD_PR2;
    unsigned int DATA_BAND_B_RXD_PR2B;
    unsigned int DATA_BAND_B_RXD_PR3;
    unsigned int DATA_BAND_B_RXD_PR3A;

    /* BAND C BPI data */
    unsigned int DATA_BAND_C_PR1;
    unsigned int DATA_BAND_C_PR2;
    unsigned int DATA_BAND_C_PR2B;
    unsigned int DATA_BAND_C_PR3;
    unsigned int DATA_BAND_C_PR3A;
    unsigned int DATA_BAND_C_PT1;
    unsigned int DATA_BAND_C_PT2;
    unsigned int DATA_BAND_C_PT2B;
    unsigned int DATA_BAND_C_PT3;
    unsigned int DATA_BAND_C_PT3A;
    unsigned int DATA_BAND_C_RXD_PR1;
    unsigned int DATA_BAND_C_RXD_PR2;
    unsigned int DATA_BAND_C_RXD_PR2B;
    unsigned int DATA_BAND_C_RXD_PR3;
    unsigned int DATA_BAND_C_RXD_PR3A;

    /* Band A TXGATE data */
    unsigned int DATA_BAND_A_PRG1;       /* Main Rx On */
    unsigned int DATA_BAND_A_PRG2;
    unsigned int DATA_BAND_A_PRG2B;
    unsigned int DATA_BAND_A_PRG3;       /* Main Rx Off */
    unsigned int DATA_BAND_A_PRG3A;
    unsigned int DATA_BAND_A_PTG1;       /* Tx On */
    unsigned int DATA_BAND_A_PTG2;
    unsigned int DATA_BAND_A_PTG2B;
    unsigned int DATA_BAND_A_PTG3;       /* Tx Off */
    unsigned int DATA_BAND_A_PTG3A;
    unsigned int DATA_BAND_A_RXD_PRG1;   /* Diversity Rx On */
    unsigned int DATA_BAND_A_RXD_PRG2;
    unsigned int DATA_BAND_A_RXD_PRG2B;
    unsigned int DATA_BAND_A_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int DATA_BAND_A_RXD_PRG3A;

    /* Band B TXGATE data */
    unsigned int DATA_BAND_B_PRG1;       /* Main Rx On */
    unsigned int DATA_BAND_B_PRG2;
    unsigned int DATA_BAND_B_PRG2B;
    unsigned int DATA_BAND_B_PRG3;       /* Main Rx Off */
    unsigned int DATA_BAND_B_PRG3A;
    unsigned int DATA_BAND_B_PTG1;       /* Tx On */
    unsigned int DATA_BAND_B_PTG2;
    unsigned int DATA_BAND_B_PTG2B;
    unsigned int DATA_BAND_B_PTG3;       /* Tx Off */
    unsigned int DATA_BAND_B_PTG3A;
    unsigned int DATA_BAND_B_RXD_PRG1;   /* Diversity Rx On */
    unsigned int DATA_BAND_B_RXD_PRG2;
    unsigned int DATA_BAND_B_RXD_PRG2B;
    unsigned int DATA_BAND_B_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int DATA_BAND_B_RXD_PRG3A;

    /* Band C TXGATE data */
    unsigned int DATA_BAND_C_PRG1;       /* Main Rx On */
    unsigned int DATA_BAND_C_PRG2;
    unsigned int DATA_BAND_C_PRG2B;
    unsigned int DATA_BAND_C_PRG3;       /* Main Rx Off */
    unsigned int DATA_BAND_C_PRG3A;
    unsigned int DATA_BAND_C_PTG1;       /* Tx On */
    unsigned int DATA_BAND_C_PTG2;
    unsigned int DATA_BAND_C_PTG2B;
    unsigned int DATA_BAND_C_PTG3;       /* Tx Off */
    unsigned int DATA_BAND_C_PTG3A;
    unsigned int DATA_BAND_C_RXD_PRG1;   /* Diversity Rx On */
    unsigned int DATA_BAND_C_RXD_PRG2;
    unsigned int DATA_BAND_C_RXD_PRG2B;
    unsigned int DATA_BAND_C_RXD_PRG3;   /* Diversity Rx Off */
    unsigned int DATA_BAND_C_RXD_PRG3A;

    /* TX Power Control data */
    unsigned int DATA_PRPC1;       /* Main Rx On */
    unsigned int DATA_PRPC2;
    unsigned int DATA_PRPC2B;
    unsigned int DATA_PRPC3;       /* Main Rx Off */
    unsigned int DATA_PRPC3A;
    unsigned int DATA_PTPC1;       /* Tx On */
    unsigned int DATA_PTPC2;
    unsigned int DATA_PTPC2B;
    unsigned int DATA_PTPC3;       /* Tx Off */
    unsigned int DATA_PTPC3A;
    unsigned int DATA_RXD_PRPC1;   /* Diversity Rx On */
    unsigned int DATA_RXD_PRPC2;
    unsigned int DATA_RXD_PRPC2B;
    unsigned int DATA_RXD_PRPC3;   /* Diversity Rx Off */
    unsigned int DATA_RXD_PRPC3A;
} BPI_DATA_T;

typedef struct
{
    // RF Window timing
    unsigned short TC_PR1;
    unsigned short TC_PR2;
    unsigned short TC_PR2B;

    unsigned short TC_PR3;
    unsigned short TC_PR3A;

    unsigned short TC_RXD_PR1;
    unsigned short TC_RXD_PR2;
    unsigned short TC_RXD_PR2B;

    unsigned short TC_RXD_PR3;
    unsigned short TC_RXD_PR3A;

    unsigned short TC_PT1;
    unsigned short TC_PT2;
    unsigned short TC_PT2B;

    unsigned short TC_PT3;
    unsigned short TC_PT3A;

    // RF Gate timing
    unsigned short TC_PRG1;
    unsigned short TC_PRG2;
    unsigned short TC_PRG2B;

    unsigned short TC_PRG3;
    unsigned short TC_PRG3A;

    unsigned short TC_RXD_PRG1;
    unsigned short TC_RXD_PRG2;
    unsigned short TC_RXD_PRG2B;

    unsigned short TC_RXD_PRG3;
    unsigned short TC_RXD_PRG3A;

    unsigned short TC_PTG1;
    unsigned short TC_PTG2;
    unsigned short TC_PTG2B;

    unsigned short TC_PTG3;
    unsigned short TC_PTG3A;

    // RF TX Power Control timing
    short TC_PRPC1;
    short TC_PRPC2;
    short TC_PRPC2B;

    short TC_PRPC3;
    short TC_PRPC3A;

    short TC_RXD_PRPC1;
    short TC_RXD_PRPC2;
    short TC_RXD_PRPC2B;

    short TC_RXD_PRPC3;
    short TC_RXD_PRPC3A;

    short TC_PTPC1;
    short TC_PTPC2;
    short TC_PTPC2B;

    short TC_PTPC3;
    short TC_PTPC3A;
} BPI_TIMING_T;

typedef struct
{
    short dc2DcSettlingTime;
} PA_TIMING_T;

typedef struct
{
    unsigned char BAND_A_CHANNEL_SEL;
    unsigned char BAND_B_CHANNEL_SEL;
    unsigned char BAND_C_CHANNEL_SEL;
} RX_LNA_PORT_SEL_T;

typedef struct
{
    unsigned char BAND_A_OUTPUT_SEL;
    unsigned char BAND_B_OUTPUT_SEL;
    unsigned char BAND_C_OUTPUT_SEL;
} TX_PATH_SEL_T;

typedef struct
{
    unsigned char structVersion; //reserved
    unsigned char isDataUpdate; //reserved
    SUPPORTED_BAND_CLASS_T supportedBand[3];
    BPI_MASK_T bpiMask;
    BPI_DATA_T bpiData;
    BPI_TIMING_T bpiTiming;
    PA_TIMING_T paTiming;
    RX_LNA_PORT_SEL_T rxLnaPortSel;
    RX_LNA_PORT_SEL_T rxDivLnaPortSel;
    TX_PATH_SEL_T txPathSel;
    unsigned char rxDiversityEnable;
    unsigned char rxDiversityTestEnable;
    unsigned char paVddPmuControlEnable;
    unsigned char paVddBattControlEnable;
    unsigned char paVddDc2DcControlEnable;
    unsigned char customTmEnable;
} CUSTOMDATA_TABLE, *LPCUSTOMDATA_TABLE;

typedef struct
{
    char rfOption[21];
    char rfDriverRev[11];
} RFVERSION_TABLE, *LPRFVERSION_TABLE;

typedef struct
{
    UINT uCount;
    bool bAFCEnable;
    UINT uIndex[C2K_NSFT_LIST_MODE_NUM];
    UINT uProtocol[C2K_NSFT_LIST_MODE_NUM];
    UINT uOffset[C2K_NSFT_LIST_MODE_NUM];
    UINT uBand[C2K_NSFT_LIST_MODE_NUM];
    UINT uChannel[C2K_NSFT_LIST_MODE_NUM];
    UINT uWashCode[C2K_NSFT_LIST_MODE_NUM];
    UINT uRadioConfig[C2K_NSFT_LIST_MODE_NUM];
    UINT uNumFrames[C2K_NSFT_LIST_MODE_NUM];
    UINT uPowerCtrlMode[C2K_NSFT_LIST_MODE_NUM];
    float fTxPower[C2K_NSFT_LIST_MODE_NUM];
} NSTLISTMODE_PARMS, *LPNSTLISTMODE_PARMS;

typedef struct
{
    unsigned char tasEnable;
    unsigned char tasInitAntIndex;
    unsigned char forceTxAntEnable;
    unsigned char forceTxAntIndex;
    unsigned int tasMask;
    unsigned int tasData[3][7];
} TASDATA_TABLE, *LPTASDATA_TABLE;

/*********** MT6176 data structure ***********/
typedef enum
{
    C2K_CAL_INIT_NVRAM,
    C2K_CAL_INIT_DEFAULT
} C2K_CAL_INIT_TYPE;

typedef enum
{
    C2K_NVRAM_DATA_RF,
    C2K_NVRAM_DATA_POC
} C2K_NVRAM_DATA_TYPE;

typedef struct
{
    unsigned short channel[16];
    char temp[8];
    double comp[8][8][16]; //[temp celsius][LNA mode][channel]
} RX_LOSS_TABLE, *LPRX_LOSS_TABLE;

typedef struct
{
    unsigned short channel[16];
    char temp[8];
    double comp[3][8][16]; //[PA mode][temp celsius][channel]
} PA_GAIN_COMP_TABLE, *LPPA_GAIN_COMP_TABLE;

typedef struct
{
    unsigned short channel[16];
    char temp[8];
    double comp[3][8][16]; //[PA mode][temp celsius][channel]
} COUPLER_LOSS_COMP_TABLE, *LPCOUPLER_LOSS_COMP_TABLE;

typedef struct
{
    C2K_RF_MODE rfMode;
    unsigned int ctrlMode;
    bool capIdValid;
    unsigned short capId;
    bool dacValid;
    unsigned short initDac;
    bool foeValid;
    short foePpb;
} AFC_CONFIG_REQ;

typedef struct
{
    double c0;
    double c1;
    double c2;
    double c3;
} S_CURVE_TABLE, *LPS_CURVE_TABLE;

typedef struct
{
    char    BB_CHIP[64];    /**< BaseBand chip version */
    char    SW_VER[100];     /**< S/W version */
    char    SW_BRANCH[64];  /**< Build branch information*/
    char    SW_FLAVOR[64];  /**< Build flavor information*/
} C2K_VER_INFO;

typedef struct
{
    short temp;
    double powerBackoff;
} TX_POWER_BACKOFF;

typedef struct
{
    TX_POWER_BACKOFF txPowerBackoff[C2K_TX_POWER_BACKOFF_NUM];
} TX_POWER_BACKOFF_TABLE, *LPTX_POWER_BACKOFF_TABLE;

typedef struct
{
    unsigned char ok;
    double rssiMain;
    double rssiRxd;
    unsigned short pnOffset;
    short strength;
} C2K_NSFT_RSSI_CNF;

typedef struct
{
    unsigned short listCount;
    unsigned short rssiCount;
    double rssiMain[C2K_NSFT_LIST_MODE_NUM][10];
    double rssiRxd[C2K_NSFT_LIST_MODE_NUM][10];
} C2K_NSFT_LIST_MODE_RSSI_CNF;

typedef struct
{
    unsigned char powerCount;
    double power[10];
} C2K_NSFT_LIST_MODE_SET_POWER_REQ;


/*************************** GEN93 data structure ****************************/
#define C2K_FHC_MAX_TX_STEP                 1000
#define C2K_FHC_MAX_RX_STEP                 1000
#define C2K_NSFT_LIST_MODE_TX_PWR_COUNT     20
#define C2K_NSFT_LIST_MODE_RSSI_COUNT       20

typedef enum
{
    C2K_TX_SIG_RF_TONE,
    C2K_TX_SIG_BB_TONE,
    C2K_TX_SIG_1xRTT,
    C2K_TX_SIG_EVDO_PILOT,
    C2K_TX_SIG_EVDO_ST2
} C2K_TX_SIG_TYPE;

typedef enum
{
    C2K_PA_TYPE_APT_MODE = 0,
    C2K_PA_TYPE_DPD_MODE
} C2K_PA_TYPE;

typedef enum
{
    C2K_POWER_CTRL_MODE_FIX = 0,
    C2K_POWER_CTRL_MODE_MANUAL
} C2K_POWER_CTRL_MODE;

typedef struct
{
    unsigned short rfId;
    unsigned short xoType;             //0: VCTCXO, 1: TSX, 2: TCXO
    unsigned int bandSupport;          //bitmap of supported band
    unsigned int rxdBandSupport;       //bitmap of RXD supported band
    unsigned int mipiBandSupport;
    unsigned int dpdBandSupport;
} C2kMsCapability;

typedef struct
{
    unsigned short mipiPort;
    unsigned short reserved;
    unsigned int mipiUsid;
    unsigned int mipiAddr;
    unsigned int mipiData;
} C2kTestCmdSetMIPICodeWord;

typedef struct
{
    unsigned short mipiPort;
    unsigned short reserved;
    unsigned int mipiUsid;
    unsigned int mipiAddr;
} C2kTestCmdGetMIPICodeWord;

typedef struct
{
    unsigned int mipiData;
} C2kTestResultGetMIPICodeWord;

typedef struct
{
    unsigned short bsiId;
    unsigned short reserved;
    unsigned int bsiAddr;
    unsigned int bsiData;
} C2kTestCmdSetBSI;

typedef struct
{
    unsigned short bsiId;
    unsigned short reserved;
    unsigned int bsiAddr;
} C2kTestCmdGetBSI;

typedef struct
{
    unsigned int bsiData;
} C2kTestResultGetBSI;

typedef struct
{
    unsigned char rc;              //reverse radio config, 0: RC1, 1: RC2, 2: RC3, 3: RC4, 4: RC5
    unsigned char chType;          //channel type, 0: access, 1: FCH, 2: FCH + SCH 
    unsigned char rate;            //0: full rate, 1: 1/2 rate, 2: 1/4 rate, 3: 1/8 rate
    unsigned short txPreamble;     //0: pilot + data, 1: pilot only
} C2k1xRTTChannelParam;
typedef struct
{
    unsigned char rfMode;          //0: 1xRTT, 1: EVDO
    unsigned char action;          //0: switch off, 1: switch on
    unsigned char sigType;         //enum C2K_TX_SIG_TYPE
    unsigned char band;            //band class 0 ~ 21
    unsigned short channel;
    unsigned short reserved;
    unsigned int frequency;        //unit: Hz, for singal tone use
    unsigned int bbTone;           //1: use baseband to generate CW tone singal
    C2k1xRTTChannelParam chParam;  //only for 1xRTT use
} C2kTestCmdTxControl;

typedef struct
{
    unsigned char rfMode;      //1: EVDO
    unsigned char action;      //0: switch off, 1: switch on
    unsigned char rxPath;      //bit0: main path, bit1: diversity path, bit2: second path
    unsigned char band;        //band class 0 ~ 21
    unsigned short channel;
    unsigned short reserved;
} C2kTestCmdRxControl;

typedef struct
{
    unsigned char ctrlMode;    //1: manual
    unsigned char capIdValid;  //0: capId not used, 1: capId used
    unsigned short capId;
    unsigned char reserved;
    unsigned char dacValid;    //0: dacValue not used, 1: dacValue used
    unsigned short dacValue;
} C2kTestCmdAfcConfig;

typedef struct
{
    unsigned char rfMode;      //0: 1xRTT, 1: EVDO
    unsigned char paType;      //0: APT mode, 1: DPD mode
    unsigned char ctrlMode;    //0: fix power, 1: manual
    unsigned char ilpcEnable;  //0: disable, 1: enable
    unsigned char paTblIndex;  //8 levels PA table index
    unsigned char paMode;      //0: high, 1: middle, 2: low
    double antennaPower;       //dBm, the power want to be transmitted at antenna port
    double txPower;            //dBm, the power of PA 8 levels
    double paGain;             //dB
    double couplerLoss;        //dB
    unsigned short am;
    unsigned short pm;
    unsigned char vm1;
    unsigned char vm2;
    unsigned short dc2dcLevel; //unit: mV
} C2kTestCmdTxAgcConfig;

typedef struct
{
    unsigned char rfMode;      //1: EVDO
    unsigned char rxPath;      //bit0: main path, bit1: diversity path, bit2: second path
    unsigned char ctrlMode;    //0: RX AGC auto loop, 1: manual
    unsigned char powerMode;   //0: high power mode, 1: low power mode
    unsigned char lnaMode;     //LNA mode index 0 ~ 7
    unsigned char reserved[3];
} C2kTestCmdRxAgcConfig;

typedef struct
{
    unsigned char rfMode;      //1: EVDO
    unsigned char rxPath;      //bit0: main path, bit1: diversity path, bit2: second path
    unsigned short reserved;
} C2kTestCmdRssi;

typedef struct
{
    double mainPower;          //main path power(dBm)
    double divPower;           //diversity/second path power(dBm)
} C2kTestResultRssi;

typedef struct
{
    unsigned short initDacValue;
    short afcSlopeInv;
    unsigned short capId;
    unsigned short reserved;
} C2kTestCmdGetSetAfcData;

typedef struct
{
    unsigned char paMode;      //0:high, 1:middle, 2:low
    short prf;
    double paGain; 
    unsigned char vm1;
    unsigned char vm2;
    unsigned short dc2dcLevel; //mV
} C2kTestPaSection;

typedef struct
{
    char hysteresisStart0;
    char hysteresisEnd0;
    char hysteresisStart1;
    char hysteresisEnd1;
    unsigned char paSectionNum;
    C2kTestPaSection paSection[C2K_PA_SECTION_NUM]; //array index is 0 to 7, TX power and PA mode is low to high
    double couplerLoss[3];
    char temperature[C2K_TEMP_COMP_NUM];
    unsigned short channel[C2K_FREQ_COMP_NUM];
    double paGainComp[C2K_PA_SECTION_NUM][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[PA section:8][temperature:8][channel:16]
    double couplerLossComp[3][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[PA mode:3][temperature:8][channel:16]
    short paPhaseComp[3];
} C2kTestCmdGetSetTxData;

typedef struct
{
    char temperature[C2K_TEMP_COMP_NUM];
    unsigned short channel[C2K_FREQ_COMP_NUM];
    double lossHpm[C2K_LNA_MODE_NUM][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[LNA mode:8][temperature:8][channel:16]
    double lossLpm[C2K_LNA_MODE_NUM][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[LNA mode:8][temperature:8][channel:16]
} C2kTestCmdGetSetRxData;

typedef struct
{
    unsigned char paControlLevel;
    unsigned char roomTempIndex;
    char hysteresisStart0;
    char hysteresisEnd0;
    char hysteresisStart1;
    char hysteresisEnd1;
    unsigned char paMode[C2K_PA_SECTION_NUM];
    short prf[C2K_PA_SECTION_NUM];
    short paGain[C2K_PA_SECTION_NUM];
    unsigned short dc2dcLevel[C2K_PA_SECTION_NUM];
    unsigned char vm1[C2K_PA_SECTION_NUM];
    unsigned char vm2[C2K_PA_SECTION_NUM];
    unsigned short channel[C2K_FREQ_COMP_NUM];
    short paGainComp[C2K_PA_SECTION_NUM][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[PA section:8][temperature:8][channel:16]
    short couplerLoss[3];
    short couplerLossComp[3][C2K_TEMP_COMP_NUM][C2K_FREQ_COMP_NUM]; //[PA mode:3][temperature:8][channel:16]
    unsigned short delay[15];
    unsigned short dpdPaArray[512];
} C2kTestCmdGetSetDpdPaData;

typedef struct
{
    unsigned short channel[C2K_FREQ_COMP_NUM];
    unsigned char lutAm[C2K_PA_SECTION_NUM][C2K_FREQ_COMP_NUM][16];
    char lutPm[C2K_PA_SECTION_NUM][C2K_FREQ_COMP_NUM][16];
    unsigned short dpdPaArray[512];
} C2kTestCmdGetSetDpdAmPmData;

typedef struct
{
    unsigned char rfMode;              //0: 1xRTT, 1: EVDO
    unsigned char stepInd;             //0: next step is normal step
                                       //1: next step is retune step
                                       //2: current step is the last step
                                       //3: next step is RF mode switch step
    unsigned char band;
    unsigned short channel;
    double txPower;                    //dBm
} FhcTxStep;

typedef struct
{
    unsigned char stepInd;             //0: next step is normal step
                                       //1: next step is retune step
                                       //2: current step is the last step
    unsigned char band;
    unsigned short channel;
    unsigned char path;                //bit0: main path, bit1: diversity path, bit2: second path
    unsigned char powerMode;           //0: high power mode, 1: low power mode
    unsigned char lnaMode;             //LNA mode index 0 ~ 7
} FhcRxStep;

typedef struct
{
    unsigned short txRxDelay;          //unit: us
    unsigned short txStepLength;       //unit: us, 1000 ~ 20000
    unsigned short txRetuneLength;     //unit: us, >=500
    unsigned short rfModeSwitchLength; //unit: us, >=1000
    unsigned short rxStepLength;       //unit: us, 1000 ~ 20000
    unsigned short rxRetuneLength;     //unit: us, >=500
    unsigned short txStepNum;
    FhcTxStep txSteps[C2K_FHC_MAX_TX_STEP];
    unsigned short rxStepNum;
    FhcRxStep rxSteps[C2K_FHC_MAX_RX_STEP];
} C2kTestCmdFhc;

typedef struct
{
    unsigned short pdNum;
    unsigned short rssiNum;
    double pdResult[C2K_FHC_MAX_TX_STEP];  //dBm
    double rssiMain[C2K_FHC_MAX_RX_STEP];  //dBm
    double rssiDiv[C2K_FHC_MAX_RX_STEP];   //dBm
} C2kTestResultFhc;

typedef struct
{
    unsigned short band;
    unsigned short channel;
    unsigned char walshCode;
    unsigned char radioConfig;
} C2kNsftCmdPowerUp;

typedef struct
{
    unsigned int status;
} C2kNsftResultStatus;

typedef struct
{
    unsigned short band;
    unsigned short channel;
    unsigned short numFrames;
    unsigned char enableAfc;
} C2kNsftCmdFer;

typedef struct
{
    unsigned int status;
    unsigned short badFrames;
    unsigned short totalFrames;
} C2kNsftResultFer;

typedef struct
{
    unsigned short band;
    unsigned short channel;
    double txPower;                    //dBm
} C2kNsftCmdSetTxPower;

typedef struct
{
    unsigned short band;
    unsigned short channel;
} C2kNsftCmdRssi;

typedef struct
{
    unsigned int status;
    unsigned short pnOffset;
    unsigned short strength;
    double mainRssi;                   //dBm
    double divRssi;                    //dBm
} C2kNsftResultRssi;

typedef struct
{
    unsigned char count;
    unsigned char offset[C2K_NSFT_LIST_MODE_NUM];
    unsigned short band[C2K_NSFT_LIST_MODE_NUM];
    unsigned short channel[C2K_NSFT_LIST_MODE_NUM];
    unsigned char walshCode[C2K_NSFT_LIST_MODE_NUM];
    unsigned char radioConfig[C2K_NSFT_LIST_MODE_NUM];
    unsigned short numFrames[C2K_NSFT_LIST_MODE_NUM];
    unsigned char txPowerCount[C2K_NSFT_LIST_MODE_NUM];
    double txPowerLevel[C2K_NSFT_LIST_MODE_NUM][C2K_NSFT_LIST_MODE_TX_PWR_COUNT]; //dBm
    unsigned char rssiCount[C2K_NSFT_LIST_MODE_NUM];
} C2kNsftCmdListMode;

typedef struct
{
    unsigned int status;
    unsigned char count;
    unsigned char index[C2K_NSFT_LIST_MODE_NUM];
    unsigned short band[C2K_NSFT_LIST_MODE_NUM];
    unsigned short channel[C2K_NSFT_LIST_MODE_NUM];
    unsigned char badFrames[C2K_NSFT_LIST_MODE_NUM];
    unsigned char totalFrames[C2K_NSFT_LIST_MODE_NUM];
    double mainRssi[C2K_NSFT_LIST_MODE_NUM][C2K_NSFT_LIST_MODE_RSSI_COUNT]; //dBm
    double divRssi[C2K_NSFT_LIST_MODE_NUM][C2K_NSFT_LIST_MODE_RSSI_COUNT];  //dBm 
} C2kNsftResultListMode;

typedef struct
{
    unsigned int reserved;
} C2kNsftCmdTestMode;

typedef struct
{
    char meid[17]; //Null-terminated 14 hexadecimal format MEID string
    char esn[9];   //Null-terminated 8 hexadecimal format ESN string, ignored in set command
} C2kTestCmdGetSetMeid;

#ifdef __cplusplus
}
#endif

#endif

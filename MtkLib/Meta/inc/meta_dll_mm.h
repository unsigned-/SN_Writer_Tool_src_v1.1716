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
 * meta_mm.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __META_MM_H__
#define __META_MM_H__
#if !defined(__GNUC__) || !defined(WIN32)
/**
 * \addtogroup Multi-Media
 *  @{
 */
//----------------------------------------------------------------//
//                            CMMB                                //
//----------------------------------------------------------------//

#define   META_CMMB_FREQ_BAND_NUM  4
#define   META_CMMB_FRAME_INFO_NUM 4

#define   META_CMMB_BLK_NUM        8
#define   META_CMMB_SERV_BLOCK_NUM   20
#define   META_CMMB_DATA_BLK_NUM     128

//--------------------------//
//    CMMB data structures  //
//--------------------------//
typedef enum
{

    META_CMMB_CHINA_U_BAND = 0,
    META_CMMB_TAIWAN_BAND = 1,
    META_CMMB_UNDEF_BAND
} META_CMMB_BAND_enum;

typedef struct
{
    META_CMMB_BAND_enum  m_rBand;

} META_CMMB_SET_BAND_REQ_T;



typedef struct
{
    unsigned char   m_u1FreqPointId;
    unsigned char   m_u1BandWidth;
    unsigned int    m_u4Freq;

} META_CMMB_FreqBandStruct_T;


typedef struct
{
    unsigned char   m_u1StartFreqPointId;
    unsigned char   m_u1EndFreqPointId;

} META_CMMB_FREQ_RANGE_FOR_AUTO_SCAN_REQ_T;


typedef struct
{
    unsigned char                   m_u1MainFreqNum;
    META_CMMB_FreqBandStruct_T      m_rMainFreqBand[META_CMMB_FREQ_BAND_NUM];

} META_CMMB_AUTO_SCAN_GET_FREQ_CNF_T;



//==================================================================



typedef struct
{
    unsigned char                   Nit_NitUpdateSeq;
    unsigned char                   Nit_SysTime[5] ;
    unsigned int                    Nit_CountryCode;

    unsigned char                   Nit_Net_NetLevel;
    unsigned short                  Nit_Net_NetId;

    unsigned char                   Nit_NetNameLen;


    unsigned char                   Nit_NetName[128];

    unsigned char                   Nit_FreqBand_FreqPointId;
    unsigned char                   Nit_FreqBand_BandWidth;
    unsigned int                    Nit_FreqBand_CenterFreq;

    unsigned char                   Nit_OtherFreqNum;    // at most 8 here transferred by ft task.
    unsigned char                   m_ucOtherFreqNumWeCarry;


    unsigned char                   Nit_OtherFreqBandList_FreqPointId[META_CMMB_BLK_NUM];
    unsigned char                   Nit_OtherFreqBandList_BandWidth[META_CMMB_BLK_NUM];
    unsigned int                    Nit_OtherFreqBandList_CenterFreq[META_CMMB_BLK_NUM];


    unsigned char                   Nit_NeighborNetNum;  // at most 8 here transferred by ft task.
    unsigned char                   m_ucNeightborNetWeCarray;

    unsigned char                   Nit_NeighborNetList_NetLevel[META_CMMB_BLK_NUM];
    unsigned short                  Nit_NeighborNetList_NetId[META_CMMB_BLK_NUM];
    unsigned char                   Nit_NeighborNetList_FreqPointId[META_CMMB_BLK_NUM];
    unsigned char                   Nit_NeighborNetList_BandWidth[META_CMMB_BLK_NUM];
    unsigned int                    Nit_NeighborNetList_CenterFreq[META_CMMB_BLK_NUM];


} META_CMMB_NitStruct_T;

typedef struct
{
    unsigned char                        MctUpdateSeq;
    unsigned char                        FreqPointId;


    unsigned char                        MfNum;

    unsigned char                        m_ucMfNumWeCarray;


    unsigned char                        Mf_MfId[META_CMMB_BLK_NUM];
    unsigned char                        Mf_RsRate[META_CMMB_BLK_NUM];
    unsigned char                        Mf_ByteInterleaveMode[META_CMMB_BLK_NUM];
    unsigned char                        Mf_LdpcRate[META_CMMB_BLK_NUM];
    unsigned char                        Mf_ModulationMode[META_CMMB_BLK_NUM];
    unsigned char                        Mf_ScrambleMode[META_CMMB_BLK_NUM];

    unsigned char                        Mf_TimeSlotNum[META_CMMB_BLK_NUM];

    unsigned char                        m_ucMf_TimeSlotNumWeCarray[META_CMMB_BLK_NUM];

    unsigned char                        Mf_TimeSlotId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];

    unsigned char                        Mf_SubMfNum[META_CMMB_BLK_NUM];
    unsigned char                        m_ucMf_SubMfNumWeCarry[META_CMMB_BLK_NUM];


    unsigned char                        Mf_SubMfId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    unsigned short                       Mf_serviceId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];

} META_CMMB_MctStruct_T;

typedef struct
{
    unsigned char                    SctUpdateSeq;
    unsigned short                   ServiceNum;
    unsigned char                    m_u1ServiceNumWeCarray;

    unsigned short                   ServiceId[META_CMMB_SERV_BLOCK_NUM];
    unsigned char                    FreqPointId[META_CMMB_SERV_BLOCK_NUM];

} META_CMMB_SctStruct_T;

typedef struct
{
    unsigned char                   EsgUpdateSeq;

    unsigned char                   NetLevel;
    unsigned short                  NetId;

    unsigned char                   LocalTimeOffset;
    unsigned char                   CharSet;

    unsigned char                   EsgServiceNum;
    unsigned char                   m_ucEsgServiceNumWeCarry;

    unsigned char                   EsgService_EsgServiceIndex[META_CMMB_BLK_NUM];
    unsigned short                  EsgService_EsgServiceId[META_CMMB_BLK_NUM];


    unsigned char                   EsgDataNum;

    unsigned char                   m_ucEsgDataNumWeCarry;
    unsigned char                   EsgData_EsgDataType[META_CMMB_BLK_NUM];

    unsigned char                   EsgData_EsgDataBlockNum[META_CMMB_BLK_NUM];
    unsigned char                   m_ucEsgData_EsgDataBlockNumWeCarry[META_CMMB_BLK_NUM];

    unsigned char                   EsgDataBlock_EsgDataBlockId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    unsigned char                   EsgDataBlock_EsgDataBlockVersion[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    unsigned char                   EsgDataBlock_EsgServiceIndex[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];

} META_CMMB_EsgListStruct_T;

typedef struct
{
    unsigned char             CaUpdateSeq;
    unsigned short            CaDataNum;
    unsigned char             m_ucCaDataNumWeCarry;
    unsigned short            CaId[META_CMMB_BLK_NUM];
    unsigned short            ServiceId[META_CMMB_BLK_NUM];
    unsigned char             EMM_BlockUnitType[META_CMMB_BLK_NUM];
    unsigned char             ECM_BlockUnitType[META_CMMB_BLK_NUM];
    unsigned char             ECM_TransmissionType[META_CMMB_BLK_NUM];

} META_CMMB_CaListStruct_T;

typedef struct
{

    META_CMMB_NitStruct_T        m_rNit;

    META_CMMB_MctStruct_T        m_rCSmct[2]; // [0] for Cmct, [1] for Smct

    META_CMMB_SctStruct_T        m_rCSsct[2]; // [0] for Csct, [1] for Ssct


    unsigned char                  Eb_EbUpdateSeq;
    unsigned char                  Eb_EbMsgNum;
    unsigned short                 Eb_DataBlockLen;
    unsigned char                  m_ucDataBlockLenWeCarray;
    unsigned char                  Eb_DataBlock[META_CMMB_DATA_BLK_NUM];


    unsigned char                   m_ucHasEsg;
    META_CMMB_EsgListStruct_T       m_rEsg;


    unsigned char                   m_ucHasCa;
    META_CMMB_CaListStruct_T        m_rCa;


} META_CMMB_CtrlInfoTable_T;


typedef struct
{

    unsigned char                    m_u1NitUpdateSeq;
    unsigned char                    m_u1CmctUpdateSeq;
    unsigned char                    m_u1SmctUpdateSeq;
    unsigned char                    m_u1CsctUpdateSeq;
    unsigned char                    m_u1SsctUpdateSeq;
    unsigned char                    m_u1EsgUpdateSeq;
    unsigned char                    m_u1FreqPointId;


    unsigned char                    m_u1NetLevel;
    unsigned short                   m_u2NetId;

    unsigned char                    m_u1HasCtrlTable;  // 0: no, 1: yes
    META_CMMB_CtrlInfoTable_T        m_rCtrlTableInfo;


} META_CMMB_FrameInfo_T;

typedef struct
{
    unsigned char                m_u1FrmNum;
    META_CMMB_FrameInfo_T        m_rFrmInfo[META_CMMB_FRAME_INFO_NUM];

} META_CMMB_AUTO_SCAN_CNF_T;

typedef struct
{
    unsigned char                m_u1FrmNum;
    META_CMMB_FrameInfo_T        m_rFrmInfo[META_CMMB_FRAME_INFO_NUM];

} META_CMMB_SET_FREQ_CNF_T;


typedef struct
{
    unsigned char m_u1FreqPointId;

} CMMB_SET_FREQ_REQ_T;

typedef struct
{
    unsigned char    m_u1FrmId;
    unsigned short   m_u2ServId;

} CMMB_SEL_SERV_REQ_ONLY_T;

typedef struct
{
    unsigned char    m_u1FrmId;
    unsigned short   m_u2ServId;
} META_CMMB_PAUSE_SERV_REQ_T;

typedef struct
{
    unsigned char   m_u1FreqPointId;
    char            m_i1Rssi;                 // unit: -dBm 0~100, 0 is best  , -1 means no such kinds of value
    char            m_i1Snr;                  // unit: dBm  0~100, 100 is best, -1 means no such kinds of value
    char            m_i1CurLdpcErrPercent;    // unit: %    0~100, 0 is best  , -1 means no such kinds of value

    int            m_i4TotalLdpcErrCnt;      // unit: -1 means no such kinds of value
    int            m_i4TotalLdpcCnt;         // unit: -1 means no such kinds of value

    int             m_i4CurRsErrorCnt;    // -1 means no such kinkds of value
    int             m_i4TotalRsErrorCnt;  // -1 means no such kinkds of value
    /* Added in W1112 */
    int             m_i4InBandPwr;
    unsigned int    m_u4IsDemodLocked;
    unsigned char   m_u1ReceptionQuality;
    unsigned int    m_u4signal_strength_indication;
} META_CMMB_GET_SIGNAL_STRENGTH_CNF_T;

//--------------------------//
//      CMMB Functions      //
//--------------------------//
META_RESULT  __stdcall META_CMMB_TurnOn(const unsigned int ms_timeout);
META_RESULT  __stdcall META_CMMB_TurnOn_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT  __stdcall META_CMMB_TurnOff(const unsigned int ms_timeout);
META_RESULT  __stdcall META_CMMB_TurnOff_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall  META_CMMB_SetBand(const unsigned int ms_timeout, const META_CMMB_SET_BAND_REQ_T* req);
META_RESULT __stdcall  META_CMMB_SetBand_r(const int meta_handle, const unsigned int ms_timeout, const META_CMMB_SET_BAND_REQ_T* req);
META_RESULT __stdcall  META_CMMB_AutoScanGetFreq(const unsigned int ms_timeout, META_CMMB_AUTO_SCAN_GET_FREQ_CNF_T* cnf);
META_RESULT __stdcall  META_CMMB_AutoScanGetFreq_r(const int meta_handle, const unsigned int ms_timeout, META_CMMB_AUTO_SCAN_GET_FREQ_CNF_T* cnf);

META_RESULT __stdcall  META_CMMB_AutoScan(const unsigned int ms_timeout, META_CMMB_AUTO_SCAN_CNF_T* cnf);
META_RESULT __stdcall  META_CMMB_AutoScan_r(const int meta_handle, const unsigned int ms_timeout, META_CMMB_AUTO_SCAN_CNF_T* cnf);


META_RESULT __stdcall  META_CMMB_StopAutoScan(const unsigned int ms_timeout);
META_RESULT __stdcall  META_CMMB_StopAutoScan_r(const int meta_handle, const unsigned int ms_timeout);
META_RESULT __stdcall  META_CMMB_SetFreq(const unsigned int ms_timeout, const CMMB_SET_FREQ_REQ_T* req, META_CMMB_SET_FREQ_CNF_T* cnf);
META_RESULT __stdcall  META_CMMB_SetFreq_r(const int meta_handle, const unsigned int ms_timeout, const CMMB_SET_FREQ_REQ_T* req, META_CMMB_SET_FREQ_CNF_T* cnf);

META_RESULT __stdcall  META_CMMB_SelServOnly(const unsigned int ms_timeout, const CMMB_SEL_SERV_REQ_ONLY_T* pSelServReq);
META_RESULT __stdcall  META_CMMB_SelServOnly_r(const int meta_handle, const unsigned int ms_timeout, const CMMB_SEL_SERV_REQ_ONLY_T* pSelServReq);
META_RESULT __stdcall  META_CMMB_PauseServ(unsigned int ms_timeout, const META_CMMB_PAUSE_SERV_REQ_T* req);
META_RESULT __stdcall  META_CMMB_PauseServ_r(const int meta_handle, unsigned int ms_timeout, const META_CMMB_PAUSE_SERV_REQ_T* req);


META_RESULT __stdcall  META_CMMB_GetSignalStrength(const unsigned int ms_timeout, META_CMMB_GET_SIGNAL_STRENGTH_CNF_T* cnf);
META_RESULT __stdcall  META_CMMB_GetSignalStrength_r(const int meta_handle, const unsigned int ms_timeout, META_CMMB_GET_SIGNAL_STRENGTH_CNF_T* cnf);


META_RESULT __stdcall  META_CMMB_AutoScanWithFreqRange(const unsigned int ms_timeout, META_CMMB_FREQ_RANGE_FOR_AUTO_SCAN_REQ_T* req, META_CMMB_AUTO_SCAN_CNF_T* cnf);
META_RESULT __stdcall  META_CMMB_AutoScanWithFreqRange_r(const int meta_handle, const unsigned int ms_timeout, META_CMMB_FREQ_RANGE_FOR_AUTO_SCAN_REQ_T* req, META_CMMB_AUTO_SCAN_CNF_T* cnf);

//----------------------------------------------------------------//
//                            TDMB                                //
//----------------------------------------------------------------//

//--------------------------//
//    TDMB data structures  //
//--------------------------//

typedef enum     // ref from TDMB
{
    META_TDMB_KOREA_BAND = 1,
    META_TDMB_BAND_III,
    META_TDMB_L_BAND,
    META_TDMB_CANADA_BAND,
    META_TDMB_CHINESE_BAND,
    META_TDMB_BAND_II,
    META_TDMB_BAND_IF,
    META_TDMB_UNDEF_BAND
} META_TDMB_BAND_enum;

typedef struct
{
    META_TDMB_BAND_enum  m_rBand;

} TDMB_SET_BAND_REQ_T;

typedef struct
{
    unsigned int  m_u4Freq;
} TDMB_SET_FREQ_REQ_T;



typedef struct
{
    unsigned char m_ucFreqNum;
    unsigned int m_u4Freq[10];

} TDMB_AUTO_SCAN_CNF_T;

// ========  for Ensemble ========


typedef struct
{
    //TDMB_DBSTATE     DB;
    unsigned char        m_ucStateNum;
    unsigned int         m_u4State[10];


    unsigned int        Type;   //DMB,DAB,DATA
    unsigned int        Id;
    unsigned int        BitRate;
    unsigned char       PL; //Protection Level
    unsigned char       Reg[8];
    unsigned short      UserApplType;       // added by KST 2006.07.20

    unsigned int        TMId;
    unsigned int        ASCTy_DSCTy;
    unsigned int        SCId;
    unsigned int        PackAdd;
    unsigned int        DG_MFflag;
    unsigned int        Primary;
    unsigned int        CAflag;
    unsigned int        Language;
    char                SCLabel[16];

    //TDMB_SvcComponentInfo  *pSvcComp;
    unsigned char       SvcComp_Order;          // 4bits
    unsigned char       SvcComp_TMId;           // 2bits    Transport Mechanism Id
    unsigned char       SvcComp_ASCTy_DSCTy;    // 6bits    Audio Service Component Type
    unsigned char       SvcComp_SubCh_FIDCId;   // 6bits    SubChId or FIDCId in FIG 0/4
    unsigned int        SvcComp_SId;            // 16bit
    unsigned char       SvcComp_CAflag;         // 1bit     CA Flag
    unsigned char       SvcComp_DG_MFflag;      // 1bit     DG Flag or MF flag
    unsigned char       SvcComp_Language;       // 8bit
    unsigned char       SvcComp_SCIdS;          // 4bit     Service component Identifier within ther Service
    unsigned char       SvcComp_SvcCompLabel[16];// 16bytes Service component Label

    unsigned short      SvcComp_SCId;           // 12bits   Service Component Id
    unsigned short      SvcComp_PackAdd;        // 10bits   Packet Address
    unsigned short      SvcComp_SCCA;           // 16bits   Service Component Conditional Access

    unsigned short      SvcComp_m_encoded_id;   // Only for Frontier
    unsigned char       SvcComp_m_sif;          // Only for Frontier


    //TDMB_SubChInfo             *pSubCh;
    unsigned char       SubChId;        // 6bits    Sub channel Id
    unsigned char       TblIndex;       // 6bits    TableIndex
    unsigned char       Form_Opt_Prot;  //[3] : FormFlag   //[2] : Option//[1~0] : protection
    unsigned short      StrtAdd;        // 10bits   Start Address
    unsigned short      SubChSize;      // 10bits   Sub channel size

    unsigned int        Tag;

} TDMB_CHANNELDB_T;

typedef struct
{
    // TDMB_DBSTATE
    unsigned char       m_ucStateNum;
    unsigned int        m_u4State[10];

    unsigned int        Id;
    char                Label[20];

    //TDMB_ServiceInfo  *pService;
    unsigned int        SId;            // 32bits
    unsigned char       SvcLabel[16];   // 16bytes  Service Label(Program service and Data service)
    unsigned short      CharacterFlag;
    unsigned char       CAId;           // 3bit
    unsigned char       NumSvcComp;     // 4bits    Number of Service Component


    //TDMB_CHANNELDB        *Channel;
    unsigned char     m_ucChannelDBNum;
    TDMB_CHANNELDB_T  m_rChannelDB[10];


    //struct _TDMB_SERVICEDB    *Next;
    unsigned int                Tag;
    unsigned int            ChannelCount;


} TDMB_SERVICEDB_T;

typedef struct
{
    // TDMB_DBSTATE
    unsigned char        m_ucStateNum;
    unsigned int         m_u4State[10];

    unsigned int         Band;
    unsigned int         Frequency;
    unsigned short       Id;
    unsigned int         SvcNum;
    unsigned int         SvcCompNum;
    unsigned int         SubChNum;
    char                 Label[20];

    // TDMB_EnsembleInfo
    unsigned char   AlFlag;             // 1bit     Al flag
    unsigned char   NumSubCh;
    unsigned char   NumSvc;
    unsigned char   NumProgram;
    unsigned char   NumSvcComp;
    unsigned char   NumUserApp;
    unsigned char   NumAnn;
    unsigned char   NumProgType;
    unsigned char   EnsemLabel[16];     // 16bytes  Ensemble Label
    unsigned short  CharacterFlag;
    unsigned short  EId;                // 16bits   country Id Ensemble reference

    // TDMB_SERVICEDB[]
    unsigned char   m_ucServiceDBNum;
    TDMB_SERVICEDB_T  m_rServiceDB[10];

    unsigned int     Tag;

} TDMB_ENSEMBLEDB_T;


typedef struct   // for META APP
{
    unsigned char      m_ucEnsembleNum;
    TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];

} TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T;

typedef struct   // for META APP
{
    char m_cResult; // 0: success,
    // 1: the band not exist  ==> META_TDMB_ERR_BAND_NOT_EXIST
    // 2: frequency not exist ==> META_TDMB_ERR_FREQ_NOT_EXIST

    unsigned char      m_ucEnsembleNum;
    TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];
    TDMB_ENSEMBLEDB_T  m_rCurEnsembleDB;

} TDMB_SET_FREQ_CNF_T;


typedef struct
{
    unsigned short m_u2Snr;
    unsigned char  m_ucBer_a;  // a.b*10^-c
    unsigned char  m_ucBer_b;
    unsigned char  m_ucBer_c;
    short          m_i2RSSI;

} TDMB_GET_SIGNAL_CNF_T;

typedef struct
{
    unsigned int m_u4ServiceId;
    unsigned int m_u4SubChnId;
    char*         m_pcfilepath; // store the TS stream data to this file

} TDMB_SEL_SERVICE_REQ_T;

typedef struct
{
    unsigned int m_u4ServiceId;
    unsigned int m_u4SubChnId;

} TDMB_SEL_SERVICE_ONLY_REQ_T;



typedef struct  //  for Meta APP only
{
    unsigned char      m_ucEnsembleNum;
    TDMB_ENSEMBLEDB_T  m_rEnsembleDB[10];
    TDMB_ENSEMBLEDB_T  m_rCurEnsembleDB;

} TDMB_GET_ENSM_CNF_T;
// --------------------------//
//      TDMB callback        //
// --------------------------//
typedef enum
{
    TDMB_FAT_DISK_FULL = 0,
    TDMB_FAT_UNKNOWN_WRITE_ERROR = 1,
    TDMB_MED_MEMORY_FULL = 2,
    TDMB_MED_MEMORY_NOT_EXIST = 3
} TDMB_SEL_SERV_ERROR_RESULT;

typedef void (__stdcall* META_TDMB_SEL_SERV_CNF)(const TDMB_SEL_SERV_ERROR_RESULT status);

//--------------------------//
//      TDMB Functions      //
//--------------------------//

META_RESULT  __stdcall META_TDMB_TurnOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_TDMB_TurnOn_r(const int meta_handle, unsigned int ms_timeout);

// send band may return: META_TDMB_ERR_BAND_NOT_EXIST, META_SUCCESS, META_FAILED
META_RESULT __stdcall META_TDMB_SetBand(unsigned int ms_timeout, TDMB_SET_BAND_REQ_T* req);
META_RESULT __stdcall META_TDMB_SetBand_r(const int meta_handle, unsigned int ms_timeout, TDMB_SET_BAND_REQ_T* req);

META_RESULT __stdcall META_TDMB_AutoScan_GetFreq(unsigned int ms_timeout, TDMB_AUTO_SCAN_CNF_T* cnf);
META_RESULT __stdcall META_TDMB_AutoScan_GetFreq_r(const int meta_handle, unsigned int ms_timeout, TDMB_AUTO_SCAN_CNF_T* cnf);

META_RESULT __stdcall META_TDMB_SetFreq(unsigned int ms_timeout, TDMB_SET_FREQ_REQ_T* req, TDMB_SET_FREQ_CNF_T* cnf);
META_RESULT __stdcall META_TDMB_SetFreq_r(const int meta_handle, unsigned int ms_timeout, TDMB_SET_FREQ_REQ_T* req, TDMB_SET_FREQ_CNF_T* cnf);

META_RESULT __stdcall META_TDMB_AutoScan_GetEnsemble(unsigned int ms_timeout, TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T* cnf);
META_RESULT __stdcall META_TDMB_AutoScan_GetEnsemble_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_ENSM_INFO_BY_AUTO_SCAN_CNF_T* cnf);

META_RESULT __stdcall META_TDMB_GetSignal(unsigned int ms_timeout, TDMB_GET_SIGNAL_CNF_T* cnf);
META_RESULT __stdcall META_TDMB_GetSignal_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_SIGNAL_CNF_T* cnf);

META_RESULT __stdcall META_TDMB_SelService(unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T* req, const META_TDMB_SEL_SERV_CNF  cnf_cb);
META_RESULT __stdcall META_TDMB_SelService_r(const int meta_handle, unsigned int ms_timeout, TDMB_SEL_SERVICE_REQ_T* req, const META_TDMB_SEL_SERV_CNF  cnf_cb);

META_RESULT __stdcall META_TDMB_SetIdle(unsigned int ms_timeout, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg);
META_RESULT __stdcall META_TDMB_SetIdle_r(const int meta_handle, unsigned int ms_timeout, CALLBACK_META_FAT_PROGRESS  cb_progress, void*  cb_progress_arg);


META_RESULT __stdcall META_TDMB_TurnOff(unsigned int ms_timeout);
META_RESULT __stdcall META_TDMB_TurnOff_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT __stdcall META_TDMB_GetEnsm(unsigned int ms_timeout, TDMB_GET_ENSM_CNF_T* cnf);
META_RESULT __stdcall META_TDMB_GetEnsm_r(const int meta_handle, unsigned int ms_timeout, TDMB_GET_ENSM_CNF_T* cnf);

META_RESULT __stdcall META_TDMB_SelServiceOnly( unsigned int ms_timeout, TDMB_SEL_SERVICE_ONLY_REQ_T* req);
META_RESULT __stdcall META_TDMB_SelServiceOnly_r(const int meta_handle, unsigned int ms_timeout, TDMB_SEL_SERVICE_ONLY_REQ_T* req);


META_RESULT __stdcall META_TDMB_StopAutoScan(unsigned int ms_timeout);
META_RESULT __stdcall META_TDMB_StopAutoScan_r(const int meta_handle, unsigned int ms_timeout);

// MATV functions
typedef struct
{
    unsigned int    freq;
    unsigned char   sndsys;
    unsigned char   colsys;
    unsigned char   flag;
} matv_ch_entry;

typedef struct
{
    unsigned char   m_ucChannel;
    matv_ch_entry   m_rmatv_ch_entry;
} FT_MATV_SET_CHANNEL_PROPERTY_REQ_T;

typedef struct
{
    unsigned char   m_ucProgress;
    unsigned char   m_ucChannels;
    matv_ch_entry   m_rmatv_ch_entry[70];
} FT_MATV_GET_CHANNEL_LIST_CNF_T;

typedef struct
{
    int             m_i4QualityIndex[128];
} FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T;

META_RESULT  __stdcall META_MATV_PowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_PowerOn_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_PowerOff(unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_PowerOff_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_SetRegion(unsigned int ms_timeout, unsigned char region);
META_RESULT  __stdcall META_MATV_SetRegion_r(const int meta_handle, unsigned int ms_timeout, unsigned char region);
META_RESULT  __stdcall META_MATV_StartScan(unsigned int ms_timeout, unsigned int scanmode);
META_RESULT  __stdcall META_MATV_StartScan_r(const int meta_handle, unsigned int ms_timeout, unsigned char scanmode);
META_RESULT  __stdcall META_MATV_StartFullScan(unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_StartFullScan_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_StopScan(unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_StopScan_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_MATV_GetChannelList(unsigned int ms_timeout, FT_MATV_GET_CHANNEL_LIST_CNF_T* cnf);
META_RESULT  __stdcall META_MATV_GetChannelList_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_GET_CHANNEL_LIST_CNF_T* cnf);
META_RESULT  __stdcall META_MATV_ChangeChannel(unsigned int ms_timeout, unsigned char channel);
META_RESULT  __stdcall META_MATV_ChangeChannel_r(const int meta_handle, unsigned int ms_timeout, unsigned char channel);
META_RESULT  __stdcall META_MATV_SetChannelProperty(unsigned int ms_timeout, FT_MATV_SET_CHANNEL_PROPERTY_REQ_T* req);
META_RESULT  __stdcall META_MATV_SetChannelProperty_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_SET_CHANNEL_PROPERTY_REQ_T* req);
META_RESULT  __stdcall META_MATV_GetChannelQuality(unsigned int ms_timeout, unsigned short item, int* qualityindex);
META_RESULT  __stdcall META_MATV_GetChannelQuality_r(const int meta_handle, unsigned int ms_timeout, unsigned short index, int* qualityindex);
META_RESULT  __stdcall META_MATV_GetChannelQualityAll(unsigned int ms_timeout, FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T* channel_quality);
META_RESULT  __stdcall META_MATV_GetChannelQualityAll_r(const int meta_handle, unsigned int ms_timeout, FT_MATV_GET_CHANNEL_QUALITY_ALL_CNF_T* channel_quality);

// CCT
typedef struct
{
    char sensor_prefix_name[64];
} CCT_Dual_Dev_ISP_camera_sensor_prefix_name_struct;

typedef struct
{
    char lens_prefix_name[64];
} CCT_Dual_Dev_ISP_camera_lens_prefix_name_struct;
/**
 * @}
 */
#endif // #if !defined(__GNUC__) || !defined(WIN32)
#endif // #ifndef __META_MM_H__

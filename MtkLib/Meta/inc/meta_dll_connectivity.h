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
 * meta_dll_connectivity.h
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
#ifndef __META_CONNECTIIVTY_H__
#define __META_CONNECTIIVTY_H__
/**
 * \addtogroup Connectivity
 *  @{
 */
// WiFi
typedef struct
{
    unsigned char   mac_addr[6];
} WiFi_MacAddress_S;

typedef struct
{
    unsigned char   CCKTxPWR[14];
    unsigned char   OFDMTxPWR[14];
} WiFi_TxPower_2400M_S;

typedef struct
{
    unsigned char   TxPWR[34];
} WiFi_TxPower_5000M_S;

typedef struct
{
    unsigned char   i_ch_offset;
    unsigned char   q_ch_offset;
} WiFi_DAC_DC_Offset_S;

typedef struct
{
    unsigned char txAlcCCK[14];
    unsigned char txOutputPowerDBCCK[14];
    unsigned char txAlcOFDM [8][14];
    unsigned char txOutputPowerDBOFDM[8][14];
} WiFi_ALC_2400M_S;

typedef struct
{
    unsigned char alcSlop1Divider;
    unsigned char alcSlop1Dividend;
    unsigned char alcSlop2Divider;
    unsigned char alcSlop2Dividend;
} WiFi_TxALC_2400M_S;
typedef struct
{
    unsigned char BluetoothAddress[6];
    unsigned char MinEncryptionSize[1];
    unsigned char MaxEncryptionSize[1];
    unsigned char HCITransportLayerParameters[3];
    unsigned char FixedPIN[16];
    unsigned char FixedPINLength[1];
    unsigned char SleepEnableMask[1];
    unsigned char LowPowerClockParameter[8];
    unsigned char PowerControlConfiguration[13];
    unsigned char SleepControlParameters[12];
    unsigned char DebugControl[4];
    unsigned char LCandRMOverrideEnable[4];
    unsigned char RadioRegisterOverride[6];
    unsigned char CodecConfiguration[8];
    unsigned char CVSDGainVolumeSettings[6];
    unsigned char VoiceSettings[2];
    unsigned char UserBaudRate[3];

    unsigned char LowPowerDriftRate[1];
    unsigned char MaxTxPowerLevel[1];
    unsigned char AdaptiveFrequencyHoppingParameters[29];
    unsigned char BufferSize[4];
    unsigned char GpioMapping[16];
    unsigned char GpioPolarity[4];
}  nvram_ef_btradio_rfmd3500_struct;

typedef struct
{
    unsigned char BDAddr[6];
    unsigned char ClassOfDevice[3];
    unsigned char LinkKeyType[1];
    unsigned char UnitKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[1];
    unsigned char Radio[30];
    unsigned char Sleep[6];
    unsigned char MainOscillatorInfo[5];
    unsigned char LPOInfo[4];
    unsigned char AFH[9];
    unsigned char PTA[49];
    unsigned char WDT[2];
    unsigned char Debug[1];
    unsigned char UART[2];
}  nvram_ef_btradio_mt6601_struct;

// this is common for MT6611/MT6612/MT6236
typedef struct
{
    unsigned char BDAddr[6];
    unsigned char CapId[1];
    unsigned char LinkKeyType[1];
    unsigned char UnitKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[1];
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char Reserved[2];
} nvram_ef_btradio_mt6611_struct;

// MT6612 (from 10AW1108MP and later)
// MT6236 (from 11AW1112MP and later)
typedef struct
{
    unsigned char BDAddr[6];
    unsigned char CapId[1];
    unsigned char LinkKeyType[1];
    unsigned char UnitKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[1];
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char Reserved[2];
    unsigned char ECLK_SEL;
} nvram_ef_btradio_mtk_bt_chip_struct;

typedef struct // LID: NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID
{
    char           cAbsTemp;
    unsigned char  ucThermoValue;
    unsigned char  ucXtalTrim;
} wndrv_cal_setting_trim_thermo_struct;
// WiFi
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_MacAddress_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_MacAddress_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_MacAddress(const WiFi_MacAddress_S*  mac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_MacAddress_r(const int meta_handle, const WiFi_MacAddress_S*  mac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_MacAddress(WiFi_MacAddress_S*  mac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_MacAddress_r(const int meta_handle, WiFi_MacAddress_S*  mac, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_TxPower2400M_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_TxPower2400M_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxPower2400M(const WiFi_TxPower_2400M_S*  txpwr, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxPower2400M_r(const int meta_handle, const WiFi_TxPower_2400M_S*  txpwr, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxPower2400M(WiFi_TxPower_2400M_S*  txpwr, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxPower2400M_r(const int meta_handle, WiFi_TxPower_2400M_S*  txpwr, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_TxPower5000M_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_TxPower5000M_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxPower5000M(const WiFi_TxPower_5000M_S*  txpwr, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxPower5000M_r(const int meta_handle, const WiFi_TxPower_5000M_S*  txpwr, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxPower5000M(WiFi_TxPower_5000M_S*  txpwr, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxPower5000M_r(const int meta_handle, WiFi_TxPower_5000M_S*  txpwr, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_DacDcOffset_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_DacDcOffset_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_DacDcOffset(const WiFi_DAC_DC_Offset_S*  dac, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_DacDcOffset_r(const int meta_handle, const WiFi_DAC_DC_Offset_S*  dac, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_DacDcOffset(WiFi_DAC_DC_Offset_S*  dac, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_DacDcOffset_r(const int meta_handle, WiFi_DAC_DC_Offset_S*  dac, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_ALC_2400M_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_ALC_2400M_Len_r(const int meta_hanle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_ALC_2400M(const WiFi_ALC_2400M_S*  alc, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_ALC_2400M_r(const int meta_handle, const WiFi_ALC_2400M_S*  alc, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_ALC_2400M(WiFi_ALC_2400M_S*  alc, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_ALC_2400M_r(const int meta_handle, WiFi_ALC_2400M_S*  alc, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_TxALC2400M_Len(int* len);
META_RESULT  __stdcall META_NVRAM_WiFi_TxALC2400M_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxALC2400M(const WiFi_TxALC_2400M_S*  txalc, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TxALC2400M_r(const int meta_handle, const WiFi_TxALC_2400M_S*  txalc, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxALC2400M(WiFi_TxALC_2400M_S*  txalc, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TxALC2400M_r(const int meta_handle, WiFi_TxALC_2400M_S*  txalc, const char* buf, const int buf_len);
//wndrv_cal_setting_trim_thermo_struct
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_TRIM_THERMO_Len(int* len);
META_RESULT  __stdcall META_NVRAM_TRIM_THERMO_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TrimThermo(const wndrv_cal_setting_trim_thermo_struct*  trim_struct, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Compose_TrimThermo_r(const int meta_handle, const wndrv_cal_setting_trim_thermo_struct*  trim_struct, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TrimThermo(wndrv_cal_setting_trim_thermo_struct*  trim_struct, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_WiFi_Decompose_TrimThermo_r(const int meta_handle, wndrv_cal_setting_trim_thermo_struct*  trim_struct, const char* buf, const int buf_len);
//BT
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Compose_RFMD3500Radio(const nvram_ef_btradio_rfmd3500_struct*  radio, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Compose_RFMD3500Radio_r(const int meta_handle, const nvram_ef_btradio_rfmd3500_struct*  radio, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Decompose_RFMD3500Radio(nvram_ef_btradio_rfmd3500_struct*  radio, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Decompose_RFMD3500Radio_r(const int meta_handle, nvram_ef_btradio_rfmd3500_struct*  radio, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Compose_MT6601Radio(const nvram_ef_btradio_mt6601_struct*  radio, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Compose_MT6601Radio_r(const int meta_handle, const nvram_ef_btradio_mt6601_struct*  radio, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Decompose_MT6601Radio(nvram_ef_btradio_mt6601_struct*  radio, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Decompose_MT6601Radio_r(const int meta_handle, nvram_ef_btradio_mt6601_struct*  radio, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Compose_MT6611Radio(const nvram_ef_btradio_mt6611_struct*  radio, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Compose_MT6611Radio_r(const int meta_handle, const nvram_ef_btradio_mt6611_struct*  radio, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Decompose_MT6611Radio(nvram_ef_btradio_mt6611_struct*  radio, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Decompose_MT6611Radio_r(const int meta_handle, nvram_ef_btradio_mt6611_struct*  radio, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Compose_MediatekBtChip(const nvram_ef_btradio_mtk_bt_chip_struct*  radio, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Compose_MediatekBtChip_r(const int meta_handle, const nvram_ef_btradio_mtk_bt_chip_struct*  radio, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_BT_Decompose_MediatekBtChip(nvram_ef_btradio_mtk_bt_chip_struct*  radio, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_BT_Decompose_MediatekBtChip_r(const int meta_handle, nvram_ef_btradio_mtk_bt_chip_struct*  radio, const char* buf, const int buf_len);
//--------------------------------------------------------------------------//
//  WiFi Calibration                                                        //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  WiFi Calibration: data structure definition        //
//-----------------------------------------------------//

// WiFi Baseband Chip ID
#define WIFI_BB_MT5911      0x00000001
#define WIFI_BB_MT5921      0x00000002
#define WIFI_BB_MT5931      0x00000003

// WiFi RF Chip ID
#define WIFI_RF_AL2236      0x00000001
#define WIFI_RF_MAX2827     0x00000002
#define WIFI_RF_MT5921      0x00000003
#define WIFI_RF_MT5931      0x00000004

typedef enum
{
    WIFI_TEST_RATE_1M = 0,     /**< 1M          */
    WIFI_TEST_RATE_2M,         /**< 2M          */
    WIFI_TEST_RATE_5_5M,       /**< 5.5M        */
    WIFI_TEST_RATE_11M,        /**< 11M         */
    WIFI_TEST_RATE_6M,         /**< 6M          */
    WIFI_TEST_RATE_9M,         /**< 9M          */
    WIFI_TEST_RATE_12M,        /**< 12M         */
    WIFI_TEST_RATE_18M,        /**< 18M         */
    WIFI_TEST_RATE_24M,        /**< 24M         */
    WIFI_TEST_RATE_36M,        /**< 36M         */
    WIFI_TEST_RATE_48M,        /**< 48M         */
    WIFI_TEST_RATE_54M,        /**< 54M         */
    WNDRV_TEST_MOD_MCS0,       /**< 802.11n MSC 0 */
    WNDRV_TEST_MOD_MCS1,       /**< 802.11n MSC 1 */
    WNDRV_TEST_MOD_MCS2,       /**< 802.11n MSC 2 */
    WNDRV_TEST_MOD_MCS3,       /**< 802.11n MSC 3 */
    WNDRV_TEST_MOD_MCS4,       /**< 802.11n MSC 4 */
    WNDRV_TEST_MOD_MCS5,       /**< 802.11n MSC 5 */
    WNDRV_TEST_MOD_MCS6,       /**< 802.11n MSC 6 */
    WNDRV_TEST_MOD_MCS7,       /**< 802.11n MSC 7 */
    WNDRV_TEST_MOD_MCS32,      /**< 802.11n MSC 32 */
    WIFI_TEST_RATE_COUNT       /**< Total count   */
} WiFi_TestRate_E;

typedef enum
{
    WNDRV_HOST_INTERFACE_SDIO = 0,
    WNDRV_HOST_INTERFACE_HPI = 1,
    WNDRV_HOST_INTERFACE_SPI = 2,
    WNDRV_HOST_INTERFACE_CF_MEM = 3,
    WNDRV_HOST_INTERFACE_CF_IO = 4
} WiFi_HostInterface_E;

typedef enum
{
    WIFI_TX_ALL_ZEROS,
    WIFI_TX_ALL_ONES,
    WIFI_TX_ALTERNATE_BITS,
    WIFI_TX_PSEUDO_RANDOM
} WiFi_TestPktTxPattern_E;

typedef enum
{
    WIFI_POWER_MODE_NORMAL,
    WIFI_POWER_MODE_IDLE,
    WIFI_POWER_MODE_SLEEP
} WiFi_PowerManagementMode_E;

typedef enum
{
    WIFI_RF_RX_TEST_MODE = 1  /**< For RF Test use */
} WiFi_TestPktRxMode_E;

typedef enum
{
    WIFI_RX_ANT_DIVERSITY_AGC = 0,  /**< AGC based selection */
    WIFI_RX_ANT_DIVERSITY_MPDU = 1, /**< MPDU based selection */
    WIFI_RX_ANT_FIXED_0 = 2,        /**< Always 0 */
    WIFI_RX_ANT_FIXED_1 = 3         /**< Always 1 */
} WiFi_RxAntSel_E;

typedef struct
{
    unsigned int    bb_chip_id;
    char            bb_chip_ver[32];
    unsigned int    rf_chip_id;
    char            rf_chip_ver[32];
    unsigned char   support_802_11b;
    unsigned char   support_802_11a;
    unsigned char   support_802_11g;
    bool            eeprom_exist;
    unsigned int    eeprom_size;
    WiFi_HostInterface_E    host_interface;
    unsigned char   support_802_11n;
} WiFi_ChipCapability_S;

typedef struct
{
    unsigned int        ch_freq; /**< Frq, units are kHz */
    WiFi_TestRate_E     tx_rate;
    int                 dbm;
} WiFi_DBM2DAC_Set_S;

typedef struct
{
    unsigned short      tx_gain_dac;
} WiFi_DBM2DAC_Query_S;

typedef struct
{
    unsigned int        ch_freq; /**< Frq, units are kHz */
    WiFi_TestRate_E     tx_rate;
    unsigned char       txAnt; /**< 0 for Antenna 0; 1 for Antenna 1 */
    unsigned short      tx_gain_dac;
} WiFi_TestTx_S;

typedef struct
{
    unsigned int            ch_freq;            /**< Frq, units are kHz */
    WiFi_TestRate_E         tx_rate;
    unsigned short          tx_gain_dac;
    unsigned int            pktCount;
    unsigned int            pktInterval;        /**< interval between each Tx Packet */
    unsigned int            pktLength;          /**< 24~1500 */
    WiFi_TestPktTxPattern_E pattern;            /**< content of the Tx Packet */
    unsigned char           txAnt;              /**< 0 for Antenna 0; 1 for Antenna 1 */
    unsigned char           is_short_preamble;  /**< 0 for long preamble and 1 for short preamble */
    unsigned char           mac_header[ 24 ];   /**< Frame Ctrl, Duration = 2bytes + 2bytes */
    /* Address 1 = 6 bytes */
    /* Address 2 = 6 bytes */
    /* Address 3 = 6 bytes */
    /* Sequence Ctrl = 2 bytes */
} WiFi_TestPktTx_S;

typedef struct
{
    unsigned int            ch_freq;            /**< Frq, units are kHz */
    WiFi_TestRate_E         tx_rate;
    unsigned short          tx_gain_dac;
    unsigned int            pktCount;
    unsigned int            pktInterval;        /**< interval between each Tx Packet */
    unsigned int            pktLength;          /**< 24~1500 */
    WiFi_TestPktTxPattern_E pattern;            /**< content of the Tx Packet */
    unsigned char           txAnt;              /**< 0 for Antenna 0; 1 for Antenna 1 */
    unsigned int            txFlags;
    unsigned int            targetAlc;
    unsigned char           is_short_preamble;  /**< 0 for long preamble and 1 for short preamble */
    unsigned char           mac_header[ 24 ];   /**< Frame Ctrl, Duration = 2bytes + 2bytes */
    /* Address 1 = 6 bytes */
    /* Address 2 = 6 bytes */
    /* Address 3 = 6 bytes */
    /* Sequence Ctrl = 2 bytes */
} WiFi_TestPktTx_Ex_S;

typedef struct
{
    unsigned int        pkt_sent_count;  /**< total num sent */
    unsigned int        pkt_sent_acked;  /**< acked num */
} WiFi_TxStatus_S;


typedef struct
{
    unsigned int        pkt_sent_count;  /**< total num sent */
    unsigned int        pkt_sent_acked;  /**< acked num */
    unsigned short      avgAlc;
    unsigned char       cckGainControl;
    unsigned char       ofdmGainControl;
} WiFi_TxStatus_Ex_S;

typedef struct
{
    unsigned int                ch_freq;  /**< Frq, units are kHz */
    WiFi_TestPktRxMode_E        mode;
    WiFi_RxAntSel_E             rxAnt;
} WiFi_TestPktRx_S;

typedef struct
{
    unsigned int        int_rx_ok_num;     /**< number of packets that Rx ok from interrupt */
    unsigned int        int_crc_err_num;   /**< number of packets that CRC error from interrupt */
    unsigned int        pau_rx_pkt_count;  /**< number of packets that Rx ok from PAU */
    unsigned int        pau_crc_err_count; /**< number of packets that CRC error from PAU */
    unsigned int        pau_cca_count;     /**< CCA rising edge count */
    unsigned int        pau_rx_fifo_full_count; /**< number of lost packets due to FiFo full */
    unsigned int        int_long_preamble_num;
    unsigned int        int_short_preamble_num;
    unsigned int        int_rate_ok_num[ 12 ];
    unsigned int        int_rate_crc_err_num[ 12 ];
    int                 int_rssi_max;
    int                 int_rssi_min;
    int                 int_rssi_mean;
    int                 int_rssi_variance;
    /* 0~63, 64~127, 128~255, 256~511, 512~1023, 1024~2047 #define WNDRV_PACKET_SIZE_COUNT   (6) */
    unsigned int        packetSize[6];
    /* Data, Management, Control */
    unsigned int        packetType[6];
    unsigned int        int_rate_ok_num_802_11n[ 8 ];
    unsigned int        int_rate_crc_err_num_802_11n[ 8 ];
} WiFi_RxStatus_S;

typedef struct
{
    int  ED;
    int  OSD;
    int  SQ1;
    int  SFD;
    int  CRC16;
} WiFi_RxCounter_S;

typedef struct
{
    unsigned int    channel_num;
    unsigned char   channel_list[64];
} WiFi_ChannelList_S;

typedef struct
{
    unsigned char   country_code[2];
} WiFi_RegDomain_S;

typedef struct
{
    unsigned int    index;      /**< 32bits alignment index, +4 */
    unsigned int    mcr_data32;
} WiFi_MACReg32_S;

typedef struct
{
    unsigned int    index;      /**< 16bits alignment index, +2 */
    unsigned short  mcr_data16;
} WiFi_MACReg16_S;

typedef struct
{
    unsigned int    index;      /**< 8bits alignment index, +1 */
    unsigned char   bbcr_data8;
} WiFi_BBReg8_S;

typedef struct
{
    unsigned int    index;      /**< 16bits alignment index, +2 */
    unsigned short  eeprom_data16;
} WiFi_EEPROM_S;

typedef enum
{
    WNDRV_TEST_BW_20MHZ = 0,
    WNDRV_TEST_BW_40MHZ = 1,
    WNDRV_TEST_BW_U20MHZ = 2,
    WNDRV_TEST_BW_L20MHZ = 3,
    WNDRV_TEST_BW_COUNT
} wndrv_test_bandwidth_enum;

typedef enum
{
    WNDRV_TEST_TX_GI_400NS = 0,
    WNDRV_TEST_TX_GI_800NS = 1,
    WNDRV_TEST_TX_GI_COUNT
} wndrv_test_guard_intval_enum;

typedef enum
{
    WNDRV_TEST_TX_GREEN_FIELD = 0,
    WNDRV_TEST_TX_MIX_MODE = 1,
    WNDRV_TEST_TX_MODE_COUNT
} wndrv_test_mode_sel_enum;

typedef struct
{
    wndrv_test_bandwidth_enum  txBw;
} wndrv_test_tx_bw_struct;


typedef struct
{
    wndrv_test_guard_intval_enum  txGi;
} wndrv_test_tx_gi_struct;


typedef struct
{
    wndrv_test_mode_sel_enum  txMode;
} wndrv_test_tx_mode_sel_struct;

typedef struct
{
    wndrv_test_bandwidth_enum  rxBw;
} wndrv_test_rx_bw_struct;

/* WNDRV_TEST_QUERY_THEM_SENS */
/* Note wndrv_test_peer_buff_them_sens_struct is used in peer_buff_ptr. */
typedef struct
{
    unsigned int  u4ThemSensVal;
} wndrv_test_peer_buff_them_sens_struct;

/* WNDRV_TEST_QUERY_VOLT_SENS */
/* Note wndrv_test_peer_buff_volt_sens_struct is used in peer_buff_ptr. */
typedef struct
{
    unsigned int  u4VoltSensVal;
} wndrv_test_peer_buff_volt_sens_struct;

/* WNDRV_TEST_QUERY_TSSI */
/* Note wndrv_test_peer_buff_volt_sens_struct is used in peer_buff_ptr. */
typedef struct
{
    unsigned int  u4Tssi;
} wndrv_test_peer_buff_tssi_struct;

/* WNDRV_TEST_QUERY_EFUSE */
/* Note wndrv_test_peer_buff_efuse_struct is used in peer_buff_ptr. */
typedef struct
{
    unsigned short  u2Offset; /**< Addressing space is determined by efuse size. */
    unsigned int    u4Value;
} wndrv_test_peer_buff_efuse_struct;

//-----------------------------------------------------//
//  WiFi Calibration: WNDRV SET Functions              //
//-----------------------------------------------------//
META_RESULT  __stdcall META_WiFi_Stop(unsigned int  ms_timeout);
META_RESULT  __stdcall META_WiFi_Stop_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall META_WiFi_ContTx(unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_ContTx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_LocalFrequencyMeasure(unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_LocalFrequencyMeasure_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_CarrierSuppressionMeasure(unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_CarrierSuppressionMeasure_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestTx_S* req);
META_RESULT  __stdcall META_WiFi_ContPktTx(unsigned int  ms_timeout, const WiFi_TestPktTx_S* req);
META_RESULT  __stdcall META_WiFi_ContPktTx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktTx_S* req);
META_RESULT  __stdcall META_WiFi_ContPktTx_Ex(unsigned int  ms_timeout, const WiFi_TestPktTx_Ex_S* req);
META_RESULT  __stdcall META_WiFi_ContPktTx_Ex_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktTx_Ex_S* req);


META_RESULT  __stdcall META_WiFi_SetPowerManagementMode(unsigned int  ms_timeout, const WiFi_PowerManagementMode_E  mode);
META_RESULT  __stdcall META_WiFi_SetPowerManagementMode_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_PowerManagementMode_E  mode);
META_RESULT  __stdcall META_WiFi_ContPktRx(unsigned int  ms_timeout, const WiFi_TestPktRx_S* req);
META_RESULT  __stdcall META_WiFi_ContPktRx_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TestPktRx_S* req);
META_RESULT  __stdcall META_WiFi_SetRegDomain(unsigned int  ms_timeout, const WiFi_RegDomain_S*  req);
META_RESULT  __stdcall META_WiFi_SetRegDomain_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_RegDomain_S*  req);
META_RESULT  __stdcall META_WiFi_SetDbmToDac(unsigned int  ms_timeout, const WiFi_DBM2DAC_Set_S* req);
META_RESULT  __stdcall META_WiFi_SetDbmToDac_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_DBM2DAC_Set_S* req);
META_RESULT  __stdcall META_WiFi_MACReg32Write(unsigned int  ms_timeout, const WiFi_MACReg32_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg32Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MACReg32_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg16Write(unsigned int  ms_timeout, const WiFi_MACReg16_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg16Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MACReg16_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_BBRegWrite(unsigned int  ms_timeout, const WiFi_BBReg8_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_BBRegWrite_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_BBReg8_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_EEPROM_Write(unsigned int  ms_timeout, const WiFi_EEPROM_S* array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_EEPROM_Write_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_EEPROM_S* array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_SetTxBw(unsigned int  ms_timeout, const wndrv_test_tx_bw_struct* req);
META_RESULT  __stdcall META_WiFi_SetTxBw_r(const int meta_handle, unsigned int  ms_timeout, const wndrv_test_tx_bw_struct* req);
META_RESULT  __stdcall META_WiFi_SetGi(unsigned int  ms_timeout, const wndrv_test_tx_gi_struct* req);
META_RESULT  __stdcall META_WiFi_SetGi_r(const int meta_handle, unsigned int  ms_timeout, const wndrv_test_tx_gi_struct* req);
META_RESULT  __stdcall META_WiFi_SetTxMode(unsigned int  ms_timeout, const wndrv_test_tx_mode_sel_struct* req);
META_RESULT  __stdcall META_WiFi_SetTxMode_r(const int meta_handle, unsigned int  ms_timeout, const wndrv_test_tx_mode_sel_struct* req);
META_RESULT  __stdcall META_WiFi_SetRxBw(unsigned int  ms_timeout, const wndrv_test_rx_bw_struct* req);
META_RESULT  __stdcall META_WiFi_SetRxBw_r(const int meta_handle, unsigned int  ms_timeout, const wndrv_test_rx_bw_struct* req);

//-----------------------------------------------------//
//  WiFi Calibration: WNDRV QUERY Functions            //
//-----------------------------------------------------//
META_RESULT  __stdcall META_WiFi_QueryTxStatus(unsigned int  ms_timeout, WiFi_TxStatus_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryTxStatus_r(const int meta_handle, unsigned int  ms_timeout, WiFi_TxStatus_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryTxStatus_Ex(unsigned int  ms_timeout, WiFi_TxStatus_Ex_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryTxStatus_Ex_r(const int meta_handle, unsigned int  ms_timeout, WiFi_TxStatus_Ex_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryRxStatus(unsigned int  ms_timeout, WiFi_RxStatus_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryRxStatus_r(const int meta_handle, unsigned int  ms_timeout, WiFi_RxStatus_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryChannelList(unsigned int  ms_timeout, WiFi_ChannelList_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryChannelList_r(const int meta_handle, unsigned int  ms_timeout, WiFi_ChannelList_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryRxCounter(unsigned int  ms_timeout, WiFi_RxCounter_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryRxCounter_r(const int meta_handle, unsigned int  ms_timeout, WiFi_RxCounter_S* cnf);
META_RESULT  __stdcall META_WiFi_QueryDbmToDac(unsigned int  ms_timeout, WiFi_DBM2DAC_Query_S*  cnf);
META_RESULT  __stdcall META_WiFi_QueryDbmToDac_r(const int meta_handle, unsigned int  ms_timeout, WiFi_DBM2DAC_Query_S*  cnf);
META_RESULT  __stdcall META_WiFi_MACReg32Read(unsigned int  ms_timeout, WiFi_MACReg32_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg32Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_MACReg32_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg16Read(unsigned int  ms_timeout, WiFi_MACReg16_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_MACReg16Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_MACReg16_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_BBRegRead(unsigned int  ms_timeout, WiFi_BBReg8_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_BBRegRead_r(const int meta_handle, unsigned int  ms_timeout, WiFi_BBReg8_S*  array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_EEPROM_Read(unsigned int  ms_timeout, WiFi_EEPROM_S* array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_EEPROM_Read_r(const int meta_handle, unsigned int  ms_timeout, WiFi_EEPROM_S* array, unsigned int array_cnt);
META_RESULT  __stdcall META_WiFi_DacDcOffsetAutoCalibration(unsigned int  ms_timeout, WiFi_DAC_DC_Offset_S*  cnf);
META_RESULT  __stdcall META_WiFi_DacDcOffsetAutoCalibration_r(const int meta_handle, unsigned int  ms_timeout, WiFi_DAC_DC_Offset_S*  cnf);
META_RESULT  __stdcall META_WiFi_QueryThermoSensor(unsigned int  ms_timeout, wndrv_test_peer_buff_them_sens_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryThermoSensor_r(const int meta_handle, unsigned int  ms_timeout, wndrv_test_peer_buff_them_sens_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryVoltageSensor(unsigned int  ms_timeout, wndrv_test_peer_buff_volt_sens_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryVoltageSensor_r(const int meta_handle, unsigned int  ms_timeout, wndrv_test_peer_buff_volt_sens_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryTssi(unsigned int  ms_timeout, wndrv_test_peer_buff_tssi_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryTssi_r(const int meta_handle, unsigned int  ms_timeout, wndrv_test_peer_buff_tssi_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryEfuse(unsigned int  ms_timeout, wndrv_test_peer_buff_efuse_struct*  cnf);
META_RESULT  __stdcall META_WiFi_QueryEfuse_r(const int meta_handle, unsigned int  ms_timeout, wndrv_test_peer_buff_efuse_struct*  cnf);

//-----------------------------------------------------//
//  WiFi Calibration: Exported Functions               //
//-----------------------------------------------------//
META_RESULT  __stdcall META_WiFi_QueryChipCapability(unsigned int  ms_timeout, WiFi_ChipCapability_S*  cnf);
META_RESULT  __stdcall META_WiFi_QueryChipCapability_r(const int meta_handle, unsigned int  ms_timeout, WiFi_ChipCapability_S*  cnf);
META_RESULT  __stdcall META_WiFi_SetMacAddress(unsigned int  ms_timeout, const WiFi_MacAddress_S*  mac);
META_RESULT  __stdcall META_WiFi_SetMacAddress_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_MacAddress_S*  mac);
META_RESULT  __stdcall META_WiFi_SetTxPower2400M(unsigned int  ms_timeout, const WiFi_TxPower_2400M_S*  txpwr);
META_RESULT  __stdcall META_WiFi_SetTxPower2400M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_2400M_S*  txpwr);
META_RESULT  __stdcall META_WiFi_SetTxPower5000M(unsigned int  ms_timeout, const WiFi_TxPower_5000M_S*  txpwr);
META_RESULT  __stdcall META_WiFi_SetTxPower5000M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxPower_5000M_S*  txpwr);
META_RESULT  __stdcall META_WiFi_SetDacDcOffset(unsigned int  ms_timeout, const WiFi_DAC_DC_Offset_S*  dac_dc_offset);
META_RESULT  __stdcall META_WiFi_SetDacDcOffset_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_DAC_DC_Offset_S*  dac_dc_offset);

META_RESULT  __stdcall META_WiFi_SetTxALC2400M(unsigned int  ms_timeout, const WiFi_TxALC_2400M_S*  txalc);
META_RESULT  __stdcall META_WiFi_SetTxALC2400M_r(const int meta_handle, unsigned int  ms_timeout, const WiFi_TxALC_2400M_S*  txalc);

//--------------------------------------------------------------------------//
//  BT Calibration                                                          //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  BT Calibration: data structure definition          //
//-----------------------------------------------------//

// BT Module ID
#define BT_NOT_SUPPORT        0x00000000
#define BTMODULE_MT6601       0x00000011
#define BTMODULE_MT6611       0x00000012
#define BTMODULE_MT6612       0x00000013
#define BTMODULE_MT6616       0x00000014
#define BTMODULE_MT6236       0x00000015
#define BTMODULE_MT6256       0x00000016
#define BTMODULE_MT6276       0x00000017
#define BTMODULE_MT6622       0x00000018
#define BTMODULE_MT6626       0x00000019
#define BTMODULE_MT6612_22_26 0x0000001A
#define BTMODULE_MT6255       0x0000001B
#define BTMODULE_MT6250       0x0000001C
#define BTMODULE_MT6260       0x0000001D
#define BTMODULE_RFMD3500     0x00000021
#define BTMODULE_RFMD4020     0x00000022

//#define BT_PACKET_LEN       339
#define BT_PACKET_LEN       1021  // because BT2.0 support at most 1021 bytes per packet
typedef struct
{
    unsigned char   id;
} BT_ModuleID_S;

typedef struct
{
    unsigned char   m_event;
    char            m_status;
    unsigned short  m_handle;
    unsigned char   m_len;
    unsigned char   m_parms[256];
} BT_HCI_EVENT;

typedef struct
{
    unsigned short  m_opcode;
    unsigned char   m_len;
    unsigned char   m_cmd[256];
} BT_HCI_COMMAND;
typedef struct
{
    unsigned short           m_con_hdl;
    unsigned short           m_len;
    unsigned char            m_buffer[BT_PACKET_LEN];
} BT_HCI_BUFFER;
typedef struct
{
    unsigned short           m_len;
    unsigned char            m_data[BT_PACKET_LEN];
} BT_HCI_PACKET;
typedef struct
{
    unsigned short           m_con_hdl;
    unsigned short           m_len;
    unsigned short           m_total_pks;
} BT_HCI_TX_PURE_TEST;

typedef struct
{
    unsigned int             m_used_time;
    unsigned short           m_len;
} BT_HCI_TX_PURE_TEST_STAT;

typedef struct
{
    unsigned int             m_used_time;
    unsigned short           m_len;
} BT_HCI_RX_PURE_TEST_STAT;

typedef struct
{
    unsigned int             m_u4UsedTime;
    unsigned short           m_u2PktSentNum;

} BT_HCI_TX_PURE_TEST_STAT_V2;

typedef struct
{
    unsigned char  m_u1Flag; /**< indicator that the FT task polling for the power on state */
    BT_HCI_COMMAND hci; /**< command buffer for the power on sequence */
} BT_POWER_ON_EX2_REQ_T;
//-----------------------------------------------------//
//  BT Calibration Functions                           //
//-----------------------------------------------------//
META_RESULT  __stdcall META_BT_QueryModuleID(unsigned int  ms_timeout, BT_ModuleID_S*  cnf);
META_RESULT  __stdcall META_BT_QueryModuleID_r(const int meta_handle, unsigned int  ms_timeout, BT_ModuleID_S*  cnf);

typedef void (__stdcall* META_BT_HCI_CNF)(const BT_HCI_EVENT* cnf, const short token, void* usrData);
typedef void (__stdcall* META_BT_HCI_TXDATA_CNF)(const BT_HCI_PACKET* cnf, const short token, void* usrData);
typedef void (__stdcall* META_BT_AUTO_HCI_CNF)(const BT_HCI_EVENT* cnf, const short token, void* usrData);
typedef void (__stdcall* META_BT_HCI_RXDATA_CNF)(const BT_HCI_BUFFER* cnf, const short token, void* usrData);

typedef void (__stdcall* META_BT_HCI_TXTEST_CNF)(const BT_HCI_TX_PURE_TEST_STAT* cnf, const short token, void* usrData);
typedef void (__stdcall* META_BT_HCI_RXTEST_CNF)(const BT_HCI_RX_PURE_TEST_STAT* cnf, const short token, void* usrData);

typedef void (__stdcall* META_BT_HCI_TXTEST_V2_CNF)(const BT_HCI_TX_PURE_TEST_STAT_V2* cnf, const short token, void* usrData);

typedef struct
{
    META_BT_HCI_TXDATA_CNF      m_SendDataCallback;
    META_BT_HCI_RXDATA_CNF      m_RecvDataCallback;
    META_BT_AUTO_HCI_CNF        m_AutoCallback;
    META_BT_HCI_TXTEST_CNF      m_TxTestCallback;
    META_BT_HCI_RXTEST_CNF      m_RxTestCallback;
    META_BT_HCI_TXTEST_V2_CNF   m_TxTestCallback_V2;
} BT_OtherCallBack;
META_RESULT  __stdcall META_BT_SendHCICommand(unsigned int  ms_timeout, BT_HCI_COMMAND* req, META_BT_HCI_CNF  cb, void*  cb_arg, unsigned char Cmpltcode);
META_RESULT  __stdcall META_BT_SendHCICommand_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_COMMAND* req, META_BT_HCI_CNF  cb, void*  cb_arg, unsigned char Cmpltcode);

META_RESULT  __stdcall META_BT_CancelHCICommand(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_CancelHCICommand_r(const int meta_handle, unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_SendHCIData(unsigned int  ms_timeout, BT_HCI_BUFFER* snd, META_BT_HCI_TXDATA_CNF  cb_tx, void*  cb_arg);
META_RESULT  __stdcall META_BT_SendHCIData_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_BUFFER* snd, META_BT_HCI_TXDATA_CNF  cb_tx, void*  cb_arg);
META_RESULT  __stdcall META_BT_RegisterAutoCallback(META_BT_AUTO_HCI_CNF cb_auto);
META_RESULT  __stdcall META_BT_RegisterAutoCallback_r(const int meta_handle, META_BT_AUTO_HCI_CNF cb_auto);
META_RESULT  __stdcall META_BT_ReceiveHCIData(META_BT_HCI_RXDATA_CNF cb_rx);
META_RESULT  __stdcall META_BT_ReceiveHCIData_r(const int meta_handle, META_BT_HCI_RXDATA_CNF cb_rx);

META_RESULT  __stdcall META_BT_TxPureTest(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST* snd, META_BT_HCI_TXTEST_CNF cb_tx, void*  cb_arg);
META_RESULT  __stdcall META_BT_TxPureTest_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST* snd, META_BT_HCI_TXTEST_CNF cb_tx, void*  cb_arg);
META_RESULT  __stdcall META_BT_RxTestStart(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall META_BT_RxTestStart_r(const int meta_handle, unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall META_BT_RxTestEnd(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_RxTestEnd_r(const int meta_handle, unsigned int  ms_timeout);

META_RESULT  __stdcall META_BT_TxPureTest_V2(unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST* snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void*  cb_arg);
META_RESULT  __stdcall META_BT_TxPureTest_V2_r(const int meta_handle, unsigned int  ms_timeout, BT_HCI_TX_PURE_TEST* snd, META_BT_HCI_TXTEST_V2_CNF cb_txtest, void*  cb_arg);

META_RESULT  __stdcall META_BT_RxTestStart_V2(unsigned int  ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);
META_RESULT  __stdcall META_BT_RxTestStart_V2_r(const int meta_handle, unsigned int ms_timeout, META_BT_HCI_RXTEST_CNF cb_rx);

META_RESULT  __stdcall META_BT_EnableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_EnableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_BT_DisableNvramOnlineUpdate(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_DisableNvramOnlineUpdate_r(const int meta_handle, unsigned int ms_timeout);


META_RESULT  __stdcall META_BT_EnablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_EnablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_BT_DisablePcmClockSyncSignal(unsigned int  ms_timeout);
META_RESULT  __stdcall META_BT_DisablePcmClockSyncSignal_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_BT_RemoveAutoCallback();
META_RESULT  __stdcall META_BT_RemoveAutoCallback_r(const int meta_handle);
META_RESULT  __stdcall META_BT_RemoveReceiveHCIDataCallback();
META_RESULT  __stdcall META_BT_RemoveReceiveHCIDataCallback_r(const int meta_handle);

META_RESULT __stdcall META_BT_POWERON_EX(const unsigned int ms_timeout, const unsigned char u1WaitFlag);
META_RESULT __stdcall META_BT_POWERON_EX_r(const int meta_handle, const unsigned int ms_timeout, const unsigned char u1WaitFlag);
META_RESULT __stdcall META_BT_POWEROFF_EX(const unsigned int ms_timeout, const unsigned char u1WaitFlag);
META_RESULT __stdcall META_BT_POWEROFF_EX_r(const int meta_handle, const unsigned int ms_timeout, const unsigned char u1WaitFlag);
META_RESULT __stdcall META_BT_POWERON_EX2(const unsigned int ms_timeout, const BT_POWER_ON_EX2_REQ_T* req);
META_RESULT __stdcall META_BT_POWERON_EX2_r(const int meta_handle, const unsigned int ms_timeout, const BT_POWER_ON_EX2_REQ_T* req);

//----------------------------------------------------------------//
//                              FM                                //
//----------------------------------------------------------------//

//--------------------------//
//    FM data structures    //
//--------------------------//
typedef enum
{
    FM_CHIP_ID_MT6189AN = 0,
    FM_CHIP_ID_MT6189BN_CN = 1,
    FM_CHIP_ID_MT6188A = 3,
    FM_CHIP_ID_MT6188C = 4,
    FM_CHIP_ID_MT6188D = 5,
    FM_CHIP_ID_MT6616 = 6,
    FM_CHIP_ID_MT6276 = 7,
    FM_CHIP_ID_MT6256 = 8,
    FM_CHIP_ID_MT6251 = 9,
    FM_CHIP_ID_MT6626 = 10,
    FM_CHIP_ID_MT6255 = 11,
    FM_CHIP_ID_MT6250 = 12,
    FM_CHIP_ID_MT6260 = 13,
} FM_CHIP_ID_E;

typedef struct
{
    unsigned char m_ucChipId;
} FM_CHIP_ID_CNF_T;

typedef struct
{
    short m_i2CurFreq;  // freq range is [875, 1080]
} FM_FREQ_REQ_T;



typedef struct
{
    unsigned char m_ucSignalLevel;
} FM_RSSI_CNF_T;

typedef struct
{
    //unsigned char m_ucIfCnt;
    unsigned short m_u2IfCnt;

} FM_IF_CNT_CNF_T;

typedef struct
{
    unsigned short m_u2MonoOrStereo;  // 0: mono, 1: stereo
    unsigned short m_u2SblendOnOrOff; // 0: sblend off, 1: sblend on
    unsigned int   m_u4ItemValue;  // 0: disable, 1: enable

} FM_MONO_STEREO_BLEND_REQ_T;

typedef struct  // freq range is [875, 1080]
{
    short m_i2StartFreq;    // note: when we try to search next: start freq should <= stop freq
    short m_i2StopFreq;     // note: when we try to search prev: start freq should >= stop freq

} FM_FREQ_RANGE_REQ_T;

typedef struct
{
    unsigned char m_ucExit;      // 0: don't exist, 1: exist
    short         m_i2ValidFreq; // -1: settings error, 0: invalid freq, others: 875-1080 valid

} FM_VAILD_FREQ_CNF_T;

typedef struct
{
    unsigned int m_u4RssiThreshold;

} FM_RSSI_THRESHOLD_REQ_T;

typedef struct
{
    unsigned int m_u4IfCntDelta;

} FM_IF_CNT_DELTA_REQ_T;


typedef struct
{
    unsigned char m_ucAddr;

} FM_READ_BYTE_ADDR_REQ_T;


typedef struct
{
    unsigned short m_u2ReadByte;

} FM_READ_BYTE_CNF_T;


typedef struct
{
    unsigned char m_ucAddr;
    unsigned short m_u2WriteByte;
} FM_WRITE_BYTE_REQ_T;

typedef struct
{
    unsigned char m_bOnOff;  // 0: off, 1: on

} FM_SOFT_MUTE_ONOFF_REQ_T;

typedef struct
{
    unsigned char m_ucStage;  // 1~3
} FM_STAGE_REQ_T;

typedef struct
{
    unsigned char  m_ucHighOrLow;
} FM_HL_Side_CNF_T;

typedef struct
{
    unsigned char m_ucStereoOrMono;

} FM_Stereo_Mono_CNF_T;

// for MT6616 new API
typedef struct
{
    unsigned char m_ucVolume;
    char m_cDigitalGainIndex;
} FM_Volume_Setting_REQ_T;

typedef struct
{
    unsigned short m_u2Bitmap[16];
} FM_AutoScan_CNF_T;

typedef struct
{
    unsigned char m_ucRDSOn;
} FM_SetRDS_REQ_T;

typedef struct
{
    unsigned char m_ucRXFilterBW;
} FM_RX_FilterBW_CNF_T;

typedef struct
{
    unsigned char m_ucPAMDLevel;
} FM_PAMD_Level_CNF_T;

typedef struct
{
    unsigned char m_ucMR;
} FM_MR_CNF_T;

typedef struct
{
    unsigned int m_u4DecodeMode;
} FM_Decode_Mode_REQ_T;

typedef struct
{
    unsigned int m_u4HCC;
} FM_HCC_REQ_T;

typedef struct
{
    unsigned int m_u4PAMDThreshold;
} FM_PAMD_Threshold_REQ_T;

typedef struct
{
    unsigned int m_u4SoftmuteEnable;
} FM_Softmute_Enable_REQ_T;

typedef struct
{
    unsigned int m_u4DeemphasisLevel;
} FM_Deemphasis_Level_REQ_T;

typedef struct
{
    unsigned int m_u4HLSide;
} FM_HL_Side_REQ_T;

typedef struct
{
    unsigned int m_u4DemodBandwidth;
} FM_Demod_Bandwidth_REQ_T;

typedef struct
{
    unsigned int m_u4DynamicLimiter;
} FM_DynamicLimiter_REQ_T;

typedef struct
{
    unsigned int m_u4SoftmuteRate;
} FM_Softmute_Rate_REQ_T;

typedef enum
{
    RDS_CMD_NONE = 0,   // No command. This is usually an error.
    RDS_CMD_PI_CODE,
    RDS_CMD_PTY_CODE,
    RDS_CMD_PROGRAMNAME,
    RDS_CMD_LOCDATETIME,
    RDS_CMD_UTCDATETIME,
    RDS_CMD_LAST_RADIOTEXT,
    RDS_CMD_AF,
    RDS_CMD_AF_LIST,
    RDS_CMD_AFON,
    RDS_CMD_TAON,
    RDS_CMD_TAON_OFF
} RdsCmd;

typedef enum
{
    RDS_FLAG_IS_TP              = 0x0001, /**< Program is a traffic program */
    RDS_FLAG_IS_TA              = 0x0002, /**< Program currently broadcasts a traffic ann. */
    RDS_FLAG_IS_MUSIC           = 0x0004, /**< Program currently broadcasts music */
    RDS_FLAG_IS_STEREO          = 0x0008, /**< Program is transmitted in stereo */
    RDS_FLAG_IS_ARTIFICIAL_HEAD = 0x0010, /**< Program is an artificial head recording */
    RDS_FLAG_IS_COMPRESSED      = 0x0020, /**< Program content is compressed */
    RDS_FLAG_IS_DYNAMIC_PTY     = 0x0040, /**< Program type can change */
    RDS_FLAG_TEXT_AB            = 0x0080  /**< If this flag changes state, a new radio text string begins */
} RdsFlag;

typedef enum
{
    RDS_EVENT_FLAGS          = 0x0001, /**< One of the RDS flags has changed state */
    RDS_EVENT_PI_CODE        = 0x0002, /**< The program identification code has changed */
    RDS_EVENT_PTY_CODE       = 0x0004, /**< The program type code has changed */
    RDS_EVENT_PROGRAMNAME    = 0x0008, /**< The program name has changed */
    RDS_EVENT_UTCDATETIME    = 0x0010, /**< A new UTC date/time is available */
    RDS_EVENT_LOCDATETIME    = 0x0020, /**< A new local date/time is available */
    RDS_EVENT_LAST_RADIOTEXT = 0x0040, /**< A radio text string was completed */
    RDS_EVENT_AF             = 0x0080, /**< Current Channel RF signal strength too weak, need do AF switch */
    RDS_EVENT_AF_LIST        = 0x0100, /**< An alternative frequency list is ready */
    RDS_EVENT_AFON_LIST      = 0x0200, /**< An alternative frequency list is ready */
    RDS_EVENT_TAON           = 0x0400,  /**< Other Network traffic announcement start */
    RDS_EVENT_TAON_OFF       = 0x0800 /**< Other Network traffic announcement finished. */
} RdsEvent;

typedef struct
{
    RdsCmd m_eCmd;
} FM_RDS_Info_REQ_T;

typedef struct
{
    unsigned short m_buffer[64];
} FM_RDS_Info_CNF_T;

typedef struct
{
    RdsFlag m_eFlag;
    unsigned short m_buffer[64];
} FM_RDS_Status_CNF_T;

typedef struct
{
    unsigned short m_u2GoodBlock;
} FM_RDS_Good_Block_Counter_CNF_T;

typedef struct
{
    unsigned short m_u2BadBlock;
} FM_RDS_Bad_Block_Counter_CNF_T;

typedef struct
{
    unsigned short m_u2GroupCounter[32];
} FM_RDS_Group_Counter_CNF_T;

typedef struct
{
    short m_i2StartFreq;
    unsigned char m_ucDirection;
} FM_HWSeek_REQ_T;

typedef struct
{
    short m_i2EndFreq;
} FM_HWSeek_CNF_T;


typedef struct
{
    unsigned short m_u2StereoBlendControl;
} FM_SetStereoBlend_REQ_T;

typedef struct
{
    unsigned short m_u2Blocks[8];
} FM_RDS_Block_CNF_T;

//--------------------------//
//      FM Functions        //
//--------------------------//
META_RESULT  __stdcall META_FM_GetChipId(unsigned int ms_timeout, FM_CHIP_ID_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetChipId_r(const int meta_handle, unsigned int ms_timeout, FM_CHIP_ID_CNF_T* cnf);
const char* __stdcall META_FM_GetChipIdName(unsigned int id);
const char* __stdcall META_FM_GetChipIdName_r(const int meta_handle, unsigned int id);
META_RESULT  __stdcall META_FM_PowerOn(unsigned int ms_timeout);
META_RESULT  __stdcall META_FM_PowerOn_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_FM_PowerOff(unsigned int ms_timeout);
META_RESULT  __stdcall META_FM_PowerOff_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_FM_SetFreq(unsigned int ms_timeout, FM_FREQ_REQ_T* req);
META_RESULT  __stdcall META_FM_SetFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req);

META_RESULT  __stdcall META_FM_GetRSSI(unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_RSSI_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetRSSI_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_RSSI_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetIfCnt(unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_IF_CNT_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetIfCnt_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_IF_CNT_CNF_T* cnf);

META_RESULT __stdcall META_FM_SearchNextFreq(unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T* req, FM_VAILD_FREQ_CNF_T* cnf);
META_RESULT __stdcall META_FM_SearchNextFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T* req, FM_VAILD_FREQ_CNF_T* cnf);

META_RESULT __stdcall META_FM_SearchPrevFreq(unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T* req, FM_VAILD_FREQ_CNF_T* cnf);
META_RESULT __stdcall META_FM_SearchPrevFreq_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_RANGE_REQ_T* req, FM_VAILD_FREQ_CNF_T* cnf);

META_RESULT  __stdcall META_FM_SetMonoOrStereo_Blend(unsigned int ms_timeout, FM_MONO_STEREO_BLEND_REQ_T* req);
META_RESULT  __stdcall META_FM_SetMonoOrStereo_Blend_r(const int meta_handle, unsigned int ms_timeout, FM_MONO_STEREO_BLEND_REQ_T* req);

META_RESULT  __stdcall META_FM_SetRssiThreold(unsigned int ms_timeout, FM_RSSI_THRESHOLD_REQ_T* req);
META_RESULT  __stdcall META_FM_SetRssiThreold_r(const int meta_handle, unsigned int ms_timeout, FM_RSSI_THRESHOLD_REQ_T* req);

META_RESULT  __stdcall META_FM_SetIfCntDelta(unsigned int ms_timeout, FM_IF_CNT_DELTA_REQ_T* req);
META_RESULT  __stdcall META_FM_SetIfCntDelta_r(const int meta_handle, unsigned int ms_timeout, FM_IF_CNT_DELTA_REQ_T* req);

META_RESULT __stdcall META_FM_ReadByte(unsigned int ms_timeout, FM_READ_BYTE_ADDR_REQ_T* req, FM_READ_BYTE_CNF_T* cnf);
META_RESULT __stdcall META_FM_ReadByte_r(const int meta_handle, unsigned int ms_timeout, FM_READ_BYTE_ADDR_REQ_T* req, FM_READ_BYTE_CNF_T* cnf);

META_RESULT  __stdcall META_FM_WriteByte(unsigned int ms_timeout, FM_WRITE_BYTE_REQ_T* req);
META_RESULT  __stdcall META_FM_WriteByte_r(const int meta_handle, unsigned int ms_timeout, FM_WRITE_BYTE_REQ_T* req);

META_RESULT  __stdcall META_FM_SetSoftMute(unsigned int ms_timeout, FM_SOFT_MUTE_ONOFF_REQ_T* req);
META_RESULT  __stdcall META_FM_SetSoftMute_r(const int meta_handle, unsigned int ms_timeout, FM_SOFT_MUTE_ONOFF_REQ_T* req);

META_RESULT  __stdcall META_FM_SelectSoftMuteStage(unsigned int ms_timeout, FM_STAGE_REQ_T* req);
META_RESULT  __stdcall META_FM_SelectSoftMuteStage_r(const int meta_handle, unsigned int ms_timeout, FM_STAGE_REQ_T* req);

META_RESULT  __stdcall META_FM_SelectSBlendStage(unsigned int ms_timeout, FM_STAGE_REQ_T* req);
META_RESULT  __stdcall META_FM_SelectSBlendStage_r(const int meta_handle, unsigned int ms_timeout, FM_STAGE_REQ_T* req);

META_RESULT  __stdcall META_FM_GetHighOrLowSide(unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_HL_Side_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetHighOrLowSide_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_HL_Side_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetStereoOrMono(unsigned int ms_timeout, FM_Stereo_Mono_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetStereoOrMono_r(const int meta_handle, unsigned int ms_timeout, FM_Stereo_Mono_CNF_T* cnf);

// for MT6616 new API

META_RESULT  __stdcall META_FM_SetVolume(unsigned int ms_timeout, FM_Volume_Setting_REQ_T* req);
META_RESULT  __stdcall META_FM_SetVolume_r(const int meta_handle, unsigned int ms_timeout, FM_Volume_Setting_REQ_T* req);

META_RESULT  __stdcall META_FM_AutoScan(unsigned int ms_timeout, FM_AutoScan_CNF_T* cnf);
META_RESULT  __stdcall META_FM_AutoScan_r(const int meta_handle, unsigned int ms_timeout, FM_AutoScan_CNF_T* cnf);

META_RESULT  __stdcall META_FM_SetRDS(unsigned int ms_timeout, FM_SetRDS_REQ_T* req);
META_RESULT  __stdcall META_FM_SetRDS_r(const int meta_handle, unsigned int ms_timeout, FM_SetRDS_REQ_T* req);

META_RESULT  __stdcall META_FM_GetRXFilterBW(unsigned int ms_timeout, FM_RX_FilterBW_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetRXFilterBW_r(const int meta_handle, unsigned int ms_timeout, FM_RX_FilterBW_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetPAMDLevel(unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_PAMD_Level_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetPAMDLevel_r(const int meta_handle, unsigned int ms_timeout, FM_FREQ_REQ_T* req, FM_PAMD_Level_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetMR(unsigned int ms_timeout, FM_MR_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetMR_r(const int meta_handle, unsigned int ms_timeout, FM_MR_CNF_T* cnf);

META_RESULT  __stdcall META_FM_SetDecodeMode(unsigned int ms_timeout, FM_Decode_Mode_REQ_T* req);
META_RESULT  __stdcall META_FM_SetDecodeMode_r(const int meta_handle, unsigned int ms_timeout, FM_Decode_Mode_REQ_T* req);

META_RESULT  __stdcall META_FM_SetHCC(unsigned int ms_timeout, FM_HCC_REQ_T* req);
META_RESULT  __stdcall META_FM_SetHCC_r(const int meta_handle, unsigned int ms_timeout, FM_HCC_REQ_T* req);

META_RESULT  __stdcall META_FM_SetPAMDThreshold(unsigned int ms_timeout, FM_PAMD_Threshold_REQ_T* req);
META_RESULT  __stdcall META_FM_SetPAMDThreshold_r(const int meta_handle, unsigned int ms_timeout, FM_PAMD_Threshold_REQ_T* req);

META_RESULT  __stdcall META_FM_SetSoftmute(unsigned int ms_timeout, FM_Softmute_Enable_REQ_T* req);
META_RESULT  __stdcall META_FM_SetSoftmute_r(const int meta_handle, unsigned int ms_timeout, FM_Softmute_Enable_REQ_T* req);

META_RESULT  __stdcall META_FM_SetDeemphasisLevel(unsigned int ms_timeout, FM_Deemphasis_Level_REQ_T* req);
META_RESULT  __stdcall META_FM_SetDeemphasisLevel_r(const int meta_handle, unsigned int ms_timeout, FM_Deemphasis_Level_REQ_T* req);

META_RESULT  __stdcall META_FM_SetHLSide(unsigned int ms_timeout, FM_HL_Side_REQ_T* req);
META_RESULT  __stdcall META_FM_SetHLSide_r(const int meta_handle, unsigned int ms_timeout, FM_HL_Side_REQ_T* req);

META_RESULT  __stdcall META_FM_SetDemodBW(unsigned int ms_timeout, FM_Demod_Bandwidth_REQ_T* req);
META_RESULT  __stdcall META_FM_SetDemodBW_r(const int meta_handle, unsigned int ms_timeout, FM_Demod_Bandwidth_REQ_T* req);

META_RESULT  __stdcall META_FM_SetDynamicLimiter(unsigned int ms_timeout, FM_DynamicLimiter_REQ_T* req);
META_RESULT  __stdcall META_FM_SetDynamicLimiter_r(const int meta_handle, unsigned int ms_timeout, FM_DynamicLimiter_REQ_T* req);

META_RESULT  __stdcall META_FM_SetSoftmuteRate(unsigned int ms_timeout, FM_Softmute_Rate_REQ_T* req);
META_RESULT  __stdcall META_FM_SetSoftmuteRate_r(const int meta_handle, unsigned int ms_timeout, FM_Softmute_Rate_REQ_T* req);

// RDS Info
META_RESULT  __stdcall META_FM_GetPI(unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetPI_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetPTY(unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetPTY_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetPS(unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetPS_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetAF(unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetAF_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetRT(unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetRT_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Info_REQ_T* req, FM_RDS_Info_CNF_T* cnf);

// RDS Status

META_RESULT  __stdcall META_FM_GetTP(unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetTP_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetTA(unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetTA_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetMS(unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetMS_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Status_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetGoodBlockCounter(unsigned int ms_timeout, FM_RDS_Good_Block_Counter_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetGoodBlockCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Good_Block_Counter_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetBadBlockCounter(unsigned int ms_timeout, FM_RDS_Bad_Block_Counter_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetBadBlockCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Bad_Block_Counter_CNF_T* cnf);

META_RESULT  __stdcall META_FM_ResetBlockCounter(unsigned int ms_timeout);
META_RESULT  __stdcall META_FM_ResetBlockCounter_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_FM_GetGroupCounter(unsigned int ms_timeout, FM_RDS_Group_Counter_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetGroupCounter_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Group_Counter_CNF_T* cnf);

META_RESULT  __stdcall META_FM_ResetGroupCounter(unsigned int ms_timeout);
META_RESULT  __stdcall META_FM_ResetGroupCounter_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_FM_HWSeek(unsigned int ms_timeout, FM_HWSeek_REQ_T* req, FM_HWSeek_CNF_T* cnf);
META_RESULT  __stdcall META_FM_HWSeek_r(const int meta_handle, unsigned int ms_timeout, FM_HWSeek_REQ_T* req, FM_HWSeek_CNF_T* cnf);

META_RESULT  __stdcall META_FM_HWSearch_Stop(unsigned int ms_timeout);
META_RESULT  __stdcall META_FM_HWSearch_Stop_r(const int meta_handle, unsigned int ms_timeout);

META_RESULT  __stdcall META_FM_SetStereoBlend(unsigned int ms_timeout, FM_SetStereoBlend_REQ_T* req);
META_RESULT  __stdcall META_FM_SetStereoBlend_r(const int meta_handle, unsigned int ms_timeout, FM_SetStereoBlend_REQ_T* req);

META_RESULT  __stdcall META_FM_GetRDSLogData(unsigned int ms_timeout, FM_RDS_Block_CNF_T* cnf);
META_RESULT  __stdcall META_FM_GetRDSLogData_r(const int meta_handle, unsigned int ms_timeout, FM_RDS_Block_CNF_T* cnf);

META_RESULT  __stdcall META_FM_GetRDSBLERRatio(unsigned int ms_timeout, unsigned short* bler);
META_RESULT  __stdcall META_FM_GetRDSBLERRatio_r(const int meta_handle, unsigned int ms_timeout, unsigned short* bler);

typedef void (__stdcall* META_FM_RDS_INFO_UPDATE_CNF)(const FM_RDS_Info_CNF_T* cnf, const short token, void* usrData);
typedef void (__stdcall* META_FM_RDS_STATUS_UPDATE_CNF)(const FM_RDS_Status_CNF_T* cnf, const short token, void* usrData);
typedef struct
{
    META_FM_RDS_INFO_UPDATE_CNF m_RDSInfoUpdateCallback;
    META_FM_RDS_STATUS_UPDATE_CNF m_RDSStatusUpdateCallback;
} FM_RDSCallBack;
META_RESULT  __stdcall META_FM_RegisterRDSInfoUpdateCallback(META_FM_RDS_INFO_UPDATE_CNF cb);
META_RESULT  __stdcall META_FM_RegisterRDSInfoUpdateCallback_r(const int meta_handle, META_FM_RDS_INFO_UPDATE_CNF cb);
META_RESULT  __stdcall META_FM_RegisterRDSStatusUpdateCallback(META_FM_RDS_STATUS_UPDATE_CNF cb);
META_RESULT  __stdcall META_FM_RegisterRDSStatusUpdateCallback_r(const int meta_handle, META_FM_RDS_STATUS_UPDATE_CNF cb);
META_RESULT  __stdcall META_FM_RemoveRDSInfoUpdateCallback(void);
META_RESULT  __stdcall META_FM_RemoveRDSInfoUpdateCallback_r(const int meta_handle);
META_RESULT  __stdcall META_FM_RemoveRDSStatusUpdateCallback(void);
META_RESULT  __stdcall META_FM_RemoveRDSStatusUpdateCallback_r(const int meta_handle);

META_RESULT  __stdcall META_FM_GetAntennaType(unsigned int ms_timeout, char* type);
META_RESULT  __stdcall META_FM_GetAntennaType_r(const int meta_handle, int ms_timeout, char* type);
META_RESULT  __stdcall META_FM_SetAntennaType(unsigned int ms_timeout, char type);
META_RESULT  __stdcall META_FM_SetAntennaType_r(const int meta_handle, int ms_timeout, char type);
META_RESULT  __stdcall META_FM_QueryCapArray(unsigned int ms_timeout, float* cap_id);
META_RESULT  __stdcall META_FM_QueryCapArray_r(const int meta_handle, int ms_timeout, float* cap_id);
/**
 * @}
 */
#endif // #ifndef __META_CONNECTIIVTY_H__

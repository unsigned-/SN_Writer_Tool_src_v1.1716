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
 * meta_dll_audio.h
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
#ifndef __META_AUDIO_H__
#define __META_AUDIO_H__
/**
 * \addtogroup Audio
 *  @{
 */
#define META_NVRAM_DESC_DEPTH    3
#define META_NVRAM_DESC_LENGTH   255
#define META_NVRAM_DESC_NUM      255

typedef struct
{
    unsigned int    u4ByteOffset;
    unsigned int    u4Length;  // unit: u1ElementSize, not bytes!
    unsigned char   u1ElementSize; // unit: bytes
    int             i4ElementNum; // element number
    unsigned char   u1ValidDepth;
    char            desc[META_NVRAM_DESC_DEPTH][META_NVRAM_DESC_LENGTH];

} meta_nvram_lid_desc_entry;

typedef struct
{
    int valid_num;
    int struct_size;
    meta_nvram_lid_desc_entry list[META_NVRAM_DESC_NUM];
} meta_nvram_lid_desc_t;

NON_REENTRANT_FUNC META_RESULT __stdcall META_NVRAM_AudioGainTableDescription(meta_nvram_lid_desc_t* pDescList);
META_RESULT __stdcall META_NVRAM_AudioGainTableDescription_r(const int meta_handle, meta_nvram_lid_desc_t* pDescList);
NON_REENTRANT_FUNC META_RESULT __stdcall META_NVRAM_AudioGainTable_Len(int* len);
META_RESULT  __stdcall META_NVRAM_AudioGainTable_Len_r(const int meta_handle, int* len);
// Speech Coefficient
typedef struct
{
    short       Speech_8k_Input_Coeff[30];      // FIR for input speech (microphone) with 8k sampling rate
    short       Speech_8k_Output_Coeff[30];     // FIR for output speech (speaker) with 8k sampling rate
    short       Speech_16k_Input_Coeff[62];     // FIR for input speech (microphone) with 16k sampling rate
    short       Speech_16k_Output_Coeff[62];    // FIR for output speech (speaker) with 16k sampling rate

    short       Additional_Speech_8k_Output_Coeff[5][30];   // The additional FIR for output speech (speaker) with 8k sampling rate

    unsigned short  Speech_8k_Output_Coeff_Index;   // The active FIR index
    // 0 -> Speech_8k_Output_Coeff
    // 1 -> Additional_Speech_8k_Output_Coeff[0]
    // 2 -> Additional_Speech_8k_Output_Coeff[1]
    // 3 -> Additional_Speech_8k_Output_Coeff[2]
    // 4 -> Additional_Speech_8k_Output_Coeff[3]
    // 5 -> Additional_Speech_8k_Output_Coeff[4]
} L1_SpeechCoeff_T;

// Melody Coefficient
typedef struct
{
    short       Melody_32k_Output_Coeff[45];    // FIR for melody playback with with 32k sampling rate
} L1_MelodyCoeff_T;

// L1Audio Param
typedef struct
{
    L1_SpeechCoeff_T    Speech_FIR[2];  // [0]: normal mode
    // [1]: headset mode
    // NOTE: In headset mode, Additional_Speech_8k_Output_Coeff and
    //       Speech_8k_Output_Coeff_Index are ignored! you can just
    //       leave them alone.

    L1_MelodyCoeff_T    Melody_FIR[2];  // [0]: loud speaker mode
    // [1]: stereo speaker mode
    unsigned short      ES_TimeConst;
    unsigned short      ES_VolConst;
    unsigned short      ES_TimeConst2;
    unsigned short      ES_VolConst2;
    unsigned short      Media_Playback_Maximum_Swing;
} l1audio_param_T;

// L1Audio Param from W0547

#define SPEECH_NORMAL_MODE          0
#define SPEECH_EARPHONE_MODE        1
#define SPEECH_LOUDSPEAKER_MODE     2
#define SPEECH_BT_ERAPHONE_MODE     3
#define SPEECH_BT_CORDLESS_MODE     4
#define SPEECH_AUX1_MODE            5
#define SPEECH_AUX2_MODE            6
#define SPEECH_AUX3_MODE            7

typedef struct
{
    L1_SpeechCoeff_T    Speech_FIR[2];  // [0]: normal mode
    // [1]: headset mode
    // NOTE: In headset mode, Additional_Speech_8k_Output_Coeff and
    //       Speech_8k_Output_Coeff_Index are ignored! you can just
    //       leave them alone.

    L1_MelodyCoeff_T    Melody_FIR[2];  // [0]: loud speaker mode
    // [1]: stereo speaker mode

    unsigned short      Speech_Common_Para[12];

    unsigned short      Speech_ModeDependent_Para[8][8];    // [0]: Normal Mode
    // [1]: Earphone Mode
    // [2]: Loud Speaker Mode
    // [3]: BlueTooth Earphone Mode
    // [4]: BlueTooth Cordless Mode
    // [5]: AUX1 Mode
    // [6]: AUX2 Mode
    // [7]: AUX3 Mode
    unsigned short      Media_Playback_Maximum_Swing;
} l1audio_param_W0547_T;


typedef struct
{
    short speech_input_FIR_coeffs[6][45];
    short speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_normal_mode_para[8];
    unsigned short speech_earphone_mode_para[8];
    unsigned short speech_loudspk_mode_para[8];
    unsigned short speech_bt_earphone_mode_para[8];
    unsigned short speech_bt_cordless_mode_para[8];
    unsigned short speech_aux1_mode_para[8];
    unsigned short speech_aux2_mode_para[8];
    unsigned short speech_aux3_mode_para[8];
    unsigned short Media_Playback_Maximum_Swing;
    short Melody_FIR_Output_Coeff_32k_Tbl1[45];
} l1audio_param_W0547_45_T;

typedef struct
{
    short speech_input_FIR_coeffs[6][45];
    short speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_normal_mode_para[8];
    unsigned short speech_earphone_mode_para[8];
    unsigned short speech_loudspk_mode_para[8];
    unsigned short speech_bt_earphone_mode_para[8];
    unsigned short speech_bt_cordless_mode_para[8];
    unsigned short speech_aux1_mode_para[8];
    unsigned short speech_aux2_mode_para[8];
    unsigned short speech_aux3_mode_para[8];
    unsigned short Media_Playback_Maximum_Swing;
    short Melody_FIR_Output_Coeff_32k_Tbl1[25];
} l1audio_param_W0712_T;


typedef struct
{
    short          speech_input_FIR_coeffs[6][45];
    short          speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_mode_para[8][8];
    unsigned short Media_Playback_Maximum_Swing;
    short          Melody_FIR_Coeff_Tbl[25];
    short          audio_compensation_coeff[2][45];  // new added, so different with others structure

} l1audio_param_W0740_T;


typedef struct
{
    short          speech_input_FIR_coeffs[6][45];
    short          speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_mode_para[8][16];
    unsigned short speech_volume_para[3][7][4];
    unsigned short Media_Playback_Maximum_Swing;
    short          Melody_FIR_Coeff_Tbl[25];
    short          audio_compensation_coeff[2][45];  // new added, so different with others structure

} l1audio_param_W0809_T; //l1audio_param_W0748_T;


typedef struct
{
    short          speech_input_FIR_coeffs[6][45];
    short          speech_output_FIR_coeffs[6][45];
    unsigned short selected_FIR_output_index;
    unsigned short speech_common_para[12];
    unsigned short speech_mode_para[8][16];
    unsigned short speech_volume_para[3][7][4];
    unsigned short Media_Playback_Maximum_Swing;
    short          Melody_FIR_Coeff_Tbl[25];
    short          audio_compensation_coeff[3][45];  // three ACFs for special branches in w10.18

} l1audio_param_EX_T;  // from W10.21

typedef struct
{
    /* Volume */
    short vol_calibration_shift[8];
    short vol_calibration_subband[8];
    /* Delay */
    short delay_cal_int;
    short delay_cal_frac;
    short delay_cal_subband[8];
    /* Leakage */
    short power_ratio_scale;
    short wind_index_threshold;
    short subband_bmg[8];
    /* Mockup Diagnosis */
    short mockup_level;
    short shielding_level;
    short NR_Level;
    /* Reserve */
    short reserve[5];
} audio_dual_mic_nb_param_struct;

typedef struct
{
    /* Volume */
    short vol_calibration_shift[16];
    short vol_calibration_subband[16];
    /* Delay */
    short delay_cal_int;
    short delay_cal_frac;
    short delay_cal_subband[16];
    /* Leakage */
    short power_ratio_scale;
    short wind_index_threshold;
    short subband_bmg[16];
    /* Mockup Diagnosis */
    short mockup_level;
    short shielding_level;
    short NR_Level;
    /* Reserve */
    short reserve[5];
} audio_dual_mic_wb_param_struct;

typedef struct
{
    audio_dual_mic_nb_param_struct nb_param; /* narrow band parameter */
    audio_dual_mic_wb_param_struct wb_param; /* wide   band parameter */
} audio_dual_mic_param_struct;

typedef struct
{
    short audio_compensation_filter_sw_ver_coeffs[3][3][45];
} l1audio_swfir_T;

typedef struct
{
    short         count;
    short         index;
    char          magnitude[8][30];
    unsigned char setting_name[9][48];
} nvram_ef_audio_equalizer_struct;

typedef struct
{
    unsigned char audio_bes_eq_initial_parameter[122];
} nvram_ef_audio_bes_eq_flexible_struct;

// Custom Acoustic Volume
#define MAX_VOL_CATE        3
#define MAX_VOL_TYPE        7
#define MAX_VOL_LEVEL       7
typedef struct
{
    unsigned char   volume_gain[MAX_VOL_CATE][MAX_VOL_TYPE][MAX_VOL_LEVEL];
    // Volume Gain: [Mode (Normal, Headset, LoudSpeaker)]
    //              [Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]
    //              [Level (1~7)]

    unsigned char   volume[MAX_VOL_CATE][MAX_VOL_TYPE];
    // Current Volume Level:    [Mode (Normal, Headset, LoudSpeaker)]
    //                          [Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]
    //                          value: 0~6 [ Level_1(0) ~ Level_7(6) ]

} CustAcousticVol_T;
typedef struct
{
    unsigned char   volume_gain[MAX_VOL_CATE][MAX_VOL_TYPE][MAX_VOL_LEVEL];
    // Volume Gain: [Mode (Normal, Headset, LoudSpeaker)]
    //              [Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]
    //              [Level (1~7)]

    unsigned char   volume[MAX_VOL_CATE][MAX_VOL_TYPE];
    // Current Volume Level:    [Mode (Normal, Headset, LoudSpeaker)]
    //                          [Tone type (CallTone, Keytone, MIC, GMI, Speech, SideTone, Melody) ]
    //                          value: 0~6 [ Level_1(0) ~ Level_7(6) ]
    unsigned char max_melody_volume_gain[MAX_VOL_CATE + 1];
    unsigned char melody_volume_gain_step[MAX_VOL_CATE + 1];
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];
} CustAcousticVol16lvl_T;
// L1Audio Param
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_AudioParam_Len(int* len);
META_RESULT  __stdcall META_NVRAM_AudioParam_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam(const l1audio_param_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_r(const int meta_handle, const l1audio_param_T* param, char* buf, const int buf_len);
//l1audio_param_W0740_T
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0740(const l1audio_param_W0740_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0740_r(const int meta_handle, const l1audio_param_W0740_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0740(l1audio_param_W0740_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0740_r(const int meta_handle, l1audio_param_W0740_T* param, const char* buf, const int buf_len);

// l1audio_param_W0809_T
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0809(const l1audio_param_W0809_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0809_r(const int meta_handle, const l1audio_param_W0809_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0809(l1audio_param_W0809_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0809_r(const int meta_handle, l1audio_param_W0809_T* param, const char* buf, const int buf_len);

// Custom Acoustic Volume
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_CustAcousticVol_Len(int* len);
META_RESULT  __stdcall META_NVRAM_CustAcousticVol_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_CustAcousticVol(const CustAcousticVol_T* cust_acoustic_vol, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_CustAcousticVol_r(const int meta_handle, const CustAcousticVol_T* cust_acoustic_vol, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_CustAcousticVol(CustAcousticVol_T* cust_acoustic_vol, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_CustAcousticVol_r(const int meta_handle, CustAcousticVol_T* cust_acoustic_vol, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_16lvlCustAcousticVol(const CustAcousticVol16lvl_T* cust_acoustic_vol, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_16lvlCustAcousticVol_r(const int meta_handle, const CustAcousticVol16lvl_T* cust_acoustic_vol, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_16lvlCustAcousticVol(CustAcousticVol16lvl_T* cust_acoustic_vol, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_16lvlCustAcousticVol_r(const int meta_handle, CustAcousticVol16lvl_T* cust_acoustic_vol, const char* buf, const int buf_len);

// l1audio_param_EX_T
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_EX(const l1audio_param_EX_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_EX_r(const int meta_handle, const l1audio_param_EX_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_EX(l1audio_param_EX_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_EX_r(const int meta_handle, l1audio_param_EX_T* param, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam(l1audio_param_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_r(const int meta_handle, l1audio_param_T* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_If_AudioParam_W0547_Support(void);
META_RESULT  __stdcall META_NVRAM_If_AudioParam_W0547_Support_r(const int meta_handle);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0547(const l1audio_param_W0547_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0547_r(const int meta_handle, const l1audio_param_W0547_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0547(l1audio_param_W0547_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0547_r(const int meta_handle, l1audio_param_W0547_T* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0547_45(const l1audio_param_W0547_45_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0547_45_r(const int meta_handle, const l1audio_param_W0547_45_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0547_45(l1audio_param_W0547_45_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0547_45_r(const int meta_handle, l1audio_param_W0547_45_T* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0712(const l1audio_param_W0712_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioParam_W0712_r(const int meta_handle, const l1audio_param_W0712_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0712(l1audio_param_W0712_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioParam_W0712_r(const int meta_handle, l1audio_param_W0712_T* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AC_SWFIR_Param(const l1audio_swfir_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AC_SWFIR_Param_r(const int meta_handle, const l1audio_swfir_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AC_SWFIR_Param(l1audio_swfir_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AC_SWFIR_Param_r(const int meta_handle, l1audio_swfir_T* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_DMNR_Param(const audio_dual_mic_param_struct* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_DMNR_Param_r(const int meta_handle, const audio_dual_mic_param_struct* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_DMNR_Param(audio_dual_mic_param_struct* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_DMNR_Param_r(const int meta_handle, audio_dual_mic_param_struct* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_Equalizer_Param(const nvram_ef_audio_equalizer_struct* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_Equalizer_Param_r(const int meta_handle, const nvram_ef_audio_equalizer_struct* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_Equalizer_Param(nvram_ef_audio_equalizer_struct* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_Equalizer_Param_r(const int meta_handle, nvram_ef_audio_equalizer_struct* param, const char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_Bes_EQ_Flexible_Param(const nvram_ef_audio_bes_eq_flexible_struct* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_Bes_EQ_Flexible_Param_r(const int meta_handle, const nvram_ef_audio_bes_eq_flexible_struct* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_Bes_EQ_Flexible_Param(nvram_ef_audio_bes_eq_flexible_struct* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_Bes_EQ_Flexible_Param_r(const int meta_handle, nvram_ef_audio_bes_eq_flexible_struct* param, const char* buf, const int buf_len);

// L1Audio Param for WB
typedef struct
{
    short coeff[6][90];
} l1audio_wb_speech_fir_struct;

typedef struct
{
    unsigned short param[8][16];
} l1audio_wb_speech_mode_struct;

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioFIRParam_WB(const l1audio_wb_speech_fir_struct* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioFIRParam_WB_r(const int meta_handle, const l1audio_wb_speech_fir_struct* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioFIRParam_WB(l1audio_wb_speech_fir_struct* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioFIRParam_WB_r(const int meta_handle, l1audio_wb_speech_fir_struct* param, const char* buf, const int buf_len);

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioSpeechParam_WB(const l1audio_wb_speech_mode_struct* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioSpeechParam_WB_r(const int meta_handle, const l1audio_wb_speech_mode_struct* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioSpeechParam_WB(l1audio_wb_speech_mode_struct* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioSpeechParam_WB_r(const int meta_handle, l1audio_wb_speech_mode_struct* param, const char* buf, const int buf_len);

typedef struct
{
    unsigned int hsf_coeffs[9][4];
    unsigned int bpf_coeffs[4][6][3];
    /// BesLoudness V3
    unsigned int audio_besloudness_DRC_Forget_Table[9][2];
    unsigned int audio_besloudness_WS_Gain_Max;
    unsigned int audio_besloudness_WS_Gain_Min;
    unsigned int audio_besloudness_Filter_First;
    char         audio_besloudness_Gain_Map_In[5];
    char         audio_besloudness_Gain_Map_Out[5];
} l1audio_besloudness_T;

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_AudioBesLoudNess_Len(int* len);
META_RESULT  __stdcall META_NVRAM_AudioBesLoudNess_Len_r(const int meta_handle, int* len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioBesLoudNess(const l1audio_besloudness_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioBesLoudNess_r(const int meta_handle, const l1audio_besloudness_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioBesLoudNess(l1audio_besloudness_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioBesLoudNess_r(const int meta_handle, l1audio_besloudness_T* param, const char* buf, const int buf_len);

typedef struct
{
    unsigned int audio_besloudness_spk_hsf_coeffs[2][9][5];
    unsigned int audio_besloudness_spk_bpf_coeffs[6][6][3];
    unsigned int audio_besloudness_spk_lpf_coeffs[6][3];
    unsigned int audio_besloudness_hdp_hsf_coeffs[2][9][5];
    unsigned int audio_besloudness_hdp_bpf_coeffs[6][6][3];
    unsigned int audio_besloudness_hdp_lpf_coeffs[6][3];
    unsigned int audio_besloudness_WS_Gain_Max;
    unsigned int audio_besloudness_WS_Gain_Min;
    unsigned int audio_besloudness_Filter_First;
    unsigned int audio_besloudness_Att_Time;
    unsigned int audio_besloudness_Rel_Time;
    char         audio_besloudness_Gain_Map_In[5];
    char         audio_besloudness_Gain_Map_Out[5];
} l1audio_besloudness_v4_T;

NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Compose_AudioBesLoudNessV4(const l1audio_besloudness_v4_T* param, char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Compose_AudioBesLoudNessV4_r(const int meta_handle, const l1audio_besloudness_v4_T* param, char* buf, const int buf_len);
NON_REENTRANT_FUNC META_RESULT  __stdcall META_NVRAM_Decompose_AudioBesLoudNessV4(l1audio_besloudness_v4_T* param, const char* buf, const int buf_len);
META_RESULT  __stdcall META_NVRAM_Decompose_AudioBesLoudNessV4_r(const int meta_handle, l1audio_besloudness_v4_T* param, const char* buf, const int buf_len);
//--------------------------------------------------------------------------//
//  Audio Testing                                                           //
//--------------------------------------------------------------------------//

//-----------------------------------------------------//
//  Audio Testing: data structure definition           //
//-----------------------------------------------------//

// audio testing result
typedef enum
{
    AUD_RES_OK = 0,                     // OK
    AUD_RES_FAIL,                       // General Fail
    AUD_RES_BUSY,                       // system busy
    AUD_RES_DISC_FULL,                  // Memory full
    AUD_RES_OPEN_FILE_FAIL,             // open file fail
    AUD_RES_END_OF_FILE,                // play finish
    AUD_ERR_OP_NOT_SUPPORT = 0xFB,       // added by ShuMin, for error handler enhancements// filepath too long
    AUD_ERR_STILL_PLAYING = 0xFC,       // added by ShuMin, because I found target had this error value
    AUD_ERR_PEER_BUF_ERROR = 0xFD,      // peer buf error
    AUD_ERR_FILEPATH_ERROR = 0xFE,      // filepath error
    AUD_ERR_FILEPATH_TOO_LONG = 0xFF    // filepath too long
} AUDIO_RESULT;

// play style enum
typedef enum
{
    FT_L4AUD_AUDIO_PLAY_CRESCENDO = 0,  // Play sound for crescendo.
    FT_L4AUD_AUDIO_PLAY_INFINITE,       // Play sound for infinite.
    FT_L4AUD_AUDIO_PLAY_ONCE,           // Play sound for once.
    FT_L4AUD_AUDIO_PLAY_DESCENDO        // Play sound for descendo.
} AUDIO_PLAY_STYLE;

// default system embeded audio id query
typedef struct
{
    unsigned short      MinRingTone_ID;
    unsigned short      MaxRingTone_ID;
    unsigned short      MinMIDI_ID;
    unsigned short      MaxMIDI_ID;
    unsigned short      MinSound_ID;
    unsigned short      MaxSound_ID;
    AUDIO_RESULT        status;
} Audio_Query_ID_Cnf;

// play default system embeded audio by the given audio id
typedef struct
{
    unsigned short      audio_id;       // default system embeded audio id
    AUDIO_PLAY_STYLE    play_style;     // play style
} Audio_Play_Req;

// play audio from FAT by the given filepath
typedef struct
{
    const char*          fat_filepath;  // filepath on target FAT file system
    AUDIO_PLAY_STYLE    play_style;     // play style
} Audio_Play_ByName_Req;

// play imelody by the buffer from PC side
typedef struct
{
    const char*          imy_buf;       // buffer that stores iMelody content
    unsigned int        imy_buf_len;    // length of buffer
    unsigned char       imy_instrument; // instrument id, 1 ~ 128
    AUDIO_PLAY_STYLE    play_style;     // play style
} Audio_Play_IMY_ByBuf_Req;

// play mp3 from FAT by the given filepath
typedef struct
{
    const char*          fat_filepath;  // filepath on target FAT file system
    AUDIO_PLAY_STYLE    play_style;     // play style
} Audio_MEDIA_Play_Req;

// set volume
typedef struct
{
    unsigned char       volume;         // play volume, 0 ~ 255
} Audio_Set_Volume_Req;

typedef struct
{
    unsigned char       echoflag;           // echofalg true
} Audio_Set_Echo_Req;

typedef struct
{
    unsigned char       modeflag;           // modeflag: 0: normal, 1: headset, 2: loudspeaker  (totally 3 modes)
} Audio_Set_Mode_Req;

typedef struct
{
    unsigned char       type;
    unsigned char       gain;
} Audio_Set_Gain_Req;

typedef struct
{
    short       in_fir_coeffs[45];
    short       out_fir_coeffs[45];
} Audio_Set_LoudSpk_FIR_Coeffs_Req;

typedef struct
{
    unsigned short speech_common_para[12];  // 8 or 12, so at most 12
} Audio_Set_Speech_Common_Req;

typedef struct
{
    unsigned short speech_loudspk_mode_para[16];  // change from 8 to 16, because at most: 16
} Audio_Set_LoudSpk_Mode_Req;

typedef struct
{
    unsigned short Media_Playback_Maximum_Swing;
} Audio_Set_Playback_Maximum_Swing_Req;

typedef struct
{
    short Melody_FIR_Output_Coeff_32k_Tbl1[25];
} Audio_Set_Melody_FIR_Output_Coeffs_Req;

typedef struct
{
    unsigned short speech_common_para[12];
    unsigned short speech_loudspk_mode_para[16];  // change from 8 to 16, because at most: 16
} Audio_Set_Speech_Common_And_Mode_Req;

typedef struct
{
    unsigned short      fre;
    unsigned char       spkgain;
    unsigned char       micgain;
    unsigned short      ulgain;
    unsigned short      dlgain;
    unsigned short      amp;

} Audio_Tone_LoopBackRec_Req;

typedef struct
{
    unsigned int        buffer[2000];
} Audio_Tone_LoopBackRec_Cnf;

typedef struct
{
    unsigned int        buffer[500];
} Audio_Tone_LoopBackRec_Cnf_2K;

typedef struct
{
    unsigned char  m_ucVolume;
    unsigned short m_u2Freq;
} Audio_Set_Freq_Vol_Tone_Req_T;

typedef struct
{
    unsigned char  m_ucMode;
} Audio_Get_Profile_Settings_By_Mode_Req_T;

typedef struct
{
    unsigned char mode;
    unsigned char melody[7];
    unsigned char sound[7];
    unsigned char keytone[7];
    unsigned char speech[7];
    unsigned char mic[7];
    unsigned char sidetone;
    unsigned char max_melody_volume_gain;
    unsigned char melody_volume_gain_step;
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];  // 7 here

} Audio_Get_Profile_Settings_By_Mode_Cnf_T;

typedef struct
{
    unsigned char mode;
    unsigned char melody[7];
    unsigned char sound[7];
    unsigned char keytone[7];
    unsigned char speech[7];
    unsigned char mic[7];
    unsigned char sidetone;
    unsigned char max_melody_volume_gain;
    unsigned char melody_volume_gain_step;
    unsigned char tv_out_volume_gain[MAX_VOL_LEVEL];  // 7 here

} Audio_Set_Profile_Settings_By_Mode_Req_T;

typedef struct
{

    unsigned short m_u2FailReason;  // possible fail resons

} Audio_Set_Profile_Settings_By_Mode_Cnf_T;


typedef struct
{

    unsigned short m_u2FailReason;  // possible fail resons, (2 means the format is not matched with Target side)

} Audio_Set_Param_Cnf_T;

//-----------------------------------------------------//
//  Audio Testing: callback function definition        //
//-----------------------------------------------------//
typedef void (__stdcall* META_AUDIO_QUERY_ID_CNF)(const Audio_Query_ID_Cnf* cnf, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_PLAY_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_PLAY_BYNAME_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_PLAY_IMY_BYBUF_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_PLAY_OVER_IND)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_STOP_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_MEDIA_PLAY_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_MEDIA_PLAY_OVER_IND)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_MEDIA_STOP_CNF)(const AUDIO_RESULT status, const short token, void* usrData);
typedef void (__stdcall* META_AUDIO_SET_VOLUME_CNF)(const AUDIO_RESULT status, const short token, void* usrData);

//-----------------------------------------------------//
//  Audio Testing: exported function definition        //
//-----------------------------------------------------//
META_RESULT  __stdcall META_Audio_Query_ID(const META_AUDIO_QUERY_ID_CNF  cnf_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Query_ID_r(const int meta_handle, const META_AUDIO_QUERY_ID_CNF  cnf_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play(const Audio_Play_Req*  req, const META_AUDIO_PLAY_CNF cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play_r(const int meta_handle, const Audio_Play_Req*  req, const META_AUDIO_PLAY_CNF cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play_ByName(const Audio_Play_ByName_Req*  req, const META_AUDIO_PLAY_BYNAME_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play_ByName_r(const int meta_handle, const Audio_Play_ByName_Req*  req, const META_AUDIO_PLAY_BYNAME_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play_IMY_ByBuf(const Audio_Play_IMY_ByBuf_Req*  req, const META_AUDIO_PLAY_IMY_BYBUF_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Play_IMY_ByBuf_r(const int meta_handle, const Audio_Play_IMY_ByBuf_Req*  req, const META_AUDIO_PLAY_IMY_BYBUF_CNF  cnf_cb, const META_AUDIO_PLAY_OVER_IND  ind_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Stop(const META_AUDIO_STOP_CNF  cnf_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Stop_r(const int meta_handle, const META_AUDIO_STOP_CNF  cnf_cb, short* token, void* usrData);
//META_RESULT  __stdcall META_Audio_MEDIA_Play(const Audio_MEDIA_Play_Req  *req, const META_AUDIO_MEDIA_PLAY_CNF  cnf_cb, const META_AUDIO_MEDIA_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
//META_RESULT  __stdcall META_Audio_MEDIA_Play_r(const int meta_handle, const Audio_MEDIA_Play_Req  *req, const META_AUDIO_MEDIA_PLAY_CNF  cnf_cb, const META_AUDIO_MEDIA_PLAY_OVER_IND  ind_cb, short *token, void *usrData);
//META_RESULT  __stdcall META_Audio_MEDIA_Stop(const META_AUDIO_MEDIA_STOP_CNF  cnf_cb, short *token, void *usrData);
//META_RESULT  __stdcall META_Audio_MEDIA_Stop_r(const int meta_handle, const META_AUDIO_MEDIA_STOP_CNF  cnf_cb, short *token, void *usrData);
META_RESULT  __stdcall META_Audio_Set_Volume(const Audio_Set_Volume_Req*  req, const META_AUDIO_SET_VOLUME_CNF  cnf_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Set_Volume_r(const int meta_handle, const Audio_Set_Volume_Req*  req, const META_AUDIO_SET_VOLUME_CNF  cnf_cb, short* token, void* usrData);
META_RESULT  __stdcall META_Audio_Set_Echo_Loop(unsigned int  ms_timeout, const Audio_Set_Echo_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Echo_Loop_r(const int meta_handle, unsigned int  ms_timeout , const Audio_Set_Echo_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Mode(unsigned int  ms_timeout, const Audio_Set_Mode_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Mode_r(const int meta_handle, unsigned int  ms_timeout , const Audio_Set_Mode_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Gain(unsigned int  ms_timeout, const Audio_Set_Gain_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Gain_r(const int meta_handle, unsigned int  ms_timeout , const Audio_Set_Gain_Req*  req);
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf* cnf);
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec_r(const int meta_handle, unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf* cnf);
//  for loud-speaker mode
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec_2K(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf_2K* cnf);
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec_2K_r(const int meta_handle, unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf_2K* cnf);
// for normal mode
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec_2K_Normal(unsigned int  ms_timeout, Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf_2K* cnf);
META_RESULT  __stdcall META_Audio_Tone_Loop_Back_Rec_2K_Normal_r(const int meta_handle, unsigned int  ms_timeout , Audio_Tone_LoopBackRec_Req*  req, Audio_Tone_LoopBackRec_Cnf_2K* cnf);

META_RESULT  __stdcall META_Audio_Set_LoudSpk_FIR_Coeffs(unsigned int  ms_timeout, const Audio_Set_LoudSpk_FIR_Coeffs_Req*  req);
META_RESULT  __stdcall META_Audio_Set_LoudSpk_FIR_Coeffs_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_LoudSpk_FIR_Coeffs_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Speech_Common(unsigned int  ms_timeout, const Audio_Set_Speech_Common_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Speech_Common_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_Speech_Common_Req*  req);
META_RESULT  __stdcall META_Audio_Set_LoudSpk_Mode(unsigned int  ms_timeout, const Audio_Set_LoudSpk_Mode_Req*  req);
META_RESULT  __stdcall META_Audio_Set_LoudSpk_Mode_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_LoudSpk_Mode_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Playback_Maximum_Swing(unsigned int  ms_timeout, const Audio_Set_Playback_Maximum_Swing_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Playback_Maximum_Swing_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_Playback_Maximum_Swing_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Melody_FIR_Output_Coeffs(unsigned int  ms_timeout, const Audio_Set_Melody_FIR_Output_Coeffs_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Melody_FIR_Output_Coeffs_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_Melody_FIR_Output_Coeffs_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Speech_Common_And_Mode(unsigned int  ms_timeout, const Audio_Set_Speech_Common_And_Mode_Req*  req);
META_RESULT  __stdcall META_Audio_Set_Speech_Common_And_Mode_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_Speech_Common_And_Mode_Req*  req);

META_RESULT  __stdcall META_Audio_Play_Freq_Vol_Tone(unsigned int  ms_timeout, const Audio_Set_Freq_Vol_Tone_Req_T*  req);
META_RESULT  __stdcall META_Audio_Play_Freq_Vol_Tone_r(const int meta_handle, unsigned int  ms_timeout, const Audio_Set_Freq_Vol_Tone_Req_T*  req);
META_RESULT  __stdcall META_Audio_Stop_Freq_Vol_Tone(unsigned int  ms_timeout);
META_RESULT  __stdcall META_Audio_Stop_Freq_Vol_Tone_r(const int meta_handle, unsigned int  ms_timeout);


META_RESULT  __stdcall META_Audio_Get_Audio_Profile_Settings(unsigned int ms_timeout,
        Audio_Get_Profile_Settings_By_Mode_Req_T* req,
        Audio_Get_Profile_Settings_By_Mode_Cnf_T* cnf);
META_RESULT  __stdcall META_Audio_Get_Audio_Profile_Settings_r(const int meta_handle,
        unsigned int  ms_timeout,
        Audio_Get_Profile_Settings_By_Mode_Req_T* req,
        Audio_Get_Profile_Settings_By_Mode_Cnf_T* cnf);
META_RESULT  __stdcall META_Audio_Set_Audio_Profile_Settings(unsigned int ms_timeout,
        Audio_Set_Profile_Settings_By_Mode_Req_T* req,
        Audio_Set_Profile_Settings_By_Mode_Cnf_T* cnf);
META_RESULT  __stdcall META_Audio_Set_Audio_Profile_Settings_r(const int meta_handle,
        unsigned int  ms_timeout,
        Audio_Set_Profile_Settings_By_Mode_Req_T* req,
        Audio_Set_Profile_Settings_By_Mode_Cnf_T* cnf);

META_RESULT  __stdcall META_Audio_Get_Audio_Param_Settings_0809(unsigned int ms_timeout,
        l1audio_param_W0809_T* cnf);
META_RESULT  __stdcall META_Audio_Get_Audio_Param_Settings_0809_r(const int meta_handle,
        unsigned int  ms_timeout,
        l1audio_param_W0809_T* cnf);

META_RESULT  __stdcall META_Audio_Set_Audio_Param_Settings_0809(unsigned int ms_timeout,
        l1audio_param_W0809_T* req,
        Audio_Set_Param_Cnf_T* cnf);

META_RESULT  __stdcall META_Audio_Set_Audio_Param_Settings_0809_r(const int meta_handle,
        unsigned int  ms_timeout,
        l1audio_param_W0809_T* req,
        Audio_Set_Param_Cnf_T* cnf);


META_RESULT  __stdcall META_Audio_Set_Output_Dev(unsigned int ms_timeout,
        unsigned char* output_dev_req);

META_RESULT  __stdcall META_Audio_Set_Output_Dev_r(const int meta_handle,
        unsigned int ms_timeout,
        unsigned char* output_dev_req);
META_RESULT  __stdcall META_Audio_Set_Output_Vol(unsigned int ms_timeout,
        unsigned char* output_vol);

META_RESULT  __stdcall META_Audio_Set_Output_Vol_r(const int meta_handle,
        unsigned int ms_timeout,
        unsigned char* output_vol);


typedef struct
{
    unsigned char          u1_set_output_device;
    unsigned short         u2_digital_gain;
} Audio_SetOutputDevEx_Req_T;


META_RESULT  __stdcall META_Audio_Set_Output_Dev_With_DG(unsigned int ms_timeout,
        Audio_SetOutputDevEx_Req_T* req);

META_RESULT  __stdcall META_Audio_Set_Output_Dev_With_DG_r(const int meta_handle,
        unsigned int ms_timeout,
        Audio_SetOutputDevEx_Req_T* req);



META_RESULT  __stdcall META_Audio_FreeMemory(unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_FreeMemory_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_PlayCurMemContent(unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_PlayCurMemContent_r(const int meta_handle, unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_StopPlaying(unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_StopPlaying_r(const int meta_handle, unsigned int ms_timeout);


typedef int (__stdcall* CALLBACK_META_AUDIO_PROGRESS)(unsigned char percent, int sent_bytes, int total_bytes, const short token, void* usr_arg);

typedef struct
{

    bool bCheckHdr;
    unsigned int u4StartFilePos; // only valid when bCheckHdr = false;

    char* pFilePath;

    bool bIsStereo;
    char i1BitPerSample;
    unsigned short u2SampleFreq;
    bool  bForceVoice;       // always set true?

    CALLBACK_META_AUDIO_PROGRESS  cb_progress;
    void*  cb_progress_arg;


} Audio_Play_Wave_File_REQ_T;



META_RESULT __stdcall META_Audio_Play_Wave_File(unsigned int ms_timeout, Audio_Play_Wave_File_REQ_T* req, int* pStopFlag, bool* bSaveAllOnTargetMem);
META_RESULT __stdcall META_Audio_Play_Wave_File_r(const int meta_handle, unsigned int ms_timeout, Audio_Play_Wave_File_REQ_T* req, int* pStopFlag, bool* bSaveAllOnTargetMem);


typedef enum
{
    AC_Filter_DSP_FIR = 0,
    AC_Filter_HW_FIR = 1,
    AC_Filter_DSP_IIR = 2,
    AC_Filter_UNKNOWN = 100
} E_Audio_Compensation_Filter_Type;

META_RESULT  __stdcall META_Audio_GetACFilterType(unsigned int ms_timeout, E_Audio_Compensation_Filter_Type* p_type);
META_RESULT  __stdcall META_Audio_GetACFilterType_r(const int meta_handle, unsigned int ms_timeout, E_Audio_Compensation_Filter_Type* p_type);

typedef struct
{
    unsigned char u1_ac_mode; // loudspeaker: 0, normal: 1
    short i2_ac_coef[45];
} Audio_Compensation_Filter_Coef;

META_RESULT  __stdcall META_Audio_SetACFilterCoef(unsigned int ms_timeout, const Audio_Compensation_Filter_Coef* p_req);
META_RESULT  __stdcall META_Audio_SetACFilterCoef_r(const int meta_handle, unsigned int ms_timeout, const Audio_Compensation_Filter_Coef* p_req);
META_RESULT  __stdcall META_Audio_GetGainTypeSupport(unsigned int ms_timeout);
META_RESULT  __stdcall META_Audio_GetGainTypeSupport_r(const int meta_handle, unsigned int ms_timeout);

typedef struct
{
    short          i2MaxGain;
    unsigned short u2Step;
    unsigned short u2TotalLevel;
} Audio_Ex_GetDLGainCap_T;

typedef struct
{
    unsigned int              u4_dl_buf_type_by_mode[4]; //0:handset, 1:headset, 2: handsfree, 3: bt earphone
    Audio_Ex_GetDLGainCap_T   buf_info[2];               // 0: audio buffer, 1: voice buffer, 2: unknown
    bool                      b_digital_gain_support;


} Audio_Ex_GetDLGainCap_CNF_T; // stored in peer buffer


META_RESULT __stdcall META_Audio_EX_GetDLGainCapability(const unsigned int ms_timeout, Audio_Ex_GetDLGainCap_CNF_T* cnf);
META_RESULT __stdcall META_Audio_EX_GetDLGainCapability_r(const int meta_handle, const unsigned int ms_timeout, Audio_Ex_GetDLGainCap_CNF_T* cnf);


typedef struct
{

    unsigned int     iir_coeff_int[4][6][3];
    unsigned int     hsf_coeff_int[9][4];
} Audio_Ex_SetACFToTarget_REQ_T;

META_RESULT __stdcall META_Audio_EX_SetACFIIRToTarget(const unsigned int ms_timeout, Audio_Ex_SetACFToTarget_REQ_T* req);
META_RESULT __stdcall META_Audio_EX_SetACFIIRToTarget_r(const int meta_handle, const unsigned int ms_timeout, Audio_Ex_SetACFToTarget_REQ_T* req);

typedef struct
{
    /// the buffer for the compose function sink
    char         buffer[2000];
    /// the buffer length (must be retrieved by META_NVRAM_AudioBesLoudNess_Len)
    unsigned int bufferLength;
} Audio_Ex_SetACFToTarget_REQ_EX_T;

META_RESULT __stdcall META_Audio_EX_SetACFIIRToTargetEx(const unsigned int ms_timeout, const Audio_Ex_SetACFToTarget_REQ_EX_T* req);
META_RESULT __stdcall META_Audio_EX_SetACFIIRToTargetEx_r(const int meta_handle, const unsigned int ms_timeout, const Audio_Ex_SetACFToTarget_REQ_EX_T* req);

META_RESULT  __stdcall META_Audio_EX_SetACFilterCoefEx(unsigned int ms_timeout, const Audio_Ex_SetACFToTarget_REQ_EX_T* p_req);
META_RESULT  __stdcall META_Audio_EX_SetACFilterCoefEx_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_SetACFToTarget_REQ_EX_T* p_req);

META_RESULT __stdcall META_Audio_EX_QueryBesLoudnessVersion(unsigned int ms_timeout, unsigned int* version);
META_RESULT __stdcall META_Audio_EX_QueryBesLoudnessVersion_r(const int meta_handle, unsigned int ms_timeout, unsigned int* version);

/*************************************************
 *============== Audio Ex Operation===============
 *************************************************/

#define META_L4AUD_VOL_TYPE_TONE 0 // Tone
#define META_L4AUD_VOL_TYPE_KT   1 // keytone
#define META_L4AUD_VOL_TYPE_MIC  2 // microphone
#define META_L4AUD_VOL_TYPE_FMR  3  // FM Radio
#define META_L4AUD_VOL_TYPE_SPH  4  // speech
#define META_L4AUD_VOL_TYPE_SID  5   // side tne
#define META_L4AUD_VOL_TYPE_MEDIA 6  // media
#define META_L4AUD_VOL_TYPE_TVOUT 7  // TV-out

#define META_L4AUD_PATH_UNKNOWN   0x00
#define META_L4AUD_PATH_RECEIVER  0x01
#define META_L4AUD_PATH_HEADSET   0x02
#define META_L4AUD_PATH_SPEAKER   0x04
#define META_L4AUD_PATH_DUAL      0x08
#define META_L4AUD_PATH_BT        0x10


#define META_L4AUD_PGA_BUF_AUDIO   0
#define META_L4AUD_PGA_BUF_VOICE   1
#define META_L4AUD_PGA_BUF_UNKNOWN 2
#define META_L4AUD_PGA_BUF_MIC     3


#define META_L4AUD_GAIN_TABLE_UNKNOWN   -1
#define META_L4AUD_GAIN_TABLE_PURE       0
#define META_L4AUD_GAIN_TABLE_RAW        1
#define META_L4AUD_GAIN_TABLE_N_LEVEL    2


typedef struct
{
    unsigned char  u1VolType;
    unsigned char  u1PathType;
    unsigned short u2SIdx; //start index: from 0
    unsigned short  u2EIdx; // end index
    bool           b_digital_gain_support;
    char           i1BufType;
    unsigned char  u1ExtAmpType; //0/L1SP_EXT_DAC_BUF0(0x40)/L1SP_EXT_DAC_BUF1(0x80)
    char           i1GainTableType;  // 0: only 8 bits
    unsigned short u2BufLevel;
    unsigned short u2ExtAmpCtrlPointNum;
} ft_l4aud_ex_gain_table_info_T;


#define AUDIO_EX_GAIN_TABLE_MAP_ENTRY_MAX_NUM 100

typedef struct
{
    unsigned char u1EntryNum;
    ft_l4aud_ex_gain_table_info_T gain_table_info[AUDIO_EX_GAIN_TABLE_MAP_ENTRY_MAX_NUM];
} Audio_Ex_GainTableMap_CNF_T;

META_RESULT __stdcall META_Audio_EX_GetGainTableMap(const unsigned int ms_timeout, Audio_Ex_GainTableMap_CNF_T* cnf);
META_RESULT __stdcall META_Audio_EX_GetGainTableMap_r(const int meta_handle, const unsigned int ms_timeout, Audio_Ex_GainTableMap_CNF_T* cnf);

META_RESULT  __stdcall META_GetGainTable_Next(int find_handle);
META_RESULT __stdcall META_GetGainTable_GetDetailedInfo(int find_handle,
        unsigned char* vol_type,
        unsigned char* path_type,
        unsigned short* s_idx,
        unsigned short* e_idx,
        char* main_title,
        int main_title_len,
        char* sub_title,
        int sub_title_len);
META_RESULT __stdcall META_GetGainTable_Close(int* p_find_handle);

META_RESULT __stdcall META_GetGainTable_Start(const unsigned int ms_timeout, int* p_find_handle);
META_RESULT __stdcall META_GetGainTable_Start_r(const int meta_handle, const unsigned int ms_timeout, int* p_find_handle);


typedef struct
{
    char   i1BufType;
    unsigned short  u2BufLevel;
} Audio_Ex_GetPgaGainMap_REQ_T; //ft_l4aud_get_pga_gain_map_T;

typedef struct
{
    unsigned char   u1ExtDac;
    unsigned short u2CtrlPoint;
} Audio_Ex_GetExtAmpMap_REQ_T; //ft_l4aud_get_ext_amp_map_T;


#define AUDIO_EX_MAP_ENTRY_MAX_NUM 1000

typedef struct
{
    unsigned short u2EntryNum;
    char  i1MapInfo[AUDIO_EX_MAP_ENTRY_MAX_NUM];
} Audio_Ex_GainMap_CNF_T;

typedef struct
{
    unsigned char  u1BitNum;
    unsigned short u2EntryNum;
    char  i1MapInfo[AUDIO_EX_MAP_ENTRY_MAX_NUM];
} Audio_Ex_ExtAmpGainMap_CNF_T;


META_RESULT __stdcall META_Audio_EX_GetPgaGainMap(const unsigned int ms_timeout,
        Audio_Ex_GetPgaGainMap_REQ_T* req,
        Audio_Ex_GainMap_CNF_T* cnf);
META_RESULT __stdcall META_Audio_EX_GetPgaGainMap_r(const int meta_handle,
        const unsigned int ms_timeout,
        Audio_Ex_GetPgaGainMap_REQ_T* req,
        Audio_Ex_GainMap_CNF_T* cnf);

META_RESULT __stdcall META_Audio_EX_GetExtAmpGainMap(const unsigned int ms_timeout,
        Audio_Ex_GetExtAmpMap_REQ_T* req,
        Audio_Ex_ExtAmpGainMap_CNF_T* cnf);
META_RESULT __stdcall META_Audio_EX_GetExtAmpGainMap_r(const int meta_handle,
        const unsigned int ms_timeout,
        Audio_Ex_GetExtAmpMap_REQ_T* req,
        Audio_Ex_ExtAmpGainMap_CNF_T* cnf);

typedef struct
{
    /// number of bits per field
    unsigned char  u1BitNum;
    /// number of entries
    unsigned short u2EntryNum;
    /// scale factor of each map entry (if scale_factor is 2, the value of map entry should be divided by 10^2
    unsigned char  scale_factor;
    /// map entries
    short          i2MapInfo[AUDIO_EX_MAP_ENTRY_MAX_NUM];
} Audio_Ex_ExtAmpGainMap_CNF_Ex_T;
META_RESULT __stdcall META_Audio_EX_GetExtAmpGainMapEx(const unsigned int ms_timeout,
        Audio_Ex_GetExtAmpMap_REQ_T* req,
        Audio_Ex_ExtAmpGainMap_CNF_Ex_T* cnf);

META_RESULT __stdcall META_Audio_EX_GetExtAmpGainMapEx_r(const int meta_handle,
        const unsigned int ms_timeout,
        Audio_Ex_GetExtAmpMap_REQ_T* req,
        Audio_Ex_ExtAmpGainMap_CNF_Ex_T* cnf);

typedef enum
{
    MEDIA_FORMAT_GSM_FR,
    MEDIA_FORMAT_GSM_HR,
    MEDIA_FORMAT_GSM_EFR,
    MEDIA_FORMAT_AMR,
    MEDIA_FORMAT_AMR_WB,
    MEDIA_FORMAT_DAF,
    MEDIA_FORMAT_AAC,
    MEDIA_FORMAT_PCM_8K,
    MEDIA_FORMAT_PCM_16K,
    MEDIA_FORMAT_G711_ALAW,
    MEDIA_FORMAT_G711_ULAW,
    MEDIA_FORMAT_DVI_ADPCM,
    MEDIA_FORMAT_VRD,
    MEDIA_FORMAT_WAV,
    MEDIA_FORMAT_WAV_ALAW,
    MEDIA_FORMAT_WAV_ULAW,
    MEDIA_FORMAT_WAV_DVI_ADPCM,
    MEDIA_FORMAT_SMF,
    MEDIA_FORMAT_IMELODY,
    MEDIA_FORMAT_SMF_SND,
    MEDIA_FORMAT_MMF,
    MEDIA_FORMAT_AU,
    MEDIA_FORMAT_AIFF,
    MEDIA_FORMAT_VRSI,
    MEDIA_FORMAT_WMA,
    MEDIA_FORMAT_M4A,
    MEDIA_FORMAT_WAV_DVI_ADPCM_16K,
    MEDIA_FORMAT_VOIPEVL,
    MEDIA_FORMAT_AAC_PLUS,
    MEDIA_FORMAT_AAC_PLUS_V2,
    MEDIA_FORMAT_BSAC,
    MEDIA_FORMAT_MUSICAM = 32,
    MEDIA_FORMAT_AWB_PLUS,
    MEDIA_FORMAT_AWB_PLUS_EXTEND,
    MEDIA_FORMAT_WAV_16K,
    MEDIA_FORMAT_MP4_AAC,
    MEDIA_FORMAT_MP4_AMR,
    MEDIA_FORMAT_MP4_AMR_WB,
    MEDIA_FORMAT_MP4_BSAC,
    MEDIA_FORMAT_DRA,
    MEDIA_FORMAT_COOK,
    MEDIA_FORMAT_APE,
    MEDIA_FORMAT_UNKNOWN
} Media_Format;

typedef struct
{
    /// format MEDIA_FORMAT_WAV_DVI_ADPCM (narrow-band), MEDIA_FORMAT_WAV_DVI_ADPCM_16K (wide-band)
    unsigned int   fmt;
    /// parameter (0: for MEDIA_FORMAT_WAV_DVI_ADPCM/MEDIA_FORMAT_WAV_DVI_ADPCM_16K)
    unsigned short param;
    /// requested time(ms)
    unsigned int   requested_time;
    /// [IN/OUT] file path of target (set all the buffer to NULL means the target will create file on its own)
    char           file_path[512];
    /// [IN] input volume
    unsigned char  inputVolume;
} Audio_Ex_RecordingParam_T;

META_RESULT  __stdcall META_Audio_EX_StartRecording(unsigned int ms_timeout, const Audio_Ex_RecordingParam_T* param);
META_RESULT  __stdcall META_Audio_EX_StartRecording_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_RecordingParam_T* param);
META_RESULT  __stdcall META_Audio_EX_StartRecordingEx(unsigned int ms_timeout, const Audio_Ex_RecordingParam_T* param, int* status);
META_RESULT  __stdcall META_Audio_EX_StartRecordingEx_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_RecordingParam_T* param, int* status);
typedef struct
{
    /// file path of target
    char     target_path[512];
    /// file path of local
    char     local_path[512];
    /// get file from target or not
    int      get_file;
    /// delete target side file or not
    int      delete_file;
    /// progress callback
    CALLBACK_META_FAT_PROGRESS cb;
    /// stop flag
    int      stop_flag;
} Audio_Ex_StopRecording_T;

META_RESULT  __stdcall META_Audio_EX_StopRecording(unsigned int ms_timeout, const Audio_Ex_StopRecording_T* req);
META_RESULT  __stdcall META_Audio_EX_StopRecording_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_StopRecording_T* req);
META_RESULT  __stdcall META_Audio_EX_StopRecordingEx(unsigned int ms_timeout, const Audio_Ex_StopRecording_T* req, int* status);
META_RESULT  __stdcall META_Audio_EX_StopRecordingEx_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_StopRecording_T* req, int* status);
typedef struct
{
    /// requested time(ms)
    unsigned int requested_time;
    /// recorded time(ms)
    unsigned int offset;
} Audio_Ex_QueryRecording_T;

META_RESULT  __stdcall META_Audio_EX_QueryRecording(unsigned int ms_timeout, Audio_Ex_QueryRecording_T* status);
META_RESULT  __stdcall META_Audio_EX_QueryRecording_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_QueryRecording_T* status);

typedef struct
{
    unsigned char  u1SpeechModeNum;
    unsigned char  u1SpeechModeParaMaxNum;
    unsigned short u2ModeTitelBufLen;
    char*          i1ModeTileBuf;
} Audio_Ex_Speech_Mode_Table_CNF_T;

META_RESULT __stdcall META_Audio_EX_GetSpeechModeTable(const unsigned int ms_timeout, Audio_Ex_Speech_Mode_Table_CNF_T* cnf);
META_RESULT __stdcall META_Audio_EX_GetSpeechModeTable_r(const int meta_handle, const unsigned int ms_timeout, Audio_Ex_Speech_Mode_Table_CNF_T* cnf);

#define FT_L1SP_MICROPHONE1  0
#define FT_L1SP_MICROPHONE2  1
#define FT_L1SP_SPEAKER1     2
#define FT_L1SP_SPEAKER2     3
#define FT_L1SP_LOUD_SPEAKER 4
typedef struct
{
    /// PCM2WAY format (0, 1, 2)
    unsigned int   format;
    /// specify the play wave file drive letter
    /// (this is queried by META_Util_QueryDriveAvailableForFileSize_r first)
    /// The application should put the file to the root folder of playDrive for example "c:\"
    /// the file name is always echo_play.wav for example "c:\echo_play.wav"
    short          playDrive;
    /// specify the record file drive letter
    /// (this is queried by META_Util_QueryDriveAvailableForFileSize_r first)
    /// The target will put the file to the root folder of recordDrive for example "c:\"
    /// the file name is always echo_record.out for example "c:\echo_record.out"
    short          recordDrive;
    /// the volume value pass to L1 (use index 6's value)
    unsigned char  outputDevice;
    unsigned char  outputVolume;
    unsigned char  inputDevice;
    unsigned char  inputVolume;
    unsigned char  sidetoneVolume;
} Audio_Ex_EchoLoopParam_T;
META_RESULT  __stdcall META_Audio_EX_StartEchoLoop(unsigned int ms_timeout, const Audio_Ex_EchoLoopParam_T* param, int* status);
META_RESULT  __stdcall META_Audio_EX_StartEchoLoop_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_EchoLoopParam_T* param, int* status);
typedef struct
{
    /// total number of samples
    unsigned int totalSamples;
    /// progress
    unsigned int progress;
    /// stop flag
    int stop;
} Audio_Ex_QueryEchoLoop_T;
META_RESULT  __stdcall META_Audio_EX_QueryEchoLoop(unsigned int ms_timeout, Audio_Ex_QueryEchoLoop_T* status);
META_RESULT  __stdcall META_Audio_EX_QueryEchoLoop_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_QueryEchoLoop_T* status);
META_RESULT  __stdcall META_Audio_EX_StopEchoLoop(unsigned int ms_timeout, int* status);
META_RESULT  __stdcall META_Audio_EX_StopEchoLoop_r(const int meta_handle, unsigned int ms_timeout, int* status);
typedef struct
{
    unsigned int playingRate;
    unsigned int recordingRate;
} Audio_Ex_QueryEchoLoopDataRate_T;
META_RESULT  __stdcall META_Audio_EX_QueryEchoLoopDataRate(unsigned int ms_timeout, unsigned int format, Audio_Ex_QueryEchoLoopDataRate_T* info);
META_RESULT  __stdcall META_Audio_EX_QueryEchoLoopDataRate_r(const int meta_handle, unsigned int ms_timeout, unsigned int format, Audio_Ex_QueryEchoLoopDataRate_T* info);
typedef enum
{
    MEDIA_SPEECH_FEATURE_NONE = 0x00000000,
    MEDIA_SPEECH_FEATURE_NB_DMNR = 0x00000001,
    MEDIA_SPEECH_FEATURE_WB_DMNR = 0x00000002,
    MEDIA_SPEECH_FEATURE_WB_LINK_SUPPORT = 0x00000004,
    MEDIA_SPEECH_FEATURE_HD_RECORD = 0x00000008,
    MEDIA_SPEECH_FEATURE_STEREO_RECORD = 0x00000010,
} Media_Speech_Feature;
META_RESULT __stdcall META_Audio_EX_QuerySpeechCapability(unsigned int ms_timeout, unsigned int* capability);
META_RESULT __stdcall META_Audio_EX_QuerySpeechCapability_r(const int meta_handle, unsigned int ms_timeout, unsigned int* capability);
typedef struct
{
    short          numberOfSpeechEnhancementMode;     /**< \brief the number of speech enhancement mode */
    unsigned short bufferLengthOfEachModeName;        /**< \brief buffer length of each speech enhancement mode name */
    short          numberOfSpeechEnhancementCategory; /**< \brief the number of categories for speech enhancement */
    unsigned short bufferLengthOfEachCategoryName;    /**< \brief buffer length of each speech enhancement category name */
} Audio_Ex_SpeechEnhancementParam_T;
META_RESULT __stdcall META_Audio_EX_QueryParamsOfSpeechEnhancement(unsigned int ms_timeout, Audio_Ex_SpeechEnhancementParam_T* param);
META_RESULT __stdcall META_Audio_EX_QueryParamsOfSpeechEnhancement_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_SpeechEnhancementParam_T* param);
typedef struct
{
    unsigned int bufferLength; /**< \brief [IN] the length of buffer */
    char*        buffer;       /**< \brief [OUT] buffer for names of speech enhancement mode or speech enhancement category */
} Audio_Ex_SpeechEnhancementNameBuffer_T;
META_RESULT __stdcall META_Audio_EX_QueryNamesOfSpeechEnhancementModes(unsigned int ms_timeout, Audio_Ex_SpeechEnhancementNameBuffer_T* cnf);
META_RESULT __stdcall META_Audio_EX_QueryNamesOfSpeechEnhancementModes_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_SpeechEnhancementNameBuffer_T* cnf);
META_RESULT __stdcall META_Audio_EX_QueryNamesOfSpeechEnhancementCategories(unsigned int ms_timeout, Audio_Ex_SpeechEnhancementNameBuffer_T* cnf);
META_RESULT __stdcall META_Audio_EX_QueryNamesOfSpeechEnhancementCategories_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_SpeechEnhancementNameBuffer_T* cnf);
typedef struct
{
    unsigned int bufferLength; /**< \brief [IN] the length of buffer */
    short*       buffer;       /**< \brief [OUT] buffer for category ID of each speech enhancement mode */
} Audio_Ex_SpeechEnhancementCategoryBuffer_T;
META_RESULT __stdcall META_Audio_EX_QueryCategoryIdOfSpeechEnhancementMode(unsigned int ms_timeout, Audio_Ex_SpeechEnhancementCategoryBuffer_T* cnf);
META_RESULT __stdcall META_Audio_EX_QueryCategoryIdOfSpeechEnhancementMode_r(const int meta_handle, unsigned int ms_timeout, Audio_Ex_SpeechEnhancementCategoryBuffer_T* cnf);
typedef struct
{
    unsigned char isWideBand;   /**< \brief [IN] 0 is narrow band (8k), >0 is wide band(16k) */
    unsigned char isOutputFir;  /**< \brief [IN] 0 is for input FIR, >0 is for output FIR */
} Audio_Ex_SpeechFirReq_T;
typedef struct
{
    short numberOfAllFIRMode; /**< \brief [OUT] the number of speech FIR mode */
} Audio_Ex_SpeechFirParam_T;
META_RESULT __stdcall META_Audio_EX_QueryParamsOfSpeechFIR(unsigned int ms_timeout, const Audio_Ex_SpeechFirReq_T* req, Audio_Ex_SpeechFirParam_T* param);
META_RESULT __stdcall META_Audio_EX_QueryParamsOfSpeechFIR_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_SpeechFirReq_T* req, Audio_Ex_SpeechFirParam_T* param);
META_RESULT __stdcall META_Audio_EX_QueryFlexibleEqBandNumber(unsigned int ms_timeout, short* count);
META_RESULT __stdcall META_Audio_EX_QueryFlexibleEqBandNumber_r(const int meta_handle, unsigned int ms_timeout, short* count);
META_RESULT __stdcall META_Audio_EX_SetFlexibleEq(unsigned int ms_timeout, char on_off);
META_RESULT __stdcall META_Audio_EX_SetFlexibleEq_r(const int meta_handle, unsigned int ms_timeout, char on_off);
typedef struct
{
    unsigned int bufferLength; /**< \brief [IN] the length of buffer */
    char*        buffer;       /**< \brief [IN] buffer for the Flexible EQ parameter setting (init parameters or magnitude) */
} Audio_Ex_FlexibleEqBuffer_T;
META_RESULT __stdcall META_Audio_EX_SetFlexibleEqMagnitude(unsigned int ms_timeout, const Audio_Ex_FlexibleEqBuffer_T* req);
META_RESULT __stdcall META_Audio_EX_SetFlexibleEqMagnitude_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_FlexibleEqBuffer_T* req);
META_RESULT __stdcall META_Audio_EX_SetFlexibleEqInitParam(unsigned int ms_timeout, const Audio_Ex_FlexibleEqBuffer_T* req);
META_RESULT __stdcall META_Audio_EX_SetFlexibleEqInitParam_r(const int meta_handle, unsigned int ms_timeout, const Audio_Ex_FlexibleEqBuffer_T* req);
/**
 * @}
 */
#endif // #ifndef __META_AUDIO_H__

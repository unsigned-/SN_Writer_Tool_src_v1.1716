#ifndef _WM_META_CCT_6238_H_
#define _WM_META_CCT_6238_H_

#include "wmmeta.h"
#include "wm_meta_cct.h"
#ifdef __cplusplus
extern "C" {
#endif


#define CCT_MAX_ISO_LUT_NO 3
#define CCT_AE_TOTAL_GAMMA_NO 	    	5
#define CCT_AE_GAMMA_STEP_NO 			20
#define CCT_AE_GAMMA_LUT_BIN_NO 		64
#define CCT_GAMMA_STEP_NO 				20
#define CCT_AE_GAMMA_CURVE_NO 	    	4
#define CCT_AE_GAMMA_BIN_NO             20  
#define CCT_AE_MAX_FLARE_HIST_NO        10
#define CCT_AE_MAX_WIND_NO              25
#define CCT_AE_MAX_CCM_HIST_NO          64
#define CCT_AE_TOTAL_GAMMA_NO           5
#define CDT_XENON_DURATION_LUT_NO_MAX   20
//-----------------------------------------------------
//
//     CCT 6238 AE related API
//
//-----------------------------------------------------

//#define META_CCT_6238_MAX_AE_TABLE_SIZE		256

META_RESULT __stdcall META_CCT_6238_AE_Enable(void);
META_RESULT __stdcall META_CCT_6238_AE_Disable(void);

// [TH] : add temp
typedef enum
{
    CAM_6238_AUTO_DSC = 0,
    CAM_6238_PORTRAIT,
    CAM_6238_LANDSCAPE,
    CAM_6238_SPORT,
    CAM_6238_FLOWER,
    CAM_6238_NIGHTSCENE,
   	CAM_6238_TV_MODE,    /* !MT6238 */
   	CAM_6238_AV_MODE,    /* !MT6238 */
   	CAM_6238_ISO_MODE,    /* !MT6238 */
    CAM_6238_DOCUMENT,
    CAM_6238_ISO_ANTI_HAND_SHAKE,
    CAM_6238_ISO100,
    CAM_6238_ISO200,
    CAM_6238_ISO400,
    CAM_6238_ISO800,
    CAM_6238_ISO1600,
    CAM_6238_VIDEO_AUTO,
    CAM_6238_VIDEO_NIGHT,
    CAM_6238_NO_OF_SCENE_MODE
}CCT_6238_DEV_SCENEMODE;

typedef enum
{
    CAM_6238_AE_METER_AUTO = 0,
    CAM_6238_AE_METER_SPOT,
    CAM_6238_AE_METER_CENTRAL,
    CAM_6238_AE_METER_AVERAGE,
    CAM_6238_NO_OF_AE_METERING
}CCT_6238_DEV_METERINGMODE;

META_RESULT __stdcall META_CCT_6238_AE_SetSceneMode( CCT_6238_DEV_SCENEMODE *req);

META_RESULT __stdcall META_CCT_6238_AE_GetSceneMode( CCT_6238_DEV_SCENEMODE *cnf);

META_RESULT __stdcall META_CCT_6238_AE_SetMeteringMode( CCT_6238_DEV_METERINGMODE *req);

META_RESULT __stdcall META_CCT_6238_AE_GetMeteringMode( CCT_6238_DEV_METERINGMODE *cnf);

typedef struct
{
	unsigned char	aeTableIdx;
	unsigned short 	aeShutterLine;
	unsigned short	aeSensorGain;	
	unsigned char	aeIspGain;	
	unsigned char	aeGammaNo;
	unsigned char	aeFlareOffset;	
    unsigned char	aePreviewGammaNo;
	unsigned char	aePreviewFlareOffset;
}CCT_6238_Dev_AE_CurrentExpoInfoResult;

typedef struct 
{
	unsigned char   aeLutEnable;      
	unsigned char	aeTableIdx;
	unsigned short 	aeShutterLine;
	unsigned short	aeSensorGain;	
	unsigned char	aeIspGain;	
	unsigned char	aeGammaNo;
	unsigned char	aeFlareOffset;	
}CCT_6238_Dev_AE_ApplyExpoInfo;

typedef struct
{
	unsigned char target_mean;
	unsigned char init_expo_idx;
}CCT_6238_Dev_AE_ExpoSetting;





META_RESULT __stdcall META_CCT_6238_AE_GetCurrentExpoInfo( CCT_6238_Dev_AE_CurrentExpoInfoResult *cnf);
META_RESULT __stdcall META_CCT_6238_AE_ApplyExpoInfo( CCT_6238_Dev_AE_ApplyExpoInfo *req);
META_RESULT __stdcall META_CCT_6238_AE_SelectBand(unsigned char *req);

META_RESULT __stdcall META_CCT_6238_AE_GetBand(unsigned char *cnf);

//META_RESULT __stdcall META_CCT_6238_AE_NotSelectBand(void);
META_RESULT __stdcall META_CCT_6238_AE_GetAutoExpoPara( CCT_6238_Dev_AE_ExpoSetting *cnf);
META_RESULT __stdcall META_CCT_6238_AE_UpdateAutoExpoPara( CCT_6238_Dev_AE_ExpoSetting *req);


typedef struct
{
	unsigned short	IsoGain[CCT_MAX_ISO_LUT_NO];
	unsigned short	IsoValue[CCT_MAX_ISO_LUT_NO];
}CCT_6238_Dev_AE_aeIsoLut; 

META_RESULT __stdcall META_CCT_6238_AE_GetIsoValueGain( CCT_6238_Dev_AE_aeIsoLut *cnf);
META_RESULT __stdcall META_CCT_6238_AE_UpdateIsoValueGain( CCT_6238_Dev_AE_aeIsoLut *req);

typedef struct
{
	unsigned char preview_gamma_no;
	// gamma table 
	//unsigned char gamma[CCT_AE_TOTAL_GAMMA_NO][CCT_AE_GAMMA_STEP_NO];
	// fast gamma lut for gamma mean 
	unsigned char gamma_lut[CCT_AE_TOTAL_GAMMA_NO][CCT_AE_GAMMA_LUT_BIN_NO];
}CCT_6238_Dev_AE_GammaSetting;

META_RESULT __stdcall META_CCT_6238_AE_GetGammaPara( CCT_6238_Dev_AE_GammaSetting *cnf);
META_RESULT __stdcall META_CCT_6238_AE_UpdateGammaPara( CCT_6238_Dev_AE_GammaSetting *req);

typedef struct
{
	unsigned char gamma[CCT_AE_TOTAL_GAMMA_NO][CCT_GAMMA_STEP_NO];
}CCT_6238_Dev_AE_GammaTable;

META_RESULT __stdcall META_CCT_6238_AE_GetGammaTable(CCT_6238_Dev_AE_GammaTable *cnf);


typedef struct
{
	/* capture flare offset cal */
	unsigned char 	flare_fix_flag;	
	unsigned char   flare_fix_offset;
	unsigned char	flare_search_dn_ratio;
	unsigned char 	preview_flare_offset;
}CCT_6238_Dev_AE_FlareSetting; 

META_RESULT _stdcall META_CCT_6238_AE_GetFlarePara( CCT_6238_Dev_AE_FlareSetting *cnf);
META_RESULT _stdcall META_CCT_6238_AE_UpdateFlarePara( CCT_6238_Dev_AE_FlareSetting *req);


typedef struct{
    unsigned int count;
    unsigned int histogram[CCT_AE_MAX_FLARE_HIST_NO];
}CCT_6238_Dev_AE_FlareHistogram;

META_RESULT __stdcall META_CCT_6238_AE_GetFlareHistogram(CCT_6238_Dev_AE_FlareHistogram *cnf);


typedef struct
{
	unsigned char 	aeLinearMean;
	unsigned char 	aeGammaMean;
	unsigned char 	aeMeteringRule;
}CCT_6238_Dev_AE_CurrentMeteringResult; 


META_RESULT __stdcall META_CCT_6238_AE_GetMeteringResult( CCT_6238_Dev_AE_CurrentMeteringResult *cnf);

typedef struct
{
	/* gamma mean */
	unsigned char indoor_outdoor_ev;
	unsigned char indoor_min_gamma_mean;
	unsigned char outdoor_max_gamma_mean;
	/* sky detection */
	unsigned char sky_ev;
	unsigned char sky_mean;
	unsigned char sky_max_window_mean;
	/* max under expo bin */
	unsigned char min_under_expo_bin;/* 33~63, default = 45 */	
	/* lowlight gamma limit */
	unsigned char lowlight_ev;
	unsigned char lowlight_min_target_mean;
	/* enable flag */
	unsigned char non_over_exposure_stretch_enabled;
	unsigned char full_dark_background_check_enabled;
    unsigned char backlight_stretch_enabled;
	unsigned char reserve_1;/* padding for even size */
	unsigned char reserve_2;/* padding for even size */   // TODO::
}CCT_6238_Dev_AE_MeteringSetting; 

META_RESULT __stdcall META_CCT_6238_AE_GetMeteringModeSetting( CCT_6238_Dev_AE_MeteringSetting *cnf);
META_RESULT __stdcall META_CCT_6238_AE_UpdateMeteringModeSetting( CCT_6238_Dev_AE_MeteringSetting *req);

// defined by [TH]
typedef struct{
    unsigned int window_pixel;
    unsigned int window[CCT_AE_MAX_WIND_NO];
    unsigned int histogram[CCT_AE_MAX_CCM_HIST_NO];
}CCT_6238_Dev_AE_WindowHistogram;

META_RESULT __stdcall META_CCT_6238_AE_GetWindowHistogram( CCT_6238_Dev_AE_WindowHistogram *cnf);


typedef struct
{
	/* method select */
	unsigned char aeSmoothMethod;/* 0:disabled, 1:enable */
	unsigned char aeSmoothFilterTape;/* media filter tape no, NA for curve like enable */
	/* normal */
	unsigned char aeSmoothNormalLastWeight;/* 0~128 */
	unsigned char aeSmoothNormalMaxStep;/* 1~4, NA for curve like enable */
	/* fast */
	unsigned char aeSmoothFastLastWeight;/* 0~128, NA for curve like enable */
	unsigned char aeSmoothFastMaxStep;/* 5~40, NA for curve like enable */
    unsigned char aeSmoothFastMaxChangeStep;/* 5~40, NA for curve like enable */
	unsigned char aeSmoothFastCheckCount;/* 0~3 */
	unsigned char aeSmoothFastBackCheckCount;/* 0~3, NA for curve like enable */
	unsigned char aeSmoothFastBackCount;/* 0~3, NA for curve like enable */
	unsigned char aeSmoothFastTransitionCount;/* 0~3, NA for curve like enable */
	unsigned char aeSmoothNormalToFastTh;/* 1~4 */
	unsigned char aeSmoothFastToNormalTh;/* 5~15*/
	/* speed normal & smooth fast */
	unsigned char aeSmoothFastSmoothEnable;/* 0: disable, 1:enable */
	unsigned char aeSmoothNormalSpeedEnable;/* 0: disable, 1:enable */
    unsigned char aeSmoothMovingStopCheckEnable;/* 0: disable, 1:enable */
	unsigned char aeSmoothMovingStopNormalCheckCount;/* 1~4 check count */
	unsigned char aeSmoothMovingStopFastCheckCount;/* 1~4 check count */
	unsigned char reserve_1;/* padding for even size */
	unsigned char reserve_2;/* padding for even size */ 
}CCT_6238_Dev_AE_SmoothMode; 

typedef struct{
    unsigned char mode;
    CCT_6238_Dev_AE_SmoothMode setting;
}CCT_6238_Dev_AE_UpdateSmoothMode;

META_RESULT __stdcall META_CCT_6238_AE_GetSmoothModeSetting( unsigned char *req_mode, CCT_6238_Dev_AE_SmoothMode *cnf );
META_RESULT __stdcall META_CCT_6238_AE_UpddateSmoothModeSetting( CCT_6238_Dev_AE_UpdateSmoothMode *req);


META_RESULT __stdcall META_CCT_6238_AE_EnablePreviewLog(void);
META_RESULT __stdcall META_CCT_6238_AE_DisablePreviewLog(void);

typedef struct
{
	unsigned char		aeCount;
	unsigned char		aeLinearMean;
    unsigned char		aeGammaMean;
	unsigned char		aeMeteringEv;	
	unsigned char		aeApplyEv;	
	unsigned char		aeDisplayEv;
}CCT_6238_Dev_AE_OutputCurrentAeInfo; 

META_RESULT __stdcall META_CCT_6238_AE_GetPreviewExpoInfo( CCT_6238_Dev_AE_OutputCurrentAeInfo *cnf);


META_RESULT __stdcall META_CCT_6238_AE_SetGammaBypass( unsigned char *req);
META_RESULT __stdcall META_CCT_6238_AE_GetGammaBypassFlag( unsigned char *cnf);

//-----------------------------------------------------
//
//     CCCT 6238 AWB related API
//
//-----------------------------------------------------
typedef struct {
    unsigned short awbRgain;
    unsigned short awbGgain;
    unsigned short awbBgain;    
}CCT_6238_Dev_AWB_Gain;

typedef struct {
    unsigned char preferenceFactor[3][3];
}CCT_6238_Dev_AWB_PreferenceFactor;

typedef struct {
    unsigned char m11;
    unsigned char m12;
    unsigned char m13;
    unsigned char m21;
    unsigned char m22;
    unsigned char m23;
    unsigned char m31;
    unsigned char m32;
    unsigned char m33;    
}CCT_6238_Dev_AWB_Matrix;

typedef struct {
    unsigned int         reg[30];
    unsigned short	     LightSource[7][4];	
	unsigned char        AWB_speed_fast;    
	unsigned char        AWB_speed_mid;  
	unsigned char        AWB_speed_slow;  
	unsigned char        AWB_thres_fast;      
	unsigned char        AWB_thres_mid;   
	unsigned char        AWBPreference[3][3]; 
	unsigned char        change_state_gain_thr;
	unsigned char        change_state_frame_thr;
	unsigned char        stable_state_gain_thr;  
	unsigned char        stable_state_frame_thr;
	unsigned char        finetune_state_gain_thr;
	unsigned char        finetune_state_frame_thr;
	unsigned char        awbSmFrameNum;  
	unsigned char        AWBPreferEn;    
	unsigned char        MWBFixedWinEn; 
	unsigned char        ALightMethod;
    unsigned char        awbSmallAWinEn; 
    unsigned char        awbSmallTL84WinEn; 
    unsigned char        awbSmallCWFWinEn; 
    unsigned char        awbSmallDWinEn;     
    unsigned char        awbCaptureFastConvergeEn;
	unsigned char        reservered[25];
}CCT_6238_Dev_AWB_V2Para;


typedef struct {
        unsigned char       LightSource[3][3][3];
        unsigned char       CCMPreferEn;
}CCT_6238_Dev_AWB_CCMPara;

typedef struct {
    unsigned char awbEn;
    unsigned char fastConvergeEn;
    unsigned char smallAWinEn;
    unsigned char smallTL84WinEn;
    unsigned char smallCWFWinEn;
    unsigned char smallDWinEn;
    unsigned char preferenceEn;
    unsigned char flashEn;
}CCT_6238_Dev_AWB_Status;

typedef struct {
    unsigned char dynamicCCMEn;
}CCT_6238_Dev_AWB_CCMStatus;

typedef struct{
	unsigned int windowWhitPoint[12];
}CCT_6238_Dev_AWB_WindowWhitPointArray;

typedef struct{
	unsigned char lightSourceMode;
	CCT_6238_Dev_AWB_Matrix nvram_ccm;
}CCT_6238_Dev_AWB_NvramCCMReq;

META_RESULT __stdcall META_CCT_6238_AWB_EnablePrefGain(void);
META_RESULT __stdcall META_CCT_6238_AWB_DisablePrefGain(void);

META_RESULT __stdcall META_CCT_6238_AWB_EnableFastConverge(void);
META_RESULT __stdcall META_CCT_6238_AWB_DisableFastConverge(void);

META_RESULT __stdcall META_CCT_6238_AWB_EnableAutoRun(void);
META_RESULT __stdcall META_CCT_6238_AWB_DisableAutoRun(void);

META_RESULT __stdcall META_CCT_6238_AWB_EnableSmallBox(unsigned int *req);
META_RESULT __stdcall META_CCT_6238_AWB_DisableSmallBox(unsigned int *req);

META_RESULT __stdcall META_CCT_6238_AWB_GetWindowWhitPointCountArray(CCT_6238_Dev_AWB_WindowWhitPointArray *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_GetLightSourceMode(unsigned int *cnf);

META_RESULT __stdcall META_CCT_6238_AWB_GetAWBGain(CCT_6238_Dev_AWB_Gain *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_SetAWBGain(CCT_6238_Dev_AWB_Gain *req);

META_RESULT __stdcall META_CCT_6238_AWB_SetPreferenceFactor(CCT_6238_Dev_AWB_PreferenceFactor *req);
META_RESULT __stdcall META_CCT_6238_AWB_GetPreferenceFactor(CCT_6238_Dev_AWB_PreferenceFactor *cnf);

META_RESULT __stdcall META_CCT_6238_AWB_EnableDynamicCCM(void);
META_RESULT __stdcall META_CCT_6238_AWB_DisableDynamicCCM(void);

META_RESULT __stdcall META_CCT_6238_AWB_SetCurrentCCM(CCT_6238_Dev_AWB_Matrix *req);
META_RESULT __stdcall META_CCT_6238_AWB_GetCurrentCCM(CCT_6238_Dev_AWB_Matrix *cnf);

META_RESULT __stdcall META_CCT_6238_AWB_EnableFlashSync(void);
META_RESULT __stdcall META_CCT_6238_AWB_DisableFlashSync(void);

META_RESULT __stdcall META_CCT_6238_AWB_ApplyCameraPara2(void);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateCameraPara2(void);

META_RESULT __stdcall META_CCT_6238_AWB_GetNvramCCM( unsigned char *req_mode, CCT_6238_Dev_AWB_Matrix *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_SetNvramCCM(CCT_6238_Dev_AWB_NvramCCMReq *req);

META_RESULT __stdcall META_CCT_6238_AWB_GetAWBPara(CCT_6238_Dev_AWB_V2Para *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_GetCCMPara(CCT_6238_Dev_AWB_CCMPara *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateAWBPara(CCT_6238_Dev_AWB_V2Para *req);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateCCMPara(CCT_6238_Dev_AWB_CCMPara *req);

META_RESULT __stdcall META_CCT_6238_AWB_GetAWBStatus(CCT_6238_Dev_AWB_Status *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_GetCCMStatus(CCT_6238_Dev_AWB_CCMStatus *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateAWBStatus(CCT_6238_Dev_AWB_Status *req);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateCCMStatus(CCT_6238_Dev_AWB_CCMStatus *req);

//-----------------------------------------------------
//
//     CCCT 6238 ISP related API
//
//-----------------------------------------------------

typedef struct ispHalfShadingTable{
    unsigned char mode;
    unsigned int offset;
    unsigned int length;
    unsigned int buffer[100];
}CCT_6238_Dev_ISP_PartialShadingTable;

typedef struct 
{
	unsigned char  ENNR;
	unsigned char  GNF;
	unsigned char  S1;
	unsigned char  S2;
	unsigned short MBND;
	unsigned char  GN1;
	unsigned char  GN2;
	unsigned char  GN3;
	unsigned char  VLR1;
	unsigned char  VLR2;
	unsigned char  VLR3;
	unsigned char  VLR4;
	unsigned char  VLR5;
	unsigned char  VLR6;
	unsigned char  VLR7;
	unsigned char  VLR8;
	unsigned char  VLGR1;
	unsigned char  VLGR2;
	unsigned char  VLGR3;
	unsigned char  VLGR4;
	unsigned char  VLGR5;
	unsigned char  VLGR6;
	unsigned char  VLGR7;
	unsigned char  VLGR8;
	unsigned char  VLGB1;
	unsigned char  VLGB2;
	unsigned char  VLGB3;
	unsigned char  VLGB4;
	unsigned char  VLGB5;
	unsigned char  VLGB6;
	unsigned char  VLGB7;
	unsigned char  VLGB8;
	unsigned char  VLB1;
	unsigned char  VLB2;
	unsigned char  VLB3;
	unsigned char  VLB4;
	unsigned char  VLB5;
	unsigned char  VLB6;
	unsigned char  VLB7;
	unsigned char  VLB8;
}CCT_6238_Dev_ISP_cct_NR1_comp_struct ;

typedef struct 
{
	unsigned char ENC;
	unsigned char ENY;
	unsigned char UV_SMPL;
	unsigned char S2;
	unsigned char S3;
	unsigned char SY1;
	unsigned char SC1;
	unsigned char GNY;
	unsigned char GNC;
	unsigned char PTY1;
	unsigned char PTY2;
	unsigned char PTY3;	
	unsigned char PTY4;
	unsigned char PTC1;
	unsigned char PTC2;
	unsigned char PTC3;
	unsigned char PTC4;
}CCT_6238_Dev_ISP_cct_NR2_comp_struct;

typedef struct 
{
	unsigned char ED_GAIN_TH;
	unsigned char CLIP_UNDER_TH;
	unsigned char CLIP_OVER_TH;
	unsigned char ED_BOUND_EN;
	unsigned char FILTER_SEL;
	unsigned char CLIP_UNDER_EN;
	unsigned char CLIP_OVER_EN;
	unsigned char YEDGE_EN;
	unsigned char RGBEDGE_EN;
	unsigned char ED_LUT_X1;
	unsigned char ED_LUT_X2;
	unsigned char ED_LUT_X3;	
	unsigned char ED_LUT_Y1;
	unsigned char ED_LUT_Y2;
	unsigned char ED_LUT_Y3;	
	unsigned char ED_LUT_Y4;	
}CCT_6238_Dev_ISP_cct_Edge_comp_struct;

typedef struct 
{
	unsigned char ENC3;
	unsigned char Y1;
	unsigned char Y2;
	unsigned char Y3;
	unsigned char Y4;
	unsigned char G1;
	unsigned char G2;
	unsigned char G3;
	unsigned char G4;
	unsigned char G5;
}CCT_6238_Dev_ISP_cct_Saturation_comp_struct;


typedef struct 
{
	unsigned char ENY3;
	unsigned char OFSTY;
	unsigned char GAINY;
	
}CCT_6238_Dev_ISP_cct_Contrast_comp_struct;

typedef struct 
{
	unsigned char  ENDP;
	unsigned short DP_THRD0;
	unsigned short DP_THRD1;
	unsigned short DP_THRD2;
	unsigned short DP_THRD3;
	unsigned short DP_THRD4;
	unsigned short DP_THRD5;
	unsigned short DP_THRD6;
	unsigned short DP_THRD7;
	unsigned char DP_CD1;
	unsigned char DP_CD2;
	unsigned char DP_CD3;
	unsigned char DP_CD4;
	unsigned char DP_CD5;
	unsigned char DP_CD6;
	unsigned char DP_CD7;
	unsigned char DP_SEL;
	unsigned char DP_NUM;
}CCT_6238_Dev_ISP_cct_autodefect_comp_struct_6238;


typedef struct{
	CCT_6238_Dev_ISP_cct_NR1_comp_struct                isp_nr1_set[7];
    CCT_6238_Dev_ISP_cct_NR2_comp_struct                isp_nr2_set[7];
    CCT_6238_Dev_ISP_cct_Edge_comp_struct               isp_edge_set[7];
    CCT_6238_Dev_ISP_cct_Saturation_comp_struct         isp_sat_set[7];
    CCT_6238_Dev_ISP_cct_Contrast_comp_struct           isp_contrast_set[3];
	CCT_6238_Dev_ISP_cct_autodefect_comp_struct_6238    isp_auto_defect_set[3];
	unsigned char  current_index;
    unsigned char  current_category;
}CCT_6238_Dev_ISP_Tuning_Cmd;

typedef struct
{
	unsigned char SDBLK_TRIG;
	unsigned char SHADING_EN;
	unsigned char SHADINGBLK_XOFFSET;
	unsigned char SHADINGBLK_YOFFSET;
	unsigned char SHADINGBLK_XNUM;
	unsigned char SHADINGBLK_YNUM;
	unsigned short SHADINGBLK_WIDTH;
	unsigned short SHADINGBLK_HEIGHT;
	unsigned int SHADING_RADDR;
	unsigned short SD_LWIDTH;
	unsigned short SD_LHEIGHT;
	unsigned char SDBLK_RATIO00;
	unsigned char SDBLK_RATIO01;
	unsigned char SDBLK_RATIO10;
	unsigned char SDBLK_RATIO11;
	unsigned short SD_TABLE_SIZE;
}CCT_6238_Dev_ISP_cct_shading_comp_struct_6238;

typedef struct{
	unsigned char		mode;
	unsigned char		m_switch;
}CCT_6238_Dev_ISP_cct_ShadingStatusMsg;

META_RESULT __stdcall META_CCT_6238_ISP_SetShadingPara(CCT_6238_Dev_ISP_cct_shading_comp_struct_6238 *req);

META_RESULT __stdcall META_CCT_6238_ISP_GetShadingPara(CCT_6238_Dev_ISP_cct_shading_comp_struct_6238 *cnf);

META_RESULT __stdcall META_CCT_6238_ISP_EnableDynamicBypassMode(void);
META_RESULT __stdcall META_CCT_6238_ISP_DisableDynamicBypassMode(void);

META_RESULT __stdcall META_CCT_6238_ISP_GetTuningSet(CCT_6238_Dev_ISP_Tuning_Cmd *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetTuningSet(CCT_6238_Dev_ISP_Tuning_Cmd *req);

META_RESULT __stdcall META_CCT_6238_ISP_GetShadingTable(CCT_6238_Dev_ISP_PartialShadingTable *req, CCT_6238_Dev_ISP_PartialShadingTable *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetShadingTable(CCT_6238_Dev_ISP_PartialShadingTable *req);

META_RESULT __stdcall META_CCT_6238_ISP_SetShadingStatus(CCT_6238_Dev_ISP_cct_ShadingStatusMsg *req);
META_RESULT __stdcall META_CCT_6238_ISP_GetShadingStatus(CCT_6238_Dev_ISP_cct_ShadingStatusMsg *req, CCT_6238_Dev_ISP_cct_ShadingStatusMsg *cnf);


typedef struct{
	unsigned char	value[7];   // NR1, NR2, EDGE, SATURATION, CONTRAST, AUTODEFECT, AUTOSHADING
}CCT_6238_Dev_ISP_TuningSettingIndexValue;

META_RESULT __stdcall META_CCT_6238_ISP_SetTuningIndexValue(CCT_6238_Dev_ISP_TuningSettingIndexValue *req);
META_RESULT __stdcall META_CCT_6238_ISP_GetTuningIndexValue(CCT_6238_Dev_ISP_TuningSettingIndexValue *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_GetAeTotalGain(unsigned int *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_GetDynamicBypassModeOnOff(unsigned char *cnf);


//-----------------------------------------------------
//
//     CDT 6238 FlashLight related API
//
//-----------------------------------------------------

typedef struct
{
    unsigned char       prestrobe_en;           /* enable pre-strobe */        
    unsigned short      prestrobe_duty;	    	/* pre-strobe duty(us) */       
    unsigned short      prestrobe_times;        /* pre-strobe times */         
    unsigned char       redeye_en;              /* enable red eye */            
    unsigned short      redeye_duty;	    	/* red eye duty(us) */       
    unsigned short      redeye_offset;   	    /* red-eye-strobe offset(line) */   
    unsigned char       redeye_wait_frame;
    unsigned short      strobe_width;           /* the image width */  
    unsigned short      strobe_height;          /* the image height */  
    unsigned short      max_strobe_duty;	    /* main-strobe duty(us) */       
    unsigned short      ae_index;               /* ae index when capture */
    unsigned char       is_awb_apply;           /* apply r/g/b gain or not */    
    unsigned short      rgain;	                /* rgain when capture */
    unsigned short      ggain;	                /* ggain when capture */           
    unsigned short      bgain;	                /* bgain when capture */                   
    unsigned short      linearity_duty;         /*linearity measurement duty(us)*/
    unsigned char       linearity_count;        /*linearity measurement count num */ 
}CCT_6238_Dev_flashlight_cdt_capture_struct;

typedef struct
{
    unsigned int flash_linearity_ae_value[50];
}CCT_6238_Dev_flashlight_linearity_ae_result_struct;

META_RESULT __stdcall META_CCT_6238_FLASHLIGHT_LinearityPrestrobe(CCT_6238_Dev_flashlight_cdt_capture_struct *req);
META_RESULT __stdcall META_CCT_6238_FLASHLIGHT_GetLinearityResult(CCT_6238_Dev_flashlight_linearity_ae_result_struct *cnf);
META_RESULT __stdcall META_CCT_6238_FlashLightConf(CCT_6238_Dev_flashlight_cdt_capture_struct* req, exposure_lut_struct *cnf);

META_RESULT __stdcall META_CCT_6238_ISP_EnableBinningMode(void);
META_RESULT __stdcall META_CCT_6238_ISP_DisableBinningMode(void);
META_RESULT __stdcall META_CCT_6238_ISP_GetBinningMode(unsigned char *cnf);


typedef struct{
    unsigned char enableFlag;       // add for enable flag
	unsigned short max_sensor_gain;
	unsigned short max_isp_gain;
	unsigned short flash_gamma_no;
	unsigned short flash_flare_offset;
	unsigned short flash_target_mean;
	unsigned short flash_min_mean;
}CCT_6238_DEV_flashlight_cdt_ae_para_struct;


META_RESULT __stdcall META_CCT_6238_FLASH_SetAePara(CCT_6238_DEV_flashlight_cdt_ae_para_struct *req);
META_RESULT __stdcall META_CCT_6238_FLASH_GetAePara(CCT_6238_DEV_flashlight_cdt_ae_para_struct *cnf);

typedef struct{
	unsigned short		af_calibration_offset;
	unsigned short		af_calibration_data;	
}CCT_6238_DEV_nvram_lens_calibration_struct;

typedef struct{
	unsigned short		af_table_num;	
	unsigned short		af_home_idx;
	unsigned short		af_macro_idx;		
	unsigned short		af_infinite_idx;		
	unsigned short		af_hyper_pos;		
	unsigned short		af_me_home_pos;			
	unsigned short		af_me_macro_pos;		
	unsigned short		af_filter_type;			
}CCT_6238_DEV_af_table_range_struct;

typedef struct{
	unsigned short	pos;	
	unsigned short	distance;
}CCT_6238_DEV_af_table_step_struct;

typedef struct{
	CCT_6238_DEV_af_table_range_struct	table_range;	
	CCT_6238_DEV_af_table_step_struct	table_step[24];
}CCT_6238_DEV_nvram_af_table_info_struct;

typedef struct 
{
   	unsigned short dof_lut_size;
   	unsigned short dof_lut[8][3];
}CCT_6238_DEV_nvram_af_mz_dof_info_struct;


typedef struct 
{
	CCT_6238_DEV_nvram_lens_calibration_struct 	lens_calibration;
	CCT_6238_DEV_nvram_af_table_info_struct		table_info[3];
	CCT_6238_DEV_nvram_af_mz_dof_info_struct	    dof_table_info;
	unsigned short					para_info[38];	
}CCT_6238_DEV_nvram_af_para_struct;

META_RESULT __stdcall META_CCT_6238_AF_GET_PARA(CCT_6238_DEV_nvram_af_para_struct *cnf);
META_RESULT __stdcall META_CCT_6238_AF_SET_PARA(CCT_6238_DEV_nvram_af_para_struct *req);



typedef struct
{
	unsigned char	autodsc;
	unsigned char	portrait;
	unsigned char	landscape;
	unsigned char	sport;
	unsigned char    flower;
	unsigned char	nightscene;
	unsigned char	tvmode;
	unsigned char	avmode;
	unsigned char	isomode;
	unsigned char	document_mode;
	unsigned char	iso_anti_hand_shake_mode;
	unsigned char	iso_100_mode;
	unsigned char	iso_200_mode;
	unsigned char	iso_400_mode;
	unsigned char	iso_800_mode;
	unsigned char	iso_1600_mode;
	unsigned char	video_auto_mode;
	unsigned char	video_night_mode;
}CCT_6238_DEV_camcorder_mode_info_struct;

typedef struct
{
	unsigned char	flashlight;
	unsigned char	autofocus;
}CCT_6238_DEV_dsc_comp_info_struct;

typedef struct
{
	unsigned char	autoflash;
	unsigned char	forceon;
	unsigned char	forceoff;
	unsigned char	antiredeye;
}CCT_6238_DEV_flash_mode_info_struct;

typedef struct
{
	unsigned char	af_support;	
	unsigned char	single;
	unsigned char	multizone;
	unsigned char	continuous;
	unsigned char	range_auto;
	unsigned char	range_macro;
	unsigned char	range_landscape;		
}CCT_6238_DEV_af_preview_mode_info_struct;

typedef struct
{
	unsigned char	af_support;		
	unsigned char	automode;
	unsigned char	multizone;
	unsigned char	continuous;
	unsigned char	range_auto;
	unsigned char	range_macro;
	unsigned char	range_landscape;		
}CCT_6238_DEV_af_video_mode_info_struct;

typedef struct
{
	CCT_6238_DEV_af_preview_mode_info_struct	preview_mode;
	CCT_6238_DEV_af_video_mode_info_struct	video_mode;
}CCT_6238_DEV_af_info_struct;

typedef struct
{
	CCT_6238_DEV_camcorder_mode_info_struct     dscmode;
	CCT_6238_DEV_dsc_comp_info_struct           dsccomp;
	CCT_6238_DEV_flash_mode_info_struct         flashlight;
	CCT_6238_DEV_af_info_struct                 af;
}CCT_6238_DEV_camcorder_info_struct;

META_RESULT __stdcall META_CCT_6238_ISP_GetCamCorderInfo(CCT_6238_DEV_camcorder_info_struct *cnf);


META_RESULT __stdcall META_CCT_6238_ISP_BypassShadingModeEnable(void);
META_RESULT __stdcall META_CCT_6238_ISP_BypassShadingModeDisable(void);
typedef struct{
	unsigned short lut_trigger_time[CDT_XENON_DURATION_LUT_NO_MAX];
	unsigned short lut_result_time[CDT_XENON_DURATION_LUT_NO_MAX];
}CCT_6238_DEV_xenon_duration_lut_struct;

META_RESULT __stdcall META_CCT_6238_FLASH_DurationLut(CCT_6238_DEV_xenon_duration_lut_struct *req);


typedef struct {
    unsigned char mode;
    unsigned int offset;
    unsigned int length;
    unsigned int buffer[100];
}CCT_6238_Dev_ISP_PartialDefectTable;

META_RESULT __stdcall META_CCT_6238_ISP_DefectTableOn(void);
META_RESULT __stdcall META_CCT_6238_ISP_DefectTableOff(void);


META_RESULT __stdcall META_CCT_6238_ISP_GetDefectPartialTable(CCT_6238_Dev_ISP_PartialDefectTable *req, CCT_6238_Dev_ISP_PartialDefectTable *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetDefectPartialTable(CCT_6238_Dev_ISP_PartialDefectTable *req);

typedef enum
{
	ROLLING_MODE = 0,
	FRAME_MODE
}CCT_6238_CAMERA_CAPTURE_EXP_ENUM;

META_RESULT __stdcall META_CCT_6238_ISP_SetShutterMode(unsigned char *req);
META_RESULT __stdcall META_CCT_GetCaptureGChannelMean(unsigned int *cnf);

//---------------------TEST----------------------------
typedef struct {
    unsigned char mode;
    unsigned int offset;
    unsigned int length;
    unsigned int buffer[400];
}CCT_6238_Dev_ISP_DefectTable;


META_RESULT __stdcall META_CCT_6238_ISP_GetDefectTable(CCT_6238_Dev_ISP_DefectTable *req, CCT_6238_Dev_ISP_DefectTable *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetDefectTable(CCT_6238_Dev_ISP_DefectTable *req);

typedef struct {
    unsigned char mode;
    unsigned int offset;
    unsigned int length;
    unsigned int buffer[400];
}CCT_6238_Dev_ISP_ShadingTable;

META_RESULT __stdcall META_CCT_6238_ISP_GetShadingTableByPeerBuff(CCT_6238_Dev_ISP_ShadingTable *req, CCT_6238_Dev_ISP_ShadingTable *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetShadingTableByPeerBuff(CCT_6238_Dev_ISP_ShadingTable *req);
META_RESULT __stdcall META_CCT_6238_ISP_GetTuningSetByPeerBuff(CCT_6238_Dev_ISP_Tuning_Cmd *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetTuningSetByPeerBuff(CCT_6238_Dev_ISP_Tuning_Cmd *req);
META_RESULT __stdcall META_CCT_6238_AE_GetGammaParaByPeerBuff( CCT_6238_Dev_AE_GammaSetting *cnf);
META_RESULT __stdcall META_CCT_6238_AE_UpdateGammaParaByPeerBuff( CCT_6238_Dev_AE_GammaSetting *req);
META_RESULT __stdcall META_CCT_6238_AE_GetWindowHistogramByPeerBuff( CCT_6238_Dev_AE_WindowHistogram *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_GetAWBParaByPeerBuff(CCT_6238_Dev_AWB_V2Para *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_UpdateAWBParaByPeerBuff(CCT_6238_Dev_AWB_V2Para *req);
META_RESULT __stdcall META_CCT_6238_AF_GET_PARA_ByPeerBuff(CCT_6238_DEV_nvram_af_para_struct *cnf);
META_RESULT __stdcall META_CCT_6238_AF_SET_PARA_ByPeerBuff(CCT_6238_DEV_nvram_af_para_struct *req);
META_RESULT __stdcall META_CCT_6238_FLASHLIGHT_GetLinearityResultByPeerBuff(CCT_6238_Dev_flashlight_linearity_ae_result_struct *cnf);

//-----------------------------------------------------


//=====================================================================================================

typedef struct {
    unsigned char mode;
	unsigned char color_temperature;
    unsigned int offset;
    unsigned int length;
    unsigned int buffer[400];
}CCT_6238_Dev_ISP_ShadingTable_V3;

typedef enum{	
    CCT_LIGHT_SRC_A,
	CCT_LIGHT_SRC_T,
	CCT_LIGHT_SRC_C,        
	CCT_LIGHT_SRC_D,
	CCT_LIGHT_SRC_NUM,
}CCT_6238_LIGHT_SOURCE_ENUM;

META_RESULT __stdcall META_CCT_6238_ISP_GetShadingTableByPeerBuff_V3(CCT_6238_Dev_ISP_ShadingTable_V3 *req, CCT_6238_Dev_ISP_ShadingTable_V3 *cnf);
META_RESULT __stdcall META_CCT_6238_ISP_SetShadingTableByPeerBuff_V3(CCT_6238_Dev_ISP_ShadingTable_V3 *req);
META_RESULT __stdcall META_CCT_6238_Check_if_LSC_V3_support(unsigned char *cnf);
META_RESULT __stdcall META_CCT_6238_AWB_CT_ENABLE(void);
META_RESULT __stdcall META_CCT_6238_AWB_CT_DISABLE(void);
META_RESULT __stdcall META_CCT_6238_AWB_Set_CCT_LightSource(CCT_6238_LIGHT_SOURCE_ENUM *req);
META_RESULT __stdcall META_CCT_Dual_GetCameraLIDByIndex(int index, char* lid_str, int lid_str_size);

#ifdef __cplusplus
}
#endif

#endif
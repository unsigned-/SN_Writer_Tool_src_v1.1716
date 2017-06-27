#ifndef _WM_META_CCT_H_
#define _WM_META_CCT_H_

#include "wmmeta.h"

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// ISP and Sensor Register Profile Functions                                    
//------------------------------------------------------------------------------

typedef enum {
	CCT_VK_NONE,
	//Color Correction
	CCT_VK_G11,
	CCT_VK_G12,
	CCT_VK_G13,
	CCT_VK_G21,
	CCT_VK_G22,
	CCT_VK_G23,
	CCT_VK_G31,
	CCT_VK_G32,
	CCT_VK_G33,
	//Gamma
	CCT_VK_GAMMA1,
	CCT_VK_GAMMA2,
	CCT_VK_GAMMA3,
	CCT_VK_GAMMA4,
	CCT_VK_GAMMA5,
	CCT_VK_GAMMA6,
	CCT_VK_GAMMA7,
	CCT_VK_GAMMA8,
	CCT_VK_GAMMA9,
	CCT_VK_GAMMA10,
	CCT_VK_GAMMA11,
	CCT_VK_GAMMA1024_EN,

	// AWB parameter 
	CCT_VK_AXIS_R_GAIN,
	CCT_VK_AXIS_G_GAIN,
	CCT_VK_AXIS_B_GAIN,
	CCT_VK_OPD_U_GAIN,
	CCT_VK_OPD_V_GAIN,
	CCT_VK_OPD_RB_POSITIVE,
	CCT_VK_OPD_RB_NEGATIVE,
	CCT_VK_OPD_MG_POSITIVE,
	CCT_VK_OPD_MG_NEGATIVE,
	CCT_VK_R_GAIN,
	CCT_VK_G_GAIN,
	CCT_VK_GR_GAIN,
	CCT_VK_GB_GAIN,
	CCT_VK_B_GAIN,
	CCT_VK_AWB_ALL,
	CCT_VK_OPD_SUPSEL,
	CCT_VK_OPD_Y_LIMIT,

	//Sensor Curve Offsets
	CCT_VK_OFFSET_00_SIGN,
	CCT_VK_OFFSET_00_VALUE,
	CCT_VK_OFFSET_01_SIGN,
	CCT_VK_OFFSET_01_VALUE,
	CCT_VK_OFFSET_10_SIGN,
	CCT_VK_OFFSET_10_VALUE,
	CCT_VK_OFFSET_11_SIGN,
	CCT_VK_OFFSET_11_VALUE,

	//Global Pregain
	CCT_VK_PREGAIN_INT,
	CCT_VK_PREGAIN_FRAC,
	CCT_VK_PREGAIN_BYPASS,

	//Fist Pixel Information
	CCT_VK_LINE_POLARITY,
	CCT_VK_PIXEL_POLARITY,
	CCT_VK_PIXELID,

	//Sensor Curve Pregains
	CCT_VK_RAW_R_GAIN,
	CCT_VK_RAW_GR_GAIN,
	CCT_VK_RAW_GB_GAIN,
	CCT_VK_RAW_B_GAIN,

	//Sensor Gamma
	CCT_VK_SG_ENABLE,
	CCT_VK_SG_R_GAMMA1,	
	CCT_VK_SG_R_GAMMA2,	
	CCT_VK_SG_R_GAMMA3,	
	CCT_VK_SG_R_GAMMA4,	
	CCT_VK_SG_R_GAMMA5,	
	CCT_VK_SG_R_GAMMA6,	
	CCT_VK_SG_R_GAMMA7,	
	CCT_VK_SG_R_GAMMA8,	
	CCT_VK_SG_R_GAMMA9,	
	CCT_VK_SG_R_GAMMA10,
	CCT_VK_SG_R_GAMMA11,
	CCT_VK_SG_GR_GAMMA1,	
	CCT_VK_SG_GR_GAMMA2,	
	CCT_VK_SG_GR_GAMMA3,	
	CCT_VK_SG_GR_GAMMA4,	
	CCT_VK_SG_GR_GAMMA5,	
	CCT_VK_SG_GR_GAMMA6,	
	CCT_VK_SG_GR_GAMMA7,	
	CCT_VK_SG_GR_GAMMA8,	
	CCT_VK_SG_GR_GAMMA9,	
	CCT_VK_SG_GR_GAMMA10,
	CCT_VK_SG_GR_GAMMA11,
	CCT_VK_SG_GB_GAMMA1,	
	CCT_VK_SG_GB_GAMMA2,	
	CCT_VK_SG_GB_GAMMA3,	
	CCT_VK_SG_GB_GAMMA4,	
	CCT_VK_SG_GB_GAMMA5,	
	CCT_VK_SG_GB_GAMMA6,	
	CCT_VK_SG_GB_GAMMA7,	
	CCT_VK_SG_GB_GAMMA8,	
	CCT_VK_SG_GB_GAMMA9,	
	CCT_VK_SG_GB_GAMMA10,
	CCT_VK_SG_GB_GAMMA11,
	CCT_VK_SG_B_GAMMA1,	
	CCT_VK_SG_B_GAMMA2,	
	CCT_VK_SG_B_GAMMA3,	
	CCT_VK_SG_B_GAMMA4,	
	CCT_VK_SG_B_GAMMA5,	
	CCT_VK_SG_B_GAMMA6,	
	CCT_VK_SG_B_GAMMA7,	
	CCT_VK_SG_B_GAMMA8,	
	CCT_VK_SG_B_GAMMA9,	
	CCT_VK_SG_B_GAMMA10,
	CCT_VK_SG_B_GAMMA11,

	//Shading Compensation
	CCT_VK_SC_ENABLE,
	CCT_VK_SC_RANGE_ENABLE,
	CCT_VK_SC_CURVE_ENABLE,
	CCT_VK_SC_K,
	CCT_VK_SC_R_FACTOR,
	CCT_VK_SC_CX,
	CCT_VK_SC_CY,
	CCT_VK_SC_R_HI,
	CCT_VK_SC_R_LO,
	CCT_VK_SC_KR,
	CCT_VK_SC_KG,
	CCT_VK_SC_KB,
	CCT_VK_SC_CURVE_SEL,

	//Shading Compensation Gamma
	CCT_VK_SCG_R_GAMMA1,	
	CCT_VK_SCG_R_GAMMA2,	
	CCT_VK_SCG_R_GAMMA3,	
	CCT_VK_SCG_R_GAMMA4,	
	CCT_VK_SCG_R_GAMMA5,	
	CCT_VK_SCG_R_GAMMA6,	
	CCT_VK_SCG_R_GAMMA7,	
	CCT_VK_SCG_R_GAMMA8,	
	CCT_VK_SCG_R_GAMMA9,	
	CCT_VK_SCG_R_GAMMA10,
	CCT_VK_SCG_R_GAMMA11,
	CCT_VK_SCG_G_GAMMA1,	
	CCT_VK_SCG_G_GAMMA2,	
	CCT_VK_SCG_G_GAMMA3,	
	CCT_VK_SCG_G_GAMMA4,	
	CCT_VK_SCG_G_GAMMA5,	
	CCT_VK_SCG_G_GAMMA6,	
	CCT_VK_SCG_G_GAMMA7,	
	CCT_VK_SCG_G_GAMMA8,	
	CCT_VK_SCG_G_GAMMA9,	
	CCT_VK_SCG_G_GAMMA10,
	CCT_VK_SCG_G_GAMMA11,
	CCT_VK_SCG_B_GAMMA1,	
	CCT_VK_SCG_B_GAMMA2,	
	CCT_VK_SCG_B_GAMMA3,	
	CCT_VK_SCG_B_GAMMA4,	
	CCT_VK_SCG_B_GAMMA5,	
	CCT_VK_SCG_B_GAMMA6,	
	CCT_VK_SCG_B_GAMMA7,	
	CCT_VK_SCG_B_GAMMA8,	
	CCT_VK_SCG_B_GAMMA9,	
	CCT_VK_SCG_B_GAMMA10,
	CCT_VK_SCG_B_GAMMA11,

	//Auto Defect
	CCT_VK_AD_G_BOUND,
	CCT_VK_AD_RB_BOUND,
	CCT_VK_AD_DEFECT_COUNT,
	CCT_VK_AD_DF_EN1,
	CCT_VK_AD_DF_EN2,
	CCT_VK_AD_DF_EN3,
	CCT_VK_AD_DF_EN4,
	CCT_VK_AD_DF_EN5,

	// Defect Table 
	CCT_VK_DT_EN,

	//Unbalance
	CCT_VK_UB_G_CHECK_MIN,
	CCT_VK_UB_G_CHECK_MAX,
	CCT_VK_UB_G_CHECKR_ENABLE,
	CCT_VK_UB_G_COMP_POLARITY,
	CCT_VK_UB_G_COMP_ENABLE,

	// optional parameter 
	CCT_VK_OPTIONAL_TAG_BEGIN,

	CCT_VK_OV_LCC1,
	CCT_VK_OV_LCC2,
	CCT_VK_OV_LCC3,
	CCT_VK_OV_LCC4,
	CCT_VK_OV_LCC5,
    //--------[TH] add for 6238-------------------
    // WB Setting reg[6]~reg[29]
    CCT6238_VK_NONE,
    CCT6238_VK_AWBXY_WINL0,
    CCT6238_VK_AWBXY_WINR0,
    CCT6238_VK_AWBXY_WINU0,
    CCT6238_VK_AWBXY_WIND0,
    CCT6238_VK_AWBXY_WINL1,
    CCT6238_VK_AWBXY_WINR1,
    CCT6238_VK_AWBXY_WINU1,
    CCT6238_VK_AWBXY_WIND1, 
    CCT6238_VK_AWBXY_WINL2,
    CCT6238_VK_AWBXY_WINR2,
    CCT6238_VK_AWBXY_WINU2,
    CCT6238_VK_AWBXY_WIND2,
    CCT6238_VK_AWBXY_WINL3,
    CCT6238_VK_AWBXY_WINR3,
    CCT6238_VK_AWBXY_WINU3,
    CCT6238_VK_AWBXY_WIND3,
    CCT6238_VK_AWBXY_WINL4,
    CCT6238_VK_AWBXY_WINR4,
    CCT6238_VK_AWBXY_WINU4,
    CCT6238_VK_AWBXY_WIND4,
    CCT6238_VK_AWBXY_WINL5,
    CCT6238_VK_AWBXY_WINR5,
    CCT6238_VK_AWBXY_WINU5,
    CCT6238_VK_AWBXY_WIND5,
    CCT6238_VK_AWBXY_WINL6,
    CCT6238_VK_AWBXY_WINR6,
    CCT6238_VK_AWBXY_WINU6,
    CCT6238_VK_AWBXY_WIND6,
    CCT6238_VK_AWBXY_WINL7,
    CCT6238_VK_AWBXY_WINR7,
    CCT6238_VK_AWBXY_WINU7,
    CCT6238_VK_AWBXY_WIND7,
    CCT6238_VK_AWBXY_WINL8,
    CCT6238_VK_AWBXY_WINR8,
    CCT6238_VK_AWBXY_WINU8,
    CCT6238_VK_AWBXY_WIND8,
    CCT6238_VK_AWBXY_WINL9,
    CCT6238_VK_AWBXY_WINR9,
    CCT6238_VK_AWBXY_WINU9,
    CCT6238_VK_AWBXY_WIND9,
    CCT6238_VK_AWBXY_WINLA,
    CCT6238_VK_AWBXY_WINRA,
    CCT6238_VK_AWBXY_WINUA,
    CCT6238_VK_AWBXY_WINDA,
    CCT6238_VK_AWBXY_WINLB,
    CCT6238_VK_AWBXY_WINRB,
    CCT6238_VK_AWBXY_WINUB,
    CCT6238_VK_AWBXY_WINDB,    
    //--------------------------------------------
	CCT_VK_SIZE
} CCT_VAR_TO_K;

typedef enum {
	CCT_VAR_FMT_BIN = 0,
	CCT_VAR_FMT_OCT,
	CCT_VAR_FMT_HEX,
	CCT_VAR_FMT_DEC
} CCT_VAR_FORMAT;

typedef enum {
	CCT_VAR_ATTR_RW = 0,	// Read/Write 
	CCT_VAR_ATTR_RO,		// Read Only 
	CCT_VAR_ATTR_WO			// Write Only 
} CCT_VAR_ATTR;

typedef enum {
	CCT_REG_ISP = 0,
	CCT_REG_CMOS,
	CCT_REG_CCD
} CCT_REG_TYPE;

typedef struct _CCT_VAR_INFO {
	const char		*m_PathKey;
	const char 		*m_Name;
	unsigned int	m_Value;
	unsigned int	m_DefaultValue;
	unsigned char	m_StartBit;
	unsigned char	m_EndBit;
	CCT_VAR_ATTR	m_Attr;
	CCT_VAR_FORMAT	m_Format;
	CCT_VAR_TO_K	m_Tag;
} CCT_VAR_INFO;

typedef struct _CCT_REG_INFO {
	const char		*m_PathKey;
	const char		*m_Name;
	unsigned int	m_RegAddr;
	unsigned int	m_RegLenInByte;
	unsigned int	m_ValueLenInByte;
	unsigned int	m_Value;
	unsigned short	m_ApplyOrder;
} CCT_REG_INFO;

typedef struct _CCT_SUB_CATEGORY_INFO {
	const char		*m_Name;
} CCT_SUB_CATEGORY_INFO;

typedef struct _CCT_MAJOR_CATEGORY_INFO {
	const char		*m_Name;
} CCT_MAJOR_CATEGORY_INFO;

typedef struct _CCT_DEVICE_ID_INFO {
	unsigned int	m_DeviceId;
	const char		*m_Name;
} CCT_DEVICE_ID_INFO;

typedef struct _CCT_REG_TYPE_INFO {
	CCT_REG_TYPE	m_RegType;
	const char		*m_Name;
} CCT_REG_TYPE_INFO;

META_RESULT __stdcall META_CCT_ImportRegProfile(const char *reg_description_filepath);

META_RESULT __stdcall META_CCT_GetNumOfRegType(int *p_NumOfRegType);
META_RESULT __stdcall META_CCT_GetNumOfDeviceId(int *p_NumOfDeviceId);
META_RESULT __stdcall META_CCT_GetNumOfMajorCategory(int *p_NumOfMajorCate);
META_RESULT __stdcall META_CCT_GetNumOfSubCategory(int *p_NumOfSubCate);
META_RESULT __stdcall META_CCT_GetNumOfRegister(int *p_NumOfRegister);
META_RESULT __stdcall META_CCT_GetNumOfVar(int *p_NumOfVar);

META_RESULT __stdcall META_CCT_GetRegTypeIds(int *p_RegTypeIds, int NumOfRegType, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetDeviceIds(int RegTypeId, int *p_DeviceIds, int NumOfDeviceId, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetMajorCategoryIds(int DeviceId, int *p_MajorCateIds, int NumOfMajorCate, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetSubCategoryIds(int MajorCateId, int *p_SubCateIds, int NumOfSubCate, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetRegisterIds(int SubCateId, int *p_RegisterIds, int NumOfRegister, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetVarIds(int RegisterId, int *p_VarIds, int NumOfVar, int *p_GetCount);
META_RESULT __stdcall META_CCT_GetVarIdsBySubCate(int SubCateId, int RegisterId, int *p_VarIds, int NumOfVar, int *p_GetCount);

META_RESULT __stdcall META_CCT_GetRegTypeInfo(int RegTypeId, CCT_REG_TYPE_INFO  *p_info);
META_RESULT __stdcall META_CCT_GetDeviceIdInfo(int DeviceId, CCT_DEVICE_ID_INFO  *p_info);
META_RESULT __stdcall META_CCT_GetMajorCateInfo(int MajorCateId, CCT_MAJOR_CATEGORY_INFO  *p_info); 
META_RESULT __stdcall META_CCT_GetSubCateInfo(int SubCateId, CCT_SUB_CATEGORY_INFO  *p_info); 
META_RESULT __stdcall META_CCT_GetRegInfo(int RegisterId, CCT_REG_INFO  *p_info); 
META_RESULT __stdcall META_CCT_GetVarInfo(int VarId, CCT_VAR_INFO  *p_info);

const char * __stdcall META_CCT_GetVarUniqueKey(int VarId);
META_RESULT __stdcall META_CCT_GetVarValue(int VarId, unsigned int *p_value);
META_RESULT __stdcall META_CCT_SetVarValue(int VarId, unsigned int value);
META_RESULT __stdcall META_CCT_GetVarValueByUniqueKey(const char *VarUniqueKey, unsigned int *p_value);
META_RESULT __stdcall META_CCT_SetVarValueByUniqueKey(const char *VarUniqueKey, unsigned int value);

//------------------------------------------------------------------------------
// General                                                                      
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_Init(bool bEnableUSBCOM);
META_RESULT __stdcall META_CCT_GetISPID(unsigned int  *p_DeviceId);
META_RESULT __stdcall META_CCT_GetSensorID(unsigned int  *p_DeviceId);
META_RESULT __stdcall META_CCT_Cancel(void);
META_RESULT __stdcall META_CCT_OpenUsbPort(int nUsbComPort);
META_RESULT __stdcall META_CCT_CloseUsbPort();
void __stdcall META_CCT_UnitTest(unsigned int  subroutine_id);
void __stdcall META_CCT_NoTimeout(bool bEnable);

//------------------------------------------------------------------------------
// ISP and Sensor Register Read/Write Functions                                 
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_LoadAllRegFromTarget(void);
META_RESULT __stdcall META_CCT_SaveAllRegToTarget(void);
META_RESULT __stdcall META_CCT_ReadReg(const unsigned int DeviceId, const unsigned int reg_addr, const unsigned char reg_len, unsigned int &value, const unsigned char value_len);
META_RESULT __stdcall META_CCT_WriteReg(const unsigned int DeviceId, const unsigned int reg_addr, const unsigned char reg_len, const unsigned int value, const unsigned char value_len);

//------------------------------------------------------------------------------
// Trigger target to load NVRAM data as current setting                         
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_LoadFromNVRAM(void);

//------------------------------------------------------------------------------
// Trigger target to save current setting to NVRAM                              
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_SaveToNVRAM(void);

//------------------------------------------------------------------------------
// Preview on LCD Functions                                                     
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_PreviewOnLCD_Start(unsigned int DeviceId);
META_RESULT __stdcall META_CCT_PreviewOnLCD_Stop(unsigned int DeviceId);
META_RESULT __stdcall META_CCT_MainLCDBackLight_TurnOn(void);
META_RESULT __stdcall META_CCT_MainLCDBackLight_TurnOff(void);
META_RESULT __stdcall META_CCT_PreviewOnLCD_Ex(int meta_handle, bool bEnablePreview);

//------------------------------------------------------------------------------
// Capture Related Functions                                                    
//------------------------------------------------------------------------------

typedef enum {
	CAMERA_SUB_SAMPLE_1_1 =	1,	// 1:1 
	CAMERA_SUB_SAMPLE_1_2 = 2,	// 1:2 
	CAMERA_SUB_SAMPLE_1_4 = 4,	// 1:4 
	CAMERA_SUB_SAMPLE_1_8 = 8	// 1:8 
} CAMERA_SUB_SAMPLE_MODE;

typedef enum {
	 OUTPUT_RAW_8BITS = 0
	,OUTPUT_YUV
	,OUTPUT_JPEG
	,OUTPUT_RGB888
	,OUTPUT_RAW_10BITS
	,OUTPUT_EXT_RAW_8BITS
	,OUTPUT_EXT_RAW_10BITS
	,OUTPUT_EXT_YUV
} CAMERA_OUTPUT_FORMAT;

typedef enum {
	BAYER_PTN_GR = 0,
	BAYER_PTN_R,
	BAYER_PTN_B,
	BAYER_PTN_GB
} CAMERA_BAYER_PATTERN;

typedef void (*CALLBACK_META_CCT_CAPTURE)(unsigned char finished_percentage, unsigned int received_bytes, unsigned int total_bytes, void *cb_arg);

typedef struct {
	// shot screen range (position in pixel) 
	unsigned short	nLeftPos;	// 0~N 
	unsigned short	nTopPos;	// 0~N 
	unsigned short	nWidth;
	unsigned short	nHeight;
} CCT_CaptureScreen_T;

typedef struct {

	// shot screen range (position in pixel) 
	CCT_CaptureScreen_T			ShotScreen;

	// RAW doesn't support subsample 
	CAMERA_SUB_SAMPLE_MODE		SubSample; 

	CAMERA_OUTPUT_FORMAT		OutputFormat;

	CALLBACK_META_CCT_CAPTURE	cb;
	void *cb_arg;

} CCT_Capture_Req;

typedef struct {

	// actual shot screen (position in pixel), the original shot screen might be truncated if out of range 
	CCT_CaptureScreen_T			ShotScreen;

	// the bayer pattern of left-top start pixel 
	CAMERA_BAYER_PATTERN		BayerPattern;

	// actual image data buffer 
	unsigned short	nOutputBuf_Width;
	unsigned short	nOutputBuf_Height;
	char 	*pOutputBuf;		// don't forget to free it by calling META_CCT_FreeCaptureImage 

	// NOTICE! buffer size will be applied different formulas according to output format 
	// For RAW 8BITS format, the size will be nOutputBuf_Width x nOutputBuf_Height bytes 
	// For RAW 10BITS format, the size will be nOutputBuf_Width x nOutputBuf_Height x 2 bytes 
	// For YUV format, the size will be nOutputBuf_Width x nOutputBuf_Height x 4 bytes 
	unsigned int	nOutputBuf_Size;

} CCT_Capture_Result;

META_RESULT __stdcall META_CCT_QuerySensorMaxWidthHeight(unsigned int DeviceId, unsigned int *p_nMaxWidth, unsigned int *p_nMaxHeight);
META_RESULT __stdcall META_CCT_SingleShotCaptureEx(unsigned int DeviceId, const CCT_Capture_Req  *req, CCT_Capture_Result  *p_result);
META_RESULT __stdcall META_CCT_MultiShotCaptureEx(unsigned int DeviceId, const CCT_Capture_Req  *req, CCT_Capture_Result  *p_result);
META_RESULT __stdcall META_CCT_FreeCaptureImage(CCT_Capture_Result  *p_result);

//------------------------------------------------------------------------------
// Expose Value and Expose Compensation Level and Step                          
//------------------------------------------------------------------------------

typedef struct {
	unsigned char	Value;		// expose value 0~255 
	unsigned char	EC_Step;	// The range of EC_Step value is 1~4 , please see CCT_EC_Step for more details. 
	char			EC_Level;	// EC_Level for expose compensation, the valid range depends on the EC_Step you set. 
} CCT_Expose;

typedef struct {
	char	EC_Level;	// -N ~ +N 
	float	EC_Value;	// value measured in EV 
} CCT_EC_Unit;

typedef struct {

	// the range of Step value is 1~4 , the meaning as below. 
	// 1: 1 EV for each step 
	// 2: 1/2 EV for each step 
	// 3: 1/3 EV for each step 
	// 4: 1/4 EV for each step 
	unsigned char	Step;

	// LevelCount describes how many level you can select in current step setting. 
	unsigned char	LevelCount;

	// LevelArray describes level and its value. 
	// For example, let's assume Step=2, LevelCount=9, then the LevelArrary will be the following 
	// LevelArray[0]= { -4, -2.000 } 
	// LevelArray[1]= { -3, -1.500 } 
	// LevelArray[2]= { -2, -1.000 } 
	// LevelArray[3]= { -1, -0.500 } 
	// LevelArray[4]= {  0,  0.000 } 
	// LevelArray[5]= { +1, +0.500 } 
	// LevelArray[6]= { +2, +1.000 } 
	// LevelArray[7]= { +3, +1.500 } 
	// LevelArray[8]= { +4, +2.000 } 
	CCT_EC_Unit		LevelArray[32];	

} CCT_EC_Step;

typedef struct {
	unsigned int	BaseShutter_60Hz;
	unsigned int	BaseShutter_50Hz;
} CCT_BandingFactor_T;

typedef struct {
	unsigned char	cal_period;
	unsigned char	cal_delay_frame;
	unsigned char	gain_delay_frame;
	unsigned char	sensor_gain_delay_frame;
	unsigned char	shutter_delay_frame;
} CCT_AE_PeriodPara;

META_RESULT __stdcall META_CCT_AE_Enable(void);
META_RESULT __stdcall META_CCT_AE_Disable(void);
META_RESULT __stdcall META_CCT_AE_SetExposeLevel(const CCT_Expose *expose);
META_RESULT __stdcall META_CCT_AE_GetExposeLevel(CCT_Expose *expose);
META_RESULT __stdcall META_CCT_AE_QueryECStepInfo(const unsigned char ec_step, CCT_EC_Step *ec_step_info);
META_RESULT __stdcall META_CCT_AE_SetInitShutter(const unsigned short init_shutter);
META_RESULT __stdcall META_CCT_AE_GetInitShutter(unsigned short *p_init_shutter);
META_RESULT __stdcall META_CCT_AE_SetManualShutter(const unsigned short manual_shutter);
META_RESULT __stdcall META_CCT_AE_GetManualShutter(unsigned short *p_manual_shutter);
META_RESULT __stdcall META_CCT_AE_SetPeriodPara(const CCT_AE_PeriodPara *p_ae_period_para);
META_RESULT __stdcall META_CCT_AE_GetPeriodPara(CCT_AE_PeriodPara *p_ae_period_para);
META_RESULT __stdcall META_CCT_GetBandingFactor(CCT_BandingFactor_T  *p_banding_factor);

//------------------------------------------------------------------------------
// White Balance                                                                
//------------------------------------------------------------------------------

typedef struct {
	unsigned short	ColorTemperature;
	unsigned short	R_Gain;
	unsigned short	G_Gain;
	unsigned short	B_Gain;
} CCT_WhiteBalance;

typedef enum {
	CAMERA_WB_MANUAL_1 = 0,
	CAMERA_WB_MANUAL_2,
	CAMERA_WB_MANUAL_3,
	CAMERA_WB_MANUAL_4,
	CAMERA_WB_MANUAL_5,
	CAMERA_WB_AUTO = 0xAA,
	CAMERA_WB_RESET = 0xBB,
	CAMERA_WB_OFF = 0xFF
} CAMERA_WB_SETTING;

typedef struct {
	// If ActivatedIndex is between 0~4. It indicates which manual white-balance 
	// setting is applied on target now. 
	// If ActivatedIndex is CCT_WB_AUTO, It indicates white-balance firmware is 
	// in auto mode. 
	// If ActivatedIndex is CCT_WB_OFF, It indicates white-balance firmware is  
	// shutdown now. 
	CAMERA_WB_SETTING		ActivatedIndex;
	CCT_WhiteBalance		m_WB[5];
} CCT_WhiteBalance_Array;

META_RESULT __stdcall META_CCT_WB_SetByIndex(const CAMERA_WB_SETTING  index, const CCT_WhiteBalance  *wb);
META_RESULT __stdcall META_CCT_WB_Activate(const CAMERA_WB_SETTING  index);
META_RESULT __stdcall META_CCT_WB_QueryAll(CCT_WhiteBalance_Array  *wb_array);

//------------------------------------------------------------------------------
// GAMMA                                                                        
//------------------------------------------------------------------------------
typedef struct {
	unsigned char	m_Gamma[1024];
} CCT_GammaTable_T;

META_RESULT __stdcall META_CCT_GammaOnOff(const bool bOn);
META_RESULT __stdcall META_CCT_GetGammaOnOffState(bool *p_bOnOff);
META_RESULT __stdcall META_CCT_GammaTableOnOff(const bool bOn);
META_RESULT __stdcall META_CCT_GetGammaTableOnOffState(bool *p_bOnOff);
META_RESULT __stdcall META_CCT_GetGammaTable(CCT_GammaTable_T  *p_result);
META_RESULT __stdcall META_CCT_SetGammaTable(const CCT_GammaTable_T  *p_req);

//------------------------------------------------------------------------------
// ISP Compensation Related Functions                                           
//------------------------------------------------------------------------------

typedef enum {
	 CCT_COMP_PREVIEW_NORMAL_SET = 0
	,CCT_COMP_PREVIEW_LOWLIGHT_SET
	,CCT_COMP_CAPTURE_NORMAL_SET
	,CCT_COMP_CAPTURE_LOWLIGHT_SET
} CCT_COMP_SET_ENUM;

typedef struct {
	unsigned char	SHADING_RANGE_EN;
	unsigned char	SHADING_EN;
	unsigned char	K_FACTOR;
	unsigned char	RADIUS_FACTOR;
	unsigned short	SHADING_CENTERX;
	unsigned short	SHADING_CENTERY;
	unsigned char	SHADING_RANGE_HI;
	unsigned char	SHADING_RANGE_LO;
	unsigned char	SHADING_KR;
	unsigned char	SHADING_KG;
	unsigned char	SHADING_KB;
	unsigned char	SHADING_CURVE_EN;
	unsigned char	SHADING_CURVE_SEL;
	unsigned char	SHADING_GAMMA[3][11];
} CCT_SHADING_COMPENSATION;

typedef struct {
	unsigned char	ADC_EN;
	unsigned char	ADL_EN;
	unsigned char	ADR_EN;
	unsigned char	ADU_EN;
	unsigned char	ADD_EN;
	unsigned char	DEADCHECK;
	unsigned char	BRIGHTTHD;
	unsigned char	BLACKTHD;
	unsigned char	GCHECKTHD;
	unsigned char	RBCHECKTHD;
	unsigned char	GCORRECTTHD;
	unsigned char	RBCORRECTTHD;
} CCT_AUTODEFECT_COMPENSATION;

typedef enum {
	 DEFECT_AREA_AVG = 1
	,DEFECT_AREA_CENTER_PRI
} CCT_DEFECT_AREA_E;

typedef enum {
	 DEFECT_PROCESS_BLACK_PIXEL_ONLY = 1
	,DEFECT_PROCESS_WHITE_PIXEL_ONLY	
	,DEFECT_PROCESS_BOTH_BW
	,DEFECT_PROCESS_BOTH_WB			
} CCT_DEFECT_PROCESS_E;

typedef struct {
	unsigned short			image_width;			// [OUT] 
	unsigned short			image_height;			// [OUT] 
	unsigned short			block_width_factor;		// [IN/OUT] 
	unsigned short			block_height_factor;	// [IN/OUT] 
	unsigned short			boarder_len;			// [IN/OUT] 
} CCT_DEFECT_TABLE_CAL_BLOCK_FACTOR;

typedef struct {
	CCT_DEFECT_AREA_E		search_mode_select;
	CCT_DEFECT_PROCESS_E	defect_type_select;
	unsigned char			threshold_area1;
	unsigned char			threshold_area2;
	unsigned short			image_width;	// [OUT] 
	unsigned short			image_height;	// [OUT] 
	unsigned short			block_width_factor;
	unsigned short			block_height_factor;
	unsigned short			boarder_len;
	unsigned short			max_defect_num;
	unsigned short			max_search_num;
} CCT_DEFECT_TABLE_CAL_PARA;

typedef struct {
	unsigned char	area_id;
	unsigned char	pixel_diff;
	unsigned short	pos_x;
	unsigned short	pos_y;
} CCT_DEFECT_PIXEL;

typedef struct {
	unsigned short			defect_num;
	unsigned short			search_num;			// this field is ignored in META_CCT_SetDefectTable() function 
	CCT_DEFECT_PIXEL		pixel_list[256];
} CCT_DEFECT_PIXEL_LIST;

typedef struct {
	bool						is_cal_result;	// 0: defectpixel is from NVRAM, cal_para, area_id and pixel_diff are ignored. 
												// 1: cal_para and defectpixel are calibration result, all fields are meaningful. 
	CCT_DEFECT_TABLE_CAL_PARA	cal_para;
	CCT_DEFECT_PIXEL_LIST		defectpixel;
} CCT_DEFECT_TABLE;

META_RESULT __stdcall META_CCT_GetLastCompensationMode(CCT_COMP_SET_ENUM  *p_mode);
META_RESULT __stdcall META_CCT_GetCurCompensationMode(CCT_COMP_SET_ENUM  *p_mode);
META_RESULT __stdcall META_CCT_SetCurCompensationMode(const CCT_COMP_SET_ENUM  mode);
META_RESULT __stdcall META_CCT_GetShadingPara(CCT_SHADING_COMPENSATION  *cnf);
META_RESULT __stdcall META_CCT_SetShadingPara(const CCT_SHADING_COMPENSATION  *req);
META_RESULT __stdcall META_CCT_GetAutoDefectPara(CCT_AUTODEFECT_COMPENSATION  *cnf);
META_RESULT __stdcall META_CCT_SetAutoDefectPara(const CCT_AUTODEFECT_COMPENSATION  *req);
META_RESULT __stdcall META_CCT_GetAutoDefectCount(unsigned short *p_ad_count);
META_RESULT __stdcall META_CCT_DefectTableVerifyBlockFactor(CCT_DEFECT_TABLE_CAL_BLOCK_FACTOR  *block_factor);
META_RESULT __stdcall META_CCT_DefectTableCalibration(const CCT_DEFECT_TABLE_CAL_PARA  *req);
META_RESULT __stdcall META_CCT_DefectTableCalibrationAbort(void);
META_RESULT __stdcall META_CCT_GetDefectTable(CCT_DEFECT_TABLE  *cnf);
META_RESULT __stdcall META_CCT_SetDefectTable(const CCT_DEFECT_PIXEL_LIST  *req);
META_RESULT __stdcall META_CCT_DefectTable_OnOff(bool bOn);
META_RESULT __stdcall META_CCT_DefectTableBypassAndBackupSetting(void);
META_RESULT __stdcall META_CCT_DefectTableRestoreSetting(void);

//------------------------------------------------------------------------------
// Generate Camera Parameter C Source Code                                      
//------------------------------------------------------------------------------
META_RESULT __stdcall META_CCT_GenCameraParaTable(const char *output_filename);

//------------------------------------------------------------------------------
// Sensor Related Functions                                                     
//------------------------------------------------------------------------------

typedef struct {
	int		Value;
	int		Min;	// this field is ignored in META_CCT_SetSensorPregain() 
	int		Max;	// this field is ignored in META_CCT_SetSensorPregain() 
	bool	Exist;	// identify this item does exist in sensor driver, zero means not exist 
} CCT_SensorEngModeItem;

typedef struct {
	CCT_SensorEngModeItem	Pregain_R;
	CCT_SensorEngModeItem	Pregain_Gr;
	CCT_SensorEngModeItem	Pregain_Gb;
	CCT_SensorEngModeItem	Pregain_B;
} CCT_SensorPregain_T;

typedef struct {
	bool	Pregain_R_Result;	// zero means error 
	bool	Pregain_Gr_Result;	// zero means error 
	bool	Pregain_Gb_Result;	// zero means error 
	bool	Pregain_B_Result;	// zero means error 
} CCT_SensorPregainResult_T;

META_RESULT __stdcall META_CCT_GetSensorPregain(unsigned int DeviceId, CCT_SensorPregain_T  *p_result);
META_RESULT __stdcall META_CCT_SetSensorPregain(unsigned int DeviceId, const CCT_SensorPregain_T  *req, CCT_SensorPregainResult_T  *p_result);

META_RESULT __stdcall META_CCT_GetSensorEngModePara(unsigned int DeviceId, const char *group_name, const char *item_name, CCT_SensorEngModeItem  *p_result);
META_RESULT __stdcall META_CCT_SetSensorEngModePara(unsigned int DeviceId, const char *group_name, const char *item_name, const int value);

//------------------------------------------------------------------------------
// AF Functions                                                                 
//------------------------------------------------------------------------------
typedef struct {
	unsigned int	distance;		// calibration chart distance, 2.5M=250
	unsigned int	max_tol;		// if cal_step>AF_table_step+AF_max_tol, report over max tol 
	unsigned int	min_tol;		// if cal_step<AF_table_step-AF_min_tol, report under min tol
	unsigned char	min_step;		// precision of minimum step
} CCT_AF_LensOffsetCalPara;

typedef struct {
	unsigned char	err_code;
} CCT_AF_LensOffsetCalResult;

META_RESULT __stdcall META_CCT_AF_OnOff(bool bOn);
META_RESULT __stdcall META_CCT_AF_LensOffsetCalibration(const CCT_AF_LensOffsetCalPara  *req, CCT_AF_LensOffsetCalResult  *cnf);
META_RESULT __stdcall META_CCT_GetFlashLevel(unsigned int *flash_charge_level);
META_RESULT __stdcall META_CCT_SetFlashLevel(unsigned int flash_charge_level);
//------------------------------------------------------------------------------
// DeviceTool Functions                                                         
//------------------------------------------------------------------------------

//-------------------------------
// Device Info                   
//-------------------------------

typedef struct {
	bool	autodsc;
	bool	portrait;
	bool	landscape;
	bool	sport;
	bool	flower;
	bool	nightscene;
	bool	tvmode;
	bool	avmode;
	bool	isomode;
}dsc_mode_info_struct;

typedef struct {
	bool	flashlight;
	bool	autofocus;
}dsc_comp_info_struct;

typedef struct {
	bool	autoflash;
	bool	forceon;
	bool	forceoff;
	bool	antiredeye;
}flash_mode_info_struct;

typedef struct {
	bool	automode;
	bool	macro;
	bool	infinite;
	bool	manual;
}af_mode_info_struct;

typedef struct {
	dsc_mode_info_struct	dscmode;
	dsc_comp_info_struct	dsccomp;
	flash_mode_info_struct	flashlight;
	af_mode_info_struct		af;
}dsc_info_struct;

typedef struct {
	unsigned short			pregain_max;
	unsigned short			pregain_min;
}sensor_info_struct;

typedef struct {
	dsc_info_struct			dsc_info;
	sensor_info_struct		sensor_info;
}CCT_DevDscInfo;

typedef enum {
	AV020=0, AV028, AV035, AV040, AV045, AV050, AV056, AV063, AV071, AV080, 
	AV090, 	AV100, AV110, AV130, AV140, AV160, AV180, AV200, AV220, AV_NO
} APERTURE_VALUE_INDEX;

typedef struct {
	bool					iris[AV_NO];
}CCT_DevIrisInfo;

META_RESULT __stdcall META_CCT_Dev_GetDscInfo(CCT_DevDscInfo *cnf);
META_RESULT __stdcall META_CCT_Dev_GetIrisInfo(CCT_DevIrisInfo *cnf);
META_RESULT __stdcall META_CCT_Dev_SetIrisInfo(const CCT_DevIrisInfo *req);


//-------------------------------
// ISO Calibration          
//-------------------------------

typedef struct {
	unsigned short						gain[3];
} CCT_DevISOGain;

typedef struct {
	unsigned short						value[3];
} CCT_DevISOValue;
typedef struct {
	unsigned short						select;
} CCT_DevISOCapture;

typedef struct
{
    bool    charge_on;              
    unsigned int  timeout_ms;            
}CCT_FlashLightCharge;

typedef struct
{
    unsigned short   strobe_width;           /* the image width */  
    unsigned short   strobe_height; 
	unsigned int  strobe_offset;         
    unsigned int  strobe_duty;            
}CCT_FlashLightStrobe;

typedef struct
{
    bool    prestrobe_en;           /* enable pre-strobe */        
    unsigned short  prestrobe_duty;	    	/* pre-strobe duty(us) */
    unsigned short  prestrobe_times;        /* pre-strobe times */         
    bool    redeye_en;              /* enable red eye */            
    unsigned short  redeye_duty;	    	/* red eye duty(us) */       
    unsigned short  redeye_offset;   	    /* red-eye-strobe offset(line) */        
    unsigned short  strobe_width;           /* the image width */  
    unsigned short  strobe_height;          /* the image height */  
    unsigned short  mainstrobe_duty;	    /* main-strobe duty(us) */       
    unsigned short  ae_index;				/* ae index when capture */
	bool    is_awb_apply;           /* apply r/g/b gain or not */    
    unsigned short  rgain;	                /* rgain when capture */
    unsigned short  ggain;	                /* ggain when capture */           
    unsigned short  bgain;	                /* bgain when capture */ 
}CCT_FlashLightCapture;

typedef struct {
	unsigned short				width;
	unsigned short				height;
	unsigned short				preview_width;
	unsigned short				preview_height;
}FT_CCT_DEV_MODE_SIZE;
typedef struct {
	unsigned short			shutter;
	unsigned short			sensorgain;
	unsigned char			ispgain;
}exposure_lut_struct;
META_RESULT __stdcall META_CCT_GetISOGain(CCT_DevISOGain *cnf);
META_RESULT __stdcall META_CCT_SetISOGain(const CCT_DevISOGain *req);
META_RESULT __stdcall META_CCT_RecoverISOCapture(void);
META_RESULT __stdcall META_CCT_SetISOCapture(CCT_DevISOCapture *req);
META_RESULT __stdcall META_CCT_GetISOValue(CCT_DevISOValue *cnf);
META_RESULT __stdcall META_CCT_SetISOValue(const CCT_DevISOValue *req);

META_RESULT __stdcall META_CCT_FlashLightCharge(CCT_FlashLightCharge *req,unsigned int *flash_charge_timeout);
META_RESULT __stdcall META_CCT_FlashLightStrobe(CCT_FlashLightStrobe *req);
META_RESULT __stdcall META_CCT_FlashLightConf(CCT_FlashLightCapture *req, exposure_lut_struct *cnf);
META_RESULT __stdcall META_CCT_GetModeSize(FT_CCT_DEV_MODE_SIZE *cnf);
META_RESULT __stdcall META_CCT_GetFlashType(unsigned char *flash_type);
META_RESULT __stdcall META_CCT_SetFlashAEIndex(unsigned char ae_index, exposure_lut_struct *cnf);
META_RESULT __stdcall META_CCT_GetFlashAEIndex(unsigned char *ae_index);

META_RESULT __stdcall META_CCT_GetISOGain_Ex(CCT_DevISOGain *cnf);
META_RESULT __stdcall META_CCT_SetISOGain_Ex(const CCT_DevISOGain *req);
META_RESULT __stdcall META_CCT_GetISOValue_Ex(CCT_DevISOValue *cnf);
META_RESULT __stdcall META_CCT_SetISOValue_Ex(const CCT_DevISOValue *req);
META_RESULT __stdcall META_CCT_IfSupportISO(void);
//-------------------------------
// AE Table Calibration          
//-------------------------------

#define META_CCT_MAX_AE_TABLE_SIZE		256

typedef enum {
	 CAM_BANDING_50HZ=0
	,CAM_BANDING_60HZ
	,CAM_NO_OF_BANDING
} CAM_BANDING_FACTOR;

typedef enum {
	 CAM_AUTO_DSC=0
	,CAM_PORTRAIT
	,CAM_LANDSCAPE
	,CAM_SPORT
	,CAM_FLOWER
	,CAM_NIGHTSCENE
	,CAM_TV_MODE
	,CAM_AV_MODE
	,CAM_ISO_MODE
	,CAM_NO_OF_SCENE_MODE
} CAM_DSC_MODE;

typedef struct {
	CAM_BANDING_FACTOR		band;
	bool					videomode;
	CAM_DSC_MODE			dscmode;
}CCT_Dev_AE_SceneMode;

typedef struct {
	unsigned char			lutsize;
	unsigned short			step;		//Ev_step*1000, ex:0.1 -> 100
	unsigned short			minEv;		//Ev*1000
	unsigned short			maxEv;		//Ev*1000
	unsigned char			iris;		//No. of Iris
	unsigned char			sensor_basegain;	// Sensor base gain, bypass capture compensate when != 0x40 
    unsigned char		binning_enable;	//binning enable
	unsigned char		binning_offset;	//binning offset	
}ae_info_struct;

typedef struct {
	bool					strobe_pol;
	unsigned char			lutidx;
	unsigned short			duty;
	unsigned short			offset;
	unsigned short			shutter;
	unsigned short			min_shutter;
	unsigned short			max_shutter;
	unsigned short			fwb_rgain;
	unsigned short			fwb_ggain;
	unsigned short			fwb_bgain;
	unsigned short			sensorgain;
	unsigned char			ispgain;
}flash_info_struct;

typedef struct {
	ae_info_struct			ae;
	flash_info_struct		autoflash;
}device_info_struct;


typedef struct {
	unsigned char			table_size;
	exposure_lut_struct		ae_table[META_CCT_MAX_AE_TABLE_SIZE];
	unsigned char			iris_table[META_CCT_MAX_AE_TABLE_SIZE];
}CCT_Dev_AE_Table;

typedef struct {
	device_info_struct		device_info;
	CCT_Dev_AE_Table		ae_table;
}CCT_Dev_AE_Info;

typedef struct {
	unsigned short			start_index;	// zero-based index 
	unsigned short			end_index;		// zero-based index 
	unsigned int			ms_delay_time;
	CCT_Dev_AE_Table		freerun_table;
}CCT_Dev_AE_BypassFreeRunPara;

typedef struct {
	unsigned int			lum_info_size;
	unsigned int			lum_info[META_CCT_MAX_AE_TABLE_SIZE];
}CCT_Dev_AE_BypassFreeRunResult;

META_RESULT __stdcall META_CCT_Dev_AE_SetSceneMode(const CCT_Dev_AE_SceneMode  *p_scene_mode);
META_RESULT __stdcall META_CCT_Dev_AE_GetInfo(CCT_Dev_AE_Info *info);
META_RESULT __stdcall META_CCT_Dev_AE_SetTableIndex(unsigned char  activate_index);
META_RESULT __stdcall META_CCT_Dev_AE_SetValue(unsigned int  shutter, unsigned int  sensorgain, unsigned int  ispgain);
META_RESULT __stdcall META_CCT_Dev_AE_BypassFreeRun(const CCT_Dev_AE_BypassFreeRunPara *p_para, CCT_Dev_AE_BypassFreeRunResult *p_result);

//-------------------------------
// AF Table Calibration          
//-------------------------------

typedef struct {
	unsigned char		af_table_num;
	unsigned short		af_home_idx;
	unsigned short		af_macro_idx;
	unsigned short		af_infinite_idx;
	unsigned short		af_hyper_pos;
	unsigned short		af_me_home_pos;
	unsigned short		af_me_macro_pos;
	unsigned short		af_calibration_offset;
}lens_info_struct;

typedef struct {
	unsigned int		pos;
	unsigned int		distance;
}af_table_struct;

#define AF_NO	32

typedef struct {
	lens_info_struct	INFO;
	af_table_struct		AF[AF_NO];	
}CCT_Dev_AF_Table;;

typedef struct {
	unsigned int		pos;
	unsigned int		atf_value;
}CCT_Dev_AF_CalResult;

META_RESULT __stdcall META_CCT_Dev_AF_GetTable(CCT_Dev_AF_Table *table);
META_RESULT __stdcall META_CCT_Dev_AF_Calibration(CCT_Dev_AF_CalResult  *cnf);
META_RESULT __stdcall META_CCT_Dev_AF_SetTableIndex(unsigned char  activate_index);
META_RESULT __stdcall META_CCT_Dev_AF_SetPosition(unsigned int	pos);

//-------------------------------
// Strobe Calibration            
//-------------------------------

#define	INIT_FLASH_LIGHT	0xFFFF

typedef struct {
	unsigned int		curr_lum;
	unsigned int		target_lum;
}CCT_DevStrobeCalPara;

META_RESULT __stdcall META_CCT_Dev_StrobeCal_Enable(void);
META_RESULT __stdcall META_CCT_Dev_StrobeCal_SetPara(const CCT_DevStrobeCalPara  *req);
META_RESULT __stdcall META_CCT_Dev_StrobeCal_Disable(void);

typedef enum
{
	CCT_MAIN_SENSOR,
	CCT_SUB_SENSOR
}CCT_SENSOR_TYPE_ENUM;


#ifdef __cplusplus
}
#endif

#endif

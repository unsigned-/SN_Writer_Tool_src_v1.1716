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
 * meta_dll_gps.h
 *
 * Project:
 * --------
 *   META
 *
 * Description:
 * ------------
 *   This module contains the META DLL GPS exported API.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *           HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __META_DLL_GPS_H__
#define __META_DLL_GPS_H__
#if !defined(__GNUC__) || !defined(WIN32)
#include "meta.h"
#ifdef __cplusplus
extern "C" {
#endif
/**
 * \addtogroup Connectivity
 *  @{
 */
typedef enum
{
    META_GPS_OPEN_SUCCESS           = 0,  /**< \brief the open command is successful */
    META_GPS_OPEN_FAIL              = 1,  /**< \brief the open command is failed */
    META_GPS_CLOSE_DONE             = 2,  /**< \brief the close command is done */
    META_GPS_START_MP_TEST_SUCCESS  = 3,  /**< \brief the start test command is done */
    META_GPS_START_MP_TEST_FAIL     = 4,  /**< \brief the start test command is failed */
    META_GPS_STOP_MP_TEST_SUCCESS   = 5,  /**< \brief the stop test command is done */
    META_GPS_STOP_MP_TEST_FAIL      = 6,  /**< \brief the stop test command is failed */
    META_GPS_SV_IV_INVALID          = 7,  /**< \brief invalid SV_id */
    META_GPS_QUERY_BITMAP_SUCCESS   = 8,  /**< \brief the query command bitmap is done */
    META_GPS_CMD_BITMAP_INVALID     = 9,  /**< \brief invalid command bitmap */
    /* CW test responce */
    META_GPS_START_CW_TEST_SECCUSS  = 10, /**< \brief the start CW test command is done  */
    META_GPS_START_CW_TEST_FAIL     = 11, /**< \brief the start CW test command is failed */
    META_GPS_STOP_CW_TEST_SECCUSS   = 12, /**< \brief the stop CW test command is done */
    META_GPS_STOP_CW_TEST_FAIL      = 13, /**< \brief the stop CW test command is failed */
    /* CNR test responce */
    META_GPS_START_CNR_TEST_SUCCESS = 14, /**< \brief the start CNR test command is done  */
    META_GPS_START_CNR_TEST_FAIL    = 15, /**< \brief the start CNR test command is failed  */
    META_GPS_STOP_CNR_TEST_SUCCESS  = 16, /**< \brief the stop CNR test command is done  */
    META_GPS_STOP_CNR_TEST_FAIL     = 17, /**< \brief the stop CNR test command is failed  */
    /* FIX test responce */
    META_GPS_START_FIX_TEST_SUCCESS = 18, /**< \brief the start FIX test command is done  */
    META_GPS_START_FIX_TEST_FAIL    = 19, /**< \brief the start FIX test command is failed  */
    META_GPS_STOP_FIX_TEST_SUCCESS  = 20, /**< \brief the stop FIX test command is done  */
    META_GPS_STOP_FIX_TEST_FAIL     = 21, /**< \brief the stop FIX test command is failed  */
    MAX_NUM_OF_META_GPS_OP_RSP,
    /*here may add other response enum for future*/
}
META_GPS_OP_RSP_ENUM;

typedef struct
{
    unsigned char rsp_type;  /** response code: refer to META_GPS_OP_RSP_ENUM */
    unsigned int  valid_cmd_bitmask; /* valid_cmd_bitmask: valid bitmask for cmd  META_GPS_OP_START_TEST */
} META_GPS_COMMAND_RESPONSE_T;

META_RESULT __stdcall META_GPS_Open(const unsigned int ms_timeout, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_GPS_Open_r(const int meta_handle, const unsigned int ms_timeout, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_GPS_Close(const unsigned int ms_timeout, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength);
META_RESULT __stdcall META_GPS_Close_r(const int meta_handle, const unsigned int ms_timeout, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength);

typedef enum
{
    META_GPS_OP_OPEN               = 0,
    META_GPS_OP_CLOSE              = 1,
    META_GPS_OP_WRITE_CMD          = 2,
    /*here may add other operation type for future*/
    MAX_NUM_OF_META_GPS_OP_TYPE,
} META_GPS_OP_TYPE_ENUM;

typedef enum
{
    META_GPS_OP_START_MP_TEST        = 0,  /**< \brief start signal mode test */
    META_GPS_OP_STOP_MP_TEST         = 1,  /**< \brief stop  signal mode test */
    META_GPS_OP_QUERY_CMD_BITMAP     = 2,  /**< \brief query bitmap supported for signal mode test */
    META_GPS_OP_START_CW_TEST        = 3,  /**< \brief start CW mode test */
    META_GPS_OP_STOP_CW_TEST         = 4,  /**< \brief stop  CW mode test */
    META_GPS_OP_START_CNR_TEST       = 5,  /**< \brief start CNR mode test */
    META_GPS_OP_STOP_CNR_TEST        = 6,  /**< \brief stop  CNR mode test */
    META_GPS_OP_START_FIX_TEST       = 7,  /**< \brief sstart fix mode test */
    META_GPS_OP_STOP_FIX_TEST        = 8,  /**< \brief stop  fix mode test */
    //here may add other operation type for future
    MAX_NUM_OF_META_GPS_OP_CMD_TYPE,
} META_GPS_OP_CMD_TYPE_ENUM;

typedef struct
{
    unsigned char  cmd_type;   /**< cmd type of the op: refer to META_GPS_OP_CMD_TYPE_ENUM */
    unsigned int   SV_id;      /**< satellite id */
    unsigned int   cmd_bitmap; /**< bitmap for META_GPS_OP_START_TEST */
} META_GPS_COMMAND_REQUEST_T;
#define META_GPS_TEST_INFO    0x01
#define META_GPS_TEST_ACQ     0x02
#define META_GPS_TEST_BITSYNC 0x04
#define META_GPS_TEST_SIGNAL  0x08

#define META_GPS_PARSER_P_VERSION_MAX  32
typedef struct
{
    char         version[META_GPS_PARSER_P_VERSION_MAX];
    unsigned int number;
} META_GPS_MP_TEST_FW_VERSION_STRUCT;

typedef struct
{
    unsigned int   fix_interval; //unit: msec. reciprocal is update(Hz)
    unsigned int   duration;     //unit: msec
    unsigned int   run_interval; //unit: msec
    unsigned short hacc;
    unsigned short vacc;
} META_GPS_MP_TEST_FIX_CTRL_STRUCT;

typedef struct
{
    unsigned int   SV_id;
    unsigned short ACQ_test_time; //unit: second
} META_GPS_MP_TEST_ACQ_STRUCT;

typedef struct
{
    unsigned int   SV_id;
    unsigned short bitsync_test_time; //unit: second
} META_GPS_MP_TEST_BITSYNC_STRUCT;

typedef struct
{
    unsigned int   SV_id;            // 1~32
    unsigned short signal_test_time; // unit: second
    unsigned short phase_error;      // unit: 0.01
    unsigned short TCXO_offset;      // unit: 0.001
    unsigned short TCXO_driftt;     // unit: 0.001
    unsigned short CNR_mean;        // unit: 0.01
    unsigned short CNR_sigma;       // unit: 0.01
} META_GPS_MP_TEST_SIGNAL_STRUCT;

typedef union
{
    META_GPS_MP_TEST_FW_VERSION_STRUCT release;  // test_info_ver
    META_GPS_MP_TEST_FIX_CTRL_STRUCT   fix_ctrl; // test_info_fixctrl
    META_GPS_MP_TEST_ACQ_STRUCT        acq;      // test_acq
    META_GPS_MP_TEST_BITSYNC_STRUCT    bitsync;  // test_bitsync
    META_GPS_MP_TEST_SIGNAL_STRUCT     signal;   // test_signal
} META_GPS_MP_TEST_RESULT_U;

typedef struct
{
    unsigned short cnr;        // unit:1
    int            clk_drift;  // unit:0.001
} META_GPS_CW_TEST_RESULT_STRUCT;

typedef struct
{
    unsigned int   SV_id;      // SV ID which to be tested(1~32)
    unsigned short cnr;        // unit:1
} META_GPS_CNR_TEST_RESULT_STRUCT;

typedef struct
{
    unsigned short  fix_mode;  // 1:no-fix 2:2-D-fix 3:3D-fix
} META_GPS_FIX_TEST_RESULT_STRUCT;

typedef union
{
    META_GPS_MP_TEST_RESULT_U        mp_result;
    META_GPS_CW_TEST_RESULT_STRUCT   cw_result;
    META_GPS_CNR_TEST_RESULT_STRUCT  cnr_result;
    META_GPS_FIX_TEST_RESULT_STRUCT  fix_result;
} META_GPS_DATA_U;

typedef enum
{
    META_GPS_MP_TEST_FINISHED          = 0,
    META_GPS_DATA_IND_INFOR_VERSION    = 1,
    META_GPS_DATA_IND_INFOR_FIXCTRL    = 2,
    META_GPS_DATA_IND_ACQ              = 3,
    META_GPS_DATA_IND_BITSYNC          = 4,
    META_GPS_DATA_IND_SIGNAL           = 5,
    META_GPS_DATA_IND_CW_TEST_RESULT   = 6,
    META_GPS_DATA_IND_CNR_TEST_RESULT  = 7,
    META_GPS_DATA_IND_FIX_TEST_RESULT  = 8,
    MAX_NUM_OF_MEAT_GPS_DATA_IND_ENUM,
} META_GPS_DATA_IND_TYPE_ENUM;

typedef struct
{
    unsigned char ind_type;
    unsigned int  test_finished_flag;
    META_GPS_DATA_U result;
} META_GPS_DATA_T;
typedef void (__stdcall* META_GPS_DATA_CALLBACK)(const void* buffer, unsigned int bufferLength, void* cb_arg);
META_RESULT __stdcall META_GPS_Command(const unsigned int ms_timeout, const META_GPS_COMMAND_REQUEST_T* request, unsigned int requestLength, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength, META_GPS_DATA_CALLBACK cb, void* cb_arg);
META_RESULT __stdcall META_GPS_Command_r(const int meta_handle, const unsigned int ms_timeout, const META_GPS_COMMAND_REQUEST_T* request, unsigned int requestLength, META_GPS_COMMAND_RESPONSE_T* response, unsigned int responseLength, META_GPS_DATA_CALLBACK cb, void* cb_arg);
/**
 * @}
 */
#ifdef __cplusplus
}
#endif
#endif // #if !defined(__GNUC__) || !defined(WIN32)
#endif // __META_DLL_GPS_H__

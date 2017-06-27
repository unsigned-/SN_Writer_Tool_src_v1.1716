#ifndef __FP_CONN_PARA__
#define __FP_CONN_PARA__

#include "meta.h"

typedef struct
{
    int                    com_port;
    META_COMM_BAUDRATE     baudrate[12];       /**< [META] META stage baudrate polling array, it must end with META_BAUD_END. */
    BOOT_META_ARG          boot_meta_arg;      /**< [BootROM] please refer to brom.h */
    unsigned int           ms_connect_timeout; /**< [META] META stage sync timeout value (after BootROM negotiation pass) */
    unsigned int           usb_enable: 1;      /**< [META] Connect target with UART or USB, 0: UART 1: USB others:reserved */
    unsigned int           InMetaMode: 1;      /**< [META] Decide that need boot META or not 0:need boot META 1:already in meta mode */
	unsigned int           SwitchModeFlag: 1;  /**< [META] Decide that need boot META or not 0:normal mode META 1:already in meta mode */
    META_MODE_TRACE_PARA_T trace_para;         /**< [META] META mode trace parameters */
    META_SysTrace_CallBack sys_cb;             /**< MODEM System trace handler */
    void*                  sys_cb_arg;         /**< argument for MODEM System trace handler */
    int                    io_channel_mode;
    bool                   ext_tool_relay;
    bool                   use_open_db;
} FP_Conn_Para;

typedef struct
{
    FP_Conn_Para input_para;
    int* boot_stop;
} FP_Conn_Input;

typedef struct
{
    bool b_shutdown;
    bool b_backup;
	bool b_switchFlag;
} FP_Disconn_Input;

#endif
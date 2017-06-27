/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  eboot_debug.cpp
*
* Project:
* --------
*  Smart Phone Download Library.
*
* Description:
* ------------
*  Debug log
*
* Author:
* -------
*  Wayne Chen (mtk01370)
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Revision:   1.9  $
* $Modtime:   Oct 19 2005 10:54:48  $
* $Log:   //mtkvs01/vmdata/flash_tool/archives/BootRom/brom_debug.cpp-arc  $
*
* 
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#include "stdafx.h"
#include "xboot_debug.h"
#include "Mdebug.h"
#include <string>
#include <windows.h>

//--------------------------------------------------------------------------//
//  The definition of Xboot version Information                             //
//--------------------------------------------------------------------------//
extern HMODULE  g_EBOOT_DLL_hMODULE;
extern std::string	g_EBOOT_DLL_Version;
extern std::string	g_EBOOT_DLL_ReleaseType;
extern std::string	g_EBOOT_DLL_LoadPath;
extern std::string	g_EBOOT_DLL_BuildDate;

hMTRACE  g_hEBOOT_DEBUG = NULL;
hMTRACE	 g_hVIRTUAL_IO_DEBUG=NULL;


// inialize debug log handle here!
static MetaTrace_Handle_Sentry	g_eboot_debug_sentry(g_hEBOOT_DEBUG, "SNWriter", false, false);

//------------------------------------------------------------------------------
// EXPORTED: debug log turn on function                                         
//------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
int _Xboot_DebugOn( void )
{
    return _Xboot_DebugOn_With_FilePath("C:\\SN Writer.log");
}

int _Xboot_DebugOn_With_FilePath(const char * filepath)
{
    if(!MTRACE_IsDumpFileOpen(g_hEBOOT_DEBUG)) {
        if(MTRACE_DumpFileOpen(g_hEBOOT_DEBUG, filepath, "w")) {
            return 1;
        }
    }

    // set virtual io module debug handle
    g_hVIRTUAL_IO_DEBUG = g_hEBOOT_DEBUG;

    MTRACE_ON(g_hEBOOT_DEBUG);
    MTRACE(g_hEBOOT_DEBUG, "Xboot_DebugOn(): runtime trace is ON now.");
    return 0;
}

//------------------------------------------------------------------------------
// EXPORTED: debug log turn off function                                        
//------------------------------------------------------------------------------
int  _Xboot_DebugOff( void )
{
    MTRACE(g_hEBOOT_DEBUG, "Xboot_DebugOff(): runtime trace is OFF now.");
    MTRACE_OFF(g_hEBOOT_DEBUG);

    if (MTRACE_IsDumpFileOpen(g_hEBOOT_DEBUG))
        MTRACE_DumpFileClose(g_hEBOOT_DEBUG);

    return 0;
}

//------------------------------------------------------------------------------
// EXPORTED: clear debug log                                                    
//------------------------------------------------------------------------------
int _Xboot_DebugClear( void ) 
{
    int ret;

    if( 0 != (ret=MTRACE_DumpFileClear(g_hEBOOT_DEBUG)) ) {
        MTRACE_ERR(g_hEBOOT_DEBUG, "Xboot_DebugClear(): ret(%d).", ret);
        return 1;
    }

    MTRACE(g_hEBOOT_DEBUG, "Xboot_DebugClear(): OK!");
    //g_BROM_INI.m_nor_flash.DumpDebug();
    //g_BROM_INI.m_nand_flash.DumpDebug();
    //g_BROM_INI.m_res.DumpDebug();
    //DumpStatusCode();

    return 0;
}

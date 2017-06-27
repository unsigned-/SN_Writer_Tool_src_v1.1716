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
#include "Mdebug.h"
#include <string>
#include <windows.h>

extern HMODULE  g_EBOOT_DLL_hMODULE;
extern std::string	g_EBOOT_DLL_Version;
extern std::string	g_EBOOT_DLL_ReleaseType;
extern std::string	g_EBOOT_DLL_LoadPath;
extern std::string	g_EBOOT_DLL_BuildDate;

extern hMTRACE  g_hEBOOT_DEBUG ;
//------------------------------------------------------------------------------
// EXPORTED: debug log turn on function                                         
//------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
extern int _Xboot_DebugOn( void );
extern int _Xboot_DebugOn_With_FilePath(const char * filepath);

//------------------------------------------------------------------------------
// EXPORTED: debug log turn off function                                        
//------------------------------------------------------------------------------
extern int _Xboot_DebugOff( void );

//------------------------------------------------------------------------------
// EXPORTED: clear debug log                                                    
//------------------------------------------------------------------------------
extern int _Xboot_DebugClear( void );



#include "stdafx.h"

#include <stdio.h>

#ifndef  _SCERT_H_
#include "SCERT.h"
#endif

#ifndef _SP_BROM_H_
#include "sp_brom.h"
#endif

#include "Common.h"

#define false 0
#define true 1

//===========================================================================
bool  SPATE_SCERT_Create( void )
{
    int ret = SP_SCERT_Create( &g_sMetaComm.sAuthOption.t_SpScertHandle );
    if( ret != 0 )
        return false;
    return true;
}

//---------------------------------------------------------------------------
bool  SPATE_SCERT_Destroy( void )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpScertHandle )
        return false;
    
    ret = SP_SCERT_Destroy( &g_sMetaComm.sAuthOption.t_SpScertHandle );
    if( ret != 0 )
        return false;
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  SPATE_SCERT_Load( const char *scert_filepath )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpScertHandle )
        return false;
    
    ret = SP_SCERT_Load( g_sMetaComm.sAuthOption.t_SpScertHandle, scert_filepath );
    if( ret != 0 )
        return false;
    return true;
}

//--------------------------------------------------------------------------
bool  SPATE_SCERT_Unload( void )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpScertHandle )
        return false;
    
    ret = SP_SCERT_Unload( g_sMetaComm.sAuthOption.t_SpScertHandle );
    if( ret != 0 )
        return false;
    return true;
}

//--------------------------------------------------------------------------
SP_SCERT_HANDLE_T SPATE_Get_ScertHandle( void )
{   
    return g_sMetaComm.sAuthOption.t_SpScertHandle;
}
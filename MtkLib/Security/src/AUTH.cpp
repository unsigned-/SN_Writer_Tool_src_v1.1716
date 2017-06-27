#include "stdafx.h"
#include <stdio.h>

#ifndef  _AUTH_H_
#include "AUTH.h"
#endif

#ifndef _SP_BROM_H_
#include "sp_brom.h"
#endif

#include "Common.h"

#define false 0
#define true 1

//===========================================================================
bool  SPATE_AUTH_Create( void )
{
    int ret = SP_AUTH_Create( &g_sMetaComm.sAuthOption.t_SpAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//---------------------------------------------------------------------------
bool  SPATE_AUTH_Destroy( void )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpAuthHandle )
        return false;
    
    ret = SP_AUTH_Destroy( &g_sMetaComm.sAuthOption.t_SpAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  SPATE_AUTH_Load( const char *auth_filepath )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpAuthHandle )
        return false;
    
    ret = SP_AUTH_Load( g_sMetaComm.sAuthOption.t_SpAuthHandle, auth_filepath );
    if( ret != 0 )
        return false;
    return true;
}

//--------------------------------------------------------------------------
bool  SPATE_AUTH_Unload( void )
{
    int ret;
    if( NULL == g_sMetaComm.sAuthOption.t_SpAuthHandle )
        return false;
    
    ret = SP_AUTH_Unload( g_sMetaComm.sAuthOption.t_SpAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//--------------------------------------------------------------------------
SP_AUTH_HANDLE_T SPATE_Get_AuthHandle( void )
{   
    return g_sMetaComm.sAuthOption.t_SpAuthHandle;
}



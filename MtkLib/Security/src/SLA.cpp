#include "stdafx.h"
#include "brom.h"    
#include "flashtool_handle.h"     
#include "SLA.h"
#include "Common.h"
//static CSLA* g_sla_ptr;
//===========================================================================
//*******************************************************************************
//=========REQ_AUTH_Create & REQ_AUTH_Destroy========================================
//*********************************************************************************


int REQ_AUTH_Create( void )
{
    int ret;
    ret = AUTH_Create( &g_sMetaComm.sAuthOption.t_AuthHandle );
    if( ret != 0 )
    {
        goto Error; 
    }    
    return 0;

Error:
    return -1;   
}


//---------------------------------------------------------------------------
int REQ_AUTH_Destroy( void )
{
    int ret; 
    if( g_sMetaComm.sAuthOption.t_AuthHandle == NULL)
    {
        goto Error;
	}
    ret = AUTH_Destroy( &g_sMetaComm.sAuthOption.t_AuthHandle );
    if( ret != 0 )
    {
       goto Error; 
    }    
    return 0;

Error:
    return -1;    
}
//************************************************************************************
//===========REQ_AUTH_Load & REQ_AUTH_Unload====================
//*************************************************************************************
int REQ_AUTH_Load(const char *filepath )
{
    int ret;
    //g_sla_ptr = this;
     if( g_sMetaComm.sAuthOption.t_AuthHandle== NULL)
    {
        goto Error;
	}
    ret = AUTH_Load( g_sMetaComm.sAuthOption.t_AuthHandle, filepath );
    if( ret != 0 )
    {
        goto Error;    
    }    
    return 0;
Error:
    return -1;    
}
//--------------------------------------------------------------------------
int REQ_AUTH_Unload( void )
{
    int ret; 
    if( g_sMetaComm.sAuthOption.t_AuthHandle == NULL)
    {
        goto Error;
	}
    ret = AUTH_Unload( g_sMetaComm.sAuthOption.t_AuthHandle );
    if( ret != 0 )
    {
        goto Error;    
    }    
    return 0;
Error:
    return -1;
}
//*****************************************************************************
//===========================================================================
//*****************************************************************************
/*int Get_ConfirmState( void )
{
    return SLA_Obj.m_iConfirmState;
}			 
*/

//--------------------------------------------------------------------------
AUTH_HANDLE_T Get_AuthHandle( void )
{   
    return g_sMetaComm.sAuthOption.t_AuthHandle;
}						  
#if 0
#endif
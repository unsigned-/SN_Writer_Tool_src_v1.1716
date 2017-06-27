/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	   USBSwitchDLLibrary.h
 *
 * Project:
 * --------
 *    Data Card Project
 *
 * Description:
 * ------------
 *    A Wrapping Class to wrap an Utility Tool to create/terminate process of USB Switch Tool
 *
 * Author:
 * -------
 *	  Juihung (Ray) Weng
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

// USBSwitchLibrary.h : Defines the entry point for the console application.
//
void * hprocess;
#ifndef _USB_SWITCH_DLLIBRARY_H_
#define _USB_SWITCH_DLLIBRARY_H_

#ifdef WIN32
#ifdef BUILD_MODEL
	#define MODELEXPORT __declspec( dllexport )
#else
	#define MODELEXPORT __declspec( dllimport )
#endif
#else
	#define MODELEXPORT
#endif



#ifdef	__cplusplus
extern "C" {
#endif


__declspec( dllimport ) void * __stdcall EnableUSBSwitch(const char* command);
__declspec( dllimport ) void   __stdcall DisableUSBSwitch(void * handle);


#ifdef	__cplusplus
}
#endif


#endif

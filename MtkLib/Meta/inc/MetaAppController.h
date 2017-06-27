// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the METAAPPCONTROLLER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// METAAPPCONTROLLER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef __META_APP_CONTROLLER_H__
#define __META_APP_CONTROLLER_H__
#include <METAAPP.h>
#ifdef METAAPPCONTROLLER_EXPORTS
#define METAAPPCONTROLLER_API extern "C" __declspec(dllexport)
#else
#define METAAPPCONTROLLER_API extern "C" __declspec(dllimport)
#endif
#define METAAPP_CONTROLLER_CALL_CONVENTION   __stdcall

METAAPPCONTROLLER_API METAAPP_RESULT METAAPP_CONTROLLER_CALL_CONVENTION METAAPP_CompressFolder( const char* outputArchiveName, const char* intputFolderName );
METAAPPCONTROLLER_API METAAPP_RESULT METAAPP_CONTROLLER_CALL_CONVENTION METAAPP_PurgeEntriesInFolder( const char* path, unsigned int days );
METAAPPCONTROLLER_API METAAPP_RESULT METAAPP_CONTROLLER_CALL_CONVENTION METAAPP_CopyPath( const char* to, const char* from );
METAAPPCONTROLLER_API METAAPP_RESULT METAAPP_CONTROLLER_CALL_CONVENTION METAAPP_RecursiveRemove( const char* path );
METAAPPCONTROLLER_API METAAPP_RESULT METAAPP_CONTROLLER_CALL_CONVENTION METAAPP_RecursiveCreateFolder( const char* path );
#endif // #ifndef __META_APP_CONTROLLER_H__
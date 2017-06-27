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
* Mdebug.h
*
* Project:
* --------
*   META
*
* Description:
* ------------
*   Debug log module for META project. 
*
* Author:
* -------
*  Amos Hsu (mtk00539)
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Revision:   1.9  $
* $Modtime:   Jan 12 2006 15:51:06  $
* $Log:   //mtkvs01/vmdata/meta_dll/archives/maui/META_DLL/Mdebug.h-arc  $
 *
 * Feb 26 2006 mtk00539
 * [STP100000625] FlashTool v2.7.1016
 * 
 * 
 *    Rev 1.9   Jan 14 2006 00:29:52   mtk00539
 * Enhancements:
 *  1. [BROM_DLL] Dump debug log in BootROM write cmd.
 * Resolution for 159: [FlashTool v2.7.1015]
 * 
 *    Rev 1.8   Oct 21 2003 17:08:48   mtk00539
 * add debug prefix 
 * Resolution for 32: [META_DLL v3.3.1001][New] See the details below.
 * 
 *    Rev 1.7   Oct 18 2003 13:57:06   mtk00539
 * Add debug level
 * Resolution for 31: [BootRom v2.1.1002][BUG FIX] Fix DA checksum error on Windows ME and 2000.
 * 
 *    Rev 1.6   Sep 02 2003 14:39:24   mtk00539
 * 1. Fix m_bSystemTrace bug in operator ()
 * 2. Modify MTRACE_ComposeDumpBuf() interface from unsigned char * to char *
 * Resolution for 26: [META_DLL v3.1.1001][Add Feature] See the reasons below.
 * 
 *    Rev 1.5   Aug 06 2003 22:16:52   mtk00539
 * 1. add new class MetaTrace_Handle_Sentry and MetaTrace_Log_Sentry.
 * 2. add new api MTRACE_IsDumpFileOpen().
 * Resolution for 24: [BootRom v2.0.1008][Add Features] Support MT6218 Cannon, Enhance debug log.
 * 
 *    Rev 1.4   Jul 25 2003 15:50:28   mtk00539
 * Reason:
 * 1. SA reports read(10sec)/write(3sec) timeouts are too long. Because DA_cmd::WriteData() and DA_cmd::ReadData() will re-try one time, so the actual timeouts are read(10x2sec)/write(3x2sec). So I decide to reduce timeouts to read(5sec)/write(1.5sec).
 * 
 * 2. Add specific debug log at the end of FlashDownload(), FlashReadback() and FlashFormat(). In this way SA can query whether if the function successfully executed by this signature.
 * 
 * 3. Export debug log clear function, let users clear debug log whenever they want.
 * Resolution for 17: [BootRom v2.0.1006][Add Features] shorten read/write timeout and export debug log clear function.
 * 
 *    Rev 1.3   Jun 30 2003 20:39:02   mtk00539
 * enable runtime trace
 * Resolution for 12: [BootRom v2.2.1001][New Version] Split flashtool function into brom.dll
 * 
 *    Rev 1.2   Jun 30 2003 19:46:08   mtk00539
 * Add include <stdio.h>
 * Resolution for 12: [BootRom v2.2.1001][New Version] Split flashtool function into brom.dll
 * 
 *    Rev 1.1   Apr 01 2003 09:39:46   mtk00539
 * 1. enlarge buffer
 * 2. fix BUG: _snprintf() buffer length count error.
 * 3. display both HEX and ASCII value in MTRACE_ComposeDumpBuf()
 * 4. remove MTRACE_DumpFileRedirect() and MTRACE_DumpFileGetFP().
 * 5. add MTRACE_DumpToStdio()
 * 6. add CRITICAL_SECTION to protect buffer and handle.
 * Resolution for 3: [META_DLL v2.0][AddFeature] Add new features for META_DLL v2.0
 * 
 *    Rev 1.0   Feb 25 2003 13:24:20   admin
 * Initial revision.
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#ifndef	_META_TRACE_H_
#define	_META_TRACE_H_
#include <stdio.h>
#define MDEBUG_RUNTIME_TRACE 1

//--------------------------------------------------------------------------//
//  The definition of MetaTrace data structure                              //
//--------------------------------------------------------------------------//
struct MetaTraceHandle;
typedef struct MetaTraceHandle *	hMTRACE;
typedef const struct MetaTraceHandle *	hMTRACE_const;

//--------------------------------------------------------------------------//
//  The definition of trace level                                           //
//--------------------------------------------------------------------------//
#define MTRACE_LEVEL_LOG_0		0
#define MTRACE_LEVEL_LOG_1		1
#define MTRACE_LEVEL_LOG_2		2
#define MTRACE_LEVEL_SYSTEM		200
#define MTRACE_LEVEL_WARNING	210
#define MTRACE_LEVEL_TOP		255
#define MTRACE_LEVEL_ERROR		MTRACE_LEVEL_TOP
#define LIBEXPORT __declspec(dllexport)

//--------------------------------------------------------------------------//
//  MetaTrace class                                                         //
//--------------------------------------------------------------------------//
class LIBEXPORT MetaTrace
{
private:
	const char *m_file;
	int m_line;
	unsigned char m_level;
	const char *m_prefix;

public:
	explicit MetaTrace( const char* file, int line, unsigned char level=MTRACE_LEVEL_LOG_0, const char *prefix="");
	virtual ~MetaTrace();

	void operator()( hMTRACE  handle, const char* Format, ... );
};
//--------------------------------------------------------------------------//
//  MetaTrace handle create/destroy sentry class                            //
//--------------------------------------------------------------------------//
class LIBEXPORT MetaTrace_Handle_Sentry {
public:
	explicit MetaTrace_Handle_Sentry(hMTRACE  &debug_handle, const char *ProcessName, bool bSystemTrace, bool bTraceEnable, unsigned char level=MTRACE_LEVEL_LOG_0, const char *DumpFile=NULL, const char *Mode="w");
	~MetaTrace_Handle_Sentry();

private:
	hMTRACE		&m_debug;
};

//--------------------------------------------------------------------------//
//  MetaTrace log sentry class                                              //
//--------------------------------------------------------------------------//
class LIBEXPORT MetaTrace_Log_Sentry {

public:
	explicit MetaTrace_Log_Sentry(hMTRACE  &debug_handle, const char *begin_hint=NULL, const char *end_hint=NULL);
	~MetaTrace_Log_Sentry();

private:
	char	m_begin_hint[256];
	char	m_end_hint[256];
	hMTRACE		&m_debug;
};

#ifdef	__cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------------//
//  Meta Trace API                                                          //
//--------------------------------------------------------------------------//


LIBEXPORT extern hMTRACE MTRACE_Create(const char *ProcessName, bool bSystemTrace, bool bTraceEnable, unsigned char level);
LIBEXPORT extern int MTRACE_Destroy(hMTRACE *p_handle);
LIBEXPORT extern int MTRACE_ON(hMTRACE handle);
LIBEXPORT extern int MTRACE_OFF(hMTRACE handle);
LIBEXPORT extern bool MTRACE_IsTraceEnabled(hMTRACE handle);
LIBEXPORT extern int MTRACE_SetSysTrace(hMTRACE handle, bool bEnable);
LIBEXPORT extern int MTRACE_SetLevel(hMTRACE handle, unsigned char level);
LIBEXPORT extern int MTRACE_GetLevel(hMTRACE handle, unsigned char *p_level);
LIBEXPORT extern bool MTRACE_IsDumpFileOpen(hMTRACE handle);
LIBEXPORT extern int MTRACE_DumpToStdio(hMTRACE handle, FILE *std_io);
LIBEXPORT extern int MTRACE_DumpFileOpen(hMTRACE handle, const char *DumpFile, const char *mode);
LIBEXPORT extern int MTRACE_DumpFileClose(hMTRACE handle);
LIBEXPORT extern int MTRACE_DumpFileClear(hMTRACE handle);
LIBEXPORT extern char *MTRACE_ComposeDumpBuf(const char *buf_in, unsigned long buf_in_len);
//-----------------------------------------------------//
//  Meta Trace API: MTRACE macro                       //
//-----------------------------------------------------//
#if defined(_DEBUG) || defined(MDEBUG_RUNTIME_TRACE)
	#define MTRACE				(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_LOG_0 ))
	#define MTRACE_SYS			(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_SYSTEM, " SYSTEM:" ))
	#define MTRACE_WARN		(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_WARNING, " WARNING:" ))
	#define MTRACE_ERR			(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_ERROR, " ERROR:" ))
	#define MTRACE_LVL(level)	(MetaTrace( __FILE__, __LINE__, level ))
#else
    extern __inline void MTRACE_Empty( hMTRACE handle, const char* Format, ... ); // dummy trace function
	#define MTRACE				(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_LOG_0 ))
	#define MTRACE_SYS			(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_SYSTEM, " SYSTEM:" ))
	#define MTRACE_WARN		(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_WARNING, " WARNING:" ))
	#define MTRACE_ERR			(MetaTrace( __FILE__, __LINE__, MTRACE_LEVEL_ERROR, " ERROR:" ))
	#define MTRACE_LVL(level)	(MetaTrace( __FILE__, __LINE__, level ))
#endif

//-----------------------------------------------------//
//  Meta Trace API: general functions                  //
//-----------------------------------------------------//
int __stdcall Eboot_GetDLLVer(unsigned int *major_ver, unsigned int *minor_ver, unsigned int *build_num, unsigned int *patch_num );
#ifdef	__cplusplus
}
#endif

#endif

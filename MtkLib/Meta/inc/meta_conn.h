#ifndef __META_CONN_H__
#define __META_CONN_H__

#include <string>
#include "meta.h"
#include "export.h"
#include "sp_md_info.h"
#include "message_box.h"

typedef struct _METACONN_RESULT
{
    void* output_para;
    int handle;
} METACONN_RESULT;

typedef struct _METACONN_MD_INFO
{
    unsigned int m_iSpNumberOfMd; //how many modems in the target
    unsigned int m_iSpActiveMd;   //the index of modem which is actived so far
    unsigned int m_iSpAllMdChannelIndex[MAX_MD_NUM]; //Modem index of each modem
    unsigned int m_iSpNumberOfMdType[MAX_MD_NUM]; //The number of images of each modem
    unsigned int m_iSpActiveMdType[MAX_MD_NUM]; //The active image of each modem
    unsigned int m_iSpAllMdSwImg[MAX_MD_NUM][MAX_MD_SW_NUM]; //Images of each modem queried from SP meta dll
    unsigned int m_iSpNumberOfMdSwImg; //how many modem images in the target
    SP_MODEM_CAPABILITY_LIST_CNF m_SpMdCapList; //
    bool m_bSpMultiMdCapabilitySupport;
    bool m_bSpMultiMdSupport;
    bool m_bSpMultiMdTypeSupport;
    bool m_bSpEncryptSupport;
    bool m_bExternalModemDownloadSupport;
} METACONN_MD_INFO;

extern "C"
{
    // TODO: comments (doxygen style)
    META_RESULT METACONNAPI MetaConn_IsBackupSupported(int handle);
    META_RESULT METACONNAPI MetaConn_Backup(int handle);
    META_RESULT METACONNAPI MetaConn_Connect(const char*, void* para, METACONN_RESULT* output_para);
    META_RESULT METACONNAPI MetaConn_Disconnect(int handle, void* para);
    META_RESULT METACONNAPI MetaConn_SwitchModem(int handle, unsigned int md_idx);
    META_RESULT METACONNAPI MetaConn_SwitchModemType(int handle, unsigned int md_idx, unsigned int mdtype_idx);

    META_RESULT METACONNAPI MetaConn_DebugOff(void);
    META_RESULT METACONNAPI MetaConn_SetDebugLevel(int traceLevel);
    META_RESULT METACONNAPI MetaConn_SetLogPath(const char* path);
    META_RESULT METACONNAPI MetaConn_SetMsgBoxFunc(MsgBoxFunc cb);
    META_RESULT METACONNAPI MetaConn_SetAppExeName(const char* name);
    META_RESULT METACONNAPI MetaConn_SetCfgFileName(const char* name);

    META_RESULT METACONNAPI MetaConn_GetMdMultiSup(int handle, bool* ret);
    META_RESULT METACONNAPI MetaConn_GetMdInfo(int handle, METACONN_MD_INFO* md_info);
    META_RESULT METACONNAPI MetaConn_GetMdChIdx(int handle, int order_md, unsigned int* ch_idx);
    META_RESULT METACONNAPI MetaConn_GetMdActiveIdx(int handle, unsigned int* md_idx);
    META_RESULT METACONNAPI MetaConn_GetMdMultiMdTypeSup(int handle, bool* sup);
    META_RESULT METACONNAPI MetaConn_GetMdNum(int handle, unsigned int* num_of_md);
    META_RESULT METACONNAPI MetaConn_GetMdActiveMdTypeIdx(int handle, unsigned int* mdtype_idx);
    META_RESULT METACONNAPI MetaConn_GetMdActiveMdTypeIdxByMdIdx(int handle, unsigned int md_idx, unsigned int* mdtype_idx);
    META_RESULT METACONNAPI MetaConn_GetMdNumMdType(int handle, unsigned int md_idx, unsigned int* num_mdtype);
    META_RESULT METACONNAPI MetaConn_GetAllMdTypeNum(int handle, unsigned int* num_mdtype);
    META_RESULT METACONNAPI MetaConn_GetMdActiveMdTypeName(int handle, const char** name);
    META_RESULT METACONNAPI MetaConn_GetEncryptSup(int handle, bool* sup);
    META_RESULT METACONNAPI MetaConn_GetExtMdDltSup(int handle, bool* sup);
    META_RESULT METACONNAPI MetaConn_GetMdSrv(int handle, unsigned int md_idx, unsigned int* srv);
    META_RESULT METACONNAPI MetaConn_GetMdChType(int handle, unsigned int md_idx, unsigned int* ch_type);
    META_RESULT METACONNAPI MetaConn_GetIsC2kLink(int handle, bool* ret);
    META_RESULT METACONNAPI MetaConn_GetIsSupMultiMdCap(int handle, bool* ret);
	META_RESULT METACONNAPI MetaConn_isSupportedGetTargetNvDatabaseFile(int handle, bool* isSupported);
	META_RESULT METACONNAPI MetaConn_GetTargetNvDatabaseFile(int handle, char* file_name, bool* isGetFile);
	META_RESULT METACONNAPI MetaConn_RebootTargetToNormalMode(int handle, void* para, bool* ret);
	META_RESULT METACONNAPI MetaConn_SetMdExceptionStopFlag(int handle, int flagValue);
	META_RESULT METACONNAPI MetaConn_GetModemMemorydumpFile(int handle, char* db_file_name, char* bin_file_name, bool* isDumpFileFinish);
	META_RESULT METACONNAPI MetaConn_isSupportedGControlMDLogger(int handle, bool* isSupported);
	META_RESULT METACONNAPI MetaConn_ControlMDLogger(int handle, unsigned int loggingType, unsigned int loggingAction);

}



#endif

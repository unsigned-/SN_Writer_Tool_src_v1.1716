#ifndef __SP_MD_INFO__
#define __SP_MD_INFO__

#include "SP_META_Wrapper.h"

#define MAX_MD_NUM 8
#define MAX_MD_SW_NUM 16

class MdInfo
{
    private:
        unsigned int m_iSpNumberOfMd; //how many modems in the target
        unsigned int m_iSpActiveMd;   //the index of modem which is actived so far
        unsigned int m_iSpAllMdChannelIndex[MAX_MD_NUM]; //Modem index of each modem
        unsigned int m_iSpNumberOfMdType[MAX_MD_NUM]; //The number of images of each modem
        unsigned int m_iSpActiveMdTypeIdx[MAX_MD_NUM]; //The active image of each modem
        unsigned int m_iSpAllMdSwImg[MAX_MD_NUM][MAX_MD_SW_NUM]; //Images of each modem queried from SP meta dll
        unsigned int m_iSpNumberOfMdSwImg; //how many modem images in the target
        SP_MODEM_CAPABILITY_LIST_CNF m_SpMdCapList; //
        bool m_bSpMultiMdCapabilitySupport;
        bool m_bSpMultiMdSupport;
        bool m_bSpMultiMdTypeSupport;
        bool m_bSpEncryptSupport;
        bool m_bExtenalModemDownloadSupport;

    public:
        MdInfo();
        unsigned int GetSpNumberOfMd(void) const;
        unsigned int GetSpMdChannelIdx(unsigned int idx) const;
        unsigned int GetSpNumberOfMdSwImg(void) const;
        unsigned int GetSpActiveMdIdx(void) const;
        unsigned int GetSpMdSrvType(unsigned int md_idx) const;
        unsigned int GetSpMdChannelType(unsigned int md_idx) const;
        unsigned int GetSpNumberOfMdTypeByMdIdx(unsigned int md_idx) const;
        unsigned int GetSpActiveMdTypeIdxByMdIdx(unsigned int md_idx) const;
        bool GetSpEncryptSupport(void) const;
        bool GetExternalModemDownloadSupport(void) const;
        bool GetSpMultiMdCapabilitySupport(void) const;
        bool GetSpMultiMdSupport(void) const;
        bool GetSpMultiMdTypeSupport(void) const;
        unsigned int GetSpActiveMdType(void) const;
        unsigned int GetMdType(unsigned int md_idx, unsigned int mdtype_idx) const;


        void SetSpNumberOfMd(unsigned int md_num);
        void SetSpActiveMdIdx(unsigned int md_num);
        void SetSpMdChannelIdx(unsigned int idx, unsigned int val);
        void SetMdCapList(SP_MODEM_CAPABILITY_LIST_CNF* cap);
        void SetSpMultiMdCapabilitySupport(bool sup);
        void SetSpMultiMdSupport(bool support);
        void SetSpMultiMdTypeSupport(bool sup);
        void SetSpNumberOfMdSwImg(unsigned int val);
        void SetSpMdSrvType(unsigned int md_idx, unsigned int service_type);
        void SetSpMdChannelType(unsigned int md_idx, unsigned int channel_type);
        void SetSpNumberOfMdTypeByMdIdx(unsigned int md_idx, unsigned int num);
        void SetSpActiveMdTypeIdxByMdIdx(unsigned int md_idx, unsigned int mdtype_idx);
        void SetAllMdSwImg(void* swimg);
        void SetSpEncryptSupport(bool);
        void SetExternalModemDownloadSupport(bool sup);
        void PrintMdCapList();
};


#endif // #ifndef __SP_MD_INFO__

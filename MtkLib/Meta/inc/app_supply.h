#ifndef __APP_SUPPLY__
#define __APP_SUPPLY__

#include <string>
#include "message_box.h"

typedef std::string AnsiString;

class  CAppSupply
{
    private:
        CAppSupply() {};
        static MsgBoxFunc m_MessageToAppFunction;
        static AnsiString m_AppExeName;
        static AnsiString m_ConfigureFileName;
    public:
        static CAppSupply* GetInstance();
        static void SetMsgBoxFunc(MsgBoxFunc func);
        static int DisplayMsgBox(const char* msg, const char* title, int code);
        static void SetAppExeName(const char* name);
        static void SetConfigFileName(const char* name);
        static AnsiString GetAppExeName();
        static AnsiString GetConfigFileName();
};

#define APP_EXE_NAME ((CAppSupply::GetInstance())->GetAppExeName().c_str())
#define CFG_FILE_NAME ((CAppSupply::GetInstance())->GetConfigFileName().c_str())

#endif // #ifndef __APP_SUPPLY__
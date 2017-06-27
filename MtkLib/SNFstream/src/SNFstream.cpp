#ifdef __cplusplus
#define DLL_API extern "C" _declspec(dllexport)
#else
#define DLL_API _declspec(dllexport)
#endif

#include <iostream>   
#include <fstream>   
#include <string> 
#include <windows.h>  
#include "SNFstream.h"
using namespace std;

string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
    
	int pos = s.find_first_not_of(" ");
    if (pos != -1)
    {
        s.erase(0, pos); 
    }
     
    pos = s.find_last_not_of(" ") + 1;
    if (pos != -1)
    {
        s.erase(pos);
    }
    return s;
}

RW_SetupFile_Status ReadIniItemData(const char* pFilePath, IniData_struct iniData)
{
    if(!pFilePath)
       return INVALID_PARAMETER;

    
    ifstream readStream;
    readStream.open(pFilePath);//以读方式打
    if(!readStream.is_open())//判断是否打开   
    {  
        return OPEN_FILE_FAIL; 
    }

    char tmpBuf[1024] = {0};
    char fileLineBuf[1024] = {0};
    string fileLine;
    string subStr;
    string fieldKeyword; 
    int subIndex = 0;

    fieldKeyword = iniData.pItemKeyWord;
    trim(fieldKeyword);
    while(!readStream.eof())  
    {  
        readStream.getline(fileLineBuf,1024); //读入打开文件的每一行
        if (fileLineBuf[0] == '\0' || fileLineBuf[0] == '\n')
        {
            continue;
        }
       
        fileLine = fileLineBuf;    //将读取文件的文件内容存到字符串中
        subIndex = fileLine.find("=");	
        subStr = fileLine.substr(0,subIndex);
        trim(subStr);	
        
        if(stricmp(subStr.c_str(), fieldKeyword.c_str()) == 0)
        {
            int length = strlen(fileLineBuf);
            subStr = fileLine.substr(subIndex+1,length);
            trim(subStr);
            strncpy(tmpBuf, subStr.c_str(), strlen(subStr.c_str())+1);
            
            switch (iniData.dataType)
            {
            case INI_BOOLEAN:
                
                if (stricmp(tmpBuf, "true") == 0)
                {
                    *((bool*)iniData.pItemData) = true;
                }
                else
                {
                    *((bool*)iniData.pItemData) = false;
                }
                cout << *((bool*)iniData.pItemData) << endl;
                break;
                
            case INI_INTEGER:
                
                *((int*)iniData.pItemData) = atoi(tmpBuf);
                cout << *((int*)iniData.pItemData) << endl;               
                break;
                
            case INI_STRING:
                
                strncpy(((char*)iniData.pItemData), tmpBuf, strlen(tmpBuf)+1);
                cout << ((char*)iniData.pItemData) << endl;
                break;
            }

            break;
        }
    }

    return INI_RW_SUCCESS;
}

RW_SetupFile_Status WriteIniItemData(const char* pFilePath, IniData_struct iniData)                                            
{
    if(!pFilePath)
       return INVALID_PARAMETER;

    LPCTSTR lpSectionName = "System Setup";
    LPCTSTR lpKeyName = iniData.pItemKeyWord; 
    BOOL bWriteSuccess = FALSE;

    char tmpBuf[1024] = {0};
    char lpValue[1024] = {0};

    switch (iniData.dataType)
    {
    case INI_BOOLEAN:
        
        if (*((bool*)iniData.pItemData) == true)
        {
            sprintf(lpValue, " %s", "True");
        }
        else
        {
            sprintf(lpValue, " %s", "False");
        }
        break;
        
    case INI_INTEGER:
  
        itoa((*((int*)iniData.pItemData)), tmpBuf, 10);
        sprintf(lpValue, " %s", tmpBuf);       
        break;
        
    case INI_STRING:

        sprintf(lpValue, " %s", ((char*)iniData.pItemData));
        break;
    }

    bWriteSuccess = WritePrivateProfileString(lpSectionName, lpKeyName, lpValue, pFilePath);
    if (bWriteSuccess == TRUE)
    {
        return INI_RW_SUCCESS;
    }
    else
    {
        return INI_RW_ERROR;
    }
}

RW_SetupFile_Status ReadIniData(const char* pFilePath, IniData_struct IniData[], int IniData_size)
{
    
    if(!pFilePath || !IniData || !IniData_size)
       return INVALID_PARAMETER;
        
    char tmpBuf[1024] = {0};
    char fileLineBuf[1024] = {0};
    ifstream readStream;
    readStream.open(pFilePath);//以读方式打
    if(!readStream.is_open())//判断是否打开   
    {  
        return OPEN_FILE_FAIL; 
    }

    string fileLine;
    string subStr;
    string fieldKeyword; 
    int subIndex = 0;
    bool bFindKeyWord = false;
    bool bResetToBegFlag = false;
    int  retryTime = 0; //每一行的都有一次从头开始找的retry机会

    int i = 0;
    for (i = 0; i < IniData_size; i++)
    {
        if (bResetToBegFlag)
        {
            readStream.seekg(0,ios::beg); //定位到文件开头
            retryTime = 1;
            bResetToBegFlag = false;
        }
        
        bFindKeyWord = false;
        cout << i << ": " << IniData[i].pItemKeyWord << " = ";

        while(!readStream.eof())  
        {  
            readStream.getline(fileLineBuf,1024); //读入打开文件的每一行
            if (fileLineBuf[0] == '\0' || fileLineBuf[0] == '\n')
            {
                continue;
            }
            
            fieldKeyword = IniData[i].pItemKeyWord;
            fileLine = fileLineBuf;    //将读取文件的文件内容存到字符串中
            subIndex = fileLine.find("=");	
            subStr = fileLine.substr(0,subIndex);
            trim(subStr);	
            trim(fieldKeyword);
            
            if(stricmp(subStr.c_str(), fieldKeyword.c_str()) == 0)
            {
                int length = strlen(fileLineBuf);
                subStr = fileLine.substr(subIndex+1,length);
                trim(subStr);
                strncpy(tmpBuf, subStr.c_str(), strlen(subStr.c_str())+1);
                
                switch (IniData[i].dataType)
                {
                case INI_BOOLEAN:
                    
                    if (stricmp(tmpBuf, "true") == 0)
                    {
                        *((bool*)IniData[i].pItemData) = true;
                    }
                    else
                    {
                        *((bool*)IniData[i].pItemData) = false;
                    }
                    cout << *((bool*)IniData[i].pItemData) << endl;
                    break;
                    
                case INI_INTEGER:
                    
                    *((int*)IniData[i].pItemData) = atoi(tmpBuf);
                    cout << *((int*)IniData[i].pItemData) << endl;               
                    break;
                    
                case INI_STRING:
                    
                    strncpy(((char*)IniData[i].pItemData), tmpBuf, strlen(tmpBuf)+1);
                    cout << ((char*)IniData[i].pItemData) << endl;
                    break;
                }

                bFindKeyWord = true;
                retryTime = 0;
                break;
            }
        }

        if (bFindKeyWord == false)
        {
            bResetToBegFlag = true;
            if (retryTime == 0)
            {
                i -= 1;  //关建行不变，重新再找一次
            }
            cout << "Can't find this keyline" << endl;
            readStream.clear();  //重新定位到文件开头前必须先clear
        }
    }
    
    return INI_RW_SUCCESS;

}

RW_SetupFile_Status WriteIniData(const char* pFilePath, IniData_struct IniData[], int IniData_size)
{
    
    if(!pFilePath || !IniData || !IniData_size)
        return INVALID_PARAMETER;
    
    ofstream writeStream;
    writeStream.open(pFilePath);//以读方式打
    if(!writeStream.is_open())//判断是否打开   
    {  
        return OPEN_FILE_FAIL; 
    }
    
    string strFile;
    char tmpBuf[1024] = {0};
    char tmpLineBuf[1024] = {0};

    sprintf(tmpLineBuf, "%s", "[System Setup]");
    strFile.append(tmpLineBuf); //新增
    strFile.append("\n");       //追加换行符
    for (int i = 0; i < IniData_size; i++)
    {
        switch (IniData[i].dataType)
        {
        case INI_BOOLEAN:
            
            if (*((bool*)IniData[i].pItemData) == true)
            {
                cout << *((bool*)IniData[i].pItemData) << endl;
                sprintf(tmpLineBuf, "%s = %s", IniData[i].pItemKeyWord, "True");
            }
            else
            {
                cout << *((bool*)IniData[i].pItemData) << endl;
                sprintf(tmpLineBuf, "%s = %s", IniData[i].pItemKeyWord, "False");
            }
            break;
            
        case INI_INTEGER:
            
            cout << *((int*)IniData[i].pItemData) << endl;   
            itoa((*((int*)IniData[i].pItemData)), tmpBuf, 10);
            sprintf(tmpLineBuf, "%s = %s", IniData[i].pItemKeyWord, tmpBuf);
            
            break;
            
        case INI_STRING:
                       
            cout << ((char*)IniData[i].pItemData) << endl;
            sprintf(tmpLineBuf, "%s = %s", IniData[i].pItemKeyWord, ((char*)IniData[i].pItemData));
            break;
        }
        
        strFile.append(tmpLineBuf); //新增加一行
        strFile.append("\n");       //追加换行符
    }
    
    writeStream<<strFile;//重新ini文件
    writeStream.close();
    return INI_RW_SUCCESS;
    
}
 



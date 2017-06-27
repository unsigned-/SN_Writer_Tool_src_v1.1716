// METARESULT_GEN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <WINDOWS.H>

using namespace std;

std::string& trim(std::string &s)
{  
    if (s.empty())   
    {  
        return s;  
    }  

    int pos = s.find_first_not_of(" ");
    if (pos != -1)
    {
        s.erase(0,pos); 
    }
     
    pos = s.find_first_of(" ");
    if (pos != -1)
    {
        s.erase(pos, s.length());
    }
      
    return s;  
}  


int main(int argc, char* argv[])
{
    char folderPath[] = ".\\";
    char filePath[260] = {0};
    HANDLE          hFind;
    WIN32_FIND_DATA FindFileData;
    
    // prescan
    //sprintf(find_path, "%s*Pass*.txt", m_log_folder);
    sprintf(filePath, "%s*.h", folderPath);
    hFind   = FindFirstFile(filePath, &FindFileData);
    if( hFind != INVALID_HANDLE_VALUE )
    {
        cout << FindFileData.cFileName << endl;
    }
    else
    {
        cout << "Can`t find .h file" << endl;
        return 0;
    }
    FindClose(hFind);


    string filename(FindFileData.cFileName);  // 输入文件
    char *pStartKeyword = "META_SUCCESS";
    char *pEndKeyword = "META_LAST_RESULT";
    
    ifstream in(filename.c_str());
    if (in) 
    {
        ostringstream os;   // 加载文件到sstream流
        os << in.rdbuf();
        string content(os.str()); // sstream流 转换成 字符串类
        
        // 查找关键字,第一次出现的位置, 在文件的第 X 行
        string::size_type pos_start = content.find(pStartKeyword);
        string::size_type pos_end = content.find(pEndKeyword);
        string::size_type rtLength = 0;

        string strResult = content.substr(pos_start, pos_end - pos_start + strlen(pEndKeyword));
        rtLength = strResult.length();        
        //cout << strResult << endl;
        //cout << "rtLength = " << rtLength << endl;
        std::string::iterator it = strResult.begin();  // 指向字符串开始的迭代器
        pos_start = 0;
        pos_end = strResult.find(pEndKeyword);
        int rtCount = count(it, it + pos_end, ',') + 1;  // 计算MetaResult个数
        cout << "Meta result Count = " << rtCount << endl;

        ofstream fileOut("Gen_MetaResult.txt");
        fileOut<<"#define M2S(x) #x" << endl;

        char strOut[1024] = {0};
        pos_end = strResult.find("\n");
        string::size_type curPos = pos_end+1;//remove '\n'

        if (strnicmp(FindFileData.cFileName, "meta.h", strlen("meta.h")) == 0)
        {
            string strTmp = strResult.substr(pos_start, pos_end - pos_start);
            sprintf(strOut, "case %s:\n\t return M2S(%s);\n\n", "META_SUCCESS", "META_SUCCESS");
            cout << strOut;
            fileOut<<strOut;

            for (int i = 0; i < rtCount - 1; i++)
            {
                strResult = strResult.substr(curPos, -1);
                pos_start = strResult.find(",");
                pos_end = strResult.find("\n");
                while (pos_end < pos_start)
                {
                    curPos = pos_end + 1;//remove '\n'
                    strResult = strResult.substr(curPos, -1);
                    pos_start = strResult.find(",");
                    pos_end = strResult.find("\n");
                }
                strTmp = strResult.substr(pos_start+1, pos_end-pos_start-1); 
                
                //去掉首尾空格
                strTmp = trim(strTmp);
                
                
                curPos = pos_end+1;
                sprintf(strOut, "case %s:\n\t return M2S(%s);\n\n", strTmp.c_str(), strTmp.c_str());
                fileOut<<strOut;
                cout << strOut;
            }
        }
        else if (strnicmp(FindFileData.cFileName, "spmeta.h", strlen("spmeta.h")) == 0)
        {
            string strSPMetadll = "SPMETA_DLL::";
            string strTmp = strResult.substr(pos_start, pos_end - pos_start);
            sprintf(strOut, "case %s:\n\t return M2S(%s);\n\n", "SPMETA_DLL::META_SUCCESS", "SPMETA_DLL::META_SUCCESS");
            cout << strOut;
            fileOut<<strOut;

            for (int i = 0; i < rtCount - 1; i++)
            {
                strResult = strResult.substr(curPos, -1);
                pos_start = strResult.find(",");
                pos_end = strResult.find("\n");
                while (pos_end < pos_start)
                {
                    curPos = pos_end + 1;//remove '\n'
                    strResult = strResult.substr(curPos, -1);
                    pos_start = strResult.find(",");
                    pos_end = strResult.find("\n");
                }
                strTmp = strResult.substr(pos_start+1, pos_end-pos_start-1); 
                
                //去掉首尾空格
                strTmp = trim(strTmp);
                
                
                curPos = pos_end+1;
                sprintf(strOut, "case SPMETA_DLL::%s:\n\t return M2S(SPMETA_DLL::%s);\n\n", strTmp.c_str(), strTmp.c_str());
                fileOut<<strOut;
                cout << strOut;
            }
        }
        
        
        fileOut.close();

        cout << "Gen meta result succss!!" << endl;
    } 
    else
    {
        cerr << "Open file error!" << endl;
        return -1;
    }
    return 0;
}


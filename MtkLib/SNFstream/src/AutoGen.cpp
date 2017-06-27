#define _AUTOGEN_API_EXPORT_
#include "AutoGen.h"

#include <stdlib.h>
#include <string.h>

char g_strMaxDenaryDigit[] = "2147483648";
char g_strMaxHexaDigit[] = "7FFFFFFF";

//FFFFFFF = 268435455
#define MAX_HEXA_VALUE 268435455
#define MAX_DENARY_VALUE 999999999

AUTOGEN_API AutoGenResult_e __stdcall strTolong(const char *nptr, long *value, int radix)
{
    if (!nptr)
    {
        return AutoGen_Invalid_Argument;
    }
    
    long tmpValue = 0;
    char *pTmp = NULL;
    tmpValue = strtol(nptr, &pTmp, radix);
    if (pTmp[0] == '\0')
    {
        *value = tmpValue;
        return AutoGen_Success;
    }
   
    return AutoGen_Fail;
}

AUTOGEN_API AutoGenResult_e __stdcall longTostr(long value,char *string, int radix)
{
    if (!string)
    {
        return AutoGen_Invalid_Argument;
    }
    
    char pTmp[1024] = {0};
    ltoa(value, pTmp, radix);
    if (strlen(pTmp))
    {
        strncpy(string, pTmp, strlen(pTmp)+1);
        return AutoGen_Success;
    }
    else
    {
        return AutoGen_Fail;
    }   
}

AUTOGEN_API AutoGenResult_e __stdcall AutoIncrease(AutoGenType_e eDataType, long step, char pOutData[], int bufSize)
{
    if (!pOutData)
    {
        return AutoGen_Invalid_Argument;
    }
    /*
    *   Because the max long int value is 2147483648(length = 10)(equal hexadecimal 7FFFFFFF(length = 8))
    *   The UI input data length exceed the max long int value data length,
    *   So input data will cut in two part: head and tail
    *   Denary(IMEI): the tail length is 9, head length is 6
    *   Hexadecimal(BT、Wifi): the tail length is 7, head length is 5
    *
    *   IMEI、BT、Wifi:
    *     -- pOutData: Consists of the head and tail string
    *     -- ex: IMEI = '1234123456789', head = '001234', tail = '123456789'
    *     -- ex: BT = 'ABCD1234567', head = '0ABCD', tail = '1234567'
    *
    *   Barcode:
    *     -- pOutData: if length <= 7, just consists of tail string
    *                if 7< length <= 14, Consists of the head and tail string
    *                if length > 14, Consists of the head 、mid、 tail string
    *     -- ex: Barcode = '12345', head='\0', mid='\0', tail = '12345'
    *     -- ex: Barcode = 'ABCDF123456', head='ABCD', mid='\0', tail = 'F123456'
    *     -- ex: Barcode = '12ABCD123F123456', head='12', mid='ABCD123', tail = 'F123456'
    */
  
    UINT dataLength = strlen(pOutData);  //Input data length

    char tmpOutStr[65] = {0};
    char *pOutStr = tmpOutStr;   
    strncpy(pOutStr, pOutData, dataLength);
   
    char strAhead[65] = {0};
    char strMid[65] = {0};
    char strTail[65] = {0};
    char *pAhead = strAhead;    
    char *pMid = strMid;    
    char *pTail = strTail;

    memset(pAhead, '0', 64);
    memset(pMid, '0', 64);
    memset(pTail, '0', 64);

    
    UINT refDataLgth = 0;    //IMEI Data length must be 15, BT/Wifi/Ethernet musth be 12
    UINT refBufSize = 0;     //Output data buffer length
    UINT refTailLgth = 0;    //Input data tail length
    UINT refAheadLgth = 0;   //Input data head length
    UINT refMidLgth = 0;     //Input data middle length, IMEI/BT/Wifi/Ethernet middle length alway is 0
    long refMaxValue = 0;    //Denary or Hexadecimal max value

	AutoGenResult_e GenResult = AutoGen_Success;
    long value = 0; 
    int  radix = 10;
    
    switch (eDataType)
    {
    case AutoGen_Barcode:
        radix = 16;
        refDataLgth = 64;
        refBufSize = 64;
        refMidLgth = 0;
        
        if (dataLength <= 7)
        {
            refTailLgth = dataLength;
            refMidLgth = 0;
            refAheadLgth = 0;
        }
        else if(7 < dataLength && dataLength <=14 )
        {
            refTailLgth = 7;
            refMidLgth = 0;
            refAheadLgth = dataLength - 7;
        }
        else if(dataLength > 14)
        {
            refTailLgth = 7;
            refMidLgth = 7;
            refAheadLgth = dataLength - (refTailLgth + refMidLgth);
        }
        
        refMaxValue = MAX_HEXA_VALUE;
        break;
        
    case AutoGen_IMEI:
        radix = 10;
        refDataLgth = 15;
        refBufSize = 16;
        
		refTailLgth = 9;
		refMidLgth = 0;		
		refAheadLgth = 6;
        
        refMaxValue = MAX_DENARY_VALUE;
        break;
        
    case AutoGen_BT:
    case AutoGen_Wifi:
    case AutoGen_Ethernet:
        radix = 16;
        refDataLgth = 12;
        refBufSize = 13;
        refTailLgth = 7;
		refMidLgth = 0;	
        refAheadLgth = 5;
        refMaxValue = MAX_HEXA_VALUE;
        break;

    case AutoGen_DRMKeyMCID:
        radix = 16;
        refDataLgth = 32;
        refBufSize = 33;
        refTailLgth = 7;
        refMidLgth = 7;
        refAheadLgth = dataLength - (refTailLgth + refMidLgth);
        refMaxValue = MAX_HEXA_VALUE;
        break;

    default:
        return AutoGen_Invalid_Argument;
    }

      
    int offset = 0;

    pAhead[refAheadLgth] = '\0'; 
    pMid[refMidLgth] = '\0';
    pTail[refTailLgth] = '\0';
      
    if (bufSize < refBufSize)
    {
        return AutoGen_Not_Enough_Buf;
    }

    if (dataLength <= 0 || dataLength > refDataLgth)
    {
    	//Input data length invalid
        GenResult = AutoGen_Invalid_Argument; 
    }       
    else if(dataLength > refTailLgth)
    {            
        //conduct tail string
        offset = dataLength - refTailLgth;
        strncpy(pTail, (pOutStr+offset), refTailLgth);
        pTail[refTailLgth] = '\0';  
        
        if (refMidLgth > 0) //IMEI/BT/Wifi/Ethernet: refMidLgth always 0
        {
        	//conduct middle string
            offset = dataLength - refTailLgth - refMidLgth;            
            strncpy(pMid, pOutStr+offset, refMidLgth);
            pMid[refMidLgth] = '\0';
            
            //conduct ahead string
            strncpy(pAhead, pOutStr, refAheadLgth);
            pAhead[refAheadLgth] = '\0';
        }
        else if(refMidLgth == 0)
        {
            //conduct ahead string
            if (eDataType == AutoGen_IMEI 
                || eDataType == AutoGen_BT 
                || eDataType == AutoGen_Wifi 
                || eDataType == AutoGen_Ethernet)
            {
                strncpy((pAhead+(refAheadLgth - offset)), pOutStr, offset);
                pAhead[refAheadLgth] = '\0';
            }  
            else if (eDataType == AutoGen_Barcode)
            {
                strncpy(pAhead, pOutStr, refAheadLgth);
                pAhead[refAheadLgth] = '\0';
            }
        }                    
    }
    else // data length less reference tail length
    {
        //This case will never be imei/bt/wifi/ethernet/drmkey mcid, because these datas length must 15/12/32
        //So this case just for barcode
        
        //conduct tail string
        offset = refTailLgth - dataLength;
       
        if (eDataType == AutoGen_IMEI 
            || eDataType == AutoGen_BT 
            || eDataType == AutoGen_Wifi 
            || eDataType == AutoGen_Ethernet
            || eDataType == AutoGen_DRMKeyMCID)
        {
            strncpy(pTail+offset, pOutStr, dataLength);
        }
        else if (eDataType == AutoGen_Barcode)
        {
            strncpy(pTail, pOutStr, dataLength);
        }
      
        pTail[refTailLgth] = '\0'; 
    }
    
    //get tail string value
    GenResult = strTolong(pTail, &value, radix);
    if (GenResult == AutoGen_Success)
    {        
        if ((value+step) > refMaxValue) //greater than max value, need to carry
        {
            char tmpCh = '0';
            long tmpVal = 0;          
            long mod = (value+step) - refMaxValue - 1;

            //conduct output tail string
            memset(pTail, '0', refTailLgth);
            switch(radix)
            {
            case 10:                    
                if (0 <= mod && mod <= 9)
                {
                    tmpCh = '0' + mod;
                }                   
                break;
                
            case 16:
                if (0 <= mod && mod <= 9)
                {
                    tmpCh = '0' + mod;
                }
                else if(9 <= mod && mod <= 15)
                {
                    tmpCh = 'A' + (mod - 10);
                }
                break;
            }
            pTail[refTailLgth-1] = tmpCh;
            pTail[refTailLgth] = '\0';   
            
            //conduct output head string
            if (eDataType == AutoGen_IMEI 
				|| eDataType == AutoGen_BT 
				|| eDataType == AutoGen_Wifi 
				|| eDataType == AutoGen_Ethernet)
            {
                GenResult = strTolong(pAhead, &tmpVal, radix);
                if (GenResult == AutoGen_Success)
                {
                    int  length = 0;
                    char pTmp[64] = {0};
                    char tmpCh = '0';
                    tmpVal += 1;
                    GenResult = longTostr(tmpVal, pTmp, radix);
                    if (GenResult == AutoGen_Success)
                    {    
                        length = strlen(pTmp);
                        strcpy(pAhead+(refAheadLgth - length), pTmp);
                    }                              
                }    
            }  
            else if(eDataType == AutoGen_Barcode || eDataType == AutoGen_DRMKeyMCID)
            {
                char pTmp[64] = {0};
                if (refMidLgth > 0)
                {                   
                    //need to conduct output middle string
                    GenResult = strTolong(pMid, &tmpVal, radix);
                    if (GenResult == AutoGen_Success)
                    {
                        int  length = 0;                        
                        char tmpCh = '0';
                        tmpVal += 1;
                        GenResult = longTostr(tmpVal, pTmp, radix);
                        if (GenResult == AutoGen_Success)
                        {    
                            if (tmpVal > refMaxValue)// mid value exceed 'FFFFFFF', need to carry
                            {
                                memset(pMid, '0', refMidLgth);
                                GenResult = strTolong(pAhead, &tmpVal, radix);
                                if (GenResult == AutoGen_Success)
                                {
                                    //conduct output head string
                                    tmpVal += 1;
                                    GenResult = longTostr(tmpVal, pTmp, radix);
                                    if (GenResult == AutoGen_Success)
                                    {    
                                        length = strlen(pTmp);
                                        strncpy(pAhead, pTmp, length);
                                        pAhead[length] = '\0';
                                    }
                                }
                            }//end if (tmpVal > refMaxValue)
                            else
                            {
                                strcpy(pMid, pTmp);
                                pMid[refMidLgth] = '\0';
                            }
                        }
                    }
                } //if (refMidLgth > 0)
                else
                {
                    //conduct output head string
                    GenResult = strTolong(pAhead, &tmpVal, radix);
                    if (GenResult == AutoGen_Success)
                    {
                        tmpVal += 1;
                        longTostr(tmpVal, pTmp, radix);
                        strncpy(pAhead, pTmp, strlen(pTmp)+1);
                    }
                }//end //if (refMidLgth > 0)
            }//end else if(eDataType == AutoGen_Barcode)
        }//end if ((value+step) > refMaxValue) //need to carry
        else
        {
            //don`t need to carry, so just need to re-conduct tail string
            char pTmp[64] = {0};
            int  length = 0;
            value += step;
            longTostr(value, pTail, radix);
            GenResult = longTostr(value, pTmp, radix);
            if (GenResult == AutoGen_Success)
            {    
                memset(pTail, '0', refTailLgth);
                length = strlen(pTmp);
                if (eDataType == AutoGen_IMEI 
					|| eDataType == AutoGen_BT 
					|| eDataType == AutoGen_Wifi 
					|| eDataType == AutoGen_Ethernet
					|| eDataType == AutoGen_DRMKeyMCID)
                {
                    strncpy(pTail+(refTailLgth - length), pTmp, length);
                }
                else if(eDataType == AutoGen_Barcode)
                {
                    strncpy(pTail, pTmp, length);
                }               
            }
        }
    }
    
    if (GenResult == AutoGen_Success)
    {       
        if (refMidLgth > 0)
        {
           // Need to strcat middle data string
            strncat(pAhead, pMid, refMidLgth);
        }
		
        strncat(pAhead, pTail, refTailLgth);
        strcpy(pOutData, pAhead);
    }

    return GenResult;
}

AUTOGEN_API AutoGenResult_e __stdcall AutoIncrease_Ex(AutoGenType_e eDataType, long step, char pOutData[], int bufSize, AutoGenOption_e eOption)
{
    if (!pOutData)
    {
        return AutoGen_Invalid_Argument;
    }
       
    if (eOption == AutoGen_WITHOUT_OPTION)
    {
        return AutoIncrease(eDataType, step, pOutData, bufSize);
    } 
    else
    {              
        AutoGenResult_e GenResult = AutoGen_Success;
        UINT dataLength = strlen(pOutData);
        char tmpOutStr[65] = {0};
        char *pOutStr = tmpOutStr;   
        strncpy(pOutStr, pOutData, dataLength);
        
        char strAhead[65] = {0};
        char strMid[65] = {0};
        char strTail[65] = {0};
        char *pAhead = strAhead;    
        char *pMid = strMid;    
        char *pTail = strTail;
        
        memset(pAhead, '0', 64);
        memset(pMid, '0', 64);
        memset(pTail, '0', 64);
        
        
        long value = 0; 
        int  radix = 10;
        UINT refDataLgth = 0;
        UINT refBufSize = 0;
        UINT refTailLgth = 0;
        UINT refAheadLgth = 0;
        UINT refMidLgth = 0;
        long refMaxValue = 0;
        
        switch (eDataType)
        {
        case AutoGen_Barcode:                       
        case AutoGen_BT:
        case AutoGen_Wifi:
		case AutoGen_Ethernet:
		case AutoGen_DRMKeyMCID:
            return AutoGen_Not_Support_Type;

        case AutoGen_IMEI:
            radix = 10;
            refDataLgth = 15;
            refBufSize = 16;
            if (eOption == AutoGen_IMEI_CHECKSUM_OPTION)
            {
                refTailLgth = 8;
                refMaxValue = 99999999;
            } 
            else
            {
                refTailLgth = 9;
                refMaxValue = MAX_DENARY_VALUE;
            }
            
            refAheadLgth = 6;
            
            break;
            
        default:
            return AutoGen_Invalid_Argument;
        }
        
        
        int offset = 0;
        
        pAhead[refAheadLgth] = '\0'; 
        pMid[refMidLgth] = '\0';
        pTail[refTailLgth] = '\0';
        
        if (bufSize < refBufSize)
        {
            return AutoGen_Not_Enough_Buf;
        }
        
        if (dataLength <= 0 || dataLength > refDataLgth)
        {
            GenResult = AutoGen_Invalid_Argument; 
        }       
        else if(dataLength > refTailLgth)
        {            
            offset = dataLength - refTailLgth;
            if (eOption == AutoGen_IMEI_CHECKSUM_OPTION)
            {
                offset -= 1;
            }
            
            //conduct tail string
            strncpy(pTail, (pOutStr+offset), refTailLgth);
            pTail[refTailLgth] = '\0';  
            
            if (refMidLgth > 0) //IMEI、BT、Wifi: refMidLgth always 0
            {
                offset = dataLength - refTailLgth - refMidLgth;
                
                //conduct middle string
                strncpy(pMid, pOutStr+offset, refMidLgth);
                pMid[refMidLgth] = '\0';
                
                //conduct ahead string
                strncpy(pAhead, pOutStr, refAheadLgth);
                pAhead[refAheadLgth] = '\0';
            }
            else if(refMidLgth == 0)
            {
                //conduct ahead string
                if (eDataType == AutoGen_IMEI || eDataType == AutoGen_BT || eDataType == AutoGen_Wifi)
                {
                    strncpy((pAhead+(refAheadLgth - offset)), pOutStr, offset);
                    pAhead[refAheadLgth] = '\0';
                }  
                else if (eDataType == AutoGen_Barcode)
                {
                    strncpy(pAhead, pOutStr, refAheadLgth);
                    pAhead[refAheadLgth] = '\0';
                }
            }                    
        }
        else // data length less reference tail length
        {
            offset = refTailLgth - dataLength;
            
            //conduct tail string
            if (eDataType == AutoGen_IMEI || eDataType == AutoGen_BT || eDataType == AutoGen_Wifi)
            {
                strncpy(pTail+offset, pOutStr, dataLength);
            }
            else if (eDataType == AutoGen_Barcode)
            {
                strncpy(pTail, pOutStr, dataLength);
            }
            
            pTail[refTailLgth] = '\0'; 
        }
        
        //get tail string value
        GenResult = strTolong(pTail, &value, radix);
        if (GenResult == AutoGen_Success)
        {        
            if ((value+step) > refMaxValue) //need to carry
            {
                char tmpCh = '0';
                long tmpVal = 0;          
                long mod = (value+step) - refMaxValue - 1;
                
                //conduct output tail string
                memset(pTail, '0', refTailLgth);
                switch(radix)
                {
                case 10:                    
                    if (0 <= mod && mod <= 9)
                    {
                        tmpCh = '0' + mod;
                    }                   
                    break;
                    
                case 16:
                    if (0 <= mod && mod <= 9)
                    {
                        tmpCh = '0' + mod;
                    }
                    else if(9 <= mod && mod <= 15)
                    {
                        tmpCh = 'A' + (mod - 10);
                    }
                    break;
                }
                pTail[refTailLgth-1] = tmpCh;
                pTail[refTailLgth] = '\0';   
                
                //conduct output head string
                if (eDataType == AutoGen_IMEI || eDataType == AutoGen_BT || eDataType == AutoGen_Wifi)
                {
                    GenResult = strTolong(pAhead, &tmpVal, radix);
                    if (GenResult == AutoGen_Success)
                    {
                        int  length = 0;
                        char pTmp[64] = {0};
                        char tmpCh = '0';
                        tmpVal += 1;
                        GenResult = longTostr(tmpVal, pTmp, radix);
                        if (GenResult == AutoGen_Success)
                        {    
                            length = strlen(pTmp);
                            strcpy(pAhead+(refAheadLgth - length), pTmp);
                        }                              
                    }    
                }  
                else if(eDataType == AutoGen_Barcode)
                {
                    char pTmp[64] = {0};
                    if (refMidLgth > 0)
                    {                   
                        //need to conduct output middle string
                        GenResult = strTolong(pMid, &tmpVal, radix);
                        if (GenResult == AutoGen_Success)
                        {
                            int  length = 0;                        
                            char tmpCh = '0';
                            tmpVal += 1;
                            GenResult = longTostr(tmpVal, pTmp, radix);
                            if (GenResult == AutoGen_Success)
                            {    
                                if (tmpVal > refMaxValue)// mid value exceed 'FFFFFFF', need to carry
                                {
                                    memset(pMid, '0', refMidLgth);
                                    GenResult = strTolong(pAhead, &tmpVal, radix);
                                    if (GenResult == AutoGen_Success)
                                    {
                                        //conduct output head string
                                        tmpVal += 1;
                                        GenResult = longTostr(tmpVal, pTmp, radix);
                                        if (GenResult == AutoGen_Success)
                                        {    
                                            length = strlen(pTmp);
                                            strncpy(pAhead, pTmp, length);
                                            pAhead[length] = '\0';
                                        }
                                    }
                                }// mid value exceed 'FFFFFFF'
                                else
                                {
                                    strcpy(pMid, pTmp);
                                    pMid[refMidLgth] = '\0';
                                }
                            }
                        }
                    } 
                    else
                    {
                        //conduct output head string
                        GenResult = strTolong(pAhead, &tmpVal, radix);
                        if (GenResult == AutoGen_Success)
                        {
                            tmpVal += 1;
                            longTostr(tmpVal, pTmp, radix);
                            strncpy(pAhead, pTmp, strlen(pTmp)+1);
                        }
                    }//end //if (refMidLgth > 0)
                }//end else if(eDataType == AutoGen_Barcode)
            }//end if ((value+step) > refMaxValue) //need to carry
            else
            {
                //don`t need to carry, so just need to re-conduct tail string
                char pTmp[64] = {0};
                int  length = 0;
                value += step;
                longTostr(value, pTail, radix);
                GenResult = longTostr(value, pTmp, radix);
                if (GenResult == AutoGen_Success)
                {    
                    memset(pTail, '0', refTailLgth);
                    length = strlen(pTmp);
                    if (eDataType == AutoGen_IMEI || eDataType == AutoGen_BT || eDataType == AutoGen_Wifi)
                    {
                        strncpy(pTail+(refTailLgth - length), pTmp, length);
                    }
                    else if(eDataType == AutoGen_Barcode)
                    {
                        strncpy(pTail, pTmp, length);
                    }               
                }
            }
    }
    
    if (GenResult == AutoGen_Success)
    {
        if (refMidLgth > 0)
        {
            strncat(pAhead, pMid, refMidLgth);
        }

        if (eOption == AutoGen_IMEI_CHECKSUM_OPTION)
        {
            pTail[refTailLgth] = pOutStr[dataLength-1];
            pTail[refTailLgth+1] = '\0';
            refTailLgth += 1;
        }        
        strncat(pAhead, pTail, refTailLgth);
        strcpy(pOutData, pAhead);
    }
    
    return GenResult;
    }  
}
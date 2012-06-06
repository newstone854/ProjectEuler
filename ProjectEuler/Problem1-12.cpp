// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ParseTimeRestriction/time_restriction_new.h"

////char pTest[] = {0x80,0x07,0x30,0x42,0x03,0x15,0x00,0x02,0x0A,0x30,0x42,0x0B,0x0B,0x00,0x02,0x03};
//char pTest[] = "[[(M3f21){M10}]-[(M11f11){M3}]]";
//char pChar[] = "%VT=11,15,16,17,20,21,25%VP=[[[[(M9d1){d30}]+[(M10d1){d30}]+[(M11d1){d30}]]*[(h16m30){h1m10}]]+[[[(M3d1){d31}]+[(M4d1){d31}]+[(M5d1){d31}]]*[(h13m30){h1}]]+[[[(M3d1){d31}]+[(M4d1){d31}]+[(M5d1){d31}]]*[(h17){h1m30}]]+[[[(M9d1){d30}]+[(M10d1){d30}]+[(M11d1){d30}]]*[(h13){h1}]]+[(h11m10){m50}]+[(h7){h1}]]%23=1";
//
////char pchar[] = {0xc0, 0x06, 0x30 , 0x20 , 0x02 , 0x00 , 0x10 , 0x05 , 0x31 , 0x00 , 0x06 , 0x01 , 0x00 , 0x0f , 0x1f , 0x40 , 0x0f , 0xc0 , 0x06 , 0x30 , 0x20 , 0x02 , 0x00 , 0x10 , 0x05 , 0x33 , 0x00 , 0x10 , 0x1e , 0x01 , 0x00 , 0x02};
//
//struct BF2
//{
//    char f1 : 3;
//    short f2 : 4;
//    char f3 : 5;
//};
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//
//	TimePoint tp;
//	const char* pTemp;
//	tp.year = 10;
//	tp.month = 11;
//	tp.day = 4;
//	tp.hour = 5;
//	tp.minute = 45;
//
//	int rlt = IsTimeRestricted(&tp, pTest);
//
//	return 0;
//}
//#include <iostream>   
//#include <vector>   
//#include <string>   
//#include "file_stream.h"
//using namespace std;   
//  
//////算法   
////int ldistance(const string source,const string target)   
////{   
////   //step 1   
////    int n=source.length();   
////    int m=target.length();   
////    if (m==0) return n;   
////    if (n==0) return m;   
////    //Construct a matrix   
////    typedef vector< vector<int> >  Tmatrix;   
////Tmatrix matrix(n+1);   
////for(int i=0; i<=n; i++)  matrix[i].resize(m+1);   
////
////    //step 2 Initialize   
////  
////    for(int i=1;i<=n;i++) matrix[i][0]=i;   
////for(int i=1;i<=m;i++) matrix[0][i]=i;   
////
////     //step 3   
////     for(int i=1;i<=n;i++)   
////     {   
////         const char si=source[i-1];   
////         //step 4   
////        for(int j=1;j<=m;j++)   
////        {   
////     
////                 const char dj=target[j-1];   
////             //step 5   
////                 int cost;   
////             if(si==dj){   
////                     cost=0;   
////                 }   
////             else{   
////                     cost=1;   
////                 }   
////             //step 6   
////                 const int above=matrix[i-1][j]+1;   
////             const int left=matrix[i][j-1]+1;   
////             const int diag=matrix[i-1][j-1]+cost;   
////             matrix[i][j]=min(above,min(left,diag));   
////     
////             }   
////      }//step7   
////      return matrix[n][m];   
////}   
//bool Utf8ToUnicode( const std::string& utf8Str, std::wstring& unicodeStr)
//{
//    int nCurWrtIndex = 0; 
//
//    bool bError = false; 
//    for(int i = 0; i < utf8Str.size(); ++ i)
//    {
//        char curByte = utf8Str.at(i); 
//        ///U-00000000 鈥毭?U-0000007F
//        if( 0 == (curByte&0x80))
//        {
//            unicodeStr.push_back((wchar_t)curByte);
//        }
//        else if( 0 ==  ((curByte&0xe0 ) ^ 0xc0)) ///110xxxxx
//        {
//            ++i;            
//            if(i >= utf8Str.size()) 
//            {
//                bError = true; 
//                break; 
//            }
//
//            char secByte =utf8Str.at(i); 
//            if( 0 == ((secByte &0xc0) ^ 0x80)) ///10xxxxxx
//            {
//                wchar_t wChar;
//                wChar = (wchar_t) (curByte &0x1f);
//                wChar <<=6; 
//                wChar |= (secByte & 0x3f); 
//                unicodeStr.push_back(wChar);
//            }
//            else
//            {
//                return false; 
//            }
//        }
//        else if( 0 == ((curByte&0xf0) ^ 0xe0)) ///1110xxxx
//        {
//            ++i;            		
//            if(i >= utf8Str.size()) 
//            {
//                bError = true; 
//                break; 
//            }
//
//            char secByte = utf8Str.at(i); 
//            ++i;
//            if(i >= utf8Str.size()) 
//            {
//                bError = true; 
//                break; 
//            }
//
//            char thirdByte = utf8Str.at(i); 
//            if( (0 == ((secByte&0xc0) ^ 0x80)) && (0 == ((thirdByte&0xc0) ^ 0x80)))
//            {
//                wchar_t wChar;
//                wChar = (wchar_t) (curByte & 0x0f); 
//                wChar <<=6; 
//                wChar |=  (wchar_t)(secByte & 0x3f); 
//                wChar <<=6; 
//                wChar |=  (wchar_t)(thirdByte & 0x3f);
//                unicodeStr.push_back(wChar);
//            }
//            else
//            {
//                bError = true; 
//                break; 
//            }
//        }
//        else 
//        {
//            //TRACE("***************Some weird Bytes stream.  *************\n"); 	
//            bError = true; 
//            break; 
//        }
//    }
//    unicodeStr.push_back((wchar_t)0);
//    return bError;   ///return bError; 
//};
//
//void Utf8ToUnicode(const std::string& strSrc, wchar_t* pDest, int& nLengthDest)
//
//{
//
//
//
//
//    int nLengthSrc = strSrc.length();
//
//    nLengthDest = 0;
//
//
//
//    int i = 0;
//
//    while (i < nLengthSrc)
//
//    {
//
//        if ( (strSrc[i] & 0x80) == 0x0)          //1 Bit
//
//        {
//
//            pDest[nLengthDest] = strSrc[i];
//
//            nLengthDest++;
//
//            i++;
//
//        }
//
//        else if ((strSrc[i] & 0xE0) == 0xC0) // 2 Bit
//
//        {
//
//
//
//
//            pDest[nLengthDest] = (((int)(strSrc[i] & 0x1F)) << 6) 
//
//                | (strSrc[i + 1] & 0x3F);
//
//            nLengthDest++;
//
//            i += 2;
//
//        } 
//
//        else if ((strSrc[i] & 0xF0) == 0xE0) // 3 Bit
//
//        {
//
//
//            pDest[nLengthDest] = (((int)(strSrc[i] & 0x0F)) << 12) 
//
//                | (((int)(strSrc[i + 1] & 0x3F)) << 6) 
//
//                | (strSrc[i + 2] & 0x3F);
//
//            nLengthDest++;
//
//            i += 3;
//
//        }
//
//        else if ((strSrc[i] & 0xF8) == 0xF0) // 4 Bit
//
//        {
//
//
//            pDest[nLengthDest] = (((int)(strSrc[i] & 0x07)) << 18) 
//
//                | (((int)(strSrc[i + 1] & 0x3F)) << 12) 
//
//                | (((int)(strSrc[i + 2] & 0x3F)) << 6) 
//
//                | (strSrc[i + 3] & 0x3F);
//
//            nLengthDest++;
//
//            i += 4;
//
//        }
//
//        else if ((strSrc[i] & 0xFC) == 0xF8) // 5 Bit
//
//        {
//
//
//            pDest[nLengthDest] = (((int)(strSrc[i] & 0x03)) << 24) 
//
//                | (((int)(strSrc[i + 1] & 0x3F)) << 18) 
//
//                | (((int)(strSrc[i + 2] & 0x3F)) << 12) 
//
//                | (((int)(strSrc[i + 3] & 0x3F)) << 6) 
//
//                | (strSrc[i + 4] & 0x3F);
//
//            nLengthDest++;
//
//            i += 5;
//
//        }
//
//        else if ((strSrc[i] & 0xFE) == 0xFC) // 6 Bit
//
//        {
//
//
//            pDest[nLengthDest] = (((int)(strSrc[i] & 0x01)) << 30) 
//
//                | (((int)(strSrc[i + 1] & 0x3F)) << 24) 
//
//                | (((int)(strSrc[i + 2] & 0x3F)) << 18) 
//
//                | (((int)(strSrc[i + 3] & 0x3F)) << 12) 
//
//                | (((int)(strSrc[i + 4] & 0x3F)) << 6) 
//
//                | (strSrc[i + 5] & 0x3F);
//
//            nLengthDest++;
//
//            i += 6;
//
//        }
//
//        else
//
//        {
//
//        }
//
//    }
//
//}
//
//

// #include <vector>
// #include <iostream>
// #include <windows.h>
// int main()
// {
//     LARGE_INTEGER counter1,counter2;
//     LARGE_INTEGER freq;
// 
//     QueryPerformanceFrequency(&freq);
//     QueryPerformanceCounter(&counter1);
// 
//     std::vector<int> vFind;
//     vFind.push_back(2);
//     vFind.push_back(3);
//     int sum = 5;
//     for(int i=5; i<10000; i+=2)
//     {
//         bool bAdd = true;
//         for(int j=0; j<vFind.size() && vFind[j]<100; j++)
//         {
//             if(i%vFind[j] == 0)
//             {
//                 bAdd = false;
//                 break;
//             }
//         }
//         if(bAdd)
//         {
//             vFind.push_back(i);
//             sum += i;
//         }
//     }
//     QueryPerformanceCounter(&counter2);
// 
//     std::cout<<double((counter2.QuadPart-counter1.QuadPart)/(freq.QuadPart/1000000.0))<<std::endl;
//     std::cout<<sum<<std::endl;
//     return 0;
// } 

//int main(){   
//    system("copy C:\\test.log d:\\test.log");
//}  


//#include<iostream>
//using namespace std;
//struct Car{
//    Car():price(20000) {}
//    Car(double b):price(b*1.1) {}
//    double price;
//};
//struct Toyota:public virtual Car
//{
//    Toyota(double b):Car(b){}
//};
//struct Prius:public Toyota
//{
//    Prius(double b):Toyota(b){}
//};
//
//int f(int a, int b)
//{
//    return a % b ? f(b, a%b):b;
//}
//int main()
//{
//    Prius p(30000);
//    int nP =sizeof(p);
//    cout << p.price << endl;
//    cout << f(399,39) << endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//static void _r(char* str, int len)
//{
//    int i;
//    for(i=0;i<len/2;i++){
//        char c = str[i];
//        str[i] = str[len-i-1];
//        str[len-i-1] = c;
//    }
//}
//void r(char* str)
//{
//    char *pos0=str, *pos1=str;
//    for(;;){
//        while(!(*pos1 == ' ' || *pos1 == '\t' || *pos1 == 0))
//            pos1++;
//        _r(pos0, pos1-pos0);
//        if(!*pos1)break;
//        pos0=++pos1;
//    }
//    _r(str, pos1-str);
//}
//
//void removeSpace(char* pChar)
//{
//    char *pos0 = pChar, *pos1 = pChar;
//    while(*pos1 != '\0')
//    {
//        if (*pos1 == ' ')
//        {
//            pos1++;
//        }else
//        {
//            *pos0++ = *pos1++;
//            
//        }
//    }
//}
//int ConvertStringToInt(char*  pChar)
//{
//    char *p = pChar;
//    int n = 0, nRet = 0;
//    while(*p != '\0')
//    {
//        n = *p++ - '0';
//        nRet = 10*nRet +n; 
//        
//    }
//    return nRet;
//}
//int main()
//{
//    char p[] = "Test reverse function 111.";
//    char p2[] = "12345";
//    //r(p);
//    //removeSpace(p);
//    ConvertStringToInt(p2);
//    cout<<p<<endl;
//    return 0;
//}

//#include <iostream>  
//using namespace std;  
//
//class Vehicle  
//{  
//public:  
//    Vehicle(int weight = 0)  
//    {  
//        Vehicle::weight = weight;  
//        cout<<"载入Vehicle类构造函数"<<endl;  
//    }  
//    void SetWeight(int weight)  
//    {  
//        cout<<"重新设置重量"<<endl;  
//        Vehicle::weight = weight;  
//    }  
//    virtual void ShowMe() = 0;  
//protected:  
//    int weight;  
//};  
//class Car:virtual public Vehicle//汽车，这里是虚拟继承  
//{  
//public:  
//    Car(int weight=0,int aird=0):Vehicle(weight)  
//    {  
//        Car::aird = aird;  
//        cout<<"载入Car类构造函数"<<endl;  
//    }  
//    void ShowMe()  
//    {  
//        cout<<"我是汽车！"<<endl;  
//    }  
//protected:  
//    int aird;  
//};  
//
//class Boat:virtual public Vehicle//船,这里是虚拟继承  
//{  
//public:  
//    Boat(int weight=0,float tonnage=0):Vehicle(weight)  
//    {  
//        Boat::tonnage = tonnage;  
//        cout<<"载入Boat类构造函数"<<endl;  
//    }  
//    void ShowMe()  
//    {  
//        cout<<"我是船！"<<endl;  
//    }  
//protected:  
//    float tonnage;  
//};  
//
//class AmphibianCar:public Car,public Boat//水陆两用汽车,多重继承的体现  
//{  
//public:  
//    AmphibianCar(int weight,int aird,float tonnage)  
//        :Vehicle(weight),Car(weight,aird),Boat(weight,tonnage)  
//        //多重继承要注意调用基类构造函数  
//    {  
//        cout<<"载入AmphibianCar类构造函数"<<endl;  
//    }  
//    void ShowMe()  
//    {  
//        cout<<"我是水陆两用汽车！"<<endl;  
//    }  
//    void ShowMembers()  
//    {  
//        cout<<"重量："<<weight<<"顿，"<<"空气排量："<<aird<<"CC，"<<"排水量："<<tonnage<<"顿"<<endl;  
//    }  
//};  
//int main()  
//{  
//    AmphibianCar a(4,200,1.35f);  
//    a.ShowMe();  
//    a.ShowMembers();  
//    a.SetWeight(3);  
//    a.ShowMembers();  
//    system("pause");   
//}
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
using namespace std;


__int64 Problem12(__int64 nMinFactors)
{
    __int64 nNum = 1;
    for (__int64 i = 2; ; i++)
    {
        __int64 nFact = 0;
        nNum = (i*(i+1))>>1;
        int j = 1;
        for(; j * j < nNum;j++)
        {
            if (nNum%j == 0)
            {
                nFact += 2;
            }
        }
        if (j * j == nNum)
        {
            nFact += 1;
        }

        if (nFact >= nMinFactors)
        {
            break;
        }
    }
    return nNum;
}

int main()
{
//     long long n = 600851475143;
//     long long maxPrime = MaxPrimeFactor(n);

    //int n = MaxPalindromic();
int n = Problem12(500);

    return 0;
}


int Sum35(int nMax)//problem 1
{
    int nSum = 0;
    for(int i =0;i<nMax;i++)
    {
        if (i%3 ==0 || i%5==0)
        {
            nSum += i;
        }
    }
    return nSum;
}

int SumEvenFib(int nMax)//problem 2
{
    int n1 = 1;
    int n2 = 2;
    int nSum = 2;
    int n3 = 0;
    for (;n3 < nMax;)
    {
        n3 = n1+n2;
        n1 = n2;
        n2 = n3;

        if (n3%2 == 0)
        {
            nSum += n3;
        }
    }
    return nSum;

}
bool IsPrime(long long n)
{
    if (n == 2)
    {
        return true;
    }
    if (n%2==0) 
    {
        return false;
    }
    else{
        for (long long i=3;i<=std::sqrt((long double)n);i+=2)
        {
            if (n%i==0)
            {
                return false;
            }
        }
    }
    return true;
}

long long MaxPrimeFactor(long long n)//problem 3
{
    long long nMaxPrime = 2;
    bool bOrig = true;
    if (n%nMaxPrime == 0)
    {
        bOrig = false;
        n = n/nMaxPrime;
    }

    for (long long i = 3; i <= n; i+=2)
    {
        if (IsPrime(i))
        {
            if (n%i == 0)
            {
                nMaxPrime = i;
                n = n/i;
                bOrig = false;
            }
        }
    }


    return nMaxPrime;
}

bool IsPalindromic(int n)
{
    char pTemp[12];
    itoa(n,pTemp,10);

    int nLen = strlen(pTemp);
    for (int i = 0; i < nLen/2; i++)
    {
        if (pTemp[i] != pTemp[nLen-i-1])
        {
            return false;
        }
    }
    return true;
}
int MaxPalindromic()//problem 4
{
    int a = 100;
    int b = 100;

    int nMax = 0;
    for (;a <= 999;)
    {
        int n = (a*b);
        if (IsPalindromic(n))
        {
            nMax = nMax > n ? nMax : n;
        }
        if (b <= 999)
        {
            b++;
        }
        else
        {
            b = 100;
            a++;
        }
    }
    return nMax;
}

int MinProduct(int nMax)//problem 5
{
    int nPro = 1;
    map<int, int> mapPrimes;
    for (int i = 2; i < nMax; i++)
    {
        if (IsPrime(i))
        {
            mapPrimes.insert(make_pair(i,1));
            if (nPro % i != 0)
            {
                nPro *= i;
            }
        }
        else if (nPro % i != 0)
        {
            int nNum = i;
            for (map<int,int>::iterator it = mapPrimes.begin(); it != mapPrimes.end() && nNum > it->first; ++it)
            {
                int nCount = 0;
                while (nNum >= it->first && nNum % it->first == 0)
                {
                    nNum /= it->first;
                    nCount++;
                }
                if (nCount > it->second)
                {
                    it->second = nCount;
                    nPro *= it->first;
                }
            }
        }

    }
    return nPro;
}
int Problem6(int nMax)//1^2 + 2^2 + ... + n^2 = n * (n+1) * (2n+1) * 1/6
//(1+2+3+...+n)^2=(1^3)+(2^3)+(3^3)+...+(n^3)
{
    int nSquareSum = 0;
    int nCubSum = 0;
    int nSumSquare = 0;
    for (int i = 1; i <= nMax; i++)
    {
        nSquareSum += i*i;
        nCubSum += i*i*i;
        nSumSquare += i;
    }
    nSumSquare *= nSumSquare;
    return nSumSquare - nSquareSum;
}

// bool bRet = IsDataFormatCompatible("1.6.a");
// bRet = IsDataFormatCompatible("1.6.2");
// bRet = IsDataFormatCompatible("1.6.1");
// bRet = IsDataFormatCompatible("1.7");
// bRet = IsDataFormatCompatible("1.7.5");
// bRet = IsDataFormatCompatible("2.6.0");
// bRet = IsDataFormatCompatible("r1.6.0");
// bRet = IsDataFormatCompatible("1r3456sd1.6.0");
bool IsDataFormatCompatible(const char* pszDataFormat)
{
    const static char s_cSep = '.';
    const static char* S_DATA_FORMAT_VERSION = "1.6.1";

    int nData = atoi(pszDataFormat);//main version
    int nLib = atoi(S_DATA_FORMAT_VERSION);
    if (nData != nLib)//main version mismatch
    {
        return false;
    }

    const char *pTemp = pszDataFormat;
    int nPosition = 0;
    for(; nPosition < strlen(pszDataFormat); nPosition++)
    {
        if (*pTemp++ == s_cSep)
        {
            nPosition++;
            break;
        }
    }

    //Add protection for invalid version string
    if (nPosition >= strlen(pszDataFormat) || nPosition >= strlen(S_DATA_FORMAT_VERSION))
    {
        return false;
    }
    nData = atoi(pTemp);//sub-version
    nLib = atoi(S_DATA_FORMAT_VERSION + nPosition);
    if (nLib < nData)
    {
        return false;
    }
    else if (nLib > nData)
    {
        return true;
    }
    else//main version match and sub-version match
    {
        nData = nLib = 0;//default 0
        for(; nPosition < strlen(pszDataFormat); nPosition++)
        {
            if (*pTemp++ == s_cSep)
            {
                nPosition++;
                break;
            }
        }
        if (nPosition < strlen(pszDataFormat))
        {
            nData = atoi(pTemp);
        }
        if(nPosition < strlen(S_DATA_FORMAT_VERSION))
        {
            nLib = atoi(S_DATA_FORMAT_VERSION + nPosition);
        }
        return nLib >= nData;
    }
}


int NthPrime(int n)//problem 7
{
    if (n == 1)
    {
        return 2;
    }
    n -= 1;
    int i = 3;
    for (; n > 0; i+=2)
    {
        if (IsPrime(i))
        {
            if (--n == 0)
            {
                return i;
            }
        }
    }

    return i;
}

int Problem9(int nSum = 1000)
{
    int a = 1;
    int b = 1;

    for (;a < 1000;a++)
    {
        for (;b < 1000;b++)
        {
            if (a*b%1000 == 0)
            {
                if (a + b - (a*b/1000) == 500)
                {
                    return a*b*(1000-a-b);
                }
            }
        }
        b = 1;
    }

    return 0;
}

long long Problem10(int nMax)
{
    long long nSum = 2;
    std::vector<int> vPrimes;
    vPrimes.push_back(2);
    for (int i = 3; i < nMax; i+=2)
    {
        bool bPrime = true;
        for (int j = 0; j < vPrimes.size() && vPrimes[j] <= sqrt((double)i); j++)
        {
            if (i % vPrimes[j] == 0)
            {
                bPrime = false;
                break;
            }
        }
        if (bPrime)
        {
            vPrimes.push_back(i);
            nSum += i;
        }
    }
    return nSum;
}

int vec[20][20]={
    {8,2,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91,8},
    {49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
    {81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
    {52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
    {22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
    {24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
    {32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
    {67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
    {24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
    {21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
    {78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92},
    {16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
    {86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
    {19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
    {04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
    {88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
    {04,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
    {20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
    {20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
    {01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48},};

    int sub11(int x, int y)
    {
        int nMax = 0;
        int nTemp = vec[x][y];
        if (x < 17)
        {
            nMax = nTemp*vec[x+1][y]*vec[x+2][y]*vec[x+3][y];
        }
        if (y < 17)
        {
            nTemp = nTemp*vec[x][y+1]*vec[x][y+2]*vec[x][y+3];
            nMax = nTemp > nMax ? nTemp : nMax;
        }
        if (x < 17 && y < 17)
        {
            nTemp = vec[x][y]*vec[x+1][y+1]*vec[x+2][y+2]*vec[x+3][y+3];
            nMax = nTemp > nMax ? nTemp : nMax;
        }
        if (y > 2 && x < 17)
        {
            nTemp = vec[x][y]*vec[x+1][y-1]*vec[x+2][y-2]*vec[x+3][y-3];
            nMax = nTemp > nMax ? nTemp : nMax;
        }
        return nMax;
    }
int Problem11()
{
    int nMax = 0;
    int nTemp = 0;
    int m,n;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (1/*vec[i][j] > nMax*/)
            {
                nTemp = sub11(i,j);
                if (nTemp > nMax)
                {
                    nMax = nTemp;
                    m = i;
                    n = j;
                }
            }
        }
    }
    return nMax;
}

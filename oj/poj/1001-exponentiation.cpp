/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * @Brief: 
 * 大数乘法的大数乘方运算
 * 
 * -------------------------------------------------------------}}}*/
#include <cstring>
#include <iostream>
using namespace std;

const size_t Max_Product_Len = 1500;

void CarryAdd(char * pszSum, char cAugend, int iMod=10) { // N进制加法
    if (pszSum && iMod > 0) {
        while (cAugend) {
            cAugend += (*pszSum-'0');
            *pszSum = '0'+cAugend%iMod;
            cAugend /= iMod;
            --pszSum;
        }
    }
    return;
}

string str_multipy(const string & strM, const string & strN) { // 大数乘法
    const char * pszM = strM.c_str();
    const char * pszN = strN.c_str();
    size_t szDecimalCnt_M=0, szDecimalCnt_N=0, szProductPosBase=Max_Product_Len, szProductPosOffset=0;
    char aszProduct[Max_Product_Len+1];
    memset(aszProduct, '0', Max_Product_Len);
    aszProduct[Max_Product_Len] = '\0';

    for (size_t szN = strN.size(); szN != 0; --szN) {
        if (pszN[szN-1] == '.') {
            szDecimalCnt_N = strN.size() - szN;
            continue;
        }

        for (size_t szM = strM.size(); szM != 0; --szM) {
            if (pszM[szM-1] == '.') {
                if (szDecimalCnt_M == 0)
                    szDecimalCnt_M = strM.size() - szM;
                continue;
            }
            CarryAdd(&aszProduct[szProductPosBase-szProductPosOffset-1], (pszN[szN-1]-'0')*(pszM[szM-1]-'0'));
            ++ szProductPosOffset;
        }
        szProductPosOffset = 0;
        -- szProductPosBase;
    }

    // 确定小数点位置和结果数据开始的位置
    size_t szDecimalPos = Max_Product_Len-1-szDecimalCnt_M-szDecimalCnt_N;
    size_t szStrStart = Max_Product_Len - strM.size() - strN.size() - 1;
    while (szStrStart < szDecimalPos && aszProduct[szStrStart] == '0') ++szStrStart;
    // 构造返回结果
    string strResult(aszProduct, szStrStart, szDecimalPos-szStrStart+1);
    if (szDecimalPos != Max_Product_Len-1) // 有小数点
        strResult += "." + string(aszProduct, szDecimalPos+1, Max_Product_Len-1);

    return strResult;
}

// 幂的快速计算
string mul_pow_imp(string _tm, unsigned _n) {
    if (_n == 0) return "1";
    string strTmp = mul_pow_imp(_tm, _n/2);
    string strTmp2 = str_multipy(strTmp, strTmp);
    if (_n&1) return str_multipy(_tm, strTmp2);
    else return strTmp2;
}

// 数据格式检查
string pow_large(string _tx, unsigned _y) {
    if (_y == 0) return "1";
    const char * pszIn = _tx.c_str();
    size_t szStart = 0;
    size_t szEnd = _tx.size();
    while (szStart < szEnd && pszIn[szStart] == '0') ++szStart;
    if (szStart >= szEnd) return "0";

    bool bIsDecimal = false;
    for (size_t sz=szStart; sz<szEnd; ++ sz) {
        if (pszIn[sz] == '.') {
            if (!bIsDecimal) bIsDecimal = true;
            else return "Invalid Input[more than one point]";
        }
        else if (pszIn[sz] < '0' || pszIn[sz] > '9') {
            return "Invalid Input[wrong bound]";
        }
    }

    if (bIsDecimal) 
        while (szEnd && pszIn[szEnd-1] == '0') --szEnd;

    return mul_pow_imp(string(pszIn, szStart, szEnd-szStart), _y);
}

int main(int argc, char * argv[]) {
    string strM, strResult;
    unsigned int uN;
    while (cin >> strM >> uN && uN <= 100) {
        strResult = pow_large(strM, uN);
        const char * pszZeroStart = strResult.c_str();
        if (pszZeroStart[0] == '0') // 这里是poj的要求，呵呵
            cout << &pszZeroStart[1] << endl;
        else
            cout << strResult << endl;
    }
    return 0;
}

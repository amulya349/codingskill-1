#include <string.h>
#include <iostream>
using namespace std;

static int make_next(const char * pMod, int * pNext) {
    if (!pMod || !pNext) return -1;

    int i = 1;
    int j = 0;
    pNext[1] = 0;
    while (pMod[i] != '\0') {
        if (j == 0 || pMod[i] == pMod[j]) {
            ++i;
            ++j;
            if (pMod[i] != pMod[j])
                pNext[i] = j;
            else
                pNext[i] = pNext[j];
        }
        else {
            j = pNext[j];
        }
    }
    return 0;
}

static int kmp_cmp(const char * pStr, const char * pMod) {
    if (!pStr || !pMod)
        return -2;	

    int aNext[strlen(pMod)+1];
    memset(aNext, sizeof(aNext), 0);
    make_next(pMod, aNext);
#if 0
    for (int ii=1; ii<=strlen(pMod); ++ii)
        cout << aNext[ii] << ", ";
    cout << endl;
#endif

    int iStr = 0;
    int iMod = 1;
    while (pStr[iStr] != '\0' && pMod[iMod] != '\0') {
        if (iMod == 0 || pStr[iStr] == pMod[iMod]) {
            ++ iStr;
            ++ iMod;
        }
        else {
            iMod = aNext[iMod];
        }
    }

    if (pMod[iMod] == '\0')
        return iStr - iMod;
    else 
        return -1;
}

int main() {
    // input
    string strK, strM;
    cout << "plz input main string : ";
    cin >> strK;
    cout << "plz input mod string  : ";
    cin >> strM;

    if (strK.size() < strM.size()) {
        cout << "can not find(length err)" << endl;
        return -1;
    }

    // calc
    int iPos = kmp_cmp(strK.c_str(), strM.c_str());

    // output
    if (iPos < 0) {
        cout << "can not find sub string position" << endl;
    }
    else {
        cout << "[found]" << endl << strK << endl;
        for (int i=0; i<iPos; ++i)
            cout << " ";
        for (unsigned int j=0; j<strM.size(); ++j)
            cout << "-";
        cout << endl;
    }
    return 0;
}

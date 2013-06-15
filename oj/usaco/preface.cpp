/*
ID:myxjtu1
PROG:preface
LANG:C++
*/
#include <fstream>
#include <math.h>
using namespace std;
#ifdef DBG
#include <iostream>
#else
ifstream cin("preface.in");
ofstream cout("preface.out");
#endif

int counter[256];

static const string ROM[] = {"",
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
    "M", "MM", "MMM" };

string intoRoman(int num) {
    string ans;
    for (int r=0; num>0; r+=9, num/=10) if (num%10)
        ans = ROM[r+num%10]+ans;
    return ans;
}

void solve(int n) {
    if (n>=4000||n<0) return;
    for (int i=1; i<=n; ++i) {
        string s=intoRoman(i);
        for (int j=s.size()-1; j>=0; --j)
            ++counter[(int)s[j]];
    }

    for (const char *c="IVXLCDM"; *c; ++c) if (counter[(int)*c]>0)
        cout << char(*c) << " " << counter[(int)*c] << endl;
}

int main(int argc, char * argv[]) {
    int N; cin >> N;
    solve(N);
    return 0;
}

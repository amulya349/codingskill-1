/*
ID:myxjtu1
PROG:dualpal
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

string itob_rev(int a, int b) {
    const static char DICT[] = "0123456789ABCDEFGHIJ";
    string ans;
    while (a) {
        ans += DICT[a%b];
        a /= b;
    }
    /*in fact, here is a SURE is a>1, so we don't care a==0*/
    return ans;
}

bool isPal(const string & a) {
    int i=0, j=a.size()-1;
    while (i<j && a[i]==a[j]) ++i,--j;
    return i>=j;
}

int main(int argc, char * argv[]) {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    if (!fin || !fout) return -1;
    int S, T; fin >> S >> T;
    for (int c=0, i=1; c<S; ++i) {
        int stat = 0;
        for (int b=2; b<=stat+9 && stat<2; ++b) {
            if (isPal(itob_rev(i+T, b))) 
                ++stat;
        }
        if (stat < 2) continue;
        ++c;
#ifdef DBG 
        cout << i+T << endl;
#else
        fout << i+T << endl;
#endif
    }
    return 0;
}

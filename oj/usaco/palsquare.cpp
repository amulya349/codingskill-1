/*
ID:myxjtu1
PROG:palsquare
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_NUM = 300;
const char DICT[] = "0123456789ABCDEFGHIJ";

string itob_rev(int a, int b) {
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

void reverse(string & s) {
    int i=0, j=s.size()-1;
    for (char temp; i<j; ++i,--j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(int argc, char * argv[]) {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    if (!fin || !fout) return -1;
    int B; fin >> B;
    for (int i=1; i<=MAX_NUM; ++i) {
        int ii = i*i;
        string iib = itob_rev(ii, B);
        if (!isPal(iib)) continue;

        string ib = itob_rev(i, B);
        reverse(ib);
#ifdef DBG
        cout << ib << " " << iib << endl;
#else
        fout << ib << " " << iib << endl;
#endif
    }
    return 0;
}

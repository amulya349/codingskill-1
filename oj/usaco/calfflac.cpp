/*
ID:myxjtu1
PROG:calfflac
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

struct PalindInteval {
    int begin, end, len;
    PalindInteval() : begin(-1),end(-2),len(0) {}
};

inline bool isA2Z(char c) { return (c>='A' && c<='Z'); }
inline char toUpper(char c) { return (c>='a' && c<='z')?c+'A'-'a':c; }

PalindInteval walker(const string &s, int l, size_t r) {
    PalindInteval ans;
    for (; l>=0 && r<s.size(); --l, ++r) {
        while (l>=0&&!isA2Z(toUpper(s[l]))) --l;
        if (l<0) break;
        while (r<s.size()&&!isA2Z(toUpper(s[r]))) ++r;
        if (r>=s.size()) break;
        if (toUpper(s[l]) != toUpper(s[r])) break;
        ans.begin=l, ans.end=r, ans.len+=2;
    }
    return ans;
}

PalindInteval solve(const string & s) {
    PalindInteval ans;
    const int LEN = s.size();

    int i=0;
    while (i<LEN && !isA2Z(s[i])) ++i;
    if (i<LEN) 
        ans.begin=ans.end=i, ans.len=1;

    for (i+=1; 2*i+ans.len+1<=2*LEN; ++i) {
        PalindInteval o = walker(s, i-1, i+1);
        PalindInteval e = walker(s, i, i+1);

        if (isA2Z(toUpper(s[i])))  ++o.len;
        if (ans.len<o.len) ans = o;
        if (ans.len<e.len) ans = e;
    }
    return ans;
}

int main(int argc, char * argv[]) {
    FILE * fin = fopen("calfflac.in", "r");
    ofstream fout("calfflac.out");
    if (!fin || !fout) return -1;
    string s; 
    for (char c=getc(fin); c!=EOF; c=getc(fin)) s+=c;
    PalindInteval ans = solve(s);
#ifdef DBG 
    cout<< ans.len << endl 
        << s.substr(ans.begin, ans.end-ans.begin+1) << endl;
#else
    fout<< ans.len << endl 
        << s.substr(ans.begin, ans.end-ans.begin+1) << endl;
#endif
    return 0;
}

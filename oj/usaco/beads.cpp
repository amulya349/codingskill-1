/*
ID:myxjtu1
PROG:beads
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

int solve(string & s) {
    const int LEN=s.size();
    int g(0), a(-1), b(-1); // a,b is the last position of one color
    for (; g<LEN; ++g) {
        if (s[g] != 'w') {
            if (a == -1) a=g;
            else if (s[a] == s[g]) a=g;
            else { b=g++; break;}
        }
    }

    int ans=g;
    bool isSecondRound = false;
    for (int begin=0; g<(isSecondRound?begin:LEN); ) {
        for (; g<(isSecondRound?begin:LEN) && s[g]!=s[a]; ++g) {
            if (s[g] == s[b]) b=g;
        }
        ans=max(ans, g-begin+(isSecondRound?LEN:0));
        if (isSecondRound&&g==begin) { 
            return ans;
        } else if (g==LEN) {
            isSecondRound=true, g=0;
            continue;
        }
        begin=a+1;
        a=b;
        b=g;
        if (++g==LEN) isSecondRound=true,g=0;
    }
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    if (!fin || !fout) return -1;
    size_t N; fin >> N;
#ifdef DBG 
    for (size_t i=0; i<N; ++i) {
        string jewls; fin >> jewls;
        cout << jewls << ":\t" << solve(jewls) << endl;
    }
#else
    string jewls; fin >> jewls;
    fout << solve(jewls) << endl;
#endif
    return 0;
}

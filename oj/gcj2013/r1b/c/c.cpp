#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <tr1/unordered_set>
using namespace std;
using namespace tr1;

unordered_set<string> dict;
int max_word_len = 0;

int solve(const string & s) {
    const int LEN = s.size();
    int modify[LEN];
    int ans[LEN];
    memset(ans, 0, sizeof(ans));
    for (int i=0; i<LEN; ++i) {
        modify[i] = -1;
        int m=LEN;
        bool changed=false;
        string w;
        for (int j=i; j>=0&&i-j+1<=max_word_len; --j) {
            w = s.substr(j, i-j+1);
            if (dict.find(w) != dict.end()) {
                if (m>=(j>0?ans[j-1]:0)) {
                    m = j>0?ans[j-1]:0;
                    modify[i] = -1;
                }
            } else {
                for (int k=)

            }
        }
    }

    return ans[LEN-1];
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ifstream dictin("./dict.txt");
    string w;
    while (dictin >> w) {
        dict.insert(w);
        if (max_word_len<w.size()) max_word_len=w.size();
    }

    int casenum; cin >> casenum;
    for (int casei=1; casei<=casenum; ++casei) {
        string s; cin >> s;
        int ans = solve(s);
        printf("Case #%d: %d\n", casei, ans);
    }
    return 0;
}

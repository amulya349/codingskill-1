#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 102;

bool isvowel(char c) {
    static bool letters[] = {
        1,0,0,0,1,0,0,0,1,0,
        0,0,0,0,1,0,0,0,0,0,
        1,0,0,0,0,0};
    return letters[c-'a'];
}

int cal(bool isExist[], int a, int b, int LEN, int N) {
    int ans = 0;
    for (int last=a+N-1; last<b; ++last, ++a) {
        for (int i=0; i<=a; ++i)
            for (int j=last; j<LEN; ++j) {
                if (isExist[MAX*i+j]) continue;
                isExist[MAX*i+j] = 1;
                ++ans;
            }
    }
    return ans;
}

int solve(const string &s, int N) {
    const int LEN = s.size();
    bool isExist[MAX*MAX];
    memset(isExist, 0, sizeof(isExist));
    int ans = 0;

    for (int i=0; i<LEN; ++i) {
        if (isvowel(s[i])) continue;

        int a=i, b=i;
        while (b<LEN && !isvowel(s[b])) ++b;
        i=b;

        ans += cal(isExist, a, b, LEN, N);
    }
    return ans;
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int casenum; cin >> casenum;
    for (int casei=1; casei<=casenum; ++casei) {
        string s; cin >> s;
        int N; cin >> N;
        int ans = solve(s, N);
        cout << "Case #" << casei << ": " << ans << endl;
    }
    return 0;
}

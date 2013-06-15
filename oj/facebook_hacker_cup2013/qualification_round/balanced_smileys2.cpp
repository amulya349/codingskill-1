#include <iostream>
#include <stdio.h>
using namespace std;

bool solve(const string & ln) {
    const int LEN = ln.size();
    int lo = 0, hi = 0;
    for (int i=0; lo<=hi && i<LEN; ++i) {
        switch (ln[i]) {
            case '(':
                ++lo, ++hi;
                break;
            case ')':
                --lo, --hi;
                lo = max(lo, 0);
                break;
            case ':':
                if (i+1 < LEN) {
                    if (ln[i+1] == '(') {
                        ++i, ++hi;
                    }
                    else if (ln[i+1] == ')') {
                        ++i, --lo;
                        lo = max(lo, 0);
                    }
                }
                break;
        }
    }
    return lo == 0 && hi >= 0;
}

int main() {
    string ln;
    int N; 
    scanf("%d\n", &N);
    for(int i=0; i < N; i++) {
        getline(cin, ln);
        printf("Case #%d: %s\n", i+1, (solve(ln)?"YES":"NO"));
    }
    return 0;
}

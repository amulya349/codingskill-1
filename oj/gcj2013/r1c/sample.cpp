#include <stdio.h>

int solve() {
    return 0;
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int casenum; scanf("%d", &casenum);
    for (int casei=1; casei<=casenum; ++casei) {
        int ans = solve();
        printf("Case #%d: %d\n", casei, ans);
    }
    return 0;
}

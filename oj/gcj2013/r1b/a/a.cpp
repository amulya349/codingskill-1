#include <stdio.h>
#include <algorithm>
const int MAX_N = 1000006;
int all[MAX_N];

int solve(long long  A, int N) {
    int ans = 0;
    std::sort(all, all+N);
    for (int i=0; i<N; ++i) {
        if (A>all[i]) {
            A+=all[i];
            continue;
        }
        int del = N-i;
        int add = 0;
        while (add < del && A<=all[i]) {
            A = 2*A-1;
            ++add;
        }

        if (A > all[i]) A+=all[i];
        ans += add;
        if (add == del) return ans;
    }
    return ans;
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int casenum; scanf("%d", &casenum);
    for (int casei=1; casei<=casenum; ++casei) {
        int A, N; scanf("%d%d", &A, &N);
        for (int i=0; i<N; ++i)
            scanf("%d", &all[i]);
        int ans = solve(A, N);
        printf("Case #%d: %d\n", casei, ans);
    }
    return 0;
}

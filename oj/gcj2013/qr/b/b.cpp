#include <algorithm>
#include <stdio.h>
using namespace std;

struct VS {
    int val, rem, idx; // rem:这一步操作完了之后需要留下多少的能量
    VS():rem(-1){}
    bool operator< (const VS & rhs) const { return val<rhs.val || (val==rhs.val && idx>rhs.idx); };
};

int solve(int E, int R, int v[], int N) {
    VS a[N];
    for (int i=0; i<N; ++i) 
        a[i].val=v[i], a[i].idx=i;
    sort(a, a+N);
    int b[N];
    for (int i=0; i<N; ++i) 
        b[a[i].idx]=i;

    for (int i=N-1; i>=0; --i) {
        int remain=0;
        for (int j=a[i].idx; j>=0&&a[j].rem==-1; --j) {
            a[j].rem=remain;
            remain-=R;
            if (remain<=0) break;
        }
    }

    //for (int i=0; i<N; ++i)
    //    printf("%d ", s[i]);
    //printf("\n");
    int ans = 0;
    return ans;
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int casenum; scanf("%d", &casenum);
    for (int casei=1; casei<=casenum; ++casei) {
        int E, R, N; scanf("%d%d%d", &E,&R,&N);
        int v[N];
        for (int i=0; i<N; ++i) 
            scanf("%d", &v[i]);
        int ans = solve(E, R>E?E:R, v, N);
        printf("Case #%d: %d\n", casei, ans);
    }
    return 0;
}

#include <stdio.h>
#include <limits.h>

int main(int argc, char * argv[]) {
    int n, k, f, t;
    int ans = INT_MIN;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; ++i) {
        scanf("%d%d", &f, &t);
        int once = f-(t<=k?0:(t-k));
        if (once > ans)
            ans = once;
    }
    printf("%d\n", ans);
    return 0;
}

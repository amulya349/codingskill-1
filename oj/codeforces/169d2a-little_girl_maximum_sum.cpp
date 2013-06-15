#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    int a[n];
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);

    int c[n+1];
    memset(c, 0, sizeof(c));
    for (int i=0; i<q; ++i) {
        scanf("%d%d", &l, &r);
        ++c[l-1], --c[r];
    }
    for (int i=1; i<n; ++i) 
        c[i] += c[i-1];

    sort(a, a+n);
    sort(c, c+n);
    unsigned long long ans = 0;
    for (int i=n-1; i>=0&&c[i]>0; --i)
        ans += 1llu*c[i]*a[i];
    cout << ans << endl;

    return 0;
}

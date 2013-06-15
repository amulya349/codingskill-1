#include <iostream>
#include <string.h>
using namespace std;
const int DIVISOR = 10007;

int cnk(int n, int k) {
    int c[n+1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for (int i=0; i<=n; ++i) {
        for (int j=i; j>=1; --j) 
            c[j] = (c[j-1]+(j-1<=i?c[j]:0))%DIVISOR; // (n, k)=(n-1, k-1)+(n-1, k)
    }
    return c[k];
}

// 2*((2n-2, n-1)-(2n-2, n-2))
int paths(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int a = cnk(2*n-2, n-1);
    int b = cnk(2*n-2, n-2);
    if (a < b)
        a += DIVISOR;
    return (2*a-2*b)%DIVISOR;
}

int main() {
    int N;
    cin >> N;
    cout << paths(N) << endl;
    return 0;
}

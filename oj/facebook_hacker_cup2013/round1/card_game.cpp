/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Problem
 * You are given an array a with N ≤10000 different integer numbers and a number, K, where 1 ≤ K ≤ N. 
 * For all possible subsets of a of size K find the sum of their maximal elements modulo 1000000007.
 * 
 * Input
 * The first line contains the number of test cases T, where 1 ≤ T ≤ 25
 * 
 * Each case begins with a line containing integers N and K. 
 * The next line contains N space-separated numbers 0 ≤ a [i] ≤ 2 000 000 000, which describe the array a.
 * 
 * Output
 * For test case i, numbered from 1 to T, output "Case #i: ", followed by a single integer, 
 * the sum of maximal elements for all subsets of size K modulo 1000000007.
 * 
 * Example
 * For a = [3, 6, 2, 8] and N = 4 and K = 3, the maximal numbers among all triples are 6, 8, 8, 8 and the sum is 30.
 *
 *
 * Example input
 * 5
 * 4 3
 * 3 6 2 8 
 * 5 2
 * 10 20 30 40 50 
 * 6 4
 * 0 1 2 3 5 8 
 * 2 2
 * 1069 1122 
 * 10 5
 * 10386 10257 10432 10087 10381 10035 10167 10206 10347 10088 
 *
 * Example output
 * Case #1: 30
 * Case #2: 400
 * Case #3: 103
 * Case #4: 1122
 * Case #5: 2621483
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
const int MODULO = 1000000007;
typedef long long unsigned u64_t;

void ck_mod(u64_t cnk[], int n, int k, int mod) {
    int c[n+1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for (int i=0,r=0; i<=n; ++i) {
        for (int j=i; j>=1; --j) 
            c[j] = (c[j-1]+(j-1<=i?c[j]:0))%mod; // (n, k)=(n-1, k-1)+(n-1, k)

        if (i>=k) {
            cnk[r] = c[r];
            ++r;
        }
    }
}

int solve(int a[], int N, int K) {
    std::sort(a, a+N);
    u64_t cnk[N-K+1];
    ck_mod(cnk, N-1, K-1, MODULO);

    u64_t sum=0;
    for (int i=0; i<N-K+1; ++i)
        sum = (sum+(a[K+i-1]*cnk[i])%MODULO)%MODULO;
    return sum;
}

int main(int argc, char * argv[]) {
    int T;
    scanf("%d\n", &T);
    for (int i=1; i<=T; ++i) {
        int N, K;
        scanf("%d%d\n", &N,&K);
        int a[N];
        for (int j=0; j<N; ++j)
            scanf("%d", &a[j]);
        scanf("\n");
        int ans = solve(a, N, K);
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}

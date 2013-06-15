/*
ID:myxjtu1
PROG:subset
LANG:C++
*/
#include <fstream>
using namespace std;
#ifdef DBG
#include <iostream>
#else
ifstream cin("subset.in");
ofstream cout("subset.out");
#endif

const int MAX=40;
typedef long long int64_t;
int64_t paths[MAX*MAX/4];

int64_t solve(int n) {
    const int64_t SUM=((1+n)*n)/2;
    if (SUM&1) return 0;

    const int64_t V=SUM/2;
    paths[0] = 1;

    for (int i=1; i<=n; ++i) 
        for (int64_t s=V; s>=i; --s) 
            paths[s] += paths[s-i];

    return paths[V]/2;
}

int main(int argc, char * argv[]) {
    int n; cin >> n;
    cout << solve(n) << endl;
    return 0;
}

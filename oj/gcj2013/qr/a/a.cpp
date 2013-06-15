#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef unsigned long long ll;

ll solve(ll r, ll t) {
    long double x=(r/2.0-0.25)*(-1.0+sqrt(1.0+(t/(0.5*r-0.25))*(1/(1.0*r-0.5))));
    return x;
}

int main(int argc, char * argv[]) {
    int casenum; cin >> casenum;
    for (int casei=1; casei<=casenum; ++casei) {
        ll r,t; cin>>r>>t;
        ll ans = solve(r, t);
        cout << "Case #" << casei << ": " << ans << endl;
    }
    return 0;
}

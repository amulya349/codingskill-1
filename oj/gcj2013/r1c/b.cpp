#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

char ans[502];
bool helper(int step, int a, int b, int X, int Y) {
    if (step>500 || X>=0?a>X:a<X || Y>=0?b>Y:b<Y) return false;
    if (X>=0) {
        if (a+step>X) {
        }
        else if (a+step==X && b==Y) {
            ans[step-1] = 'E';
            return true;
        }
        helper(step+1, a+step, b, X, Y);
    }
    else if (X<0)

}

void solve(int X, int Y) {
    memset(ans, 0, sizeof(ans));
    helper(1, 0, 0, X, Y);
}

int main(int argc, char * argv[]) {
#ifdef DBG 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int casenum; cin >> casenum;
    for (int casei=1; casei<=casenum; ++casei) {
        int x, y; cin >> x >> y;
        solve(x, y);
        cout << "Case #" << casei << ": " << ans << endl;
    }
    return 0;
}

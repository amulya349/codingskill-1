/*
ID:myxjtu1
PROG:numtri
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

void output(ostream &out, int ans) {
    out << ans << endl;
}

int main(int argc, char * argv[]) {
    ifstream fin("numtri.in");   if (!fin)  return -1;
    int R; fin >> R;
    int a[R];
    memset(a, 0, sizeof(a));
    for (int i=1; i<=R; ++i) {
        int prev = a[0], now = INT_MIN;
        for (int j=0; j<i; ++j) {
            int b; fin >> b;
            prev = a[j];
            a[j] = b+max(a[j], now);
            now = prev;
        }
    }

    int ans=INT_MIN;
    for (int i=0; i<R; ++i) 
        ans = max(ans, a[i]);
#ifdef DBG 
    cout << ans << endl;
#else
    ofstream fout("numtri.out"); if (!fout) return -2;
    fout << ans << endl;
#endif
    return 0;
}

/*
ID:myxjtu1
PROG:barn1
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int solve(const bool lived[], int n, int M) {
    vector<int> emptys;
    for (int i=0; i<n; ) {
        while (i<n && lived[i]) ++i;
        int begin = i;
        while (i<n && !lived[i]) ++i;
        int end = i-1;
        if (end>=begin) 
            emptys.push_back(end-begin+1);
    }
    sort(emptys.begin(), emptys.end());

    int ans = n;
    for (int k=2,i=emptys.size()-1; k<=M&&i>=0; ++k,--i)
        ans -= emptys[i];
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("barn1.in"); if (!fin) return -1;
    int M, S, C; fin >> M >> S >> C;

    int a(S+1), b(0);
    bool lived[S+1];
    memset(lived, 0, sizeof(lived));
    for (int i=1,k; i<=C; ++i) {
        fin >> k;
        lived[k]=true, a=min(a, k), b=max(b, k);
    }
    int ans = solve(&lived[a], b-a+1, M);
#ifdef DBG 
    cout << ans << endl;
#else
    ofstream fout("barn1.out"); if (!fout) return -2;
    fout << ans << endl;
#endif
    return 0;
}

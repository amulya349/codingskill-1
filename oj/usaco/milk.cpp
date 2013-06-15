/*
ID:myxjtu1
PROG:milk
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_PRICE = 1000;
int QoP[MAX_PRICE+1];

int solve(int N) {
    int ans(0), less(0);
    for (int i=0; i<=MAX_PRICE && N>0; ++i) {
        less = min(N, QoP[i]);
        ans += i*less, N -= less;
    }
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    if (!fin || !fout) return -1;
    int N, M; fin >> N >> M;
    int p,a;
    for (int i=0; i<M; ++i) {
        fin >> p >> a;
        QoP[p] += a;
    }
#ifdef DBG 
    cout << solve(N) << endl;
#else
    fout << solve(N) << endl;
#endif
    return 0;
}

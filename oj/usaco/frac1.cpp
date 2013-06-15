/*
ID:myxjtu1
PROG:frac1
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#ifdef DBG 
ostream & out = cout;
#else
ofstream fout("frac1.out");
ostream & out = fout;
#endif

struct frac {
    int n, d;
    frac(int _n, int _d) : n(_n), d(_d) {}
    void print() { out << n << "/" << d << endl; }
};

void solve(int n, frac a, frac b) {
    if (a.d+b.d > n) return;
    frac m(a.n+b.n, a.d+b.d);

    solve(n, a, m);
    m.print();
    solve(n, m, b);
}

int main(int argc, char * argv[]) {
    ifstream fin("frac1.in");
    if (!fin) return -1;
    int N; fin >> N;

    frac a(0,1), b(1,1);
    a.print();
    solve(N, a, b);
    b.print();
    return 0;
}

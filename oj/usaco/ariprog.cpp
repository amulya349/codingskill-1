/*
ID:myxjtu1
PROG:ariprog
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_M=250;
bool exist[2*MAX_M*MAX_M+1];
int  pq2[(MAX_M*MAX_M+MAX_M)/2]; 

struct Ari {
    int a, b, n;
    Ari(int _a, int _b) : a(_a), b(_b), n(2) {}
    bool operator<(const Ari & rhs) const { return b<rhs.b||(b==rhs.b&&a<rhs.a); }
};

int init(int M) {
    int m2[M+1]; 
    m2[0] = 0;
    for (int i=1; i<=M; ++i)
        m2[i] = m2[i-1]+2*i-1;
    for (int i=0; i<=M; ++i)
        for (int j=i; j<=M; ++j)
            exist[m2[i]+m2[j]] = true;
    const int M2=2*M*M;
    int count=0;
    for (int i=0; i<=M2; ++i) if (exist[i])
        pq2[count++] = i;
    return count;
}

void output(ostream &out, const vector<Ari> &ans) {
    const int LEN = ans.size();
    if (LEN==0) {
        out << "NONE" << endl;
    } else {
        for (int i=0; i<LEN; ++i)
            out << ans[i].a << " " << ans[i].b << endl;
    }
}

vector<Ari> solve(int num, int N) {
    vector<Ari> ans;
    for (int i=0; i+N<=num; ++i) {
        for (int j=i+1; j+N<=num+1; ++j) {
            Ari p(pq2[i], pq2[j]-pq2[i]);
            if (p.a+(N-1)*p.b>pq2[num-1]) break; // SUPER CUT 1 

            for (int next=p.a+p.b*p.n; p.n<N && exist[next]; next+=p.b) ++p.n;
            if (p.n == N) ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("ariprog.in");   if (!fin)  return -1;
    int N, M; fin >> N >> M; // have a try with 25&&250

    int num = init(M);
    vector<Ari> ans = solve(num, N);
#ifdef DBG
    output(cout, ans);
#else
    ofstream fout("ariprog.out"); if (!fout) return -2;
    output(fout, ans);
#endif
    return 0;
}

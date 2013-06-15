/*
ID:myxjtu1
PROG:milk2
LANG:C++
*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Intev {
    int first, second;
    Intev(int _first=0, int _second=0) : first(_first), second(_second) {}
    bool operator<(const Intev & rhs) const { return first<rhs.first; }
};

Intev solve(vector<Intev> &a) {
    const int LEN = a.size();
    sort(a.begin(), a.end());
    Intev ans(LEN==0?0:a[0].second-a[0].first, 0);
    for (int i=1, j=0; i<LEN; ++i) {
        if (a[j].second < a[i].first) {
            ans.second = max(ans.second, a[i].first-a[j].second);
            j = i;
        } else if (a[j].second < a[i].second) {
            a[j].second = a[i].second;
            ans.first = max(ans.first, a[j].second-a[j].first);
        }
    }
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("milk2.in"); if (!fin) return -1;
    size_t N; fin >> N;
    vector<Intev> a(N);
    for (size_t i=0; i<N; ++i) 
        fin >> a[i].first >> a[i].second;

    Intev ans = solve(a);
#ifdef DBG 
    cout << ans.first << " " << ans.second << endl;
#else
    ofstream fout("milk2.out"); if (!fout) return -2;
    fout << ans.first << " " << ans.second << endl;
#endif
    return 0;
}

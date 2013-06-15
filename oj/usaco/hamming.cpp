/*
ID:myxjtu1
PROG:hamming
LANG:C++
*/
#include <fstream>
#include <vector>
using namespace std;

ifstream cin("hamming.in");
ofstream cout("hamming.out");

bool diff(int a, int b, int D) {
    int c1 = 0;
    for (int c=a^b; c && c1<D; c=c&(c-1))
        ++c1;
    return c1==D;
}

vector<int> solve(int N, int B, int D) {
    int MAX=1;
    for (int i=0; i<B; ++i) MAX *= 2;

    vector<int> ans; ans.push_back(0);
    for (int c=1; c<MAX && ans.size()<N; ++c) {
        size_t j=0;
        for (; j<ans.size() && diff(ans[j],c,D); ++j);
        if (j == ans.size())
            ans.push_back(c);
    }
    return ans;
}

int main(int argc, char * argv[]) {
    int N,B,D; cin>>N>>B>>D;
    vector<int> ans = solve(N,B,D);

    cout << ans.at(0);
    const int LEN = ans.size();
    for (int i=1; i<LEN; ++i) {
        if (i%10==0) cout << endl << ans.at(i);
        else cout << " " << ans.at(i);
    }
    cout << endl;
    return 0;
}

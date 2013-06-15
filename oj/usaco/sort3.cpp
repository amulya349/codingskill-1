/*
ID:myxjtu1
PROG:sort3
LANG:C++
*/
#include <fstream>
using namespace std;
ifstream cin("sort3.in");
ofstream cout("sort3.out");
int count[4];

int helper(int & diff, int A, int B, const int * begin, const int * end) {
    int x=0;
    for (const int * r=begin; r!=end; ++r) if (*r != A) {
        ++diff;
        if (*r == B) ++x;
    }
    return x;
}

int solve(int a[], int N) {
    int ans=0;
    int c13 = helper(ans, 1, 3, &a[0], &a[count[1]]);
    int c31 = helper(ans, 3, 1, &a[count[1]+count[2]], &a[N]);
    return ans-min(c13,c31);
}

int main(int argc, char * argv[]) {
    int N; cin>>N;
    int a[N];
    for (int i=0; i<N; ++i) {
        cin >> a[i];
        ++count[a[i]];
    }
    cout << solve(a, N) << endl;
    return 0;
}

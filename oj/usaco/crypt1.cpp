/*
ID:myxjtu1
PROG:crypt1
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;
bool a[10];

bool isValid(int x) {
    if (x<10) return a[x];
    return isValid(x%10) && isValid(x/10);
}

int solve() {
    int ans = 0;
    for (int a=100; a<=999; ++a) {
        if (!isValid(a)) continue;
        for (int b=10; b<=99; ++b) {
            if (!isValid(b)) continue;
            int c=a*(b%10);
            if (c<100||c>999||!isValid(c)) continue;

            int d=a*(b/10);
            if (d<100||d>999||!isValid(d)) continue;

            int e=c+d*10;
            if (e<1000||e>9999||!isValid(e)) continue;
            
            ++ans;
        }
    }
    return ans;
}

int main(int argc, char * argv[]) {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    if (!fin || !fout) return -1;

    int N; fin >> N;
    int k;
    for (int i=0; i<N; ++i) {
        fin >> k;
        a[k] = true;
    }
#ifdef DBG 
    cout << solve() << endl;
#else
    fout << solve() << endl;
#endif
    return 0;
}

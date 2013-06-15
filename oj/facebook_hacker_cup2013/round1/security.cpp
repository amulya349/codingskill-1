#include <stdio.h>
#include <iostream>
using namespace std;

string solve(const string & k1, const string & k2, int m) {
}

int main(int argc, char * argv[]) {
    int T;
    scanf("%d\n", &T);
    for (int i=1; i<=T; ++i) {
        int m;
        scanf("%d\n", &m);
        string k1, k2;
        getline(cin, k1);
        getline(cin, k2);
        string ans = solve(k1, k2, m);
        cout << "Case #" << i << ": " << ans << endl;
    }
	return 0;
}

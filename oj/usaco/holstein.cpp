/*
ID:myxjtu1
PROG:holstein
LANG:C++
*/
#include <fstream>
#include <bitset>
#include <string.h>
using namespace std;

ifstream cin("holstein.in");
ofstream cout("holstein.out");
const int MAX_FEEDS = 15;
int V, vit[25], G, feed[MAX_FEEDS][25];

bitset<MAX_FEEDS> solve() {
    bitset<MAX_FEEDS> ans((1<<G)-1);
    for (int i=(1<<G)-2; i>=0; --i) {
        bitset<MAX_FEEDS> bit(i);
        if (ans.count() < bit.count()) continue;

        int eat[V]; memset(eat, 0, sizeof(eat));
        for (int b=0; b<G; ++b) if (bit[b])
            for (int j=0; j<V; ++j)
                eat[j] += feed[b][j];

        int f=0;
        for (; f<V && eat[f]>=vit[f]; ++f);
        if (f==V) ans = bit;
    }
    return ans;
}

int main(int argc, char * argv[]) {
    cin >> V;
    for (int i=0; i<V; ++i)
        cin >> vit[i];
    cin >> G;
    for (int i=0; i<G; ++i)
        for (int j=0; j<V; ++j)
            cin >> feed[i][j];

    bitset<MAX_FEEDS> ans = solve();

    cout << ans.count();
    for (int i=0; i<G; ++i) if (ans[i])
        cout << " " << i+1;
    cout << endl;
    return 0;
}

/*
ID:myxjtu1
PROG:clocks
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int TRANSNUM = 9;
const int UNIVERSE = 1024*1024/4; // 4^9
const string transstyle[TRANSNUM] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
#pragma pack(1)
char used[UNIVERSE][TRANSNUM];
#pragma pack()
int prev[UNIVERSE];
char way[UNIVERSE];

int transform(int a, int k) {
    for (int i=transstyle[k].size()-1; i>=0; --i) {
        int p = 16-(transstyle[k][i]-'A')*2;
        int test = (3<<p);
        if ((a & test) == test)
            a = a&(~test);
        else a = a+(1<<p);
    }
    return a;
}

vector<int> bfs(int c9) {
    for(deque<int> clocks(1, c9); clocks.size(); ) {
        for (size_t i=0; i<clocks.size(); ++i) {
            int c=clocks.front(); clocks.pop_front();
            if (c==0) {
                vector<int> ans(1, way[0]);
                for (int cp=prev[c]; cp!=c9; cp=prev[cp])
                    ans.push_back(way[cp]);
                return ans;
            }

            for (int j=0; j<TRANSNUM; ++j) {
                if (used[c][j]>=3) continue;

                int t=transform(c,j);
                bool visited=false;
                for (int r=0; r<TRANSNUM&&!visited; ++r) {
                    if (used[t][r]) visited = true;
                    else used[t][r] = used[c][r];
                }
                if (visited) continue;

                ++used[t][j];
                clocks.push_back(t);
                prev[t]=c, way[t]=j+1;
            }
        }
    }
    return vector<int>();
}

int main(int argc, char * argv[]) {
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");
    if (!fin || !fout) return -1;
    int c9=0;
    for (int i=0; i<9; ++i) {
        int c; fin >> c;
        c9 |= (c/3)%4;
        c9 <<= 2;
    }
    c9 >>= 2;
    vector<int> ans = bfs(c9);
#ifdef DBG 
    if (ans.size()>=1)                  cout << ans.back();
    for (int i=ans.size()-2; i>=0; --i) cout << " " << ans[i];
    cout << endl;
#else
    if (ans.size()>=1)                  fout << ans.back();
    for (int i=ans.size()-2; i>=0; --i) fout << " " << ans[i];
    fout << endl;
#endif
    return 0;
}

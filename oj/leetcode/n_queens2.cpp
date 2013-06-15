/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Follow up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>

class Solution {
    public:
        int totalNQueens(int n) {
            if ( n <= 0 ) return 0;
            int Q[n];
            memset(Q, 0, sizeof(Q));
            int total = 0;
            NQ(Q, n, 0, total);
            return total;
        }
    private:
        void NQ(int * Q, int n, int lev, int & rtotal) {
            if (lev >= n) {
                ++rtotal;
            } else {
                for (int i=1; i<=n; ++i) {
                    Q[lev] = i;
                    if (Valid(Q, lev))
                        NQ(Q, n, lev+1, rtotal);
                }
            }
            return;
        }

        bool Valid(int * Q, int lev) {
            for (int i=0; i<lev; ++i) {
                if (Q[i] == Q[lev] \
                        || Q[lev] - Q[i] == lev - i \
                        || Q[lev] - Q[i] == i - lev)
                    return false;
            }
            return true;
        }
};

int main(int argc, char * argv[]) {
    int N = 14;
    Solution solve;
    printf("%d Queens=%d\n", N, solve.totalNQueens(N));
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all 
 * numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int minPathSum(const vector<vector<int> > &grid) {
            int M = grid[0].size();
            int N = grid.size();
            int MAX = M>N?M:N;
            int S[MAX];
            S[0] = grid[0][0];

            for (int step=1; step<=M+N-2; ++step) {
                int x = step;
                if (x >= M) x = M-1;
                int y = step-x;

                for (; x>=0 && y<=N-1; --x,++y) {
                    if (x == step) {
                        S[x] = S[x-1]+grid[y][x];
                    } else if (x == 0) {
                        S[0] += grid[y][x];
                    } else {
                        if (S[x] < S[x-1])
                            S[x] += grid[y][x];
                        else
                            S[x] = S[x-1]+grid[y][x];
                    }
                }
            }
            return S[M-1];
        }
};

int main(int argc, char * argv[]) {
    Solution solve;

    vector<vector<int> > grid;
    int A[] = {1,2,5};
    grid.push_back(UIO<int>::in(A, sizeof(A)/sizeof(A[0])));
    int B[] = {3,2,1};
    grid.push_back(UIO<int>::in(B, sizeof(B)/sizeof(B[0])));
    cout << solve.minPathSum(grid) << endl;
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Follow up for "Unique Paths":
 *   Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *   An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *   [
 *     [0,0,0],
 *     [0,1,0],
 *     [0,0,0]
 *   ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(const vector<vector<int> > &obstacleGrid) {
            return uniqueImp(obstacleGrid, \
                    obstacleGrid.size()-1, \
                    obstacleGrid[0].size()-1);
        }

        int uniqueImp(const vector<vector<int> > & grid, int m, int n) {
            if (m <  0 || n <  0) return 0;
            if (m == 0 && n == 0) return !grid[0][0];
            return (grid[m][n] == 1)?0:uniqueImp(grid, m-1, n)+uniqueImp(grid, m, n-1);
        }
};

int main(int argc, char * argv[]) {
    vector<vector<int> > grid;
    int A[] = {0,0,0};
    grid.push_back(UIO<int>::in(A, sizeof(A)/sizeof(A[0])));
    int B[] = {0,1,0};
    grid.push_back(UIO<int>::in(B, sizeof(B)/sizeof(B[0])));
    int C[] = {0,0,0};
    grid.push_back(UIO<int>::in(C, sizeof(C)/sizeof(C[0])));

    Solution engine;
    printf("(%lu, %lu)=%d\n", grid.size(), grid[0].size(), engine.uniquePathsWithObstacles(grid));
    return 0;
}

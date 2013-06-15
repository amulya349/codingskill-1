/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * Bonus point if you are able to do this using only O(N) extra space, 
 * where N is the total number of rows in the triangle.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int minimumTotal(const vector<vector<int> > & triangle) {
            const int ROW = triangle.size();
            int sum[ROW];
            sum[0] = 0;
            for (int i=0; i<ROW; ++i) {
                const int COL = triangle[i].size();
                if (COL>=2)
                    sum[COL-1] = sum[COL-2]+triangle[i][COL-1];
                for (int j=COL-2; j>=1; --j) 
                    sum[j] = min(sum[j], sum[j-1])+triangle[i][j];
                sum[0] += triangle[i][0];
            }
            int ans = sum[0];
            for (int i=1; i<ROW; ++i)
                ans = min(ans, sum[i]);
            return ans;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

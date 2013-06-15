/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * 
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * -------------------------------------------------------------}}}*/
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            if (!matrix.size() || !matrix[0].size()) return;
            const int ROW = matrix.size();
            const int COL = matrix[0].size();

            // find the first line contain zero
            int zeroline = -1;
            for (int r=0; r<ROW && zeroline == -1; ++r) 
                for (int c=0; c<COL; ++c) if (matrix[r][c] == 0) {
                    zeroline = r;
                    break;
                }
            if (zeroline < 0) return;

            // save col-zero to zeroline && set zero
            for (int r=zeroline+1; r<ROW; ++r) {
                bool iszero = false;
                for (int c=0; c<COL; ++c) if (matrix[r][c] == 0) {
                    matrix[zeroline][c] = 0;
                    iszero = true;
                }
                if (iszero)
                    for (int c=0; c<COL; ++c) matrix[r][c] = 0;
            }

            // set col(saving in zeroline) to zero
            for (int c=0; c<COL; ++c) if (matrix[zeroline][c] == 0)
                for (int r=0; r<ROW; ++r)
                    matrix[r][c] = 0;
            else matrix[zeroline][c] = 0;
        }
};

int main(int argc, char * argv[]) {
    vector<vector<int> > res;
    int L1[] = {0,0,0,5};
    int L2[] = {4,3,1,4};
    int L3[] = {0,1,1,4};
    int L4[] = {1,2,1,3};
    int L5[] = {0,0,1,1};
    res.push_back(UIO<int>::in(L1, sizeof(L1)/sizeof(L1[0])));
    res.push_back(UIO<int>::in(L2, sizeof(L2)/sizeof(L2[0])));
    res.push_back(UIO<int>::in(L3, sizeof(L3)/sizeof(L3[0])));
    res.push_back(UIO<int>::in(L4, sizeof(L4)/sizeof(L4[0])));
    res.push_back(UIO<int>::in(L5, sizeof(L5)/sizeof(L5[0])));
    UIO<int>::pr(res);

    Solution solve;
    solve.setZeroes(res);

    cout<<"\nZerolize ==>\n";
    UIO<int>::pr(res);
    return 0;
}

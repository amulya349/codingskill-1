/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int> > &matrix, size_t lev=0) {
            size_t N = matrix.size();
            if (lev >= N/2) return;

            for (int i=lev, tmp; i<N-lev-1; ++i) {
                tmp = matrix[lev][i];
                matrix[lev][i]         = matrix[N-i-1][lev];
                matrix[N-i-1][lev]     = matrix[N-lev-1][N-i-1];
                matrix[N-lev-1][N-i-1] = matrix[i][N-lev-1];
                matrix[i][N-lev-1]     = tmp;
            }
            rotate(matrix, lev+1);
        }
};

int main(int argc, char * argv[]) {
    return 0;
}


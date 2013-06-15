/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * 
 * Consider the following matrix:
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 * -------------------------------------------------------------}}}*/
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            const int COL = matrix[0].size();
            if (matrix.size() == 0 || COL == 0 || matrix[0][0] > target || matrix[matrix.size()-1][COL-1] < target)
                return false;

            unsigned md;
            for (int lo=0,hi=matrix.size()-1; lo<=hi; ) {
                md = lo+(hi-lo)/2;
                if      (matrix[md][0] > target)     hi = md-1;
                else if (matrix[md][COL-1] < target) lo = md+1;
                else                                 break;
            }

            for (int lo=0,hi=COL-1; lo<=hi;) {
                unsigned x = lo+(hi-lo)/2;
                if      (matrix[md][x] == target) return true;
                else if (matrix[md][x] >  target) hi = x-1;
                else                              lo = x+1;
            }
            return false;
        }
};

int main(int argc, char * argv[]) {
    vector<vector<int> > matrix;
    int A[] = {1,3,5,7};
    matrix.push_back(UIO<int>::in(A, sizeof(A)/sizeof(A[0])));
    int B[] = {10,11,16,20};
    matrix.push_back(UIO<int>::in(B, sizeof(B)/sizeof(B[0])));
    int C[] = {23,30,34,50};
    matrix.push_back(UIO<int>::in(C, sizeof(C)/sizeof(C[0])));
    static Solution solve;
    if (solve.searchMatrix(matrix, 35))
        cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}

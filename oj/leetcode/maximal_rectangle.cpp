/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing all ones and return its area.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        /*
         * h: the value of height at positon x 
         * l: for each i in [l+1, x-1], h(i) >= h(x)
         * r: for each i in [x+1, r-1], h(i) >= h(x)
         * */
        struct ColDes {
            int h, l, r; 
        };

    public:
        int maximalRectangle(const vector<vector<char> > & matrix) {
            int ROW = matrix.size();
            int COL = matrix.at(0).size();
            ColDes cols[COL];
            memset(cols, 0, sizeof(cols));

            int curMax = 0;
            for (int i=0; i<ROW; ++i)
                maximalRectangleImp(matrix.at(i), cols, COL, curMax);

            return curMax;
        }

    private:
        /*
         * Here a row's time complex is O(n). explain:         
         *
         * on creating the left-s, while an element(x) added, it may spend 
         * k time compares, but the result looks like reducing 
         * k-1 elements between left[x] and x, so the time cost is O(n).
         * so as to the right-s.
         * */
        void maximalRectangleImp(const vector<char> & row, ColDes * cols, int COL, int & curMax) {
            int i, j;
            for (i=0; i<COL; ++i) {
                cols[i].h = (1+cols[i].h)*row[i];
                for (j=i-1; j>=0 && cols[i].h <= cols[j].h; j=cols[j].l);
                cols[i].l = j;
            }

            for (i=COL-1; i>=0; --i) {
                for (j=i+1; j<COL && cols[i].h <= cols[j].h; j=cols[j].r);
                cols[i].r = j;

                int t = cols[i].h*(cols[i].r-cols[i].l-1);
                if (curMax < t) curMax = t;
            }
        }
};

int main(int argc, char * argv[]) {
    vector<vector<char> > matrix;
    char rs1[] = {1,0,0,1,1,0,1,1};
    matrix.push_back(UIO<char>::in(rs1, sizeof(rs1)/sizeof(rs1[0])));
    char rs2[] = {1,0,0,0,0,1,0,0};
    matrix.push_back(UIO<char>::in(rs2, sizeof(rs2)/sizeof(rs2[0])));
    char rs3[] = {0,1,1,1,0,0,1,1};
    matrix.push_back(UIO<char>::in(rs3, sizeof(rs3)/sizeof(rs3[0])));
    char rs4[] = {0,0,0,1,0,0,0,1};
    matrix.push_back(UIO<char>::in(rs4, sizeof(rs4)/sizeof(rs4[0])));
    char rs5[] = {0,0,0,0,0,1,1,1};
    matrix.push_back(UIO<char>::in(rs5, sizeof(rs5)/sizeof(rs5[0])));

    Solution solve;
    printf("MaxArea=%d\n", solve.maximalRectangle(matrix));
    return 0;
}

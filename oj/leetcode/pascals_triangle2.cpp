/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 * -------------------------------------------------------------}}}*/
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            int line[rowIndex+1];
            for (int r=0; r<=rowIndex; ++r) {
                line[r] = 1;
                for (int j=r-1; j>=1; --j) 
                    line[j] += line[j-1];
            }

            vector<int> ans;
            for (int i=0; i<=rowIndex; ++i)
                ans.push_back(line[i]);
            return std::move(ans);
        }
};

void honglei(int numRows) {
    static Solution solve;
    vector<int> ans = solve.getRow(numRows);
    UIO<int>::pr(ans);
}

int main(int argc, char * argv[]) {
    honglei(5);
    return 0;
}

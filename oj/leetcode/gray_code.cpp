/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the code, 
 * print the sequence of gray code. A gray code sequence must begin with 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ans;
            ans.push_back(0);
            for (int i=1; i<=n; ++i) {
                int h = 1<<(i-1);
                for (int j=ans.size()-1; j>=0; --j) 
                    ans.push_back(h+ans[j]);
            }
            return std::move(ans);
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    UIO<int>::pr(solve.grayCode(1));
    UIO<int>::pr(solve.grayCode(3));
    return 0;
}

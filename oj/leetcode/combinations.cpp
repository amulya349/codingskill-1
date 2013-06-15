/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/io.h"

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > ans;
            vector<int> a;
            combine_imp(ans, a, n, k);
            return std::move(ans);
        }
    private:
        void combine_imp(vector<vector<int> > & rans, vector<int> & a, int n, size_t k) {
            if (n+a.size() < k) return;
            if (a.size()  == k) {
                rans.push_back(a);
                return;
            }
            combine_imp(rans, a, n-1, k);
            a.push_back(n);
            combine_imp(rans, a, n-1, k);
            a.pop_back();
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    vector<vector<int> > ret = solve.combine(5, 3);
    UIO<int>::pr(ret);
    return 0;
}

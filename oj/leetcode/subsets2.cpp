/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 *
 * For example, If S = [1,2,2], a solution is:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <algorithm>
#include "../../util/io.h"
using namespace std;

// http://discuss.leetcode.com/questions/265/subsets-ii/758
class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            sort(S.begin(), S.end());
            vector<int> once;
            vector<vector<int> > ans;
            subsetsWithDupHelper(S, 0, once, ans);
            return std::move(ans);
        }

        void subsetsWithDupHelper(const vector<int> &s, size_t begin, vector<int> &once, vector<vector<int> > &ans) {
            ans.push_back(once);

            for (size_t i=begin; i<s.size(); ++i) {
                if (i != begin && s[i] == s[i-1]) continue; // 重复的最多放一遍

                once.push_back(s[i]);
                subsetsWithDupHelper(s, i+1, once, ans);
                once.pop_back();
            }
        }
};

int main(int argc, char * argv[]) {
    int ipt[] = {1, 2, 2, 4};
    vector<int> S(ipt, ipt+sizeof(ipt)/sizeof(ipt[0]));
    Solution solve;
    vector<vector<int> > ans = solve.subsetsWithDup(S);
    UIO<int>::pr(ans);
    return 0;
}

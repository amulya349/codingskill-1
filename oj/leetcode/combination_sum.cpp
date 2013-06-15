/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 *     [7] 
 *     [2, 2, 3] 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > res;
            if (candidates.size()) {
                sort(candidates.begin(), candidates.end());
                vector<int> e;
                combin_imp(res, e, candidates, 0, target);
            }
            return std::move(res);
        }
    private:
        void combin_imp(vector<vector<int> > &res, vector<int> e,\
                const vector<int> & candidates, size_t from, int target) {
            if (from >= candidates.size()) return;

            if (candidates[from] < target) {
                combin_imp(res, e, candidates, from+1, target);
                e.push_back(candidates[from]);
                combin_imp(res, e, candidates, from, target-candidates[from]);
            } else if (candidates[from] == target) {
                e.push_back(target);
                res.push_back(e);
            }
        }
};

int main(int argc, char * argv[]) {
    Solution solve;

    int A[] = {8,7,4,3,11,123};
    vector<int> candidates = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    vector<vector<int> > res = solve.combinationSum(candidates, 11);
    UIO<int>::pr(res);
    return 0;
}

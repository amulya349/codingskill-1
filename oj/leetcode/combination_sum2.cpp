/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a collection of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            vector<vector<int> > rvv;
            if (num.size() > 0) {
                sort(num.begin(), num.end());
                combinationSum2Imp(rvv, vector<int>(), target, num, 0);
            }
            return std::move(rvv);
        }
    private:
        void combinationSum2Imp(vector<vector<int> > & rvv, vector<int> e, \
                int target, const vector<int> & num, size_t from) {
            if (target == 0) {
                rvv.push_back(e);
                return;
            }
            if (target < 0 || from >= num.size()) return;

            size_t duplicates = 1;
            while (num[from] == num[from+duplicates]) ++duplicates;
            for (size_t i=0; i<=duplicates; ++i) {
                combinationSum2Imp(rvv, e, target, num, from+duplicates);

                target -= num[from];
                if (target < 0) break;
                e.push_back(num[from]);
            }
        }
};

int main(int argc, char * argv[]) {
    Solution solve;

    // int A[] = {2,1,3,1,4};
     int A[] = {4,1,1,4,4,4,4,2,3,5};
    vector<int> candidates = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    vector<vector<int> > v = solve.combinationSum2(candidates, 10);
    printf("result:\n");
    UIO<int>::pr(v);
    return 0;
}

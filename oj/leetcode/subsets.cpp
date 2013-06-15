/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  Given a set of distinct integers, S, return all possible subsets.
 *  Note:
 *  Elements in a subset must be in non-descending order.
 *  The solution set must not contain duplicate subsets.
 *
 *  For example,
 *  If S = [1,2,3], a solution is:
 *  [
 *     [3],
 *     [1],
 *     [2],
 *     [1,2,3],
 *     [1,3],
 *     [2,3],
 *     [1,2],
 *     []
 *  ]
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > subsets(const vector<int> &S) {
            vector<vector<int> > ans;
            subsetHelper(ans, vector<int>(), S, 0);
            return std::move(ans);
        }
    private:
        void subsetHelper(vector<vector<int> > & ans, vector<int> e, const vector<int> & S, size_t index) {
            if (index >= S.size()) {
                ans.push_back(e);
                return;
            }

            subsetHelper(ans, e, S, index+1);
            e.push_back(S[index]);
            subsetHelper(ans, e, S, index+1);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {3,2,1,4};
    vector<int> v = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    UIO<int>::pr(v);
    printf("subsets following:\n");

    static Solution solve;
    vector<vector<int> > subs = solve.subsets(v);
    UIO<int>::pr(subs);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 *   [1,2,3] have the following permutations:
 *   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > ans;
            vector<int> tmp;
            char used[num.size()];
            memset(used, 0, sizeof(used));
            permute_imp(ans, used, num, tmp);
            return std::move(ans);
        }
    private:
        void permute_imp(vector<vector<int> > &ans, \
                char * used, \
                const vector<int> & num, \
                vector<int> & tmp) {
            if (tmp.size() == num.size()) {
                ans.push_back(tmp);
            } else {
                for (size_t i=0; i<num.size(); ++i) {
                    if (used[i])
                        continue;

                    tmp.push_back(num[i]);
                    used[i] = 1;
                    permute_imp(ans, used, num, tmp);
                    used[i] = 0;
                    tmp.pop_back();
                }
            }
            return;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {-1, 1, 0};
    vector<int> num = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    vector<vector<int> > res = solve.permute(num);
    UIO<int>::pr(res);
    return 0;
}

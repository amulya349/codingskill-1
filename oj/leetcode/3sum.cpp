/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array S of n integers, are there elements a, b, c in S such that \
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 *   (-1, 0, 1)
 *   (-1, -1, 2)
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        // O(N^2)
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > res;
            sort(num.begin(), num.end()); // nlog(n)
            for (size_t k=0; k<=num.size()-3; ++k) { // n 
                int i = k+1;
                int j = num.size()-1;
                while (i < j) { // n*n
                    int sum = num[i]+num[j]+num[k];
                    if (sum == 0) {
                        int A[] = {num[k], num[i], num[j]};
                        vector<int> e = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
                        res.push_back(e);

                        while (i<j && num[i] == num[i+1]) ++i;
                        while (i<j && num[j] == num[j-1]) --j;
                        ++i, --j;
                    } else if (sum > 0) {
                        while (i<j && num[j] == num[j-1]) --j;
                        --j;
                    } else {
                        while (i<j && num[i] == num[i+1]) ++i;
                        ++i;
                    }
                }
                while (k<num.size() && num[k] == num[k+1]) ++k;
            }
            return std::move(res);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {-1,0,1,1,2,-1,4};
    vector<int> num = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    vector<vector<int> > res = solve.threeSum(num);
    UIO<int>::pr(res);
    return 0;
}

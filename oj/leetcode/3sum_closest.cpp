/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array S of n integers, find three integers in S such that \
 * the sum is closest to a given number, target. 
 * Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int closest = num[0]+num[1]+num[2];
            const int nsize = num.size();
            sort(num.begin(), num.end());

            for (int i=0; i<=nsize-3; ++i) {
                for (int j(i+1), k(nsize-1); j<k; ) {
                    int sum = num[i]+num[j]+num[k];
                    if (abs(sum-target) < abs(closest-target))
                        closest = sum;
                    
                    if      (sum == target) return sum;
                    else if (sum >  target) --k;
                    else                    ++j;
                }
            }
            return closest;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;

    int A[] = {1,1,1,1};
    vector<int> num = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    int closest = solve.threeSumClosest(num, -100);
    printf("%d\n", closest);

    int B[] = {-1,2,1,-4};
    num = UIO<int>::in(B, sizeof(B)/sizeof(B[0]));
    closest = solve.threeSumClosest(num, -100);
    printf("%d\n", closest);
    return 0;
}

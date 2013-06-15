/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array S of n integers, are there elements a, b, c, \
 * and d in S such that a + b + c + d = target? \
 * Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 1 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * 2 The solution set must not contain duplicate quadruplets.
 * 
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 * -------------------------------------------------------------}}}*/
/*
 * Solution 1 (代码实现的解法) :
 *  排序, 然后依次锚定两个数字, 再尝试其后的两个数字, 看4个数字的和是否目标
 *  因此时间复杂度是O(n^3), 空间复杂度O(1)
 *
 * Solution 2:
 *  两两求和得到n(n-1)/2个数字, 并对其排序sorting.
 *  然后对这些和求2sum, 额外的, 需要判定组成满足条件的这4个数, 是否有重叠(hash). 
 *  因此, 时间复杂度为O(n^2)+O(sorting) = O(n^2), 在Note中解释
 *        空间复杂度为O(n^2)+O(hash extra)
 * [Note]
 *  tricky的是, 这里的sorting可以做到线性时间: 可以用杨氏矩阵的方式来实现
 * */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > res;
            if (num.size()<4) return std::move(res);

            sort(num.begin(), num.end());
            for (size_t l=0; l<=num.size()-4; ++l) {
                for (size_t r=l+1; r<=num.size()-3; ++r) {
                    int i = r+1;
                    int j = num.size()-1;
                    int sum;
                    while (i < j) {
                        sum = num[i]+num[j]+num[l]+num[r];
                        if (sum == target) {
                            int A[] = {num[l], num[r], num[i], num[j]};
                            vector<int> e = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
                            res.push_back(e);

                            while (i<j && num[i] == num[i+1]) ++i;
                            while (i<j && num[j] == num[j-1]) --j;
                            ++i, --j;
                        } else if (sum > target) {
                            while (num[j] == num[j-1] && i<j) --j;
                            --j;
                        } else {
                            while (num[i] == num[i+1] && i<j) ++i;
                            ++i;
                        }
                    }
                    while ( num[r] == num[r+1] && r<=num.size()-3 ) ++r;
                }
                while ( num[l] == num[l+1] && l<=num.size()-4 ) ++l;
            }
            return std::move(res);
        }
};

int main(int argc, char * argv[]) {
    vector<int> num;
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    for (int i=0; i<100; ++i)
        num.push_back(i*i-i);

    num.push_back(-1);
    num.push_back(4);

    Solution solve;
    vector<vector<int> > res = solve.fourSum(num, 34);
    UIO<int>::pr(res);
    return 0;
}

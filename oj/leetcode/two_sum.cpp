/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array of integers, find two numbers such that \
 * they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that \
 * they add up to the target, where index1 must be less than index2. 
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * -------------------------------------------------------------}}}*/
/* {{{ Solution 1(代码解法):
 *  排序, 两头逼近. 时间复杂度O(nlgn), 空间为常数
 *
 * Solution 2:
 *  入hash并保存了元素的出现次数, 然后对元素A[i]判定target-A[i]是否在hash中,
 *  并且依据 A[i] == double(target/2)来决定是否存在解
 *  时间复杂度O(n), 空间需要hash的耗费
 * }}}*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> ori = numbers;
            sort(numbers.begin(), numbers.end());
            size_t i=0;
            size_t j=numbers.size()-1;
            int sum;
            vector<int>res;
            bool iok = true;
            bool jok = true;
            while(i<j) {
                sum=numbers[i]+numbers[j];
                if(sum == target) {
                    for (size_t k=0;k<ori.size();++k) {
                        if (ori[k]==numbers[i] && iok) {
                            res.push_back(k+1);
                            iok = false;
                            continue;
                        }
                        if (ori[k] == numbers[j] && jok) {
                            res.push_back(k+1);
                            jok = false;
                            continue;
                        }
                    }
                    return std::move(res);
                } else if(sum<target) {
                    while(numbers[i]==numbers[i+1] && i<j) ++i;
                    ++i;
                } else {
                    while(numbers[j]==numbers[j-1] && i<j) --j;
                    --j;
                }
            }
            return std::move(res);
        }
};

int main(int argc, char * argv[]) {
    int A[] ={-1,0,1,1,2,-1,4};
    vector<int> num = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    vector<int> res = solve.twoSum(num, 6);
    UIO<int>::pr(res);

    return 0;
}

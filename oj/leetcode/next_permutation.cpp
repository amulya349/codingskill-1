/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Implement next permutation, which rearranges numbers into the \
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as \
 * the lowest possible order (ie, sorted in ascending order).
 * 
 * NOTE: The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and \
 * its corresponding outputs are in the right-hand column.
 *   1,2,3 → 1,3,2
 *   3,2,1 → 1,2,3
 *   1,1,5 → 1,5,1
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

/* ie: 6 4 7 5 5 2
 * 1 寻找G点. 从右向左的递增序列一直走, 直到 7->4
 * 2 交换. 找到比4大的最小值(可以二分) 此处为5(第几个呢?)
 * 3 部分倒转. 从右向左看的递增序列倒序排列即可
 * */
class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            const int SIZE = num.size();
            if (SIZE <= 1)
                return;

            int rev = SIZE-1;
            while (--rev>=0 && num[rev] >= num[rev+1]);

            if (rev >= 0) {
                int rightless = SIZE;
                while (--rightless > rev && num[rightless] <= num[rev]);
                if (rightless > rev && num[rightless] > num[rev]) {
                    int tmp = num[rightless];
                    num[rightless] = num[rev];
                    num[rev] = tmp;
                }
            }
            reverse_ves(num, rev+1, SIZE-1);
        }
    private:
        void reverse_ves(vector<int> & num, int begin, int end) {
            for (; begin < end; ++begin,--end) {
                int tmp    = num[begin];
                num[begin] = num[end];
                num[end]   = tmp;
            }
        }
};

void TellSolution(int * nums, size_t n, int round=1) {
    if (n == 0)
        return;
    vector<int> num = UIO<int>::in(nums, n);
    if (round == 1)
        printf("next permuation is:\n");
    else if (round > 1)
        printf("next permuations are:\n");

    static Solution solve;
    while (--round >= 0) {
        solve.nextPermutation(num);
        UIO<int>::pr(num);
    }
}

int main(int argc, char * argv[]) {
    int n1[] = {6, 4, 7, 5, 5, 2};
    TellSolution(n1, sizeof(n1)/sizeof(n1[0]));
    int n2[] = {3, 2, 1, 0};
    TellSolution(n2, sizeof(n2)/sizeof(n2[0]), 27);
    int n3[] = {1, 1, 5};
    TellSolution(n3, sizeof(n3)/sizeof(n3[0]), 8);
    return 0;
}

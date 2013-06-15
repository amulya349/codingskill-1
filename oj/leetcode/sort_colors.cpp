/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array with n objects colored red, white or blue, \
 * sort them so that objects of the same color are adjacent, \
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent \
 * the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, \
 * then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        /*
         * e0 最后一个0的位置
         * b2 第一个2的位置
         * i walker遍历
         * */
        void sortColors(int A[], int n) {
            int e0=-1, b2=n;
            for (int i=0; i<b2; ++i) switch (A[i]) {
                case 0:
                    if (i > e0+1) A[e0+1]=0, A[i]=1;
                    ++e0;
                    break;
                case 2:
                    if (i < b2-1) A[i]=A[b2-1], A[b2-1]=2;
                    --b2, --i;
                    break;
            }
        }
};

void test(int A[], int n) {
    if (!A || n<=0) return;

    printf("[%d", A[0]);
    for (int i=1; i<n; ++i)
        printf(", %d", A[i]);
    printf("], by one pass sort, then:\n");

    static Solution solve;
    solve.sortColors(A, n);

    printf("[%d", A[0]);
    for (int i=1; i<n; ++i)
        printf(", %d", A[i]);
    printf("]\n\n");
}

int main(int argc, char * argv[]) {
    int n1[] = {0, 2, 2, 1, 2, 1, 0};
    test(n1, sizeof(n1)/sizeof(n1[0]));
    int n2[] = {0, 1, 0};
    test(n2, sizeof(n2)/sizeof(n2[0]));
    int n3[] = {0};
    test(n3, sizeof(n3)/sizeof(n3[0]));
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            int uniq = (n<=1?n:2);
            for (int i=2; i<n; ++i) {
                if (A[i] != A[uniq-1] || A[i] != A[uniq-2]) 
                    A[uniq++] = A[i];
            }
            return uniq;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,1,1,2,2,3};
    Solution solve;
    int distin = solve.removeDuplicates(A, sizeof(A)/sizeof(A[0]));
    printf("%d",A[0]);
    for (int i=1; i<distin; ++i)
        printf(",%d", A[i]);
    printf("\n");
    return 0;
}

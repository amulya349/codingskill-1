/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. 
 * It doesn't matter what you leave beyond the new length.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int tail = 0;
            for (int i=0; i<n; ++i) if (A[i] != elem)
                A[tail++] = A[i];
            return tail;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    int A[] = {1, 2, -3, 1, 2, 0};
    const int LEN = solve.removeElement(A, sizeof(A)/sizeof(A[0]), -4);
    for (int i=0; i<LEN; ++i)
        printf("%d\t", A[i]);
    printf("\n");
    return 0;
}

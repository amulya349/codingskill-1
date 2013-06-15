/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a sorted array, remove the duplicates in place such that \
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, \
 * you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            int total = (n<=0?0:1);
            for (int i=1; i<n; ++i) {
                if (A[i] != A[total-1]) 
                    A[total++] = A[i];
            }
            return total;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}
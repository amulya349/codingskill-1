/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
class Solution {
    public:
        int search(int A[], int n, int target) {
            return -1;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,3,1,1,1};
    Solution solve;
    printf("%d\n", solve.search(A, sizeof(A)/sizeof(A[0]), 3));
    return 0;
}

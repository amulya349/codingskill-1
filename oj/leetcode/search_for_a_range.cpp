/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Search in Rotated Sorted Array
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. 
 * If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int search(int A[], int n, int target) {
            if (A && n>0) {
                int l = 1;
                int h = n-1;
                int m;
                if (target == A[0]) {
                    return 0;
                }
                else if (target > A[0]) {
                    while (l <= h) {
                        m = l+(h-l)/2;
                        if (A[m] == target) {
                            return m;
                        } else if (A[m] > target) {
                            h = m-1;
                        } else {
                            if (A[m] > A[0])
                                l=m+1;
                            else h=m-1;
                        }
                    }
                } else {
                    while (l <= h) {
                        m = l+(h-l)/2;
                        if (A[m] == target) {
                            return m;
                        } else if (A[m] < target) {
                            l = m+1;
                        } else {
                            if (A[m] > A[0])
                                l=m+1;
                            else h=m-1;
                        }
                    }
                }
            }
            return -1;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    Solution solve;
    int x = solve.search(A, sizeof(A)/sizeof(A[0]), 1);
    printf("at %d\n", x);

    x = solve.search(A, sizeof(A)/sizeof(A[0]), 100);
    printf("at %d\n", x);
    return 0;
}

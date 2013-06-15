/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. 
 * If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        /* 一个更简单的考虑是：判定哪一半是排序好的，目标是否在其中*/
        int search(int A[], int n, int target) {
            for (int i=0, j=n-1; i<=j;) {
                int m=i+(j-i)/2;
                if (A[m] == target) {
                    return m;
                } else if (A[m] > target) {
                    if (A[m] <= A[j])        j = m-1;
                    else if (target >= A[i]) j = m-1;
                    else                     i = m+1;
                } else {
                    if (target <= A[j])    i = m+1;
                    else if (A[m] >= A[i]) i = m+1;
                    else                   j = m-1;
                }
            }
            return -1;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int findMedianSortedArrays(int A[], int m, int B[], int n) {
            int k = m+(n-m-1)/2;
            return m > n ? getKthSortedArrays(n, &A[k-n], B) : getKthSortedArrays(m, A, &B[k-m]);
        }

        int getKthSortedArrays(int k, int * A, int * B) {
            if (k <= 1) return A[0] < B[0] ? A[0] : B[0];

            int mid = (k-1)/2;
            if      (A[mid] == B[mid]) return A[mid];
            else if (A[mid] >  B[mid]) return getKthSortedArrays(k-mid-1, A, &B[mid+1]);
            else                       return getKthSortedArrays(k-mid-1, &A[mid+1], B);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {-3, 1, 2}; //, 5, 6, 11
    int B[] = {1, 3, 4};//, 5, 9, 10, 11, 31, 33
    Solution solve;
    int median = solve.findMedianSortedArrays(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0]));
    printf("%d\n", median);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int searchInsert(const int A[], int n, int target) {
            if (A[0] >=  target) return 0;
            if (A[n-1] < target) return n;

            for (int l=0,h=n-1,m; l<=h; ) {
                m = l+(h-l)/2;
                if (A[m] == target) return m;
                if (A[m] >  target) {
                    if (m>=1 && A[m-1]<target)  return m;
                    else                        h = m-1;
                } else {
                    if (m+1<n && A[m+1]>target) return m+1;
                    else                        l = m+1;
                }
            }
        }
};

void honglei(const int A[], int N, int target) {
    if (N>0)
        printf("[%d", A[0]);
    for (int i=1; i<N; ++i)
        printf(",%d", A[i]);
    static Solution solve;
    int si = solve.searchInsert(A, N, target);
    printf("], %d - %d\n", target, si);
}

int main(int argc, char * argv[]) {
    int A[] = {1, 3, 5, 6};
    honglei(A, sizeof(A)/sizeof(A[0]), 4);
    int B[] = {1, 3, 5};
    honglei(B, sizeof(B)/sizeof(B[0]), 4);
    return 0;
}


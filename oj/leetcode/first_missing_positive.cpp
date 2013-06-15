/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <iostream>

class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            for (int i=0; i<n; ++i) {
                while (A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
                    std::swap(A[i], A[A[i]-1]);
            }

            int ans;
            for (ans=0; ans<n && A[ans]==ans+1; ++ans);
            return ans+1;
        }

        // containing 0
        int firstMissingPositive2(int A[], int n) {
            for (int i=0; i<n; ++i) {
                while (A[i] >= 0 && A[i] < n && A[A[i]] != A[i])
                    std::swap(A[i], A[A[i]]);
            }

            int ans;
            for (ans=0; ans<n && A[ans]==ans; ++ans);
            return ans;
        }
};

int main(int argc, char * argv[]) {
    // int A[] = {2,1};
    // int A[] = {3,4,-1,0,2};
    int A[] = {1, 2, 0};
    Solution solve;
    printf("%d\n", solve.firstMissingPositive(A, sizeof(A)/sizeof(A[0])));
    return 0;
}

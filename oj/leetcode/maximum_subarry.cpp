/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Find the contiguous subarray within an array (containing at least one number) 
 * which has the largest sum.
 *
 *  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 *  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 *  More practice:
 *  If you have figured out the O(n) solution, 
 *  try coding another solution using the divide and conquer approach,
 *  which is more subtle
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include <limits.h>

class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int sum = A[0];
            for (int i=0, local=0; i<n; ++i) {
                local += A[i];
                if (local > sum) sum = local;
                if (local < 0)   local = 0;
            }
            return sum;
        }

    public: // NlogN
        int maxSubArray2(const int * A, int b, int e) {
            if (b == e) return A[b];

            int m = b+(e-b)/2;
            int mleft  = maxSubArray2(A, b, m);
            int mright = maxSubArray2(A, m+1, e);
            int mcross = arraysum(A, b, m, e);
            return mleft>mright?(mleft>mcross?mleft:mcross):(mright>mcross?mright:mcross);
        }

        int arraysum(const int * A, int b, int m, int e) {
            int l = A[m];
            for (int i=m, s=0; i>=b; --i) {
                s += A[i];
                if (l < s) l = s;
            }
            if (l <= 0)
                return INT_MIN;

            int r = A[m+1];
            for (int i=m+1, s=0; i<=e; ++i) {
                s += A[i];
                if (r < s) r = s;
            }
            return l+r;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solve;
    int maxsum = solve.maxSubArray(A, sizeof(A)/sizeof(A[0]));
    // int maxsum = solve.maxSubArray2(A, 0, sizeof(A)/sizeof(A[0])-1);
    printf("max sum of contiguous subarray=%d\n", maxsum);
    return 0;
}


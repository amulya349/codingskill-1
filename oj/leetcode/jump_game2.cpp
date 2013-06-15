/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 * The minimum number of jumps to reach the last index is 2. 
 * (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * -------------------------------------------------------------}}}*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        int jump(int A[], int n) {
            for (int i=0,jumps=0,step=0,maxreach=0; \
                    i<n; ++jumps,step=maxreach) {
                for (; i<=step; ++i) { // within a step
                    maxreach = max(A[i]+i, maxreach);
                    if (maxreach >= n-1) 
                        return jumps+(n<=1?0:1);
                }
            }
            return n<=1?0:-1;
        }

        /*{{{ dynamic programming method*/
        int jump_dp_imp(int A[], int n) {
            if (n <= 1 || !A)
                return 0;
            int ** solves = new int*[n];
            solves[0] = new int[n*n];
            for (int i=1; i<n; ++i)
                solves[i] = solves[i-1]+n;
            // init +++
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j)
                    solves[i][j] = n;
            }
            for (int i=0; i<n-1; ++i) {
                for (int j=1; j<=A[i]; ++j)
                    solves[i][i+j] = 1;
            }
            // init ---

            for (int jump=2; jump<=n-1; ++jump) {
                int max_index = n-1-jump;
                for (int i=0; i<=max_index; ++i) {
                    int min=solves[i][i+jump];
                    int candidate;
                    for (int x=i+1; x<=i+jump-1; ++x) {
                        candidate = solves[i][x]+solves[x][i+jump];
                        if (candidate < n && candidate < min)
                            min = candidate;
                    }
                    solves[i][i+jump] = min;
                }
            }

            int res = solves[0][n-1];
            delete [] solves[0];
            delete [] solves;
            return res;
        }
        /*}}}*/
};

int main(int argc, char * argv[]) {
    int A[] = {2,3,1,1,4};
    // int A[] = {2,3,1,2,0,1};

    Solution solve;
    cout << solve.jump(A, sizeof(A)/sizeof(A[0])) << endl;
    return 0;
}

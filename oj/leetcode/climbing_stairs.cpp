/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        // there is O(logN) method by using matrix-method
        int climbStairs(int n) {
            if (n <= 1) return 1;
            int f0(1), f1(1), f2;
            for (int i=1; i<n; ++i) {
                f2 = f0+f1;
                f0 = f1;
                f1 = f2;
            }
            return f2;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    printf("%d\n", solve.climbStairs(3));
    return 0;
}


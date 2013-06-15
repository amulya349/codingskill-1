/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int numTrees(int n) {
            if (n < 0) return -1;

            int A[n+1];
            A[0] = 1;
            for (int i=1; i<=n; ++i) {
                A[i] = 0;
                for (int j=i-1; j>=0; --j) 
                    A[i] += A[j]*A[i-1-j];
            }
            return A[n];
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    int n = 3;
    printf("%d => %d\n", n, solve.numTrees(n));
    return 0;
}

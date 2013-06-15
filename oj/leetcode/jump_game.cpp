/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array of non-negative integers, \
 * you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * 
 * For example:
 *   A = [2,3,1,1,4], return true.
 *   A = [3,2,1,0,4], return false.
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool canJump(int A[], int n) {
            for (int i=0,maxreach=0; i<=maxreach; ++i) {
                maxreach = max(A[i]+i, maxreach);
                if (maxreach >= n-1)
                    return true;
            }
            return false;
        }
};

int main(int argc, char * argv[]) {
    //   int A[] = {2,3,1,1,4};
    int A[] = {3,2,1,0,4};

    Solution solve;
    if (solve.canJump(A, sizeof(A)/sizeof(A[0])))
        cout << "Yeap!" << endl;
    else cout << "Nop..." << endl;
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, 
 * such that the container contains the most water.
 * 
 * Note: You may not slant the container.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/io.h"

class Solution {
    public:
        int maxArea(const vector<int> &height) { 
            int mc = 0, a = 0, b = height.size()-1;
            for (int i=a, j=b; i<=j; ) {
                if (height[a] < height[b]) {
                    if (height[a] < height[i]) a = i;
                    ++i;
                } else {
                    if (height[b] < height[j]) b = j;
                    --j;
                }
                mc = max(min(height[a], height[b])*(b-a), mc);
            }
            return mc;
        }

        // int maxArea(const vector<int> &height) {
        //     int a = 0, b = height.size()-1;
        //     int mc = max(min(height[a], height[b])*(b-a), 0);
        //     for (int i=a, j=b; i<=j; ) {
        //         if (height[a] < height[b]) {
        //             if (height[a] < height[i]) {
        //                 a = i;
        //                 mc = max(min(height[a], height[b])*(b-a), mc);
        //             }
        //             ++i;
        //         } else {
        //             if (height[b] < height[j]) {
        //                 b = j;
        //                 mc = max(min(height[a], height[b])*(b-a), mc);
        //             };
        //             --j;
        //         }
        //     }
        //     return mc;
        // }
};

int main(int argc, char * argv[]) {
    int A[] = {5,2,12,1,5,3,4,11,9,4}; 
    const vector<int> height = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    int mA = solve.maxArea(height);
    printf("%d\n", mA);
    return 0;
}

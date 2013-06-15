/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given n non-negative integers representing an elevation map where the width \
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * For example, 
 *     Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int trap(int A[], int n) {
            int traps(0), hl(0), hr(n-1);
            while (hl < hr) {
                if (A[hl] <= A[hr]) {
                    int i = hl+1;
                    for (; i<hr; ++i) {
                        if (A[i] <= A[hl]) {
                            traps += A[hl]-A[i];
                        } else {
                            hl = i;
                            break;
                        }
                    }
                    if ( i == hr )
                        return traps;
                } else {
                    int i = hr-1;
                    for (; i>hl; --i) {
                        if (A[i] <= A[hr]) {
                            traps += A[hr]-A[i];
                        } else {
                            hr = i;
                            break;
                        }
                    }
                    if ( i == hl )
                        return traps;
                }
            }
            return traps;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solve;
    printf("trapping net=%d\n", solve.trap(A, sizeof(A)/sizeof(A[0])));
    return 0;
}

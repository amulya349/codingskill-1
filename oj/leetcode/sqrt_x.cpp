/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <assert.h>

class Solution {
    public:
        int sqrt(int x) {
            assert(x>=0);
            for (int begin=0,end=x; begin<=end; ) {
                int mid  = begin + (end-begin)/2;
                int mid2 = mid * mid;

                if (mid2 > x) {
                    end = mid-1;
                } else {
                    if (mid2+2*mid+1 > x) return mid;
                    else                  begin = mid+1;
                }
            }
        }

        float sqrt_niudun(float n) {
            assert(n>=0);
            float a=2;
            for(int i=0; i<15; ++i)
                a=(a+(n/a))/2.0;
            return a;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    for (int i=0; i<=17; ++i)
        printf("sqrt(%d)=%d\n", i, solve.sqrt(i));
    return 0;
}

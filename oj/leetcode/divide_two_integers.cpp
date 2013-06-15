/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Divide two integers without using multiplication, division and mod operator.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int divide(int a, int b) { 
            assert(b != 0);
            if (b == a)       return 1;
            if (b == INT_MIN) return 0;

            bool neg = (a>0 && b<0) || (a<0 && b>0);
            int sub = 0;
            if (b < 0) b = -b;
            if (a == INT_MIN) {
                a += b;
                sub = 1;
            }
            if (a < 0) a = -a;

            int x = b, d = 0;
            while ((x<<1) > 0 && x <= a) x <<= 1;
            while (x >= b) {
                if (a >= x) {
                    a -= x;
                    ++d;
                }
                x >>= 1;
                if (x >= b)
                    d <<= 1;
            }
            return neg ? -sub-d : sub+d;
        }
};

void honglei(int dividend, int divisor) {
    static Solution solve;
    int d = solve.divide(dividend, divisor);
    printf("%d/%d=%d\n", dividend, divisor, d);
}

int main(int argc, char * argv[]) {
    honglei(25, 3);
    // honglei(4, 0);
    // honglei(20, 20);
    honglei(2147483647, 1);
    honglei(-2147483648, 1);
    // honglei(-2147483648, 1);
    return 0;
}

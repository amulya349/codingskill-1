/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * implement pow(x, n).
 * double pow(double x, int x)
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        double pow(double x, int n) {
            if (x == 0) return n==0?1:0;
            if (n <  0) return powhelper(1/x, -n);
            else        return powhelper(x, n);
        }

        double powhelper(double x, unsigned n) {
            double t = (n==0 ? 1 : powhelper(x, n/2));
            return (n&1) ? x*t*t : t*t;
        }
};

int main(int argc, char * argv[]) {
    double x = 0.9999;
    int n = -2147483647;
    Solution solve;
    printf("%lf^%d=%lf\n", x, n, solve.pow(x, n));
    return 0;
}

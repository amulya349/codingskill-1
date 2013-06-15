/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. \
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <stdint.h>

int cpf(int m, int n) {
    if ( m <= 1 || n <= 1)
        return 1;
    if ( m < n ) {
        int tmp = n;
        n = m;
        m = tmp;
    }

    int64_t cpf = 1;
    int div = 2;
    for ( int i = 1; i <= n-1; ++i) {
        cpf *= (m+i-1);
        while (div <= n-1) {
            if (cpf % div == 0) {
                cpf /= div;
                ++ div;
            } else {
                break;
            }
        }
    }

    return cpf;
}

int main(int argc, char * argv[]) {
    int i = 3;
    int j = 3;
    printf("C(%d, %d)=%d\n", i, j, cpf(i, j));
    return 0;
}

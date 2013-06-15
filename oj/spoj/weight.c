/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  You are given N integers, A[1] to A[N]. You have to assign weights to these integers such that their weighted sum is maximized. The weights should satisfy the following conditions :
 *  
 *  Each weight should be an positive integer.
 *  W[1] = 1
 *  W[i] should be in the range [2, W[i-1] + 1] for i > 1
 *  Weighted sum is defined as S = A[1] * W[1] + A[2] * W[2] + ... + A[N] * W[N]
 *  
 *  Input
 *  
 *  There are multiple test cases. 
 *  First line contains the number of test cases 
 *  Each test case consists of a single line containing N. 
 *  This is followed by N lines, each containing A[i]
 *  
 *  Output
 *  
 *  For each test case, output one line - the maximum weighted sum.
 *  
 *  Example
 *  
 *  Input:
 *  1 
 *  4 
 *  1 
 *  2 
 *  3 
 *  -4
 *  Output:
 *  6
 *  Explanation
 *  The weights are 1,2,3,2
 *  
 *  Constraints
 *  
 *  N <= 10^6 
 *  | A[i] | <= 10^6 
 *  Total number of test cases is around 10.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 1000006

int ass[MAX_SIZE];

int main(int argc, char * argv[]) {
    unsigned rounds;
    scanf("%u", &rounds);
    while (rounds--) {
        int lines;
        scanf("%d", &lines);
        if (lines <= 0)
            continue;
        int * an = (int *)malloc(lines*sizeof(int));
        int i;
        for (i=0; i<lines; ++i)
            scanf("%d", &an[i]);

        int asses, revsum;
        asses = revsum = 0;
        for (i=lines-1; i>=1; --i) {
            revsum += an[i];
            if (revsum < 0) {
                ass[asses++] = i;
                revsum = 0;
            }
        }

        int assi = asses-1;
        int needass = 1;
        if (assi < 0)
            needass = 0;

        int a = 1;
        int64_t maxsum = an[0];
        for (i=1; i<lines; ++i) {
            if (needass && i == ass[assi]) {
                --assi;
                if (assi < 0)
                    needass = 0;
                a = 2;
            }
            else {
                ++a;
            }
            maxsum += a*an[i];
        }
        printf("%ld\n", maxsum);

        free(an);
    }
    return 0;
}

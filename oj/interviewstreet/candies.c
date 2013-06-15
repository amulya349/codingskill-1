/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Alice is a kindergarden teacher. 
 * She wants to give some candies to the children in her class.  
 * All the children sit in a line and each  of them  has a rating score
 * according to his or her usual performance.  
 * Alice wants to give at least 1 candy for each child.
 * Children get jealous of their immediate neighbors, 
 * so if two children sit next to each other then the one with
 * the higher rating must get more candies. 
 * Alice wants to save money, 
 * so she wants to minimize the total number of candies.
 *  
 * Input
 * The first line of the input is an integer N, 
 * the number of children in Alice's class. 
 * Each of the following N lines contains an integer 
 * indicates the rating of each child.
 * 
 * Ouput
 * Output a single line containing the minimum number of candies Alice must give.
 * 
 * Sample Input
 * 3
 * 1
 * 2
 * 2
 * Sample Ouput
 * 4
 * 
 * Explanation
 *  The number of candies Alice must give are 1, 2 and 1.
 * Constraints:
 *  N and the rating  of each child are no larger than 10^5.
 *
 *  WAWAWAWAWAWAWAWAWAWAWAWAWAWA
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>

int LeastCost(int * rate, int size) {
    int rasing[size];
    memset(rasing, 0, sizeof(rasing));

    int i = 1;
    while (i<size && rate[i] == rate[0]) ++i;
    if (i == size)
        return size;

    int ri = 0;
    int rasingsize = 0;
    rasing[rasingsize++] = ri;

    while (i<size) {
        if (rate[i] > rate[i-1]) {
            while (i<size) { 
                if (rate[i] > rate[i-1]) {
                    ++i, ++ri;
                }
                else if (rate[i] == rate[i-1]) {
                    ++i;
                    rasing[rasingsize++] = ri++;
                    while (i<size && rate[i] == rate[i-1]) ++i;
                    if (i>=size || rate[i] > rate[i-1])
                        rasing[rasingsize++] = ri++;
                }
                else {
                    break;
                }
            }
            rasing[rasingsize++] = ri;
        }
        else { // if (rate[i] < rate[i-1])
            while (i<size) {
                if (rate[i] < rate[i-1]) {
                    ++i, ++ ri;
                }
                else if (rate[i] == rate[i-1]) {
                    ++i;
                    rasing[rasingsize++] = ri;
                    while (i<size && rate[i] == rate[i-1]) ++i;
                    if (i>=size || rate[i] < rate[i-1])
                        rasing[rasingsize++] = ++ri;
                }
                else {
                    break;
                }
            }
            rasing[rasingsize++] = ri;
        }
    }

    int rasindex, cost;
    rasindex = 0, cost = size;
    if (rate[1] <= rate[0]) {
        cost += (rasing[1]+1)*rasing[1]/2;
        ++rasindex;
    }

    int rounds = (rasingsize-rasindex-1)/2;
    int d1, d2, r;
    for (r=0; r<rounds; ++r) {
        d1 = rasing[rasindex+r*2+1] - rasing[rasindex+2*r];
        d2 = rasing[rasindex+2*r+2] - rasing[rasindex+r*2+1];
        if (d1 > d2)
            cost += d1*(d1+1)/2+d2*(d2-1)/2;
        else
            cost += d2*(d2+1)/2+d1*(d1-1)/2;
    }
    if (!((rasingsize-rasindex) & 1)) {
        d1 = rasing[rasingsize-1] - rasing[rasingsize-2];
        cost += d1*(d1+1)/2;
    }

    return cost;
}

int main(int argc, char * argv[]) {
    int N;
    scanf("%d", &N);
    if (N <= 0) {
        return -1;
    }
    else if (N == 1) {
        printf("%u", 1);
        return 0;
    }

    int rate[N];
    int i;
    for (i=0; i<N; ++i)
        scanf("%d", &rate[i]);

    int lc = LeastCost(rate, sizeof(rate)/sizeof(rate[0]));
    printf("%d", lc);
    return 0;
}

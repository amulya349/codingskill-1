/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Say you have an array for which the ith element is the price of a given stock on day i.  
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> peaks(int * prices, int LEN) {
    vector<int> peaks;
    bool climbing = true;
    for (int i=1; i<LEN; ++i) {
        if (prices[i] < prices[i-1]) {
            if (climbing) {
                climbing = false;
                peaks.push_back(i-1);
            }
        }
        else if (prices[i] > prices[i-1]) {
            if (!climbing) climbing = true;
        }
    }
    if (LEN > 0 && climbing) peaks.push_back(LEN-1);
    return peaks;
}

void tell_peaks(int * prices, int LEN) {
    if (LEN <= 0)
        return;
    printf("%d", prices[0]);
    for (int i=1; i<LEN; ++i)
        printf(",%d", prices[i]);
    vector<int> ret = peaks(prices, LEN);
    int RETLEN = ret.size();
    if (RETLEN > 0)
        printf("\npeaks[%d", prices[ret[0]]);
    for (int i=1; i<RETLEN; ++i)
        printf(",%d", prices[ret[i]]);
    printf("]\n\n");
}

int main(int argc, char * argv[]) {
    int A0[] = {1,1};
    tell_peaks(A0, sizeof(A0)/sizeof(A0[0]));
    int A1[] = {1,1, 1,1,1,1};
    tell_peaks(A1, sizeof(A1)/sizeof(A1[0]));
    int A2[] = {1,5,3,2,7,6,11,4,4,8};
    tell_peaks(A2, sizeof(A2)/sizeof(A2[0]));
    int A3[] = {4,1,3,5,7,8,1,110,3,0};
    tell_peaks(A3, sizeof(A3)/sizeof(A3[0]));
    return 0;
}

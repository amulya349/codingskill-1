/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. 
 * You may complete as many transactions as you like 
 * (ie, buy one and sell one share of the stock multiple times). 
 *
 * However, you may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again). 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int maxProfit(const vector<int> &prices) {
            int ans = 0;
            for (size_t i=1; i<prices.size(); ++i)
                ans += max(0, prices[i]-prices[i-1]);
            return ans;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    int A[] = {1,2,4,2,5,7,2,4,9,0,9};
    vector<int> v = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    int max = solve.maxProfit(v);
    UIO<int>::pr(v);
    printf("MaxProfit = %d\n", max);
    return 0;
}

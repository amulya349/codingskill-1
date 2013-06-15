/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int maxProfit(const vector<int> &prices) {
            int ans = 0;
            for (int i=prices.size()-1, maxprice=0; i>=0; --i) {
                maxprice = max(maxprice, prices[i]);
                ans = max(ans, maxprice-prices[i]);
            }
            return ans;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,4,2,5,7,2,4,9,0,9};
    vector<int> v = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    int ans = solve.maxProfit(v);
    UIO<int>::pr(v);
    printf("MaxProfit = %d\n", ans);
    return 0;
}

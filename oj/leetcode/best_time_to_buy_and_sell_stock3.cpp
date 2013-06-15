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
#include <limits.h>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        int maxProfit(const vector<int> &prices) {
            const int LEN = prices.size();
            if (LEN < 2) return 0;

            vector<int> monotone_de; // monotone decreasing queue
            monotone_de.push_back(0);
            for (int i=1; i<LEN; ++i) {
                if (prices[i] < prices[monotone_de.back()])
                    monotone_de.push_back(i);
            }

            int prf2(0), prf_all(0), right_peak(0); // in fact, right_peak is an monotone increasing queue from back
            for (int sell1=LEN-1; sell1>=1; --sell1) {
                while (sell1 <= monotone_de.back()) monotone_de.pop_back();
                int prf = prf2+prices[sell1]-prices[monotone_de.back()];
                if (prf_all < prf) prf_all = prf;
                if (right_peak < prices[sell1]) {
                    right_peak = prices[sell1]; 
                } else {
                    prf = right_peak-prices[sell1];
                    if (prf2 < prf) prf2 = prf;
                }
            }
            return prf_all;
        }

        /* patrick9-294 :
         * 和一次买入卖出思想差不多, 相当于使用了一个隐式滚动数组, 只把空间简化
         *   a/b: 第一次买入/卖出时的最大利润 (a肯定是负数) 
         *   c/d: 第二次买入/卖出时的最大利润 
         */
        int maxProfit2(const vector<int> &prices) {
            int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
            for (size_t i=0; i<prices.size(); ++i) {
                d = ((c != INT_MIN && c+prices[i] > d) ? c+prices[i] : d);
                c = ((b != INT_MIN && b-prices[i] > c) ? b-prices[i] : c);
                b = ((a != INT_MIN && a+prices[i] > b) ? a+prices[i] : b);
                a = ((0-prices[i] > a) ? 0-prices[i] : a);
            }
            return max(max(d,b), 0);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,4,2,5,7,2,4,9,0,9};
    vector<int> v = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    // int max = solve.maxProfit(v);
    int max = solve.maxProfit2(v);
    UIO<int>::pr(v);
    printf("MaxProfit = %d\n", max);
    return 0;
}

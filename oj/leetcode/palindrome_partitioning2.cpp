/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * -------------------------------------------------------------}}}*/
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        int minCut(const string & s) {
            const int LEN = s.size();
            bool palindrome[LEN][LEN];
            memset(palindrome, 0, sizeof(palindrome));
            int dp[LEN];
            for (int i=LEN-1; i>=0; --i) {
                dp[i] = (i==LEN-1?0:1+dp[i+1]);
                for (int j=i; j<LEN; ++j) {
                    if (!(s[i] == s[j] && (i+2>=j || palindrome[i+1][j-1]))) continue;
                    palindrome[i][j] = true;
                    dp[i] = min(j==LEN-1?0:1+dp[j+1], dp[i]);
                }
            }
            return dp[0];
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    printf("%d\n", solve.minCut("aaabbaaaa")); // expecting 1

    return 0;
}

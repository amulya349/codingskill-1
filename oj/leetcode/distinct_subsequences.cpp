/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string S and a string T, \
 * count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original \
 * string by deleting some (can be none) of the characters without disturbing \
 * the relative positions of the remaining characters. 
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 *  S = "rabbbit", T = "rabbit"
 * Return 3.
 * -------------------------------------------------------------}}}*/
#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
    public:
        int numDistinct(const string & S, const string & T) {
            int M = S.length();
            int N = T.length();
            if (M < N || (M == N && S != T)) return 0;

            int dp[1+M]; // auto roll array
            dp[0] = 0;
            for (int j=0; j<=M-N; ++j) {
                if (S[j] == T[0])   dp[j+1] = dp[j]+1;
                else                dp[j+1] = dp[j];
            }

            for (int i=1; i<N; ++i) {
                int keep = dp[i];
                dp[i] = 0;
                for (int j=i; j<M; ++j) { // j>=i : up-triangle 
                    int tmp = dp[j+1];
                    if (S[j] == T[i])   dp[j+1] = dp[j]+keep;
                    else                dp[j+1] = dp[j];
                    keep = tmp;
                }
            }

            return dp[M];
        }
};

void honglei(const string & s, const string & t) {
    static Solution solve;
    int c = solve.numDistinct(s, t);
    cout << s << "[" << t << "] = " << c << endl;
}

int main(int argc, char * argv[]) {
    honglei("anacondastreetracecar", "contra");
    honglei("aacaacca", "ca");
    honglei("aaaa", "aaaa");
    honglei("aaaa", "aaaaa");

    return 0;
}

/*
 * as LCS problem, define dp[m][n] is the numDistinct of S[1,m] with T[1,n], then
 *            / dp[m-1][n] + dp[m-1][n-1], if S[m] == T[n]  
 * dp[m][n] =| 
 *            \ dp[m-1][n], otherwise
 * */

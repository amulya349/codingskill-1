/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * Below is one possible representation of s1 = "great":
 *     great
 *    /     \
 *   gr     eat
 *  / \     / \
 * g   r   e  at
 *            / \
 *           a   t
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *     rgeat                
 *    /     \
 *   rg     eat
 *  / \     / \
 * r   g   e  at
 *            / \
 *           a   t    
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *     rgtae
 *    /     \
 *   rg     tae
 *  / \     / \
 * r   g   ta  e
 *        / \
 *       t   a
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <assert.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class Solution {
    public:
        // another soluton based k-len minimum presentation is on the document stars5.doc
        bool isScramble(const string & s1, const string & s2) {
            const int LEN = s1.size();
            if (s2.size() != LEN) return false;

            bool dp[LEN][LEN][LEN+1];
            memset(dp, 0, sizeof(dp));
            for (int k=1; k<=LEN; ++k) 
                for (int i=LEN-k; i>=0; --i) 
                    for (int j=LEN-k; j>=0; --j) {
                        if (k==1) {
                            dp[i][j][k] = (s1[i] == s2[j]);
                        } else {
                            for (int a=1; a<=k-1 && !dp[i][j][k]; ++a) 
                                dp[i][j][k] = ((dp[i][j][a] && dp[i+a][j+a][k-a]) || (dp[i][j+k-a][a] && dp[i+a][j][k-a]));
                        }
                    }
            return dp[0][0][LEN];
        }
};

void honglei(const string &s1, const string s2) {
    static Solution solve;
    bool isscramble = solve.isScramble(s1, s2);
    if (isscramble)
        cout << s1 << ", " << s2 << "\tYES!" << endl;
    else cout << s1 << ", " << s2 << "\tNOP!" << endl;
}

int main(int argc, char * argv[]) {
    honglei("rgeat", "great");
    honglei("rgtae", "great");
    honglei("abcd", "dbac");
    honglei("abcd", "dbca");
    honglei("abcd", "dcab");
    honglei("abcd", "dcba");
    honglei("dcba", "abcd");
    honglei("abcd", "bdac");
    honglei("bdac", "abcd");
    honglei("abcd", "cadb");
    honglei("cadb", "abcd");
    honglei("abcdd", "dbdac");
    return 0;
}

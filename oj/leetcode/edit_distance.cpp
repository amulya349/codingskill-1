/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  Given two words word1 and word2, find the minimum number of steps required \
 *  to convert word1 to word2. (each operation is counted as 1 step.)
 *
 *  You have the following 3 operations permitted on a word:
 *  a) Insert a character
 *  b) Delete a character
 *  c) Replace a character
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        int minDistance(const string & s, const string & t) {
            int L1 = s.size();
            int L2 = t.size();
            int md[L2+1][L1+1];
            for (int i=0; i<=L1; ++i) md[0][i] = i;
            for (int j=1; j<=L2; ++j) md[j][0] = j;

            for (int i=1; i<=L1; ++i) 
                for (int j=1; j<=L2; ++j) 
                    md[j][i] = min3(md[j-1][i]+1, md[j][i-1]+1, md[j-1][i-1]+(s[i-1]==t[j-1]?0:1));
            return md[L2][L1];
        }
        int min3(int a, int b, int c) {
            int x = a>b?b:a;
            return x>c?c:x;
        }
};

int main(int argc, char * argv[]) {
    string s1("ab");
    string s2("ba");

    Solution solve;
    int md = solve.minDistance(s1, s2);
    printf("%d\n", md);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * 
 * For example,
 *     Given:
 *     s1 = "aabcc",
 *     s2 = "dbbca",
 * 
 *     When s3 = "aadbbcbcac", return true.
 *     When s3 = "aadbbbaccc", return false
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        bool isInterleave(const string & s1, const string & s2, const string & s3) {
            return isInterleave_recursion_imp(s1.c_str(), s2.c_str(), s3.c_str());
            // return isInterleave_dp_imp(s1, s2, s3);
        }
    private:
        bool isInterleave_recursion_imp(const char * s1, const char * s2, const char * s3) {
            if (*s3 && (*s1 || *s2)) {
                if (*s3 != *s1 && *s3 != *s2)
                    return false;

                bool res = false;
                if (*s3 == *s1)
                    res = isInterleave_recursion_imp(s1+1, s2, s3+1);
                if (!res && *s3 == *s2)
                    res = isInterleave_recursion_imp(s1, s2+1, s3+1);
                return res;
            } else {
                return true;
            }
        }
    private:
        bool isInterleave_dp_imp(const string & x, const string & y, const string & z) {
            /* C[i, j] // X[i] interleaving Y[j] to Z[i+j]
             *     = true                       if i==0 && j==0
             *     = false                      if X(i)!=Z(i+j) && Y(j)!=Z(i+j)
             *     = C[i-1, j]                  if X(i)==Z(i+j) && Y(j)!=Z(i+j)
             *     = C[i, j-1]                  if X(i)!=Z(i+j) && Y(j)==Z(i+j)
             *     = C[i-1, j] || C[i, j-1]     if X(i)==Z(i+j) && Y(j)==Z(i+j)
             *
             * Finally, return the result C[n-1, m-1]
             * The time complexity is clearly O(n*m) since there are 
             * n*m subproblems each of which is solved in constant time. 
             * Finally, the c[i, j] matrix can be computed in row major order.
             * */
            return true; 
        }
};

void honglei(const string & s1, const string & s2, const string & s3) {
    static Solution solve;
    printf("(%s) mixed with (%s) => (%s) ? ", s1.c_str(), s2.c_str(), s3.c_str());
    if (solve.isInterleave(s1, s2, s3))
        printf("yes!\n");
    else printf("no!!\n");
}

int main(int argc, char * argv[]) {
    string s1("aa");
    string s2("ab");
    honglei(s1, s2, "aaba");
    honglei(s1, s2, "abaa");
    return 0;
}

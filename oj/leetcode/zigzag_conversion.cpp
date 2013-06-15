/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(const string & text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        string convert(const string & s, int nRows) {
            if (nRows <= 1) return s;
            const int LEN = s.size();
            const int ROUND = 2*(nRows-1);

            char ans[LEN+1];
            for (int i=0, k=0; i<=nRows-1; ++i) {
                for (int j=i; j<LEN; j+=ROUND) {
                    ans[k++] = s[j];
                    if (i>0 && i<nRows-1 && j+ROUND-2*i<LEN)
                        ans[k++] = s[j+ROUND-2*i];
                }
            }
            ans[LEN] = 0;
            return ans;
        }
};

void honglei(const string & s, int nRows) {
    Solution solve;
    string ans = solve.convert(s, nRows);
    printf("zigzag(%s, %d) => %s\n", s.c_str(), nRows, ans.c_str());
}

int main(int argc, char * argv[]) {
    honglei("ABCD", 3); // "PINALSIGYAHRPI" 
    return 0;
}

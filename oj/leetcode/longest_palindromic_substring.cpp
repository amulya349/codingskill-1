/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string S, find the longest palindromic substring in S. \
 * You may assume that the maximum length of S is 1000, \
 * and there exists one unique longest palindromic substring.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int LEN = s.size();
            if (LEN == 0)
                return "";

            int max_len = 1;
            int max_start = 0;

            const char * ps = s.c_str();
            int odd1, even2;
            for (int i=1; i<LEN; ++i) {
                odd1 = 1+walker(ps, i-1, i+1);
                even2 = walker(ps, i-1, i);
                if (odd1 > even2) {
                    if (max_len < odd1) {
                        max_len = odd1;
                        max_start = i-odd1/2;
                    }
                } else {
                    if (max_len < even2) {
                        max_len = even2;
                        max_start = i-even2/2;
                    }
                }
            }
            return s.substr(max_start, max_len);
        }

        int walker(const char * ps, int l, int r) {
            int len = 0;
            for (; l>=0 && ps[l] == ps[r]; --l, ++r)
                len += 2;
            return len;
        }
};

int main(int argc, char * argv[]) {
    string s("ccd");
    Solution solve;
    cout << solve.longestPalindrome(s) << endl;
    return 0;
}

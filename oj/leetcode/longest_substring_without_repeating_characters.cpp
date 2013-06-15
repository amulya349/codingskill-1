/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  Given a string, find the length of the longest substring without repeating characters. 
 *
 *  For example
 *  the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 *  For "bbbbb" the longest substring is "b", with the length of 1.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(const string & s) {
            int geo[256];
            for (int i=sizeof(geo)/sizeof(geo[0])-1; i>=0; --i)
                geo[i]=-1;

            int b(0), ans(0), LEN(s.size());
            for (int i=0; i<LEN; ++i) {
                if (geo[s[i]-'0'] >= b) { 
                    ans = max(ans, i-b);
                    b = geo[s[i]-'0']+1;
                }
                geo[s[i]-'0'] = i;
            }
            return max(ans, LEN-b);
        }
};

void honglei(const string & s) {
    static Solution solve;
    int length = solve.lengthOfLongestSubstring(s);
    printf("%s => %d\n", s.size()?s.c_str():"null", length);
}

int main(int argc, char * argv[]) {
    honglei("a");
    honglei("aa");
    honglei("ab");
    honglei("abcd");
    honglei("abbabababa"); // 2
    return 0;
}

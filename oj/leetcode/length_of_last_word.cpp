/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string s consists of upper/lower-case alphabets and empty space \
 * characters ' ', return the length of last word in the string.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * If the last word does not exist, return 0.
 * 
 * For example: Given s = "Hello World", return 5.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        int lengthOfLastWord(const char * s) {
            if (!s) return 0;

            int len = 0;
            for ( ; *s; ++s) if (*s != ' ') {
                if (len == 0 || s[-1] == ' ') len = 1;
                else                          ++len;
            }
            return len;
        }
};

void honglei(const char * s) {
    static Solution solve;
    int lastwl = solve.lengthOfLastWord(s);
    printf("%s => %d\n", s, lastwl);
}

int main(int argc, char * argv[]) {
    honglei(" ");
    honglei("hello world ");
    return 0;
}

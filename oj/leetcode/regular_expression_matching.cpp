/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * The function prototype should be: bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * isMatch("aaa", "ab*ac*a") → true
 * isMatch("aaa", "ab*a*c*a") → true
 * isMatch("aaca", "ab*a*c*a") → true
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // http://leetcode.com/2011/09/regular-expression-matching.html
            assert(s && p);
            if (*p == '\0')    return *s == 0;
            if (*(p+1) != '*') return isEq(*s, *p) ? isMatch(s+1, p+1):false;

            for (; isEq(*s, *p); ++s) 
                if (isMatch(s, p+2)) return true;
            return isMatch(s, p+2);
        }
        bool isEq(char a, char b) {
            return a == b || (b == '.' && a != 0);
        }
};

void honglei(const char * s, const char * p) {
    static Solution solve;
    printf("isMatch(\"%s\", \"%s\") - %s\n", s, p, solve.isMatch(s, p)?"true":"false");
}

int main(int argc, char * argv[]) {
    honglei("aaa", "aaaa");
    honglei("aa", "a*");
    return 0;
}

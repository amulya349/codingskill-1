/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  Implement strStr().
 *
 *  Returns a pointer to the first occurrence of needle in haystack,
 *  or null if needle is not part of haystack.
 * -------------------------------------------------------------}}}*/

#include <stdio.h>

class Solution {
    public:
        /* KMP-Implement at ../practice/kmp.cpp for large case */
        const char *strStr(const char *haystack, const char *needle) {
            if (*needle == '\0') return haystack;

            while (*haystack) {
                int i=0;
                while (needle[i] && haystack[i] == needle[i]) ++i;
                if (needle[i] == '\0')
                    return haystack;
                ++haystack;
            }
            return NULL;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    const char * h = "abccd";
    const char * n = "cc";
    const char * ss = solve.strStr(h, n);
    printf("%s\n", ss);
    return 0;
}


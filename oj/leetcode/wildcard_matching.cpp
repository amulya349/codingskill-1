/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char * str, const char * pat) 
 * Some examples:
 *
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        bool isMatch(const char * s, const char * p) {
            // assert(s && p);
            if (*s == 0) {
                while (*p == '*') ++p;
                return *p == 0;
            }
            if (*p == '*')
                return isMatch(s+1,p) || isMatch(s,p+1);
            else return (*p=='?'||*p==*s) ? isMatch(s+1,p+1) : false;        
        }

        /*{{{ isMatch2 comments
         * Solution @ http://blog.sina.com.cn/s/blog_60b5450101016nmp.html
         *  从头开始对str[]和pat[]进行循环,遇到str[]的结尾结束.对pat进行分析:
         *  1 *pat == '?' || *pat == *str
         *      继续循环
         *
         *  2 *pat == '*'
         *      我们把到目前为止的结果设置为true, 然后记录下来当前的位置.
         *      若*pat的下一位是'\0', 返回true.
         *      若*pat下一位不是'\0', 就不把str和pat都往后走一位，然后开始比较,
         *  这里注意只要记住前一个'*'的位置, 而不用记住前面所有'*'的位置即可,
         *  因为啊, '*'是可以随便匹配的.<<<<这是代码逻辑的核心>>>>
         *
         *  3 其他情况 (不匹配)
         *      回到pat前一个'*'的位置, pat从这个位置开始比较
         **/
        bool isMatch2(const char *str, const char *pat) {
            const char *s, *p;
            bool exist_star = false;
LOOPSTART:
            for (s=str, p=pat; *s; ++s,++p) {
                switch (*p) {
                    case '?': 
                        break;
                    case '*':
                        exist_star = true, str = s, pat = p+1;  
                        if (!*pat) 
                            return true;
                        goto LOOPSTART;
                    default:
                        if (*s != *p) {
                            if (!exist_star)
                                return false;
                            ++str; // * 湮灭不匹配
                            goto LOOPSTART;
                        }
                        break;
                }
            }
            while (*p == '*') ++p;
            return (!*p);
        }
        /*}}}*/
};

int main(int argc, char * argv[]) {
    Solution solve;
    const char * s = "ab";
    const char * p = "?*";
    if (solve.isMatch(s, p))
        printf("%s\nMATCH\n%s\n", s, p);
    else printf("%s\nUNMATCH\n%s\n", s, p);
    return 0;
}

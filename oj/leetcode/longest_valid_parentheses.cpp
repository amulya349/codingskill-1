/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string containing just the characters '(' and ')', \
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", \
 * which has length = 2.
 *
 * Another example is ")()())", where the longest valid \
 * parentheses substring is "()()", which has length = 4.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
    public:
        int longestValidParentheses(const string & s) {
            int MAXLEN(s.size()), ans(0);
            stack<int> lefts;
            for (int i=0, begin=MAXLEN; i<MAXLEN; ++i) { // begin是保存()(())情况的开头
                if (s[i] == '(') {
                    lefts.push(i);
                } else if (lefts.empty()) {
                    begin = MAXLEN;  // ()) invalid former
                } else { // SUPER_MARK begin&lefts' brilliant
                    begin = min(lefts.top(), begin);
                    lefts.pop();
                    ans = max(ans, lefts.empty()?i-begin+1:i-lefts.top());
                }
            }
            return ans;
        }

        int longestValidParentheses_longway2008(const string & s) {
            int ans = 0;
            stack<int> toMatch; // 上一个待匹配的位置
            toMatch.push(-1);   // 其实就是上一种做法中的begin
            for (int i=0; i<(int)s.size(); ++i) {
                if (s[i] == '(') {
                    toMatch.push(i);
                    continue;
                } 

                toMatch.pop();
                if (toMatch.size()==0) toMatch.push(i); // SUPER_MARK 2
                else ans = max(ans,   i-toMatch.top());
            }
            return ans;
        }
};

void honglei(const string & s) {
    static Solution solve;
    int longest = solve.longestValidParentheses_longway2008(s);
    printf("%s -> %d\n", s.c_str(), longest);
}

int main(int argc, char * argv[]) {
    honglei("()(()");
    honglei("()()");
    honglei("(())"); // -1|0|1|
    return 0;
}

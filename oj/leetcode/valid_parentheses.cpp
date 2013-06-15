/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string containing just the characters :
 *      '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, 
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

class Solution {
    public:
        bool isValid(const string & s) {
            const size_t SIZE = s.size();
            if (SIZE == 0)
                return true;
            else if (SIZE % 2)
                return false;

            char push[SIZE];
            memset(push, 0, sizeof(push));

            int u = 0;
            for (size_t i=0; i<SIZE; ++i) {
                switch (s[i]) {
                    case '(':
                    case '[':
                    case '{':
                        push[u++] = s[i];
                        break;
                    case ')':
                        if (push[u-1] != '(')
                            return false;
                        --u;
                        break;
                    case ']':
                        if (push[u-1] != '[')
                            return false;
                        --u;
                        break;
                    case '}':
                        if (push[u-1] != '{')
                            return false;
                        --u;
                        break;
                    default:
                        return false;
                        break;
                }
            }
            return u == 0;
        }
};

void test(const string & s) {
    printf("%s : ", s.c_str());
    static Solution solve;
    if (solve.isValid(s))
        printf("good\n");
    else printf("bad!\n");
}

int main(int argc, char * argv[]) {
    test("[]"); // true
    test("[({(())}[()])]"); // true
    test("[({((dfs))}[()])]");// false
    test("[({(()})[()])]");// false
    return 0;
}

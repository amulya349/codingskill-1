/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if (n <= 0) return "";
            string content = "1";
            for (int i=2; i<=n; ++i) {
                string s = content;
                content = "";
                int LEN = s.size();
                int count = 1;
                for (int j=1; j<LEN; ++j) {
                    if (s[j] == s[j-1]) {
                        ++count;
                    } else {
                        content += count+'0';
                        content += s[j-1];
                        count = 1;
                    }
                }
                content += count+'0';
                content += s[LEN-1];
            }
            return content;
        }
};

void honglei(int n) {
    static Solution solve;
    string content = solve.countAndSay(n);
    printf("%d. %s\n", n, content.c_str());
}

int main(int argc, char * argv[]) {
    honglei(2);
    honglei(3);
    honglei(4);
    honglei(5);
    honglei(6);
    honglei(7);
    honglei(8);
    honglei(9);
    honglei(30);
    return 0;
}
/* follow up: 最大重复的个数是多少？如何证明
 * 如果出现4个连续的x，如xxxx
 * 则其必然尝试描述x个x，x个x；或者a个x，x个x，x个b这两种情况
 * 分别可以合并为：2x个x，(a+x)个x，x个b. 因此最多会出现3个连续相同
 */

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * [google面试题] 给定一个字符串，返回只包含两种字符的子串的最大长度
 *
 * requirement: bug free, clean, quickly!!!!
 * -------------------------------------------------------------}}}*/
#include <iostream>
#include <string>
using namespace std;

int calc2(const string & s, int end, char x1, char x2) {
    int first = end-3;
    while (first>=0 && (s[first] == x1 || s[first] == x2))
        --first;
    return end-first-1;
}

int longest2chars(const string & s) {
    const int LEN = s.size();
    int i = 1;
    while (i<LEN && s[i] == s[i-1]) ++i; 
    if (i >= LEN-1) return LEN;

    int ans = i+1;
    char x1 = s[i], x2 = s[i-1];
    for (i+=1; i<LEN; ++i) {
        if (s[i] != x1 && s[i] != x2) {
            ans = max(ans, calc2(s, i, x1, x2));
            x1 = s[i], x2 = s[i-1];
        }
    }
    ans = max(ans, calc2(s, i, x1, x2));
    return ans;
}

void honglei(string s) {
    cout << "\"" << s << "\" = " << longest2chars(s) << endl;
}

int main(int argc, char * argv[]) {
    honglei("");
    honglei("abaabc");
    honglei("a");
    honglei("aa");
    honglei("ab");
    honglei("abb");
    honglei("aab");
    honglei("aabbb");
    honglei("aabbc");
    honglei("aabbccccc");
    honglei("aabbcccccaabbbbbccc");
    return 0;
}

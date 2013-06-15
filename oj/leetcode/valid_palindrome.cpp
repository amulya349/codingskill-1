/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string, determine if it is a palindrome, 
 * considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 * -------------------------------------------------------------}}}*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(const string & s) {
            int a=0;
            int b=s.size()-1;
            while (a < b) {
                while (!validch(s[a]) && a<b) ++a;
                while (!validch(s[b]) && a<b) --b;
                if (a<b) {
                    if (s[a]==s[b] || s[a]==s[b]+'a'-'A' || s[a]==s[b]+'A'-'a') 
                        ++a,--b;
                    else return false;
                }
            }
            return a>=b;
        }
    private:
        bool validch(char c) {
            if ((c>='0' && c<='9') || (c>='a' && c<='z') || (c >='A' && c<='Z'))
                return true;
            return false;
        }
};

void honglei(string s) {
    cout << "\"" << s << "\" ";
    static Solution solve;
    if (solve.isPalindrome(s))
        cout << "is a palindrome" << endl;
    else cout << "is not a palindrome" << endl;
}

int main(int argc, char * argv[]) {
    honglei("A man, a plan, a canal: Panama");
    honglei("race a car");
    honglei("1a2");
    return 0;
}

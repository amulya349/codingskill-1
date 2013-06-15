/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        string addBinary(const string & a, const string & b) {
            string res;
            addBinaryImp(res, 0, a, a.size()-1, b, b.size()-1);
            reverse(res.begin(), res.end());
            return res;
        }
    private:
        void addBinaryImp(string & res, int carry, \
                const string & a, int ai, \
                const string & b, int bi) {
            if (ai < 0 && bi < 0 && !carry) return;
            if (ai >= 0) carry += a[ai]-'0';
            if (bi >= 0) carry += b[bi]-'0';

            res += char('0'+carry%2);
            addBinaryImp(res, carry/2, a, ai-1, b, bi-1);
        }
};

int main(int argc, char * argv[]) {
    string a("10110"), b("100");
    Solution solve;
    string c = solve.addBinary(a, b);
    printf("%s\n", c.c_str());
    return 0;
}

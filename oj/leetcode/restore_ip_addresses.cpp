/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string containing only digits,
 * restore it by returning all possible valid IP address combinations.
 * 
 * For example:
 * Given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <string>
#include <iostream>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<string> restoreIpAddresses(const string & s) {
            vector<string> ans;
            restoreIpAddresses(ans, s, 0, 0, "");
            return std::move(ans);
        }

    private:
        void restoreIpAddresses(vector<string> & ans, const string & s, unsigned seg, unsigned pos, string tmp) {
            if (seg == 4) {
                if (pos == s.size())
                    ans.push_back(tmp);
                return;
            }

            int ipseg = 0;
            for (unsigned i=pos; i<s.size(); ++i) {
                int bit = s[i]-'0';
                if (bit > 9 || bit < 0)
                    return;
                ipseg += bit;
                if (ipseg > 255)
                    return;

                tmp += s[i];
                restoreIpAddresses(ans, s, seg+1, i+1, seg==3?tmp:tmp+'.');
                if (ipseg == 0)
                    return;
                ipseg *= 10;
            }
        }
};

void honglei(const string & s) {
    static Solution solve;
    vector<string> ans = solve.restoreIpAddresses(s);
    cout << s << " =>" << endl;
    UIO<string>::pr(ans);
}

int main(int argc, char * argv[]) {
    honglei("25525511135");
    honglei("255255113211135");
    honglei("123");
    honglei("1205");
    honglei("12c5");
    honglei("12005");
    honglei("0000");
    honglei("00000");
    honglei("1200005");
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string multiply(const string & a, const string & b) {
            string ans("0");
            if (a=="0" || b=="0" || b.size() == 0 || a.size() == 0) 
                return ans;
            multiply_imp(ans, a, b, b.size()-1);
            reverse(ans.begin(), ans.end());
            return ans;
        }
    private:
        void multiply_imp(string & ans, const string & a, const string & b, int i) {
            int x = b[i]-'0'; // optimize for x==0 or x==1
            const int ANSLEN = ans.size();
            for (int j=a.size()-1, k=b.size()-1-i, carry=0; j>=0 || carry; --j) {
                if (j>=0) carry += (a[j]-'0')*x;
                if (k<ANSLEN) {
                    carry += ans[k]-'0';
                    ans[k] = carry%10+'0';
                    ++k;
                } else {
                    ans += carry%10+'0';
                }
                carry /= 10;
            }
            if (i>0) multiply_imp(ans, a, b, i-1);
        }
};

void honglei(string a, string b) {
    static Solution solve;
    string m = solve.multiply(a, b);
    printf("%s * %s = %s\n", a.c_str(), b.c_str(), m.c_str());
}

int main(int argc, char * argv[]) {
    honglei("62176", "1200");
    return 0;
}


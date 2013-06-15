/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        int numDecodings(const string & s) {
            // return numDecodingsR(s);
            return numDecodingsDP(s);
        }
    private:
        int numDecodingsDP(const string & s) {
            int SIZE = s.size();
            if (SIZE == 0 || s[0] == '0') return 0;
            else if (SIZE == 1)           return 1;

            int a0 = 0, a1 = 1; // 隐式滚动数组
            for (int i=1; i<SIZE; ++i) {
                int tmp_a1 = a1;
                if (s[i] == '0') a1 = 0;

                if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                    a1 += (a0 == 0 ? 1 : a0);

                if (a1 == 0) return 0; // invalid expression
                a0 = tmp_a1;
            }
            return a1;
        }
    private:
        int numDecodingsR(const string & s) {
            int c = 0;
            if (s.size()) numDecodingRimp(s, 0, s.size()-1, c);
            return c;
        }
        void numDecodingRimp(const string & s, int begin, int end, int & rc) {
            if (begin < end) {
                switch (s[begin]) {
                    case '1':
                        if (s[begin+1] != '0')
                            numDecodingRimp(s, begin+1, end, rc);
                        numDecodingRimp(s, begin+2, end, rc);
                        break;
                    case '2':
                        if (s[begin+1] != '0' && s[begin+1] < '7')
                            numDecodingRimp(s, begin+1, end, rc);
                        numDecodingRimp(s, begin+2, end, rc);
                        break;
                    case '0':
                        return;
                        break;
                    default:
                        numDecodingRimp(s, begin+1, end, rc);
                        break;
                }
            } else if (begin != end || s[end] != '0') {
                ++ rc;
            }
        }
};

void honglei(const string & s) {
    static Solution solve;
    printf("%s => %d\n", s.c_str(), solve.numDecodings(s));
}

int main(int argc, char * argv[]) {
    honglei("301");
    honglei("101");
    honglei("13182021");
    return 0;
}

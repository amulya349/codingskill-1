/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 *     S = "ADOBECODEBANC"
 *     T = "ABC"
 *     Minimum window is "BANC".
 * 
 * Note:
 *   If there is no such window in S that covers all characters in T, \
 *       return the emtpy string "";
 *   If there are multiple such windows, you are guaranteed that there \
 *       will always be only one unique minimum window in S.
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
    public:
        string minWindow(string S, string T) {
            if (S.size() == 0 || T.size() == 0 || S.size() < T.size())
                return "";

            uint16_t tflag[256];    // T串字符存在数组
            uint16_t tcontain[256]; // T串已在S子串的匹配量, 可能多余tflag
            uint32_t compaired = 0; // 已经匹配的总量,达到T.size()则为一次完整匹配
            uint32_t minwindow = 1+S.size();
            uint16_t start_candi = 0;
            uint16_t start;

            memset(tflag, 0, sizeof(tflag));
            memset(tcontain, 0, sizeof(tcontain));
            const unsigned char * pt = (const unsigned char *)T.c_str();
            for (size_t j=0; j<T.size(); ++j)
                ++tflag[pt[j]];

            const unsigned char * ps = (const unsigned char *)S.c_str();
            for (size_t i=0; i<S.size(); ++i) {
                if (tflag[ps[i]] <= 0)
                    continue;
                if (tcontain[ps[i]] < tflag[ps[i]])
                    ++compaired;
                ++tcontain[ps[i]];

                while (compaired == T.size()) {
                    if ( tflag[ps[start_candi]] <= 0) {
                        ++start_candi;
                    } else {
                        if (tcontain[ps[start_candi]] > tflag[ps[start_candi]]) {
                            --tcontain[ps[start_candi]];
                            ++start_candi;
                        } else {
                            if (minwindow > i-start_candi+1) {
                                minwindow = i-start_candi+1;
                                start = start_candi;
                            }
                            break;
                        }
                    }
                }
            }
            return (minwindow > S.size() ? "" : S.substr(start, minwindow));
        }
};

int main(int argc, char * argv[]) {
    // cabd
    string S("abcabdebac");
    string T("cda");

    Solution solve;
    string M = solve.minWindow(S, T);

    printf("S=%s\n", S.c_str());
    printf("T=%s\n", T.c_str());
    printf("min window contain=%s\n", M.c_str());
    return 0;
}


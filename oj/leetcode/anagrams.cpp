/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <string>
#include <tr1/unordered_map>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<string> anagrams(const vector<string> &strs) {
            vector<string> res;
            tr1::unordered_map<string, int> world;
            int VLEN = strs.size();
            for (int i=0; i<VLEN; ++i) {
                string ss = sortbyletter(strs[i]);
                auto it = world.find(ss);
                if (it == world.end()) {
                    world[ss] = i;
                } else {
                    if (it->second >= 0) {
                        res.push_back(strs[it->second]);
                        it->second = -1;
                    }
                    res.push_back(strs[i]);
                }
            }
            return std::move(res);
        }
    private:
        string sortbyletter(const string & str) {
            string ss(str);
            int LEN = ss.size();
            for (int i=0; i<LEN; ++i) {
                for (int j=i+1; j<LEN; ++j) if (ss[j] < ss[i]) {
                    char tmp = ss[i]; ss[i] = ss[j]; ss[j] = tmp;
                }
            }
            return ss;
        }
};

int main(int argc, char * argv[]) {
    vector<string> inputs;
    inputs.push_back("ape");
    inputs.push_back("and");
    inputs.push_back("eap");
    // inputs.push_back("cat");
    Solution solve;
    vector<string> output = solve.anagrams(inputs);
    UIO<string>::pr(output);
    return 0;
}

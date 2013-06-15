/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Write a function to find the longest common prefix string amongst an array of strings. 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0) return "";
            int length = strs[strs.size()-1].size();
            for (int i=strs.size()-2; i>=0; --i) {
                if ((length=common_prefix(strs[i], strs[i+1], length)) == 0)
                        break;
            }
            return strs[0].substr(0, length);
        }

    private:
        int common_prefix(const string & a, const string & b, int max) {
            int length = 0;
            while (a[length] == b[length] && length < max) ++length;
            return length;
        }
};

int main(int argc, char * argv[]) {
    string A[] = {"aabc", "aabd", "aac"};
    vector<string> strs = UIO<string>::in(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    string common_prefix = solve.longestCommonPrefix(strs);
    UIO<string>::pr(strs);
    printf("longest common prefix=%s\n", common_prefix.c_str());
    return 0;
}

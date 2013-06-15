/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given n pairs of parentheses, write a function to generate all combinations \
 * of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            if (n>0) generator(ans, "", 0, 0, n);
            return std::move(ans);
        }

    private:
        void generator(vector<string> & ans, string s, int l, int r, int n) {
            if (l == n) {
                ans.push_back(s.append(n-r, ')'));
                return;
            }
            generator(ans, s+'(', l+1, r, n);
            if (l>r) generator(ans, s+")", l, r+1, n);
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    vector<string> ans = solve.generateParenthesis(3);
    UIO<string>::pr(ans);
    cout << "Total: " << ans.size() << endl;
    return 0;
}

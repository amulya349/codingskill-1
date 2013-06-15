/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return
 *   [
 *     ["aa","b"],
 *     ["a","a","b"]
 *   ]
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <string>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<string> > partition(const string & s) {
            vector<vector<string> > ans;
            if (s.size()>0) partition(ans, vector<string>(), s, 0);
            return std::move(ans);
        }
        void partition(vector<vector<string> > & ans, vector<string> once, const string & s, size_t begin) {
            if (begin == s.size()) {
                ans.push_back(once);
                return;
            }

            for (size_t i=begin; i<s.size(); ++i) {
                if (!isPalindrome(s, begin, i))
                    continue;
                once.push_back(s.substr(begin, i-begin+1));
                partition(ans, once, s, i+1);
                once.pop_back();
            }
        }
        bool isPalindrome(const string & s, int i, int j) {
            while (i < j && s[i] == s[j]) ++i, --j;
            return i >= j;
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    vector<vector<string> > ans = solve.partition("aab");
    UIO<string>::pr(ans);

    return 0;
}

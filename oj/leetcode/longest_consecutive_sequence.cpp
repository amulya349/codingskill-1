/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * 
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * 
 * Your algorithm should run in O(n) complexity.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

class Solution {
    public:
        int longestConsecutive(const vector<int> &num) {
            unordered_map<int, int> hash;
            for (size_t i=0; i<num.size(); ++i) 
                hash[num[i]] = 1;

            int ans=0;
            for (size_t i=0; i<num.size(); ++i) {
                auto it = hash.find(num[i]+1);
                for (int j=num[i]+1; it!=hash.end(); it=hash.find(++j)) {
                    hash[num[i]] += it->second;
                    hash.erase(it);
                }
                ans = max(ans, hash[num[i]]);
            }
            return ans;
        }
};

int main(int argc, char * argv[]) {
    int a[] = {100, 2, 4, 200, 1, 3, 2};
    vector<int> num(a, a+sizeof(a)/sizeof(a[0]));
    Solution solve;
    int ans = solve.longestConsecutive(num);
    printf("%d\n", ans);
    return 0;
}

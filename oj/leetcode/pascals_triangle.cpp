/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 * -------------------------------------------------------------}}}*/
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > ans;
            generate_imp(ans, 1, numRows);
            return std::move(ans);
        }
    private:
        void generate_imp(vector<vector<int> > & ans, int now, int total) {
            if (now > total) return;

            ans.push_back(vector<int>());
            ans[now-1].push_back(1);
            for (int i=0; i<=now-3; ++i) 
                ans[now-1].push_back(ans[now-2][i]+ans[now-2][i+1]);
            if (now > 1) ans[now-1].push_back(1);

            generate_imp(ans, now+1, total);
        }
};

void honglei(int numRows) {
    static Solution solve;
    vector<vector<int> > ans = solve.generate(numRows);
    UIO<int>::pr(ans);
}

int main(int argc, char * argv[]) {
    honglei(5);
    return 0;
}

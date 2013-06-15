/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            sort(num.begin(), num.end());

        }
};

int main(int argc, char * argv[]) {
    return 0;
}

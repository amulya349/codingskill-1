/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree and a sum, find all root-to-leaf paths \
 * where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *         5
 *       /  \
 *      4    8
 *     /    / \
 *    11   3   4
 *   /  \     / \
 *  7    2   5   1
 * return
 *  [
 *      [5,4,11,2],
 *      [5,8,4,5]
 *  ]
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        typedef Tree<int>::TreeNode TreeNode;
    public:
        vector<vector<int> > pathSum(const TreeNode * root, int sum) {
            vector<vector<int> > ans;
            vector<int> path;
            pathSumImp(root, sum, ans, path);
            return std::move(ans);
        }

        void pathSumImp(const TreeNode * root, int sum, \
                vector<vector<int> >& ans, vector<int> & rpath) {
            if (!root) return;

            rpath.push_back(root->val);
            if (!root->left && !root->right && root->val == sum)
                ans.push_back(rpath);

            pathSumImp(root->left,  sum-root->val, ans, rpath);
            pathSumImp(root->right, sum-root->val, ans, rpath);
            rpath.pop_back();
        }
};

int main(int argc, char * argv[]) {
    int A[] = {5, 4, 8, 11, '#', 3, 4, 7, 2, '#', '#', 5, 1};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    vector<vector<int> > res = solve.pathSum(t.Root(), 22);
    UIO<int>::pr(res);
    return 0;
}

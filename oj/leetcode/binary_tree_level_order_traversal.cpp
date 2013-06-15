/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *-------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        vector<vector<int> > levelOrder(const TreeNode * root) {
            vector<vector<int> > rvv;
            levelOrderImp(root, 0, rvv);
            return std::move(rvv);
        }
    private:
        void levelOrderImp(const TreeNode * p, size_t lev, vector<vector<int> > & rvv) {
            if (!p) return;
            if (rvv.size() <= lev)
                rvv.push_back(vector<int>());
            rvv[lev].push_back(p->val);
            levelOrderImp(p->left,  lev+1, rvv);
            levelOrderImp(p->right, lev+1, rvv);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {3, 9, 20, '#', '#', 15, 7};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    vector<vector<int> >res = solve.levelOrder(t.Root());
    UIO<int>::pr(res);
    return 0;
}

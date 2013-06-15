/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 *(ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 *-------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(const TreeNode * root) {
            vector<vector<int> > vv;
            LevelOrder(root, 0, vv);
            for (size_t lev=1; lev<vv.size(); lev+=2)
                reverse(vv[lev].begin(), vv[lev].end());
            return std::move(vv);
        }

        void LevelOrder(const TreeNode * p, size_t lev, vector<vector<int> > & rvv) {
            if (!p) return;
            if (rvv.size() <= lev)
                rvv.push_back(vector<int>());
            rvv[lev].push_back(p->val);
            LevelOrder(p->left,  lev+1, rvv);
            LevelOrder(p->right, lev+1, rvv);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {3, 9, 20, '#', '#', 15, 7};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    vector<vector<int> >res = solve.zigzagLevelOrder(t.Root());
    UIO<int>::pr(res);
    return 0;
}

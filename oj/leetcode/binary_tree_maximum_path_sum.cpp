/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 * 
 * For example:
 * Given the below binary tree,
 *        1
 *       / \
 *      2   3
 * Return 6.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include "../../util/tree.h"

class Solution {
    private:
        typedef Tree<int>::TreeNode TreeNode;
    public:
        int maxPathSum(const TreeNode * root) {
            int g2root;
            return maxPathSumImp(root, g2root);
        }

        int maxPathSumImp(const TreeNode * r, int & g2root) {
            if (!r) {
                g2root = 0;
                return INT_MIN;
            }
            int g2l, g2r;
            int maxl = maxPathSumImp(r->left,  g2l);
            int maxr = maxPathSumImp(r->right, g2r);

            g2root = r->val + std::max(0, std::max(g2l, g2r));
            int g  = r->val + std::max(g2l, 0) + std::max(g2r, 0);
            return std::max(std::max(maxl, maxr), g);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1, 2, 3};
    Tree<int> tree(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    printf("res:%d\n", solve.maxPathSum(tree.Root()));
    return 0;
}

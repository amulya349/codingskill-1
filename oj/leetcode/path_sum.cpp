/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            return root && hasPathSumImp(root, sum, false);
        }

        bool hasPathSumImp(TreeNode * root, int sum, bool hasbrother) {
            if (!root) return !hasbrother && sum == 0;

            return hasPathSumImp(root->left,  sum-root->val, root->right!=NULL) \
                || hasPathSumImp(root->right, sum-root->val, root->left !=NULL);
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

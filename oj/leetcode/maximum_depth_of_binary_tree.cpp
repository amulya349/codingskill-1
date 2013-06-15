/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path \
 * from the root node down to the farthest leaf node.
 * -------------------------------------------------------------}}}*/
#include "../../util/tree.h"
typedef Tree<int>::TreeNode TreeNode;

class Solution {
    public:
        int maxDepth(const TreeNode *root) {
            if (!root)
                return 0;
            int ld = maxDepth(root->left);
            int rd = maxDepth(root->right);
            return 1+(ld>rd?ld:rd);
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

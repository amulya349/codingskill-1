/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined \
 * as a binary tree in which the depth of the two subtrees of \
 * every node never differ by more than 1.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <algorithm>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        bool isBalanced(const TreeNode * root) {
            int h = 0;
            return isBalanced_imp(root, h);
        }

        bool isBalanced_imp(const TreeNode * root, int & h) {
            if (!root) {
                h = 0;
                return true;
            }

            int lh, rh;
            if (isBalanced_imp(root->left, lh) \
                    && isBalanced_imp(root->right, rh)) {
                h = 1 + (lh > rh ? lh : rh);
                if (abs(lh - rh) <= 1)
                    return true;
            }
            return false;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,5,3,4,'#',6,'#','#','#','#',2};
    Tree<int> t(A, sizeof(A)/sizeof(A[0])); 

    static Solution solve;
    if (solve.isBalanced(t.Root()))
        printf("is balanced\n");
    else printf("not balanced\n");
    return 0;
}

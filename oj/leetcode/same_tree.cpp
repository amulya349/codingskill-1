/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally 
 * identical and the nodes have the same value.
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include "../../util/tree.h"
typedef Tree<int>::TreeNode TreeNode;

class Solution {
    public:
        bool isSameTree(const TreeNode *p, const TreeNode *q) {
            if (p && q) 
                return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            return p == q;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}


/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, the left binary tree is symmetric, but the right one is not
 *     1              1
 *    / \            / \
 *   2   2          2   2
 *  / \ / \          \   \
 * 3  4 4  3          3   3
 * Note: Bonus points if you could solve it both recursively and iteratively.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/tree.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        bool isSymmetric(const TreeNode * root) {
            return !root || isSymmetricImp(root->left, root->right);
        }
    private:
        bool isSymmetricImp(const TreeNode * p, const TreeNode * q) {
            if (p && q)
                return p->val == q->val && \
                       isSymmetricImp(p->left, q->right) && \
                       isSymmetricImp(p->right, q->left);
            return p == q;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,2,'#',3,'#',3}; // {1,2,2,3,4,4,3};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    Solution solve;
    if (solve.isSymmetric(t.Root())) printf("yeap\n");
    else printf("nop\n");
    return 0;
}

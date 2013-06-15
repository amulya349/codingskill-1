/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, Given
 *       1
 *      / \
 *     2   5
 *    / \   \
 *   3   4   6
 * The flattened tree should look like:
 *   1
 *    \
 *     2
 *      \
 *       3
 *        \
 *         4
 *          \
 *           5
 *            \
 *             6
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child \
 * points to the next node of a pre-order traversal.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        void flatten(TreeNode * root) {
            // flatten_preorder(root);
            flatten_preorder(NULL, root);
        }

    private:
        // 返回先序访问的最后一个节点
        TreeNode * flatten_preorder(TreeNode * root) {
            if (!root) return NULL;
            TreeNode * l  = root->left;
            TreeNode * r  = root->right;
            TreeNode * ll = flatten_preorder(l);
            TreeNode * rr = flatten_preorder(r);

            root->left = NULL;
            if (l && r) {
                root->right = l;
                ll->right = r;
                return rr;
            } else if (l) {
                root->right = l;
                return ll;
            } else if (r) {
                root->right = r;
                return rr;
            } else {
                return root;
            }
        }

        TreeNode * flatten_preorder(TreeNode * prev, TreeNode * now) {
            if (!now) return NULL;
            TreeNode * l = now->left;
            TreeNode * r = now->right;

            if (prev) prev->right = now; // 因为这里会改变，所以需要先保存右子树
            now->left = prev;

            TreeNode * prev2 = flatten_preorder(now, l);
            if (r) return flatten_preorder(prev2?prev2:now, r);
            else   return prev2?prev2:now;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,5,3,4,6};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    solve.flatten(t.Root());
    for (TreeNode * c=t.Root(); c; c=c->right) 
        printf("%d, ", c->val);
    printf("\n");
    return 0;
}

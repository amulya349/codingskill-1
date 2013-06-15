/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary search tree, flatten it to a double linked list in-place.
 * in fact, it's an IN_order flatten
 *
 * For example, Given
 *        4 
 *      /   \
 *     2     6 
 *    / \   / \
 *   1   3 5   7 
 * The flattened tree should look like:
 * 1-2-3-4-5-6-7
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include <string.h>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;

class Solution {
    public:
        TreeNode * flatten(TreeNode * root) {
            TreeNode * h = root;
            if (h) while (h->left) h=h->left;
            helper(NULL, root);
            return h;
        }

        // return the last node of inorder travsal
        TreeNode * helper(TreeNode * prev, TreeNode * r) {
            if (!r) return NULL;

            TreeNode * prev_in_left = helper(prev, r->left);
            if (prev_in_left) prev = prev_in_left;

            r->left = prev;
            if (prev) prev->right = r;

            return r->right?helper(r, r->right):r;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {4,2,6,1,3,5,7};
    Tree<int> t(A, sizeof(A)/sizeof(A[0])); 

    static Solution solve;
    for (TreeNode * start = solve.flatten(t.Root()); start; start=start->right) 
        printf("%d, ", start->val);
    printf("\n");
    return 0;
}

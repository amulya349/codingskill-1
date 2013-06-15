#include <stdio.h>
#include "../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;

TreeNode * ca_bst_imp(TreeNode * r, const TreeNode * a, const TreeNode * b) {
    if (!r || (r->val > a->val && r->val < b->val)) return r;
    else if (r->val > b->val) return ca_bst_imp(r->left,  a, b);
    else if (r->val < a->val) return ca_bst_imp(r->right, a, b);
}

TreeNode * ca_bst(TreeNode * root, const TreeNode * a, const TreeNode * b) {
    // TODO check if a & b in the tree
    if (a->val > b->val) {
        const TreeNode * tmp = b;
        b = a;
        a = tmp;
    }
    return ca_bst_imp(root, a, b);
}

int main(int argc, char * argv[]) {
    int A[] = {5, 4, 8, 11, '#', 3, 4, 7, 2, '#', '#', 5, 1};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));
    TreeNode * root = t.Root();
	return 0;
}


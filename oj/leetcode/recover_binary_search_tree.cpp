/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 * 
 * Note:
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        void recoverTree(TreeNode * root) {
            err1 = err2 = prev = NULL;
            recoverTreeHelper(root);
            if (err1 && err2) std::swap(err1->val, err2->val);
        }
    private:
        void recoverTreeHelper(TreeNode * root) {
            if (!root) return;
            recoverTreeHelper(root->left);
            if (prev && prev->val > root->val) {
                err2 = root;
                if (!err1) err1 = prev;
                else return;
            }
            prev = root;
            recoverTreeHelper(root->right);
        }
    private:
        TreeNode *err1, *err2, *prev;
};

void honglei(int A[], size_t n) {
    Tree<int> t(A, n);
    Tree<int>::InOrder(t.Root());
    printf("\nrecover=>\n");

    static Solution solve;
    solve.recoverTree(t.Root());
    Tree<int>::InOrder(t.Root());
    printf("\n\n");
}

int main(int argc, char * argv[]) {
    int A1[] = {1,'#',3,'#',2};
    honglei(A1, sizeof(A1)/sizeof(A1[0]));
    int A2[] = {1,2,3};
    honglei(A2, sizeof(A2)/sizeof(A2[0]));
    int A3[] = {2,'#',1};
    honglei(A3, sizeof(A3)/sizeof(A3[0]));
    return 0;
}

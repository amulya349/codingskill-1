/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node 
 *      contains only nodes with keys less than the node's key.
 * The right subtree of a node
 *      contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <stack>
#include <limits.h>
#include "../../util/tree.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        bool isValidBST(const TreeNode *root) {
            // isbstIt(root);
            return isbstR(root);
        }

    private:
        /*方法1: 迭代*/
        bool isbstIt(const TreeNode *root) {
            stack<const TreeNode *> A;
            int min = 1+(unsigned(-1)/2);
            while (root || A.size()) {
                if (root) {
                    A.push(root);
                    root = root->left;
                } else {
                    root = A.top();
                    A.pop();
                    if (root->val <= min)
                        return false;

                    min = root->val;
                    root = root->right;
                }
            }
            return true;
        }

    private:
        // http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_B.pdf
        bool isbstR(const TreeNode * root) {
            return isValidBSTHelper(root, INT_MIN, INT_MAX);
        }

        bool isValidBSTHelper(const TreeNode * t, int min, int max) {
            if (!t) return true;
            return (t->val < max && t->val > min) && \
                isValidBSTHelper(t->left,  min, t->val) && \
                isValidBSTHelper(t->right, t->val, max);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {3,1,5,0,2,4,6,'#','#','#',3};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));
    Solution solve;
    if (solve.isValidBST(t.Root()))
        printf("is a bst\n");
    else printf("isn't a bst\n");
    return 0;
}

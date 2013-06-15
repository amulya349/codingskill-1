/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * stackless in morris traversal
 *
 * http://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion
 *
 * 1. Initialize current as root
 * 2. While current is not NULL
 *      If current does not have left child     
 *          a. Print current’s data
 *          b. Go to the right, i.e., current = current->right
 *      Else
 *          a. In current's left subtree, make current the right child of the rightmost node
 *          b. Go to this left child, i.e., current = current->left
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        typedef Tree<int>::TreeNode TreeNode;
    public:
        vector<int> inorderTraversal(TreeNode *root) { // morris_traversal_inorder
            vector<int> res;
            for (TreeNode *c=root; c; ) {
                TreeNode *predecessor = c->left;
                if (!predecessor) {
                    res.push_back(c->val); // access, no need of memory to cache
                    c = c->right;          // BACKTRACE + TURN to right-subtree
                    continue;
                }

                while (predecessor->right && predecessor->right != c)  
                    predecessor = predecessor->right; 
                if (!predecessor->right) { // Make current as right child of its inorder predecessor
                    predecessor->right = c;
                    c = c->left;
                } else { 
                    predecessor->right = NULL; // 为什么置空, 请考虑!
                    res.push_back(c->val);     // access
                    c = c->right;
                }
            }
            return std::move(res);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {0, '#', 1, 2, '#'};
    Tree<int> tree(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    vector<int> res = solve.inorderTraversal(tree.Root());
    UIO<int>::pr(res);
    return 0;
}

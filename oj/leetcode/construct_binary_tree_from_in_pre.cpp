/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree
 * -------------------------------------------------------------}}}*/
#include <tr1/unordered_map>
#include <stdio.h>
#include <vector>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        TreeNode * buildTree(const vector<int> &preorder, const vector<int> &inorder) {
            tr1::unordered_map<int, int> inidx;
            for (int i=inorder.size()-1; i>=0; --i)
                inidx[inorder[i]] = i;
            return buildTreeImp(inidx, preorder, inorder, 0, 0, inorder.size());
        }

        TreeNode * buildTreeImp(tr1::unordered_map<int, int> & inidx, 
                const vector<int> & preorder, const vector<int> & inorder, 
                int pb, int ib, int LEN) {
            if (LEN <= 0) return NULL;

            TreeNode * root = new TreeNode(preorder[pb]);
            int rootat = inidx[preorder[pb]];
            root->left  = buildTreeImp(inidx, preorder, inorder, pb+1, ib, rootat-ib);
            root->right = buildTreeImp(inidx, preorder, inorder, pb+1+rootat-ib, rootat+1, LEN-rootat+ib-1);
            return root;
        }
};

int main(int argc, char * argv[]) {
    int Apr[] = {2, 1};
    vector<int>preorder = UIO<int>::in(Apr, sizeof(Apr)/sizeof(Apr[0]));
    int Ain[] = {1, 2};
    vector<int>inorder = UIO<int>::in(Ain, sizeof(Ain)/sizeof(Ain[0]));

    Solution solve;
    TreeNode * root = solve.buildTree(preorder, inorder);
    Tree<int>::PreOrder(root);
    return 0;
}

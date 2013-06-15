/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
        TreeNode * buildTree(const vector<int> &inorder, const vector<int> &postorder) {
            tr1::unordered_map<int, int> inidx;
            for (int i=inorder.size()-1; i>=0; --i)
                inidx[inorder[i]] = i;

            return buildTreeImp(inidx, inorder, postorder, 0, 0, inorder.size());
        }
    private:
        TreeNode * buildTreeImp(tr1::unordered_map<int, int> & inidx, 
                const vector<int> & inorder, const vector<int> & postorder,
                int ib, int pb, int LEN) {
            if (LEN <= 0) return NULL;

            TreeNode * root = new TreeNode(postorder[pb+LEN-1]);
            int rootat = inidx[postorder[pb+LEN-1]];
            root->left  = buildTreeImp(inidx, inorder, postorder, ib, pb, rootat-ib);
            root->right = buildTreeImp(inidx, inorder, postorder, rootat+1, pb+rootat-ib, LEN-rootat+ib-1);
            return root;
        }
};

int main(int argc, char * argv[]) {
    int Ain[] = {1, 2};
    vector<int>inorder = UIO<int>::in(Ain, sizeof(Ain)/sizeof(Ain[0]));
    int Apo[] = {2, 1};
    vector<int>postorder = UIO<int>::in(Apo, sizeof(Apo)/sizeof(Apo[0]));

    Solution solve;
    TreeNode * root = solve.buildTree(inorder, postorder);
    Tree<int>::PreOrder(root);
    return 0;
}

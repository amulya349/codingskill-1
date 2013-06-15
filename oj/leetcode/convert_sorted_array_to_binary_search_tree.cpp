/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * -------------------------------------------------------------}}}*/

#include <stdio.h>
#include "../../util/tree.h"
#include "../../util/io.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        TreeNode * sortedArrayToBST(const vector<int> & num) {
            return sortedArrayToBSTImp(num, 0, num.size()-1);
        }
    private:
        TreeNode * sortedArrayToBSTImp(const vector<int> & num, int a, int b) {
            if (a>b) return NULL;
            int m = a+(b-a)/2;
            TreeNode * root = new TreeNode(num[m]);
            root->left  = sortedArrayToBSTImp(num, a, m-1);
            root->right = sortedArrayToBSTImp(num, m+1, b);
            return root;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {-10,-3,0,5,9};
    vector<int> num = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));
    Solution solve;
    const TreeNode * root = solve.sortedArrayToBST(num);

    Tree<int>::PreOrder(root);
    printf("(pre)\n");
    Tree<int>::InOrder(root);
    printf("(in)\n");
    Tree<int>::PostOrder(root);
    printf("(post)\n");
    return 0;
}

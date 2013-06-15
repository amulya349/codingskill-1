/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * 
 * For example,
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/tree.h"

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        int sumNumbers(const TreeNode * root) {
            return sumNumbersHelper(root, 0);
        }

        int sumNumbersHelper(const TreeNode * r, int path) {
            if (!r) return 0;
            path = 10*path+r->val;
            if (!r->left && !r->right) 
                return path;

            return sumNumbersHelper(r->left, path) + sumNumbersHelper(r->right, path);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {0, 9};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    printf("%d\n", solve.sumNumbers(t.Root()));
    return 0;
}

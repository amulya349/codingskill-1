/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 * input:3 
 * output:{1,#,2,#,3},{1,#,3,2},{2,1,3},{3,1,#,#,2},{3,2,#,1}
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/tree.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        vector<TreeNode *> generateTrees(int n) {
            return std::move(generateTreesImp(1, n));
        }
    private:
        vector<TreeNode *> generateTreesImp(int a, int b) {
            vector<TreeNode *>subtree;
            if (a>b) 
                subtree.push_back(NULL);
            for (int n=a; n<=b; ++n) {
                vector<TreeNode *>leftchild  = generateTreesImp(a, n-1);
                vector<TreeNode *>rightchild = generateTreesImp(n+1, b);
                for (size_t l=0; l<leftchild.size(); ++l) {
                    for (size_t r=0; r<rightchild.size(); ++r) {
                        TreeNode * node = new TreeNode(n);
                        node->left  = leftchild[l];
                        node->right = rightchild[r];
                        subtree.push_back(node);
                    }
                }
            }
            return std::move(subtree);
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    vector<TreeNode*> trees = solve.generateTrees(4);
    for (size_t i=0; i<trees.size(); ++i) {
        printf("\n[%lu]\npreo:", 1+i);
        Tree<int>::PreOrder(trees[i]);
        printf("\ninor:");
        Tree<int>::InOrder(trees[i]);
        printf("\npost:");
        Tree<int>::PostOrder(trees[i]);
        printf("\n");
    }
    return 0;
}

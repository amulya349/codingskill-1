/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path \
 * from the root node down to the nearest leaf node.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>
#include "../../util/tree.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class Solution {
    public:
        int minDepth(const TreeNode * root) {
            return minDepthR(root, false);
            // return minDepthQueue(root);
        }
    private:
        int minDepthR(const TreeNode * r, bool hasbrother) {
            if (!r) 
                return hasbrother?INT_MAX:0;
            int minl = minDepthR(r->left, r->right!=NULL);
            int minr = minDepthR(r->right, r->left!=NULL);
            return 1+min(minl, minr);
        }

    private:
        int minDepthQueue(const TreeNode * root) {
            if (!root) return 0;

            deque<const TreeNode *> q;
            q.push_front(root);
            int count(1), min(0);
            while (count) {
                int newcount = 0;
                const TreeNode * n;
                ++min;
                for (int i=0; i<count; ++i) {
                    n = q.back();
                    q.pop_back();

                    if (!n->left && !n->right) return min;
                    if (n->left) {
                        ++newcount;
                        q.push_front(n->left);
                    }
                    if (n->right) {
                        ++newcount;
                        q.push_front(n->right);
                    }
                }
                count = newcount;
            }
            return min;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,5,3,4,'#', 6};
    Tree<int> t(A, sizeof(A)/sizeof(A[0])); 

    static Solution solve;
    int md = solve.minDepth(t.Root());
    printf("%d\n", md);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree? Would your previous solution still work?
 * 
 * Note:
 * 
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 * -------------------------------------------------------------}}}*/
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(0), right(0), next(0) {}
};

class Solution {
    public:
        // 树的解法一般递归，但并非只能递归, 例如还有BFS/DFS
        void connect(TreeLinkNode * n) {
            while (n) {
                TreeLinkNode * nextlevel = 0;
                for (TreeLinkNode * prev=0; n; n=n->next) {
                    if (!nextlevel) nextlevel = n->left?n->left:n->right;

                    if (n->left) {
                        if (prev) prev->next = n->left;
                        prev = n->left;
                    }
                    if (n->right) {
                        if (prev) prev->next = n->right;
                        prev = n->right;
                    }
                }
                n = nextlevel;
            }
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

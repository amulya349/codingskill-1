/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree
 *   struct TreeLinkNode {
 *     TreeLinkNode *left;
 *     TreeLinkNode *right;
 *     TreeLinkNode *next;
 *   }
 * Populate each next pointer to point to its next right node. 
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *
 * For example, Given the following perfect binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 * -------------------------------------------------------------}}}*/
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x=0) : val(x), left(0), right(0), next(0) {}
};

class Solution {
    public:
        /* if we go deep into sub-tree first, it's not easy to connect right's next */
        void connect(TreeLinkNode * p) {
            if (!p) return;
            connect(p->left);
            connect(p->right);

            for (TreeLinkNode *a=p->left, *b=p->right; \
                    a; a=a->right, b=b->left) // because of perfect tree so no need to judge b is NULL
                a->next = b;
        }

        /* level by level top->down is easy to mannge the right's next by connected infos */
        void connect2(TreeLinkNode * p) {
            if (!p) return;
            if (p->left)  p->left->next  = p->right;
            if (p->right) p->right->next = p->next?p->next->left:0;

            connect2(p->left);
            connect2(p->right);
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

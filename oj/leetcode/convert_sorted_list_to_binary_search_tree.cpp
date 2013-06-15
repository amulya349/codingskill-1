/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/tree.h"
#include "../../util/io.h"
#include "../../util/linkedlist.h"
typedef Tree<int>::TreeNode TreeNode;
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        TreeNode * sortedListToBST(const ListNode * head) {
            int count=0;
            for (const ListNode * w = head; w; w=w->next) ++count;
            return sortedListToBSTImp(head, count);
        }
    private:
        TreeNode * sortedListToBSTImp(const ListNode * h, int c) {
            if (c <= 0) return NULL;

            const ListNode * w = h;
            for (int i=c/2; i>0; --i) w = w->next;

            TreeNode * root = new TreeNode(w->val);
            root->left  = sortedListToBSTImp(h, c/2);
            root->right = sortedListToBSTImp(w->next, (c-1)/2);
            return root;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

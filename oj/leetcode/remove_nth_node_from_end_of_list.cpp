/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid. Try to do this in one pass.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            int i=0;
            ListNode *h(head), *bm(NULL);
            while (h) {
                ListNode * tmp = h;
                for (i=0; i<n && h; ++i)
                    h = h->next;
                if (i == n && h)
                    bm = tmp;
            }
            if (!bm) 
                return head?head->next:head;
            while (bm && i>1)
                bm = bm->next, --i;
            if (bm && bm->next)
                bm->next = bm->next->next;
            return head;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2,3,4,5};
    ListNode * ln = LinkedList<int>::make(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    ListNode * c = solve.removeNthFromEnd(ln, 3);
    for (const ListNode * x=c; x; x=x->next)
        printf("%d", x->val);
    printf("\n");
    return 0;
}

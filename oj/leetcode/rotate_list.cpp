/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 * -------------------------------------------------------------}}}*/
#include <stdlib.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head || k<=0) return head;
            ListNode *pre(0), *p(head);
            int i=0, LEN=0;
            for (ListNode *now=head; p; p=p->next, ++LEN) {
                if (++i<=k) continue;
                i=0;
                pre = now;
                now = p->next;
            }

            if (!pre && i<=k) return rotateRight(head, k%LEN);
            for (; i>0; --i) pre=pre->next;
            for (p=pre; p->next; p=p->next);

            p->next = head;
            head = pre->next;
            pre->next = NULL;
            return head;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,2};
    ListNode * list = LinkedList<int>::make(A, sizeof(A)/sizeof(A[0]));
    Solution solve;
    ListNode * nlist = solve.rotateRight(list, 3);
    LinkedList<int>::print(nlist);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given  1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        // learning at the tail of article http://www.eskimo.com/~scs/cclass/int/sx8.html
        // read again while seeing this
        ListNode * reverseBetween(ListNode * head, int m, int n) {
            ListNode ** h = &head; // GREAT!!!!  DIR_MARK
            for (int i=1; i<m; ++i) h = &((*h)->next);

            ListNode * prev = NULL;
            ListNode * now  = *h;
            for (int j=m; j<=n && now; ++j) {
                ListNode * tmp4next = now->next;
                now->next = prev;
                prev = now;
                now  = tmp4next;
            }
            (*h)->next = now;
            *h = prev;
            return head;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * ie.
 *   1->3->5 && 2->7, return 1->2->3->5->7.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode * mergeTwoLists(ListNode * a, ListNode * b) {
            if (!a || !b) return a?a:b;

            ListNode ** pp = &a;
            while (*pp && (*pp)->val<=b->val) pp=&(*pp)->next;
            b->next = mergeTwoLists(*pp, b->next);
            *pp = b;
            return (a->val <= b->val) ? a : b;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

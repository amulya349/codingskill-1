/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space.
  You may not modify the values in the list, only nodes itself can be changed.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (!head || !head->next) 
                return head;
            ListNode * n = head->next;
            head->next = swapPairs(n->next);
            n->next = head;
            return n;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

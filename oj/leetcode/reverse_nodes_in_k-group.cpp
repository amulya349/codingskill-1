/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            for (ListNode **neck=&head, **neckto=NULL; *neck; neck=neckto) {
                ListNode * prev = NULL;
                ListNode * now = *neck;
                if (!hasLeftK(now, k)) break;
                for (int i=0; i<k&&now; ++i) {
                    ListNode * next = now->next;
                    now->next = prev;
                    prev = now;
                    now = next;
                }

                (*neck)->next = now; // connect to next group 
                neckto = &(*neck)->next;
                *neck = prev;        // connect this head to prev group's tail
            }
            return head;
        }
    private:
        bool hasLeftK(const ListNode * a, int k) {
            int i;
            for (i=0; a&&i<k; ++i,a=a->next);
            return i==k;
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

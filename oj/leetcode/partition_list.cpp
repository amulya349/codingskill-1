/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode *a(NULL), *b(NULL), *ha(NULL), *hb(NULL);
            for (; head; head=head->next) {
                if (head->val < x) {
                    if (a) 
                        a->next = head;
                    else if (!ha)
                        ha = head;
                    a = head;
                } else {
                    if (b)
                        b->next = head;
                    else if (!hb)
                        hb = head;
                    b = head;
                }
            }
            if (a) a->next = hb;
            if (b) b->next = NULL;
            return ha?ha:hb;
        }
};

int main(int argc, char * argv[]) {
    int A[] = {1,4,3,2,5,2};
    ListNode * ln = LinkedList<int>::make(A, sizeof(A)/sizeof(A[0]));

    static Solution solve;
    ListNode * c = solve.partition(ln, 3);
    for (const ListNode * x=c; x; x=x->next)
        printf("%d", x->val);
    printf("\n");
    return 0;
}

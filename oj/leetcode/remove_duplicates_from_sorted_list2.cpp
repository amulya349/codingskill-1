/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            deleteDuplicates(&head, head, INT_MIN);
            return head;
        }

        void deleteDuplicates(ListNode ** conntctor, ListNode * head, int prev) {
            if (!head) {
                *conntctor = NULL;
                return;
            }

            if (head->val != prev) {
                prev = head->val;
                if (!head->next || head->val != head->next->val) {
                    *conntctor = head;
                    conntctor  = &head->next;
                }
            }
            deleteDuplicates(conntctor, head->next, prev);
        }
};

void honglei(int A[], int N) {
    ListNode * list = LinkedList<int>::make(A, N);

    static Solution solve;
    for (ListNode * h=solve.deleteDuplicates(list); h; h=h->next)
        printf("%d ",h->val);
    printf("\n");
}

int main(int argc, char** argv) {
    int A[] = {1,1,1,1,1,1,2,2,3,3,3,3,3,3,4,5,6,7,8,8,8,9,9,10,10};
    honglei(A, sizeof(A)/sizeof(A[0]));
    int B[] = {1,2,3,4,4,};
    honglei(B, sizeof(B)/sizeof(B[0]));
    return 0;
}

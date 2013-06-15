/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (!head) return NULL;

            int prev = head->val;
            for (ListNode ** pp=&head->next; *pp;) {
                if ((*pp)->val == prev) {
                    *pp = (*pp)->next;
                } 
                else {
                    prev = (*pp)->val;
                    pp=&(*pp)->next;
                }
            }
            return head;
        }
};

void honglei(int A[], int N) {
    ListNode * list = LinkedList<int>::make(A, N);

    static Solution solve;
    for (ListNode * h=solve.deleteDuplicates(list); h; h=h->next)
        printf("%d,",h->val);
    printf("\n");
}

int main(int argc, char** argv) {
    int A[] = {1,1,1,1,1,1,2,2,3,3,3,3,3,3,4,5,6,7,8,8,8,9,9,10,10};
    honglei(A, sizeof(A)/sizeof(int));
    return 0;
}

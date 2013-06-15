/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain \
 * a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "../../util/linkedlist.h"
typedef LinkedList<int>::ListNode ListNode;

class Solution {
    public:
        ListNode * addTwoNumbers(const ListNode * a, const ListNode * b) {
            ListNode * h = NULL;
            addTwoNumbersImp(h, 0, a, b);
            return h;
        }

    private:
        void addTwoNumbersImp(ListNode * & c, int carry, const ListNode * a, const ListNode * b) {
            if (!a && !b && carry == 0) return;
            if (a) carry += a->val;
            if (b) carry += b->val;

            c = new ListNode(carry%10);
            addTwoNumbersImp(c->next, carry/10, a?a->next:0, b?b->next:0);
        }
};

int main(int argc, char * argv[]) {
    int A[] = {2, 4, 3};
    int B[] = {5, 6, 4};
    ListNode * a = LinkedList<int>::make(A, sizeof(A)/sizeof(A[0]));
    ListNode * b = LinkedList<int>::make(B, sizeof(B)/sizeof(B[0]));

    Solution solve;
    ListNode * c = solve.addTwoNumbers(a, b);
    for (const ListNode * x=c; x; x=x->next)
        printf("%d", x->val);
    printf("\n");
    return 0;
}

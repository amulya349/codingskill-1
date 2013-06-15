#ifndef __LINKED_LIST_H_20130515
#define __LINKED_LIST_H_20130515
#include<iostream>

template<typename T>
class LinkedList {
    public:
        struct ListNode {
            T val;
            ListNode * next;
            ListNode() : val(0), next(NULL) {}
            ListNode(const T & x) : val(x), next(NULL) {}
        };
    public:
        static void print(const ListNode * head) {
            for (const ListNode * a=head; a; a=a->next)
                std::cout << a->val << " ";
            std::cout << std::endl;
        }
        
        static ListNode * make(const T * A, size_t nA) {
            if (!A || !nA) return NULL;
            ListNode * h = new ListNode(A[0]);
            ListNode * a = h;
            for (size_t i=1; i<nA; ++i) {
                a->next = new ListNode(A[i]);
                a = a->next;
            }
            return h;
        }
};

#endif


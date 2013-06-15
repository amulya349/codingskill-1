/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 *
 * input		    expected	
 * []		    {}	
 * [{}]		    {}	
 * [{1}]		{1}	
 * [{0,2,5}]	{0,2,5}	
 * [{},{}]		{}	
 * [{},{1}]		{1}	
 * [{1},{0}]	{0,1}	
 * [{0},{1}]	{0,1}	
 * [{1,2,2},{1,1,2}]		        {1,1,1,2,2,2}	
 * [{1,2,3},{4,5,6,7}]	            {1,2,3,4,5,6,7}	
 * [{1,4,5},{0,2}]		            {0,1,2,4,5}	
 * [{2},{},{-1}]		            {-1,2}	
 * [{},{-1,5,11},{},{6,10}]		    {-1,5,6,10,11}	
 * [{},{-2},{-3,-2,1}]		        {-3,-2,-2,1}	
 * [{-1,1},{-3,1,4},{-2,-1,0,2}]	{-3,-2,-1,-1,0,1,1,2,4}
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <set>
#include <stdio.h>
#include "../../util/linkedlist.h"
using namespace std;
typedef LinkedList<int>::ListNode ListNode;

struct ListHelper {
    ListNode * a;
    ListHelper(ListNode * x) : a(x) {}
    bool operator<(const ListHelper & rhs) const {return a->val<rhs.a->val;}
};

class Solution {
    public:
        ListNode *mergeKLists(const vector<ListNode *> &lists) {
            multiset<ListHelper> eachline;
            for (int i=lists.size()-1; i>=0; --i) if (lists[i])
                eachline.insert(ListHelper(lists[i]));

            ListNode * head = eachline.begin()->a;
            for (ListNode *pre(NULL), *now(NULL); !eachline.empty(); pre=now) {
                now = eachline.begin()->a;
                eachline.erase(eachline.begin());
                if (pre) pre->next = now;
                if (now->next) eachline.insert(ListHelper(now->next));
            }
            return head;
        }
};


int main(int argc, char * argv[]) {
    int A[] = {-1, 1};
    int B[] = {-3, 1, 4};
    int C[] = {-2, -1, 0, 2};
    vector<ListNode *> lists;
    lists.push_back(LinkedList<int>::make(A, sizeof(A)/sizeof(A[0])));
    lists.push_back(LinkedList<int>::make(B, sizeof(B)/sizeof(B[0])));
    lists.push_back(LinkedList<int>::make(C, sizeof(C)/sizeof(C[0])));

    Solution solve;
    ListNode * c = solve.mergeKLists(lists);
    for (const ListNode * x=c; x; x=x->next)
        printf("%d ", x->val);
    printf("\n");
    return 0;
}

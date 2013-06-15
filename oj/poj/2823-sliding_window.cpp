/* {{{ +++++++++++++++++++++++
 * Description
 * An array of size n ≤ 10^6 is given to you. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves rightwards by one position.
 *  Your task is to determine the maximum and minimum values in the sliding window at each position. 
 * 
 *  Input
 *  The input consists of two lines. The first line contains two integers n and k which are the lengths of the array and the sliding window. There are n integers in the second line. 
 *
 *  Output
 *  There are two lines in the output. The first line gives the minimum values in the window at each position, from left to right, respectively. The second line gives the maximum values. 
 *
 *  Sample Input
 *  8 3
 *  1 3 -1 -3 5 3 6 7
 *
 *  Sample Output
 *  -1 -3 -3 -3 3 3
 *  3 3 5 5 6 7
 * ---------------------------}}}*/
#include <stdio.h>
#include <deque>
using namespace std;

struct node {
    int pos;
    int val;
};

/* 这里应该自行实现队列支持二分查找插入 */
void insert_imp(deque<node> & rdq, int val, int pos) {
    node n;
    n.val = val, n.pos = pos;
    while (rdq.size() && n.val <= rdq.front().val) rdq.pop_front();

    rdq.push_front(n);
}

/*follow up: 请分析为何这里的时间复杂度是O(n)*/
int window_extractor(const int * num, int nsize, int wsize) {
    deque<node> dq;
    for (int i=0; i<wsize && i<nsize; ++i) 
        insert_imp(dq, num[i], i);

    printf("%d", dq.back().val);
    for (int i=wsize; i<nsize; ++i) {
        insert_imp(dq, num[i], i);

        if (dq.back().pos+wsize <= i)
            dq.pop_back();
        printf(" %d", dq.back().val);
    }

    return 0;
}

int main(int argc, char * argv[]) {
    int num_size, window_size;
    scanf("%d%d", &num_size, &window_size);
    if (num_size > 0 && window_size > 0) {
        int * num = new int[num_size];
        for (int i=0; i<num_size; ++i)
            scanf("%d", &num[i]);

        window_extractor(num, num_size, window_size);
        delete [] num;
    }

    return 0;
}

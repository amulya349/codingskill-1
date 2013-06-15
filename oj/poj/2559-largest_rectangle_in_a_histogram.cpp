/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * follow up: 请分析这里的时间复杂度
 * -------------------------------------------------------------}}}*/
#include <iostream>
#include <stdlib.h>
#include "limits.h" 
#include "stdio.h" 
using namespace std; 

struct Point {
    int64_t data;
    long left;  // 往左边数，第一个小于data
    long right; // 向右边数，第一个小于data
};

int main(int argc, char *argv[]) {
    int nums;
    while (cin >> nums && nums) {
        Point block[nums+2];
        block[0].data = -1;
        block[nums+1].data = -1;
        for (int i=1; i<=nums; ++i) {
            scanf("%ld", &block[i].data);
            block[i].left = i;
            block[i].right = i;
        }

        for (int head=1, tail=nums; head<=nums; ++head,--tail) {
            if (block[block[head].left-1].data >= block[head].data)
                block[head].left = block[block[head].left-1].left;
            if (block[block[tail].right+1].data >= block[tail].data)
                block[tail].right = block[block[tail].right+1].right;
        }

        int64_t max = 0;
        int64_t now = 0;
        for (int i=1; i<=nums; ++i) {
            now = block[i].data * (block[i].right-block[i].left+1);
            if (now > max) max = now;
        }
        cout << max << endl;
    }
    return 0; 
}

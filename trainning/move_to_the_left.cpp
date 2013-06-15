/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * [1, 0, 4, -3, 0, 0, 2]
 * 
 * valid output
 * [1, 4, -3, 2, 0, 0, 0]
 * [1, 4, -3, 2, 3, 3, 3]
 * [1, 4, 2, -3, 1, -1, 1]
 * 
 * move non-zero elements to the left
 * in place
 * return # non-zero elements
 * minimize the number of writes to the array
 * you don't have to maintain the original order of the elements
 * the zero elements don't have to remain 0
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../util/io.h"
using namespace std;

int movetotheLeft(vector<int> & arr) {
    int c=0;
    for (int a=0,b=arr.size()-1; a<=b; ) {
        while (a<=b && arr[a]!=0) ++a, ++c;
        while (a<=b && arr[b]==0) --b;

        if (a<b) {
            ++c;
            arr[a++]=arr[b--];
        }
    }
    return c;
}

int main(int argc, char * argv[]) {
    int a[] = {1, 0, 4, -3, 0, 0, 2, 0};
    vector<int> arr(a, a+sizeof(a)/sizeof(a[0]));
    UIO<int>::pr(arr);
    int ans = movetotheLeft(arr);
    UIO<int>::pr(arr);
    printf("%d\n", ans);

    return 0;
}

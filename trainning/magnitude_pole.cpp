/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 找array的一个点，所有左边的数字不大于它，右边不小于它。要求O(N)
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>
#include <vector>
using namespace std;

int magnitude(int a[], int n) {
    vector<int> inc;
    for (int i=0; i<n; ++i)
        if (inc.size() == 0 || a[inc.back()] <= a[i])
            inc.push_back(i);

    int povit=INT_MAX;
    for (int i=n-1; i>=0; --i) {
        povit = min(povit, a[i]);
        if (i == inc.back()) {
            if (povit == a[i])
                return i;
            inc.pop_back();
        }
    }
    return -1;
}

void honglei(int a[], int n) {
    if (n <= 0) return;
    int ans = magnitude(a, n);
    for (int i=0; i<ans; ++i)
        printf("%d ", a[i]);
    if (ans >=0 )
        printf("[%d] ", a[ans]);
    for (int i=ans+1; i<n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char * argv[]) {
    int a[] = {1,3,2,5,8,7,6,7};
    honglei(a, sizeof(a)/sizeof(a[0]));
    int b[] = {2,3,1};
    honglei(b, sizeof(b)/sizeof(b[0]));
    int c[] = {2};
    honglei(c, sizeof(c)/sizeof(c[0]));
    int d[] = {2,2,2,2,2,2};
    honglei(d, sizeof(d)/sizeof(d[0]));
    return 0;
}

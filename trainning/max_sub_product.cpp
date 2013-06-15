/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 给定一个整数数组，求最大的子数组的乘积
 * 
 * 计算小于0的个数
 * 计算等于0的个数
 * -------------------------------------------------------------}}}*/
#include <string.h>
#include <iostream>
#include <limits.h>
using namespace std;

void calc_max_product(const int a[], int n) {
    int max_negative = INT_MIN;
    int l0 = 0;
    int e0 = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] < 0) {
            ++l0;
            max_negative = max(max_negative, a[i]);
        }
        else if (a[i] == 0) {
            ++e0;
        }
    }

    if ((e0 == n-1 && l0 == 1) || e0 == n) // 这种情况最大值是0
        return;

    bool bOddLessZero = false;
    if (l0&1) // 奇数个负数，只要除去绝对值最小的负数(最接近于0)
        bOddLessZero = true;

    for (int i=0; i<n; ++i) {
        if (a[i] == 0)
            continue;
        else if (bOddLessZero && a[i] == max_negative)
            bOddLessZero = false;
        else
            cout << a[i] << " ";
    }
}

template<typename T>
T maxproduct(const T a[], int n) {
    T postive(0), negative(0), ans=0;
    for (int i=0; i<n; ++i) {
        if (a[i]>=0) {
            postive = max(postive*a[i], a[i]);
            negative = negative*a[i];
        }
        else {
            T pprev = postive;
            postive = negative*a[i];
            negative = min(pprev*a[i], a[i]);
        }
        ans = max(postive, ans);
    }
    return ans;
}

int main() {
    int num;
    cout << "input size of err : ";
    cin >> num;
    while (num > 0) {
        double aiArr[num];
        memset(aiArr, 0, sizeof(aiArr));
        cout << "plz type " << num << " integers : ";
        for (int i=0; i<num; ++i)
            cin >> aiArr[i];

        cout << "ans=" << maxproduct(aiArr, num) << endl;
        // calc_max_product(aiArr, num);

        cout << endl << "input size of err : ";
        cin >> num;
    }
    return 0;
}

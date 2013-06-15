/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Description: 
 *  对于某些正整数，可以表示连续N个正整数的和的形式(N>1)
 *  现输入一个正整数M，请输出所有的表示方式。
 * -------------------------------------------------------------}}}*/

#include <iostream>
#include <math.h>

using namespace std;

int calc_continue_sum(int InSum) {
    double M = InSum;
    int iTypes = 0; // 不同的表现个数
    double Start;
    for (int N=(int)sqrt(2*M)-1; N >= 2; --N) {
        Start = M/N -((double)N-1)/2;
        if (Start == (int)Start) {
            cout << Start << "(" << N << ")" << endl;
            ++iTypes;
        }
    }

    return iTypes;
}

int main() {
    int InSum;
    cout << "plz input an integer : ";
    cin >> InSum;
    if (InSum <= 0) {
        cout << InSum << " is illegal" << endl;
        return -1;
    }

    calc_continue_sum(InSum);
    return 0;
}

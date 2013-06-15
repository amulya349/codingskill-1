/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *  f(n) 表示所有小于n的数中说包含1的个数
 *  例如 f(1)=1, f(11)=4
 *
 *  解法：
 *  假设g(n)表示0～999...9(n个9)之间, 也就是0~n位数所有1的个数
 *  容易得到 g(n) = 10*g(n-1)+10^(n-1), g(0)=0, g(1)=1
 *
 *  下边求通项公式；
 *  方法1 : 数学归纳法，比较无聊但是很有用
 *  方法2 : 一般类似这种带有杂项的递推式，大约有两种方式进行凑配
 *  2.1 两边同时加上一个项式（可以是和对应的n，n-1相关的）
 *  2.2 两边同时除去一个项式（当然也可以和对应n，n-1相关）
 *
 *  这里就是两边同时除以10^n，得到 (g(n)/10^n)=(g(n-1)/10^(n-1))+1/10
 *  呵呵，这就变成 k(n)=k(n-1)+0.1了，可以得到 g(n)=n*10^(n-1)
 * -------------------------------------------------------------}}}*/
#include <math.h>
#include <iostream>
using namespace std;

inline int cal_one_num_bit(int ten_bits) {
    return ten_bits*(int)pow(10, ten_bits-1);
}

int cal_one_num(int n) {
    if (n <= 0)
        return 0;

    int ten_bits  = 0; // 位数
    int first_bit = 0; // 首位
    int m = n;
    while (m) {
        ++ ten_bits;
        first_bit = m;
        m /= 10;
    }
    int left_bit = n-first_bit*pow(10, ten_bits-1);

    if (first_bit == 1) // 0打头到999..9 + 100..0~n之间1的个数 + 剩余部分1的个数
        return cal_one_num_bit(ten_bits-1) + left_bit + 1 + cal_one_num(left_bit); 
    else
        return first_bit*cal_one_num_bit(ten_bits-1)+pow(10, ten_bits-1)+cal_one_num(left_bit);
}

int main() {
    cout << cal_one_num(1000000000) << endl;
    return 0;
}

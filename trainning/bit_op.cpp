/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 1、 计算整数的二进制表示中1的个数
 * 2、 计算整数的二进制表示中末尾0的个数，神一样的方法 
 * http://graphics.stanford.edu/~seander/bithacks.html
 * http://www.matrix67.com/blog/archives/3985
 * -------------------------------------------------------------}}}*/

#include <iostream>
#include <algorithm>

using namespace std;

/* {{{ 二进制表示 */
template <typename T>
string bin_display(T a) {
    string s;
    for (size_t sz=0; sz<8*sizeof(a); ++sz) {
        if (a&1)
            s += "1";
        else
            s += "0";
        a >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
/* }}} */

/* {{{ 求1的个数，该方法已经是比较牛的 */
template <typename T>
size_t bin_1_cnt(T t) {
    size_t szNum = 0;
    while (t) {
        ++szNum;
        t = t & (t-1);
    }
    return szNum;
}
/*}}}*/

/* {{{ 求二进制表示中末尾0个数的方法，该方法是神写的 */
size_t bin_tail_0_cnt_v2(int t) {
    static const size_t MultiplyDeBruijnBitPosition[32] = {
        0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
        31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
    };
    return MultiplyDeBruijnBitPosition[((int)((t & -t) * 0x077cb531U)) >> 27];
}
/*}}}*/

inline void HandleInput(size_t & szStart, size_t & szEnd, size_t szOverFlow) {
    szStart = (szStart<1 ? 1:szStart);
    szEnd = (szEnd>szOverFlow ? szOverFlow:szEnd);
    if (szStart > szEnd) {
        szStart ^= szEnd;
        szEnd ^= szStart;
        szStart ^= szEnd;
    }
    return;
}

/* {{{ 反转指定范围的位，交换*/
template <typename T>
T reverse_bit(T t, size_t szStart=1, size_t szEnd=8*sizeof(T)) {
    HandleInput(szStart, szEnd, 8*sizeof(T));

    T tRet = t;
    T tInputPos = 1<<(8*sizeof(T)-szEnd);
    T tRetPos = 1<<(8*sizeof(t)-szStart);
    for (; szStart<=szEnd; ++szStart) {
        if (t & tInputPos)
            tRet |= tRetPos;
        else
            tRet &= ~tRetPos;
        tInputPos <<= 1;
        tRetPos >>= 1;
    }
    return tRet;
}
/*}}}*/

/*{{{ 生成000..011..100..0形式的掩码。从右边开始数第low个开始往左数到第high个*/
template <typename T>
void GenMask(T & t, size_t low, size_t high) {
    t = ((1<<(high+1))-1)^((1<<low)-1);
    return;
}
/*}}}*/

int main(int argc, char * argv[]) {
    unsigned short bit;
    while (cin >> bit && bit) {
        /*
         * 数0 啊 1 啊这些阿猫阿狗的数目
         * cout << bin_display(bit) << endl;
         * cout << bin_1_cnt(bit) << endl;
         * cout << bin_tail_0_cnt(bit) << endl;
         **/
        cout << bit << " : " << bin_display(bit) << endl;
        unsigned short rbit = reverse_bit(bit, 13, 15);
        cout << rbit << " : " << bin_display(rbit) << endl;
    }

    return 0;
}

#include <string.h>
#include <iostream>

const size_t Max_Str_Len = 100;
char backtrace[Max_Str_Len][Max_Str_Len];

using namespace std;

/*{{{dp 滚动数组的方法, 在leetcode/distinct_subsequences.cpp 中实现*/
int lcs_dp(const char * X, const char * Y) {
    size_t xlen = strlen(X);
    size_t ylen = strlen(Y);
    int counter[ylen+1][xlen+1];
    for (size_t i=0; i<=xlen; ++ i)
        counter[0][i] = 0;
    for (size_t i=1; i<=ylen; ++ i)
        counter[i][0] = 0;

    for (size_t iy=1; iy<=ylen; ++iy) {
        for (size_t ix=1; ix<=xlen; ++ix) {
            if (X[ix-1] == Y[iy-1]) {
                counter[iy][ix] = counter[iy-1][ix-1]+1;
                backtrace[iy][ix] = '\\'; // 前续来自左上角
            }
            else { // 不相等
                if (counter[iy][ix-1] > counter[iy-1][ix]) {
                    counter[iy][ix] = counter[iy][ix-1];
                    backtrace[iy][ix] = '|'; 
                }
                else {
                    counter[iy][ix] = counter[iy-1][ix];
                    backtrace[iy][ix] = '-';
                }
            }
        }
    }

    return counter[ylen][xlen];
}
/*}}}*/

/*{{{ 递归方法*/
template <typename T> inline T Bigger(T a, T b) { return (a > b? a : b); }

int lcs_recurse(const char * X, const char * Y, int xLastPos, int yLastPos) {
    if (xLastPos < 0 || yLastPos < 0)
        return 0;

    if (X[xLastPos] == Y[yLastPos])
        return lcs_recurse(X, Y, xLastPos-1, yLastPos-1)+1;
    else
        return Bigger(lcs_recurse(X, Y, xLastPos-1, yLastPos), lcs_recurse(X, Y, xLastPos, yLastPos-1));
}
/*}}}*/

/*{{{ print */
void Print_Lcs(const char * X, size_t ix, size_t iy) {
    if (!X || ix == 0 || iy == 0)
        return ;

    if (backtrace[iy][ix] == '\\') {
        Print_Lcs(X, ix-1, iy-1);
        cout << X[ix-1];
    }
    else if (backtrace[iy][ix] == '|') {
        Print_Lcs(X, ix-1, iy);
    }
    else if (backtrace[iy][ix] == '-') {
        Print_Lcs(X, ix, iy-1);
    }
    return ;
}
/*}}}*/

int main() {
    cout << "plz input 2 strings : " << endl;
    string strX, strY;
    cin >> strX >> strY;
    if (strX.size() > Max_Str_Len || strY.size() > Max_Str_Len) {
        cout << "too long string" << endl;
        return -1;
    }

    cout << endl << "-- common string --" << endl;
    cout << "max length  : " << lcs_dp(strX.c_str(), strY.c_str()) << endl;
    cout << "composed by : ";
    Print_Lcs(strX.c_str(), strX.size(), strY.size());
    cout << endl << endl;

    return 0;
}

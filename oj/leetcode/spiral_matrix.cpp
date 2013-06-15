/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a matrix of m x n elements (m rows, n columns), \
 * return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *  [
 *      [ 1, 2, 3 ],
 *      [ 4, 5, 6 ],
 *      [ 7, 8, 9 ]
 *  ]
 * You should return [1,2,3,6,9,8,7,4,5].
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
struct tMatrix2D {
    T * pData;
    size_t Lines; 
    size_t Rows;
};

void _print_around(const tMatrix2D<int> & M, int XBegin, int YBegin, int XEnd, int YEnd) {
    if (XBegin > XEnd || YBegin > YEnd) return; // XBegin > XEnd || YBegin > YEnd 结束

    for (int x=XBegin;   x<=XEnd; ++x) cout << M.pData[x+YBegin*M.Rows] << " ";
    for (int y=YBegin+1; y<=YEnd; ++y) cout << M.pData[XEnd+y*M.Rows]   << " ";
    if (YBegin != YEnd) // 只有一列时候已经显示完成
        for (int x=XEnd-1; x>=XBegin; --x)   cout << M.pData[x+YEnd*M.Rows]   << " ";
    if (XBegin != XEnd) // 只有一行...
        for (int y=YEnd-1; y>=YBegin+1; --y) cout << M.pData[XBegin+y*M.Rows] << " ";

    return _print_around(M, XBegin+1, YBegin+1, XEnd-1, YEnd-1);
}

void print_matrix(int Lines, int Rows) {
    int A[Lines][Rows];
    for (int y=0; y<Lines; ++y) {
        for (int x=0; x<Rows; ++x) {
            A[y][x] = y*Rows+x+1;
            printf("%d\t", A[y][x]);
        }
        printf("\n");
    }
    tMatrix2D<int> M;
    M.pData = &A[0][0];
    M.Lines = Lines;
    M.Rows  = Rows;
    return _print_around(M, 0, 0, Rows-1, Lines-1);
}

int main(int argc, char * argv[]) {
    unsigned int Lines, Rows;
    printf("input m & n, 0 for quit\n");
    while ((cin >> Lines && Lines) && (cin >> Rows && Rows)) {
        printf("===>\n");
        print_matrix(Lines, Rows);
        printf("input m & n, 0 for quit\n");
    }
    return 0;
}

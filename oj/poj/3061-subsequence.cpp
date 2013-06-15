/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Description
 * A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
 *
 * Input
 * The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
 *
 * Output
 * For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
 *
 * Sample Input
 * 2
 * 10 15
 * 5 1 3 5 10 7 4 9 2 8
 * 5 11
 * 1 2 3 4 5
 *
 * Sample Output
 * 2
 * 3
 * -------------------------------------------------------------}}}*/
#include <iostream>
#include <cstdio>
using namespace std;

inline size_t tLessItem(size_t l, size_t r) { return l < r ? l : r; }

size_t over_sub(int * iArry, size_t szArrySize, size_t szSum) {
    if (!iArry || szArrySize == 0)
        return 0;

    size_t szMinLen = szArrySize+1;
    size_t szLeft = 0;
    size_t szRight = 0;
    size_t szNowSum = iArry[0];
    while (szRight < szArrySize) {
        if (szNowSum < szSum) {
            szNowSum += iArry[++szRight];
        }
        else {
            while (szLeft <= szRight && szNowSum >= szSum)
                szNowSum -= iArry[szLeft++];

            if (szLeft > szRight)  // 某一个数的值大于和，直接就返回1
                return 1;
            else 
                szMinLen = tLessItem(szMinLen, szRight-szLeft+2);
        }
    }
    if (szMinLen > szArrySize) return 0;
    else	return szMinLen;
}

int main(int argc, char * argv[]) {
    size_t szLines = 0;
    cin >> szLines;
    while (szLines--) {
        size_t szNums, szSum;
        cin >> szNums >> szSum;
        int inputs[szNums];
        for (size_t sz=0; sz<szNums; ++sz)
            scanf("%d", &inputs[sz]);

        cout << over_sub(inputs, szNums, szSum) << endl;
    }
    return 0;
}

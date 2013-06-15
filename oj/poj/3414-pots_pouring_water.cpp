/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * [Description]
 * You are given two pots, having the volume of A and B liters respectively. 
 * The following operations can be performed:
 * FILL(i)    fill the pot i (1 ≤ i ≤ 2) from the tap;
 * DROP(i)    empty the pot i to the drain;
 * POUR(i,j)  pour from pot i to pot j; after this operation either the pot j \
 *            is full (and there may be some water left in the pot i), or the \
 *            pot i is empty (and all its contents have been moved to the pot j).
 *
 * Write a program to find the shortest possible sequence of these operations 
 * that will yield exactly C liters of water in one of the pots.
 *
 * Input
 * On the first and only line are the numbers A, B, and C. \
 * These are all integers in the range from 1 to 100 and C≤max(A,B).
 *
 * Output
 * The first line of the output must contain the length of the sequence of \
 * operations K. The following K lines must each describe one operation. \
 * If there are several sequences of minimal length, output any one of them. \
 * If the desired result can’t be achieved, the first and only line of \
 * the file must contain the word ‘impossible’.
 *
 * Sample Input
 * 3 5 4
 *
 * Sample Output
 * 6
 * FILL(2)
 * POUR(2,1)
 * DROP(1)
 * POUR(2,1)
 * FILL(2)
 * POUR(2,1)
 * -------------------------------------------------------------}}}*/
#include <string>
#include <iostream>
using namespace std;
string s = " \
 * a,b两个容器,要得到c的水, 假设a>b && a>c, 这里单说思路 \
 * \
 * 定理: 如果a,b互质, 则通过倒水过程, 可以得到[1, a]之间的任意一个容量; \
 *       如果a,b存在最大公因子f, 则f*i (i的范围: [1, a/f])的容量是可达成的. \
 * \
 * 定理前半部分的证明: \
 *      对于i属于[1, a], (i*b)%a有a个数, 其大小总是介于0与a-1之间. 证明如下: \
 *          假设存在x1, x2使得(x1*b)%a = (x2*b)%a = M, 即同余M. \
 *          则 x1*b = a*m1+M, x2*b = a*m2+M \
 *          即 (x1-x2)*b = (m1-m2)*a, 这与a,b互质矛盾 \
 *      因此a个介于0与a-1之间的数两两不同, 那必然是取遍了0~a-1之间的每一个值 \
 * 定理的第二部分不言自明 # \
 * \
 * 遗憾的是, 定理虽然告诉了如何去达成目标的一种解, 但未必是最快解, 因为解答只有 \
 * 从b往a倒水一个动作. \
 * 最快解的一个宽搜方法: http://yzmduncan.iteye.com/blog/869281 \
 *";
int main(int argc, char * argv[]) {
    cout << s << endl;
    return 0;
}

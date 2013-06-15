/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Description: 
 * 对于N次硬币的投掷，要求至少连续出现K次正面的概率(K<=N)
 * 
 * 实现 : 设C(N,K)为N次投掷至少出现连续K次正面的次数
 * 那么，C(N,K)=C(N-1,K)*2+2^(N-K-1)-C(N-K-1,K)
 * N-1个中出现的次数 + N-1个中最后K-1个为正面且倒数第K个为反面 - 两者重复部分
 * -------------------------------------------------------------}}}*/

#include <iostream>
#include <cmath>

using namespace std;

unsigned int C(int N, int K) {
    if (N > K)			
        return 2*C(N-1,K)+pow(2,N-K-1)-C(N-K-1,K);
    else if (N == K)	
        return 1;
    else	
        return 0; // (N < K)
}

int main(int argc, char * argv[]) {
    unsigned int N, K;
    double dPro;
    while (cin>>N && N) {
        cin >> K;
        if (N <= 32 && N >= K) {
            dPro = C(N, K)/pow(2, N);
            cout << "CALC(" << N << ", " << K << ")=" << dPro*100 << endl;
        }
        else {
            cout << "wrong input!!!" << endl;
        }
    }

    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
* 2. Prime Generator
* Problem code: PRIME1
* 
* Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
* 
* Input
* 
* The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
* 
* Output
* 
* For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
* 
* Example
* 
* Input:
* 2
* 1 10
* 3 5
* 
* Output:
* 2
* 3
* 5
* 7
* 
* 3
* 5
* Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
 * 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

const int MAX_PRIMER = 1000000000; // 生成10^9之內的素數, 根据需要可以调整
const int MAX_PRE_SIEVE = sqrt(MAX_PRIMER);

void siever(bool * composite, int size) { // 预先生成筛选数组
    memset(composite, 0, size*sizeof(bool));
    for (int i=2; i<size; ++i) {
        if (composite[i]) 
            continue;
        for (int j=i<<1; j<size; j+=i)
            composite[j] = true;
    }
}

// 生成从s开始到e结束的素数, s <= e <= MAX_PRIMER
void gen_prime(int s, int e, const bool * composite_sieve) {
    if (s > e || s < 0 || e < 0)
        return;
    if (s <= 1)
        s = 2;

    const int total = e-s+1;
    bool * num = new bool[total];
    memset(num, 0, total*sizeof(bool));
    int run;
    for (int i=2; i<=MAX_PRE_SIEVE && i<e; ++i) {
        if (composite_sieve[i]) // else if a prime
            continue;

        if (s <= i) {
            run = i<<1;
        }
        else {
            run = (s/i)*i;
            if (run != s)
                run += i;
        }

        for (; run <= e; run += i) {
            if (!num[run-s])
                num[run-s] = true;
        }
    }

    for (int j=0; j<total; ++j) {
        if (!num[j])
            printf("%d\n", s+j);
    }
    delete[] num;
}

int main(int argc, char * argv[]) {
    bool * composite_sieve = new bool[MAX_PRE_SIEVE+1];
    siever(composite_sieve, MAX_PRE_SIEVE+1);

    int loops;
    scanf("%d", &loops);
    int s, e;
    for (int i=0; i<loops; ++i) {
        scanf("%d%d", &s, &e);
        gen_prime(s, e, composite_sieve);
        printf("\n");
    }

    delete[] composite_sieve;

    return 0;
}

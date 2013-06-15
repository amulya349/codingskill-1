#ifndef PRIME_H_20130217
#define PRIME_H_20130217
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>

class Primes {
    public:
        Primes(long max_prime);
        std::vector<long> factorize(long);
        ~Primes();
    private:
        Primes() {}
    private:
        long * primes_;
        int primes_num_;
};

Primes::Primes(long max_prime) : primes_(NULL), primes_num_(0) {
    long sieve_num = 1+sqrt(max_prime);
    bool * composite = new bool[sieve_num];
    memset(composite, 0, sieve_num*sizeof(bool));
    for (long i=2; i<=sieve_num; ++i) {
        if (!composite[i]) {
            ++primes_num_;
            for (int j=i*2; j<=sieve_num; j+=i) 
                composite[j] = true;
        }
    }

    primes_ = new long[primes_num_];
    for (long i=2, j=0; i<=sieve_num; ++i) 
        if (!composite[i]) 
            primes_[j++] = i;
    delete [] composite;
}

Primes::~Primes() {
    delete [] primes_;
}

std::vector<long> Primes::factorize(long y) {
    long x = y>0?y:-y;
    std::vector<long> ans;
    for (int i=0; i<primes_num_ && x>0; ) {
        long d = x/primes_[i];
        if (x == d*primes_[i]) {
            ans.push_back(primes_[i]);
            x = d;
        }
        else {
            ++i;
        }
    }
    if (x != 0) ans.push_back(x);
    if (y <  0) ans[0] = -ans[0];
    return ans;
}
#endif


#include <stdio.h>
#include <vector>
#include "prime.h"
#include "../util/io.h"
using namespace std;

int main(int argc, char * argv[]) {
    long cpno = 86404506111;
    Primes pm(cpno);
    vector<long> vl;
    for (long x=cpno; x>=0; --x) {
        vl = pm.factorize(x);
        if (vl.size() == 1) {
            UIO<long>::pr(vl);
            x -= vl[0];
            ++x;
        }
    }
    return 0;
}

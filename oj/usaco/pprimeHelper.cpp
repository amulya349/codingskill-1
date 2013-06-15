/*
ID:myxjtu1
PROG:pprime
LANG:C++
*/
/* 10^8 直接brute force刚好有内存风险，位筛选需要12.5M
 * 注意到abba形的可以被11整除(归纳法证明), 因此必须为aba形的回文
 * 这样数据规模马上降到了(0, 10^7)，位图筛选1.25M无忧
 *
 * 接下来就是构造回文, 查筛选表即可
 * */
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

const int MAX_NUM = 10000000;
const int EVERYLINE = 15;
/*{{{ class BitMap */
class BitMap {
    public:
        explicit BitMap(size_t num) : num_(num), bits_(NULL) {
            bits_ = new char[num_];
            memset(bits_, 0, num_);
        }
        inline void set(size_t k) {
            if (k<num_&&bits_)
                bits_[k/8] |= (1<<(k%8));
        }
        inline bool is(size_t k) const {
            return (k<num_&&bits_) && (bits_[k/8]&(1<<(k%8)));
        }
        inline size_t getLen() {
            return num_;
        }
        ~BitMap() {
            if (bits_) delete [] bits_;
        }
    private:
        BitMap() {}
        BitMap operator=(const BitMap & rhs) { return rhs;}
    private:
        size_t num_;
        char * bits_;
}; /*}}}*/

/*{{{ output() */ 
int output(const vector<int> & a) {
#ifdef DBG 
    ostream & out = cout;
#else
    ofstream fout("pprime.out");
    if (!fout) return -2;
    ostream & out = fout;
#endif
    const int LEN = a.size();
    for (int i=0,j=1; i<=LEN-2; ++i,++j) {
        out << a[i] << ","; 
        if (j == EVERYLINE)
            j=0, out << "\\" << endl;
    }
    if (LEN > 0)
        out << a[LEN-1];
    out << endl;
    return 0;
} /*}}}*/

/*{{{ core function */
void genComposite(BitMap & composite){
    const size_t LEN = composite.getLen();
    const size_t SIEVE_LEN=sqrt(LEN);

    for (size_t i=2; i<=SIEVE_LEN; ++i) if (!composite.is(i)) 
        for (size_t j=i+i; j<LEN; j+=i) if (!composite.is(j))
            composite.set(j);
}

int reverse(int x) {
    int ans = x%10;
    for (x/=10; x; x/=10) {
        ans *= 10;
        ans += x%10;
    }
    return ans;
}

void pprime(vector<int> & ans, const BitMap & composite) {
    for (int i=2; i<=11; ++i) if (!composite.is(i))
        ans.push_back(i);
    for (int c=1; c<=100; c*=10) {
        for (int i=c; i<10*c; ++i) {
            for (int j=0; j<=9; ++j) {
                int pp=i*100*c+j*10*c+reverse(i);
                if (!composite.is(pp))
                    ans.push_back(pp);
            }
        }
    }
}
/*}}}*/

int main(int argc, char * argv[]) {
    vector<int> ans;
    BitMap composite(MAX_NUM);
    genComposite(composite); // 生成合数表
    pprime(ans, composite);
    return output(ans);
}

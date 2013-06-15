/*
ID:myxjtu1
PROG:sprime
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
#include <math.h>
using namespace std;

const int MAX_NUM=80000000;

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

void gen_sieve(vector<int> & sieve) {
    const size_t SIEVE_LEN=sqrt(MAX_NUM)+1;
    const size_t SIEVE2=sqrt(SIEVE_LEN);
    BitMap composite(SIEVE_LEN);

    for (size_t i=2; i<=SIEVE2; ++i) if (!composite.is(i)) 
        for (size_t j=i+i; j<SIEVE_LEN; j+=i) if (!composite.is(j))
            composite.set(j);
    for (size_t i=2; i<SIEVE_LEN; ++i) if (!composite.is(i))
        sieve.push_back(i);
}

bool isprime(const vector<int> & siv, int c) {
    const int c2 = sqrt(c);
    for (int i=0; siv[i]<=c2; ++i) if (c%siv[i] == 0)
        return false;
    return true;
}

void bfs(deque<int> & ans, int N, const vector<int> & siv) {
    const int choices[4]={1,3,7,9};
    for (int i=1; i<N; ++i) {
        int ilen=ans.size();
        for (int j=0; j<ilen; ++j) {
            int s=10*ans.front(); ans.pop_front();
            for (int k=0; k<4; ++k) if (isprime(siv, s+choices[k]))
                ans.push_back(s+choices[k]);
        }
    }
}

int output(const deque<int> & ans) {
#ifdef DBG 
    ostream & out = cout;
#else
    ofstream fout("sprime.out");
    if (!fout) return -2;
    ostream & out = fout;
#endif
    const int LEN = ans.size();
    for (int i=0; i<LEN; ++i)
        out << ans[i] << endl;
    return 0;
}

int main(int argc, char * argv[]) {
    ifstream fin("sprime.in");
    if (!fin) return -1;
    int N; fin >> N;
    vector<int> sieve;
    gen_sieve(sieve);

    deque<int> ans(4);
    ans[0]=2, ans[1]=3, ans[2]=5, ans[3]=7;
    bfs(ans, N, sieve);

    return output(ans);
}

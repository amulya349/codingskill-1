/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            if (n<=0 || k<=0 || n>9) return "";

            int PERM[n]; // calc n!
            PERM[0] = 1;
            for (int i=1; i<n; ++i)
                PERM[i] = i*PERM[i-1];
            char ALL[n+1];
            for (int i=sizeof(ALL)/sizeof(ALL[0])-1; i >= 0; --i)
                ALL[i] = '0'+i;

            string strp;
            PermWrapper(strp, n, k, PERM, ALL, 1);
            return strp;
        }
    private:
        void PermWrapper(string & rstrp, int n, int k, int * PERM, char * ALL, int run) {
            if (run > n) return;

            int div = (k-1)/PERM[n-run];
            k -= div*PERM[n-run];
            rstrp += ALL[div+run];
            for (int i=div+run; i>run; --i)
                ALL[i] = ALL[i-1];
            return PermWrapper(rstrp, n, k, PERM, ALL, run+1);
        }
};

int main(int argc, char * argv[]) {
    Solution solve;
    cout << solve.getPermutation(9, 218590) << endl;
    return 0;
}

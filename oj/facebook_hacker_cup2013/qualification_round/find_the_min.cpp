/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * After sending smileys, John decided to play with arrays. 
 * Did you know that hackers enjoy playing with arrays? 
 * John has a zero-based index array, m, which contains n non-negative integers. 
 * However, only the first k values of the array are known to him, and he wants to figure out the rest.
 * 
 * John knows the following: for each index i, where k <= i < n, 
 * m[i] is the minimum non-negative integer which is *not* contained in the *previous k* values of m.
 * 
 * For example, if k = 3, n = 4 and the known values of m are [2, 3, 0], he can figure out that m[3] = 1.
 * 
 * John is very busy making the world more open and connected, 
 * as such, he doesn't have time to figure out the rest of the array. 
 * It is your task to help him.
 * 
 * Given the first k values of m, calculate the nth value of this array. (i.e. m[n - 1]).
 * 
 * Because the values of n and k can be very large, 
 * we use a pseudo-random number generator to calculate the first k values of m.
 * Given positive integers a, b, c and r, the known values of m can be calculated as follows:
 * m[0] = a
 * m[i] = (b * m[i - 1] + c) % r, 0 < i < k
 *
 *
 * Input
 * The first line contains an integer T (T <= 20), the number of test cases.
 * This is followed by T test cases, consisting of 2 lines each.
 * The first line of each test case contains 2 space separated integers, n, k (1 <= k <= 105, k < n <= 109).
 * The second line of each test case contains 4 space separated integers a, b, c, r (0 <= a, b, c <= 109, 1 <= r <= 109).
 *
 * Output
 * For each test case, output a single line containing the case number and the nth element of m.
 *
 * Example input
 * 5
 * 97 39
 * 34 37 656 97
 * 186 75
 * 68 16 539 186
 * 137 49
 * 48 17 461 137
 * 98 59
 * 6 30 524 98
 * 46 18
 * 7 11 9 46
 *
 * Example output
 * Case #1: 8
 * Case #2: 38
 * Case #3: 41
 * Case #4: 40
 * Case #5: 12
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

void make_known(int m[], int k, long long a, int b, int c, int r) {
    set<int> s;
    pair<set<int>::iterator, bool> pr;
    for (int i=0; i<k; ++i) {
        pr = s.insert(a);
        if (!pr.second) { // already exists
            int f=0;
            while (a != m[f]) ++f;
            while (i<k) m[i++] = m[f++];
            return;
        }
        m[i] = a;
        a = (b*a+c)%r;
    }
}

int apperance(int m[], int k, int mtimes[], set<int> & nom) {
    memset(mtimes, 0, (k+1)*sizeof(int));
    for (int i=0; i<k; ++i)
        if (m[i]<=k)
            ++mtimes[m[i]];

    int valids = 0;
    for (int i=0; i<=k; ++i) {
        if (mtimes[i] == 0)
            nom.insert(i);
        else
            ++valids;
    }

    m[k] = *nom.begin(); // append tail
    nom.erase(nom.begin());
    ++mtimes[m[k]];
    return 1+valids;
}

unsigned int solve(int n, int k, int a, int b, int c, int r) {
    int m[k+1];
    make_known(m, k, a, b, c, r);

    int mtimes[k+1];
    set<int> nom;
    int aprc = apperance(m, k, mtimes, nom); // aprc : apperance of less equal k

    n -= (k+2);
    for (int g=0; aprc<=k && g<=n; ++g,++aprc) {
        int tmp = m[g];
        m[g] = *nom.begin();
        nom.erase(nom.begin());
        ++mtimes[m[g]]; // unnecessary

        if (tmp <= k) {
            --mtimes[tmp];
            if (mtimes[tmp] == 0) {
                nom.insert(tmp);
                --aprc;
            }
        }
    }
    return n==-1?m[k]:m[n%(k+1)];
}

int main(int argc, char * argv[]) {
    int num;
    scanf("%d\n", &num);
    for (int i=1; i<=num; ++i) {
        int n,k,a,b,c,r;
        scanf("%d%d\n", &n,&k);
        scanf("%d%d%d%d\n", &a,&b,&c,&r);
        printf("Case #%d: %u\n", i, solve(n,k,a,b,c,r));
    }
    return 0;
}

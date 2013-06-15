/*
ID:myxjtu1
PROG:runround
LANG:C++
*/
#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
#ifdef DBG
#include <iostream>
#else
ifstream cin("runround.in");
ofstream cout("runround.out");
#endif

bool isrr(unsigned long n) {
    int b[11]; memset(b, 0, sizeof(b));
    bool apperance[10]={0};
    int len=0;
    for (int i=n, x; i!=0; i/=10) {
        ++len, x=i%10;
        if (x==0||apperance[x]) return false;
        apperance[x]=true, b[len]=x;
    }
    reverse(&b[1], &b[len+1]);

    int i=0, npos=1;
    for (int next; b[npos]>0; npos=next) {
        ++i;
        next=npos%len+b[npos]%len;
        if (next>len) next-=len;
        b[npos]=0;
    }
    return i==len&&npos==1;
}

unsigned long solve(unsigned long M) { // brute force!!!
    unsigned long ans=M+1;
    while (!isrr(ans)) ++ans;
    return ans;
}

int main(int argc, char * argv[]) {
    unsigned long M; cin>>M;
    cout << solve(M) << endl;
    return 0;
}

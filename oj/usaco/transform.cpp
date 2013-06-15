/*
ID:myxjtu1
PROG:transform
LANG:C++
*/
#include <fstream>
#include <iostream>
using namespace std;

const int MAXLEN = 10;
char a[MAXLEN][MAXLEN];
char b[MAXLEN][MAXLEN];

void print(int N) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j)
            cout << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool isSame(int N) {
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void turnhorizon(int N) {
    for (int i=0; i<N; ++i)
        for (int j=0; j<N/2; ++j) {
            char t = a[i][j];
            a[i][j] = a[i][N-1-j];
            a[i][N-1-j] = t;
        }
}

void turn90(int N) {
    if (N <= 1) return;
    for (int j=0; j<N/2; ++j)
        for (int i=j; i<=N-2-j; ++i) {
            char t = a[j][i];
            a[j][i] = a[N-1-i][j];
            a[N-1-i][j] = a[N-1-j][N-1-i];
            a[N-1-j][N-1-i] = a[i][N-1-j];
            a[i][N-1-j] = t;
        }
}

int solve(int N) {
    for (int i=1; i<=3; ++i) {
        turn90(N);
        if (isSame(N)) return i;
    }
    turn90(N);
    turnhorizon(N);
    if (isSame(N)) return 4;
    for (int i=1; i<=3; ++i) {
        turn90(N);
        if (isSame(N)) return 5;
    }
    turn90(N);
    turnhorizon(N);
    if (isSame(N)) return 6;
    return 7;
}

int main(int argc, char * argv[]) {
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    if (!fin || !fout) return -1;
    int N; fin >> N;
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            fin >> a[i][j];
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            fin >> b[i][j];
#ifdef DBG 
    cout << solve(N) << endl;
#else
    fout << solve(N) << endl;
#endif
    return 0;
}

/*
ID:myxjtu1
PROG:milk3
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_NET = 20;
int CUPS[3];
bool status[MAX_NET+1][MAX_NET+1];
bool reachable[MAX_NET+1];

struct AB {
    int a, b;
    AB() : a(0), b(0) {}
};

void inline pour(deque<AB> &run, int x, int y, int direction) {
    int cy=direction%10-1;
    int cx=direction/10-1;
    int all=x+y;
    if (all<CUPS[cy]) x=0, y=all;
    else x=all-CUPS[cy], y=CUPS[cy]; 

    AB ab;
    ab.a=(cx==0?x:(cy==0?y:CUPS[2]-x-y));
    ab.b=(cx==1?x:(cy==1?y:CUPS[2]-x-y));
    run.push_back(ab);
}

void bfs() {
    for (deque<AB> run(1, AB()); run.size(); ) {
        for (size_t i=0; i<run.size(); ++i) {
            AB ab=run.front(); run.pop_front();
            int a=ab.a, b=ab.b, c=CUPS[2]-ab.a-ab.b;

            if (a==0) reachable[c] = true;
            if (status[a][b]) continue;
            else status[a][b] = true;

            pour(run, a, b, 12);
            pour(run, a, c, 13);
            pour(run, b, a, 21);
            pour(run, b, c, 23);
            pour(run, c, a, 31);
            pour(run, c, b, 32);
        }
    }
}

void output(ostream &out) {
    int i=0;
    for (; i<=MAX_NET; ++i) if (reachable[i]) {
        out << i++;
        break;
    }
    for (; i<=MAX_NET; ++i) if (reachable[i]) 
        out << " " << i;
    out << endl;
}

int main(int argc, char * argv[]) {
    ifstream fin("milk3.in");   if (!fin)  return -1;
    fin >> CUPS[0] >> CUPS[1] >> CUPS[2];

    bfs();
#ifdef DBG 
    output(cout);
#else
    ofstream fout("milk3.out"); if (!fout) return -2;
    output(fout);
#endif
    return 0;
}

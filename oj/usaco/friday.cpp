/*
ID:myxjtu1
PROG:friday
LANG:C++
*/
#include <fstream>
#include <string.h>
using namespace std;

int week[7];

void solve(int year) {
    int month[12];
    memset(month, 0, sizeof(month));
    int lastofyear = 6; // 1900/01/01 = monday, one day before is sunday 
    for (int y=0; y<year; ++y) {
        bool isSpecial = (y%4==0);
        if (y%100==0 && (y+1900)%400!=0)
            isSpecial = false;
        for (int m=0; m<12; ++m)
            month[m] = 31;
        month[3]  = 30;
        month[5]  = 30;
        month[10] = 30;
        month[8]  = 30;
        month[1]  = (isSpecial?29:28);

        for (int m=0, j=lastofyear; m<12; ++m) {
            ++week[(j+13)%7];
            j += month[m];
        }
        lastofyear += isSpecial?366:365;
        lastofyear %= 7;
    }
}

int main(int argc, char * argv[]) {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    if (!fin || !fout) return -1;
    int year; fin >> year;
    solve(year);
    fout<< week[5] << " " 
        << week[6] << " " 
        << week[0] << " " 
        << week[1] << " " 
        << week[2] << " " 
        << week[3] << " " 
        << week[4] << endl;
    return 0;
}

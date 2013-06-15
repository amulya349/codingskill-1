/*
ID:myxjtu1
PROG:namenum
LANG:C++
*/
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int Alphabea[255];

void init() {
    memset(Alphabea, 0, sizeof(Alphabea));
    int c = 'A';
    for (int i=2; i<=7; ++i) {
        Alphabea[c++] = i;
        Alphabea[c++] = i;
        Alphabea[c++] = i;
    }
    c = 'Q';
    for (int i=7; i<=9; ++i) {
        Alphabea[c++] = i;
        Alphabea[c++] = i;
        Alphabea[c++] = i;
    }
    Alphabea['Q'] = 0;
}

int main(int argc, char * argv[]) {
    ifstream fin("namenum.in");
    ifstream dict("dict.txt");
    ofstream fout("namenum.out");
    if (!fin || !dict || !fout) return -1;
    init();
    string n; fin >> n;
    const size_t nLEN = n.size();


    bool hasAny = false;
    string word;
    for (string word; !dict.eof(); ) {
        dict >> word;
        if (nLEN != word.size()) continue;

        size_t i=0;
        for (; i<nLEN && Alphabea[word[i]]==n[i]-'0'; ++i);
        if (i == nLEN)
            fout << word << endl, hasAny = true;
    }
    if (!hasAny)
            fout << "NONE" << endl;

    return 0;
}

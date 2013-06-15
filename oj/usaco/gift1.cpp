/*
ID:myxjtu1
PROG:gift1
LANG:C++
*/
#include <fstream>
#include <map>
using namespace std;

struct Person {
    string name;
    int give, get;
};

int main(int argc, char * argv[]) {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    if (!fin || !fout)
        return -1;

    unsigned NP; fin >> NP;
    map<string, int> hash;
    Person guys[NP];
    for (unsigned i=0; i<NP; ++i) {
        fin >> guys[i].name;
        guys[i].give = 0, guys[i].get = 0;
        hash[guys[i].name] = i;
    }

    while (!fin.eof()) {
        string from;    fin >> from;
        int all, num=0; fin >> all >> num; 

        if (num == 0) continue;
        int k = all/num;
        guys[hash[from]].give = k*num;
        for (int n=0; n<num; ++n) {
            string to; fin >> to;
            guys[hash[to]].get += k;
        }
    }

    for (unsigned i=0; i<NP; ++i) 
        fout << guys[i].name << " " << guys[i].get - guys[i].give << endl;

    return 0;
}

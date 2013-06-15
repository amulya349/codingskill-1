/*
ID:myxjtu1
PROG:ride
LANG:C++
*/
#include <fstream>
using namespace std;
const int MOD = 47;

int main(int argc, char * argv[]) {
    ifstream in("ride.in");
    ofstream out("ride.out");
    if (!in || !out)
        return -1;
    string comet, group;
    in >> comet >> group;

    int c=1,g=1;
    for (size_t i=0; i<comet.size(); ++i) {
        c *= comet[i]-'A'+1;
        c %= MOD;
    }

    for (size_t i=0; i<group.size(); ++i) {
        g *= group[i]-'A'+1;
        g %= MOD;
    }

    out << (c==g?"GO":"STAY") << endl;
    return 0;
}

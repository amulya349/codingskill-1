#include "io.h"
#include <vector>
using namespace std;

int main(int argc, char * argv[]) {
    int A[] = {-1,0,1,1,2,-1,4};
    vector<int> vt = UIO<int>::in(A, sizeof(A)/sizeof(A[0]));

    UIO<int>::pr(vt);

    vector<vector<int> > vvt;
    vvt.push_back(vt);
    UIO<int>::pr(vvt);
    return 0;
}

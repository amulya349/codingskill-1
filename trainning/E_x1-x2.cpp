/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * x1, x2为0～1均匀分布，求E(x1-xy)
 * -------------------------------------------------------------}}}*/
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) {
    srand(time(NULL));

    unsigned total;
    while (cin >> total && total) {
        double sum = 0;
        for (unsigned i=0; i<total; ++i) 
            sum += rand()/(RAND_MAX+1.0)-rand()/(RAND_MAX+1.0);
        cout << sum/total << endl;
    }
    return 0;
}

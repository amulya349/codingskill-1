/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a array of integers, find 3 indexes i,j,k such that:
 * i<j<k and a[i]<a[j]<a[k]. 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> find3is(const vector<int> & a) {
    vector<int> res;
    int is1(0), is21(0), is22(-1);
    for (size_t i=1; i<a.size(); ++i) {
        if (is22 == -1) {
            if (a[is21] < a[i])
                is22 = i;
            else if (a[is21] > a[i])
                is21 = i, is1 = i;
        }
        else {
            if (a[is22] < a[i]) {
                res.push_back(is21);
                res.push_back(is22);
                res.push_back(i);
                return res;
            }
            else if (a[is22] > a[i])
            {
                if (a[is21] < a[i]) {
                    is22 = i;
                }
                else {
                    if (a[is1] > a[i])     
                        is1 = i;
                    else if (a[is1] < a[i])
                        is21 = is1, is22 = i;
                }
            }
        }
    }
    return res;
}

void tell(int A[], int size) {
    vector<int> v;
    for (int i=0; i<size; ++i)
        v.push_back(A[i]);
    vector<int> res = find3is(v);
    for (size_t i=0; i<res.size(); ++i)
        printf("%d, ", v[res[i]]);
    printf("\n");
}

int main(int argc, char * argv[]) {
    int A[] = {8, 6, 3, 3, 5, 4, 2, 1, 4, 4, 8};
    tell(A, sizeof(A)/sizeof(A[0]));
	return 0;
}

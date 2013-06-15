#ifndef __UTILITIESIO_H_20121210
#define __UTILITIESIO_H_20121210 

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
class UIO {
    public:
        UIO()  {}
        ~UIO() {}

    public:
        static vector<T> in(const T * a, size_t na);
        static void pr(const vector<T> & vt);
        static void pr(const vector<vector<T> > & vvt);
};

template <typename T>
vector<T> UIO<T>::in(const T * a, size_t na) {
    assert(a);
    vector<T> ret(a, a+na);
    return ret;
}

template <typename T>
void UIO<T>::pr(const vector<T> & vt) {
    const size_t SIZE = vt.size();
    cout << "[";
    if (SIZE > 0) {
        cout << vt[0];
        for (size_t i=1; i<SIZE; ++i) 
            cout << ", " << vt[i];
    }
    cout << "]\n";
}

template <typename T>
void UIO<T>::pr(const vector<vector<T> > & vvt) {
    const int ROW_SIZ = vvt.size();
    if (ROW_SIZ > 0) {
        cout << "[\n";
        for (int i=0; i<ROW_SIZ; ++i) {
            cout << "    ";
            pr(vvt[i]);
        }
        cout << "]\n";
    }
}

#endif


/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *    整数拆分的个数
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

void integer_spliter_imp(int k, int min, int & rc) {
    int half = k/2;
    for (int i=min; i<=half; ++i) {
        ++rc;
        integer_spliter_imp(k-i, i, rc);
    }
}

int integer_spliter(int k) {
    int c = 0;
    integer_spliter_imp(k, 1, c);
    return c;
}

void tell_proc(unsigned k) {
    printf("split(%u)=%u\n", k, integer_spliter(k));
}

int main(int argc, char * argv[]) {
    tell_proc(1);
    tell_proc(3);
    tell_proc(4);
    tell_proc(5);
    tell_proc(7);
    //    tell_proc(30);
    return 0;
}

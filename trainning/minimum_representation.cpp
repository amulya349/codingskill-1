/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * minimum representation of string
 * 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>

int minimum_representation(const char * s) {
    if (!s) return -1;
    const int LEN = strlen(s);
    int i, j, walk;
    for (i=0,j=1,walk=0; i<LEN && j<LEN && walk<LEN; ) {
        int cmp = s[i+walk >= LEN ? i+walk-LEN : i+walk] - \
                  s[j+walk >= LEN ? j+walk-LEN : j+walk];
        if (cmp == 0) {
            ++walk;
        }
        else {
            if (cmp > 0) i += walk+1;
            else         j += walk+1;
            if (i == j) ++j;
            walk = 0;
        }
    }
    return i<j?i:j;
}

void tell_min_rep(const char * s) {
    int min_begin = minimum_representation(s);
    if (min_begin >= 0) {
        printf("%s\n", s);
        for (int i=0; i<min_begin; ++i) 
            printf(" ");
        printf("^\n");
    }
}

int main(int argc, char * argv[]) {
    tell_min_rep("a");
    tell_min_rep("ab");
    tell_min_rep("bsfsaf98dfau[daaafcyhifa7j43fdaa");
    return 0;
}

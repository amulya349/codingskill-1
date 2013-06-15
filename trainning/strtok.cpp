/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * NetBSD 实现
 * -------------------------------------------------------------}}}*/
#include <stdlib.h>
#include <stdio.h>

char * my_strtok_r(char * s, const char * delim, char ** last) {
    if ((!s && !(s = *last)) || !delim)
        return NULL;

    char c;
    // 1 略过前导
SKIP_LEADINGS:              
    c = *s++;
    for (const char * spanp=delim; *spanp; ++spanp) {
        if (*spanp == c) 
            goto SKIP_LEADINGS; 
    }

    // 2 结束判断, 记录返回值
    if (c == 0) {          
        *last = NULL;
        return  NULL;
    }
    char * ans = s-1;      

    // 3 末尾界定
    for (;;) {
        c = *s++;
        const char * spanp=delim;
        do {
            if (*spanp == c) {
                if (c) s[-1] = 0;
                else   s = NULL; 

                *last = s;
                return ans;
            }
        } while (*spanp++);
    }
}

char * my_strtok(char *s, const char * delim) {
    // static mutex
    static char * last = NULL;
    return my_strtok_r(s, delim, &last);
}

int main() {
    char s[] = {"  .- this is a dot. test !!"};
    const char * delim = "- .";
    char * pch = my_strtok(s, delim);
    while (pch) {
        printf("%s\n", pch);
        pch = my_strtok(NULL, delim);
    }
    return 0;
}

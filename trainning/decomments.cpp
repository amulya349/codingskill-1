#include <iostream>
#include <fstream>
#include <assert.h>

const unsigned long MAX_BUF_LEN = 100000;
using namespace std;

// 0[normal] 1[/]  2[//]  3[/*]  4[/**/] 5["]
void decomment_ccpp(char * decommentcode, const char * sourcecode) {
    assert(decommentcode && sourcecode);
    enum {NORMAL, SLASH, SLASH2, SLASH_STAR, SLASH_STAR2, QUOTE} stat=NORMAL;
    while (*sourcecode) {
        switch (stat) {
            case SLASH:
                if (*sourcecode == '*') {
                    stat = SLASH_STAR;
                }
                else if (*sourcecode == '/') {
                    stat = SLASH2;
                }
                else {
                    stat = NORMAL;
                    *decommentcode++ = sourcecode[-1];
                    *decommentcode++ = *sourcecode;
                }
                break;
            case SLASH_STAR:
                if (*sourcecode == '*')
                    stat = SLASH_STAR2;
                break;
            case SLASH_STAR2:
                if (*sourcecode == '/')
                    stat = NORMAL;
                else if (*sourcecode != '*') 
                    stat = SLASH_STAR;
                break;
            case SLASH2:
                if (*sourcecode == '\n') {
                    stat = NORMAL;
                    *decommentcode++ = *sourcecode; 
                }
                break;
            case QUOTE:
                if (*sourcecode == '"' && sourcecode[-1] != '\\') 
                    stat = NORMAL;
                *decommentcode++ = *sourcecode;
                break;
            case NORMAL:
            default:
                if (*sourcecode == '/') {
                    stat = SLASH;
                }
                else if (*sourcecode == '"') {
                    stat = QUOTE;
                    *decommentcode++ = *sourcecode;
                }
                else {
                    *decommentcode++ = *sourcecode;
                }
                break;
        }
        ++sourcecode;
    }
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <file:sourcecode>" << endl;
        return -1;
    }
    ifstream from(argv[1]);

    char sourcecode[MAX_BUF_LEN] = {0};
    unsigned long len = 0;
    while (from.get(sourcecode[len++]) && len < MAX_BUF_LEN);

    char decommentcode[MAX_BUF_LEN] = {0};
    decomment_ccpp(decommentcode, sourcecode);
    cout << decommentcode;

    return 0;
}

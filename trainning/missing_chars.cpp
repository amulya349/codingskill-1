/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 两个字符串，第二个字符串是第一个的缺了几个，打印第二个字符串缺了的字符位置
 * “abc”, “ab” => print “2”
 * “abc”, “b”  => print “0 2”
 * “abc”, “ac” => print “1”
 * “aab”, “ab” => print “0”   OR   print “1”
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
using namespace std;

void missing_chars(const char * s1, const char * s2) {
    if (s1 && s2) {
        for (int i=0, j=0; s1[i] != '\0'; ++i) {
            if (s1[i] == s2[j]) 
                ++j;
            else 
                printf("%d, ", i);
        }
        printf("\n");
    }
}

int main(int argc, char * argv[]) {
    missing_chars("abc", "ab");
    missing_chars("abc", "b");
    missing_chars("abc", "ac");
    missing_chars("aab", "ab");
    return 0;
}

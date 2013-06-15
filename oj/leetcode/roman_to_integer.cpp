/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999. 
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
    public:
        int romanToInt(const string & s) {
            int LEN = s.size();
            int x = 0;
            for (int i=0; i<LEN; ++i) {
                switch (s[i]) {
                    case 'I': case 'i':
                        if (i+1<LEN && (s[i+1] == 'V' || s[i+1] == 'v' || s[i+1] == 'X' || s[i+1] == 'x')) 
                            x -= 1;
                        else x += 1;
                        break;
                    case 'V': case 'v':
                        x += 5;
                        break;
                    case 'X': case 'x':
                        if (i+1<LEN && (s[i+1] == 'L' || s[i+1] == 'l' || s[i+1] == 'C' || s[i+1] == 'c')) 
                            x -= 10;
                        else x += 10;
                        break;
                    case 'L': case 'l':
                        x += 50;
                        break;
                    case 'C': case 'c':
                        if (i+1<LEN && (s[i+1] == 'D' || s[i+1] == 'd' || s[i+1] == 'M' || s[i+1] == 'm')) 
                            x -= 100;
                        else x += 100;
                        break;
                    case 'D': case 'd':
                        x += 500;
                        break;
                    case 'M': case 'm':
                        x += 1000;
                        break;
                    default:
                        return -1;
                        break;
                }
            }
            return x;
        }
};

void honglei(const string & roman) {
    static Solution solve;
    int ir = solve.romanToInt(roman);
    printf("%s => %d\n", roman.size()?roman.c_str():"null", ir);
}

int main(int argc, char * argv[]) {
    honglei("XLV");
    honglei("MMMCMXCIX");

    return 0;
}


/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * 1 I
 * 2 II 
 * 3 III
 * 4 IV
 * 5 V
 * 6 VI
 * 7 VII
 * 8 VIII
 * 9 IX
 * 10 X
 * 11 XI
 * 12 XII
 * ..
 * 50 L
 * 100 C
 * 500 D
 * 1000 M
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
using namespace std;

static const string ROM[] = {"",
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
    "M", "MM", "MMM" };

class Solution {
    public:
        string intToRoman(int num) {
            if (num >= 4000) return "";
            string ans;
            for (int row=0; num>0; row+=9, num/=10) {
                if (num%10)
                    ans = ROM[row+num%10]+ans;
            }
            return ans;
        }
};

void honglei(int num) {
    static Solution solve;
    string roman = solve.intToRoman(num);
    printf("%d => %s\n", num, roman.c_str());
}

int main(int argc, char * argv[]) {
    honglei(45);
    honglei(0);
    honglei(3999);
    return 0;
}

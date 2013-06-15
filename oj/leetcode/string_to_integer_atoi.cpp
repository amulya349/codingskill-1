/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, 
 * please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 * You are responsible to gather all the input requirements up front.
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
 * Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
 * and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, 
 * which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, 
 * or if no such sequence exists because either str is empty or it contains only whitespace characters, 
 * no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. 
 * If the correct value is out of the range of representable values, 
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 * ""		        0	
 * "1"		        1	
 * "+1"		        1	
 * "-1"		        -1	
 * "123"	        123	
 * "-123"	        -123	
 * "010"	        10	
 * "+00131204"		131204	
 * "-01324000"		-1324000	
 * "2147483647"		2147483647	
 * "-2147483647"	-2147483647	
 * "-2147483648"	-2147483648	
 * "2147483648"		2147483647	
 * "-2147483649"	-2147483648	
 * "abc"	        0	
 * "-abc"	        0	
 * "1a"		        1	
 * "23a8f"	        23	
 * "-3924x8fc"	    -3924	
 * "   321"		    321	
 * "   -321"	    -321	
 * "123  456"	    123	
 * "123   "		    123	
 * "   - 321"	    0	
 * "   +4488"	    4488	
 * "  +  413"	    0	
 * " ++c"		    0	
 * " ++1"		    0	
 * " --2"		    0	
 * "  -2"		    -2
 * -------------------------------------------------------------}}}*/
#include <assert.h>
#include <stdio.h>
#include <string.h>

class Solution {
    public:
        int atoi(const char *str) {
            assert(str);
            while (*str == ' ') ++str;
            bool neg = (*str=='-'?true:false);
            if (*str == '-' || *str == '+') ++str;
            while (*str == '0') ++str;

            unsigned int val = 0;
            for (; *str; ++str) {
                int s = *str-'0';
                if (s<0 || s>9) break;
                if ((INT_MAX-s)/10 < (int)val)
                    return neg?INT_MIN:INT_MAX;
                val = val*10+s;
            }
            return neg?-val:val;
        }
};

void honglei(const char * str) {
    static Solution solve;
    int ans = solve.atoi(str);
    printf("\"%s\" => %d\n", str, ans);
}

int main(int argc, char * argv[]) {
    honglei("+00131204");
    honglei("-01324000");
    honglei("2147483647");
    honglei("-2147483647");
    honglei("-2147483648");
    honglei("2147483648");
    honglei("-2147483649");
    honglei("abc");
    honglei("-abc");
    honglei("1a");
    honglei("   - 321");
    return 0;
}

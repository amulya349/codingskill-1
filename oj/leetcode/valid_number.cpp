/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * Note: It is intended for the problem statement to be ambiguous. 
 * You should gather all requirements up front before implementing one.
 *
 ""		false	
 "    "	false	
 "0"	    true		
 " 0.1 "	true	
 "abc"	false	
 "1 a"	false	
 "2e10"	true	
 "010"	true	
 "000000000"		true	
 "+"		false	
 "-"		false	
 "."		false	
 "1."	true	
 "+1."	true	
 "-1."	true	
 "1.01"	true	
 "+1.23"	true	
 "-2.34"	true	
 "  1."  true	
 "  1.01"true	
 " +1.23"true	
 "  1. "	true	
 " 1.01 "	true	
 " +1.23 "	true	
 " -2.34"	true	
 " -2.34 "	true	
 " 1.2 0"	false	
 " 1.2 a"	false	
 "1.."	false	
 "2.3."	false	
 ".34"	true	
 "0.34"	true	
 "2. 34"	false	
 "2 .34"	false	
 "- 2.34"false	
 "a"		false	
 "a1"	false	
 "1a"	false	
 "a."	false	
 "0."	true	
 "0 ."	false	
 "+0."	true	
 "-0."	true	
 "+.1"	true	
 "-.1"	true	
 "+."	false	
 "-."	false	
 "++1"	false	
 "--1"	false	
 "+-1"	false	
 "-+1"	false	
 "1++"	false	
 "1 0"	false	
 "a 1"	false	
 "0+1"	false	
 "0-2"	false	
 "1e0"	true	
 "1e0000000000"	true	
"1e 0"	false	
"1e0 "	true	
"1e"	false	
"1e1"	true	
"1.3e2"	true	
"1.e3"	true	
"2e."	false	
"2e.3"	false	
"2e+0"	true	
"2e-0"	true	
"2e+32"	true	
"2e-310"true	
"2e3+"	false	
"2e3+1"	false	
"2e+1-1"false	
"2e++1"	false	
"2e-+3"	false	
" +2e-3 "	true	
"3e3."	false	
"3e3.1"	false	
"4ee"	false	
"4ee1"	false	
"4e3e1"	false	
"e3"	false	
"0xA"	false	
"0xff"	false	
* -------------------------------------------------------------}}}*/
class Solution {
    public:
        bool isNumber(const char *s) {
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

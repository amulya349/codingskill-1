/*
 * Given a digit string, return all possible letter combinations \
 * that the number could represent.
 * 
 * A mapping of digit to letters(as on the telephone buttons) is given below.
 * 
 * Input:   Digit string "23"
 * Output:  ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, \
 * your answer could be in any order you want.
 */

#include <stdio.h>
#include <vector>
#include <string>
#include "../../util/io.h"

using namespace std;
class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            string s;
            letter_combinations_imp(res, s, digits.c_str());
            return std::move(res);
        }
    private:
        void letter_combinations_imp(vector<string> & rr, string s, const char * digits) {
            switch(*digits) {
                case 0:
                    rr.push_back(s);
                    break;
                case '2':
                    letter_combinations_imp(rr, s+'a', digits+1);
                    letter_combinations_imp(rr, s+'b', digits+1);
                    letter_combinations_imp(rr, s+'c', digits+1);
                    break;
                case '3':
                    letter_combinations_imp(rr, s+'d', digits+1);
                    letter_combinations_imp(rr, s+'e', digits+1);
                    letter_combinations_imp(rr, s+'f', digits+1);
                    break;
                case '4':
                    letter_combinations_imp(rr, s+'g', digits+1);
                    letter_combinations_imp(rr, s+'h', digits+1);
                    letter_combinations_imp(rr, s+'i', digits+1);
                    break;
                case '5':
                    letter_combinations_imp(rr, s+'j', digits+1);
                    letter_combinations_imp(rr, s+'k', digits+1);
                    letter_combinations_imp(rr, s+'l', digits+1);
                    break;
                case '6':
                    letter_combinations_imp(rr, s+'m', digits+1);
                    letter_combinations_imp(rr, s+'n', digits+1);
                    letter_combinations_imp(rr, s+'o', digits+1);
                    break;
                case '7':
                    letter_combinations_imp(rr, s+'p', digits+1);
                    letter_combinations_imp(rr, s+'q', digits+1);
                    letter_combinations_imp(rr, s+'r', digits+1);
                    letter_combinations_imp(rr, s+'s', digits+1);
                    break;
                case '8':
                    letter_combinations_imp(rr, s+'t', digits+1);
                    letter_combinations_imp(rr, s+'u', digits+1);
                    letter_combinations_imp(rr, s+'v', digits+1);
                    break;
                case '9':
                    letter_combinations_imp(rr, s+'w', digits+1);
                    letter_combinations_imp(rr, s+'x', digits+1);
                    letter_combinations_imp(rr, s+'y', digits+1);
                    letter_combinations_imp(rr, s+'z', digits+1);
                    break;
                default:
                    break;
            }
        }
};

int main(int argc, char * argv[]) {
    static Solution solve;
    vector<string> ret = solve.letterCombinations("23");
    UIO<string>::pr(ret);
    return 0;
}


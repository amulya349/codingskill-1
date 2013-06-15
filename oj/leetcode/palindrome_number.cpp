/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string,\
 * note the restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the \
 * problem "Reverse Integer", you know that the reversed integer might overflow.\
 * How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

class Solution {
    public:
        bool isPalindrome(int x) {
            if      (x <  0) return false;
            else if (x < 10) return true;

            int div=10;
            while (x/div >= 10) div *= 10;

            while (x/div == x%10) {
                x /= 10, div /= 10; 
                x %= div;
                div /= 10; 

                if (x < 10) return true;
            }
            return false;        
        }
};

int main(int argc, char * argv[]) {
    int x=272;
    Solution solve;
    printf("%d", x);
    if (solve.isPalindrome(x))
        printf(" is ");
    else printf(" is not ");
    printf("a palidrome number\n");
    return 0;
}

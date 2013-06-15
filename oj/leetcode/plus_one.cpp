/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a number represented as an array of digits, plus one to the number.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        vector<int> plusOne(const vector<int> & digits) {
            vector<int> ans;
            plusOneImp(ans, digits, digits.size()-1, 1);
            reverse(ans.begin(), ans.end());
            return std::move(ans); 
        }
    private:
        void plusOneImp(vector<int> & ans, const vector<int> & digits, int i, int carry) {
            if (i < 0 && carry == 0) return;
            if (i >= 0)  carry += digits[i];
            ans.push_back(carry%10);
            plusOneImp(ans, digits, i-1, carry/10);
        }
};

void honglei(int * A, size_t n) {
    static Solution solve;
    vector<int> digits = UIO<int>::in(A, n);
    vector<int> ans = solve.plusOne(digits);
    UIO<int>::pr(ans);
}

int main(int argc, char * argv[]) {
    int A[] = {8,9,9,9};
    honglei(A, sizeof(A)/sizeof(A[0]));
    return 0;
}

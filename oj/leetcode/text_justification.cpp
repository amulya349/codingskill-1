/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an array of words and a length L, format the text such that each line \
 * has exactly L characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, \
 * pack as many words as you can in each line. \
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. \
 * If the number of spaces on a line do not divide evenly between words, \
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * 
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."] L=16.
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <vector>
#include "../../util/io.h"
using namespace std;

// online's judgement is not a good sense
class Solution {
    public:
        vector<string> fullJustify(const vector<string> &words, int L) {
            vector<string> ans;
            for (int i=0, lw=0, lc=0; i<(int)words.size();) {
                int topad = words[i].size()+(lc==0?0:1);
                if (lc+topad <= L) {
                    ++i, ++lw, lc += topad;
                    if (lc != L && i < (int)words.size())
                        continue;
                }

                if (lw <= 1) {
                    if (lw == 0) return ans;
                    ans.push_back(words[i-lw]);
                } else {
                    string line, pad;
                    pad.assign(1+(L-lc)/(lw-1), ' ');
                    for (int j=0, m=(L-lc)%(lw-1); j<lw-1; ++j, --m) 
                        line += words[i-lw+j] + (m>0?pad+' ':pad);
                    line += words[i-1];
                    ans.push_back(line);
                }
                lc = lw = 0;
            }
            return std::move(ans);
        }
};

void honglei(string A[], unsigned n, int L) {
    vector<string> words = UIO<string>::in(A, n);
    Solution solve;
    vector<string> ans = solve.fullJustify(words, L);
    vector<vector<string> >format;
    for (size_t i=0; i<ans.size(); ++i) {
        format.push_back(vector<string>());
        format[format.size()-1].push_back(ans[i]);
    }
    printf("\n\n");
    UIO<string>::pr(words);
    printf("=>\n");
    UIO<string>::pr(format);
}

int main(int argc, char * argv[]) {
    string A[] = {"this", "is", "an", "example", "of", "text", "justification."};
    honglei(A, sizeof(A)/sizeof(A[0]), 16);
    honglei(A, sizeof(A)/sizeof(A[0]), 8);
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, \
 * where "adjacent" cells are those horizontally or vertically neighboring. \
 * The same letter cell may not be used more than once.
 * 
 * For example, Given board =
 *                          [
 *                            ["ABCE"],
 *                            ["SFCS"],
 *                            ["ADEE"]
 *                          ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        bool exist(const vector<vector<char> > & board, const string & word) {
            bool walked[board.size()*board[0].size()];
            memset(walked, 0, sizeof(walked));
            for (int r=board.size()-1; r>=0; --r) 
                for (int c=board[r].size()-1; c>=0; --c) 
                    if (exist_imp(board, r, c, walked, word, 0)) return true;
            return false;
        }
    private:
        bool exist_imp(const vector<vector<char> > & board, int r, int c, bool * walked, const string & word, size_t w) {
            if (w >= word.size()) return true;
            if (r >= (int)board.size() || c >= (int)board[r].size() || r < 0 || c < 0 || \
                    walked[r*board[r].size()+c] || board[r][c] != word[w]) 
                return false;

            walked[r*board[r].size()+c] = true;
            bool all4 = exist_imp(board, r-1, c, walked, word, w+1) || \
                        exist_imp(board, r+1, c, walked, word, w+1) || \
                        exist_imp(board, r, c-1, walked, word, w+1) || \
                        exist_imp(board, r, c+1, walked, word, w+1);
            if (!all4) walked[r*board[r].size()+c] = false;
            return all4;
        }
};

void honglei(const string & s) {
    static char board[][4] = { \
        {'A','B','C','E'}, \
        {'S','F','C','S'}, \
        {'A','D','E','E'}  \
    };
    vector<vector<char> > vvc;
    for (int r=0; r<3; ++r) {
        vector<char> vc = UIO<char>::in(board[r], 4);
        vvc.push_back(vc);
    }

    static Solution solve;
    if (solve.exist(vvc, s)) printf("%s, true\n",  s.c_str());
    else                     printf("%s, false\n", s.c_str());
}

int main(int argc, char * argv[]) {
    honglei("ABCCED");
    honglei("SEE");
    honglei("ABCB");
    return 0;
}

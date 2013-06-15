/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 * 
 * You may assume that there will be only one unique solution.
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    public:
        bool solveSudoku(vector<vector<char> > &board, int id=0) { // row by row
            while (id<81 && board[id/9][id%9] != '.') ++id;
            if (id >= 81) return true;

            for (char c='1'; c<='9'; ++c) {
                if (isValid(board, id, c)) {
                    board[id/9][id%9] = c;
                    if (solveSudoku(board, id+1)) 
                        return true;
                }
            }
            board[id/9][id%9] = '.'; // back trace !!!!!!
            return false;
        }

    private:
        bool isValid(const vector<vector<char> > &board, int id, char c) {
            const int ROW = id/9;
            for (int i=0; i<9; ++i) 
                if (board[ROW][i] == c) return false;

            const int COL = id%9; 
            for (int j=0; j<9; ++j) 
                if (board[j][COL] == c) return false;

            const int BLOCK_ROW = (ROW/3)*3;
            const int BLOCK_COL = (COL/3)*3;
            for (int i=0; i<3; ++i) 
                for (int j=0; j<3; ++j) 
                    if (board[BLOCK_ROW+i][BLOCK_COL+j] == c) return false;

            return true;
        }
};

void sudokuprinter(const vector<vector<char> > & sdk) {
    for (int r=0; r<9; ++r) {
        for (int c=0; c<9; ++c) {
            printf("%c ", sdk[r][c]);
            if (c == 2 || c == 5) printf("| ");
        }
        if (r == 2 || r == 5) printf("\n------+-------+------\n");
        else                  printf("\n");
    }
}

void honglei(char (*sdk)[9]) {
    vector<vector<char> > vvc;
    for (int r=0; r<9; ++r) {
        vector<char> vc = UIO<char>::in(sdk[r], 9);
        vvc.push_back(vc);
    }
    sudokuprinter(vvc);
    static Solution solve;
    if (solve.solveSudoku(vvc)) {
        printf("\n\n");
        sudokuprinter(vvc);
    } else {
        printf("\nbad input!!!\n");
    }
}

int main(int argc, char * argv[]) {
    char sdk[][9] = {\
        {'.','.','.','5','.','.','.','.','.'}, \
        {'.','1','.','.','.','8','.','.','9'}, \
        {'.','.','4','.','.','.','6','.','.'}, \
        {'.','.','.','8','7','.','.','5','.'}, \
        {'4','.','.','.','.','.','.','.','8'}, \
        {'.','.','.','9','.','1','.','.','3'}, \
        {'.','6','.','.','9','.','2','4','.'}, \
        {'.','.','.','.','.','.','.','7','.'}, \
        {'5','4','2','.','.','.','.','3','.'}  \
    };
    honglei(sdk);
    return 0;
}

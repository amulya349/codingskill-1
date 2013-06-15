/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region .
 * 
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * -------------------------------------------------------------}}}*/
#include <string.h>
#include <vector>
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        struct Point {
            int x, y;
            Point(int _x, int _y):x(_x), y(_y) {}
        };
    public:
        void solve(vector<vector<char> > & board) {
            const int M = board.size();
            if (M <= 2) return;
            const int N = board[0].size();
            vector<Point> run;
            for (int i=0; i<M; ++i)     // 1 border
                for (int j=0; j<N; ++j) 
                    if ((i==0 || i==M-1 || j==0 || j==N-1) && board[i][j]=='O') { 
                        board[i][j] = 'D';
                        run.push_back(Point(i, j));
                    }

            const static int PATH[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
            while (!run.empty()) {      // 2 out -> insider
                Point p = run.back();
                run.pop_back();
                for (int i=0; i<4; ++i) {
                    int x = p.x+PATH[i][1];
                    int y = p.y+PATH[i][0];
                    if (x<0 || x>=M || y<0 || y>= N || board[x][y]!='O')
                        continue;
                    board[x][y] = 'D';
                    run.push_back(Point(x, y));
                }
            }

            for (int i=0; i<M; ++i)     // 3 check surrounded
                for (int j=0; j<N; ++j) {
                    if (board[i][j]=='X') continue;
                    board[i][j] = (board[i][j]=='O'?'X':'O');
                }
        }
};

void honglei(const char * s, int m) {
    vector<vector<char> > board;
    for (int k=0; s[k] == 'X' || s[k] == 'O'; k+=m) {
        vector<char> line;
        for (int i=0; i<m; ++i)
            line.push_back(s[k+i]);
        board.push_back(line);
    }

    UIO<char>::pr(board);
    static Solution engine;
    engine.solve(board);
    UIO<char>::pr(board);
    cout << endl;
}

int main(int argc, char * argv[]) {
    honglei("XOOX", 2);
    honglei("XXXXOXXXX", 3);
    honglei("XOXXOXOXXOXOOXOX", 4);
    return 0;
}

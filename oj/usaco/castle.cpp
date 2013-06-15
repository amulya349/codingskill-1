/*
ID:myxjtu1
PROG:castle
LANG:C++
*/
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
using namespace std;

const int PATH[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
bool inline hasWall  (int   cell, int k) { return (cell&(1<<k)); }
void inline setRoomId(int & cell, int roomid) { cell|=(roomid<<16); }
int  inline getRoomId(int   cell) { return cell>>16; }
void inline setVisted(int & cell) {        cell|=16; }
bool inline isVisted (int   cell) { return cell &16; }

void inline visiting(vector<vector<int> > & matrix, int i, int M, int j, int N, \
        deque<pair<int, int> > &aroom, int roomid, int &area) {
    if (i<0||i>=M || j<0||j>=N || isVisted(matrix[i][j])) return;
    aroom.push_back(make_pair(i, j));
    setVisted(matrix[i][j]);
    setRoomId(matrix[i][j], roomid);
    ++area;
}

void bigger(vector<vector<int> > & matrix, map<int, int> & rooms, int i, int j, int ii, int jj, \
        int & maxcombine, pair<int, int> & cross, char & ne) {
    int a = getRoomId(matrix[i][j]);
    int b = getRoomId(matrix[i+ii][j+jj]);
    if (a == b) return;
    int combine = rooms[a]+rooms[b];
    if (maxcombine < combine) {
        maxcombine = combine;
        cross = make_pair(i, j);
        ne = ii?'N':'E';
    }
}

void solve(ostream & out, vector<vector<int> > & matrix) {
    const int M=matrix.size();
    const int N=matrix[0].size();
    map<int, int>rooms; int maxarea = 0;
    for (int i=0, roomid=0; i<M; ++i)
        for (int j=0; j<N; ++j) if (!isVisted(matrix[i][j])) {
            int area = 0;
            deque<pair<int, int> > aroom;
            visiting(matrix, i, M, j, N, aroom, roomid, area);
            for (int k=aroom.size(); k>0; k=aroom.size()) {
                pair<int, int>cell = aroom.front(); aroom.pop_front();
                for (int k=0; k<4; ++k) if (!hasWall(matrix[cell.first][cell.second], k))
                    visiting(matrix, cell.first+PATH[k][0], M, cell.second+PATH[k][1], N, aroom, roomid, area);
            }
            rooms[roomid++] = area, maxarea=max(maxarea, area);
        }
    out << rooms.size() << endl << maxarea << endl;

    int maxcombine = 0;
    pair<int, int> cross;
    char ne;
    for (int j=0; j<N; ++j)
        for (int i=M-1; i>=0; --i) {
            if (i >=1) bigger(matrix, rooms, i, j, -1, 0, maxcombine, cross, ne);
            if (j<N-1) bigger(matrix, rooms, i, j,  0, 1, maxcombine, cross, ne);
        }
    out << maxcombine << endl << 1+cross.first << " " << 1+cross.second << " " << ne << endl;
}

int main(int argc, char * argv[]) {
    ifstream fin("castle.in");
    if (!fin) return -1;
    int N, M; fin >> N >> M;
    vector<vector<int> > matrix;
    for (int i=0; i<M; ++i) {
        vector<int> line(N);
        for (int j=0; j<N; ++j) 
            fin >> line[j];
        matrix.push_back(line);
    }

#ifdef DBG 
    ostream & out = cout;
#else
    ofstream fout("castle.out");
    ostream & out = fout;
#endif

    solve(out, matrix);
    return 0;
}

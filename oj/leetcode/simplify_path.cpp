/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"? 
 *   In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 *   In this case, you should ignore redundant slashes and return "/home/foo".
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string>
#include <deque>
using namespace std;

class Solution {
    public:
        string simplifyPath(const string & path) {
            const int LEN = path.size();
            deque<string> dirs;
            string dir;
            for (int i=0; i<LEN; ++i) {
                if (path[i] == '/') {
                    if (!dir.empty()) {
                        dirs.push_back(dir);
                        dir.clear();
                    }
                } else if (path[i] == '.') {
                    switch (path[i+1]) {
                        case '.':
                            if (dirs.size()) dirs.pop_back();
                            ++i;
                            break;
                        case '/':
                            ++i;
                            break;
                        default:
                            if (i+1<LEN) dir += path[i];
                    }
                } else {
                    dir += path[i];
                }
            }
            if (!dir.empty()) dirs.push_back(dir);
            if (dirs.empty()) return "/";

            string simplify;
            for (auto it=dirs.begin(); it != dirs.end(); ++it) 
                simplify += "/"+*it;
            return simplify;
        }
};

void honglei(string path) {
    static Solution solve;
    string simplify = solve.simplifyPath(path);
    printf("%s => %s\n", path.c_str(), simplify.c_str());
}

int main(int argc, char * argv[]) {
    honglei("/.");
    honglei("/home/foo/./bar");
    return 0;
}

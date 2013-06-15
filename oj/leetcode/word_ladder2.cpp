/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two words (start and end), and a dictionary, find all shortest 
 * transformation sequence(s) from start to end, such that:
 *      Only one letter can be changed at a time
 *      Each intermediate word must exist in the dictionary
 *
 * For example, Given:
 *      start = "hit"
 *      end = "cog"
 *      dict = ["hot","dot","dog","lot","log"]
 * Return
 *      [
 *        ["hit","hot","dot","dog","cog"],
 *        ["hit","hot","lot","log","cog"]
 *      ]
 *
 * Note
 *      All words have the same length.
 *      All words contain only lowercase alphabetic characters.
 * -------------------------------------------------------------}}}*/
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include "../../util/io.h"
using namespace std;
using namespace tr1;

/* Solution {{{ I won't give any shit to large data */
class Solution {
    public:
        vector<vector<string> > findLadders(const string &start, const string &end, const unordered_set<string> &dict) {
            vector<vector<string> > ans;
            vector<string> an;
            an.push_back(start);

            if (start == end) {
                an.push_back(end);
                ans.push_back(an);
                return std::move(ans);
            }
            size_t shortest = INT_MAX;
            unordered_set<string> visited;
            visited.insert(start);
            findLaddersHelper(ans, an, start, end, 1, shortest, visited, dict);

            const int LEN = ans.size();
            vector<vector<string> > ans2;
            for (int i=0; i<LEN; ++i) {
                if (ans[i].size() == shortest)
                    ans2.push_back(ans[i]);
            }
            return std::move(ans2);
        }
        void findLaddersHelper(vector<vector<string> > &ans, vector<string> &an, \
                const string &start, const string &end, size_t runner, size_t &shortest, \
                unordered_set<string> &visited, const unordered_set<string> &dict) {
            if (runner >= shortest) return;
            for (size_t i=0; i<start.size(); ++i) {
                for (int j=0; j<26; ++j) {
                    string w2 = start;
                    w2[i] = 'a'+j;
                    if (w2 == end) {
                        an.push_back(end);
                        ans.push_back(an);
                        an.pop_back();
                        shortest = min(shortest, runner+1);
                        return;
                    }
                    if (dict.find(w2) == dict.end() || visited.find(w2) != visited.end())
                        continue;
                    an.push_back(w2);
                    visited.insert(w2);
                    findLaddersHelper(ans, an, w2, end, runner+1, shortest, visited, dict);
                    an.pop_back();
                    visited.erase(w2);
                }
            }
        }
}; /*}}}*/

/*{{{ ihasleetcode (1337coder)
 * word ladder II 有人过了 large tests 吗？
 * 我抛砖引玉一下吧，希望有大牛可以提出更好的解法。
 * 思路就是按照 wwwyhx 的思路 backtrack 重建路径。昨晚写了一下，果然简洁很多，整个程序不到50行。
 * 基于程序可读性，所以 bottom up 返回路径，产生了很多不必要的拷贝而导致效率会差很多。
 * 但路径组合没那么多，所以性能上也没什么影响。
 */
class Solution2 {
    private:
        typedef unordered_multimap<string, string> Map;
    public:
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
            Map map, map2;
            queue<string> q, q2;
            q.push(start);
            bool goal = false;
            while (!q.empty()) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < start.length(); i++) {
                    string s = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;
                        if (s == word) continue;
                        if (s == end) goal = true;
                        if (map.find(s) == map.end() && dict.find(s) != dict.end()) {
                            if (map2.find(s) == map2.end())
                                q2.push(s);
                            map2.insert(make_pair(s, word));
                        }
                    }
                }
                if (q.empty()) {
                    swap(q, q2);
                    map.insert(map2.begin(), map2.end());
                    map2.clear();
                    if (goal) return std::move(print(map, end, start));
                }
            }
            return vector<vector<string> >();
        }

    private:
        // backtrack to reconstruct the path from start -> end.
        vector<vector<string> > print(Map &map, string s, string start, int depth=0) {
            if (depth > 0 && s == start)
                return vector<vector<string> >(1, vector<string>(1, s));

            vector<vector<string> > ret;
            for (auto it=map.equal_range(s); it.first != it.second; ++it.first) {
                vector<vector<string> > temp = print(map, it.first->second, start, depth+1);
                for (int i=0; i<temp.size(); ++i)
                    temp[i].push_back(s);

                ret.insert(ret.end(), temp.begin(), temp.end());
            }
            return std::move(ret);
        }
}; /*}}}*/

int main(int argc, char * argv[]) {
    string start = "hit";
    // string end = "cog";
    string end = "log";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    Solution solve;
    vector<vector<string> > ans = solve.findLadders(start, end, dict);
    UIO<string>::pr(ans);
    return 0;
}

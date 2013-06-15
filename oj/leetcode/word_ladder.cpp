/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two words (start and end), and a dictionary, find the length of 
 * shortest transformation sequence from start to end, such that:
 *   Only one letter can be changed at a time
 *   Each intermediate word must exist in the dictionary
 *
 * For example, Given:
 *   start = "hit"
 *   end = "cog"
 *   dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * 
 * Note:
 *   Return 0 if there is no such transformation sequence.
 *   All words have the same length. 
 *   All words contain only lowercase alphabetic characters.
 * -------------------------------------------------------------}}}*/
#include <string>
#include <iostream>
#include <queue>
#include <tr1/unordered_set>
using namespace std;
using namespace tr1;

class Solution {
    public:
        int ladderLength(const string &start, const string &end, const unordered_set<string> &dict) {
            if (start == end) return 1;
            queue<string> visiting;        visiting.push(start);
            unordered_set<string> visited; visited.insert(start);
            for (int vnum=visiting.size(),transf=1; vnum!=0; vnum=visiting.size(),++transf)
                for (int v=0; v<vnum; ++v) {
                    const string w = visiting.front();
                    visiting.pop();
                    for (size_t i=0; i<start.size(); ++i)
                        for (int j=0; j<26; ++j) {
                            string w2 = w;
                            w2[i] = 'a'+j;
                            if (w2 == end)
                                return transf+1;
                            if (dict.find(w2) == dict.end() || visited.find(w2) != visited.end())
                                continue;
                            visited.insert(w2);
                            visiting.push(w2);
                        }
                }
            return 0;
        }
};

int main(int argc, char * argv[]) {
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    Solution solve;
    cout << solve.ladderLength(start, end, dict) << endl;
    return 0;
}

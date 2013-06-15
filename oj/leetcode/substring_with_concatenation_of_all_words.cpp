/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * You are given a string, S, and a list of words, L, that are all of the same length.
 * Find all starting indices of substring(s) in S that is a concatenation 
 * of each word in L exactly once and without any intervening characters.
 *
 * For example, given:
 *   S: "barfoothefoobarman"
 *   L: ["foo", "bar"]
 * You should return the indices: [0,9].
 * (order does not matter).
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        struct WordDes {
            int appear_times;
            int index;
        };

    public:
        vector<int> findSubstring(const string & S, const vector<string> &L) {
            const int WORD_NUM = L.size();
            const int WORD_LEN = L[0].size();

            // L -> map
            map<string, WordDes> dict;
            WordDes wd;
            for (int i=0, j=0; i<WORD_NUM; ++i) {
                auto it = dict.find(L[i]);
                if (it != dict.end()) {// find
                    ++it->second.appear_times;
                } else {
                    wd.appear_times = 1;
                    wd.index = j++;
                    dict[L[i]] = wd; // dict.insert(pair<string, int>(L[i], i));
                }
            }

            int begin_tag[WORD_LEN]; // tag where the compair begins
            for (int i=0; i<WORD_LEN; ++i)
                begin_tag[i] = i;
            int SMAX_RUN = S.size()-WORD_NUM*WORD_LEN;
            vector<int> ans;
            for (int i=0; i<=SMAX_RUN; ++i) 
                match_imp(S, WORD_LEN, WORD_NUM, i, begin_tag, dict, ans);
            return std::move(ans);
        }
    private:
        /*
         * 在S串中遍历, 每次跳跃单词的长度,
         * 如果在字典中, 则计数并检查是否遍历完了字典
         * 如果有重复, 返回(下一轮从上次出现这个单词的后一个单词开始)
         * 若不在字典中, 下一次从下一个单词长度开始匹配
         *
         * 这里的begin_tag数组,就是保存了开始匹配的位置, 避免重复匹配
         * */
        void match_imp(const string & S, int WLEN, int WNUM, int begin, 
                int * begin_tag, const map<string, WordDes> & dict, \
                vector<int> & res) {
            if (begin != begin_tag[begin%WLEN])
                return;
            int matched_count = 0;
            WordDes wd[dict.size()];
            memset(wd, 0, sizeof(wd));

            int wordrun = begin;
            for (auto it = dict.find(S.substr(wordrun, WLEN)); it != dict.end(); ) {
                ++wd[it->second.index].appear_times;
                if (wd[it->second.index].appear_times == 1) {
                    wd[it->second.index].index = wordrun;
                } else if (wd[it->second.index].appear_times > it->second.appear_times) { //repeat
                    begin_tag[begin%WLEN] = wd[it->second.index].index+WLEN; // surely, we could record which words are found. but ...
                    return;
                }

                if (++matched_count >= WNUM) {
                    res.push_back(begin);
                    begin_tag[begin%WLEN] = begin+WLEN; // = wordrun;
                    return;
                }
                wordrun += WLEN;
                it = dict.find(S.substr(wordrun, WLEN));
            }
            begin_tag[begin%WLEN] = wordrun+WLEN; // unmatch, so we could skip from begin to here;
        }
};

void test(const string & s, const string * L, size_t nL) {
    static Solution solve;
    if (L && nL && s.size()) {
        vector<string> v = UIO<string>::in(L, nL);
        vector<int> res = solve.findSubstring(s, v);
        UIO<int>::pr(res);
    }
}

int main(int argc, char * argv[]) {
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    string L1[] = {"fooo", "barr", "wing", "ding", "wing"};
    test(s, L1, sizeof(L1)/sizeof(L1[0]));

    string s2 = "abababab";
    string L2[] = {"ab", "ab", "ab"};
    test(s2, L2, sizeof(L2)/sizeof(L2[0]));

    string s3 = "sheateateseatea";
    string L3[] = {"sea", "tea", "ate"};
    test(s3, L3, sizeof(L3)/sizeof(L3[0]));

    return 0;
}

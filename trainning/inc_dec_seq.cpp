/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * http://www.51weixue.com/thread-330-1-1.html
 * 给定1-N的一个排列，如果相邻两项是递增的对应I，递减的对应D，则这个排列对应着(N - 1)的字符串。
 * 如: N = 5， 一个排列是2 1 3 5 4, 则它对应一个长度为4的串是 DIID。 
 * 现在问题是：给定一个长度为N的ID的串，如何求出字典序最小的(N + 1)排列？
 *
 * 说明：所谓字典序，其定义和字符串相同，两个排列字典序从第一个元素不同的位置开始算，哪个元素小，则它的字典序也小。
 * 如：(1,2,3) < (1, 3, 2) < (2,1,3) < (2,3,1) < (3,1,2) < (3,2,1)）
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <string>
#include <algorithm>
#include "../util/io.h"
using namespace std;

vector<int> lessPermutation(const string & sequence) {
    const int LEN = sequence.size();
    vector<int> ans(LEN+1, 1);
    for (int i=1; i<=LEN; ++i) ans[i] = i+1;

    for (int i=0; i<LEN; ++i) {
        if (sequence[i] == 'D') {
            int first_d = i++;
            while (i < LEN && sequence[i] == 'D') ++i;
            reverse(ans.begin()+first_d, ans.begin()+i+1);
        }
    }
    return ans;
}

void honglei(string sequence) {
    vector<int> ans = lessPermutation(sequence);
    cout << sequence << " => ";
    UIO<int>::pr(ans);
}

int main(int argc, char * argv[]) {
    honglei("IIII");
    honglei("DIID");
    honglei("DDDD");
    return 0;
}

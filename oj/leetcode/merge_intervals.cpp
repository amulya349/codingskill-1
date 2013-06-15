/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * -------------------------------------------------------------}}}*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool lessInterval(const Interval & a, const Interval & b) {
    return a.start < b.start;
}

class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            sort(intervals.begin(), intervals.end(), lessInterval);
            vector<Interval> ans;
            const int LEN = intervals.size();
            for (int i=0; i<LEN; ++i) {
                if (ans.size() == 0 || ans.back().end < intervals[i].start)
                    ans.push_back(intervals[i]);
                else
                    ans.back().end = max(intervals[i].end, ans.back().end);
            }
            return std::move(ans);
        }
};

void PrintInterval(const vector<Interval> & intervals) {
    const size_t SIZ = intervals.size();
    if (SIZ)
        printf("[%d, %d]", intervals[0].start, intervals[0].end);
    for (size_t i=1; i<SIZ; ++i) 
        printf(",[%d, %d]", intervals[i].start, intervals[i].end);
    printf("\n");
}

int main(int argc, char * argv[]) {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(2, 3));

    static Solution solve;
    vector<Interval> ans = solve.merge(intervals);
    PrintInterval(ans);
    return 0;
}

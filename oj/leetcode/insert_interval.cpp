/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> v;
            int i = 0;
            const int N = intervals.size();
            for (; i<N && newInterval.start > intervals[i].end; ++i)
                v.push_back(intervals[i]);
            for (; i<N && newInterval.end >= intervals[i].start; ++i) {
                newInterval.end = max(newInterval.end, intervals[i].end);
                newInterval.start = min(newInterval.start, intervals[i].start); // runing once acturely
            }
            v.push_back(newInterval);
            for (; i<N; ++i) v.push_back(intervals[i]);
            return std::move(v);
        }
};

void pad(vector<Interval> & v, int a, int b) {
    Interval i(a, b);
    v.push_back(i);
}

int main(int argc, char * argv[]) {
    vector<Interval> v;
    pad(v, 1, 5);
    pad(v, 8, 12);
    Interval newer(2, 7);

    Solution solve;
    vector<Interval> res = solve.insert(v, newer);
    for (size_t i=0; i<res.size(); ++i)
        printf("[%d,%d]\t", res[i].start, res[i].end);
    return 0;
}

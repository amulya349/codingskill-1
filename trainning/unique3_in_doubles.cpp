/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 一个数组中有三个数字a、b、c只出现一次，其他数字都出现了两次。
 * 请找出三个只出现一次的数字。
 * 
 * http://zhedahht.blog.163.com/blog/static/25411174201283084246412/
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
using namespace std;

inline int lastBitOf1(int number) { return number & ~(number-1); }

void getTwoUnique(vector<int>::iterator begin, vector<int>::iterator end, vector<int>& unique) {
    int xorResult = 0;
    for(auto it = begin; it != end; ++it)
        xorResult ^= *it;

    int diff = lastBitOf1(xorResult);
    int first = 0;
    int second = 0;
    for(auto it = begin; it != end; ++it) {
        if(diff & *it) first  ^= *it;
        else           second ^= *it;
    }

    unique.push_back(first);
    unique.push_back(second);
}

void getThreeUnique(vector<int>& numbers, vector<int>& unique) {
    if(numbers.size() < 3) return;

    int xorResult = 0;
    for(auto it = numbers.begin(); it != numbers.end(); ++it)
        xorResult ^= *it;

    int flags = 0;
    for(auto it = numbers.begin(); it != numbers.end(); ++it)
        flags ^= lastBitOf1(xorResult ^ *it);
    flags = lastBitOf1(flags);

    // get the first unique number
    int first = 0;
    for(auto it = numbers.begin(); it != numbers.end(); ++it) if(lastBitOf1(*it ^ xorResult) == flags)
        first ^= *it;
    unique.push_back(first);

    // move the first unique number to the end of array
    for(auto it = numbers.begin(); it != numbers.end(); ++it) if(*it == first) {
        swap(*it, *(numbers.end()-1));
        break;
    }

    // get the second and third unique numbers
    getTwoUnique(numbers.begin(), numbers.end()-1, unique);
}

void honglei(int * A, int SIZE) {
    vector<int> numbers;
    for (int i=0; i<SIZE; ++i)
        numbers.push_back(A[i]);

    vector<int> unique;
    getThreeUnique(numbers, unique);
    for (unsigned i=0; i<unique.size(); ++i)
        printf("%d,", unique[i]);
    printf("\n");
}

int main(int argc, char * argv[]) {
    int A[] = {2,5,7,3,4,4,3};
    honglei(A, sizeof(A)/sizeof(A[0]));
    return 0;
}

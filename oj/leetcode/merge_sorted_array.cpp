/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B.
 * The number of elements initialized in A and B are m and n respectively.
 * -------------------------------------------------------------}}}*/
class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            for (int k=m+n-1; k>=0; --k)
                A[k] = n<=0 || (m>0 && A[m-1]>B[n-1]) ? A[--m] : B[--n];
        }
};

int main(int argc, char * argv[]) {
    return 0;
}

/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given an ascending order ARRAY and a VAL
 * get the number of VAL appears in ARRAY
 * -------------------------------------------------------------}}}*/
#include <stdio.h>

int lowbound(const int * array, int low, int the) {
    while (low < the) {
        int mid = low + (the-low)/2; 
        if (array[mid] == array[the]) the = mid;
        else                          low = mid+1;
    }
    return the;
}

int highbound(const int * array, int high, int the) {
    while (the < high) {
        int mid = high - (high-the)/2; // big note!!!!!!!!!!
        if (array[mid] == array[the]) the  = mid;
        else                          high = mid-1;
    }
    return the;
}

int appearance(const int * array, int array_size, int val) {
    if (array) {
        for (int low(0),high(array_size-1); low <= high; ) {
            int mid = low+(high-low)/2;
            if (array[mid] == val) {
                int a = lowbound(array, low, mid);
                int b = highbound(array, high, mid);
                return b-a+1;
            }

            if (array[mid] < val) low  = mid+1;
            else                  high = mid-1;
        }
    }
    return 0;
}

int main(int argc, char * argv[]) {
    int val = 128;
    int A[val*2];
    for (int i=sizeof(A)/sizeof(A[0])-1; i >= 0; --i)
        A[i] = i;
    A[val-2] = val;
    A[val-1] = val;
    A[val+0] = val;
    A[val+1] = val;
    A[val+2] = val;

    int c = appearance(A, sizeof(A)/sizeof(A[0]), val);
    printf("appearance=%d\n", c);
    return 0;
}

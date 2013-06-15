#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

// 快速排序的关键，就是在这里: 确定枢轴，两端移动
static unsigned int partition(int * paiArr, int iBegin, int iEnd) {
    int pivotkey = paiArr[iBegin];
    while (iBegin < iEnd) {
        while (iBegin < iEnd && paiArr[iEnd] > pivotkey) -- iEnd;
        paiArr[iBegin] = paiArr[iEnd];
        while (iBegin < iEnd && paiArr[iBegin] <= pivotkey) ++ iBegin;
        paiArr[iEnd] = paiArr[iBegin];
    }
    paiArr[iBegin] = pivotkey;

    return iBegin;
}

void qsort(int * paiArr, int iBegin, int iEnd) {
    if (paiArr && iBegin < iEnd) {
        unsigned int q = partition(paiArr, iBegin, iEnd); // 第q个数在partition时已in place
        qsort(paiArr, iBegin, q-1);
        qsort(paiArr, q+1, iEnd);
    }
    return;
}

int main() {
    int iNum4Sort = 0;
    while (cin>>iNum4Sort && iNum4Sort > 0) {
        int aiOriginal[iNum4Sort];
        cout << "plz input " << iNum4Sort << " integers to sort : " << endl; 
        for (int i=0; i<iNum4Sort; ++i)
            scanf("%d", &aiOriginal[i]);

        qsort(aiOriginal, 0, iNum4Sort-1);

        cout << "the sorted of above integers is : " << endl;
        for (int i=0; i<iNum4Sort; ++i)
            printf("%d ", aiOriginal[i]);
        cout << endl << endl;
    }

    return 0;
}

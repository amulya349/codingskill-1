#include<iostream>
using namespace std;

int maxsum(int aiInput[], unsigned int uSize, int & iStarPos, int & iEndPos) {
    int Max = aiInput[0];
    int sum = aiInput[0];
    int istart = 0;
    for (unsigned int i=1; i<uSize; ++i) {
        if (sum <= 0) {
            istart = i;
            sum = aiInput[i];
        }
        else {
            sum += aiInput[i];
        }

        if (Max < sum) {
            Max = sum;
            iEndPos = i;
            iStarPos = istart;
        }
    }

    return Max;
}

int main() {
    int aiInput[15] = {-24,4,5,9,-25,-4,15,32,-99,7,-4,55,-45,46,-7};
    //	int aiInput[15] = {-24, -2, -4, -99, -4, -7};
    int iStarPos = 0;
    int iEndPos = 0;
    int iMaxSum = maxsum(aiInput, sizeof(aiInput)/sizeof(aiInput[0]), iStarPos, iEndPos);

    for (int i=iStarPos; i<=iEndPos; ++i)
        cout << aiInput[i] << " ";
    cout << endl << "max sum = " << iMaxSum << endl;
    return 0;
}

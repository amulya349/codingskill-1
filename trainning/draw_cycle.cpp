/*
 * 画一个任意大小的圆 : 不准使用平方根函数
 * */

#include <iostream>
#include <string.h>

using namespace std;

void draw_cycle_quater(unsigned int uiRadio, int * aiYpoint) {
    if (uiRadio == 0 || !aiYpoint)
        return;

    aiYpoint[0] = 0;
    unsigned int uiR2 = uiRadio * uiRadio;
    unsigned int uiDis2 = uiR2;
    unsigned int uiDelt2 = uiR2;

    for (unsigned int i=1; i<=uiRadio; ++i) {
        unsigned int ypos = aiYpoint[i-1]; // 从这里开始穷举
        uiDis2 = (uiRadio-i)*(uiRadio-i)+ypos*ypos;
        if (uiDis2 >= uiR2) { // 首次依然在圆外，直接就ok了，因为正常情况是从圆内到圆外的
            aiYpoint[i] = ypos;
            continue;
        }
        else { // 首次出现在圆内
            for (; ypos<=uiRadio; ++ypos) {
                uiDelt2 = uiR2-uiDis2;
                uiDis2 += 2*ypos+1;   // 呵呵，就这一步还算有点幼稚园的数学知识
                if (uiDis2 >= uiR2) { // 跑出了圆外
                    if (uiDis2-uiR2 <= uiDelt2)
                        aiYpoint[i] = ypos+1;
                    else
                        aiYpoint[i] = ypos;
                    break;
                }
            }
        }
    }
}

void draw_cycle(unsigned int uiRadio) {
    int aiYpoint[uiRadio+1];
    memset(aiYpoint, 0x0, sizeof(aiYpoint));
    draw_cycle_quater(uiRadio, aiYpoint);
    for (size_t i=0; i<sizeof(aiYpoint)/sizeof(aiYpoint[0]); ++i)
        cout << aiYpoint[i] << " ";
    cout << endl;

    // 上半圆
    for (unsigned int j=0; j<uiRadio-aiYpoint[0]; ++j)
        cout << "  ";
    cout << "**" << endl; // 上顶点只有一个
    for (unsigned int y=1; y<=uiRadio; ++y) {
        for (unsigned int j=0; j<uiRadio-aiYpoint[y]; ++j)
            cout << "  ";
        cout << "**";
        for (int j=0; j<2*aiYpoint[y]; ++j)
            cout << "  ";
        cout << "**" << endl;
    }

    // 下半圆
    for (unsigned int y=uiRadio+1; y<=2*uiRadio-1; ++y) {
        for (unsigned int j=0; j<uiRadio-aiYpoint[2*uiRadio-y]; ++j)
            cout << "  ";
        cout << "**";
        for (int j=0; j<2*aiYpoint[2*uiRadio-y]; ++j)
            cout << "  ";
        cout << "**" << endl;
    }
    for (unsigned int j=0; j<uiRadio-aiYpoint[0]; ++j)
        cout << "  ";
    cout << "**" << endl; // 下顶点只有一个
}

int main() {
    unsigned int uiRadio = 0;
    cout << "plz input the radio (0 for quit) : ";
    while (cin >> uiRadio && uiRadio) {
        draw_cycle(uiRadio);
        cout << "plz input the radio (0 for quit) : ";
    }

    return 0;
}

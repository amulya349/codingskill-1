/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * [���] �ܹ�����a���ӵ�,�ɼ���b��,���ж����ִ�.(ÿ��0~10��)
 * -------------------------------------------------------------}}}*/
#include<iostream>
using namespace std;

int store[10];

void output() {
    for(int i=9; i>=0; --i) {
        cout<<store[i]<<" ";
    }
    cout<<endl;
}

void process(int score, int num, int & sum) {
    if(score<0||score>(num+1)*10)
        return;
    if(0 == num) {
        store[0] = score;
        output();
        ++sum;
        return;
    }
    for(int i = 0; i<=10; ++i) {
        store[num] = i;
        process(score-i, num-1, sum);
    }
}

int main() {
    int sum = 0;
    process(90, 9, sum);
    cout<<"��������"<<sum<<endl;
    return 0;
}

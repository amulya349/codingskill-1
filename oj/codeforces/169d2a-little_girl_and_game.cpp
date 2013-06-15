#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int counter[26];
    memset(counter, 0, sizeof(counter));

    string s;
    cin >> s;
    int LEN = s.size();
    for (int i=0; i<LEN; ++i) 
        ++counter[s[i]-'a'];

    int odds=0;
    for (int i=0; i<26; ++i) {
        if (counter[i]&1)
            ++odds;
    }

    if (odds == 0 || (odds&1))
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int q, count;
    cin >> q;
    string str;

    while(q--) {
        cin >> str;
        if(str.length()==1) {
            cout << 0 << endl;
            continue;
        }
        count=0;
        for(int i=1; i<str.length(); i++) {
            if(str[i-1]==str[i])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}

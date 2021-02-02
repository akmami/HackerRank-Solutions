#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int q, length, count;
    cin >> q;
    string str;

    while(q--) {
        cin >> str;
        length=(int)str.length();
        count=0;
        for(int i=0, j=length-1; i<j; i++, j--) {
            count=count+abs(str[i]-str[j]);
        }
        cout << count << endl;
    }

    return 0;
}

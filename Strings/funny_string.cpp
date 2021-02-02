#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    short q; int length;
    cin >> q;
    string str;

    while(q--) {
        cin >> str;
        length=(int)str.length();
        bool isFunny=true;
        for(int i=0, j=length-1; i<j; i++, j--) {
            if(abs(str[i+1]-str[i]) != abs(str[j]-str[j-1])) {
                isFunny=false;
                break;
            }
        }
        if(isFunny) {
            cout << "Funny" << endl;
        } else {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}

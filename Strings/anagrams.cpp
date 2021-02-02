#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    short q;
    cin >> q;
    string str;
    while(q--) {
        cin >> str;
        if(str.length()%2==1) {
            cout << -1 << endl;
            continue;
        }
        short length=(int)str.length(), i, j;
        bool arr[length/2];
        for(i=0; i<length/2; i++) {
            arr[i]=false;
        }
        short count=0;
        for(i=0; i<length/2; i++) {
            for(j=length/2; j<length; j++) {
                if(str[i]==str[j] && !arr[j-length/2]) {
                    arr[j-length/2]=true;
                    break;
                }
            }
            if(j==length) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

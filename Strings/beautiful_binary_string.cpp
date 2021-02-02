#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    short n;
    string str;
    cin >> n >> str;
    if(n<3) {
        cout << 0 << endl;
        return 0;
    }
    int count=0, temp;
    for(short i=1; i<n-1; i++) {
        if(str[i-1]=='0' && str[i]=='1' && str[i+1]=='0') {
            i=i+2;
            if(i<n-1) {
                temp=0;
                while(str[i]=='1' && str[i+1]=='0') {
                    temp++;
                    i=i+2;
                    if(!(i<n-1)) {
                        break;
                    }
                }
                if(temp==0) {
                    count++;
                    cout << i << endl;
                } else {
                    cout << temp << ':' << i << endl;
                    count=count+temp;
                }
            } else {
                count++;
            }
        }
    }
    cout << count << endl;
    
    //Solution2
//    short n;
//    string str;
//    cin >> n >> str;
//    if(n<3) {
//        cout << 0 << endl;
//        return 0;
//    }
//    int count=0;
//    for(short i=0; i<n-2; i++) {
//        if(str[i]=='0' && str[i+1]=='1' && str[i+2]=='0') {
//            i=i+2;
//            count++;
//        }
//    }
//    cout << count << endl;

    return 0;
}

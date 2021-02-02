#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main() {
    string str, special_char="!@#$%^&*()-+";
    int n;
    cin >> n >> str;
    bool bool_int=false, bool_low=false, bool_upp=false, bool_spec=false;
    char ch;
    for(int i=0; i<n; i++) {
        ch=str[i];
        if(ch<=122 && 97<=ch)
            bool_low=true;
        else if(ch<=90 && 65<=ch)
            bool_upp=true;
        else if(ch<=57 && 48<=ch)
            bool_int=true;
        else {
            if(!bool_spec) {
                for(int j=0; j<12; j++) {
                    if(special_char[j]==ch) {
                        bool_spec=true;
                        break;
                    }
                }
            }
        }
    }
    int count=0;
    if(!bool_int) count++;
    if(!bool_upp) count++;
    if(!bool_low) count++;
    if(!bool_spec) count++;
    if(str.length()>=6) {
        cout << count << endl;
    } else {
        if( count>(6-str.length())) {
            cout << count << endl;
        } else {
            cout << 6-str.length() << endl;
        }
    }
    return 0;
}

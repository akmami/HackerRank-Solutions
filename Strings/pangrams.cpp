#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    if(str.length()<26) {
        cout << "not pangram" << endl;
        return 0;
    }
    bool arr[26];
    for(int i=0; i<26; i++) {
        arr[i]=false;
    }
    for(int i=0; i<str.length(); i++) {
        if(97<=str[i]) {
            arr[str[i]-97]=true;
        } else if(65<=str[i]) {
            arr[str[i]-65]=true;
        }
    }
    for(int i=0; i<26; i++) {
        if(!arr[i]) {
            cout << "not pangram" << endl;
            return 0;
        }
    }
    cout << "pangram" << endl;
    return 0;
}

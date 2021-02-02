#include <iostream>

using namespace std;

int main() {
    string str;
    int arr[26], i, length;
    for(i=0; i<26; i++) {
        arr[i]=0;
    }
    cin >> str;
    length=(int)str.length();
    for(i=0; i<length; i++) {
        arr[str[i]-'a']++;
    }
    bool odd=false;
    for(i=0; i<26; i++) {
        if(arr[i]%2==1) {
            if(!odd) {
                odd=true;
            } else {
                break;
            }
        }
    }
    if(i==26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

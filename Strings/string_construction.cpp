#include <iostream>

using namespace std;

int main() {
    int q, length, i, cost;
    cin >> q;
    bool arr[26];
    string str;

    while(q--) {
        cin >> str;
        length=(int)str.length();
        for(i=0; i<26; i++) {
            arr[i]=false;
        }
        cost=0;
        for(i=0; i<length; i++) {
            if(!arr[str[i]-'a']) {
                arr[str[i]-'a']=true;
                cost++;
            }
        }
        cout << cost << endl;
    }
    return 0;
}

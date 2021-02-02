#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    short q, limit_i;
    string str, str2;
    cin >> q;
    long val, val2;
    int i, k, j;
    while(q--) {
        cin >> str;
        if(str.length()==1) {
            cout << "NO" << endl;
            continue;
        }
        limit_i=(short)str.length()/2;
        for(i=1; i<=limit_i; i++) {
            val=0;
            for(j=0; j<i; j++) {
                val=val*10+(str[j]-48);
            }
            val2=val;
            str2="";
            while(str2.length()<str.length()) {
                str2=str2+to_string(val2);
                val2++;
            }
            if(str2.length() == str.length()) {
                bool equal=true;
                for(k=0; k<str.length(); k++) {
                    if(str2[k]!=str[k]){
                        equal=false;
                        break;
                    }
                }
                if(equal) {
                    cout << "YES " << val << endl;
                    break;
                }
            }
            if(i==limit_i) {
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}

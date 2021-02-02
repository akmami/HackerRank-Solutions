#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;
    string str1, str2;
    int arr1[26], arr2[26], length1, length2, i;
    
    while(q--) {
        cin >> str1 >> str2;
        length1=(int)str1.length();
        length2=(int)str2.length();
        for(i=0; i<26; i++) {
            arr1[i]=0;
            arr2[i]=0;
        }
        for(i=0; i<length1; i++) {
            arr1[str1[i]-'a']++;
        }
        for(i=0; i<length2; i++) {
            arr2[str2[i]-'a']++;
        }
        bool result=false;
        for(i=0; i<26; i++) {
            if(arr1[i]!=0 && arr2[i]!=0) {
                result=true;
                break;
            }
        }
        if(result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

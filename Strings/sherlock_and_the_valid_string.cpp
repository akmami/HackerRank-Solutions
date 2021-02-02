#include <iostream>

using namespace std;

int main() {
    string str;
    int arr[26], length, i;
    for(i=0; i<26; i++) {
        arr[i]=0;
    }
    cin >> str;
    length=(int)str.length();
    for(i=0; i<length; i++) {
        arr[str[i]-'a']++;
    }
    int max=0, min=length, count=0;
    double total=0;
    for(i=0; i<26; i++) {
        if(arr[i]==0)
            continue;
        total=total+arr[i];
        count++;
        if(min>arr[i])
            min=arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    if(total/count==min && total/count==max) {
        cout << "YES" << endl;
    } else if((total-1)/count==min) {
        cout << "YES" << endl;
    } else if((total-1)/(count-1)==max) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

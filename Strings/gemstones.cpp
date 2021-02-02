#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    //Solution1
    int n, temp=0;
    cin >> n;
    bool arr[26];
    int arr_count[26];
    for(int i=0; i<26; i++) {
        arr[i]=false;
        arr_count[0]=0;
    }
    string str_input;
    while(temp++<n) {
        cin >> str_input;
        for(int i=0; i<str_input.length(); i++) {
            arr[str_input[i]-97]=true;
        }
        for(int i=0; i<26; i++) {
            if(arr[i]) {
                arr_count[i]++;
            }
        }
    }
            
    int count=0;
    for(int i=0; i<26; i++) {
        if(arr_count[i]==n) count++;
    }
    cout << count << endl;
    //Solution2
//    int n;
//    cin >> n;
//    string str_temp="", str_input, str_common="";
//    cin >> str_input;
//    for(int i=0; i<str_input.length(); i++) {
//        bool exists=false;
//        for(int j=0; j<i; j++) {
//            if(str_input[i]==str_input[j]) {
//                exists=true;
//                break;
//            }
//        }
//        if(!exists) {
//            str_common=str_common+str_input[i];
//        }
//    }
//    n--;
//    while(n--) {
//        cin >> str_input;
//        str_temp="";
//        for(int i=0; i<str_common.length(); i++) {
//            for(int j=0; j<str_input.length(); j++) {
//                if(str_input[j]==str_common[i]) {
//                    str_temp=str_temp+str_common[i];
//                    break;
//                }
//            }
//        }
//        str_common=str_temp;
//    }
//    cout << str_common.length() << endl;
    return 0;
}

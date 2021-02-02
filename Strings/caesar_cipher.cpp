#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    short n, k;
    string str, final_str="";
    cin >> n >> str >> k;
    k=k%26;
    n--;
    char ch;
    while(n>=0) {
        ch=str[n];
        if(ch>122 || ch<65 || (ch>90 && ch<97)) {
            final_str=ch+final_str;
        } else {
            if(ch>=97) {
                if(ch+k>122) {
                    final_str=(char)(k-26+ch)+final_str;
                } else {
                    final_str=(char)(ch+k)+final_str;
                }
            } else {
                if(ch+k>90) {
                    final_str=(char)(k-26+ch)+final_str;
                } else {
                    final_str=(char)(ch+k)+final_str;
                }
            }
        }
        n--;
    }
    cout << final_str << endl;
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("/Users/akmami/Downloads/input14.txt");
    
    int q;
    inFile >> q;
    string str;

    while(q--) {
        inFile >> str;
        int breakpoint=-1, i=0, j=(int)str.length()-1;
        bool done=false, isPolidrome=true;
        while (i<=j) {
            if(str[i]!=str[j]) {
                if(done) {
                    isPolidrome=false;
                    break;
                }
                if(str[i+1]==str[j]) {
                    breakpoint=i;
                    i++;
                    done=true;
                } else if(str[i]==str[j-1]) {
                    breakpoint=j;
                    j--;
                    done=true;
                }
            }
            i++; j--;
        }
        if(breakpoint==-1 || !isPolidrome) {
            cout << -1 << endl;
            cout << q << endl;
        } else {
            cout << breakpoint<< endl;
        }

    }
    return 0;
}

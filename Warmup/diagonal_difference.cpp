#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, diff=0, val;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> val;
            if(i==j) diff=diff+val;
            if(i+j+1==n)   diff=diff-val;
        }
    }
    cout << abs(diff) << endl;

    return 0;
}

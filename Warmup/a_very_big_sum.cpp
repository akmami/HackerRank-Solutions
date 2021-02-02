#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long val, sum=0;
    int n;
    cin >> n;
    
    while(n--) {
        cin >> val;
        sum=sum+val;
    }
    cout << sum << endl;

    return 0;
}

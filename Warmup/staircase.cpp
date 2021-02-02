#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, temp_n, index;
    cin >> n;
    temp_n=n;
    while(temp_n--) {
        index=temp_n;
        while(index--) {
            cout << ' ';
        }
        index=n-temp_n;
        while(index--) {
            cout << '#';
        }
        cout << endl;
    }
    return 0;
}

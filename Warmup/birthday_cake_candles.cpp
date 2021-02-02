#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, max, max_count, height;
    cin >> n;
    cin >> max;
    n--;
    max_count=1;
    while(n--) {
        cin >> height;
        if(height > max) {
            max=height;
            max_count=1;
        } else if(height == max) {
            max_count++;
        }
    }
    cout << max_count << endl;
    
    return 0;
}

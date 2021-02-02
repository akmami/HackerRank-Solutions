#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long sum, val, index=4, min, max;
    cin >> sum;
    max=sum;
    min=sum;

    while(index--) {
        cin >> val;
        sum=sum+val;
        if(val>max) max=val;
        else if(val<min) min=val;
    }
    cout << sum-max << ' ' << sum-min << endl;

    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, val;
    cin >> n;
    double pos=0, neg=0, zer=0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if(val>0)       pos++;
        else if(val<0)  neg++;
        else            zer++;
    }
    int total=pos+neg+zer;
    printf("%.6f\n%.6f\n%.6f\n", pos/total, neg/total, zer/total);

    return 0;
}


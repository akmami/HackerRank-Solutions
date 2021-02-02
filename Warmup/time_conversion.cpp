#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int hour, minute, second;
    string half;
    char ch;
    cin >> hour >> ch >> minute >> ch >> second >> half;
    if(half=="AM") {
        if(hour==12)
            printf("%02d:%02d:%02d\n", 0, minute, second);
        else
            printf("%02d:%02d:%02d\n", hour, minute, second);
    }
    else {
        if(hour==12)
            printf("%02d:%02d:%02d\n", hour, minute, second);
        else
            printf("%02d:%02d:%02d\n", hour+12, minute, second);
    }
    
    return 0;
}

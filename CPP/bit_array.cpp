#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const int limit = pow(2, 31);
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    long arr[n];
    long prev = s; int index = 0;
    arr[index] = prev; index++;
    bool exists = false;
    n--;
    while(n>0) {
        prev = prev*p+q;
        while(limit < prev) {
            prev = prev - limit;
        }
        for(int i=0; i<index; i++) {
            if(arr[i] == prev) {
                exists = true;
                break;
            }
        }
        if(!exists) {
            exists = false;
            arr[index] = prev;
            index++;
        }
        n--;
    }
    cout << index << '\n';
    return 0;
}

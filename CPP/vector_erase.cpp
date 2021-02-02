#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, x, a, b;
    cin >> N;
    vector<int> v;
    while(N>0) {
        int val;
        cin >> val;
        v.push_back(val);
        N--;
    }
    cin >> x;
    cin >> a >> b;
    bool isInside = false;
    if( a<=x && x<b ) {
        isInside = true;
    }
    if(isInside) {
        v.erase(v.begin()+a-1, v.begin()+b-1);
    } else {
        if( x<a ) {
            v.erase(v.begin()+a-1, v.begin()+b-1);
            v.erase(v.begin()+x-1);
        } else {
            v.erase(v.begin()+x-1);
            v.erase(v.begin()+a-1, v.begin()+b-1);
        }
    }
    cout << v.size() << endl;
    if(v.size() != 0 ) {
        cout << v[0];
        for(long i=1; i < v.size(); i++) {
            cout << ' ' << v[i];
        }
    }
    return 0;
}
//6
//1 4 6 2 8 9
//2
//2 4

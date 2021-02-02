#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> v;
    while(N>0) {
        int x;
        cin >> x;
        int index=v.size();
        for(int i=0; i<v.size(); i++) {
            if(x<v[i]) {
                index=i;
                break;
            }
        }
        v.insert(v.begin()+index, x);
        N--;
    }
    cout << v[0];
    for(int i=1; i<v.size(); i++) {
        cout << ' ' << v[i];
    }
    return 0;
}


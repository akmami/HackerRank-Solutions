#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;

    while(t--) {
        cin >> n >> k;
        if(k==0) {
            for(int i=1; i<=n; i++)
                cout << i << ' ';
            cout << endl;
        } else if(n%(2*k)==0) {
            for(int i=1; i<=n; i=i+2*k) {
                for(int j=i; j<i+k; j++)
                    cout << k+j << ' ';
                for(int j=i+k; j<i+2*k; j++)
                    cout << j-k << ' ';
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

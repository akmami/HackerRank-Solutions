#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int t, n, val, result;
    cin >> t;

    while(t--) {
        cin >> n;
        int arr[n];
        for(int k=0; k<n; k++) {
            cin >> val;
            arr[k]=val;
        }
        result=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if( arr[j]<arr[i] ) {
                    result++;
                }
            }
        }
        if(result%2==0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, index1=0, index2=0, val, i=1, count=0;
    cin >> n >> val;
    bool first=false, second=false;
    int arr[n];
    arr[0]=val;
    while(i<n) {
        cin >> val;
        arr[i]=val;
        if(arr[i-1]>arr[i]) {
            count++;
            if(!first) {
                first=true;
                index1=i-1;
            } else {
                second=true;
                index2=i;
            }
        }
        i++;
    }
    if(count==0) {
        cout << "yes" << endl;
        return 0;
    }
    if(count<=2) {
        if(count==1) {
            index2=index1+1;
        }
        swap(arr[index1], arr[index2]);
        bool sorted=true;
        for(int k=1; k<n; k++) {
            if(arr[k-1]>arr[k]) {
                sorted=false;
                break;
            }
        }
        if(sorted) {
            cout << "yes\nswap " << index1+1 << ' ' << index2+1 << endl;
            return 0;
        }
        swap(arr[index1], arr[index2]);
    }
    if(index2-index1==count) {
        if(index1==0 && index2==n-1) {
            cout << "yes\nreverse " << index1+1 << ' ' << index2+1 << endl;
            return 0;
        } else if(index1==0) {
            if(arr[index1]<arr[index2+1]) {
                cout << "yes\nreverse " << index1+1 << ' ' << index2+1 << endl;
                return 0;
            }
        } else if(index2==n-1) {
            if(arr[index1-1]<arr[index2]) {
                cout << "yes\nreverse " << index1+1 << ' ' << index2+1 << endl;
                return 0;
            }
        } else {
            if(arr[index1-1]<arr[index2] && arr[index1]<arr[index2+1]) {
                cout << "yes\nreverse " << index1+1 << ' ' << index2+1 << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}

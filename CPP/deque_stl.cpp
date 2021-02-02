#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> dq;
    dq.push_back(arr[0]);
    int max = dq[0];
    for(int i=1; i<k; i++) {
        dq.push_back(arr[i]);
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    cout << max;
    for(int i=k; i<n; i++) {
        dq.push_back(arr[i]);
        dq.pop_front();
        int max2 = dq[0];
        for(int j=0; j<k; j++) {
            if(max2 < dq[j]) {
                max2 = dq[j];
            }
        }
        cout << ' ' << max2;
    }
    cout << '\n';
}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

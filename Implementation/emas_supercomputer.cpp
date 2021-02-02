#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool bool_arr[n][m];
    for (int i = 0; i < n; i++) {
        string grid_item;
        cin >> grid_item;
        for(int j = 0; j < m; j++) {
            if(grid_item[j]=='G')
                bool_arr[i][j]=true;
            else
                bool_arr[i][j]=false;
        }
    }
    int int_arr[n][m];
    int maximum=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!bool_arr[i][j]) {
                int_arr[i][j]=0;
            } else {
                int k=1;
                while(true) {
                    if(i+k>=n || i-k<0 || j+k>=m || j-k<0) {
                        break;
                    }
                    if(bool_arr[i+1][j] || bool_arr[i][j+1]
                       || bool_arr[i-1][j] || bool_arr[i][j-1]) {
                        break;
                    }
                    k++;
                }
                int_arr[i][j]=k;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(bool_arr[i][j]) {
                for(int s=0; s<n; s++) {
                    for(int t=0; t<m; t++) {
                        if(i!=s && j!=t) {
                            if(int_arr[i][j]+int_arr[s][t] <= min(abs(i-s), abs(j-t))) {
                                if(maximum < int_arr[i][j]*int_arr[s][t])
                                    maximum=int_arr[i][j]+int_arr[s][t];
                            } else {
                                
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


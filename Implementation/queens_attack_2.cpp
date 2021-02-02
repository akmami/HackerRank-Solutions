#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int r_q, c_q;
    cin >> r_q >> c_q;
    
    int nor=n-r_q;
    int sou=r_q-1;
    int wes=c_q-1;
    int eas=n-c_q;
    int n_w=min(nor, wes);
    int n_e=min(nor, eas);
    int s_w=min(sou, wes);
    int s_e=min(sou, eas);

    int row, column;
    for(int i=0; i<m; i++) {
        cin >> row >> column;
        if(row==r_q) {
            if(column > c_q) { //east
                if(column-c_q<=eas)
                    eas=column-c_q-1;
            } else { //west
                if(c_q-column<=wes)
                    wes=c_q-column-1;
            }
        } else if(column==c_q) {
            if(row > r_q) { //north
                if(row-r_q<=nor)
                    nor=row-r_q-1;
            } else { //south
                if(r_q-row<=sou)
                    sou=r_q-row-1;
            }
        } else if(abs(row-r_q) == abs(column-c_q)) {
            if(row-r_q>0 && column-c_q>0) {     //n_e
                if(row-r_q<=n_e)
                    n_e=row-r_q-1;
            } else if(row-r_q>0 && column-c_q<0) {   //n_w
                if(row-r_q<=n_w)
                    n_w=row-r_q-1;
            } else if(row-r_q<0 && column-c_q>0) {   //s_e
                if(r_q-row<=s_e)
                    s_e=r_q-row-1;
            } else {                            //s_w
                if(r_q-row<=s_w)
                    s_w=r_q-row-1;
            }
        }
    }

    cout << nor+sou+wes+eas+n_w+n_e+s_w+s_e << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int n, k;
    string val;
    cin >> n >> k >> val;

    int i, j, length=(int)val.length();
    char result[length];
    bool isChange[length];
    for(i=0, j=length-1; i<j; i++, j--) {
        if(k<0) {
            break;
        }
        if(val[i]>val[j]) {
            result[i]=val[i];
            result[j]=val[i];
            isChange[j]=true;
            k--;
        } else if(val[i]<val[j]) {
            result[i]=val[j];
            result[j]=val[j];
            isChange[i]=true;
            k--;
        } else {
            result[i]=val[i];
            result[j]=val[j];
            isChange[i]=false;
            isChange[j]=false;
        }
    }
    if(n%2==1) {
        result[length/2]=val[length/2];
        isChange[length/2]=false;
    }
    if(k<0) {
        cout << -1 << endl;
    } else {
        for(i=0, j=length-1; i<j && k!=0; i++, j--) {
            if(result[i]!='9') {
                if(k==1) {
                    if(isChange[i]||isChange[j]) {
                        result[i]='9';
                        result[j]='9';
                        k--;
                    }
                    continue;
                }
                result[i]='9';
                result[j]='9';
                k--;
                if(!isChange[i] && !isChange[j]) {
                    k--;
                }
            }
        }
        if(k!=0) {
            result[length/2]='9';
        }
        for(i=0; i<length; i++) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}

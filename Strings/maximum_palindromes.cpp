#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int factorial(int n) {
    if(n==0 || n==1)
        return 1;
    int res=1;
    for(int i=2; i<=n; i++) {
        res=res*i;
    }
    return res;
};

int main() {
    ifstream inFile;
    inFile.open("/Users/akmami/Downloads/input02.txt");
    ifstream inFileResults;
    inFileResults.open("/Users/akmami/Downloads/output02.txt");
    if(!inFileResults) {
        exit(1);
    }
    string str;
    inFile >> str;
    int q, l, r, arr[26], odd_count, total, test=0;
    inFile >> q;

    while(q--) {
        inFile >> l >> r;
        odd_count=0; total=0;
        for(int i=0; i<26; i++) {
            arr[i]=0;
        }
        for(int i=l-1; i<=r-1; i++) {
            arr[str[i]-'a']++;
        }
        stack<int> st;
        for(int i=0; i<26; i++) {
            if(arr[i]/2!=0) {
                st.push(arr[i]/2);
                total=total+arr[i]/2;
            }
            if(arr[i]%2==1)
                odd_count++;
        }
        int result=1;
        if(!st.empty()) {
            result=factorial(total);
            while(!st.empty()) {
                result=result/factorial(st.top());
                st.pop();
            }
            if(odd_count!=0)
                result=result*odd_count;
        }
        int compar;
        inFileResults >> compar;
        if(compar!=result) {
            cout << l << ' ' << r << ": expected: " << compar << ' ' << "result: " << result << endl;
        } else {
            test++;
        }
    }
    cout << test << endl;
    return 0;
}

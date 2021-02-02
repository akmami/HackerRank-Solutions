#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;

    int size=(int)str.length();
    stack<char> st;
    for(int i=0; i<size; i++) {
        st.push(str[i]);
    }
    stack<char> res;

    while(!st.empty()) {
        if(res.empty()) {
            res.push(st.top());
            st.pop();
            continue;
        }
        if (res.top()==st.top()) {
            res.pop();
            st.pop();
        } else {
            res.push(st.top());
            st.pop();
        }
    }
    if(res.empty()) {
        cout << "Empty String" << endl;
    } else {
        while(!res.empty()) {
            cout << res.top();
            res.pop();
        }
        cout << endl;
    }
    return 0;
}


//#include <stdio.h>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int main() {
//    string str;
//    int n;
//    cin >> n >> str;
//    bool bool_int=false, bool_low=false, bool_upp=false, bool_spec=false;
//    for(int i=0; i<n; i++) {
//        if(str[i].isA)
//    }
//    return 0;
//}

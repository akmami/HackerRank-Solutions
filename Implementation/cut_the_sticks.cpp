
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

vector<string> split_string(string);
vector<int> cutTheSticks(vector<int> arr);
// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> res;
    int a[arr.size()];
    for(int i=0; i<arr.size(); i++) {
        a[i]=arr[i];
    }
    sort(a, a+((int)sizeof(a)/sizeof(a[0])));
    stack<int> st;
    for(int i=(int)arr.size()-1; i>=0; i--) {
        st.push(a[i]);
    }
    int subs;
    while(!st.empty()) {
        res.push_back((int)st.size());
        subs=st.top();
        while(st.top()==subs) {
            st.pop();
            if(st.empty())  break;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

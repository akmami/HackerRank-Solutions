
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<string> split_string(string);

int reverse_int( int number) {
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    reverse(str.begin(), str.end());
    stringstream ss2;
    int reverse_number;
    ss2 << str;
    ss2 >> reverse_number;
    return reverse_number;
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int days=0;
    while(i++<=j) {
        int rev = reverse_int(i);
        if(abs(rev-i)%k==0) {
            days++;
            cout << days <<" ";
        }
            
    }
    return days;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

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

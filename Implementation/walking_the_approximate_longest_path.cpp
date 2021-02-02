#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class result {
public:
    void operator=(result& right) {
        while(!path.empty()) {
            path.pop();
        }
        while(!right.path.empty()) {
            path.push(right.path.top());
            right.path.pop();
        }
        longest_path = right.longest_path;
        
    }
    int longest_path=0;
    stack<int> path;
};

void find_main_path(const int n, bool visited[], const vector<vector<int>>& matrix, result &res_max);
void find_longest_path(stack<stack<int>>& results, result& res);
void find_paths(const int n, int cur_city, bool visited[], const vector<vector<int>>& matrix, stack<int> cities, stack<stack<int>>& results);

void find_longest_path(stack<stack<int>>& results, result& res) {
    res.path = results.top();
    results.pop();
    res.longest_path = (int)res.path.size();
    stack<int> cur_path;
    while(!results.empty()) {
        while(!cur_path.empty()) {
            cur_path.pop();
        }
        while(!results.top().empty()) {
            cur_path.push(results.top().top());
            results.top().pop();
        }
        results.pop();
        if(cur_path.size() > res.longest_path) {
            res.longest_path = (int)cur_path.size();
            while(!res.path.empty()) {
                res.path.pop();
            }
            while(!cur_path.empty()) {
                res.path.push(cur_path.top());
                cur_path.pop();
            }
        }
    }
}

void find_paths(const int n, int cur_city, bool visited[10000], const vector<vector<int>>& matrix, stack<int> cities, stack<stack<int>>& results) {
    
    cities.push(cur_city+1);
    visited[cur_city] = true;
    for(int i=0; i<n; i++) {
        if( !visited[i] && matrix[cur_city][i]==1 ) {
            find_paths(n, i, visited, matrix, cities, results);
        }
    }
    results.push(cities);
}

void find_main_path(const int n, bool visited[10000], const vector<vector<int>>& matrix, result &res_max) {
    stack<result> all_results;
    for(int i=0; i<n; i++) {
        stack<int> cities;
        stack<stack<int>> results;
        find_paths(n, i, visited, matrix, cities, results);
        result res;
        find_longest_path(results, res);
        all_results.push(res);
    }
    res_max = all_results.top();
    all_results.pop();
    while(!all_results.empty()) {
        result res;
        res = all_results.top();
        all_results.pop();
        if(res.longest_path > res_max.longest_path) {
            res_max = res;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix;
    int temp_matrix[n][n];
    bool visited[10000];
    for(int i=0; i<n; i++) {
        visited[i] = false;
        for(int k=0; k<n; k++) {
            temp_matrix[i][k] = 0;
        }
    }
//    for(int i=0; i<n; i++) cout << visited[i] << ' '<<endl;
    for(int i=0; i<m; i++) {
        int xi, yi;
        cin >> xi >> yi;
        temp_matrix[xi-1][yi-1] = 1;
        temp_matrix[yi-1][xi-1] = 1;
    }
    
    for(int i=0; i<n; i++) {
        vector<int> row;
        for(int k=0; k<n; k++) {
            if(temp_matrix[i][k])
                row.push_back(1);
            else
                row.push_back(0);
        }
        matrix.push_back(row);
    }
    
    result res;
    find_main_path(n, visited, matrix, res);
    cout << res.longest_path << endl;
    while(!res.path.empty()) {
        cout << res.path.top() << ' ';
        res.path.pop();
    }
    cout << endl;
    
    return 0;
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2) {
    vector<vector<int> > answer;
    int n, m, o;
    n = arr1.size();
    m = arr1[0].size();
    o = arr2[0].size();
    answer.resize(n);
    for(int i = 0; i < n; i++){
        answer[i].resize(o);
    }
   
    for(int y = 0; y < n; y++){
        for(int x = 0; x < o; x++){
            int sum = 0;
            for(int i = 0; i < m; i++){
                sum += arr1[y][i] * arr2[i][x];
            }
            answer[y][x] = sum;
            cout <<"["<< y <<","<< x <<"]"<< sum <<" ";
            
        }
        cout <<endl;
    }
   
    return answer;
}

int main(int argc, char* argv[]){
    vector<vector<int> > arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int> > arr2 = {{3, 3}, {3, 3}};
    vector<vector<int> > answer; 
    answer = solution(arr1, arr2);
    for(int x = 0; x < answer.size(); x++){
        for(int y = 0; y < answer[0].size(); y++){
            cout << answer[y][x] <<" ";
        }
        cout << "\n";
    }
}
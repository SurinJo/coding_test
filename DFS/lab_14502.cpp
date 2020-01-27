#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define MAX 8
#define WALL 3

int n,m;
int graph[MAX][MAX];

void printGraph() {
    cout << "\n----------print----------"<<endl;
    for(int y = 0; y < n; y++){
        for( int x = 0; x < m; x++){
            cout << graph[y][x] << " ";
        }
        cout<<endl;
    }
}


int main(int argc, char* argv[]){
    //####INPUT####
    cin >> n >> m;
    
    for(int y = 0; y < n; y++){
        for( int x = 0; x < m; x++){
            cin >> graph[y][x];
        }
    }
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(){

            }
        }
    }

}

#if 0
4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2
#endif
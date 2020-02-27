#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define WALL 3

int N, M;
int wall; 

vector<vector<int> > map;
vector<vector<int> > temp;

void printGraph() {
    cout << "\n----------print----------"<<endl;
    for(int y = 1; y <= N; y++){
        for( int x = 1; x <= M; x++){
            cout << map[y][x] << " ";
        }
        cout<<endl;
    }
}


int main(int argc, char* argv[]){
    cin >> N >> M;
    map.resize(N + 2, vector<int>(M + 2, 0));    
    for(int y = 1; y <= N; y++){
        for( int x = 1; x <= M; x++){
            cin >> map[y][x];
            if(map[y][x] == 1) wall++;
        }
    }
/*
    알고리즘 생각하기
    
    임의로 3개의 벽을 쌓는다.
    바이러스에 관해 BFS 혹은 DFS를 수행한다.
    전체 크기에서 바이러스, 벽의 수를 뺀 크기르 구한다.
    그의 최대 크기를 구한다.
    
*/

    //임의로 3개의 벽 쌓기.
    buildWall();
    //원본보호
    temp = map;

    printGraph();

    //cout << N*M - wall - WALL - 바이러스의 수 <<endl;
}
void buildWall(){
    int wallCnt = 0;
    for(int y = 1; y <= N; y++){
        for(int x = 1; x <= M; x++){
            if(temp[y][x] == 0 && wallCnt <3){
                벽 세우기.
                temp[y][x] = 1;
                wallCnt++;
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
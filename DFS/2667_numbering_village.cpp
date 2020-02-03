#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 25
using namespace std;

int N; //square size
int cnt = 0;
char map[MAX][MAX];
int visited[MAX][MAX];
void printMap(){
	for(int y = 0; y < N; y++){
		for(int x=0; x < N; x++){
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}
void DFS(int y, int x, int key){
	visited[y][x] = key;

	
}

int main(int argc, char* argv[]){
	cin >> N;
	for(int y = 0; y < N; y++){
		for(int x=0; x < N; x++)
			cin >> map[y][x];
	}

	for(int y = 0; y < N; y++){
		for(int x=0; x < N; x++){
			if(map[y][x] == '1'){
				cnt++;
				DFS(y, x, cnt+1);
			}
		}
	}

}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
char search;
vector<vector <char> > grid;
queue<pair<int, int> > q;
vector<vector <int> > visited;
void BFS(int, int);
void DFS(int, int);
void check(int, int);
void DFS_check(int y, int x);
void find(int y, int x);//, char color);
#if 0
void printVisit(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			cout << visited[y][x];
		}
		cout << endl;
	}
}
#endif
int main(){
	cin >> N;
	//테두리 씌우기
	grid.resize(N + 2);
	for(int i = 0; i < N + 2; i++)
		grid[i].resize(N + 2);

	//visited 배열도 초기화
	visited.resize(N + 2);
	for(int i = 0; i < N + 2; i++)
		visited[i].resize(N + 2);

	//좌표는 1부터
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			cin >> grid[y][x];
	
	int cnt = 0;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(visited[y][x] == 0){
				// cout << "start" << y <<", "<< x <<endl;
				BFS(y, x);
				cnt++;
			}
		}
	}	
	cout << cnt <<" ";
	
	//적록색맹의 경우
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(grid[y][x] == 'G') grid[y][x] = 'R';
		}
	}
	cnt = 0;
	visited.clear();
	visited.resize(N + 2, vector<int>(N + 2, 0));

	// printVisit();
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(visited[y][x] == 0){
				// cout << "start" << y <<", "<< x <<endl;
				DFS(y, x);
				cnt++;
			}
		}
	}	
	cout << cnt <<endl;

	
}
void BFS(int y, int x){
	// int cnt = 0;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	search = grid[y][x];
	while(!q.empty()){
		pair<int, int> front = q.front();
		q.pop();
		// cout << "visit" << front.first << ", " << front.second <<endl;
		check(front.first, front.second);
		// check(front.second, front.first); // 내가 실수한 부분!
	}
}
void check(int y, int x){
	find(y, x + 1);//, grid[y][x]);
	find(y + 1, x);// grid[y][x]);
	find(y, x -1);// grid[y][x]);
	find(y - 1, x);//, grid[y][x]);
}
void find(int y, int x){
	if(grid[y][x] == search && visited[y][x] == 0){
		q.push(make_pair(y, x));
		visited[y][x] = 1;
	}
}

#if 1
void DFS(int y, int x){
	visited[y][x] = 1;
	search = grid[y][x];
	DFS_check(y, x + 1);
	DFS_check(y + 1, x);
	DFS_check(y, x - 1);
	DFS_check(y -1,  x);
}
void DFS_check(int y, int x){
	if((search == grid[y][x]) && (visited[y][x] == 0)) DFS(y, x);
}
#endif

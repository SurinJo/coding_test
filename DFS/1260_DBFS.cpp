#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int> > map;
vector<int> st;
queue<int> q;
vector<int> visit;
void DFS(int start);
void BFS(int start);
int main(){
	cin >> N >> M >> V; //N : 정점개수, M : 간선개수, V : 시작번호
	//map 초기화
	map.resize(N+2);
	for(int i = 0; i < N + 2;i++) {
		map[i].resize(N + 2, -1); //
	}

	for(int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y;
		//갈 수 있는 경로에 1 표시.
		map[x][y] = 1;
		map[y][x] = 1; 
	}
	visit.resize(N + 1, 0);
	DFS(V); //needs start point
	cout << endl;
	visit.clear();
	visit.resize(N + 1, 0);
	BFS(V);

	
}
#if 1
//재귀버전
void DFS(int start){
	//방문한 경우 탈출.
	cout << start << " ";
	visit[start] = 1;
	for(int i = 1; i <= N; i++){
		// 방문한 기록이 없고, 길이 있을 때 출발!
		if((visit[i] == 0) && (map[start][i] == 1))
			DFS(i);
	}
}
#endif
#if 0
//스택으로 구현
void DFS(int start){
	st.push_back(start);
	while(!st.empty()){
		int top = st.back();
		st.pop_back();
		if(visit[top] == 1) continue;
		visit[top] = 1;
		cout << top << " ";	
		for(int i = N; i >= 1; i--){ //줄어들게 넣어야함!
			if((visit[i] == 0) && (map[top][i] == 1)){
				st.push_back(i);
			}
		}
	}
}
#endif
void BFS(int start){
	q.push(start);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		if(visit[front] == 1) continue;
		visit[front] = 1;
		cout << front << " ";
		for(int i = 1; i <= N; i++){
			if((visit[i] == 0) && (map[front][i] == 1)){
				q.push(i);
			}
		}
	}
}

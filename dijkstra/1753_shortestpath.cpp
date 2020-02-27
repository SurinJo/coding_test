#include <iostream>
#include <vector>
using namespace std;

#define INF 99999
#define MAX 20001; //20000 + 1
int V, E;
int K; //시작 정점의 번호
vector<pair <int, int> > graph[MAX];


int main() {
	cin >> V >> E;
	cin >> K;
	
	int *dist = new int[V + 1];
	vector<int> = dist(V + 1, INF);
	//인접행렬 입력받기
	for(int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	
	//dist 행렬 초기화
	for(int i = 1; i <= V; i++)
		dist[i] = map[K][i];
	//------------Dijkstra---------------

	dist[K] = 0; //시작점은 0으로 !	
	

	for(int i = 1; i <= V; i++)
		cout << "i : "<< dist[i] << endl;
}


#include <iostream>
#include <queue>
#include <vector>
#define SIZE 1001
#define INF 1000000000

using namespace std;

inline int Max(int a, int b) { return a > b ? a : b; }

void dijkstra_party(int total[], vector< pair<int, int> > map[], int n, int s, int to)
{
	priority_queue< pair<int, int> > pq;
	pq.push({ 0, s });

	int dist[SIZE];
	for (int i = 1; i <= n; ++i) dist[i] = INF;

	dist[s] = 0;

	while (!pq.empty())
	{
		int iTown = pq.top().second;
		int iCost = -pq.top().first;
		pq.pop();

		if (iCost > dist[iTown]) continue;

		for (int i=0; i<map[iTown].size(); ++i)
		{
			int next_town = map[iTown][i].first;
			int next_cost = iCost + map[iTown][i].second;

			if (dist[next_town] > next_cost)
			{
				dist[next_town] = next_cost;
				pq.push({-next_cost, next_town});
			}
		}
	}
	total[s] = dist[to];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	vector< pair<int, int> > map[SIZE];

	int total[SIZE] = { 0 };

	cin >> n >> m >> x;

	map->resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int from, to, time;
		cin >> from >> to >> time;

		map[from].push_back({ to, time });
	}

	// 파티장으로 가는 경로 구하기
	for (int i = 1; i <= n; ++i)
	{
		if (i == x) continue;
		dijkstra_party(total, map, n, i, x);
	}




	// 파티장에서 집으로 돌아가는 경로 구하기
	priority_queue< pair< int, int> > pq;
	pq.push({ 0, x });

	int iDist[SIZE];
	for (int i = 1; i <= n; ++i) iDist[i] = INF;
	iDist[x] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int iCost = -pq.top().first;
		pq.pop();

		if (iCost > iDist[cur]) continue;

		for (int i = 0; i < map[cur].size(); ++i)
		{
			int next = map[cur][i].first;
			int next_cost = iCost + map[cur][i].second;

			if (iDist[next] > next_cost)
			{
				iDist[next] = next_cost;
				pq.push({ -next_cost, next });
			}
		}
	}
	int iMax = 0;

	for (int i = 1; i <= n; ++i)
	{
		iMax = Max(iMax, iDist[i] + total[i]);
	}

	cout << iMax << '\n';

	return 0;
}



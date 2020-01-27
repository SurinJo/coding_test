#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B){
	if(A.second == B.second)
		return A.first < B.first;
	else
	{
		return A.second < B.second;
	}
		
}
int main(int argc, char* argv[]){
	int N, start, end;
	int cnt = 0, eSpot = 0; //ending spot
	vector<bool> checkList;
	vector< pair <int, int> > mList;
	cin >> N;
	checkList.resize(N);
	for(int i = 0; i < N; i++){
		cin >> start >> end;
		mList.push_back(make_pair(start, end));
	}
	sort(mList.begin(), mList.end(), cmp);

	for(int i = 0; i < mList.size(); i++){
		if(eSpot <= mList[i].first){
			eSpot = mList[i].second;
			cnt++;
		}
	}
	cout << cnt;
	//회의가 끝나는 기준으로 Greedy!
}

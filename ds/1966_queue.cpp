#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int> > q;

pair<int, int> findMax(){
	
}
int printer(){
	int N, M, value; //as value higher, faster output
	int cnt = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> value;
		q.push(make_pair(value, i));
	}
	while(!q.empty()){
		if(findMax() == true)
			q.pop();
		else{

		}
	}
}


int main(int argc, char* argv[]){
	int T, result;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		result = printer();
		cout << result << endl;
	}
	return 0;
}
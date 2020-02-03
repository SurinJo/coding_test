/*
1. dp[n] = dp[n-3] + array[n-1] + array[n]
2. dp[n] = dp[n-2] + array[n]
출처: https://mygumi.tistory.com/100 [마이구미의 HelloWorld]
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	int *stair; // from user
	int *max; //store its MAX
	
	cin >> N;
	stair = new int[N+1];
	max = new int[N+1];
	for(int i = 1; i <= N; i++){
		cin >> stair[i];
	}
	max[0] = stair[0]= 0;
	max[1] = stair[1];
	max[2] = stair[1] + stair[2];
	for(int i = 3; i <= N; i++){		
		max[i] = std::max(max[i-3] + stair[i-1] + stair[i], max[i-2] + stair[i]);
 	}

	cout << max[N] << endl;
/* 
for(int i = 1; i <= N; i++){
	cout <<"stair "<< i <<  stair[i] << endl;;
}
*/
}
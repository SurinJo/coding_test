#include <iostream>
#include <vector>
using namespace std;

bool Eratos(int n){
	if(n <= 1) return false;
	vector<bool> primeArray(n+1, true); //모두 소수라고 가정
	for(int i = 2; i <= n; i++){
		if(primeArray[i]){
			for(int j = i * i; j <= n; j += i)
				primeArray[j] = false;
		}		
	}
	return primeArray[n];
}
int main(){
	int N, cnt = 0;
	cin >> N;
	vector<int> nums(N);
	for(int i = 0; i < N; i++){
		cin >> nums[i];
	}
	for(int i = 0; i < N; i ++){
		if(Eratos(nums[i]) == true) cnt++;
	}
	cout << cnt;
}
/*
	에라토스테네스의 방법으로 소수 구하기
	1은 소수가 아니고 지우고,
	2는 소수니까 나머지는 소수가 아니니까 지우고
*/
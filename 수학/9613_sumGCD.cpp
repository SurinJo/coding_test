#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
	int A = a, B = b;
	int mod = a % b;
	while(mod > 0){
		a = b;
		b = mod;
		cout << "h";
		mod = a % b; //mod갱신
	}
	return b;
}
void sumOfGCD(vector<int> set){
	int sum = 0;
	int N = set.size();
	cout << "s-";
	for(int i = 0; i < N - 1; i++){
		for(int j = i; j < N - 2; j++){
			sum += GCD(set[i], set[j]);
			cout << "GCD" << sum; 
		}
	}
	cout << sum << " ";
}
int main(){
	int t, n;
	vector<int> nums;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		// N 개의 수를 입력받음
		for(int j = 0; j < n; j++){
			int tmp;
			nums.push_back(tmp);
			cout << "--";
			sumOfGCD(nums);
		}
		nums.clear();
	}
}


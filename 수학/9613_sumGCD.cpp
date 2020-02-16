//유클리드 호제법
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
	int A = a, B = b;
	int mod = a % b;
	cout <<"d"<<endl;
	while(mod > 0){
		a = b;
		b = mod;
		mod = a % b; //mod갱신
	}
	return b;
}

int main(){
	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;
		vector<int> nums(n);
		// N 개의 수를 입력받음
		for(int j = 0; j < nums.size(); j++){
			cin >> nums[i];
			// nums.push_back(tmp);
		}

		long long sum = 0;
		for(int i = 0; i < nums.size() -1; i++){
			for(int j = i + 1; j < nums.size(); j++){
				sum += GCD(nums[i], nums[j]);
			}
		}
		cout << sum << endl;
	}
}
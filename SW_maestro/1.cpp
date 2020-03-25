#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num; // 입력받는 숫자
	cin >> num;
	int digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 각 숫자별 차지하는 획
	string answer;

	vector<pair<int, int> > satisfy; //(획, 해당 숫자) ex) (3, 7)
	
	for(int i = 0; i < num; i++){
		if(digit[i] <= num) satisfy.push_back(make_pair(digit[i], i));
	}

	cout << satisfy.size() ;
	/*-----해당하는 가장 큰 정수 찾기---------*/


	return 0;
}


//마지막에 할일
//unsigned int로 바꿔주기
#include <vector>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	//board[y][x];
	vector<vector<int> > board[n+2][m+2];
	for(int y = 1; y < n + 1; y++){
		for(int x = 1; x < m + 1; x++){
			cout <<  picture[y-1][x-1] <<" ";
			// board[y][x] = picture[y-1][x-1];
		}
		cout <<"\n";
	}



	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}

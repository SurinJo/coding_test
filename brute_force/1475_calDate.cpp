//https://jaimemin.tistory.com/520
#include <iostream>
using namespace std;

int E, S, M;
int main(){
//범위를 넘어가면 1이됨.
	cin >> E >> S >> M;
	int result;
	int year = 1;
	while(true){
		if((year - E) % 15 == 0 &&
			(year - S) % 28 == 0 &&
			(year - M) % 19 == 0){
			result = year;
			break;
		}
		year++;
	}
	cout << result << endl;
}


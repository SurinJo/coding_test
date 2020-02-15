#include <iostream>
using namespace std;

void LCD(int a, int b){
	int A = a, B = b;
	int tmp = a % b;
	while(tmp > 0) {
		a = b;
		b = tmp;
		tmp = a % b;
	}
	cout << A * B / b << endl; 
}
int main(){
	int T;
	int A, B;
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> A >> B;
		LCD(A, B);
	}
	return 0;
}

#include <iostream>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	int a = A, b = B;
	
	int mod = A % B;
	while(mod > 0){
		A = B; //B에 A
		B = mod;
		mod = A % B;
	}
	//GCD
	cout << B << " ";
	//LCM
	cout << a * b / B <<endl;
}
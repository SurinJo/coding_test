#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]){
	int N;
	int *X;
	
	cin >> N;
	X = new int[N+1];
	X[1] = 0;

	for(int i =2; i <= N; i++) {
		X[i] = X[i-1] + 1;
		if(i%3 == 0)
			X[i] = min(X[i], X[i/3] + 1);
		else if(i%2 == 0)
			X[i] = min(X[i], X[i/2] + 1);
	}	
	
	cout << X[N] << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;
int main(){
	int n, m, temp, answer = 0;
	vector<int> cards;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		cards.push_back(temp);
	}

	for(int i = 0; i < n - 2; i++) {
		for(int j = i + 1; j < n -1; j++){
			for(int k = j + 1; k < n; k++){
				// cout << cards[i] << "," <<cards[j] <<  "," << cards[k] << endl;
				temp = cards[i] + cards[j] +cards[k];
				if(temp <= m){
					answer = answer > temp ? answer : temp;
					// cout << "temp: " << temp << endl;
					// cout << "answe: " << answer << endl;
				}
				else{
					// cout << "wrong" <<endl;
				}
			}
		}
	}
	cout << answer;
	return 0;
}
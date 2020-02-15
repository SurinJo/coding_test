#include <iostream>
#include <vector>

using namespace std;
int main(){
	int N;
    int wegiht, height;
    vector<pair <int, int> > people;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> wegiht >> height;
        people.push_back(make_pair(wegiht, height));
    }
}
// 11:40준비
// 12:20출발
// 12:40도착
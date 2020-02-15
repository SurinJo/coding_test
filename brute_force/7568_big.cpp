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
    int k;
    for(int i = 0; i < N; i++){
        k = 0; // 비교대상
        for(int j = 0; j < N; j++){
            if((people[i].first < people[j].first)
            && (people[i].second < people[j].second)) k++;
            
        }
        cout << k + 1 <<" ";
    }
}
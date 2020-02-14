#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    cache.resize(cacheSize);
    if(cacheSize == 0) { 
        answer = cities.size() * 5;
        return answer;
    }
    for(int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        deque<string>::iterator it = find(cache.begin(), cache.end(), cities[i]);
        if(it != cache.end()){ //cache안에 있는 경우
            answer++;
            cache.erase(it);
            cache.push_back(cities[i]);
        }
        else{ //cache안에 없는 경우
            answer = answer + 5;
            cache.pop_front();
            cache.push_back(cities[i]);      
        }
    }
    return answer;
}
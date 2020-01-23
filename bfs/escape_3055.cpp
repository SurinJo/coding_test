/*Baekjoon #3055 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

//지도 정보 저장
vector< vector<int> >map; 
//물이차오르는 날을 저장
vector< vector<int> > water_minute;
//이동하는데 걸리는 시간
vector< vector<int> > minute;

queue< pair<int, int> > water;
queue<pair<int, int> > q;
int R, C;
/* -1은 갈 수 없는 곳
1은 방문한 지점
0은 가야할 곳 */
void build(pair<int, int> &start, pair<int, int> &dest){
    char e;//element
    for(int x = 0; x < map.size(); x++){
        for(int y = 0; y < map[0].size(); y++){
            cin >> e;
            if(e == 'D') dest = make_pair(x,y);            
            else if(e == 'S') start = make_pair(x,y); 
            else if(e == 'X') map[x][y] = -1;
            else if(e == '*') {
                map[x][y] = -1;
                water.push(make_pair(x,y)); 
            }
            else if(e == '.') map[x][y] = 0;
        }
    }
}

/* for debugging */
void print(vector<vector <int> > &v) {
    for(int x = 0; x < v.size();x++){
        for(int y=0; y<v[0].size();y++){
            cout << v[x][y] <<" ";
        }
        cout << endl;
    }
}

void debug() {
    cout<<"####MAP####"<<endl;
    print(map);
    cout<<"###MINUTE###"<<endl;
    print(minute);
}
#if 0
3 3
D.*
...
.S.
#endif
#if 1
void find(vector<vector <int> > &v, int x, int y, int m){
    
    if(minute[x][y] == 0 &&(map[x][y] == 0)){
        if(water_minute[x][y] == 0){
            minute[x][y] = m+1;
            q.push(make_pair(x,y));
        }
        else{
            if(water_minute[x][y] > m+1){
                minute[x][y] = m+1;
                q.push(make_pair(x,y));
            }
        }
        cout <<"find function"  <<"("<< x <<","<<y<<")"<<endl;
        q.push(make_pair(x,y));
        v[x][y] = -1;
        minute[x][y] = m + 1; 
    }
}
void check(vector<vector <int> > &v, int x, int y){
    //v는 맵
    cout << "CHECK the MAP" <<  "("<< x <<","<<y<<")"<<endl;
    debug();
    if(x>=0 && x< R && y>=1 && y<C+1) find(v, x, y-1, minute[x][y]);
    if(x>=0 && x< R && y>=-1 && y<C-1) find(v, x, y+1, minute[x][y]);
    if(x>=1 && x< R+1 && y>=0 && y<C) find(v, x-1, y, minute[x][y]);
    if(x>=-1 && x< R-1 && y>=0 && y<C) find(v, x+1, y, minute[x][y]);
        
   
}
#endif
void find_water(vector<vector <int> > &v, int x, int y, int wm){
    cout << "FIND the water" <<  "("<< x <<","<<y<<")"<<endl;
    if(water_minute[x][y] == 0 && map[x][y] == 0 ){
        cout<<" 000";
        water_minute[x][y] = wm + 1;
        water.push(make_pair(x,y));        
    }
}
void check_water(vector<vector <int> > &v, int x, int y){
    cout << "CHECK the water" <<  "("<< x <<","<<y<<")"<<endl; //wX, wY
    print(water_minute);
    if(x>=0 && x< R && y>=1 && y<C+1) find_water(v, x, y-1, water_minute[x][y]);
    if(x>=0 && x< R && y>=-1 && y<C-1) find_water(v, x, y+1, water_minute[x][y]);
    if(x>=1 && x< R+1 && y>=0 && y<C) find_water(v, x-1, y, water_minute[x][y]);
    if(x>=-1 && x< R-1 && y>=0 && y<C) find_water(v, x+1, y, water_minute[x][y]);
}

int main(int argc, char* argv[]){
    cout << "baekjoon #3055" << endl;
    int result;
    pair<int, int> start, dest, temp;
    cin >> R >> C;
    
    map.assign(R, vector<int>(C, 0));
    minute.assign(R, vector<int>(C,0));
    water_minute.assign(R, vector<int>(C,0));

    build(start, dest);

    //물에 대한 BFS
      
    while(!water.empty()){
        cout << "HHH"<<endl;
        int wX = water.front().first;
        int wY = water.front().second;
        water.pop();
        check_water(map, wX, wY);
        // debug();
    }
    
#if 0
3 3
D.*
...
.S.
#endif
    
    q.push(start);
    while(!q.empty()){      
        temp = q.front();
        q.pop();
        check(map, temp.first, temp.second);
    }

    if(minute[dest.first][dest.second] != 0) cout << minute[dest.first][dest.second]<<endl;
    else cout<<"KAKTUS"<<endl;
}
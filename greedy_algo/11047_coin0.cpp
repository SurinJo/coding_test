#include <iostream>
#include <vector>

#define MAX 10
using namespace std;

int main(int argc, char* argv[]){
    int N, K;
    int coin[MAX];
    int limit = 0, remain, cnt = 0;

    // INPUT from user
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
        if(coin[i] <= K){
            limit = i;
        }
    }

    remain = K;

    for(int j= limit; j >= 0; j--){
        while(remain >= 0){
            if(remain-coin[j] >= 0){
                remain = remain - coin[j];
                cnt++;
            }
            else{
                break;
            }
        }
    }

    cout << "cnt:"<< cnt<<endl;
    
    return 0;
}

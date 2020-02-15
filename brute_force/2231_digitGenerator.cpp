#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N, copy, sum = 0;
    cin >> N;
    int generator = 1;

    while(true){
        sum = generator; // 생성자 체크
        copy = generator; // 자릿수의 합을 구하기 위해서
        while(copy != 0){
            sum = sum + copy %10;
            copy = copy / 10;
        }
        cout << "sum : " << sum << endl;
        if(sum == N || generator == N){
            break;
        }
        generator++;
    }
    if(sum == N) cout << generator;
    else cout << 0;
    return 0;
}

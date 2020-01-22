#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
    long fixed, variable, price, answer;
    long breakPoint;
    cout << "baekjoon #1712" << endl;
    cin >> fixed >> variable >> price;
    // fixed + variable * x < price * x
    // fixed < x *(price-variable)
    breakPoint = fixed * 1.0 / (price -variable);
    answer = floor(breakPoint) + 1;
    if(answer < 0) answer = -1;
    cout << answer << endl;

}
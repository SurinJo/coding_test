#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "baekjoon 11720" << std::endl;

    int N;
    char number;
    int sum = 0;

    std::cin >> N;
    if(N < 1 || N > 100) { std::cout << "out of range" << std::endl; exit(1); }
    
    // std::cout << number.substr(0,1);
    for(int i =0; i < N; ++i) {
        std::cin >> number;
        sum += (number-'0');
    }
    std::cout << sum << std::endl;
}
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    int c; // number of testcases
    int N; // number of students
    float cnt;
    int score; // score of each student
    float average;
    std::cout << "baekjoon #4344" << std::endl;
    std::cin >> c; 
    std::vector<int> students;
    std::vector<int>::iterator it;

    for(int i = 0; i < c; i++) {
        cnt = 0;
        std::cin >> N; //get the Number of Student

        if(N <1 || N > 1000) {
            std::cout << "wrong input" << std::endl;
            exit(1);
        }

        for(int j = 0; j < N; j++) {
            std::cin >> score;
            students.push_back(score);
            average += score;
        }
        average = average / N;
        // average = std::accumulate (students.begin(), students.end(), 0.0) / students.size();;
        for(it = students.begin(); it !=students.end(); ++it) {
            if(*it > average) cnt++;
        }
        // std::cout <<"test : " << cnt/N <<std::endl;
        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << cnt / N * 100 << "%" <<std::endl;
        students.clear();
    }
}


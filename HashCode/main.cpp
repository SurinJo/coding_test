#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<int> score; // (score, id)
 
class library
{
public:
   vector<p> books; // 도서관이 가지고 있는책
   int signup;        // signup 하는데 걸리는 시간
   int facility;      // 하루에 스캔하는 책 개수
};
 
bool compare(p a, p b) {
   return a.first > b.first;
}
 
int main(int argc, char* argv[])
{
   /*----------FILE input--------------*/
   fstream inFile(argv[1]);
   //   ofstream outFile("result.txt");
   int B, L, D;
   inFile >> B >> L >> D;
   vector<library> lib; // 라이브러리 집합
   vector<p> day;       // 책 다 처리하는데 얼마나 걸리는지
   vector<int> visit;
 
   visit.resize(B, 0); // 방문 안했으면 0
   for (int i = 0; i < B; i++)
   {
       int tmp;
       inFile >> tmp;
       score.push_back(tmp);
   }
   for (int i = 0; i < L; i++)
   {
       int numBooks;
       inFile >> numBooks; //라이브러리당 책의 수 입력받음
       library temp;
       inFile >> temp.signup;   // 등록하는데 걸리는 일수
       inFile >> temp.facility; // 하루에 책 몇권 스캔?
  
       for (int j = 0; j < numBooks; j++)
       {
           int b;
           inFile >> b;
           temp.books.push_back(make_pair(score[b], b));
       }
       sort(temp.books.begin(), temp.books.end(), compare);
       lib.push_back(temp);
       day.push_back(make_pair(temp.signup + numBooks / temp.facility, i));
   }
 
   sort(day.begin(), day.end(), compare);
   inFile.close();
   inFile.open(argv[1], ios::out);
   inFile << L << endl;
 
   //    cout << L << endl;      // 도서관 몇개 등록할건지
   for (int i = 0; i < day.size(); i++)
   { // day[i] = i번쨰로 signup할 거 (걸리는일수, library id)
       vector<int> print;
 
       int libidx = day[i].second;     // i번째로 signup하는 도서관의 id
       inFile << libidx << " ";                    // library id 출력
 
       for (int j = 0; j < lib[libidx].books.size(); j++)
       {
           int curr = lib[libidx].books[j].second;
           if(visit[curr] == 1) {
               continue;
           }
           visit[curr] = 1;
           print.push_back(curr);
       }
 
       inFile << print.size() << endl; // library의 책 개수 출력
       for (int j = 0; j < print.size(); j++)
       {
           inFile << print[j] << " ";
       }
       if(print.size() != 0) inFile << endl;
 
   }
   //    cout << endl;
   inFile.close();
}
 
 
 
 


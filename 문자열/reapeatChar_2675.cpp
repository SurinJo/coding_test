#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int i,j,k;
    int numOfCase, repeatNum;
    string obj;
    char s;
    cin >> numOfCase;

    for(i = 0; i < numOfCase; i++) {
        cin >> repeatNum;
        cin >> obj;
        for(j = 0; j < obj.length(); j++) {
            s = obj[j];
            for(k = 0; k < repeatNum; k++) {
                cout << s;
            }
        }
        cout <<endl;
    }
}
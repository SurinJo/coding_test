#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_blank(string str){
    int cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ')
            cnt++;
    }
    if(str[0] == ' ') cnt--;
    if(str[str.length()-1] == ' ') cnt--;
    return cnt;
}

int main(int argc, char* argv[]) {
    int cnt;
    string str;
    while(true){
        cout << "enter the sentence" << endl;/
        getline(cin, str);
        cnt = count_blank(str);
        cout << cnt+1 <<endl;
    }
    
}
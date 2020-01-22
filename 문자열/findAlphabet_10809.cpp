#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) {
    cout <<"baekjoon #10809" << endl;
    string S;
    cin >> S;


    vector<char> S_vec(S.begin(),S.end());
    vector<char>::iterator it;
    int idx;
    char *s_idx;
    for(char i = 'a'; i <= 'z'; ++i) {
        s_idx = strchr(S.c_str(), i);
        if(s_idx == NULL)
            cout << "-1 ";
        else
        {
            cout << s_idx - S.c_str() << " ";
        }
        
    }
#if 0
    for(int i = 'a'; i <= 'z'; ++i) {
        idx = -1;
        for(it = S_vec.begin(); it < S_vec.end(); it++) {
            if(i == *it) {
                idx = it - S_vec.begin();
                break;
            }
        }        
        cout << idx << " ";
    }
#endif
}


#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 1000000
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    //Erotos의 체
    vector<bool> primeArray(MAX + 1, true); //모두 소수라고 가정
	for(int i = 2; i * i <= MAX; i++){
		if(primeArray[i]){
			for(int j = i * i; j <= MAX; j += i)
				primeArray[j] = false;
		}		
	}
    
    //홀수인 소수를 저장
    vector<int> prime;
    for(int i = 3; i < MAX; i++){
        if(primeArray[i]==true)
            prime.push_back(i);
    }

    while(true){
        // cin >> n;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 0; i < prime.size(); i++){
            if(primeArray[prime[i]] && primeArray[n-prime[i]]) { //소수라면
                printf("%d = %d + %d\n", n, prime[i], n- prime[i]);
                // cout << n << " = " << prime[i] << " + "<< n- prime[i] <<endl;
                break;                
            }
        }
    }
    return 0;
}

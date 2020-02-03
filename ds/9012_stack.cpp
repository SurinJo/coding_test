#include <iostream>
#include <queue>

bool check_VPS(){
	std::vector<char> stack;
	std::string par;
	std::cin >> par;
	for(int i = 0; i < par.length(); i++){
		if(par[i]== '(') stack.push_back('(');
		else {
			if(!stack.empty()) stack.pop_back();
			else return false;
		}
	}
	if(stack.empty()) return true;	
	else return false;
	
}
int main(int argc, char* argv[]){
	int T;
	bool result;
	std::cin >> T; //number of data

	for(int i = 0; i < T; i++){
		result = check_VPS();
		if(result == true) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl; 
	}
	return 0;
}

#include <iostream>

using namespace std;
bool patternCheck(string, string);
string fr, ba;
int main(){
	int N;
	string pattern;
	cin >> N;
	cin >> pattern;
	bool star = false;
	for(int i = 0; i < pattern.size(); i++){
		if(pattern[i] == '*'){
			star = true;
			continue;}
		else if(star)
			ba += pattern[i];
		else
			fr += pattern[i];
	}

	for(int i = 0; i < N; i++){
		if(patternCheck(fr, ba))
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}
bool patternCheck(string fa, string ba){
	string name;
	cin >> name;
	if(name.size() < fa.size()+ ba.size())
		return false;
	for(int i = 0; i < fa.size(); i++){
		if(fa[i] != name[i]) return false;
	}

	for(int i = 1; i <= ba.size(); i++){
		if(ba[ba.size() - i] != name[name.size() - i]) return false;
	}

	return true;
}

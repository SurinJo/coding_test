#include <iostream>
#include <vector>
#include <algorithm>
#define DWARF 9
#define TALL 100
using namespace std;

void solution(vector<int> &dwarf, int sum)
{
	int tmp;
	for (int i = 0; i < DWARF - 1; i++)
	{
		for (int j = i + 1; j < DWARF; j++)
		{
			tmp = dwarf[i] + dwarf[j];
			//합이 100인 경우를 찾음
			if ((sum - tmp) == TALL)
			{
				dwarf[i] = 0;
				dwarf[j] = 0;
				return;
			}
		}
	}
}

int main()
{
	vector<int> dwarf(DWARF);
	int sum = 0;
	for (int i = 0; i < DWARF; i++)
	{
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	solution(dwarf, sum);
	sort(dwarf.begin(), dwarf.end());
	
	for (int i = 2; i < DWARF; i++)
	{
		cout << dwarf[i] << endl;
	}
	return 0;
}

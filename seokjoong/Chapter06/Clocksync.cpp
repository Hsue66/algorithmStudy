#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
char linked[SWITCHES][CLOCKS + 1] = { 
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.." };

bool areAligned(const vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; i++)
		if (clocks[i] % 4 != 0) return false;
	return true;
}

void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock)
		if (linked[swtch][clock] == 'x')
			clocks[clock] += 3;
}

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) 
		return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}


int main()
{
	int cases;
	cin >> cases;
	while(cases > 0) {
		vector<int> clocks(16, 0);
		for (int i = 0; i < CLOCKS; i++)
			cin >> clocks[i];
		int ret = solve(clocks, 0);
		cout << (ret >= INF ? -1 : ret) << endl;
		cases--;
	}
    return 0;
}


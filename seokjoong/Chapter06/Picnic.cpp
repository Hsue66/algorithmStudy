#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
bool friendsTable[10][10];
int N;

int countCouple(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < N; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) 
		return 1;
	int ret = 0;
	for (int i = firstFree + 1; i < N; ++i) {
		if (!taken[i] && friendsTable[firstFree][i]) {
			taken[i] = true;
			taken[firstFree] = true;
			ret += countCouple(taken);
			taken[i] = false;
			taken[firstFree] = false;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	while (cases > 0) {
		int total = 2;
		int couple = 0;
		int temp;
		
		bool taken[10];
		
		
		int friendtemp = 0;
		int index = 0;

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				friendsTable[i][j] = false;
			}
		}
		cin >> total >> couple;

		for (int i = 0; i < couple * 2; ++i) {
			cin >> temp;
			if (i % 2 == 0)
				friendtemp = temp;
			else {
				friendsTable[friendtemp][temp] = true;
				friendsTable[temp][friendtemp] = true;
			}
		}

		for (int i = 0; i < total; ++i) {
			taken[i] = false;
		}
		N = total;
		int c = countCouple(taken);
		cout << c << endl;

		cases--;
	}
    return 0;
}


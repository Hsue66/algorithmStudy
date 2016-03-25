#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


inline int getfirstIndex(string var) {
	int skipword = 0;
	for (int i = 0; i < var.length(); ++i) {
		if (var[i] == 'x') {
			skipword += 4;
		}
		if (skipword == 0)
			return i;
		skipword--;
	}
	return -1;
}
inline int getsecondIndex(string var) {
	int skipword = 1;
	for (int i = 0; i < var.length(); ++i) {
		if (var[i] == 'x') {
			skipword += 4;
		}
		if (skipword == 0)
			return i;
		skipword--;
	}
	return -1;

}
inline int getthirdIndex(string var) {
	int skipword = 2;
	for (int i = 0; i < var.length(); ++i) {
		if (var[i] == 'x') {
			skipword += 4;
		}
		if (skipword == 0)
			return i;
		skipword--;
	}
	return -1;
}
inline int getfourthIndex(string var) {
	int skipword = 3;
	for (int i = 0; i < var.length(); ++i) {
		if (var[i] == 'x') {
			skipword += 4;
		}
		if (skipword == 0)
			return i;
		skipword--;
	}
	return -1;
}


inline string decomp(string var) {
	
	int index = 0;
	int part = 0;
	int skipword = 0;
	string a[4];
	if (var.length() < 4)
		return var;

	if (var[0] == 'x') {
		var = var.substr(1, var.length() - 1);
		int pos1 = getfirstIndex(var);
		int pos2 = getsecondIndex(var);
		int pos3 = getthirdIndex(var);
		int pos4 = getfourthIndex(var);

		a[0] = var.substr(0, pos1 + 1);
		a[1] = var.substr(pos1 + 1, pos2 - pos1);
		a[2] = var.substr(pos2 + 1, pos3 - pos2);
		a[3] = var.substr(pos3 + 1, pos4 - pos3);
	}

	for (int i = 0; i < 4; ++i) {
		if (a[i].length() > 1) {
			a[i] = decomp(a[i]);
		}
	}

	return "x"+ a[2] + a[3]+ a[0] + a[1];

}





int main()
{
	ios_base::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	string problem;
	while (cases > 0)
	{
		cin >> problem;
		cout << decomp(problem)<<endl;
		cases--;
	}

	return 0;
}


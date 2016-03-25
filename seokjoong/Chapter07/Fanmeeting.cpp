#include "stdafx.h"
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> fanList;
vector<int> memberList;



vector<int> mul() {

	vector<int> result;
	result.resize(fanList.size() + memberList.size() - 1);


	vector<int> memberCheck;
	vector<int> fanCheck;

	for (int i = 0; i < memberList.size(); ++i) {
		if (memberList[i] == 1)
			memberCheck.push_back(i);
	}

	for (int i = 0; i < fanList.size(); ++i) {
		if (fanList[i] == 1)
			fanCheck.push_back(i);
	}

	for (int i = 0; i < fanCheck.size(); ++i) {
		for (int j = 0; j < memberCheck.size(); ++j) {
			result[fanCheck[i] + memberCheck[j]] = 1;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	while (cases > 0) {
		string memberInput;
		string fanInput;
		cin >> memberInput;
		cin >> fanInput;

		memberList.clear();
		fanList.clear();
		for (int i = memberInput.size() - 1; i >= 0; --i) {
			if(memberInput[i] == 'F')
				memberList.push_back(0);
			else
				memberList.push_back(1);
		}
		for (int i = 0; i < fanInput.size(); ++i) {

			if (fanInput[i] == 'F')
				fanList.push_back(0);
			else
				fanList.push_back(1);
		}
		vector<int> result;
		result = mul();

		int hug = 0;
		for (int i = memberList.size() - 1; i < fanList.size(); ++i) {
			if (result[i] == 0)
				hug++;
		}


		cout << hug << endl;
		cases--;
	}
    return 0;
}


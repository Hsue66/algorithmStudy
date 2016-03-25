#include "stdafx.h"
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> problemList;

long sum(int left, int right) {

	if (left == right) 
		return problemList[left];

	int mid = (left + right) / 2;

	long ret = fmax(sum(left, mid), sum(mid + 1, right));

	int lo = mid;
	int hi = mid + 1;
	int height = fmin(problemList[lo], problemList[hi]);
	ret = fmax(ret, height*2);
	while (left < lo || right > hi) {
		if (hi < right && (lo == left || problemList[lo - 1] < problemList[hi + 1])) {
			hi++;
			height = fmin(height, problemList[hi]);
		}
		else {
			lo--;
			height = fmin(height, problemList[lo]);
		}
		ret = fmax(ret, height *(hi - lo + 1));
	}
	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	while (cases > 0) {
		int input, count;
		problemList.clear();
		cin >> count;
		for (int i = 0; i < count; ++i) {
			cin >> input;
			problemList.push_back(input);
		}

		long result = sum(0, count - 1);
		cout << result << endl;
		cases--;
	}

    return 0;
}


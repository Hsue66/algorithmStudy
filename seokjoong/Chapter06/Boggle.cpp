#include <list>
#include <iostream>
#include <cstring>
using namespace std;


inline bool isNear(int firstVal, int secondVal) {
	if (firstVal == secondVal)
		return false;

	int x1, y1, x2, y2;
	x1 = firstVal / 5;
	y1 = firstVal % 5;
	x2 = secondVal / 5;
	y2 = secondVal % 5;

	if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1)
		return false;
	else
		return true;


}

int main()
{
	ios_base::sync_with_stdio(false);
	int cases = 0;
	cin >> cases;
	while (cases > 0)
	{
		int testCount = 0;
		char problems[5][5];
		char test[20];

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> problems[i][j];
			}
		}
		cin >> testCount;
		while (testCount > 0)
		{
			list<list<int>> testList;
			list<int> firstcharList;
			list<int> tempList;

			cin >> test;
			int len = strlen(test);
			for (int i = 0; i < len; ++i) {
				tempList.clear();
				for (int j = 0; j < 5; ++j) {
					for (int k = 0; k < 5; ++k) {
						if (problems[j][k] == test[i]) {
							tempList.push_back((j * 5) + k);
						}
					}
				}
				if (0 == i)
					firstcharList = tempList;
				testList.push_back(tempList);
			}


			bool result = true;

			for (list<list<int>>::iterator iter = next(testList.begin(), 1); iter != testList.end(); iter++) {
				tempList.clear();
				for (list<int>::iterator i = firstcharList.begin(); i != firstcharList.end(); i++) {
					for (list<int>::iterator j = iter->begin(); j != iter->end(); j++) {
						if (isNear(*i, *j)) {
							tempList.push_back(*j);
						}
					}
					for (list<int>::iterator j = tempList.begin(); j != tempList.end(); j++) {
						iter->remove(*j);
					}
				}
				if (tempList.size() == 0) {
					result = false;
					break;
				}
				else {
					firstcharList = tempList;
				}
			}

			if (result)
				cout << test << " YES" <<endl;
			else
				cout << test << " NO" <<endl;
	
			testCount--;
		}

		cases--;
	}
    return 0;
}


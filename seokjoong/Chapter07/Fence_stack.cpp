#include "stdafx.h"

#include<iostream>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int cases;
	int height[20001];
	stack<std::pair<int, int>> heightStack;
	
	cin >> cases;
	while (cases > 0) {
	
		int maxValue = 0;
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
			cin >> height[i];

		height[count] = 0;
		int expandIndex = 0;

		for (int i = 0; i <= count; ++i) {
			expandIndex = count + 1;
			while (!heightStack.empty() && heightStack.top().first >= height[i]) {
				maxValue = max(maxValue, heightStack.top().first * (i - heightStack.top().second));
				expandIndex = heightStack.top().second;
				heightStack.pop();
			}
			if (expandIndex < i)
				heightStack.push(make_pair(height[i], expandIndex));
			else
				heightStack.push(make_pair(height[i], i));
		}
		cout << maxValue << endl;
		cases--;
	}

    return 0;
}


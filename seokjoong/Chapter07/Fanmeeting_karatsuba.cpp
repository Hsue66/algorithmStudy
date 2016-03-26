#include "stdafx.h"
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> fanList;
vector<int> memberList;



vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size();
	int bn = b.size();
	if (an < bn) 
		return karatsuba(b, a);
	
	if (an == 0 || bn == 0) 
		return vector<int>();
	
	if (an <= 50) 
		return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	// z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);
	// z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	// a0 = a0 + a1; b0 = b0 + b1
	addTo(a0, a1, 0); 
	addTo(b0, b1, 0);
	// z1 = (a0 * b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	// ret = z0 + z1 * 10^half + z2 * 10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
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
			if (memberInput[i] == 'F')
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
		result = karatsuba(memberList, fanList);

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
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>v;
	for (int i = 1; i <= n; i++)v.push_back(i);
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--;
		reverse(v.begin() + i, v.begin() + j);
	}
	for (auto c : v)cout << c << ' ';
	cout << '\n';
}
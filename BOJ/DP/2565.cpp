#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[101];

vector<pair<int, int>>p;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p.push_back({ a,b });
	}
	sort(p.begin(), p.end());
	int ret = 0;
	for (int i = 0; i < p.size();i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (p[i].second > p[j].second) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
		ret = max(ret, d[i]);
	}
	cout << n - ret << '\n';
}
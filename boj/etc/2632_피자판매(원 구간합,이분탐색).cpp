#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int da[2002];
int db[2002];
int a[2002];
int b[2002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int size;
	cin >> size;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		da[i] = da[i - 1] + a[i];
	}
	for (int i = n + 1; i < 2 * n; i++) {
		da[i] = da[i - 1] + a[i - n];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		db[i] = db[i - 1] + b[i];
	}
	for (int i = m + 1; i <2* m; i++) {
		db[i] = db[i - 1] + b[i - m];
	}
	vector<int>p1, p2;
	for (int i = 1; i < n+1; i++) {
		for (int j = i; j < 2*n; j++) {
			if(j-i<n-1) p1.push_back(da[j] - da[i - 1]);
		}
	}
	for (int i = 1; i < m+1; i++) {
		for (int j = i; j <2* m; j++) {
			if (j - i < m-1) p2.push_back(db[j] - db[i - 1]);
		}
	}
	p1.push_back(da[n]);
	p2.push_back(db[m]);
	p1.push_back(0);
	p2.push_back(0);
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	int ret = 0;
	for (int tmp : p1) {
		auto range = equal_range(p2.begin(), p2.end(), -tmp+size);
		ret += range.second - range.first;
	}
	cout << ret << '\n';
}
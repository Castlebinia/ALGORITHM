#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[502][502];
vector<pair<int, int>> p;

int foo(int i, int j) {
	if (i == j)return 0;
	int &ret = d[i][j];
	if (ret != -1)return ret;
	if (i + 1 == j)ret = p[i].first*p[i].second*p[j].second;
	for (int k = i; k < j; k++) {
		int mi = foo(i, k) + foo(k + 1, j) + p[i].first*p[k].second*p[j].second;
		if (ret == -1 || ret > mi)ret = mi;
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x,y });
	}
	memset(d, -1, sizeof(d));
	cout << foo(0, n - 1) << '\n';
}
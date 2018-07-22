#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, w[100], v[100];
int d[101][100001];

int foo(int i,int x) {
	if (i <0 || x<0)return 0;
	int &ret = d[i][x];
	if (ret != -1)return ret;
	int full = foo(i - 1, x);
	if (w[i] > x)return ret=full;
	int get = foo(i - 1, x - w[i]) + v[i];
	return ret=max(full, get);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	memset(d, -1, sizeof(d));
	cout << foo(n-1, k) << '\n';
}
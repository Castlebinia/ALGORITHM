#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[501];
int d[501];

int foo(int x, int n) {
	int &ret = d[x];
	if (ret != -1)return ret;
	ret = 1;
	for (int i = x+1; i < n; i++) {
		if (a[x] < a[i]) {
			ret = max(ret, foo(i, n) + 1);
		}
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ret = 0;
		for (int i = 0; i < n; i++)cin >> a[i];
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++)ret = max(foo(i, n), ret);
		cout << ret << '\n';
	}
}
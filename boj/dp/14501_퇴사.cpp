#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t[16], p[16], d[16];
int n;
int foo(int x) {
	if (x==n)return 0;
	if (x > n)return -0x3f3f3f3f;
	int &ret = d[x];
	if (ret != -1)return ret;
	ret = max(foo(x + 1), foo(x + t[x]) + p[x]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	cout << foo(0) << '\n';
}
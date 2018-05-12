#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1002][31];
int a[1002];

int n, w;

int foo(int s, int t) {
	if (s > n || t > w)return 0;
	int &ret = d[s][t];
	if (ret != -1)return ret;
	int pos = t % 2 + 1;
	ret = max(foo(s + 1, t), foo(s + 1, t + 1)) + (pos==a[s]);		//t위치 s초에 알아서 받아먹음
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++)cin >> a[i];
	memset(d, -1, sizeof(d));
	cout << max(foo(1, 0), foo(1, 1)) << '\n';
}
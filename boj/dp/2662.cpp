#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
const int INF = -0x3f3f3f3f;
int a[301][21], d[301][21];
int track[301][21];

int foo(int money, int pos) {
	if (money == 0)return 0;
	if (pos == m)return INF;
	int &ret = d[money][pos];
	if (ret != -1)return ret;
	for (int i = 0; i <=money; i++) {
		int tmp = foo(money - i, pos + 1) + a[i][pos];
		if (ret < tmp) {
			ret = tmp;
			track[money][pos] = i;
		}
	}
	return ret;
}

void trace(int money, int pos) {
	if (pos == m)return;
	cout << track[money][pos] << ' ';
	trace(money - track[money][pos], pos + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		for(int j=0;j<m;j++){
			cin >> a[tmp][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << foo(n, 0) << '\n';
	trace(n, 0);
	cout << '\n';
}
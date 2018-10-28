#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int d[1000001];
int track[1000001];

int foo(int x) {
	if (x == 1) return 0;
	int &ret = d[x];
	if (ret != -1)return ret;
	ret = foo(x - 1) + 1;
	track[x] = 1;
	if (x % 3 == 0) {
		int tmp = foo(x / 3) + 1;
		if (ret > tmp) {
			ret = tmp;
			track[x] = 3;
		}
	}
	if (x % 2 == 0) {
		int tmp = foo(x / 2) + 1;
		if (ret > tmp) {
			ret = tmp;
			track[x] = 2;
		}
	}
	return ret;
}

void print(int x) {
	while (x > 1) {
		cout << x << ' ';
		if (track[x]==1)x--;
		else if (track[x] == 2)x /= 2;
		else x /= 3;
	}
	cout << 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	cout << foo(n) << '\n';
	print(n);
}
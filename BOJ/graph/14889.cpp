#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cmath>

using namespace std;

int a[21][21];

int n;
bool check[21];
int ret = 0x3f3f3f3f;

void foo(int pos, int cnt) {
	if (pos == n)return;
	if (cnt == n / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if(check[i]&&check[j])sum1 += a[i][j];
				if (!check[i]&&!check[j])sum2 += a[i][j];
			}
		}
		ret = min(ret,abs(sum1 - sum2));
	}
	check[pos] = true;
	foo(pos + 1, cnt + 1);
	check[pos] = false;
	foo(pos + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	foo(0, 0);
	cout << ret << '\n';
}
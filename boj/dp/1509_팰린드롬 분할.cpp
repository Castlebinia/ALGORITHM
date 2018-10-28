#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int d[2501][2501];
const int INF = 987654321;
string a;
int ans[2501];

int check(int i, int j) {
	int &ret = d[i][j];
	if (i == j)return ret=1;
	if (j - i == 1) {
		if (a[i] == a[j])return ret=1;
		else return ret=0;
	}
	if (ret != -1)return ret;
	if (a[i] != a[j]) return ret = 0;
	else return ret = check(i + 1, j - 1);
}

int main() {
	cin >> a;
	int n = a.length();
	a=' ' + a;
	memset(d, -1, sizeof(d));
	ans[0] = 0;
	for (int i = 1; i <=n; i++) {
		ans[i] = INF;
		for (int j = 1; j <= i; j++) {
			if (check(j,i)) {
				ans[i] = min(ans[i], ans[j - 1] + 1);
			}
		}
	}
	cout << ans[n] << '\n';
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int INF = -0x3f3f3f3f;

int n;
int a[51];
int d[51][500000];

int solve(int pos, int diff) {
	if (pos == n)return !diff ? 0 : INF;
	if (diff > 250000)return INF;
	int &ret = d[pos][diff];
	if (ret != -1)return ret;
	return ret = max({
		solve(pos + 1,diff),
		solve(pos + 1,diff + a[pos]) + a[pos],
		solve(pos + 1,abs(diff - a[pos])) + a[pos] });
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	int ret = solve(0, 0);
	if (!ret||ret==INF)cout << -1 << '\n';
	else cout << ret/2 << '\n';
}
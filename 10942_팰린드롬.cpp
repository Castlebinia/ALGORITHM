#include <iostream>
#include <cstring>

using namespace std;

int d[2001][2001];
int a[2001];

int solve(int i,int j) {
	int &ret = d[i][j];
	if (i == j)return 1;
	if (i-j==1) {
		if (a[i] == a[j])return ret=1;
		else return ret=0;
	}
	if (ret != -1)return ret;
	if (a[i] != a[j])return ret = 0;
	else return ret=solve(i + 1, j - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	memset(d, -1, sizeof(d));
	int t;
	cin >> t;
	while (t--) {
		int s, e;
		cin >> s >> e;
		cout << solve(s, e) << '\n';
	}
}
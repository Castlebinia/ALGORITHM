#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int&a, const int &b) { return a > b; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	if (m*k < n || n < m + k - 1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int>p, q;
	for (int i = 1; i <= n; i++)p.push_back(i);
	n -= k,m -= 1;
	int g, mod;
	if (m == 0) g = 1, mod = 0;
	else g = n / m, mod = n % m;
	int last = k;
	sort(p.begin(), p.begin() + k, cmp);
	for (int i = 0; i < m; i++) {
		int next = last + g + (mod > 0 ? 1 : 0);
		sort(p.begin() + last, p.begin() + next, cmp);
		if (mod > 0)mod--;
		last = next;
	}
	for (auto x : p)cout << x << ' ';
	cout << '\n';
}
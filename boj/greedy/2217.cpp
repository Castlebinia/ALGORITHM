#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll>p;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		p.push_back(x);
	}
	sort(p.begin(), p.end());
	ll ret = 0;
	for (int i = 0; i < n;i++) {
		ret = max(ret, p[i] * (n - i));
	}
	cout << ret << '\n';
}
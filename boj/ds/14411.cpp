#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<ll, ll>>p, rp;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		p.push_back({ x,y });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) {
		while (!rp.empty() && rp.back().second < p[i].second) rp.pop_back();
		rp.push_back({ p[i].first,p[i].second });
	}
	ll ret = rp[0].first*rp[0].second;
	for (int i =1; i < rp.size(); i++) ret += (rp[i].first - rp[i - 1].first)*rp[i].second;
	cout << ret << '\n';
}
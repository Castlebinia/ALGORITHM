#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>p1;
	vector<int>p2;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		p1.push_back({ m,v });
	}
	sort(p1.begin(), p1.end());
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		p2.push_back(x);
	}
	ll idx, ret;
	idx = ret = 0;
	priority_queue<ll>pq;
	sort(p2.begin(), p2.end());
	for (int i = 0; i < k;i++) {
		while (idx<n&&p2[i]>=p1[idx].first) {
			pq.push(p1[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ret += (ll)pq.top();
			pq.pop();
		}
	}
	cout << ret << '\n';
}
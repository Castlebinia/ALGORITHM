#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool check[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int>p;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		p.push_back(x);
	}
	sort(p.begin(), p.end());
	priority_queue<int>pq;
	for (int i = 0; i < p.size()-1; i++) {
		pq.push(p[i+1] - p[i]);
	}
	int ret = 0;
	for (int i = 0; i < k-1; i++) {
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << p[p.size()-1]-p[0] - ret << '\n';
}
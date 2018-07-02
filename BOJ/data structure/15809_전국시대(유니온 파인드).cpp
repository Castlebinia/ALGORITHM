#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int p[100001];
int sum[100001];

int find(int n) {
	if (p[n]<0)return n;
	return p[n] = find(p[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		p[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 1){
			a = find(a);
			b = find(b);
			p[b] = a;
			sum[a] += sum[b];
			sum[b] = 0;
		}
		else {
			a = find(a);
			b = find(b);
			if(sum[a]>sum[b]){
				p[b] = a;
				sum[a] -= sum[b];
				sum[b] = 0;
			}
			else if (sum[a] < sum[b]) {
				p[a] = b;
				sum[b] -= sum[a];
				sum[a] = 0;
			}
			else {
				sum[a] = 0;
				sum[b] = 0;
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] != 0)ret++;
	}
	cout << ret << '\n';
	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		if (sum[i] != 0)ans.push_back(sum[i]);
	}
	sort(ans.begin(), ans.end());
	for (auto x : ans)cout << x << ' ';
	cout << '\n';
}
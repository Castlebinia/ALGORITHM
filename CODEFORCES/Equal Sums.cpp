#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, pair<int, int>>m;
int sum[200001];
vector<vector<int>> p;

int main() {
	int k;
	cin >> k;
	p.resize(k);
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			sum[i] += x;
			p[i].push_back(x);
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p[i].size(); j++) {
			pair<int,int> &ret = m[sum[i] - p[i][j]];
			if (ret == make_pair(0, 0)) {
				ret.first = i;
				ret.second = j;
			}
			else if (ret.first != i) {
				cout << "YES\n" << ret.first + 1 << ' ' << ret.second + 1 << '\n';
				cout<< i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
}
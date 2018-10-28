#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[51][100];
char op[4] = { 'A','C','G','T' };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string>v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt[j][v[i][j]]++;
		}
	}
	vector<char>ans;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		char ctmp = 'Z';
		for (int j = 0; j < 4; j++) {
			if (tmp < cnt[i][op[j]]) {
				tmp = cnt[i][op[j]];
				ctmp = op[j];
			}
			else if (tmp == cnt[i][op[j]]) {
				if (ctmp > op[j]) {
					ctmp = op[j];
				}
			}
		}
		ans.push_back(ctmp);
	}
	for (auto c : ans)cout << c;
	cout << '\n';
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != ans[j])ret++;
		}
	}
	cout << ret << '\n';
}


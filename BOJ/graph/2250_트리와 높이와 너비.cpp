#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>>p(10001);
vector<int>v[10001];
vector<int>level(10001);
vector<int>width(10001);
vector<int>solve[10001];
bool root[10001];
bool check[10001];
const int INF= 0x3f3f3f3f;

int w, h,m;
void foo(int x) {
	if (x == -1)return;
	foo(p[x].first);
	width[x] = ++w;
	foo(p[x].second);
}

void dfs(int now) {
	check[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!check[next] && next != -1) {
			check[next] = true;
			level[next] = level[now] + 1;
			solve[level[next]].push_back(next);
			m = max(level[next], m);
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, l, r;
		cin >> x >> l >> r;
		p[x] = { l,r };
		v[x].push_back(l);
		v[x].push_back(r);
		root[l] = true;
		root[r] = true;
	}
	int r;
	for (int i = 1; i <= n; i++) {
		if (!root[i]) {
			r = i;
			break;
		}
	}
	solve[1].push_back(r);
	level[r] = 1;
	foo(r);
	dfs(r);
	int ret = 1;
	int what = 1;
	for (int i = 1; i <=m; i++) {
		int Max = 0;
		int Min = INF;
		for (auto x : solve[i]) {
			Max = max(width[x], Max);
			Min = min(width[x], Min);
		}
		if (ret < Max-Min+1) {
			what = i;
			ret = Max - Min + 1;
		}
	}
	cout << what << ' ' << ret << '\n';
}
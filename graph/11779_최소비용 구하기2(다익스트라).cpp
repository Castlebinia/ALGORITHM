#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int inf = 987654321;
bool check[1001];
int d[1001];
int path[100001];

vector<pair<int,int>>p[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, start, end;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p[u].push_back({ v,c });
	}
	cin >> start >> end;
	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
	d[start] = 0;
	for (int k = 0; k < n-1; k++) {
		int m = inf + 1;
		int here = -1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && d[i] < m) {
				m = d[i];
				here = i;
			}
		}
		check[here] = true;
		for (int i = 0; i < p[here].size(); i++) {
			int there = p[here][i].first;
			int cost = p[here][i].second;
			if (d[there] > d[here] + cost) {
				d[there] = d[here] + cost;
				path[there] = here;
			}
		}
	}
	path[start] = -1;
	cout << d[end] << '\n';
	stack<int>st;
	int x = end;
	while (x != -1) {
		st.push(x);
		x = path[x];
	}
	cout << st.size() << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
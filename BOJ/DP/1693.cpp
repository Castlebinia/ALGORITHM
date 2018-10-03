#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
vector<vector<int>>p, tree;
bool visited[100001];
int d[100001][18];	//2^18>10^5
int n;
const int INF = 0x3f3f3f3f;

void make_tree(int now) {
	visited[now] = true;
	for (auto &next : p[now]) {
		if (!visited[next]) {
			tree[now].push_back(next);
			make_tree(next);
		}
	}
}

int foo(int root, int k) {	//k is parent color
	int &ret = d[root][k];
	if (ret != -1)return ret;
	ret = INF;
	for (int i = 1; i <= log2(n)+1; i++) {
		if (i == k)continue;
		int tmp = i;
		for (auto next : tree[root])tmp += foo(next, i);
		ret = min(ret, tmp);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	p.resize(n + 1);
	tree.resize(n + 1);
	for(int i=0;i<n-1;i++){
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	make_tree(1);
	memset(d, -1, sizeof(d));
	cout << foo(1,0) << '\n';
}
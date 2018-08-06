#include <iostream>
#include <vector>

using namespace std;

bool check[51];
int parent[51];
int root;
vector<vector<int>>child;

void go(int now) {
	check[now] = true;
	for (auto next : child[now]) {
		check[next] = true;
		go(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	child.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == -1)root = i;
		else {
			child[x].push_back(i);
			parent[i] = x;
		}
	}
	int d;
	cin >> d;
	go(d);
	int ret = 0;
	if (child[parent[d]].size() == 1)ret++;
	for (int i = 0; i < n; i++) {
		if (!check[i] && !child[i].size())ret++;
	}
	cout << ret << '\n';
}
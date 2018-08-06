#include <iostream>
#include <vector>

using namespace std;

int parent[51];
int root;
vector<vector<int>>child;

int go(int now) {
	int ret = child[now].empty() ? 1 : 0;
	for (auto next : child[now]) ret += go(next);
	return ret;
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
	cout << go(root)-go(d)+(child[parent[d]].size()==1?1:0) << '\n';
	
}
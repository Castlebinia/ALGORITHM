#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
vector<ll>p[300001];
bool check[300001];
int par[300001];

ll dfs(int now, int fin,bool flag) {
	int ret = 0;
	check[now] = true;
	if (now == fin)flag = true;
	if (flag)ret++;
	for (auto s : p[now]) {
		if (!check[s]) {
			ret+=dfs(s, fin, flag);
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, x, y;
	bool flag = false;
	cin >> n >> x >> y;
	ll ret = n*(n-1);
	for(int i=0;i<n-1;i++){
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	ll a = (dfs(x, y, flag));
	flag = false;
	memset(check, false, sizeof(check));
	ll b = dfs(y, x, flag);
	cout << ret - (a*b) << '\n';
}
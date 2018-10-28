#include <iostream>
#include <vector>

using namespace std;

int parent[100001];
vector<vector<int> >p;

void dfs(int now){
	for(int next:p[now]){
		if(!parent[next]){
		parent[next]=now;
		dfs(next);}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	p.resize(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
	    cin >> u>>v;
		p[u].push_back(v);
		p[v].push_back(u);
																	}
		dfs(1);
	    for(int i=2;i<=n;i++)cout << parent[i] << '\n';
}


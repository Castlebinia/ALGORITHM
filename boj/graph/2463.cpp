#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e+9;

struct edge{
	int u,v,c;
	bool operator<(const edge&a){
		return a.c<this->c;
	}
};

int pa[100001];
ll cost[100001],s[100001];

int find(int a){
	if(pa[a]<0)return a;
	pa[a]=find(pa[a]);
	return pa[a];
}

void merge(int x,int y){
	int a=find(x);
	int b=find(y);
	s[a]+=s[b];
	pa[b]=a;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<edge>p;
	memset(pa,-1,sizeof(pa));
	for(int i=1;i<=n;i++)s[i]=1;
	ll ret=0,sum=0;
	for(int i=0;i<m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		p.push_back({u,v,c});
		sum+=c;
	}
	sort(p.begin(),p.end());
	for(int i=0;i<m;i++){
		int a=find(p[i].u);
		int b=find(p[i].v);
		if(a!=b){
			ret+=((s[a]%mod*s[b]%mod)*sum)%mod;
			ret%=mod;
			merge(a,b);
		}
		sum-=p[i].c;
	}
	cout << ret << '\n';
}


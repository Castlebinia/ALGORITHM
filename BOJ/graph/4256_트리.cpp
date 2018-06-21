#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>pre;
vector<int>in;

void post(int pl,int pr,int il,int ir){
	if (pl > pr)return;
	int root = pre[pl];
	int pos= in[root];
	int left = pos - il;
	post(pl+1,pl+left,il,pos-1);
	post(pl+left+1,pr,pos+1,ir);
	cout << root << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pre.clear();
		in.clear();
		pre.resize(n);
		in.resize(n+1);
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			in[x] = i;
		}
		post(0,n-1,0,n-1);
		cout << '\n';
	}
}
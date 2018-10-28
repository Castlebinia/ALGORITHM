#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int a[8];
map<string, int>d;

string swap(string s,int l,int r) {
	string ret = s;
	int tmp = r;
	for (int i = l; i <= r; i++)ret[tmp--]= s[i];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	string ans = "";
	string first = "";
	queue<string>q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		first += to_string(a[i]);
	}
	set<string> visited;
	visited.insert(first);
	sort(a, a + n);
	for (int i = 0; i < n; i++) ans += to_string(a[i]);
	q.push(first);
	bool flag = false;
	while (!q.empty()) {
			string now = q.front();
			q.pop();
			if (now == ans) {
				flag = true;
				break;
			}
			for (int i = 0; i <= n-k; i++) {
				string next = swap(now,i,i+k-1);
				if (visited.find(next) == visited.end()) {
					visited.insert(next);
					d[next] = d[now] + 1;
					q.push(next);
				}
			}
	}
	if (!flag)cout << -1 << '\n';
	else cout << d[ans] << '\n';
}
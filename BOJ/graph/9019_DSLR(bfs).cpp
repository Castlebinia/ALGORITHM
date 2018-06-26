#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

bool visit[10000];
char op[] = { 'D','S','L','R' };
int cal(char c, int num) {
	if (c == 'D') {
		if (2 * num > 9999) {
			return (2 * num) % 10000;
		}
		else return 2 * num;
	}
	else if (c == 'S') {
		if (num == 0)return 9999;
		else return num - 1;
	}
	else if (c == 'L') {
		return (num%1000)*10 + num/1000;
	}
	else if(c=='R'){
		return (num / 10) + (num % 10)*1000;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n, m;
	int from[10000];
	char path[10000];
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> n >> m;
		queue<int> q;
		q.push(n);
		visit[n] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (now == m) {
				stack<int>s;
				int i = now;
				while (i!=n) {
					s.push(i);
					i = from[i];
				}
				while (!s.empty()) {
					int tmp = s.top();
					s.pop();
					cout << path[tmp];
				}
				break;
			}
			for (int i = 0; i < 4; i++) {
				int next = cal(op[i], now);
				if (!visit[next]) {
					visit[next] = true;
					q.push(next);
					from[next] = now;
					path[next] = op[i];
				}
			}
		}
		cout << '\n';
	}
}
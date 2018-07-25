#include <iostream>
#include <cstring>
using namespace std;

bool visited[100001];
bool finished[100001];
int p[100001];
int cnt;

void dfs(int now) {
	visited[now] = true;
	int next = p[now];
	if (visited[next]) {
		if (!finished[next]) {
			while (now != next) {
				cnt++;
				next = p[next];
			}
			cnt++;
		}
	}
	else dfs(next);
	finished[now] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> p[i];
		for (int i = 1; i <= n; i++)if (!visited[i])dfs(i);
		cout << n - cnt << '\n';
	}

}
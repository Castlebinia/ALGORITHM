#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int s = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0)tmp = 9;
			s = s * 10 + tmp;
		}
	}
	queue<int>q;
	q.push(s);
	map<int, int> d;
	d[s] = 0;
	while (!q.empty()) {
		int now =q.front();
		q.pop();
		string nowstr = to_string(now);
		int zero = nowstr.find('9');
		int x = zero / 3;
		int y = zero % 3;
		for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 3 && ny < 3 && nx >= 0 && ny >= 0) {
					string next = nowstr;
					swap(next[3 * x + y], next[3 * nx + ny]);
					int nextnum = stoi(next);
					if (d.count(nextnum) == 0) {
						d[nextnum] = d[now] + 1;
						q.push(nextnum);
					}
				}
			}
		}
	
	if (d.count(123456789)==0)cout << -1 << '\n';
	else cout << d[123456789] << '\n';	
}
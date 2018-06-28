#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>>pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			pq.push(x);
		}
		while (pq.size() != n)pq.pop();
	}
	cout << pq.top() << '\n';
}
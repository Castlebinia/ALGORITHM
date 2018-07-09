#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
int a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		priority_queue<int, vector<int>, greater<int>>minq;
		priority_queue<int>maxq;
		for (int i = 1; i <= m; i++) cin >> a[i];
		vector<int>ret;
		int mid = a[1];
		ret.push_back(a[1]);
		for (int i = 2; i <= m; i++) {
			if (i % 2 != 0) {
				if (minq.top() < a[i]) {
					mid = minq.top();
					minq.pop();
					minq.push(a[i]);
				}
				else if(maxq.top()>a[i]){
					mid = maxq.top();
					maxq.pop();
					maxq.push(a[i]);
				}
				else{
					mid = a[i];
				}
				ret.push_back(mid);
			}
			if(i%2==0) {
				if (a[i] > mid) {
					maxq.push(mid);
					minq.push(a[i]);
				}
				else {
					maxq.push(a[i]);
					minq.push(mid);
				}
			}
		}
		cout << ret.size() << '\n';
		for (int i = 0; i < ret.size(); i++) {
			if (i!=0&&i % 10 == 0)cout << '\n';
			cout << ret[i] << ' ';
		}
		cout << '\n';
	}
}
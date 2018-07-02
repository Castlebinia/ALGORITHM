#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

using ll = long long;

class cmp{
public:
	bool operator()(const ll &a,const ll &b) {
		if (abs(a) == abs(b))return a > b;
		else return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<ll,vector<ll>, cmp>pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		if (tmp != 0)pq.push(tmp);
		else{
			if (pq.empty())cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}
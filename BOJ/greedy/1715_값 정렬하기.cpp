#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>>pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(x);
	}
	int ret = 0;
	while (pq.size() != 1){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		pq.push(first + second);
		ret += first + second;
	}
	cout << ret << '\n';
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point { 
	int x, i; 
	Point(int x, int i) :x(x), i(i) {}
};

int a[1000001];
int tree[1000001 * 4];
int ssize = 1;

void update(int i, int x) {
	i += ssize;
	tree[i] = x;
	while (i > 1) {
		i /= 2;
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}
}

int query(int node, int start,int end, int i, int j) {
	if (i>end || j<start)return 0;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return max(query(node * 2, start, m, i, j), query(node * 2 + 1, m + 1, end, i, j));
}

bool cmp(const Point&a, const Point &b) {
	if (a.x == b.x)return a.i > b.i;
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (ssize < n) ssize <<= 1;
	ssize--;
	vector<Point>p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p.push_back({ a[i],i });
	}
	sort(p.begin(), p.end(), cmp);
	for (int i = 0; i < n; i++) {
		int tmp = query(1,1,ssize,1,p[i].i);
		update(p[i].i, tmp+1);
	}
	cout << tree[1] << '\n';
}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int check[300001];
int p[300001];

int find(int n) {
	if (p[n]<0)return n;
	else return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	p[b] = a;
	cout << "LADICA\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	memset(p, -1, sizeof(p));
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (!check[a]) {
			check[a] = true;
			merge(a, b);
		}
		else if (!check[b]) {
			check[b] = true;
			merge(b, a);
		}
		else if (!check[find(a)]) {
			check[find(a)] = true;
			merge(a, b);
		}
		else if (!check[find(b)]) {
			check[find(b)] = true;
			merge(b, a);
		}
		else {
			cout << "SMECE\n";
		}
	}

}
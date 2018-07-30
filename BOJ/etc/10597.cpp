#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check[51];
int ret[51];
bool flag = false;
int len;
string s;

void foo(int x,int pos) {
	if (x == len) {
		for (int i = 0; i < len;i++)cout << ret[i] << ' ';
		cout << '\n';
		exit(0);
	}	
	int one = (s[pos] - '0');
	if (!check[one] && one!=0) {
		check[one] = true;
		ret[x] = one;
		foo(x + 1, pos + 1);
		check[one] = false;
	}
	if (!s[pos + 1])return;
	int two = one*10 + (s[pos + 1] - '0');
	if (check[two]||two<=0||two>len)return;
	check[two] = true;
	ret[x] = two;
	foo(x + 1, pos + 2);
	check[two] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; s[i];) {
		len++;
		i += (len < 10 ? 1 : 2);
	}
	foo(0,0);
}
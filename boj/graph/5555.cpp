#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n;
	cin >> n;
	int ret=0;
	for(int i=0;i<n;i++){
		string x;
		cin >> x;
		x+=x;
		if(x.find(s)!=-1)ret++;
	}
	cout << ret << '\n';
}


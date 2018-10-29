#include <iostream>
#include <string>

using namespace std;

int h[26] = { 3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1 };
int d[4001][4001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin >> s>>t;
	int idx=0;
	for(int i=0;s[i];i++,idx+=2){
		d[0][idx]=h[s[i]-'A'];
		d[0][idx+1]=h[t[i]-'A'];
	}
	int len=s.size()*2;
	for(int i=0;i<len-2;i++){
		for(int j=0;j<len-i-1;j++){
			d[i+1][j]=(d[i][j]%10+d[i][j+1]%10)%10;
		}
	}
	cout << d[len-2][0] << d[len-2][1] << '\n';
}

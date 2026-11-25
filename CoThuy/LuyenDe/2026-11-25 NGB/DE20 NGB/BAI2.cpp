#include<iostream>
using namespace std;
int n;
long long cnt,res;
string s;
void solve(){
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') cnt=0;
		else res+=++cnt;
	}
	cout<<res;
}
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	solve();
}
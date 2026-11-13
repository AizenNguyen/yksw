#include<iostream>
#include<string>
#include<vector>
using namespace std;
int t,ssz;
string s;
void solve(){
	cin>>s;
	ssz=s.size();
	int cnt[256]={0};
	for(char c:s) cnt[(unsigned char)c]++;
	for(int i=0;i<ssz;i++)
		if(cnt[(unsigned char)s[i]]==1){
			cout<<i+1<<'\n';
			return;
		}
	cout<<-1<<'\n';
}
int main(){
	if(fopen("BAI3.INP","r")){
		freopen("BAI3.INP","r",stdin);
		freopen("BAI3.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
		solve();
}
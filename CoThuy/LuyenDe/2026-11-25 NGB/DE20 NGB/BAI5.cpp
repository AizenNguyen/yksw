#include<iostream>
using namespace std;
const int MOD=1e9+7;
int n,a[1000006];
long long s;
void brute(){
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				s=(s+((1LL*(a[i]%MOD)*(a[j]%MOD))%MOD)*(a[k]%MOD)%MOD)%MOD;
	cout<<s;
}
void solve(){

}
int main(){
	if(fopen("BAI5.INP","r")){
		freopen("BAI5.INP","r",stdin);
		freopen("BAI5.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	brute();
	//solve();
}
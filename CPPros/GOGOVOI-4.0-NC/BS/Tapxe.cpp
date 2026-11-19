#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,diff,len,a[1000006];
long long res;
void solve(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		diff=m-a[i];
		if(a[i]+a[i+1]>m) break;
		auto it=upper_bound(a+1,a+n+1,m-a[i]);
		len=(it-a)-i-1;
		res+=len;
		//cout<<i<<" "<<it-a<<" "<<len<<" "<<res<<'\n';
	}
	cout<<res<<'\n';
	len=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve();
	cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
}
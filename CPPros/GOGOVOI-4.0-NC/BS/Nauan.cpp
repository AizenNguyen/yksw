#include<iostream>
#include<algorithm>
using namespace std;
int n,q,a[100010];
long long x,ans[100010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1LL*ans[i-1]+a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x;
		auto it=lower_bound(ans+1,ans+n+1,x);
		cout<<it-ans<<'\n';
	}
}
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200005];
long long res;
void solve(){
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) res+=1LL*abs(a[i]-i);
	cout<<res;
}
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve();
}
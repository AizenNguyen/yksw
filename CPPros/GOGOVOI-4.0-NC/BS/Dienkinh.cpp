#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,diff,a[100005];
void solve(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		diff=a[i]+m;
		auto it=lower_bound(a+1,a+n+1,a[i]+m);
		if(*it==diff){
			cout<<a[i]<<" "<<*it;
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve();
}
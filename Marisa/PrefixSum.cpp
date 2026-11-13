#include<iostream>
using namespace std;
int n,q,l,r,a[100010];
long long pf[100010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
	for(int i=1;i<=q;++i){
		cin>>l>>r;
		cout<<pf[r]-pf[l-1]<<'\n';
	}
}
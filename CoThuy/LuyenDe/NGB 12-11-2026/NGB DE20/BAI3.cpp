#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e6+6;
int n,m;
void solve(){
	int x,diff=n-m;
	long long MIN=1e18;
	vector<long long> pf(n+1);
	for(int i=1;i<=n;i++){
		cin>>x;
		pf[i]=pf[i-1]+x;
	}
	for(int i=0;i<=m;i++) MIN=min(MIN,pf[diff+i]-pf[i]);
	cout<<pf[n]-MIN<<'\n';
}
void solve_sw(){
	int l=2,r=m+1;
	long long MIN,res;
	MIN=res=0;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res+=a[i];
	}
	for(int i=1;i<=m;i++) MIN+=a[i];
	cout<<MIN<<'\n';
	while(r<=n){
		MIN=min(MIN,MIN-a[l]+a[r]);
		cout<<MIN-a[l]+a[r]<<'\n';
		l++; r++;
	}
	cout<<res-MIN<<'\n';
}
int main(){
	if(fopen("BAI3.INP","r")){
		freopen("BAI3.INP","r",stdin);
		freopen("BAI3.INP","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	//solve();
	solve_sw();
}
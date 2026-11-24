#include<iostream>
#include<vector>
using namespace std;
int n,x,q,u,v;
long long cnt;
void brute(){
	long long s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--){
		cin>>u>>v;
		s=0;
		for(int i=u;i<=v;i++) s+=a[i];
		cnt+=s<x?1:0; 
	}
	cout<<cnt<<'\n';
	cnt=0;
}
void solve(){
	int xi;
	vector<long long> pf(n+1);
	for(int i=1;i<=n;i++){
		cin>>xi;
		pf[i]=pf[i-1]+xi;
	}
	while(q--){
		cin>>u>>v;
		cnt+=pf[v]-pf[u-1]<x?1:0;
	}
	cout<<cnt<<'\n';
	cnt=0;	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x>>q;
	//brute();
	solve();
}
#include<iostream>
using namespace std;
int n;
long long res=-1e18;
void brute(){
	int a[n+1]; a[0]=0;
	long long s=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(res<s) res=s;
		}
	}
	cout<<res<<'\n';
}
void solve_pf(){
	int x;
	long long MINpf,res=-1e18,pf[n+1];
	pf[0]=MINpf=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf[i]=pf[i-1]+x;
	}
	for(int i=1;i<=n;i++){
		res=max(res,pf[i]-MINpf);
		MINpf=min(MINpf,pf[i]);
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//brute();
	solve();
}
//		res=res>pf[i]-MINpf?res:pf[i]-MINpf;
//		MINpf=MINpf<pf[i]?MINpf:pf[i];
#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,k,s,MOD,res;
int main(){
	if(fopen("CAU1.INP","r")){
		freopen("CAU1.INP","r",stdin);
		freopen("CAU1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>k;
		res=1e18;
		MOD=n/k;
    	MOD=(n==(MOD)*k?MOD:MOD+1);
		res=res<n*a?res:n*a;
		res=res<MOD*b?res:MOD*b;
		s=(n%k)*a+(n/k)*b;
		if(s<res) res=s;
		//s=(n%k)*b+(n/k)*a;
		cout<<res<<'\n';
	}
}
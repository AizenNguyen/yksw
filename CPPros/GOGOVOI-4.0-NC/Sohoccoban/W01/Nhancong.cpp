#include<iostream>
#include<cmath>
#include <cstdint>
using namespace std;
int t;
int64_t a,d,q,n,uAP,uGP,sAP,sGP;
void brute(){
	for(int i=1;i<=t;i++){
		cin>>a>>d>>q>>n;
		uAP=uGP=sAP=sGP=a;
		for(int i=2;i<=n;i++){
			uAP+=d;
			sAP+=uAP;
			uGP*=q;
			sGP+=uGP;
		}
		cout<<uAP<<" "<<sAP<<" "<<uGP<<" "<<sGP<<'\n';
	}
	uAP=sAP=uGP=sGP=0;
}
void solve(){
	for(int i=1;i<=t;i++){
		cin>>a>>d>>q>>n;
		uAP=a+(n-1)*d;
		sAP=n*a+(d*n*(n-1))/2;
		uGP=a*pow(q,n-1);
		//sGP=(q==1)?a*n:a*((pow(q,n)-1)/(q-1));
		sGP=(q==1)?a*n:a*((1-pow(q,n))/(1-q));
		cout<<uAP<<" "<<sAP<<" "<<uGP<<" "<<sGP<<'\n';
	}
	uAP=sAP=uGP=sGP=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	brute();
	//solve();
}
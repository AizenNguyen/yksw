// Luy thua nhi phan (O(log b)) va Nhan An Do mul_mod chong tran long long (O(log b))
// Luu y: dung mul_mod khi MOD > 2e9 (co the len toi ~4e18)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const long long MOD=1000000007;

long long mul_mod(long long a,long long b,long long m){
	long long res=0;
	a=(a%m+m)%m;
	b=(b%m+m)%m;
	while(b>0){
		if(b&1){
			res+=a;
			if(res>=m) res-=m;
		}
		a+=a;
		if(a>=m) a-=m;
		b>>=1;
	}
	return res;
}

long long fast_pow(long long a,long long b,long long m){
	long long res=1%m;
	a=(a%m+m)%m;
	while(b>0){
		if(b&1) res=(1LL*res*a)%m;
		a=(1LL*a*a)%m;
		b>>=1;
	}
	return res;
}

long long fast_pow_safe(long long a,long long b,long long m){
	long long res=1%m;
	a=(a%m+m)%m;
	while(b>0){
		if(b&1) res=mul_mod(res,a,m);
		a=mul_mod(a,a,m);
		b>>=1;
	}
	return res;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long a,b,m;
	if(cin>>a>>b>>m){
		cout<<fast_pow(a,b,m)<<" "<<fast_pow_safe(a,b,m)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}

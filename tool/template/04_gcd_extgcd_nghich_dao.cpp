// GCD, LCM, Euclid mo rong (ax+by=gcd(a,b)) va Nghich dao Modulo (O(log N))
// Luu y: mod_inv(a,m) ton tai khi gcd(a,m)==1; chia truoc khi nhan trong lcm tranh tran so
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

long long gcd(long long a,long long b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	while(b!=0){
		long long r=a%b;
		a=b;
		b=r;
	}
	return a;
}

long long lcm(long long a,long long b){
	if(a==0||b==0) return 0;
	return a/gcd(a,b)*b;
}

long long ext_gcd(long long a,long long b,long long& x,long long& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long x1,y1;
	long long d=ext_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}

long long mod_inv(long long a,long long m){
	long long x,y;
	long long d=ext_gcd((a%m+m)%m,m,x,y);
	if(d!=1) return -1;
	return (x%m+m)%m;
}

long long fast_pow(long long a,long long b,long long m){
	long long res=1%m;
	a=(a%m+m)%m;
	while(b>0){
		if(b&1) res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res;
}

long long mod_inv_prime(long long a,long long p){
	return fast_pow(a,p-2,p);
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long a,b,m;
	if(cin>>a>>b>>m){
		long long x,y;
		long long g=ext_gcd(a,b,x,y);
		cout<<"gcd="<<g<<" lcm="<<lcm(a,b)<<" x="<<x<<" y="<<y<<'\n';
		cout<<"inv="<<mod_inv(a,m)<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}

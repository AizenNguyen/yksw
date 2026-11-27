// Tinh to hop nCr mod p: O(N) tien xu ly + O(1) truy van; kem Pascal DP cho mod bat ky (N<=2000)
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

const int MAXN=1000005;
const long long MOD=1000000007;
long long fact[MAXN],inv_fact[MAXN];

long long fast_pow(long long a,long long b,long long m){
	long long res=1%m;
	a%=m;
	while(b>0){
		if(b&1) res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res;
}

void build_comb(int limit=MAXN-1){
	fact[0]=1;
	for(int i=1;i<=limit;i++) fact[i]=fact[i-1]*i%MOD;
	inv_fact[limit]=fast_pow(fact[limit],MOD-2,MOD);
	for(int i=limit-1;i>=0;i--) inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
}

long long nCr(int n,int k){
	if(k<0||k>n) return 0;
	return fact[n]*inv_fact[k]%MOD*inv_fact[n-k]%MOD;
}

// Dung khi n<=2000 va mod khong phai so nguyen to
const int MAXP=2005;
long long C[MAXP][MAXP];

void build_pascal(int n,long long m){
	for(int i=0;i<=n;i++){
		C[i][0]=1%m;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=m) C[i][j]-=m;
		}
	}
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	build_comb(1000000);
	int q,n,k;
	if(cin>>q){
		while(q--){
			cin>>n>>k;
			cout<<nCr(n,k)<<'\n';
		}
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}

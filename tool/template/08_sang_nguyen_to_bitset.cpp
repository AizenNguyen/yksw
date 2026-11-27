// Sang Eratosthenes bitset (O(N log log N)) & Kiem tra nguyen to O(sqrt(N))
// Quy uoc: not_prime[x]==0 la so nguyen to, ==1 la hop so
#include<iostream>
#include<cstdio>
#include<ctime>
#include<bitset>
using namespace std;

const int MAXN=10000000;
bitset<MAXN+8> not_prime;

void sieve(int limit=MAXN){
	not_prime[0]=not_prime[1]=1;
	for(int i=4;i<=limit;i+=2) not_prime[i]=1;
	for(int i=3;1LL*i*i<=limit;i+=2)
		if(!not_prime[i])
			for(long long j=1LL*i*i;j<=limit;j+=2LL*i)
				not_prime[j]=1;
}

bool is_prime(long long n){
	if(n<=1) return false;
	if(n==2||n==3) return true;
	if(n%2==0||n%3==0) return false;
	for(long long i=5;i<=n/i;i+=6)
		if(n%i==0||n%(i+2)==0) return false;
	return true;
}

int main(){
	if(fopen("TENBAI.INP","r")){
		freopen("TENBAI.INP","r",stdin);
		freopen("TENBAI.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	sieve(1000000);
	long long x;
	if(cin>>x){
		if(x<=1000000&&x>=0) cout<<(!not_prime[x]?"YES":"NO")<<'\n';
		else cout<<(is_prime(x)?"YES":"NO")<<'\n';
	}
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}

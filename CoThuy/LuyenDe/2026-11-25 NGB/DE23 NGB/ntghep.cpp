#include<bits/stdc++.h>
#include<vector>
#include<ctime>
#include<bitset>
using namespace std;
const int MAXN=1e7;
short m;
bitset<MAXN+8> prime;
bool primecheck(long long n){
	if(n<=1) return false;
	if(n==2||n==3) return true;
	if(n%2==0||n%3==0) return false;
	for(int i=5;i<=n/i;i+=6)
		if(n%i==0||n%(i+2)==0)
			return false;
	return true;
}
void sieve(){
	prime[0]=prime[1]=1;
	for(int i=3;i*i<=MAXN;i+=2)
		if(!prime[i])
			for(int j=i*i;j<=MAXN;j+=i)
				prime[j]=1;
}
void solve(){
	sieve();
	if(m==0) cout<<0;
	else cout<<"23\n";
	m--;
	int alpha_cnt=10;
	unsigned long long ghep=0;
	cout<<primecheck(10000000000);
	// for(int i=5;i<=MAXN;i+=2){
	// 	if(!prime[i]){
	// 		if(ghep){
	// 			while(alpha_cnt<=i) alpha_cnt*=10;
	// 			ghep=ghep*alpha_cnt+i;
	// 			if(ghep<=1e7)
	// 				if(!prime[ghep]){
	// 					cout<<ghep<<'\n';
	// 					m--;
	// 				}
	// 			else{
	// 				if(primecheck(ghep)){
	// 					cout<<ghep<<'\n';
	// 					m--;
	// 				}
	// 			}
	// 			alpha_cnt=10;
	// 			ghep=0;
	// 		}
	// 		else ghep=i;
	// 	}
	// }
}
int main(){
	if(fopen("NTGHEP.INP","r")){
		freopen("NTGHEP.INP","r",stdin);
		freopen("NTGHEP.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m;
	solve();
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
}
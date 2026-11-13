#include<iostream>
#include<cmath>
using namespace std;
long long n,res=1;
bool prime[1000006];
void ssnt(){
	prime[0]=prime[1]=1;
	for(int i=3;i*i<=1000001;i+=2)
		if(!prime[i])
			for(int j=i*i;j<=1000001;j+=i)
				prime[j]=1;
}
void solve(){
	if(n<4){
		cout<<0;
		return;
	}
	else if(n==4){
		cout<<1;
		return;
	}
	ssnt();
	n=sqrtl(n);
	for(int i=3;i<=n;i+=2)
		if(!prime[i]) res++;
	cout<<res;
	res=0;
}
int main(){
	if(fopen("bauoc.inp","r")){
		freopen("bauoc.inp","r",stdin);
		freopen("bauoc.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve();
}
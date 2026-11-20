#include<iostream>
using namespace std; 
int n,a[1000010];
long long k,p,res;
void sub1(){
	for(int i=1;i<=k;++i){
		cin>>a[i];
		res+=a[i];
	}
	cout<<res;
}
void solve(){
	long long kp,check=0;
	kp=k+p-1;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i){
		check++;
		if(check>=p&&check<=kp) res+=a[i];
		if(check==kp) break;
		if(i==n) i=0;
	}
	cout<<res%1000000007;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("tong.inp","r",stdin);
	freopen("tong.out","w",stdout);
	cin>>n>>k>>p;
	if(n<=1000&&p==1&&k<=n)sub1();
	else solve();
}
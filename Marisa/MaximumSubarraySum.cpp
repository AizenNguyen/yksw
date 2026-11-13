#include<iostream>
using namespace std;
int n,a[100010];
long long pfmin=100000000000000,pfmax=-100000000000000,res=-100000000000000,pf[100010];
void brute(){
	long long sum;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i){
		sum=0;
		for(int j=i;j<=n;++j){
			sum+=a[j];
			res=(res>sum?res:sum);
		}
	}
	cout<<res;
	res=0;
}
void solve1(){
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
		pfmin=(pfmin<pf[i]?pfmin:pf[i]);
	}
	for(int i=1;i<=n;++i)
		res=(res>pf[i]-pfmin?res:pf[i]-pfmin);
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	brute();
	cout<<'\n';
	solve1();
	cout<<'\n';
}
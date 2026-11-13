#include<iostream>
using namespace std;
int n,x,res,a[100010];
long long sum,pf[100010];
void solve1(){
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum+=a[j];
			res+=(sum==x?1:0);
		}
	}
	cout<<res;
}
void solve2(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
}
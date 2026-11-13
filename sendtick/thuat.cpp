#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long k,delta,res;
void brute(){
	long long a[n+10]; a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]-k==a[i]) res++;
	cout<<res<<'\n';
	res=0;
}
void solve_bs(){
	long long a[n+10]; a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		delta=a[i]+k;
		auto first=lower_bound(a+1,a+n+1,delta);
		if(*first!=delta) continue;
		auto last=upper_bound(a+1,a+n+1,delta);
		res+=last-first;
	}
	cout<<res<<'\n';
	res=0;
}
void solve_tp_mine(){
	int l=1,r=2,cnt_first,cnt_delta;
	cnt_first=cnt_delta=1;
	long long a[n+10]; a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=n&&a[l]+k<=a[n]&&r<=n){
		if(a[r]==a[l]+k){
			while(a[r+1]==a[l]+k){
				cnt_delta++;
				r++;
			}
			while(a[l]==a[l+1]){
				cnt_first++;
				l++;
			}
			res+=cnt_first*cnt_delta;
			cnt_delta=cnt_first=1;
			l++;
		}
		while(a[l]<a[r]-k) l++;
		if(a[l]!=a[r]-k) r++;
	}
	cout<<res<<'\n';
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	//brute();
	//solve_bs();
	solve_tp_mine();
}
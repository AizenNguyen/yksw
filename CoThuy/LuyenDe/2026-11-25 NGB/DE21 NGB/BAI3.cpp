#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s,f,a[100005];
void brute(){
	int cnt;
	for(int i=1;i<=n;i++)
		if(s<=a[i]&&a[i]<=f)
			cnt++;
	cout<<cnt<<'\n';
}
void solve(){
	auto first=lower_bound(a+1,a+n+1,s);
	auto last=upper_bound(a+1,a+n+1,f);
	cout<<(last-a)-(first-a)<<'\n';
}
int main(){
	if(fopen("BAI3.INP","r")){
		freopen("BAI3.INP","r",stdin);
		freopen("BAI3.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s>>f;
		//brute();
		solve();
	}
}
#include<iostream>
#include<algorithm>     //solve_bs
#include<unordered_map> //solve_freq
using namespace std;
int n,q,x;
void solve_bs(){
	int a[n+10]={};
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cin>>q;
	while(q--){
		cin>>x;
		auto first=lower_bound(a+1,a+n+1,x);
		auto last=upper_bound(a+1,a+n+1,x);
		cout<<last-first<<'\n';
	}
}
void solve_freq(){
	unordered_map<int,int> freq;
	int a[n+10]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	cin>>q;
	while(q--){
		cin>>x;
		cout<<freq[x]<<'\n';
	}
}
int main(){
	if(fopen("lucky.inp","r")){
		freopen("lucky.inp","r",stdin);
		freopen("lucky.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve_bs();
	//solve_freq();
	cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n"; 
}
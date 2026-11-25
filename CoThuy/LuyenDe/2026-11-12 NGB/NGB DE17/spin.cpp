#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m,k,n,t,x;
long long cost;
void brute(){
	if(m-n<k){
		cout<<-1;
		return;
	}
	vector<bool> check(m+1);
	for(int i=1;i<=n;i++){
		cin>>x;
		check[x]=1;
	}
	for(int i=1;i<=m&&k!=0;i++)
		if(!check[i]){
			cost+=t+i;
			k--;
		}
	cout<<cost<<'\n';
	cost=0;
}
void solve(){
	if(m-n<k){
		cout<<-1;
		return;
	}
	long long x=k,sb=0;
	vector<int> b(n+1);
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b.begin()+1,b.end());
	for(int i=1;i<=n;i++){
		if(b[i]<=x){ 
			x++;
			sb+=b[i];
		}
		else break;
	}
	cout<<1LL*k*t+((x*(x+1))/2)-sb<<'\n';
}
int main(){
	if(fopen("spin.inp","r")){
		freopen("spin.inp","r",stdin);
		freopen("spin.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>k>>n>>t;
	solve();
}
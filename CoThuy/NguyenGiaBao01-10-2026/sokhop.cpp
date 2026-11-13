#include<iostream>
#include<unordered_map>
using namespace std;
int n,m,x,res,a[500010],b[500010];
unordered_map<int,int> ump;
void solve(){
	for(int i=1;i<=n;++i){
		cin>>x;
		ump[x]++;
	}
	for(int i=1;i<=m;++i){
		cin>>x;
		if(ump[x]>0)
			res++;
	}
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("sokhop.inp","r",stdin);
	freopen("sokhop.out","w",stdout);
	cin>>n>>m;
	solve();
}
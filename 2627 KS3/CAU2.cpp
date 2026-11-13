#include<iostream>
#include<unordered_map>
using namespace std;
short t;
int n,k,res;
void solve(){
	unordered_map<int,int> freq;
	while(t--){
		cin>>n>>k;
		res=0;
		int a[n+1]={};
		for(int i=1;i<=n;i++){
			cin>>a[i];
			freq[a[i]%k]++;
		}
		for(auto x:freq){
			//cout<<x.first<<" "<<x.second<<'\n';
			if(x.first==k-x.first||x.first==0) res+=x.second*(x.second-1)/2;
			else if(x.first!=k-x.first){
					res+=x.second*freq[(k-x.first)];
					freq[k-x.first]=0;
			}
		}
		cout<<res<<'\n';
		freq.clear();
	}
}
int main(){
	if(fopen("CAU2.INP","r")){
		freopen("CAU2.INP","r",stdin);
		freopen("CAU2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	solve();
	cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
}
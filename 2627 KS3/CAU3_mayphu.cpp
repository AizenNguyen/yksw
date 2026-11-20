#include<iostream>
#include<vector>
#include<map>
using namespace std;
short t;
int n,k,first,res;
// void brute(){
// 	while(t--){
// 		cin>>n>>k;
// 		for(int i=1;i<=n;i++) cin>>a[i];

// 	}
// }
void solve(){
	while(t--){
		cin>>n>>k;
		int a[n+1]={},l=1,r=1; res=first=1;
		map<int,int> cnt;
		for(int i=1;i<=n;i++) cin>>a[i];
		while(l<=n&&r<=n){
			//cout<<l<<" "<<r<<'\n';
			cnt[a[r]]++;
			if(cnt.size()>k&&r-l>res){
				res=r-l;
				first=l;
				l=r;
				cnt.clear();
			}
			r++;
		}
		if(cnt.size()<=k&&res<r-l){
			res=r-l;
			first=l;
		}
		cout<<res<<" "<<first<<'\n';
	}
}
int main(){
	if(fopen("CAU3.INP","r")){
		freopen("CAU3.INP","r",stdin);
		freopen("CAU3.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	solve();
}
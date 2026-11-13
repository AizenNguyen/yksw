#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n,m,l,r,MAX,res;
map<int,int> cnt;
int main(){
	if(fopen("BAI3.INP","r")){
		freopen("BAI3.INP","r",stdin);
		freopen("BAI3.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		if(l<=r)
			for(int j=l;j<=r;j++){
				cnt[j]++;
				MAX=max(MAX,cnt[j]);
			}
		else{
			for(int j=l;j<=n;j++){
				cnt[j]++;
				MAX=max(MAX,cnt[j]);
			}
			for(int j=1;j<=r;j++){
				cnt[j]++;
				MAX=max(MAX,cnt[j]);
			}
		}
	}
	for(auto x:cnt){
		if(x.second==MAX)
			res++;
	}
	cout<<MAX<<" "<<res<<'\n';
	MAX=res=0;
}
#include<iostream>
#include<unordered_map>
using namespace std;
short t;
int n,k,maxlen,pos;
void solve(){
	int l,numdif;
	unordered_map<int,int> freq;
	while(t--){
		cin>>n>>k;
		int a[n+1]={};
		numdif=0,l=maxlen=pos=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int r=1;r<=n;++r){
			freq[a[r]]++;
			if(freq[a[r]]==1) numdif++;
			while(numdif>k){
				freq[a[l]]--;
				if(freq[a[l]]==0) numdif--;
				l++;
			}
			if(r-l+1>maxlen){
				maxlen=r-l+1;
				pos=l;
			}
		}
		cout<<maxlen<<" "<<pos<<'\n';
		freq.clear();
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
	cerr<<"Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,x;
long double MAX=-1e18;
void solve(){
	int pos,asz;
	long long tmp;
	vector<int> a(1,0);
	map<int,int> freq;
	for(int i=1;i<=n;i++){
		cin>>x;
		auto it=freq.find(x);
		if(it==freq.end()){
			a.emplace_back(x);
			freq[x]++;
		}
	}
	asz=a.size();
	sort(a.begin()+1,a.end());
	for(int i=1;i<asz-1;i++){
		tmp=(1.0L*a[i])/a[i+1];
		if(tmp>MAX){
			MAX=tmp;
			pos=i;
		}
	}
	if(MAX==-1e18) cout<<-1;
	else cout<<a[pos]<<" "<<a[pos+1];
}
int main(){
	if(fopen("maxf.inp","r")){
		freopen("maxf.inp","r",stdin);
		freopen("maxf.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve();
}
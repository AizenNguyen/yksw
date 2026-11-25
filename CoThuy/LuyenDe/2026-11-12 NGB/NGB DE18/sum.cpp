#include<iostream>
#include<vector> //brute
#include<map> //solve
using namespace std;
int n;
long long cnt;
void brute(){
	long long s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(s==0) cnt++;
		}
	}
	cout<<cnt<<'\n';
	cnt=0;
}
void solve(){
	int x;
	long long pf=0,cnt=0;
	map<long long,int> freq; freq[0]++;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf+=x;
		freq[pf]++;
	}
	for(auto x:freq) cnt+=1LL*x.second*(x.second-1)/2;
	cout<<cnt<<'\n';
	cnt=0;
}
int main(){
	if(fopen("sum.inp","r")){
		freopen("sum.inp","r",stdin);
		freopen("sum.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//brute();
	solve();
}
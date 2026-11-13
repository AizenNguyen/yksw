#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
int n,k;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<int> b,asort;
	asort=a;
	sort(asort.begin(),asort.end());
	for(int i=1;i<=n-k+1;i++){
		b=a;
		sort(b.begin()+i,b.begin()+i+k);
		for(auto x:b)
			cout<<x<<" ";
		cout<<"pos "<<i<<" "<<i+k<<'\n';
		if(b==asort){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	cerr<<"Time elapsed: "<<TIME<<"s\n";
}
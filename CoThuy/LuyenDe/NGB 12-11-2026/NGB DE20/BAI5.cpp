#include<iostream>
#include<vector>
using namespace std;
const int MOD=1e9+7;
int n;
long long res;
void brute(){
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				res+=(a[i]*a[j]*a[k])%MOD;
	cout<<res%MOD;
}
void solve(){

}
int main(){
	if(fopen("BAI5.INP","r")){
		freopen("BAI5.INP","r",stdin);
		freopen("BAI5.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	brute();
	//solve();
}
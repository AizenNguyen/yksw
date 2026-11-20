#include<iostream>
using namespace std;
short t;
int n;
long long a,b,res;
void solve(){
	for(int i=1;i<=t;i++){
		cin>>a>>b>>n;
		res=0;
		while(a<=n&&b<=n){
			if(a<=b) a+=b;
			else if(b<a) b+=a;
			res++;
		}
		cout<<res<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("TANGDV.INP","r",stdin);
	freopen("TANGDV.OUT","w",stdout);
	cin>>t;
	solve();
}
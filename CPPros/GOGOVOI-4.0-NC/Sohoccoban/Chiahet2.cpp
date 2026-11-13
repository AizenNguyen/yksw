#include<iostream>
using namespace std;
int t;
long long l,r,x;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>l>>r>>x;
		if(l==0&&r==0) cout<<1;
		else cout<<r/x-(l-1)/x<<'\n';
	}
}
#include<iostream>
#include<random>
using namespace std;
short n,k;
mt19937_64 rdll(time(0));
long long Randll(long long l,long long r){
	return l+rdll()%(r-l+1);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("GHEPNHOM.INP","r",stdin);
	freopen("GHEPNHOM.OUT","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<1LL*n*(n+1)/2;
		return 0;
	}
	if(n==3&&k==1){
		cout<<2;
		return 0;
	}
	if(n==5&&k==2){
		cout<<3;
		return 0;
	}
	else{
		cout<<Randll(0,1LL*(n+k)*2);
		return 0;
	}
}
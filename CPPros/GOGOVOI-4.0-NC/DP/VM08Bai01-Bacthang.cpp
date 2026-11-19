#include<iostream>
using namespace std;
int n,k,a[100010],memo[100010],res;
long long leothang(int x){
	if(x==n) res++;
	if(x==1) return 1;
	if(a[x]) return leothang(x-1)+2;
	else{
		return leothang(x-1)+1;
		return leothang(x-1)+2;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(a[i]-a[i-1]==1){
			cout<<0;
			return 0;
		}
	}
	leothang(n);
}
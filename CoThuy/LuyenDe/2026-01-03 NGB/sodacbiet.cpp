#include<iostream>
using namespace std;
int l,r,last,res,cnt;
int suoc[3000010];
void solve(){
	for(int i=1;i*2<=r;i++)
		for(int j=i+i;j<=r;j+=i) suoc[j]+=i;
	for(int i=l;i<=r;i++)
		if(i<suoc[i]) res++;
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("sodacbiet.inp","r",stdin);
	freopen("sodacbiet.out","w",stdout);
	cin>>l>>r;
	solve();
}
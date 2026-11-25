#include<iostream>
#include<algorithm>
using namespace std;
int n,m,check,a[100010];
long long nm,starta,enda;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("trochoi.inp","r",stdin);
	freopen("trochoi.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;++i)
		cin>>a[i];
	sort(a+1,a+nm+1);
	for(int i=1;i<=n;++i){
		enda=i*m;
		starta=enda-m+1;
		if(i%2!=0)
			for(int j=starta;j<=enda;++j)
				cout<<a[j]<<" ";
		else
			for(int j=enda;j>=starta;--j)
				cout<<a[j]<<" ";
		cout<<'\n';
	}
}
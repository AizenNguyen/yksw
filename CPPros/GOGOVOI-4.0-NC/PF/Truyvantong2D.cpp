#include<iostream>
using namespace std;
short n,m,x1,y1,x2,y2;
int q,a[1003][1003];
long long pf[1003][1003];
void solve_pf(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+a[i][j];
		}
	cin>>q;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		cout<<pf[x2][y2]-(pf[x1-1][y2]+pf[x2][y1-1])+pf[x1-1][y1-1]<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	solve_pf();
}
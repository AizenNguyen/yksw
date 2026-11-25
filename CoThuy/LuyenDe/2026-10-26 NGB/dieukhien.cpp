#include<iostream>
#include<algorithm>
using namespace std;
int m,n,s,t,res;
void brute(){
	int a[m+1][n+1];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=s;i++){
		cin>>t;
		if(t<=m)
			for(int j=1;j<=n;j++){
				if(a[t][j]<=1) a[t][j]++;
				else a[t][j]=0;
			}
		else
			for(int i=1;i<=m;i++){
				if(a[i][t-m]<=1) a[i][t-m]++;
				else a[i][t-m]=0;
			}
	}
	for(int i=1;i<=m;i++)
		res+=count(a[i]+1,a[i]+n+1,0);
	cout<<res<<'\n';
	res=0;	
}
int main(){
	if(fopen("dieukhien.inp","r")){
		freopen("dieukhien.inp","r",stdin);
		freopen("dieukhien.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n>>s;
	brute();
}
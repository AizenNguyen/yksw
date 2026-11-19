#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
short n,m;
int maxpoint=0,mintime=1000000;
void brute(){
	short a[n+10][m+10];
	int point[n+10]={},pftime[n+10]={};
	vector<pair<int,short>> ldb;
	for(short i=1;i<=n;i++)
		for(short j=1;j<=m;j++){
			cin>>a[i][j];
			pftime[i]+=a[i][j];
			if(a[i][j]!=0){
				point[i]+=10;
				maxpoint=maxpoint>point[i]?maxpoint:point[i];
			}
		}
	for(int i=1;i<=n;i++)
		if(point[i]==maxpoint){
			mintime=mintime<pftime[i]?mintime:pftime[i];
			ldb.emplace_back(pftime[i],i);
		}
	sort(ldb.begin(),ldb.end());
	for(auto x:ldb)
		if(x.first==mintime)
			cout<<x.second<<" ";
}
int main(){
	if(fopen("team.inp","r")){
		freopen("team.inp","r",stdin);
		freopen("team.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	brute();
}
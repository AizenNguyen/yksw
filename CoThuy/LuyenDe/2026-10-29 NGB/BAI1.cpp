#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000006;
short n,x;
int sr[MAXN],sc[MAXN];
long long res;
void brute(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			res+=(sr[i]==sc[j]?1:0);
	cout<<res<<'\n';
	res=0;
}
void algo(){
	sort(sr+1,sr+n+1);
	for(int i=1;i<=n;i++){
		auto range=equal_range(sr+1,sr+n+1,sc[i]);
		res+=(range.second-range.first);
	}
	cout<<res<<'\n';
	res=0;
}
int main(){
	if(fopen("BAI1.INP","r")){
		freopen("BAI1.INP","r",stdin);
		freopen("BAI1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>x;
			sr[i]+=x;
			sc[j]+=x;
		}
	if(n<=1000) brute();
	else algo();
}
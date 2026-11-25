#include<iostream>
#include<unordered_map>
using namespace std;
bool check[500010];
short a[500010];
int n,sum,MAX=1;
unordered_map<short,int> firstpos;
void sub1and2(){
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum+=a[j];
			if(a[i]==a[j]) MAX=MAX>sum?MAX:sum;
		}
	}
	cout<<MAX;
	MAX=0;
}
void sub3(){
	int pf[500010]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
		if(!firstpos.emplace(a[i],i).second) continue;
	}
	for(int i=n;i>=1;i--){
		if(check[a[i]])
			continue;
		check[a[i]]=true;
		sum=pf[i]-pf[firstpos[a[i]]-1];
		MAX=MAX>sum?MAX:sum;
	}
	cout<<MAX;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("quantrong.inp","r",stdin);
	freopen("quantrong.out","w",stdout);
	cin>>n;
	if(n<=5000) sub1and2();
	else sub3();
}
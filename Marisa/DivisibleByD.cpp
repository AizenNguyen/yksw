#include<iostream>
#include<map>
using namespace std;
long long sum,res;
int n,d,a[100010],pf[100010];
map<int,int> cnt;
void trau(){
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i){
		sum=0;
		for(int j=i;j<=n;++j){
			sum+=a[j];
			if(sum%d==0){
				cout<<i<<" "<<j<<'\n';         
				res++;
			}
		}
	}
	cout<<res;
	res=0;
}
void solve1(){
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j)
			if((pf[j]-pf[i-1])%d==0)
				res++;
	}
	cout<<res;
	res=0;
}
void solve2(){
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
		cnt[pf[i]]++;
	}
	for(auto l=cnt.begin();l!=cnt.end();++l){
		cout<<l->first;
		for(auto r=next(l);r!=cnt.end();++r){

		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>d;
	trau();
	cout<<'\n';
	solve1();
}
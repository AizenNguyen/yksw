#include<iostream>
using namespace std;
long long n,res;
int m,a[1000006];
void sub12(){
	int pf[1000006]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(pf[j]-pf[i-1]<=m)
				res++;
	cout<<res<<'\n';
	res=0;
}
void sub3(){
	int l=1,r=1,pf=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int r=1;r<=n;r++){
		pf+=a[r];
		while(l<=r&&pf>m){
			pf-=a[l];
			l++;
		}
		res+=r-l+1;
	}
	cout<<res<<'\n';
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("daycon.inp","r",stdin);
	freopen("daycon.out","w",stdout);
	cin>>n>>m;
	//if(n<=1000) sub12();
	//else sub3();
	sub3();
}
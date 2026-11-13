#include<iostream>
using namespace std;
int n,m,a[1000006],pf[1000006];
long long res;
void sub1(){
	int s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(s>m) break;
			res++;
		}
	}
	cout<<res<<'\n';
	res=0;
}
void sub2(){
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
	int l=1,pf=0;
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
	cout<<res;
}
int main(){
	if(fopen("daycon.inp","r")){
		freopen("daycon.inp","r",stdin);
		freopen("daycon.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	if(n<=100) sub1();
	else if(n<=1000) sub2();
	else sub3();
}
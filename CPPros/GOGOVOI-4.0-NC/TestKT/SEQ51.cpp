#include<iostream>
using namespace std;
int n,l=1,r=1,cond=1,tmp,res,a[100010];
void sub1and2(){
	int cnt;
	for(int i=1;i<=n;i++){
		cnt=0;
		cond=1;
		for(int j=i;j<=n;j++){
			if(a[j]<cond){
				for(int k=i;k<=j-1;k++) cout<<k<<" ";
				cout<<'\n';
				break;
			}
			cnt++;
			cond++;
		}
		res=(res>cnt?res:cnt);
	}
	cout<<res;
	res=0;
}
void sub3(){
	while(l<=n){
		if(a[r]<cond){
			tmp=r-l+1;
			res=res>tmp?res:tmp;
			cond=1;
			l=r+1;
			continue;
		}
		if(r==n){
			tmp=r-l+1;
			res=res>tmp?res:tmp;
			break;
		}
		r++;
	}
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//if(n<=500)sub1and2();
	//else sub3();
	sub1and2();cout<<" SUB1";
	cout<<'\n';
	sub3();cout<<" SUB2";
}
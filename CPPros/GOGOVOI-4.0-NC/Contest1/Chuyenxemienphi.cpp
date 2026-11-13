#include<iostream>
#include<algorithm>
using namespace std;
int n,k,r,a[200010];
long long tmp,sum,res;
int phi(int x){
	if(x<=0) return 0;
	return (x+k-1)/k;
}
void brute(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=phi(a[i]);
	}
	res=sum;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(j==i){
				tmp=(a[j]<r?0:a[j]-r);	
				sum+=phi(tmp);
			}
			else sum+=phi(a[j]);
		}
		res=(res>sum)?sum:res;
	}
	cout<<res;
	res=0;
}
void sub1(){
	cin>>a[1];
	if(r>=a[1]){
		cout<<0;
		return;
	}
	a[1]-=r;
	res=(a[1]+k-1)/k;
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>r;
	if(n==1) sub1();
	else brute(); 
}
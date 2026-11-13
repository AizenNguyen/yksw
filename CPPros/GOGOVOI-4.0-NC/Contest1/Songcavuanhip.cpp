#include<iostream>
#include<algorithm>
using namespace std;
int n,tmp;
long long d,b,res,a[200010];
void brute(){
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(a[i]-a[j])<=d&&a[i]+a[j]<=b)
				res++;
	cout<<res;
	res=0;
}
void sub2(){
	int l=1,r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(l<r){
		if(a[l]+a[r]<=b){
			res+=(r-l);
			l++;
		}
		else r--;
	}
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>d>>b;
	// if(n<=2000){
	// 	brute();
	// 	return 0;
	// }
	if(d==1000000000){
		sub2();
		return 0;
	}
	else{
		brute();
		return 0;
	}
}
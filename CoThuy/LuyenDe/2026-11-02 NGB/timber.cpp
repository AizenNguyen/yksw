#include<iostream>
using namespace std;
long long n;
bool check(long long mid){
	return mid<=(2*n)/(mid+1);
	//return mid*(mid+1)/2<=n;
}
void sub1(){
	long long i=2,s=0;
	while(s<n){
		s+=i;
		i++;
	}
	cout<<i-2;
}
void sub2(){
	long long l=1,r=1414213561,mid,res=0;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<res;
	res=0;
}
int main(){
	if(fopen("timber.inp","r")){
		freopen("timber.inp","r",stdin);
		freopen("timber.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n<=1000000000000) sub1();
	else sub2();
}
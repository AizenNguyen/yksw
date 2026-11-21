#include<iostream>
using namespace std;
short t;
int n,l,r,d;
int bs(int ai){
	l=1,r=ai/3,d=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(ai-mid-mid*2>mid){
			l=mid+1;
			d=mid;
		}
		else r=mid-1;
	}
	return d;
}
int main(){
	if(fopen("BAI3.INP","r")){
		freopen("BAI3.INP","r",stdin);
		freopen("BAI3.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int a[n+1]; a[0]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=3;i<=4;i++){
			int d=bs(a[i]);
			a[i]=a[i]-d-d*2;
			a[i-1]=a[i-1]+d;
			a[i-2]=a[i-2]+d*2;
		}
	}
}
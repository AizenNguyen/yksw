#include<iostream>
#include<algorithm>
using namespace std;
short n,halfn;
int k,l,r,mid,sum,ans,an[200005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	halfn=n/2;
	for(short i=0;i<n;++i)
		cin>>an[i];
	sort(an,an+n);
	l=an[halfn],r=an[n-1]+k;
	while(l<=r){
		mid=(l+r)/2;
		sum=0;
		for(short i=halfn;i<n;++i)
			sum+=mid-an[i];
		cout<<mid<<" "<<sum<<'\n';
		if(k-sum==0||k-sum==1){
			cout<<mid;
			return 0;
		}
		else if(k-sum<-2)
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<ans;
}
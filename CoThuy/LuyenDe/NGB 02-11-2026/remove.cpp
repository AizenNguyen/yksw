#include<iostream>
#include<algorithm>
using namespace std;
int n,l,res=-1,a[2000006];
long long k,last,pf[2000006];
bool bs(long long pfl){
	int low=1,high=n,mid;
	long long x=pfl+k;
	while(low<=high){
		mid=(low+high)/2;
		if(pf[mid]==x) return true;
		else if(pf[mid]<x) low=mid+1;
		else if(x<pf[mid]) high=mid-1;
	}
	return false;
}
int main(){
	if(fopen("remove.inp","r")){
		freopen("remove.inp","r",stdin);
		freopen("remove.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
	while(l<=n){
		if(pf[l]+k>pf[n]) break;
		if(bs(pf[l])){
			auto it=upper_bound(pf+1,pf+n+1,pf[l]+k);
			res=max(res,((it-1)-pf)-l);
			last=pf[l];
			while(l<=n&&pf[l]==last) l++;
		}
		else l++;
	}
	if(res==-1) cout<<-1<<'\n';
	else cout<<n-res<<'\n';
	res=0;
}
#include<iostream>
#include<algorithm>
using namespace std;
short t,a[10010];
int n,p,k,pos;
long long s;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("MUAK.INP","r",stdin);
	freopen("MUAK.OUT","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>p>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if(p<a[1]){
			cout<<0<<'\n';
			continue;
		}
		auto r=lower_bound(a+1,a+n+1,p);
		pos=r-a;
		pos-=(p<a[pos]?1:0);
		//
		while(a[pos+1]==p)
			pos+=1;
		//
		if(k<=pos) cout<<k<<'\n';
		else if(k>pos){
			s=0;
			for(int i=1;;i++){
				if(s+a[i]>=p){
					pos=i;
					break;
				}
				s+=a[i];
			}
			cout<<pos<<'\n';
		}
	}
}
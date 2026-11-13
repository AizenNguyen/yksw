#include<iostream>
#include<algorithm>
using namespace std;
int n,k,m;
long long d,res=-1,a[200010];
void sub1(int i,int c,long long lastr,long long maxw){
	if(c==k){
		res=(res==-1?maxw:min(res,maxw));
		return;
	}
	if(i+(k-c)*m-1>n) return;
	sub1(i+1,c,lastr,maxw);
	if(c==0||a[i]-lastr>=d) sub1(i+m,c+1,a[i+m-1],max(maxw,a[i+m-1]-a[i]));

}
void sub2(){
	long long l=0,r=a[n]-a[1];
	while(l<=r){
		long long mid=(l+r)/2,cnt=0;
		for(int i=1;i+m-1<=n;){
			if(a[i+m-1]-a[i]<=mid){
				cnt++;
				i+=m;
			}
			else i++;
		}
		if(cnt>=k){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>m>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(d==0)sub2();
	else sub1(1,0,-1,0);
	cout<<res;
}
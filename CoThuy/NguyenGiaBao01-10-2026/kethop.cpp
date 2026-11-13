#include<iostream>
#include<algorithm>
using namespace std;
int x,y,z,n,a[1000010];
long long t,res=-1000000000000000000;
void sub1(){
	for(int i=1;i<=n-2;++i)
		for(int j=i+1;j<=n-1;++j)
			for(int k=j+1;k<=n;++k){
				t=x*a[i]+y*a[j]+z*a[k];
				res=(res>t?res:t);
			}
	cout<<res;
}
void sub2(){
	sort(a+1,a+n+1);
	res=(x>0?x*a[n-2]+y*a[n-1]+z*a[n]:x*a[1]+y*a[2]+z*a[3]);
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("kethop.inp","r",stdin);
	freopen("kethop.out","w",stdout);
	cin>>x>>y>>z>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(x==y&&y==z) sub2();
	else sub1();

}
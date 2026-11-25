#include<iostream>
#include<algorithm>
using namespace std;
int n,d,a[1000010];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("capsocong.inp","r",stdin);
	//freopen("capsocong.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	for(int i=3;i<=n;++i)
		if(a[i]-a[i-1]!=d){
			cout<<"no";
			return 0;
		}
	cout<<"yes"<<'\n';
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
}
#include<iostream>
using namespace std;
int n,res,a[100010],b[100010];
void sub1(){
	res=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=i&&a[j]>=a[i]&&b[j]>=b[i]){
				res--;
				break;
			}
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("THANHKIEM.INP","r",stdin);
	//freopen("THANHKIEM.OUT","w",stdout);
	cin>>n;
	//if(n<=1000)
		sub1();
}
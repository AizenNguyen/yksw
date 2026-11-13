#include<iostream>
using namespace std;
int n,Suoc[100000010];
long long cnt;
void sub2(){
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			cnt++;
	cout<<cnt;
}
void sub3(){
	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("capso.inp","r",stdin);
	//freopen("capso.out","w",stdout);
	cin>>n;
	if(n<=10000000)
		sub2();
	else
		sub3();

}
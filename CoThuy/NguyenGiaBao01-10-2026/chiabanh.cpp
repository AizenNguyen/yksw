#include<iostream>
using namespace std;
long long x,tmp=1,a[10000000];
void sub1(){
	for(long long i=1;i*i<=x;++i)
		if(x%i==0){
			cout<<i<<" "<<x/i<<'\n';
			if(x/i!=i){
				a[tmp]=x/i;
				tmp++;
			}
		}
	for(int i=tmp-1;i>=1;--i)
		cout<<a[i]<<" "<<x/a[i]<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("chiabanh.inp","r",stdin);
	freopen("chiabanh.out","w",stdout);
	cin>>x;
	sub1();
}
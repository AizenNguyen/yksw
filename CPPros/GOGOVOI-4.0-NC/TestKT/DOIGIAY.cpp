#include<iostream>
using namespace std;
int s,day,h,m;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("DOIGIAY.INP","r",stdin);
	freopen("DOIGIAY.OUT","w",stdout);
	cin>>s;
	day=s/86400;
	s-=day*86400;
	h=s/3600;
	s-=h*3600;
	m=s/60;
	s-=m*60;
	cout<<day<<'\n'<<h<<'\n'<<m<<'\n'<<s;
}
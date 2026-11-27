#include<iostream>
using namespace std;
bool check=false;
long long u1,d,x,pos;
int main(){
	if(fopen("aripog.inp","r")){
		freopen("aripog.inp","r",stdin);
		freopen("aripog.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>u1>>d>>x;
	pos=(x-u1)/d+1;
	if(u1+d*((pos-1)-1)==x) check=true;
	else if(u1+d*(pos-1)==x) check=true;
	else if(u1+d*((pos+1)-1)==x) check=true;
	if(check==true) cout<<pos;
	else cout<<-1;
}
#include<iostream>
using namespace std;
long long a,cost;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a;
	if(a<=5) cost=a*8000;
	else if(a>=6&&a<=10) cost=40000+(a-5)*10000;
	else if(a>=11&&a<=15) cost=90000+(a-10)*14000;
	else if(a>=16&&a<=20) cost=160000+(a-15)*20000;
	else if(a>=21) cost=260000+(a-20)*30000;
	cout<<cost+(cost/100*10)<<'\n';
	cost=0;
}
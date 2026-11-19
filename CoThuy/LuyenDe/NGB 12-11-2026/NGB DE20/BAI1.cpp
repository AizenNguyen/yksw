#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
long double a,alpha,h;
int main(){
	if(fopen("BAI1.INP","r")){
		freopen("BAI1.INP","r",stdin);
		freopen("BAI1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>alpha>>h;
	cout<<fixed<<setprecision(3)<<tan((alpha*acos(-1))/180)*a+h;
}
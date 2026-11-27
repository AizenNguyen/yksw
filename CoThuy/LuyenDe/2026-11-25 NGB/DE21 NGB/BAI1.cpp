#include<iostream>
using namespace std;
long long a,b,c;
int main(){
	if(fopen("BAI1.INP","r")){
		freopen("BAI1.INP","r",stdin);
		freopen("BAI1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c;
	cout<<(a*b)-(a*c)-(b*c)+(c*c);
}
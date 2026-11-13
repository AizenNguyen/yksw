#include<iostream>
using namespace std;
short a,b,c,x,y,z;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b>>c>>x>>y>>z;
	if(c==z){
		if(b==y){
			cout<<(a<b?1:2);
			return 0;
		}
		cout<<(b<y?1:2);
		return 0;
	}
	cout<<(c<z?1:2);
}
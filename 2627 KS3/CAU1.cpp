#include<iostream>
using namespace std;
short t,d,m,y;
int k;
int main(){
	if(fopen("CAU1.INP","r")){
		freopen("CAU1.INP","r",stdin);
		freopen("CAU1.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>d>>m>>y>>k;
	}
}
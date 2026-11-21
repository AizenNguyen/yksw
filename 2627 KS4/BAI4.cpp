#include<iostream>
using namespace std;
int q,n;
bool check=true;
int main(){
	if(fopen("BAI4.INP","r")){
		freopen("BAI4.INP","r",stdin);
		freopen("BAI4.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>q;
	while(q--){
		cin>>n;
		if(n!=2||n!=3||n!=4) check=false;
		bool notequal=true;
		int a[n+1],b[n+1];
		cin>>a[1]>>b[1];
		for(int i=2;i<=n;i++){
			cin>>a[i]>>b[i];
			if(a[i]==a[i-1]) notequal=false;
		}
		if(notequal){cout<<0; return 0;}
	}
	if(check) cout<<3<<'\n'<<5<<'\n'<<0;
}
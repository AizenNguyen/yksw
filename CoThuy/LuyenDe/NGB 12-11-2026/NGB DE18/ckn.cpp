#include<iostream>
using namespace std;
short n,m;
int main(){
	if(fopen("ckn.inp","r")){
		freopen("ckn.inp","r",stdin);
		freopen("ckn.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
}
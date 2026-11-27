#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
short n;
int x,s;
char alpha[]={'A','B','C','D','E','F','G','H','I'};
void solve(){
	while(n--){
		cin>>x;
		s=0;
		for(int i=2;i<=8;i++){
			s+=(x%10)*i;
			x/=10;
		}
		cout<<alpha[s%9]<<'\n';
	}
}
int main(){
	if(fopen("thenv.inp","r")){
		freopen("thenv.inp","r",stdin);
		freopen("thenv.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	solve();
}
#include<iostream>
using namespace std;
short k,b[100005];
int n,a[100005];
int main(){
	if(fopen("BAI4.INP","r")){
		freopen("BAI4.INP","r",stdin);
		freopen("BAI4.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
}
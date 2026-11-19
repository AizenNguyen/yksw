#include<iostream>
#include<vector>
using namespace std;
short n;
int main(){
	if(fopen("dsdb.inp","r")){
		freopen("dsdb.inp","r",stdin);
		freopen("dsdb.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
}
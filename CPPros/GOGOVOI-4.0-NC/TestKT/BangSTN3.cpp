#include<iostream>
using namespace std;
short n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<i*2;j++)
			cout<<j<<" ";
		cout<<'\n';
	}
}
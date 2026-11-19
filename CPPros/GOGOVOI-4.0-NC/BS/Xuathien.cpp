#include<iostream>
using namespace std;
int n,x,c,res;
void brute(){
	for(int i=1;i<=n;i++){
		cin>>c;
		res+=(c==x)?1:0;
	}
	cout<<res;
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x;
	brute(); cout<<'\n';
}
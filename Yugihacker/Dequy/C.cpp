#include<iostream>
using namespace std;
bool used[11];
short n,xau[11];
void sinh(){
	for(short i=1;i<=n;++i)
		cout<<xau[i];
	cout<<'\n';
}
void back(short pos){
	for(short i=1;i<=n;++i){
		if(used[i])
			continue;
		xau[pos]=i;
		used[i]=1;
		if(pos==n)
			sinh();
		else
			back(pos+1);
		used[i]=0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	back(1);
}
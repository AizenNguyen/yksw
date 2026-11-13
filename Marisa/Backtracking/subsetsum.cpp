#include<iostream>
using namespace std;
bool check;
short n;
long long k,a[1000010];
bool Try(short pos,long long k){
	if(k==0)
		return true;
	if(pos==n)
		return false;
	if(Try(pos+1,k))
		return true;
	if(a[pos]<=k)
		if(Try(pos+1,k-a[pos]))
			return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(short i=1;i<=n;++i)
		cin>>a[i];
	if(Try(1,k))
		cout<<"YES";
	else
		cout<<"NO";
}
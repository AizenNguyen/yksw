#include<iostream>
using namespace std;
short n,s,cnt=0,sum=0,an[21];
void back(short start){
	for(short i=1;i<=n;++i){
		sum+=an[i];
		if(sum>s)
			sum-=an[i];
		else if(sum<s){
			sum+=an[i];
			back(start+1);
		}
		else{
			cnt++;
			return;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	short an[n];
	cout<<cnt;
	for(short i=1;i<=n;++i)
		cin>>an[i];
	back(1);
	cout<<cnt;
}

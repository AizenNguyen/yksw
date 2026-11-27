#include<iostream>
#include<cmath>
using namespace std;
long long n,s,tmp,sum;
void brute(){
	long long l=pow(10,n-1),r=pow(10,n)-1;
	for(int i=r;i>=l;i--){
		tmp=i;
		sum=0;
		while(tmp){
			sum+=tmp%10;
			tmp/=10;
		}
		if(sum==s){
			cout<<i;
			return;
		}
	}
	cout<<-1;
}
void solve(){
	
}
int main(){
	if(fopen("PASSWORD.INP","r")){
		freopen("PASSWORD.INP","r",stdin);
		freopen("PASSWORD.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	//brute();
	solve();
}
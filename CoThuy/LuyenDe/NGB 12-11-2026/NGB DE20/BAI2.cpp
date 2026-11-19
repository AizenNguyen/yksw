#include<iostream>
using namespace std;
int n,cnt;
long long score;
string s;
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt=0;
			while(s[i+1]==0) i++;
		}
		else{
			cnt++;
			score+=cnt;
		}
	}
	cout<<score;
}
#include<iostream>
using namespace std;
int n,k,cnt;
long long res;
char c;
string s=" ",tmp;
void sub1(){
	cnt=0;
	for(int i=1;i<=n;i++){
		tmp="";
		cnt=0;
		for(int j=i;j<=n;j++){
			tmp+=s[j];
			cnt+=(s[j]=='a'?1:0);
			if(cnt==k){
				res++;
				if(s[j+1]=='a') break;
			}
		}
	}
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("DOANTH.INP","r",stdin);
	freopen("DOANTH.OUT","w",stdout);
	cin>>n>>k;
	while(cin>>c){
		cnt+=(c=='a'?1:0);
		s+=c;
	}
	if(cnt<k){
		cout<<0;
		return 0;
	}
	//if(n<=1000) sub1();
	//else sub2();
	sub1();
}
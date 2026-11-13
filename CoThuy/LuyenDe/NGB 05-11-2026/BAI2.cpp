#include<iostream>
using namespace std;
short d;
int cnt[10];
long long sum;
char c;
void solve(){
	while(cin>>c){
		d=c-'0';
		sum+=d;
		cnt[d]++;
	}
	if(cnt[0]==0||sum%3!=0) cout<<-1;
	else if(sum==0) cout<<0;
	else if(sum%3==0&&cnt[0]>0)
		for(int i=9;i>=0;i--)
			while(cnt[i]){
				cout<<i;
				cnt[i]--;
			}
}
int main(){
	if(fopen("BAI2.INP","r")){
		freopen("BAI2.INP","r",stdin);
		freopen("BAI2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	solve();
}
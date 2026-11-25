#include<iostream>
using namespace std;
int n,pos=1,cnt[1000010];
bool xu,xu_pre,bl[1000010];
void sub1(){
	cin>>xu;
	bl[pos]=xu;
	cnt[pos]++;
	xu_pre=xu;
	for(int i=2;i<=n;++i){
		cin>>xu;
		if(xu!=xu_pre){
			pos++;
			bl[pos]=xu;
		}
		cnt[pos]++;
		xu_pre=xu;
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("latxu.inp","r",stdin);
	//freopen("latxu.out","w",stdout);
	cin>>n;
		sub1();
}
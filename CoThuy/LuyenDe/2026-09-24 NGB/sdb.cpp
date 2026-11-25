#include<iostream>
using namespace std;
int t,a,b,cnt,res,uoc[1000010],pf[1000010];
bool check[1000010];
int cntuoc(int x){
	cnt=0;
	for(int i=1;i*i<=x;++i)
		if(x%i==0)
			cnt+=(x/i!=i?2:1);
	return cnt;
}
void sanguoc(){
	for(int i=1;i<=1000010;++i)
		for(int j=i;j<=1000010;j+=i)
			uoc[j]++;
}
void sub1(){
	cin>>a>>b;
	for(int i=a;i<=b;++i)
		if(i%3==0&&cntuoc(i)==9)
			res++;
	cout<<res;
}
void sub2(){
	for(int i=1;i<=t;++i){
		cin>>a>>b;
		res=0;
		for(int j=a;j<=b;++j)
			if(j%3==0&&cntuoc(j)==9)
				res++;
		cout<<res<<'\n';
	}
}
void sub3(){
	sanguoc();
	for(int i=3;i<=1000010;i+=3)
		check[i]=1;
	for(int i=1;i<=t;++i){
		cin>>a>>b;
		res=0;
		while(a%3!=0) a++;
		for(int j=a;j<=b;j+=3)
			if(uoc[j]==9&&j%3==0)
				res++;
		cout<<res<<'\n';
	}
}
void sub4(){
	sanguoc();
	for(int i=1;i<=1000005;++i){
		pf[i]=pf[i-1];
		if(uoc[i]==9&&i%3==0)
			pf[i]++;
	}
	for(int i=1;i<=t;++i){
		cin>>a>>b;
		cout<<pf[b]-pf[a-1]<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("sdb.inp","r",stdin);
	freopen("sdb.out","w",stdout);
	cin>>t;
	//if(t==1) sub1();
	//sub2();
	//sub3();
	sub4();
}
#include<iostream>
using namespace std;
long long a,b,c,cnt,res;
void sub1(){
	for(int i=a;i<=b;i++)
	if(i%c!=0)
		res++;
	cout<<res;
	res=0;
}
void sub1plus(){
	res=b-a+1;
	while(a%c!=0) a++;
	for(long long i=a;i<=b;i+=c) cnt++;
	cout<<res-cnt;
	res=0;
}
void sub2(){
	//cout<<((a%c!=0)?(b-a+1)-(b/c-a/c):(b-a+1)-(b/c-a/c+1));
	cout<<(b-a+1)-(b/c-(a+1)/c);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("demso.inp","r",stdin);
	freopen("demso.out","w",stdout);
	cin>>a>>b>>c;
    if(c==1){
    	cout<<b-a+1;
    	return 0;
    }
    if(b<c){
    	cout<<0;
    	return 0;
    }
    if(b==c){
    	cout<<1;
    	return 0;
    }
    if(a<=1000000&&b<=1000000&&c<=1000000){
    	sub1();
    	return 0;
    }
    else{
    	sub2();
    	return 0;
    }
}
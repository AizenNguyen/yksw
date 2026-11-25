#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=10000007;
int tmp,tmpn;
long long a,b,res;
bool prime[MAXN+10];
bool check(int n) {
    int rev=0,tmp=n;
    while(tmp){
        rev=rev*10+tmp%10;
        tmp/=10;
    }
    return rev==n;
}
void sub1(){
	int sqrti;
	prime[0]=prime[1]=1;
	for(int i=4;i<=MAXN;i+=2)
		prime[i]=1;
	for(int i=3;i*i<=MAXN;i+=2)
		if(!prime[i])
			for(int j=i*i;j<=MAXN;j+=i)
				prime[j]=1;
	for(int i=a;i<=b;i++){
		sqrti=sqrt(i);
		if(sqrti*sqrti==i)
			if(!prime[sqrti])
				if(check(sqrti))
					res++;
	}
	cout<<res<<'\n';
	res=0;
}
void sub2(){
	long long sqrta;
	prime[0]=prime[1]=1;
	for(int i=3;i*i<=MAXN;i+=2)
		if(!prime[i])
			for(int j=i*i;j<=MAXN;j+=i)
				prime[j]=1;
	sqrta=sqrt(a);
	if(sqrta*sqrta<a) sqrta++;
	if(sqrta<=2){
		if(4<=b&&check(2)) res++;
		sqrta=3;
	}
	else if(sqrta%2==0) sqrta++;
	for(long long i=sqrta;i*i<=b;i+=2)
		if(!prime[i])
			if(check(i))
				res++;
	cout<<res<<'\n';
	res=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("SOCPDEP.INP","r",stdin);
	freopen("SOCPDEP.OUT","w",stdout);
	cin>>a>>b;
	if(b<=1000) sub1();
	else sub2();
}
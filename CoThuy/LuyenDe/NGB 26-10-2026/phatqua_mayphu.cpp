#include<iostream>
#include<algorithm>
using namespace std;
int a,b,res;
void sub1(){
    for(int i=1;i<=a;i++)
        if(a%i==0&&b%i==0)
            res++;
    cout<<res<<'\n';
    res=0;
}
void sub2(){
	int ucln=__gcd(a,b);
	for(int i=1;i*i<=ucln;i++)
		if(ucln%i==0){
			res++;
			if(ucln/i!=i)
				res++;
		}
	cout<<res<<'\n';
	res=0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("phatqua.inp","r",stdin);
    freopen("phatqua.out","w",stdout);
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(b<=100000) sub1();
    else sub2();
}
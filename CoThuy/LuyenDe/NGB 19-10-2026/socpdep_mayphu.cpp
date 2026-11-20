#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=10000000;
int sqrta,sqrti,tmp,tmpn;
long long a,b,res;
bool prime[MAXN+10];
bool check(int n){
    tmp=0,tmpn=n;
    while(tmpn){
        tmp*=10;
        tmp+=tmpn%10;
        tmpn/=10;
    }
    if(tmp==n) return true;
    return false;
}
void sub1(){
    prime[0]=prime[1]=1;
    for(int i=4;i<=10000000;i+=2)
        prime[i]=1;
    for(int i=3;i*i<=MAXN;i+=2)
        if(!prime[i])
            for(int j=i*i;j<=MAXN;j+=i)
                prime[j]=1;
    for(int i=a;i<=b;i++){
        sqrti=sqrt(i);
        // if(sqrti*sqrti==i)
        //  if(prime[sqrti]==0)
        //      if(check(sqrti))
        //          res++;
        if(sqrti*sqrti==i&&prime[sqrti]==0&&check(sqrti)==true)
            res++;
    }
    cout<<res;
}
void sub2(){
    prime[0]=prime[1]=1;
    // for(int i=4;i<=10000000;i+=2)
    //  prime[i]=1;
    for(int i=3;i*i<=MAXN;i+=2)
        if(!prime[i])
            for(int j=i*i;j<=MAXN;j+=i)
                prime[j]=1;
    if(a==4&&b>=4)
        res++;
    sqrta=sqrt(a);
    if(sqrta*sqrta!=a)
        sqrta++;
    if(sqrta%2==0)
        sqrta++;
    for(int i=sqrta;i*i<=b;i+=2){
        if(prime[i]==0&&check(i)==true){
            res++;
            //cout<<i<<" "<<i*i<<'\n';
        }
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("SOCPDEP.INP","r",stdin);
    //freopen("SOCPDEP.OUT","w",stdout);
    cin>>a>>b;
    sub2();
    // if(b<=1000) sub1();
    // else if(b>1000) sub2();
}
#include<iostream>
#include<algorithm>
using namespace std;
long long x,tmp,gcd,a=1,b;
long long ucln(long long a,long long b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>x;
    b=x;
    for(int i=1;i*i<=x;++i){
        if(x%i==0){
            tmp=x/i;
            if(ucln(i*1ll,tmp)==1){
                if(tmp<b){
                    a=i;
                    b=tmp;
                }
            }
        }
    }
    cout<<a<<" "<<b;
}

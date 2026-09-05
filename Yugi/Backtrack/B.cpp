#include<iostream>
using namespace std;
short n,xau[14];
void sinh(){
    for(short i=1;i<=n;++i)
        cout<<xau[i];
    cout<<'\n';
}
void back(short pos){
    for(short i=0;i<=2;++i){
        xau[pos]=i;
        if(pos==n)
            sinh();
        else
            back(pos+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    back(1);
}
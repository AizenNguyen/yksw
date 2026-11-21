#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a[3];
    for(int i=0;i<3;i++) cin>>a[i];
    int b=a;
    for(auto x:b) cout<<x<<" ";
}
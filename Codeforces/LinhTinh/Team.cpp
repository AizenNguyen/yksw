#include<iostream>
using namespace std;
short n,x,y,z,cnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        cin>>x>>y>>z;
        if(x+y+z>=2)
            cnt++;
    }
    cout<<cnt;
}

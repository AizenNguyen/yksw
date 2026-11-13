#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
mt19937_64 rdll(time(0));
int Rand(int l,int r){
    return l+rd()%(r-l+1);
}
long long Randll(long long l,long long r){
    return l+rdll()%(r-l+1);
}
void sinh(){
    ofstream cout("sinh.inp");
    int n=Rand(1,15); cout<<n<<" ";
    int k=Rand(3,7); cout<<k<<'\n';
    for(int i=1;i<=n;i++){
        int ai=(Rand(3,20));
        cout<<ai<<" ";
    }
}
int main(){
    for(int i=1;i<=100;++i){
        sinh();
        system("thuat.exe < sinh.inp > sinh.out");
        system("trau.exe < sinh.inp > sinh.ans");
        if(system("fc sinh.out sinh.ans > nul")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }
}

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
    int n=Rand(50,100);
    for(int i=1;i<=n;i++){
        int xi=Rand(1,10);
        if(xi==1)
    }
    cout<<'\n'<<0;
}
int main(){
    for(int i=1;i<=150;++i){
        sinh();
        system("trau.exe < sinh.inp > sinh.ans");
        system("thuat.exe < sinh.inp > sinh.out");
        if(system("fc sinh.out sinh.ans > nul")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }
}

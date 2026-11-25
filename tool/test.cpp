#include<bits/stdc++.h>
using namespace std;
mt19937_64 rd(time(0));
long long Rand(long long l,long long r){
    if(l>r) swap(l,r);
    return uniform_int_distribution<long long>(l,r)(rd);
}
void sinh(){
    ofstream cout("sinh.inp");
    int n=Rand(2,15);
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        int xi=Rand(-5,5);
        cout<<xi<<" ";
    }
    cout<<'\n';
}
int main(){
    for(int t=1;t<=1000;++t){
        sinh();
        system("trau.exe < sinh.inp > sinh.ans");
        system("thuat.exe < sinh.inp > sinh.out");
        if(system("fc sinh.out sinh.ans > nul")){
            cout<<"[-] TEST "<<t<<" WRONG!\n";
            return 0;
        }
        if(t%100==0) cout<<"Passed "<<t<<" test...\n";
    }
    cout<<"\n=> ALL TESTS PASSED\n";
}
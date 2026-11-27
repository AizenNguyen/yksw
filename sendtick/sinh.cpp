#include<bits/stdc++.h>
using namespace std;
mt19937_64 rd(time(0));
long long Rand(long long l,long long r){
    if(l>r) swap(l,r);
    return uniform_int_distribution<long long>(l,r)(rd);
}
void sinh(){
    ofstream cout("sinh.inp");
    int n=Rand(3,5);
    int k=Rand(2,2);
    cout<<n<<" "<<k<<'\n';
    for(int i=1;i<=n;i++){
        int xi=Rand(-3,3);
        cout<<xi<<" ";
    }
}
int main(){
    int t;
    for(t=1;t<=200;++t){
        sinh();
        system("trau.exe < sinh.inp > sinh.ans");
        system("thuat.exe < sinh.inp > sinh.out");
        if(system("fc sinh.out sinh.ans > nul")){
            cout<<"[-] TEST "<<t<<" WRONG!\n";
            return 0;
        }
        if(t%100==0) cout<<"Passed "<<t<<" tests...\n";
    }
    cout<<"\n=> ALL TESTS PASSED! ("<<t<<" TESTS)";
}
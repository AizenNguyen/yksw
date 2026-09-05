#include<iostream>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("chuhoa.inp","r",stdin);
    //freopen("chuhoa.out","w",stdout);
    getline(cin,s);
    for(char &c:s)
        c=toupper(c);
    cout<<s;
}

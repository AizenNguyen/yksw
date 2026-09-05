#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("chuhoa.cpp","r",stdin);
    freopen("chuhoa.cpp","w",stdout);
    getline(cin,s);
    for(char &c:s)
        c=toupper(c);
    cout<<s;
}

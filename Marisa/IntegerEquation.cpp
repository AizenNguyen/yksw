#include<iostream>
using namespace std;
short a,b,check;
int main(){
	cin>>a>>b;
	if(a==0) cout<<(b==0?"INFINITE SOLUTIONS":"NO SOLUTION");
	else if(b%a!=0) cout<<"NO SOLUTION";
	else cout<<-b/a;
}
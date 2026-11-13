#include<iostream>
using namespace std;
short st,en,used,tmp;
void sub1(){
	cout<<(used<=4?used*6:(used-4)*3+4*6);
}
void sub2(){
	cout<<(used<=4?used*10:(used-4)*5+4*10);
}
void sub3(){
	if(used<=4)
		cout<<(12-st)*6+(en-12)*10;
	else{
		tmp=12-st;
		if(tmp==4)
			cout<<(tmp)*6+(en-12)*5;
		else if(tmp<4)
			cout<<(tmp)*6+(4-(tmp))*10+(en-st-(4-(tmp))*5);
		else if(tmp>4)
			cout<<24+(tmp-4)*3+(en-12)*5;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("khuvuichoi.inp","r",stdin);
	freopen("khuvuichoi.out","w",stdout);
	cin>>st>>en;
	used=en-st;
	if(en<=12) sub1();
	else if(st>=12) sub2();
	else sub3();
}
#include<iostream>
using namespace std;
long long n;
string s,pre="",MAX="";
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("BAI03.INP","r",stdin);
	//freopen("BAI03.OUT","w",stdout);
	cin>>n;
	while(cin>>s){
		if(s.size()>MAX.size()){
			pre=MAX;
			MAX=s;
		}
		if(s>MAX){
			pre=MAX;
			MAX=s;
		}
		if(s>pre&&s!=MAX)
			pre=s;
	}
	cout<<pre;
}
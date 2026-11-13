#include<iostream>
using namespace std;
short ssz,id,lastsize=1;
string s,tmp,res;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("BAI02.INP","r",stdin);
	//freopen("BAI02.OUT","w",stdout);
	cin>>s;
	s=" "+s;
	ssz=s.size();
	for(short i=1;i<=ssz;i++){
		bool used[52]={};
		tmp="";
		for(short j=i;j<=ssz;j++){
			id=('a'<=s[j]&&s[j]<='z')?s[j]-'a':s[j]-'A'+26;
			if(used[id]){
				if(lastsize<tmp.size()){
					res=tmp;
					lastsize=tmp.size();
				}
				break;
			}
			used[id]=true;
			tmp+=s[j];
		}
	}
	cout<<res;
}
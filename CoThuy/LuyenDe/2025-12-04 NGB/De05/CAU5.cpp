#include<iostream>
#include<unordered_set>
#include<time.h>
using namespace std;
short n;
string s,t;
void solve1(){
	for(short len=1;len<=n;++len){
		unordered_set<string> st;
		st.reserve(n);
		for(short i=0;i+len<=n;++i)
			st.insert(s.substr(i,len));
		if(st.size()==n-len+1){
			cout<<len;
			return;
		}
	}
}
int main(){
	//freopen("CAU5.INP","r",stdin);
	//freopen("CAU5.OUT","w",stdout);
	cin>>n>>s;
	solve1();
	cerr<<"\nTime elapsed: "<<(1.0 * clock() / CLOCKS_PER_SEC)<<"s\n";
}
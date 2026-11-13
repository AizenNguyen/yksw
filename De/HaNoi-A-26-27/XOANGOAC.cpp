#include<iostream>
using namespace std;
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
int n,check;
long long res;
string s,tmp;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("XOANGOAC.INP","r",stdin);
	//freopen("XOANGOAC.OUT","w",stdout);
	cin>>n>>s;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++){
			tmp=s;
			tmp.erase(l-1,r-1);
			check=0;
			for(auto c:tmp)
				check+=(c=='('?-1:1);
			if(check==0)
				res++;
		}
	cout<<res;
	cerr<<"time elapsed :"<<TIME<<"s\n";
}
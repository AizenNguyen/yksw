#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
int n,a[60];
long long res;
char c;
string s,t;
map<string,int> mp;
void brute(){
	while(cin>>c){
		s+=c;
		a[(c-'0')-16]++;
	}
	if(a[(c-'0')-16]==n){
		cout<<n*(n-1)/2;
		return;
	}
	for(int i=0;i<n;i++){
		t=s;
		mp[t.erase(i,1)]++;
	}
	for(auto x:mp) res+=x.second*(x.second-1)/2;
	cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("COSMIC.INP","r",stdin);
	freopen("COSMIC.OUT","w",stdout);
	cin>>n;
	//cin>>s;
	brute();
}
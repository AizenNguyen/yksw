#include<iostream>
#include<unordered_map>
using namespace std;
long long sum,res;
int ssz;
string s;
unordered_map <int,int> cnt;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	cnt[0]=1;
	for(int i=1;i<=s.size();++i){
		if(s[i]=='0') sum--;
		else sum++;
		res+=cnt[sum];
		cnt[sum]++;
	}
	cout<<res;
}
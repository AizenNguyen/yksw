#include<iostream>
#include<vector>
using namespace std;
int n,cnt=0;
vector<int> a;
void Try(int x){
	if(x==0) return;
	if(x==1){
		a.emplace_back(cnt);
		return;
	}
	if(x&1) a.emplace_back(cnt);
	cnt++;
	Try(x/2);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	Try(n);
	for(auto x:a) cout<<x<<" ";
}
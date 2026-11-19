#include<iostream>
#include<vector>
using namespace std;
short n;
long long a,b;
vector<pair<long long,long long>> ps;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(b==0)
			continue;
		
		ps.emplace_back(a,b);
	}
}
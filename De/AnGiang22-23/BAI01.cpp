#include<iostream>
#include<vector>
#include<set>
using namespace std;
int m,n,last;
bool dssnt[1000010];
vector<int> snt(1,2);
vector<pair<int,int>> res;
set<int> sti;
void ssnt(){
	dssnt[0]=dssnt[1]=1;
	for(int i=3;i*i<=1000001;i+=2)
		if(!dssnt[i]){
			snt.emplace_back(i);
			last=i;
			for(int j=i*i;j<=1000001;j+=i)
				dssnt[j]=1;
		}
	for(int i=last+2;i<=1000001;i+=2)
		if(!dssnt[i])
			snt.emplace_back(i);
}
set<int> tsnt(int x){
	set<int> st;
	for(int i:snt){
		if(x%i==0){
			st.insert(i);
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1) st.insert(x);
	return st;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("BAI01.INP","r",stdin);
	//freopen("BAI01.OUT","w",stdout);
	cin>>m>>n;
	ssnt();
	for(int i=m;i<=n-2;i++){
		sti=tsnt(i);
		for(int j=i+2;j<=n;j+=2)
			if(sti==tsnt(j))
				res.push_back({i,j});
	}
	cout<<res.size()<<'\n';
	for(auto i:res)
		cout<<i.first<<" "<<i.second<<'\n';
}
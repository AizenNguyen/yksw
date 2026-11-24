#include<iostream>
#include<map>
using namespace std;
bool x;
int n,len,maxlen,pf;
int firstpos[200020];
void solve_pf_map(){
	map<int,int> freq; freq[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf+=x==0?-1:1;
		auto it=freq.find(pf);
		if(it!=freq.end()){
			len=i-it->second;
			maxlen=maxlen>len?maxlen:len;
		}
		else freq[pf]=i;
	}
	cout<<maxlen<<'\n';
}
void solve_pf_arr(){
	int index;
	fill(firstpos,firstpos+200011,-2);
	firstpos[100005]=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		pf+=x==0?-1:1;
		index=pf+100005;
		if(firstpos[index]!=-2){
			len=i-firstpos[index];
			maxlen=maxlen>len?maxlen:len;
		}
		else firstpos[index]=i;
	}
	cout<<maxlen<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	//solve_pf_map();
	solve_pf_arr();
}
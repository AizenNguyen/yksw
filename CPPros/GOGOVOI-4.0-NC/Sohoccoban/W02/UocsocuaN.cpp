#include<iostream>
#include<set>
using namespace std;
int n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	set<int> st;
	for(int i=1;i*i<=n;i++)
		if(n%i==0){
			st.insert(i);
			if(n/i!=i)
				st.insert(n/i);
		}
	for(auto x:st) cout<<x<<" ";
}
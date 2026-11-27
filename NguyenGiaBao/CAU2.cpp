#include<bits/stdc++.h>
using namespace std;
int t,l,r,cnt;
short doc[1000006]; //1 ko doc 2 doc
bool check(int n){
	int d,doc_cnt=0,pre_d=n%10; n/=10;
	short pre_cond=0,cond=0; //1 giam 2 tang
	
	return true;
}
int main(){
	if(fopen("CAU2.INP","r")){
		freopen("CAU2.INP","r",stdin);
		freopen("CAU2.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(int i=0;i<=9;i++)
		doc[i]=2;
	while(t--){
		cin>>l>>r;
		cnt=0;
		for(int i=l;i<=r;i++){
			if(doc[i]==2) cnt++;
			else if(doc[i]==0){
				if(check(i)){
					doc[i]=2;
					cnt++;
				}
				else doc[i]=1;
			}
		}
		cout<<cnt<<'\n';
	}
}
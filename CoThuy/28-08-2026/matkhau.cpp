#include<iostream>
using namespace std;
string s;
bool dssnt[1000003];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//freopen("matkhau.inp","r",stdin);
	//freopen("matkhau.out","w",stdout);
	dssnt[0]=dssnt[1]=1;
	for(int i=4;i<=1000002;i+=2)
		dssnt[i]=1;
	for(int i=3;i*i<=1000003;i+=2)
		if(!dssnt[i])
			for(int j=2*i;j<=1000003;j+=i)
				dssnt[j]=1;
	cin>>s;
	s+=" ";
	for(char c:s){
		if(c>='0'&&c<='9')
			if(tmpsz==7)
	}
}
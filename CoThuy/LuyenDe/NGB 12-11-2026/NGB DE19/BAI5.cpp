#include<iostream>
#include<vector>
using namespace std;
short n;
int x1,y1,x2,y2;
void sub1(){
	long long s1,s2,scover;
	vector<pair<int,int>> ver1,ver2;
	while(n--){
		cin>>x1>>y1>>x2>>y2;
		ver1.emplace_back(x1,y1);
		ver2.emplace_back(x2,y2);
	}
	s1=abs(ver1[0].first-ver2[0].first)*abs(ver1[0].second-ver2[0].second);
	s2=abs(ver1[1].first-ver2[1].first)*abs(ver1[1].second-ver2[1].second);
	scover=abs(ver2[0].first-ver1[1].first)*abs(ver2[0].second-ver1[1].second);
	cout<<s1+s2-scover;
}
int main(){
	if(fopen("BAI5.INP","r")){
		freopen("BAI5.INP","r",stdin);
		freopen("BAI5.OUT","w",stdout);
	}
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==2) sub1();
}
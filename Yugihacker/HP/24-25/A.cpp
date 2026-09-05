#include<iostream>
using namespace std;
string s,sans;
short ssize;
int sum=0;
int main(){
	cin>>s;
	ssize=s.size();
	sans.reverse(ssize+1);
	for(short i=ssize;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9')
			sum+=s[i]-'0';
		else
			sans.push_back(s[i]);
	}
	cout<<sum<<'\n'<<sans;
}
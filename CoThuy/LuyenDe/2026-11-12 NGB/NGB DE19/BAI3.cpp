#include<iostream>
#include<map>
using namespace std;
int n;
int main(){
    if(fopen("BAI3.INP","r")){
        freopen("BAI3.INP","r",stdin);
        freopen("BAI3.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);
    int pos=1,lastpos=0,MAXFREQ=1,res;
    map<int,pair<int,int>> freq;
    while(cin>>n&&n!=0){
        if(freq.find(n)==freq.end()) freq[n]={pos,1};
        else{
            freq[n].second++;
            MAXFREQ=MAXFREQ>freq[n].second?MAXFREQ:freq[n].second;
        }
        pos++;
    }
    for(const auto& [key,info]:freq)
        if(info.second==MAXFREQ&&info.first>lastpos){
        	lastpos=info.first;
            res=key;
        }
    cout<<res<<" "<<MAXFREQ<<'\n';
}
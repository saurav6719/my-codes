#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include<set>

#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const int pw[]={1,10,100,1000,10000};
int val(char c){
	return pw[c-'A'];
}
int calc(string&s){
	int res=0,mx=0;
	for(int i=s.size()-1;i>=0;i--){
		mx=max(mx,(int)s[i]);
		if(s[i]==mx)res+=val(s[i]);
		else res-=val(s[i]);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int>v[5];
		for(int i=0;i<s.size();i++){
			v[s[i]-'A'].push_back(i);
		}
		set<int>st;
		for(int i=0;i<5;i++){
			if(v[i].empty())continue;
			st.insert(v[i][0]);
			st.insert(v[i].back());
		}
		int res=calc(s);
		for(auto x:st){
			char c=s[x];
			for(int i=0;i<5;i++){
				s[x]='A'+i;
				if(s[x]==c)continue;
				res=max(res,calc(s));
			}
			s[x]=c;
		}
		cout<<res<<"\n";
	}
	return 0;
}
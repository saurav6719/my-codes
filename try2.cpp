// LUOGU_RID: 149964285
#include<bits/stdc++.h>
#define ri register int
#define F first
#define S second
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=500005;
int n,m,a[N],ls[N],la[N],li[N],an[N];vector<pair<int,int> >vc[N];
struct nd{
	int t[N];
	void cl(){memset(t,0,sizeof(t));}
	void add(int x,int y){for(;x<=n;x+=x&-x)t[x]+=y;}
	int qr(int x){ri y=0;for(;x;x-=x&-x)y+=t[x];return y;}
}t1,t2;
int main(){
	n=rd();
	for(ri i=1;i<=n;++i){
		a[i]=rd();la[i]=ls[a[i]];ls[a[i]]=i;
		li[i]=i-la[i]==la[i]-la[la[i]]?li[la[i]]:la[la[i]];
	}
	m=rd();
	for(ri i=1,x,y;i<=m;++i)x=rd(),y=rd(),vc[y].push_back({x,i});
	for(ri i=1;i<=n;++i){
		if(la[i])t1.add(la[i],-1);
		if(li[la[i]])t2.add(li[la[i]],-1);t1.add(i,1);if(li[i])t2.add(li[i],1);
		for(auto j:vc[i]){
			ri u=t2.qr(i)-t2.qr(j.F-1),v=t1.qr(i)-t1.qr(j.F-1);
			an[j.S]=v+(u==v);
		}
	}
	for(ri i=1;i<=m;++i)printf("%d\n",an[i]);return 0;
}
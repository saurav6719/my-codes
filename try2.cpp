/*input
2 4 1 1
 
*/
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
long long mod=1e9+7;
 
typedef long long unsigned llu;
typedef long long int lld;
typedef long ld;
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%d",&a)
#define scd2(a,b) scanf("%d%d",&a,&b)
#define scd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scf(a) scanf("%lf",&a)
#define scf2(a,b) scanf("%lf%lf",&a,&b)
#define scf3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define prfL(a) printf("%lf\n",a)
#define prfS(a) printf("%lf ",a)
#define popcount __builtin_popcountll
#define swap(a,b,t) t=a;a=b;b=t
typedef pair<lld,lld> PA;
 
#define lim 1000003
#define lim2 3003
inline lld sqr(lld x) { return x * x; }
// map<pair<PA,PA>,lld> M;
// map<lld,lld> M,Mn;
// map<lld,lld>::iterator it;
// std::ios::sync_with_stdio(false);
// string S[lim],T[lim],Q[lim];
 
// multiset<lld> S;
// set<PA> H,V;
// string S[lim];
vector<lld> V[lim],Vf[lim],X,Y;
// vector<PA> IN[lim];
 
// bool dp[1002][12][12];
// priority_queue<PA> Q;
lld A[lim],P[lim],dp[103][103][13][13];
// lld A[lim];
// PA A[lim];
// char S[lim];
// double dp[1<<18];
// lld countV=0,op;
lld one,zero,ansR,numNodes;
 
 
 
int main(){
    // std::ios::sync_with_stdio(false);
    lld T,i,j,h,l,r,k,s,a,b,c,d,n,m,w,x,y,v,z,t,p,q,curr,prev,sum,ans,pos,val,countA,secondMin,indicator;
    mod=1e8;
    lld n1,n2,k1,k2;
    sc2(n1,n2);sc2(k1,k2);
    rep(i,0,n1){
    	rep(j,0,n2){
    		rep(l,0,k1){
    			rep(r,0,k2){
    				if(i+j==0){
    					dp[i][j][l][r]=1;
    					continue;
    				}
    				if(l==0 && r==0) dp[i][j][l][r]=0;
    				else if(l==0){
    						if(j!=0) dp[i][j][l][r]=dp[i][j-1][k1][r-1];
    						else dp[i][j][l][r]=0;
    				}
    				else if(r==0){
    						if(i!=0) dp[i][j][l][r]=dp[i-1][j][l-1][k2];
    						else dp[i][j][l][r]=0;
    				}
    				else{
    					if(j!=0) dp[i][j][l][r]=dp[i][j-1][k1][r-1];
    					else dp[i][j][l][r]=0;
    					if(i!=0) dp[i][j][l][r]=(dp[i-1][j][l-1][k2]+dp[i][j][l][r])%mod;
    				}
    				// printf("dp[%lld][%lld][%lld][%lld]=%lld\n",i,j,l,r,dp[i][j][l][r] );
    			}
    		}
    	}
    }
    prL(dp[n1][n2][k1][k2]);
	return 0;
}
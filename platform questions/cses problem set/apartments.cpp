#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicants(n);
    for(int i = 0 ;i<n; i++){
        cin>>applicants[i];
    }
    vector<int> apartments(m);
    for(int i =0 ; i<m; i++){
        cin>>apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int i = 0; // pointer to applicants
    int j = 0; // pointer to apartment
    int ans = 0;
    while(i<n and j<m){
        if(apartments[j]+k < applicants[i]) { // no one can get that apartment
            j++;
            continue;
        } 
        if(applicants[i] < apartments[j] - k) { // this applicant can't get any apartment
            i++;
            continue;
        }
        ans ++;
        i++;
        j++; 
    }

    cout<<ans;


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}
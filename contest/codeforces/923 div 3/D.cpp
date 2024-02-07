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
    int n;
    cin>>n;
    vector<int> av(n);
    for(int i = 0; i<n; i++){
        cin>>av[i];
    }
    vector<vector<int> >checker(n,vector<int> (2));
    int count = -1;
    int j = 0;
    for(int i = 0; i<n; i++){
        checker[i][0] = av[i];
        //debug(i);
        if(av[j] == av[i]) {
            //debug(j);
            count++;
        }
        
        if(av[i] != av[j]){
            //debug(j);
            count = 0;
            j = i;
        }

        checker[i][1] = count;
        //debug(count);
    }
    // for(int i =0; i<n; i++){
    //     cout<<checker[i][0]<<" "<<checker[i][1]<<" ,";
    // }
    int q;
    cin>>q;
    while(q--){
        int l;
        cin>>l;
        int r;
        cin>>r;
        int required = r-l; // 4-2
        debug(required);
        int aa = checker[r-1][1]; //0
        debug(aa);
        if(aa >= required){
            cout<<-1<<" "<<-1<<endl;
            continue;
        }
        else if(aa==0){
            cout<<r-1<<" "<<r<<endl;
        }
        else{
            cout<<r-aa-1<<" "<<r<<endl;
        }

    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}
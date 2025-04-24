/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
bool poss(int mid, vector<int> &input, int n, vector<vector<int> > &store){
    int i = 0;
    int j = mid - 1;

    vector<int> tocheck(22,0);

    

    for(int k = i; k<=j; k++){
        int ele = input[k];
        for(int l = 0; l<=20; l++){
            if((ele & (1<<l)) > 0){
                tocheck[l]++;
            }
        }
    }


    vector<int> tocheck_copy = tocheck;

    
    //print(tocheck_copy);
    while(j<n-1){
        int ele1  = input[i];
        //debug(ele1);
        for(int k = 0;k<=20; k++){
            if((ele1 & (1<<k)) > 0){
                tocheck[k]--;
            }
        }
        i++;
        j++;
        int ele2 = input[j];
        //debug(ele2);
        for(int k = 0; k<=20 ; k++){
            if((ele2 & (1<<k) )> 0){
                tocheck[k]++;
            }
        }
        //print(tocheck);

        for(int k = 0; k<=20; k++){
            if((tocheck[k] == 0 and tocheck_copy[k] != 0)  or (tocheck_copy[k] == 0 and tocheck[k] != 0 )) return false;
        }
    }
    return true;

}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    if(n==1){
        cout<<1<<endl;
        return;
    }

    vector<vector<int> > store(n, vector<int> ());

    for(int i= 0; i<n; i++){
        for(int j = 0; j<=20; j++){
            if(((input[i]) & (1<<j)) > 0){
                store[i].push_back(j);
            }
        }
    } 

    // for(int i = 0; i<n; i++){
    //     cout<<i<<" -> ";
    //     for(int j = 0; j<store[i].size(); j++){
    //         cout<<store[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    //poss(3, input,n, store);


    int lo = 1;
    int hi = n;
    int res = -1;

    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(poss(mid, input, n, store)){
            res = mid;
            hi = mid - 1;
        }

        else lo = mid + 1;
    }

    cout<<res<<endl;


}
/* logic ends */

signed main(){
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


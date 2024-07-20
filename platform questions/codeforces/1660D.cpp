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
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<vector<int> > store;
    vector<pair<int,int> > indexstore;
    vector<int> topush;
    int last = 0;
    for(int i = 0; i<n; i++){
        
        if(input[i] == 0){
            store.push_back(topush);
            indexstore.push_back({last , i-1});
            last = i+1;
            topush.clear();
            continue;
        }
        topush.push_back(input[i]);
    }
    if(input[n-1] != 0){
        store.push_back(topush);
        indexstore.push_back({last , n-1});
        topush.clear();
    }


    // for(int i = 0; i<indexstore.size(); i++){
    //     cout<<indexstore[i].first<<" "<<indexstore[i].second<<endl;
    // }

    // cout<<endl;


    // for(int i = 0; i<store.size(); i++){
    //     for(int j = 0; j<store[i].size(); j++){
    //         cout<<store[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }


    vector<int> negcount;

    for(int i = 0; i<store.size(); i++){
        int cnt = 0;
        for(int j = 0; j<store[i].size(); j++){
            if(store[i][j] < 0) cnt++;
        }

        negcount.push_back(cnt);
    }


    print(negcount);
    debug(store.size());
    vector<int> twocount;

    for(int i = 0; i<store.size(); i++){
        int cnt = 0;
        for(int j = 0; j<store[i].size(); j++){
            if(store[i][j] == 2 or store[i][j] == -2){
                cnt++;
            }
        }

        twocount.push_back(cnt);
    }

    print(twocount);

    for(int i = 0; i<store.size(); i++){
        if(negcount[i] % 2 == 0) continue;
        int toremove1 = 0;
        int toremove2 = 0;
        for(int j = 0; j<store[i].size(); j++){
            if(store[i][j] == -1) break;
            if(store[i][j] == -2){
                toremove1++;
                break;
            }
            if(store[i][j] == 2) toremove1++;
        }

        for(int j = store[i].size() - 1; j>= 0; j--){
            if(store[i][j] == -1) break;
            if(store[i][j] == -2){
                toremove2++;
                break;
            }
            if(store[i][j] == 2) toremove2++;
        }


        twocount[i] -= min(toremove1, toremove2);

        if(toremove1 < toremove2){
            int cnt = 0;
            for(int j = 0; j<store[i].size(); j++){
                if(store[i][j] < 0){
                    cnt++;
                    break;
                }
                cnt++;
            }

            indexstore[i].first += cnt;
        }
        else{
            int cnt = 0;
            for(int j = store[i].size() - 1; j>=0; j--){
                if(store[i][j] < 0){
                    cnt++;
                    break;
                }
                cnt++;
            }

            indexstore[i].second -= cnt;
        }
    }

    print(twocount);

    int maxsegment = 0;
    int maxtwocount = 0;
    for(int i = 0; i<store.size(); i++){
        if(twocount[i] > maxtwocount){
            maxtwocount = twocount[i];
            maxsegment = i;
        }
    }

    debug(maxtwocount);
    debug(maxsegment);

    // if(maxtwocount == 0){
    //     cout<<0<<" "<<n<<endl;
    //     return;
    // }

    cout<<indexstore[maxsegment].first<<" "<<n-1-indexstore[maxsegment].second<<endl;


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


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
    vector<pair<int,int> > input(n);
    for(int i =0 ; i<n; i++){
        cin>>input[i].first;
        input[i].second = i;
    }

    vector<pair<int,int> > input_copy = input;

    sort(input.begin(), input.end());

    // for(int i = 0; i<n; i++){
    //     cout<<input[i].first<<" "<<input[i].second<<endl;
    // }

    vector<vector<int> > store;

    int i = 0; 
    vector<int> toput;
    toput.push_back(input[0].second);
    i++;
    while(i<n){
        //print(toput);
        if(((input[i].first) ^ (input[i-1].first)) < 4){
            toput.push_back(input[i].second);
            i++;
            continue;
        }
        else{
            store.push_back(toput);
            toput.clear();
            toput.push_back(input[i].second);
            i++;
            continue;
        }
    }

    if(toput.size() > 0){
        store.push_back(toput);
    }


    // for(int k = 0; k<store.size(); k++){
    //     for(int j = 0; j<store[k].size(); j++){
    //         cout<<store[k][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> ans(n);

    for(int j = 0; j<store.size(); j++){
        vector<int> curr = store[j];
        sort(curr.begin(), curr.end());
        vector<int> num;
        for(int k = 0; k<curr.size(); k++){
            num.push_back(input_copy[curr[k]].first);
        }

        sort(num.begin(), num.end());

        for(int k = 0; k<curr.size(); k++){
            ans[curr[k]] = num[k];
        }
    }

    for(int i = 0;i<n; i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


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


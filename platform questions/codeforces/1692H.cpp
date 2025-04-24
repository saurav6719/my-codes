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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int ans = INT_MIN;
    int rightmostindex = -1;
    int value = 0;

    map<int,int> mp;

    for(int i =0; i<n; i++){

        map<int,int> newmp;
        int ele = input[i];

        if(mp.count(ele) == 0){
            mp[ele] = 1;
            if(mp[ele] > ans){
                ans = mp[ele];
                rightmostindex = i;
                value = ele;
            }
        }

        else{
            mp[ele] ++;
            if(mp[ele] > ans){
                ans = mp[ele];
                rightmostindex = i;
                value = ele;
            }
        }

        for(auto ele2 : mp){
            if(ele2.first != ele){
                mp[ele2.first] --;
            }
        }

        for(auto ele2 : mp){
            if(ele2.second == 0)continue;
            newmp.insert(ele2);
        }

        mp = newmp;
    }

    debug(rightmostindex);
    debug(ans);
    debug(value);
    int currval = 0;
    int leftmostindex =-1;
    for(int i = rightmostindex ; i>=0; i--){
        if(input[i] == value){
            currval ++;
            if(currval == ans){
                leftmostindex = i;
                break;
            }
        }
        else {
            currval --;
        }
    }

    debug(leftmostindex);

    cout<<value<<" "<<leftmostindex + 1<<" "<<rightmostindex+1<<endl;
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


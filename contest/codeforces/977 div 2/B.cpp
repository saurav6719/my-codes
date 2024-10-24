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
    int n,x;
    cin>>n>>x;
    vector<int> input(n);
    for(int i=0; i<n; i++){
        cin>>input[i];
    }

    map<int,int> freq;

    for(auto ele : input){
        freq[ele]++;
    }

    map<int,set<int> > multiplewithmod;

    for(auto ele : freq){
        if(ele.second > 1){
            multiplewithmod[ele.first%x].insert(ele.first);
        }
    }

    int mex = 0;
    for(int i=0; i<=n; i++){
        if(freq.find(i) == freq.end()){
            mex = i;
            break;
        }
    }

    debug(mex);

    while(true){
        if(freq[mex] >=1) {
            mex++;
            continue;
        }
        int mexmod = mex%x;
        if(multiplewithmod[mexmod].size() == 0){
            cout<<mex<<endl;
            return;
        }
        int ele = *multiplewithmod[mexmod].begin();
        if(ele > mex){
            cout<<mex<<endl;
            return;
        }
        freq[ele]--;
        if(freq[ele] == 1){
            multiplewithmod[ele%x].erase(ele);
        }
        mex++;
    }

    cout<<mex<<endl;
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


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
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;

    vector<pp> ans;
    for(int j = 0;j<k-1; j++){
        vector<int> open;
        vector<int> close;
        for(int i = 0; i<n; i++){
            if(str[i] == '('){
                open.push_back(i);
            }
            else close.push_back(i);
        }
        print(open);
        print(close);
        int openi = open[j];
        debug(openi);
        reverse(str.begin()+(2*j), str.begin()+openi+1);
        ans.push_back({(2*j) + 1, openi+1});
        // cout<<str<<endl;
        print(str);

        vector<int> open2;
        vector<int> close2;
        for(int i = 0; i<n; i++){
            if(str[i] == '('){
                open2.push_back(i);
            }
            else close2.push_back(i);
        }
        int closi = close2[j];
       
        reverse(str.begin() + (2*j+1) , str.begin() + closi+1);
        ans.push_back({(2*j) + 2, closi+1});

    }

    vector<int> finalopen;
    vector<int> finalclose;
    for(int i = 0; i<n; i++){
        if(str[i] == '('){
            finalopen.push_back(i);
        }
        else finalclose.push_back(i);
    }

    int toswap = finalclose[k-1];
    debug(toswap);
    print(finalopen);
    print(finalclose);

    for(int i = k-1; i<finalopen.size(); i++){
        debug(finalopen[i]);
        if(finalopen[i] > toswap){
            ans.push_back({toswap+1, finalopen[i]+1});
            reverse(str.begin() + toswap, str.begin() + finalopen[i]+1);
            toswap++;
        }
    }


    print(str);
    cout<<ans.size()<<endl;
    for(auto ele : ans){
        cout<<ele.first<<" "<<ele.second<<endl;
    }


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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}


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
    int n;cin>>n;
    int k;cin>>k;
    string str;
    cin>>str;

    sort(str.begin(), str.end());

    map<char,int> mp;
    for(auto ele : str){
        mp[ele]++;
    }

    bool allequal = true;

    for(auto ele : mp){
        if(ele.second != k){
            allequal = false;
            break;
        }
    }

    vector<string> ans(k, "");

    if(allequal){
        int i = 0;
        while(i<n){
            ans[i%k]+= str[i];
            i++;
        }
        cout<<ans[0]<<endl;
        return;
    }

    if(mp.size() == 1){
        int least = n / k;
        string res = "";
        res += str.substr(0, least);
        if(n%k != 0){
            res += str[0];
        }

        cout<<res<<endl;
        return;
    }


    if(mp.size() == 2){
        auto one = *mp.begin();
        auto two = *mp.rbegin();
        int freqtwo = two.second;
        int freqone = one.second;
        if(freqone < k){
            cout<<two.first<<endl;
            return;
        }
        else if(freqone > k){
            int i = 0;
            while(i<k){
                ans[i%k] += str[i];
                i++;
                
            }
            ans[0] += str.substr(k);

            sort(ans.begin(), ans.end());

            cout<<ans.back()<<endl;
            return;
        }
        else{
            string res = "";
            res += one.first;
            int res2 = freqtwo / k;
            for(int a = 0; a<res2; a++){
                res += two.first;
            }
            if(freqtwo % k != 0){
                res += two.first;
            }

            cout<<res<<endl;
            return;
        }

    }
    int i = 0;
    while(i<k){
        ans[i%k] += str[i];
        i++;
        
    }
    
    


    ans[0] += str.substr(k);

    sort(ans.begin(), ans.end());

    cout<<ans.back()<<endl;



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


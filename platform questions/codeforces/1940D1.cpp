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
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    vector<pp> bsort(n);
    for(int i = 0; i<n; i++){
        bsort[i] = {b[i] , i};
    }

    sort(bsort.begin(), bsort.end());



    for(int i = 0; i<n; i++){
        int reqmax = bsort[i].first;
        int idx = bsort[i].second;

        // debug(reqmax);
        // debug(idx);

        if(a[idx] == reqmax) continue;
        if(a[idx] > reqmax){
            cout<<"NO"<<endl;
            return;
        }

        //left search 
        int currmax = a[idx];
        bool flag = false;
        for(int j = idx; j>=0; j--){
            currmax = max(currmax , a[j]);
            if(currmax == reqmax){
                for(int k = j ; k<= idx; k++){
                    a[k] = reqmax;
                }
                flag = true;
                break;
            }
            if(b[j] < reqmax) break;
        }

        if(flag == true) continue;

        //right search

        currmax = a[idx];
        flag = false;
        for(int j = idx; j<n; j++){
            currmax = max(currmax , a[j]);
            if(currmax == reqmax){
                for(int k = idx ; k<= j; k++){
                    a[k] = reqmax;
                }
                flag = true;
                break;
            }
            if(b[j] < reqmax) break;
        }

        if(!flag) {
            cout<<"NO"<<endl;
            return;
        }
    }



    print(a);

    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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


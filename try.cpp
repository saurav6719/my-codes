/**
 *    author: Saurav
 *    created: 2024.11.19 00:39:39
 **/

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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    multiset<int> s1;
    multiset<int> s2;

    if(k<5){
        
        for(int i = 0; i<=n-k; i++){
            vector<int> v;
            for(int j = i; j<i+k; j++){
                v.push_back(arr[j]);
            }
            sort(v.begin(),v.end());
            if(k == 1){
                cout<<v[0]<<" ";
            }
            else if(k == 2){
                cout<<v[0]<<" ";
            }
            else if(k == 3){
                cout<<v[1]<<" ";
            }
            else if(k == 4){
                cout<<v[1]<<" ";
            }
        }
    }
    else{
        int leftsize = k/2+k%2;
        int rightsize = k/2;

        vector<int> v;
        for(int i = 0; i<k; i++){
            v.push_back(arr[i]);
        }
        sort(v.begin(),v.end());

        for(int i=0;i<leftsize;i++){
            s1.insert(v[i]);
        }

        for(int i=leftsize;i<k;i++){
            s2.insert(v[i]);
        }

        cout<<*s1.rbegin()<<" ";

        for(int i = k; i<n; i++){
            int eletoadd = arr[i];
            int eletoerase = arr[i-k];

            if(s1.find(eletoerase) != s1.end()){
                auto it = s1.find(eletoerase);
                s1.erase(it);
                vector<int> v2;
                v2.push_back(eletoadd);
                v2.push_back(*s1.rbegin());
                v2.push_back(*s2.begin());

                s1.erase(s1.find(*s1.rbegin()));
                s2.erase(s2.find(*s2.begin()));

                sort(v2.begin(),v2.end());

                s1.insert(v2[0]);
                s1.insert(v2[1]);
                s2.insert(v2[2]);

                cout<<*s1.rbegin()<<" ";

            }
            else{
                auto it = s2.find(eletoerase);
                s2.erase(it);
                vector<int> v2;
                v2.push_back(eletoadd);
                v2.push_back(*s1.rbegin());
                v2.push_back(*s2.begin());

                s1.erase(s1.find(*s1.rbegin()));
                s2.erase(s2.find(*s2.begin()));

                sort(v2.begin(),v2.end());

                s1.insert(v2[0]);
                s2.insert(v2[1]);
                s2.insert(v2[2]);

                cout<<*s1.rbegin()<<" ";
            }
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}


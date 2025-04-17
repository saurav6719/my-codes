/**
 *    author: Saurav
 *    created: 2025.04.16 20:39:12
 *    We stop at Candidate Master in 2025
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
    string str;
    cin>>str;
    int maxi = 2*(k-1);
    vector<int> blocks;
    int i = 0;
    while(i<n){
        int j = i;
        while(j<n and str[j] == str[i]){
            j++;
        }
        blocks.push_back(j-i);
        i = j;
    }

    // print(blocks);

    for(auto ele : blocks){
        if(ele > maxi){
            cout<<"NO"<<endl;
            return;
        }
    }

    vector<int> galat;
    for(int i = 0; i<blocks.size(); i++){
        if(blocks[i] >= k){
            galat.push_back(i);
        }
    }

    // print(galat);

    if(galat.size() == 0){
        cout<<"YES"<<endl;
        return;
    }

    if(galat.size() > 2){
        cout<<"NO"<<endl;
        return;
    }

    if(galat.size() == 2){
        if(galat[0] % 2 == galat[1] % 2 ){
            cout<<"NO"<<endl;
            return;
        }
        else{
            cout<<"YES"<<endl;
            return;
        }
        
    }

    if(galat.size() == 1){
        int index = galat[0];
        if(index>0){
            // left swap
            if(index % 2 != blocks.size() % 2 ){
                cout<<"YES"<<endl;
                return;
            }

            for(int j = index - 1; j>=0; j-=2){
                if(blocks[j] > 1){
                    cout<<"YES"<<endl;
                    return;
                }
            }

            for(int j = index - 2; j>=0; j-=2){
                if(blocks[index] + blocks[j] <= maxi){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        if(index < blocks.size() - 1){
            // right swap

            if(index % 2 == blocks.size() % 2 ){
                cout<<"YES"<<endl;
                return;
            }

            for(int j = index + 1; j<blocks.size(); j+=2){
                if(blocks[j] > 1){
                    cout<<"YES"<<endl;
                    return;
                }
            }

            for(int j = index + 2; j<blocks.size(); j+=2){
                if(blocks[index] + blocks[j] <= maxi){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}


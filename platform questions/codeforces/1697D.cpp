/**
 *    author: Saurav
 *    created: 2024.10.30 23:14:11
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
char query1(int i){
    cout<<"? 1 "<<i<<endl;
    cout.flush();
    char c;
    cin>>c;
    return c;
}

int query2(int l,int r){
    cout<<"? 2 "<<l<<" "<<r<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    vector<char> ans(n+1);
    ans[1] = query1(1);
    map<pp,int> mp;
    mp[{1,1}] = 1;
    map<char,int> lastoccurence;
    lastoccurence[ans[1]] = 1;

    for(int i = 2; i<=n; i++){
        int xx = query2(1,i);
        int yy = mp[{1,i-1}];

        if(xx != yy){
            ans[i] = query1(i);
            lastoccurence[ans[i]] = i;
            map<char ,int> temp;
            for(int j = 1; j<=i; j++){
                temp[ans[j]] ++;
            }
            mp[{1,i}] = temp.size();
            for(int j = 2; j<=i; j++){
                temp[ans[j-1]] --;
                if(temp[ans[j-1]] == 0){
                    temp.erase(ans[j-1]);
                }
                mp[{j,i}] = temp.size();
            }
        }
        else{
            vector<int> last;
            for(auto x : lastoccurence){
                last.push_back(x.second);
            }
            sort(last.begin(),last.end());
            int l = 0;
            int r = last.size()-1;
            char ch = '#';
            while(l<=r){
                int mid = (l+r)/2;
                int xx = query2(last[mid],i);
                int yy = mp[{last[mid],i-1}];
                if(xx == yy){
                    ch= ans[last[mid]];
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            ans[i] = ch;
            lastoccurence[ans[i]] = i;
            map<char ,int> temp;
            for(int j = 1; j<=i; j++){
                temp[ans[j]] ++;
            }
            mp[{1,i}] = temp.size();
            for(int j = 2; j<=i; j++){
                temp[ans[j-1]] --;
                if(temp[ans[j-1]] == 0){
                    temp.erase(ans[j-1]);
                }
                mp[{j,i}] = temp.size();
            }
        }
    }

    cout<<"! ";
    for(int i = 1; i<=n; i++){
        cout<<ans[i];
    }
    cout<<endl;
    cout.flush();

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


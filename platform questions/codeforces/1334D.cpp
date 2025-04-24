/**
 *    author: Saurav
 *    created: 2024.10.20 22:29:26
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

void printff(int primary , int secondary , int times, int n){
    while(times > 0){
        cout<<secondary <<" ";
        times--;
        if(times <= 0) break;
        secondary ++;
        if(secondary > n){
            primary ++;
            secondary = primary + 1;
        }

        if(primary == n) break;

        cout<<primary <<" ";
        times--;
        if(times <= 0) break;
    }

    if(times > 0){
        cout<<1<<" ";
    }
}

void solve(){
    int n;
    cin>>n;

    map<int,int> mp;
    mp[1] = 1;

    int curr = 2;
    int currincrease = (n-1) * 2;
    int last = 1;

    while(curr < n){
        mp[curr] = last + currincrease;
        last = mp[curr];
        currincrease -= 2;
        curr++;
    }

    printmap(mp);

    int l,r;
    cin>>l>>r;

    vector<int> v;
    for(auto ele : mp){
        v.push_back(ele.second);
    }

    int xx = lower_bound(v.begin(), v.end(), l) - v.begin();

    if(xx == v.size()){
        if(l == (n * (n-1))){
            if(r>l){
                cout<<n<<" "<<1<<endl;
                return;
            }
            cout<<n<<endl;
            return;
        }
        else if(l == (n * (n-1)) + 1){
            cout<<1<<endl;;
            return;
        }
    }

    if(xx!=v.size() and v[xx] == l){
        xx++;
    }

    debug(xx);

    int primary = xx;
    int used = l - mp[primary];

    if(used % 2== 0){
        cout<<primary<<" ";
        used++;
        l++;
    }

    int secondary = primary + (used / 2+ used % 2);

    printff(primary , secondary , r-l+1, n);

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


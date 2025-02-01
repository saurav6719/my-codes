/**
 *    author: Saurav
 *    created: 2025.02.01 01:14:42
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
bool cmp(pp a, pp b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int dp[2005];

int pickorleave[2005];

int f(vector<pp> &input, vector<int> &next, vector<int> &under, int idx){
    int n = input.size();
    if(idx == n){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }
    // pick this one
    int pick = 1 + under[idx] + f(input,next,under,next[idx]);

    // leave this one

    int leave = f(input,next,under,idx+1);

    if(pick > leave){
        pickorleave[idx] = 1;
    }
    else{
        pickorleave[idx] = 0;
    }

    return dp[idx] = max(pick,leave);
}

int f2(vector<pp> &input, int idx, vector<int> &picknotpick2, vector<int> &dp2){
    int n = input.size();
    if(idx >= n){
        return 0;
    }

    if(dp2[idx] != -1){
        return dp2[idx];
    }

    int pick = 1;
    for(int i = idx+1; i<n; i++){
        if(input[idx].second <= input[i].first){
            pick = 1 + f2(input,i,picknotpick2,dp2);
            break;
        }
    }

    int leave = f2(input,idx+1,picknotpick2,dp2);

    if(pick > leave){
        picknotpick2[idx] = 1;
    }
    else{
        picknotpick2[idx] = 0;
    }

    return dp2[idx] = max(pick,leave);
}
void solve(){
    int n;
    cin>>n;

    vector<pp> v(n);

    map<pp,int> mp;

    map<pp,int> mp2;

    for(int i = 0; i<n; i++){
        int c,r;
        cin>>c>>r;
        int left = c-r;
        int right = c+r;
        v[i] = {left,right};
        mp[{left,right}] = i+1;
    }

    sort(v.begin(),v.end(),cmp);

    for(int i = 0; i<n; i++){
        mp2[v[i]] = i+1;
    }

    printpp(v);

    memset(dp,-1,sizeof(dp));

    vector<int> howmanyunderthis(n,0);

    vector<vector<pp> > underthis(n);

    for(int i = 0; i<n; i++){
        int left1 = v[i].first;
        int right1 = v[i].second;
        vector<pp> temp;
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            int left2 = v[j].first;
            int right2 = v[j].second;

            if(left1 <= left2 && right1 >= right2){
                temp.push_back(v[j]);
            }
        }

        vector<int> picknotpick2(temp.size(),-1);
        vector<int> dp2(temp.size(),-1);

        if(temp.size() == 0){
            howmanyunderthis[i] = 0;
            continue;
        }

        howmanyunderthis[i] = f2(temp,0,picknotpick2,dp2);

        int curr2 = 0;

        while(curr2 < temp.size()){
            if(picknotpick2[curr2] == 1){
                underthis[i].push_back(temp[curr2]);
                bool found = false;
                for(int j = curr2+1; j < temp.size(); j++){
                    if(temp[curr2].second <= temp[j].first){
                        curr2 = j;
                        found = true;
                        break;
                    }
                }
                if (!found) { // No valid next index was found: update curr2 to avoid infinite loop
                    curr2++;  
                }
            }
            else{
                curr2++;
            }
        }
    }

    print(howmanyunderthis);

    vector<int> next(n,0);
    vector<int> lefts(n,0);
    for(int i = 0; i<n; i++){
        lefts[i] = v[i].first;
    }

    for(int i = 0; i<n; i++){
        int right = v[i].second;
        int idx = lower_bound(lefts.begin(),lefts.end(),right) - lefts.begin();
        next[i] = idx;
    }

    print(next);

    int ans = f(v,next,howmanyunderthis,0);


    for(int i = 0; i<n; i++){
        debug(pickorleave[i]);
    }

    cout<<ans<<endl;

    int curr = 0;

    set<pp> s;

    printpp(underthis[0]);

    while(curr < n){
        if(pickorleave[curr] == 1){
            s.insert(v[curr]);
            debug(v[curr].first);
            debug(v[curr].second);
            curr = next[curr];
        }
        else{
            curr++;
        }
    }

    set<pp> unders;

    for(auto ele : s){
        int index = mp2[ele];
        debug(index);
        for(auto x : underthis[index-1]){
            unders.insert(x);
            debug(x.first);
            debug(x.second);
        }
    }

    for(auto ele : unders){
        s.insert(ele);
    }

    for(auto x : s){
        cout<<mp[x]<<" ";
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}


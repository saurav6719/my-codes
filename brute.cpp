/**
 *    author: Saurav
 *    created: 2025.02.01 13:08:51
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

vector<vector<int> > choiceati;
vector<vector<int> > dp;

set<pp> changes;

int f(int i, int j, vector<int> &endpoints, map<int,vector<int> > &mpleft){

    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }


    int skipleft = 0;
    int pick = 0;

    // skipping left 

    if(i + 1 <= j){
        skipleft = f(i+1,j,endpoints,mpleft);
    }

    // picking
    int bestpick = -1;

    bool isthispresent = false;

    for(auto ele : mpleft[i]){
        if(ele == j){
            isthispresent = true;
            pick = 1; 
            break;
        }
    }


    for(int k = 0; k<mpleft[i].size(); k++){
        int right = mpleft[i][k];
        if(right < j){
            int curr = 0;
            if(isthispresent) curr++;
            curr += f(i,right,endpoints,mpleft) + f(right,j,endpoints,mpleft); 
            if(curr > pick){
                pick = curr;
                bestpick = right;
            }
        }
    }

    int maxi = max(skipleft,pick);
    if(maxi == skipleft){
        choiceati[i][j] = -1;
    }
    else{
        choiceati[i][j] = bestpick;
    }

    return dp[i][j] = maxi;
    
}

vector<pp> ans;


void constructanswer(int i, int j, map<int,vector<int> > &mpleft){

    if(i >= j){
        return;
    }
    if(choiceati[i][j] == -1){
        constructanswer(i+1,j,mpleft);
        return;
    }
    if(choiceati[i][j] == -2){
        constructanswer(i,j-1,mpleft);
        return;
    }

    int nextidx = choiceati[i][j];
    ans.push_back({i,nextidx});

    if(changes.count({i,j}) == 0)constructanswer(i,nextidx-1,mpleft);
    else{
        constructanswer(i+1,nextidx,mpleft);
    }
    constructanswer(nextidx,j,mpleft);
}
void solve(){
    int n;
    cin>>n;

    vector<pp> v(n);

    map<int,vector<int> > mpleft;
    map<pp, int> originalindex;

    vector<int> endpoints;
    for(int i = 0; i<n; i++){
        int c,r;
        cin>>c>>r;
        int left = c-r;
        int right = c+r;
        v[i] = {left,right};
        mpleft[left].emplace_back(right);
        originalindex[{left,right}] = i+1;
        endpoints.emplace_back(right);
        endpoints.emplace_back(left);
    }

    sort(endpoints.begin(),endpoints.end());
    endpoints.erase(unique(endpoints.begin(),endpoints.end()),endpoints.end());

    map<int, vector<int> > mptemp;

    print(endpoints);

    for(int i = 0; i<endpoints.size(); i++){
        int left = endpoints[i];
        vector<int> &temp = mpleft[left];
        sort(temp.begin(),temp.end());
        for(auto ele : temp){
            int right = ele;
            int lb = lower_bound(endpoints.begin(),endpoints.end(),right) - endpoints.begin();
            mptemp[i].emplace_back(lb);
        }
    }

    mpleft = mptemp;

    for(auto ele : mpleft){
        debug(ele.first);
        print(ele.second);
    }
    int m = endpoints.size();

    choiceati.assign(m,vector<int> (m,-1));
    dp.assign(m,vector<int> (m,-1));

    int ans1 = f(0,m-1,endpoints,mpleft);

    // debug(dp[0][3]);
    // debug(dp[0][2]);
    // debug(dp[1][2]);
    // debug(dp[3][5]);

    cout<<ans1<<endl;

    constructanswer(0,m-1,mpleft);

    vector<pp> leftrights;


    for(auto ele : ans){
        int left = endpoints[ele.first];
        int right = endpoints[ele.second];
        leftrights.push_back({left,right});
    }

    vector<int> finalans;


    for(auto ele : leftrights){
        finalans.push_back(originalindex[ele]);
    }

    sort(finalans.begin(),finalans.end());

    for(auto ele : finalans){
        cout<<ele<<" ";
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


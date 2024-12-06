/**
 *    author: Saurav
 *    created: 2024.12.07 01:43:53
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
struct xxxx{
    int i; // which test case
    int start;
    int length;

};

int sum(vector<int> &prfsum, vector<int> &weightedpfsum, int l, int r){
    return weightedpfsum[r] - weightedpfsum[l-1] - (prfsum[r] - prfsum[l-1])*(l-1);
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> input(n+1);
    for(int i=1;i<=n;i++){
        cin>>input[i];
    }

    map<pp,vector<xxxx> > mp;

    for(int i = 1; i<=q; i++){
        int s,d,k;
        cin>>s>>d>>k;
        int x = s%d;
        if(x == 0){
            x = d;
        }
        mp[{d,x}].push_back({i, s, k});
    }

    vector<int> ans(q+1);


    for(auto &ele : mp){
        auto &ff = ele.first;
        auto &ss = ele.second;
        int d = ff.first;
        int start = ff.second;
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            v.push_back(x);
        }

        vector<int> prfsum;
        prfsum.push_back(0);
        for(auto x : v){
            prfsum.push_back(prfsum.back() + x);
        }

        vector<int> weightedpfsum;
        weightedpfsum.push_back(0);
        for(int i = 1; i<=v.size(); i++){
            weightedpfsum.push_back(weightedpfsum.back() + i*v[i-1]);
        }

        print(prfsum);
        print(weightedpfsum);

        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            int answer = sum(prfsum, weightedpfsum, l, r);
            cout<<answer<<" ";
        }

        for(auto &ele : ss){
            int testcase = ele.i;
            int s = ele.start;
            debug(s);
            int left =( s - start ) / d + 1;
            debug(left);
            int right = left + ele.length - 1;
            debug(right);
            int answer = sum(prfsum, weightedpfsum, left, right);
            debug(answer);
            ans[testcase] = answer;
        }
    }

    for(int i = 1; i<=q; i++){
        cout<<ans[i]<<" ";
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}


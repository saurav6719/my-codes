/**
 *    author: Saurav
 *    created: 2025.12.02 16:13:10
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int f(vector<int> &v, int l, int r){
    if(l > r) return 0;
    if(l == 0){
        return v[r];
    }
    return v[r] - v[l-1];
}
void solve(){
    string s;
    cin>>s;
    vector<int> left;
    vector<int> right;
    int curr = 0;
    for(auto ele : s){
        if(ele == '-'){
            left.push_back(curr);
            curr = 0;
            continue;
        }
        else if(ele == ','){
            right.push_back(curr);
            curr = 0;
            continue;
        }
        curr *= 10;
        curr += ele - '0';
    }

    right.push_back(curr);
    // print(left);
    // print(right);
    int maxi = 0;
    for(auto ele : left){
        maxi = max(ele, maxi);
    }
    for(auto ele : right){
        maxi = max(ele, maxi);
    }

    debug(left.size());
    debug(right.size());
    set<int> st;

    vector<int> v;
    vector<int> v2;

    for(int i = 1; i<=1000000; i++){
        string temp = to_string(i);
        temp += to_string(i);
        while(true){
            long long num = stoll(temp);
            if(num <= maxi) st.insert(num);
            else break;
            temp = temp + to_string(i);
        }
    }

    for(auto ele : st){
        v2.push_back(ele);
    }

    // print(v2);
    sort(v2.begin(), v2.end());
    print(v2);
    v.push_back(v2[0]);
    for(int i = 1; i<v2.size(); i++){
        v.push_back(v[i-1] + v2[i]);
    }

    int sum = 0;

    for(int i = 0; i<left.size(); i++){
        int one = left[i];
        int two = right[i];

        int l = lower_bound(v2.begin(), v2.end(), one) - v2.begin();
        int r = upper_bound(v2.begin(), v2.end(), two) - v2.begin();
        r--;

        sum += f(v, l, r);
    }

    cout<<sum<<endl;

}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}


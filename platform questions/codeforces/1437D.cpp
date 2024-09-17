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

vector<pp> st;

void buildTree(int arr[], int i, int lo, int hi){
    if(lo == hi){
        st[i].first = arr[lo]; // max value
        st[i].second = arr[lo]; // min value
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr, 2*i+1, lo, mid);
    buildTree(arr, 2*i+2, mid+1, hi);
    
    st[i].first = max(st[2*i+1].first, st[2*i+2].first); // max value
    st[i].second = min(st[2*i+1].second, st[2*i+2].second); // min value
}

int getMax(int i, int lo, int hi, int l, int r){
    if(l > hi || r < lo) return LLONG_MIN; // out of range, return very small value
    if(lo >= l && hi <= r) return st[i].first; // segment is within range
    int mid = lo + (hi-lo)/2;
    int left = getMax(2*i+1, lo, mid, l, r);
    int right = getMax(2*i+2, mid+1, hi, l, r);
    return max(left, right);
}

int getMin(int i, int lo, int hi, int l, int r){
    if(l > hi || r < lo) return LLONG_MAX; // out of range, return very large value
    if(lo >= l && hi <= r) return st[i].second; // segment is within range
    int mid = lo + (hi-lo)/2;
    int left = getMin(2*i+1, lo, mid, l, r);
    int right = getMin(2*i+2, mid+1, hi, l, r);
    return min(left, right);
}

int f(pp interval1, pp interval2){
    // cout<<interval1.first<<" "<<interval1.second;
    // cout<<interval2.first<<" "<<interval2.second;

    // Separate intervals
    if(interval1.second < interval2.first || interval2.second < interval1.first){
        return (interval1.second - interval1.first + 1) + (interval2.second - interval2.first + 1);
    }
    // Overlapping intervals
    return max(interval1.second, interval2.second) - min(interval1.first, interval2.first) + 1;
}

void solve(){
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    int arr[n+1];
    arr[0] = 0;
    st.resize(4*(n+1));

    for(int i = 1; i <= n; i++){
        if(str[i-1] == '+') arr[i] = arr[i-1] + 1;
        else arr[i] = arr[i-1] - 1;
    }


    buildTree(arr, 0, 0, n);

    // for(int i = 0; i<=3*n; i++){
    //     cout<<st[i].second<<" ";
    // }

    // cout<<endl;

    

    debug(getMax(0,0,n,0,1));

    while(q--){
        int l, r;
        cin >> l >> r;
        int minleft = getMin(0, 0, n, 0, l-1);
        int maxleft = getMax(0, 0, n, 0, l-1);

        debug(minleft);
        debug(maxleft);

        pp interval1 = {minleft, maxleft};
        pp interval2;

        if(r == n) interval2 = interval1;
        else{
            int minright = getMin(0, 0, n, r+1, n);
            int maxright = getMax(0, 0, n, r+1, n);

            debug(minright);
            debug(maxright);

            int diff = arr[r] - arr[l-1];
            diff *= -1;
            minright += diff;
            maxright += diff;
            debug(diff);
            debug(minright);
            debug(maxright);
            interval2 = {minright, maxright};

            
        }

        cout << f(interval1, interval2) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
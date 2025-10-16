/**
 *    author: Saurav
 *    created: 2025.10.16 19:36:16
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
class segtree {
public:
    int size;
    vector<int>maxi;
    void init(int n)
    {
        size = 1;
        while ( size < n )
            size *= 2;
        maxi.assign(2*size, 0);
    }
    void build (vector<int>&a, int x, int lx, int rx)
    {
        if ( rx - lx == 1 ) //reached leaf node
        {
            if ( lx < (int)a.size()) //check if even valid element
            {
                maxi[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        maxi[x] = max(maxi[2*x+1] , maxi[2*x+2]);
    }
    void build (vector<int>&a)
    {
        build(a, 0, 0, size);
    }
    void add (int i, int v, int x, int lx, int rx)
    {
        if ( rx - lx == 1 )
        {
            maxi[x] += v;
            return;
        }
        int m = (lx + rx)/2;
        if ( i < m )
        {
            add(i, v, 2*x+1, lx, m); //checking the left subtree as i < m 
        }
        else
        {
            add(i, v, 2*x+2, m, rx); //checking the right subtree as i >= m
        }
        maxi[x] = max(maxi[2*x+1] , maxi[2*x+2]);
    }
    void add (int i, int v)
    {
        add(i, v, 0, 0, size);
    }
    int getMax ( int l, int r, int x, int lx, int rx)
    {
        if ( lx >= l && rx <= r )
            return maxi[x];
        if ( r <= lx || l >= rx )
            return -1e18;
        int m = (lx + rx)/2;
        return max(getMax(l, r, 2*x+1, lx, m), getMax(l, r, 2*x+2, m, rx));
    }
    int getMax ( int l, int r)
    {
        return getMax (l, r, 0, 0, size);
    }
};
void solve()
{
    int n, x;
    cin>>n>>x;
    vector<int>chests(n);
    for (int i = 0; i<n; i++)
        cin>>chests[i];
    vector<int>pref(n), pref2(n);
    pref[0] = chests[0];
    for (int i = 1; i<n; i++){
        pref[i] = pref[i-1] + chests[i];
        pref2[i] = pref[i-1];
    }
    /*
    dp[i][j] = maximum coins i can collect from index i till n-1 with exactly j explosions

    say i am at index i
    I iterate j from 0 to x
    dp[i][j] = maxValue of (dp[k][j-1] where k ranges from i+1 till i + v[i] -> find out using segtree + sum from index i + 1 till index k-1 ) -> this is when I am certain to do an explosion in the range
    when i am not doing any explosion i can just have the sum from index i + 1 till index i + x
    once this is done, add dp[i][j] to the segtree

    */
    //REXPLODED
    // This is the brute force solution
    // for (int i = 0; i<n; i++){
    //     for (int j = i+1; j<=min(n-1, i+v[i]); j++){
    //         dp[i] = max(dp[i], pref[j] - pref[i]); //-> pref and no dp[j]
    //         dp[i] = max(dp[i], dp[j] + pref[j-1] - pref[i]); //-> pref2
    //     }
    // }
    vector<segtree>st(x + 1);
    vector<segtree>st2(x + 1);
    for (int i = 0; i<=x; i++){
        st[i].init(n);
        st[i].build(pref);
        st2[i].init(n);
        st2[i].build(pref2);
    }
    vector<vector<int>>dp(n, vector<int>(x + 1, 0));
    dp[n-1][0] = chests[n-1];
    st2[0].add(n-1, dp[n-1][0]);
    // see(dp);
    // see(chests[n-1]);
    for (int i = n-2; i>=0; i--){
        //no explosion done here
        int temp = chests[i];
        dp[i][0] = temp;
        //explosion done
        for (int j = 1; j<=x; j++){
            int uprange = min(i + chests[i], n-1);
            int type1 = st[j-1].getMax(i+1, uprange+1);
            int type2 = st2[j-1].getMax(i+1, uprange+1);
            temp = max(type1 - pref[i], type2 - pref[i]);
            temp = max(0ll, temp);
            dp[i][j] = temp;
            st2[j].add(i, dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i<=x; i++){
        ans = max(ans, dp[0][i]);
    }
    cout<<ans<<endl;
    // see(dp);
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


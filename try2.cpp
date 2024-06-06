/*
    ------------------------------------------
    |                                        |
    |      Code Crafted by Saurav     |
    |                                        |
    ------------------------------------------
        \        ,     ,        /
        \      |     |      /
            \   \___/   /
            \  -----  /
                \_____/
    
    Happy coding! 
    */
 
    /* includes and all */
 
    #include<bits/stdc++.h>
 
    #include <iomanip>
    #include <sstream>
 
 
    #ifndef ONLINE_JUDGE
    #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
    #define print(v) do { \
                        cout << "vect--" << #v << " = [ "; \
                        for (int i = 0; i < v.size(); i++) { \
                            cout << v[i] << " "; \
                        } \
                        cout << " ]" << endl; \
                    } while(0)
    #else
    #define debug(x)
    #define print(v)
    #endif
    #define endl "\n"
    #define int long long int
    #define mod 1000000007
    #define mn(a,b,c) min(a,min(b,c))
    #define mx(a,b,c) max(a,max(b,c))
    using namespace std;
 
    /* write core logic here */
 
    void norm(pair<int,int> &pp){
        int x = pp.first;
        int y = pp.second;
        if(y<0){
            x *= -1;
            y *= -1;
        }
        if(x==0 and y<0){
            y *= 0;
        }
 
        int d = __gcd(abs(x), abs(y));
        x /= d;
        y /= d;
 
        pp.first = x;
        pp.second = y;
    }
    void solve(){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0 ; i<n; i++){
            cin>>a[i];
        }
 
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
 
        map<pair<int,int>, int> mp;
        int cnt = 0;
 
        for(int i = 0; i<n; i++){
            if(a[i] == 0 and b[i] == 0){
                cnt++;
            }
            if(a[i] == 0) continue;
            pair<int,int> pp;
            pp.first = b[i];
            pp.second = a[i];
            norm(pp);
            //cout<<pp.first<<" "<<pp.second<<endl;
            mp[pp]++;
        }
 
        int ans = 0;
        for(auto ele : mp){
            ans = max(ans, ele.second);
        }
        cout<<ans+cnt;
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